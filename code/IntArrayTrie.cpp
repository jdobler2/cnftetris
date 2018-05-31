//IntArrayTrie.cpp

#include "IntArrayTrie.h"
#include "IntIntervalTrie.h"
#include "IntFITrie.h"
#include "IntPlaneTrie.h"
#include "FixedIITrie.h"
#include "PointerTrie.h"

IntArrayTrie::IntArrayTrie() {
   insertionMode = 0;
}

IntArrayTrie::IntArrayTrie(int md, int newMode, int newLayer) {
   insertionMode = newMode;
   myLayer = newLayer;
   this->setMaxNodeID(md);
}

IntArrayTrie::~IntArrayTrie() {
}

//(note: this method changed heavily--cannot merge with str. ver.)
bool IntArrayTrie::contains(const vector<int>& box, vector<int>& output) {
 /*  std::cout << "Entering contains" << std::endl;
   std::cout << "Box is: ";
   for (int i = 0; i < box.size(); i++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl; 
   std::cout << "Branches.size() is : " << branches.size() << std::endl;
*/   for (int index = box.at(myLayer); index > 0; index >>= 1) {
      
      if (wordBits[index]==1) {
   //      std::cout << "Returning in 2" << std::endl;
   //      std::cout << "Index is: " << index << std::endl;

         output[myLayer] = index;
         return true;
      }
      
      if (branches.at(index)!=NULL) {
  //       std::cout << "Going down 1" << std::endl;
         bool status = branches.at(index)->contains(box, output);
 //        std::cout << "Returned 1" << std::endl;
         if (status==true) {
   //         std::cout << "Returning in 1" << std::endl;
    //        std::cout << "Index is: " << index << std::endl;
            output[myLayer] = index;
            return status;
         }
         //if false, continue to search
      }
      
   }
   
   //since we now test at 0 in the for loop, we can simply exit
   return false;
}

//This one might be merge-able?
int IntArrayTrie::insert(const vector<int>& box) {
 /*  std::cout << "Inserting: ";
   for (int i = 0; i < box.size(); i ++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl;
   */
   int index = box.at(myLayer);
   
   bool status = false;
      
   if (box.size()==1 || remainingInputEmpty(box, 1)) {
      wordBits[index] = 1;
      status = true;
      index >>= 1;
   }
   else {
      switch(insertionMode) {
        case 0:
      
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new IntIntervalTrie(maxNodeID));
            branches.at(index)->setMyLayer(myLayer+1);
         }
         
         status = branches.at(index)->insert(box); 
         break;
         
        case 1: 
         if (branches.at(index)==NULL) {
            if (index==1) {
               IntArrayTrie* tmp = new IntArrayTrie();
               tmp->setMaxDepth(maxDepth);
               tmp->setMaxNodeID(maxNodeID);
               tmp->setMyLayer(myLayer+1);
               tmp->setInsertionMode(2);
               branches.at(index).reset(tmp);
            } else {
               branches.at(index).reset(new IntPlaneTrie(maxNodeID, 
                                                      box.size()-myLayer-1,
                                                      myLayer+1));
            }
         }
         
       //  std::cout << "Inserting bottomBox" << std::endl;
         status = branches.at(index)->insert(box);
      //   std::cout << "Status is: " << status << std::endl;
         break;
        
        case 2:
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new FixedIITrie(maxNodeID));
            branches.at(index)->setMyLayer(myLayer+1);
         }
         
         status = branches.at(index)->insert(box); 
         break;
         
        case 3:
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new IntArrayTrie(maxNodeID, 3, myLayer+1));
         }
         
         status = branches.at(index)->insert(box);
         break;
      }//end switch
   }
   
   //fix past bits
   for(; index > 0; index >>= 1) {
      if (wordBits[index]==0) {
         bits[index] = 1;
      }
      else {
         std::cout << "ERR::We inserted below a word." << std::endl;
         break;
      }
   }
   
   return status;
}

