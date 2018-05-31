//ArrayTrie.cpp

#include "ArrayTrie.h"
#include "IntervalTrie.h"
#include "FertileIntervalTrie.h"
#include "PlaneTrie.h"

ArrayTrie::ArrayTrie() {}

ArrayTrie::~ArrayTrie() {
}

bool ArrayTrie::contains(const vector<string>& box, vector<string>& output) {
   int index = 0;
   vector<string> subbox;
 /*  std::cout << "Entering contains" << std::endl;
   std::cout << "Box is: ";
   for (int i = 0; i < box.size(); i++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl; */
//   std::cout << "Branches.size() is : " << branches.size() << std::endl;
   for (int i = 0; i < box[myLayer].size(); i++) {     
 //     std::cout << "Index is: " << index << std::endl;
          
      //update index
      index = index * 2 + box[myLayer][i] - '/';
      
      if (bits[index]==0) {
  //       std::cout << "Quick return" << std::endl;
         return false;
      }
      
      if (branches.at(index)!=NULL) {
  //       std::cout << "Going down 1" << std::endl;
         bool status = branches.at(index)->contains(box, output);
 //        std::cout << "Returned 1" << std::endl;
         if (status==true) {
  //          std::cout << "Returning in 1" << std::endl;
   //         std::cout << "Index is: " << index << std::endl;
            output[myLayer]=box[myLayer].substr(0,i+1);
            return status;
         }
         //if false, continue to search
      }
      
      if (wordBits[index]==1) {
   //      std::cout << "Returning in 2" << std::endl;
         output[myLayer]=box[myLayer].substr(0,i+1);
         return true;
      }
   }//end for
   //output[myLayer]=box[myLayer];
   if (branches[0]==NULL) {
   //   std::cout << "Returning in 3" << std::endl;
      return false;
   }
   else {
   //         std::cout << "Going down 2" << std::endl;

      bool status = branches[0]->contains(box, output);
  //    std::cout << "Returning in 4" << std::endl;
      return status; //branches[index]->contains(box, output);
   }
   
   std::cout << "ERR: arraytrie::contains went south" << std::endl;
   return false;
}

bool ArrayTrie::insert(const vector<string>& box) {
 /*  std::cout << "Inserting...";
   for (int i = 0; i < box.size(); i ++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl;*/
   
   int index = 0;
   int ratio = 2;

   bits[0] = 1;
   
   for (int i = 0; i < box[0].size(); i++) {
      
      //update index
      index = index * 2 + box[0][i] - '/'; 
      
      if (wordBits[index]==1) {
         return false;
      }
      
      bits[index] = 1; 
   }
   
   bool status = false;
   
   //TODO: select on a mode parameter, rather than like this
   if (box.size()==2) {
      vector<string> bottomBox;
      bottomBox.push_back(box.at(box.size()-1));
      
      if (branches.at(index)==NULL) {
         branches.at(index).reset(new IntervalTrie(maxNodeID));
         branches.at(index)->setMyLayer(myLayer+1);
      }
      
      status = branches.at(index)->insert(bottomBox);
   }
   else if (box.size()==1 || remainingInputEmpty(box, 1)) {
      wordBits[index] = 1;
      status = true;
   }
   else { //box.size() > 2
      vector<string> bottomBox;
      for (int i = 1; i < box.size(); i++) {
         bottomBox.push_back(box.at(i));
      }
      
      if (branches.at(index)==NULL) {
         if (index==0) {
            branches.at(index).reset(new FertileIntervalTrie(maxNodeID));
            branches.at(index)->setMyLayer(myLayer+1);
         } else {
            branches.at(index).reset(new PlaneTrie(maxNodeID, box.size()-1,
                                                   myLayer+1));
         }
      }
      
      //TODO: check if branch is a barren IntervalTrie--need mods...
      //But #levels should be constant for a given query, so !nec?
      
    //  std::cout << "Inserting bottomBox" << std::endl;
      status = branches.at(index)->insert(bottomBox);
   //   std::cout << "Status is: " << status << std::endl;
   }
   
   return true;
}

