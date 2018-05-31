//B243BunchedInnerGIAT.cpp

#include "B243BunchedInnerGIAT.h"
#include <math.h>

#include <immintrin.h>

B243BunchedInnerGIAT::B243BunchedInnerGIAT() : branches(243) {
   myLayer = 0;
  //childBits[0] = 0;
  //childBits[1] = 0;
   for (int i = 0; i < 4; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }
   
   
}

B243BunchedInnerGIAT::B243BunchedInnerGIAT(int newLayer) : branches(243) {
   myLayer = newLayer;
   for (int i = 0; i < 4; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }

}

int B243BunchedInnerGIAT::insert(const vector<int>& box) {
   if (mStatus == GIAT_STATUS_EMPTY) {
      pathToThis = box;
   }
   insertedCount++;
   
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   /*TODO
   //check for inclusion
   if (mStatus & GIAT_STATUS_WORD_ONLY) {
      __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      __m128i and_result = _mm_and_si128(link, data);
      
      uint64_t dest[2];
      _mm_storeu_si128((__m128i*)dest, and_result);
      if (dest[0]!=0 || dest[1]!=0) {
         return INSERT_PRESENT;
      }
   }//end if words present*/
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
    
   int initialLoc = loc;
   if (wordFlag) {
      
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      
      //TODO: check if we filled the trie
      /*if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }*/
      //clearChildren(loc);
      //clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word TODO: Add support for skipping
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      if (branches.at(loc).size()==0) {
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < _LAYERS - 1) {
            auto pair = branches.at(loc).insert(std::make_pair(
               nextActiveLayer,
               std::unique_ptr<GenericIntTrie>(
                  new B243BunchedInnerGIAT(nextActiveLayer)
            )));
            return (*(pair.first)).second->insert(box);
         }
         else {//if at the bottom, insert bottom-level GIAT.
            auto pair = branches.at(loc).insert(std::make_pair(
               nextActiveLayer,
               std::unique_ptr<GenericIntTrie>(
                  new Base243GIAT(nextActiveLayer)
            )));
            return (*(pair.first)).second->insert(box);

         }
         
         //return branches[loc].back()->insert(box);
      }
      else { //determine if already exists, else add new
         int nextActiveLayer = getNextActiveLayer(box);
         if (branches.at(loc).count(nextActiveLayer)) {
            return branches.at(loc)[nextActiveLayer]->insert(box);
         }
         
         branches.at(loc).insert(std::make_pair(
            nextActiveLayer,
            std::unique_ptr<GenericIntTrie>(
               new B243BunchedInnerGIAT(nextActiveLayer)
            )));
         return branches[loc][nextActiveLayer]->insert(box);
      }
   }
}   