bool IntArrayTrie::insertPair(
   const pair<dataLayerPair, dataLayerPair>& box) 
{
   int index;
   if (box.first.layer!=myLayer) {
      index = 1;
   }
   else {
      index = box.first.data;
   }
   
   bool status = false;
   
   if (box.first.layer==myLayer && box.second.data<=1) {
      wordBits[index] = 1;
      status = true;
      index >>= 1;
   }
   else {
      switch(insertionMode) {
        case 0:
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new IntIntervalTrie(maxNodeID));
            branches.at(index)->setMyLayer(myLayer+1);
         }
         break;
         
        case 1: 
         if (branches.at(index)==NULL) {
            if (index==1) {
               IntArrayTrie* tmp = new IntArrayTrie();
               tmp->setMaxDepth(maxDepth);
               tmp->setMaxNodeID(maxNodeID);
               tmp->setMyLayer(myLayer+1);
               tmp->setInsertionMode(2);
               branches.at(index).reset(tmp);
            } else {
               branches.at(index).reset(new IntPlaneTrie(maxNodeID, 
                                                      _LAYERS-myLayer-1,
                                                      myLayer+1));
            }
         }
         break;
        
        case 2:
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new FixedIITrie(maxNodeID));
            branches.at(index)->setMyLayer(myLayer+1);
         }
         break;
         
        case 3:
         if (branches.at(index)==NULL) {
            branches.at(index).reset(new IntArrayTrie(maxNodeID,
                                                      insertionMode,
                                                      myLayer+1));
         }
         break;
      }//end switch
      status = branches.at(index)->insertPair(box); 
   }
   
   //fix past bits
   for(; index > 0; index >>= 1) {
      if (wordBits[index]==0) {
         bits[index] = 1;
      }
      else {
         std::cout << "ERR::We inserted below a word." << std::endl;
         break;
      }
   }
   
   return status;
}

//this is an exact copy
bool IntArrayTrie::deleteChildren(int index) {
   int ratio = 2;
   //left side
   int lIndex = index * ratio;
   if (lIndex > bits.size()) { return false;}
   if (bits[lIndex]==1) {
      bits[lIndex] = 0;
      if (wordBits[lIndex]==1) { 
         wordBits[lIndex] = 0;
      }
      else {
         branches.at(lIndex).reset();
         deleteChildren(lIndex);
      }
   }
   int rIndex = lIndex + 1;
   if (bits[rIndex]==1) {
      bits[rIndex] = 0;
      if (wordBits[rIndex]==1) { 
         wordBits[rIndex] = 0;
      }
      else {
         branches.at(rIndex).reset();
         deleteChildren(rIndex);
      }
   }
   
   return true;
}

bool IntArrayTrie::remove(const vector<int>& box) {
   if (insertionMode==3) {
      std::cout << "ERROR: Removal not yet written for iMode 3!" << std::endl;
      return false;
   }
   
   bool status = false;
   
   int index = box.at(myLayer);
   bits[index] = 1;
   
   if (box.size() - myLayer == 1) {
      branches.at(index).reset();
      if (wordBits[index]==0) { //if has children
         deleteChildren(index);
      }
       else {
         wordBits[index] = 0;
      }
      status = true;
   } else if (box.size() - myLayer == 2) { //if exactly 1 layer below
      if (branches.at(index)==NULL) {
         branches.at(index).reset(new IntIntervalTrie(maxNodeID));
         branches.at(index)->setMyLayer(myLayer+1);
         vector<int> tempBox;
         for (int x = 0; x < myLayer+2; x++) {
            tempBox.push_back(1);
         }
         branches.at(index)->insert(tempBox);
         wordBits[index] = 0;
      }
      status = branches[index]->remove(box);
   } else { //box.size() > 2; i.e., the next layer has kids
      std::cout << "ERROR: should not be removing >2?" << std::endl;
   }
   
   //For the time being, we'll assume we can't remove the last element.
   //of a lower layer, which simplifies things greatly.
   //TODO: stop assuming that!
   
   //add in words and bits where necessary.
   int pastDirection = index % 2;
   index >>= 1;
   for(; index > 0; index >>= 1) {
      if (wordBits[index] || !bits[index]) {
         //if it was a word, neighbor needs to be a word
         if (pastDirection==1) {
            bits[index*2] = 1;
            wordBits[index*2] = 1;
         }
         else {
            bits[index*2+1] = 1;
            wordBits[index*2+1] = 1;
         }
         
         //one of these things needs to be set, checking takes time.
         bits[index] = 1;
         wordBits[index] = 0;
      }
      else {
         break;
      }
   }
   return status;
}