bool ArrayTrie::deleteChildren(int index) {
   int ratio = 2;
   //left side
   int lIndex = index * ratio + 1;
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

bool ArrayTrie::remove(const vector<string>& box) {
 //  std::cout << "Going to " << box[0] << std::endl;
 //  std::cout << "maxNodeID is: " << maxNodeID << std::endl;
  // std::cout << "branches.size() is: " << branches.size() << std::endl;
   int index = 0;
   int ratio = 2;
   
   vector<int> pastLocations;
   for (int i = 0; i < box[0].size(); i++) {
      pastLocations.push_back(index);
   //   std::cout << "i is: " << i << "; index is: " << index << std::endl;
      if (bits[index]==1 && wordBits[index]==0) {
         //do nothing
      }
      else if (bits[index]==1 && wordBits[index]==1) {
         wordBits[index] = 0;
         
         //create children
        
         if (index * 2 + 2 < bits.size()) {
            bits[index*2 + 1] = 1;
            wordBits[index*2 + 1] = 1;
            bits[index*2 + 2] = 1;
            wordBits[index*2 + 2] = 1;
         }
                     
      }
      else { // bits[index]==0
         std::cout << "Nothing to remove there" << std::endl;
         return false;
      } //end case branches
    
      //updating index
      if (box[0][i]=='0') {
         index = index *ratio + 1;
      }
      else {
         index = index * ratio + 2;
      }
      
   } // end for
   
 //  std::cout << "Index is " << index << std::endl;
   
   pastLocations.push_back(index);
   
   bool status = false;
   
   if (box.size()==1) {
      branches.at(index).reset();
      if (wordBits[index]==0) { //if has children
         deleteChildren(index);
      }
       else {
         wordBits[index] = 0;
      }
      status = true;
   } else if (box.size()==2) { //if this is the top level of a 2-layer
      if (branches.at(index)==NULL && wordBits[index]==1) {
         branches.at(index).reset(new IntervalTrie(maxNodeID));
         vector<string> tempBox;
         tempBox.push_back("");
         branches[index]->insert(tempBox);
         wordBits[index] = 0;
      }
      if (branches.at(index)!=NULL) {
         status = branches[index]->remove(box);
      }
      else {
         return false;
      }
   } else { //box.size() > 2; i.e., the next layer has kids
      std::cout << "ERROR: should not be removing >2?" << std::endl;
   }
   
   //check to see if we need to delete back up the tree
   if ((branches.at(index)==NULL || branches.at(index)->size()==0) 
         && (index + ratio + 2 > bits.size() || 
            (bits[index + ratio + 1]==0 && bits[index+ratio+2]==0))
      ) {
      std::cout << "Deleting up tree" << std::endl; 
      bits[index] = 0;
      
      for (int i = pastLocations.size()-2; i >= 0; i--) {
         index = pastLocations[i];
         int future = pastLocations[i+1];
         
         if (branches[index]->size()==0) {
            branches[index].reset();
         }
         
         wordBits[index] = 0;
         
         int oppositeFuture;
         if (future % 2 == 1) {
            oppositeFuture = future + 1;
         } else {
            oppositeFuture = future - 1;
         }
         
         if (branches.at(index)==NULL && bits[oppositeFuture]==0) {
            bits[index] = 0;
         }
         else {
            break;
         }
      } //end for
   }
   
   return status;
}

void ArrayTrie::apply(trie_actor * actor, int index) {

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
         
         if (index*ratio + 2 < bits.size()) {
            this->apply(actor, index*ratio + 1);
            this->apply(actor, index*ratio + 2);
         }
         actor->if_array_after_children(this, index);
      }
   }
   else {
      std::cout << "Did not progress." << std::endl;
   }
}

void ArrayTrie::apply (trie_actor * actor) {
   this->apply(actor,0);
}

int ArrayTrie::size() {
   return bits.size();
}

void ArrayTrie::setMaxDepth(int mD) {
   maxDepth = mD;
}
void ArrayTrie::setMaxNodeID(int mNID) {
   maxNodeID = mNID; 
   
   //TODO: TEST THIS PROPERLY
   std::cout << "MaxNodeID: " << maxNodeID << std::endl;
   int tempMaxNodeID = 1 << (int)ceil(log2(maxNodeID+1));
  // bits.resize(tempMaxNodeID-1+maxNodeID, false);
  // wordBits.resize(tempMaxNodeID-1+maxNodeID, false);
   bits.resize(2*tempMaxNodeID-1, false);
   wordBits.resize(2*tempMaxNodeID-1, false);
   bits[0] = 1;
   wordBits[0] = 1;
   branches.resize(2*tempMaxNodeID-1);

}

vector<vector<string> > ArrayTrie::getAllContainingBoxes(
   const vector<string>& input,
   vector<string>& prevWord) const
{
   
   vector<vector<string> > output;
   vector<string> currentWord;
   currentWord.push_back("");
   
   int index = 0;
   int i = 0;
   while (bits[index]==1) {
      if (wordBits[index]==1) {
      //   std::cout << "Word found." << std::endl;
         //output.push_back(currentWord);
         currentWord.back() = input.at(0).substr(0,i);
         output.push_back(currentWord);
         output.back().push_back("");
         break;
      } else {
         if (branches.at(index)!=NULL) {
            prevWord.push_back(input.at(0).substr(0,i));
            vector<vector<string> > subResult = 
               branches.at(index)->getAllContainingBoxes(input, prevWord);
            prevWord.pop_back();
            for (int j = 0; j < subResult.size(); j++) {
               output.push_back(subResult.at(j));
            }
         }
         
         if (i >= input[0].size()) {
            break;
         }
         
         //update index, CW
         index = index * 2 + input[0][i] - '/';
         
         
      }//end else (wordBits[index]==0)
      i++;
   }//end while (legal bits)
   
   return output;
}

//todo: stop duplicating methods
//WARNING: Needs updating!
vector<vector<string> > ArrayTrie::getAllContainingBoxes(
   const vector<string>& input,
   vector<string>& prevWord,
   int cap) const
{
   
   vector<vector<string> > output;
   vector<string> currentWord;
   currentWord.push_back("");
   
   int index = 0;
   int i = 0;
   while (bits[index]==1) {
      if (wordBits[index]==1) {
      //   std::cout << "Word found." << std::endl;
         output.push_back(currentWord);
         output.back().push_back("");
         break;
      } else {
         if (branches.at(index)!=NULL) {
            prevWord.push_back(currentWord.back());
            vector<vector<string> > subResult = 
               branches.at(index)->getAllContainingBoxes(input, prevWord);
            prevWord.pop_back();
            for (int j = 0; j < subResult.size(); j++) {
               output.push_back(subResult.at(j));
            }
         }
         
         if (i >= input[0].size()) {
            break;
         }
         
         //update index, CW
         index = index * 2 + input[0][i] - '/';
         currentWord.back() = currentWord.back() + input[0][i];
         
      }//end else (wordBits[index]==0)
      i++;
      if (i >= cap) break;
   }//end while (legal bits)
   
   return output;
}

bool ArrayTrie::remainingInputEmpty(const vector<string>& input, int start) {
   for (int i = start; i < input.size(); i++) {
      if (input.at(i)!="") {
         return false;
      }
   }
   return true;
}