int B243BunchedInnerGIAT::insert(const vector<int>& box, int& firstNewsLayer, Base243GIAT*& firstNew) {
   
   return this->insert(box); //TODO: implement!!!!
   
   // if (mStatus == GIAT_STATUS_EMPTY) {
      // pathToThis = box;
   // }
   // insertedCount++;
   
   // //ASSERT: box.at(myLayer)!=-1
   // int i = myLayer + 1;
   // int loc = box.at(myLayer);
   // /*TODO
   // //check for inclusion
   // if (mStatus & GIAT_STATUS_WORD_ONLY) {
      // __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      // __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      // __m128i and_result = _mm_and_si128(link, data);
      
      // uint64_t dest[2];
      // _mm_storeu_si128((__m128i*)dest, and_result);
      // if (dest[0]!=0 || dest[1]!=0) {
         // return INSERT_PRESENT;
      // }
   // }//end if words present*/
   
   // savedInput = -5;

   
   // int wordFlag = 0;
   // if (box.at(myLayer+1)==-1) {
      // wordFlag = 1;
   // }
   
  // // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
    
   // int initialLoc = loc;
   // if (wordFlag) {
      
   // //  std::cout <<"\nActloc: " << loc << std::endl;
      // //Assert: 0 <= loc <= 120
      // //I should really wrap this...
      // wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      // mStatus |= GIAT_STATUS_WORD_ONLY;
      
      // //TODO: check if we filled the trie
      // /*if (size()) {
       // //  std::cout << "REturning IMR" << std::endl << std::endl;
         // return INSERT_MERGE_REQ;
      // }*/
      // //clearChildren(loc);
      // //clearChildBits(loc); //saves time to do it here.

        // // std::cout << "Insertion successful." << std::endl << std::endl;

      // return INSERT_SUCCESSFUL;
   // }
   // else { //not a word TODO: Add support for skipping
      // mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      // if (branches.at(loc).size()==0) {
         // childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         // int nextActiveLayer = getNextActiveLayer(box);
         // if (nextActiveLayer < _LAYERS - 1) {
            // branches.at(loc).push_back(new B243BunchedInnerGIAT(nextActiveLayer));
         // }
         // else {//if at the bottom, insert bottom-level GIAT.
            // branches.at(loc).push_back(new Base243GIAT(nextActiveLayer));
         // }
         
         // firstNewsLayer = myLayer;
         // firstNew = this;
         
         // return branches[loc].back()->insert(box);
      // }
      // else { //determine if already exists, else add new
         // int nextActiveLayer = getNextActiveLayer(box);
         // for (auto p : branches.at(loc)) {
            // if (p->getMyLayer() == nextActiveLayer) {
               // return p->insert(box, firstNewsLayer, firstNew);
            // }
         // }
         // branches.at(loc).push_back(new B243BunchedInnerGIAT(nextActiveLayer));
         
         // firstNewsLayer = myLayer;
         // firstNew = this;
         
         // return branches[loc].back()->insert(box);
      // }
   // }
}   

int B243BunchedInnerGIAT::insertWeighted(const weightedBox& wbox) {
   std::cout << "INSERTED WEIGHTED NOT IMPLEMENTED FOR B243BUNCHED" << std::endl;
   return -1;
}

void B243BunchedInnerGIAT::forcedInsertAtZero(GenericIntTrie* trie) {
   std::cout << "Error: Bunched243 should not have forced inserts at 0!" << std::endl;
}

bool B243BunchedInnerGIAT::contains(const vector<int>& box, 
                                   vector<int>& output)
{
   std::cout << "Error: Contains not implemented on B243Bunched!" << std::endl;
   return true;
}

bool B243BunchedInnerGIAT::containsWeighted(const weightedBox& wbox, 
                                   weightedBox& output) {
                                      
   std::cout << "Error: ContainsWeighted not implemented on B243Bunched!" << std::endl;
   return true;
}

void B243BunchedInnerGIAT::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, 
                  int& currentDepth) 
{
   std::cout << "Error: gacbb not implemented on B243Bunched!" << std::endl;
   return;
}

void B243BunchedInnerGIAT::getAllContainingBoxesWeighted( const weightedBox& winput,
                  vector<weightedBox>& output,
                  vector<int>& prevWord, 
                  int& currentDepth) 
{
   std::cout << "Error: gacbbWeighted not implemented on B243Bunched!" << std::endl;
   return;
}

void B243BunchedInnerGIAT::resetPrevWord(vector<int>& prevWord, int& myLayer) const {
   prevWord.at(myLayer) = 0;
}

int B243BunchedInnerGIAT::getNextActiveLayer(const vector<int>& box) const {
   int nextLayer = myLayer + 1;
   while (box.at(nextLayer) == 0) { //<= WILL cause crashes.
      nextLayer++; //assert: there exists a fully-defined box eventually.
   }
   return nextLayer;
}

void B243BunchedInnerGIAT::add243Children(
   std::vector<std::vector<Base243GIAT*> >& lists, 
   int index, int& remaining) 
{
   for (auto& p : branches.at(index)) {
      Base243GIAT* candidate = (Base243GIAT*) p.second.get();
      lists.at(candidate->getMyLayer()).push_back(candidate);
      remaining++;
   }
   
}