//Exact copy of function in ArrayTrie.cpp
void IntArrayTrie::apply(trie_actor * actor, int index) {

   if (bits[index]==1) {
      actor->if_array(this, index);
      if (wordBits[index]==1) {
         actor->if_array_word(this, index);
      }
      else {
         if (branches[index]!=NULL) {
            branches[index]->apply(actor);
         }
         int ratio = 2;
         
         if (index*ratio + 1 < bits.size()) {
            this->apply(actor, index*ratio);
            this->apply(actor, index*ratio + 1);
         }
         actor->if_array_after_children(this, index);
      }
   }
   else {
      std::cout << "Did not progress." << std::endl;
   }
}

//exact copy
void IntArrayTrie::apply (trie_actor * actor) {
   this->apply(actor,1);
}

//exact copy
int IntArrayTrie::size() {
   return bits.size();
}

//exact copy
void IntArrayTrie::setMaxDepth(int mD) {
   maxDepth = mD;
}

//exact copy
void IntArrayTrie::setMaxNodeID(int mNID) {
   maxNodeID = mNID; 
   
   int tempMaxNodeID = 1 << (int)ceil(log2(maxNodeID+1));
  // bits.resize(tempMaxNodeID-1+maxNodeID, false);
  // wordBits.resize(tempMaxNodeID-1+maxNodeID, false);
   bits.resize(2*tempMaxNodeID, false);
   wordBits.resize(2*tempMaxNodeID, false);
 //  bits[0] = 1;
 //  wordBits[0] = 1;
   branches.resize(2*tempMaxNodeID);

}

void IntArrayTrie::getAllContainingBoxes(
   const vector<int>& input,
   vector<pair<dataLayerPair, dataLayerPair> >& output,
   vector<int>& prevWord) const
{  
   for (int index = input.at(myLayer); index > 0; index >>= 1) {
      if (wordBits[index]==1) {
      //   std::cout << "Word found." << std::endl;
         //output.push_back(currentWord);

         output.push_back(pair<dataLayerPair,dataLayerPair>(
            dataLayerPair(index, 1), dataLayerPair()
         ));
      } 
      else if (branches.at(index)!=NULL) {
         prevWord.push_back(index);
         branches.at(index)->getAllContainingBoxes(input, output, prevWord);
         prevWord.pop_back();
      }//end else (wordBits[index]==0)
   }//end for (index)
}

bool IntArrayTrie::remainingInputEmpty(const vector<int>& input, int start) {
   for (int i = start; i < input.size(); i++) {
      if (input.at(i) > 1) {
         return false;
      }
   }
   return true;
}

void IntArrayTrie::pointerClone(const IntArrayTrie& rhs) {
   bits = rhs.bits;
   wordBits = rhs.wordBits;
   maxDepth = rhs.maxDepth;
   maxNodeID = rhs.maxNodeID;
   insertionMode = rhs.insertionMode;
   branches.resize(rhs.branches.size());
   
   //build everyone except for 1
   for (int i = 1; i < rhs.branches.size(); i++) {
      if (rhs.branches.at(i)!=NULL) {
         PointerTrie* pt = new PointerTrie(maxDepth, _LAYERS, 
                              myLayer+1, rhs.branches.at(i));
         branches.at(i).reset(pt);
      }
   }
   IntArrayTrie* iat_p;
   if (myLayer==0) {
      //build 1
      std::cout << "This only prints once." << std::endl;
      iat_p = new IntArrayTrie();
      iat_p->setMyLayer(1);
      iat_p->pointerClone(rhs);
      branches.at(1).reset(iat_p);
   }
   else {
      PointerTrie* pt = new PointerTrie(maxDepth, _LAYERS, 
                              myLayer+1, rhs.branches.at(1));
      branches.at(1).reset(pt);
   }
}

