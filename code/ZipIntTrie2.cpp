//ZipIntTrie2.cpp

#include "ZipIntTrie2.h"
#include "SmallIntArrayTrie.h"
#include "GroupedIntArrayTrie.h"
#include "SIMD_GIATrie.h"
#include "SmallIntArrayTrie2.h"

//note: LayersSkipped counts itself!
ZipIntTrie2::ZipIntTrie2(int newLayer, int newLayersSkipped) {
   myLayer = newLayer;
   layersSkipped = newLayersSkipped;
}
 
ZipIntTrie2::~ZipIntTrie2() {
   child.reset();
}

bool ZipIntTrie2::contains(const vector<int>& box, vector<int>& output) {
   return child->contains(box, output);
}

int ZipIntTrie2::insert(const vector<int>& box) {
 //  std::cout << "Inserting..." << std::endl;
   for (int i = 0; i < layersSkipped; i++) {
      if (box.at(myLayer + i) != 1) { //if need to break up zip
 //        std::cout << "Breaking; i is " << i << "; layersSkiped is " << layersSkipped << std::endl;
         SmallIntArrayTrie2* trie = new SmallIntArrayTrie2(myLayer + i);
         
         if (i==0) {
            if (layersSkipped > 1) {
               std::shared_ptr<GenericIntTrie> zit;
               zit.reset(new ZipIntTrie2(myLayer+i+1, layersSkipped - i - 1));
               std::shared_ptr<GenericIntTrie> temp = child;
               
               zit->append(temp, 0);
               child.reset(trie);
               child->append(zit, 0);
            }
            else {
               std::shared_ptr<GenericIntTrie> temp = child;
               trie->append(temp, 0);
               child.reset(trie);
            }
            return INSERT_ZIP_BROKEN;
         }
         else if (i==layersSkipped - 1) { 
            std::shared_ptr<GenericIntTrie> temp = child;
            child.reset(trie);
            child->append(temp, 0);
         }
         else {
            std::shared_ptr<GenericIntTrie> zit;
            zit.reset(new ZipIntTrie2(myLayer+i+1, layersSkipped - i - 1));
            std::shared_ptr<GenericIntTrie> temp = child;
            
            zit->append(temp, 0);
            child.reset(trie);
            child->append(zit, 0);
         }


         layersSkipped = i; //this will also break the for-loop
      } //end if(need break-up)
   }
   
 //  std::cout << "Inserting below." << std::endl;
   //ASSERT: If the zip needs to be broken, it has been
   //NOTE: we do not need to handle INSERT_MERGE_REQ's at this level; it just gets passed up to the next above SIAT.
   return child->insert(box);
}

void ZipIntTrie2::apply(trie_actor* actor) {
   child->apply(actor);
}

int ZipIntTrie2::size() {
   return layersSkipped;
}

bool ZipIntTrie2::append(std::shared_ptr<GenericIntTrie> tr, int index) {
   child = tr;
   return true;
}

std::shared_ptr<GenericIntTrie> ZipIntTrie2::getChild(int index) {
   return child;
}

void ZipIntTrie2::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth) const 
{
   //with preallocate, not necessary!
  /* for (int i = 0; i < layersSkipped; i++) {
      prevWord.push_back(1); 
   }*/
   currentDepth+=layersSkipped;
   child->getAllContainingBoxesB(input, output, prevWord, currentDepth);
   currentDepth-=layersSkipped;
   //ditto
   /*
   for (int i = 0; i < layersSkipped; i++) {
      prevWord.pop_back();
   }*/
}