//SmallIntArrayTrie2.cpp

#include "SmallIntArrayTrie2.h"
#include <cmath>
#include "ZipIntTrie2.h"
#include "GroupedIntArrayTrie.h"
//#include "SIMD_GIATrie.h"


SmallIntArrayTrie2::SmallIntArrayTrie2() {
   myLayer = 0;
   this->setMaxNodeID(2);
}

SmallIntArrayTrie2::SmallIntArrayTrie2(int newLayer) {
   myLayer = newLayer;
   this->setMaxNodeID(2);
}

void SmallIntArrayTrie2::setMaxNodeID(int mNID) {
   maxNodeID = mNID; 
   bits.resize(3, false);
   wordBits.resize(3, false);
   branches.resize(3);
}

SmallIntArrayTrie2::~SmallIntArrayTrie2() {
   //rely on call to normal IntArrayTrie destructor
}

//meaning of box is the same as other tries
//but we adjust to count from 0, not 1!
int SmallIntArrayTrie2::insert(const vector<int>& box) {   
   int index = box.at(myLayer) - 1;
   
   //Unnecessary comp!
   /*
   if (wordBits[0] == 1) {
      std::cout << "Blocked!" << std::endl;
      return INSERT_SUCCESSFUL;
   }*/
   
   int status = false;
      
   //first check is equivalent to saying there exists a next layer
   if ((box.size() - myLayer) < 2 || isLastInput(box, myLayer+1)) {
      wordBits[index] = 1;
      bits[index] = 1;
      branches.at(index).reset();
      bits[0] = 1;
 //     std::cout << "Returning in 1" << std::endl;
      if (this->size() == 1) {
         return INSERT_MERGE_REQ;
      }
      return INSERT_SUCCESSFUL;
   }
   else { // we are branching 100%.
      if (wordBits[index] == 1) {
  //       std::cout << "Returning false in 2" << std::endl;
         return INSERT_PRESENT;
      }
      //bookkeeping
      bits[index] = 1;
      bits[0] = 1;

      if (branches.at(index)==NULL) {
         if (box.size() - myLayer - 2 == GIAT_SWITCH) { //#remaining levels == the switch
            branches.at(index).reset(new GroupedIntArrayTrie(myLayer+1, GIAT_SWITCH));
            //branches.at(index).reset(new SIMD_GIATrie(myLayer+1));
         }
         else if (index==0 && 
                  myLayer + 2 < box.size() - 1 - GIAT_SWITCH &&
                  box.at(myLayer+1) == 1) 
         {
            int layersSkipped = 1;
            int giatFlag = 1;
            for (int i = myLayer + 2; i < box.size() - 1 - GIAT_SWITCH; i++) {
               if (box.at(i)==1) {
                  layersSkipped++;
               }
               else {
                  giatFlag = 0;
                  break;
               }
            }
            branches.at(index).reset(new ZipIntTrie2(myLayer+1, layersSkipped));
            
            std::shared_ptr<GenericIntTrie> temp;
            if (giatFlag) {
               temp.reset(new GroupedIntArrayTrie(myLayer+1+layersSkipped, GIAT_SWITCH));
               //temp.reset(new SIMD_GIATrie(myLayer+1+layersSkipped));
            }
            else {
               temp.reset(new SmallIntArrayTrie2(myLayer+1+layersSkipped));
            }
            branches.at(index)->append(temp, 0);
            //todo: insert now?
         }
         else {//cannot zip or go to GIAT.
            branches.at(index).reset(new SmallIntArrayTrie2(myLayer+1));
         }
      }
      int status = branches.at(index)->insert(box); //recurse
      switch(status) {
        case(INSERT_ZIP_BROKEN): //<-- Child is a zip that needs to be deleted
         //it shouldn't be able to recurse, but... Let's be safe for now.
         branches.at(index) = branches.at(index)->getChild(index);
         status = branches.at(index)->insert(box);
         break;
        case(INSERT_MERGE_REQ): //<-- Child is full
         wordBits[index] = 1;
         branches.at(index).reset();
         if (this->size() == 0) {
            status = INSERT_SUCCESSFUL;
         } //else: need to continue merging
         break;
      }
      //status must be true
      return status;
      
   }
   
   
}

//a quick-and-dirty hack to make things work.
//I'm not in love with this implemenation, though.
bool SmallIntArrayTrie2::contains(const vector<int>& box, vector<int>& output) {

//   std::cout << "Calling in " << myLayer << "..." << std::endl;
   
   
   if (box.size() >= myLayer + 1 && box.at(myLayer) >= 0) { //safety check
      for (int index = box.at(myLayer)-1; index >= 0; index = (index + 1) / 2 - 1) {
      
         if (wordBits[index]==1) {
   //         std::cout << "Returning in 2" << myLayer << std::endl;
       //     std::cout << "Index is: " << index << std::endl;

            output[myLayer] = index + 1;
            return true;
         }
         
         if (branches.at(index)!=NULL) {
   //         std::cout << "Going down 1" << std::endl;
     //       std::cout << "Child is a " << branches.at(index)->getType() << std::endl;
            bool status = branches.at(index)->contains(box, output);
       //     std::cout << "Returned 1" << std::endl;
            if (status==true) {
         //      std::cout << "Returning in 1" << myLayer << std::endl;
        //       std::cout << "Index is: " << index << std::endl;
               output[myLayer] = index + 1;
               return status;
            }
            //if false, continue to search
         }
         //for doing upwards
         /*
         if (index == box.at(myLayer) - 1) {
            break;
         }
         index = box.at(myLayer) - 1;
         */
      }
      //failed to find
      //std::cout << "Failed to find." << myLayer <<  std::endl;
      return false;
   }
   else { //box is a superbox of this!
      //std::cout << "Returning false in " << myLayer << std::endl;
      return false;
   }   
}

//DEPRECATED
bool SmallIntArrayTrie2::contains(const vector<int>& box,
                                 int currentLayer, 
                                 vector<int>& output) 
{
   std::cout << "DEPRECATED." << std::endl;
   //initial check
   if (wordBits[0] == 1) {
      return true;
   }
  /* std::cout << "box.size(): " << box.size() << std::endl;
   std::cout << "currentLayer: " << currentLayer << std::endl;
   std::cout << "myLayer; " << myLayer << std::endl;*/
   
   if (std::abs(box.at(currentLayer))==myLayer) {
      int index = 1; // 2= positive, 1 = negative
      if (box.at(currentLayer) > 0) {
         index = 2;
      }
      if (wordBits[index]==1) { //check if subsuming box exists
         return true;
      }
      //check if there's another layer to examine
      if (branches.at(index)!=NULL && currentLayer+1 < box.size()) {
         output.push_back(currentLayer+1);
         return branches.at(index)->contains(box, output);
      } 
      else {
         //box can't possibly exist
         return false;
      }
   }
   else { //recurse onto next layer
      if (branches.at(0)!=NULL) {
         output.push_back(currentLayer);
         return branches.at(0)->contains(box, output);
      }
      else { //req'd lower layer doesn't exist
         return false;
      }
   }
}

//todo: better way?
void SmallIntArrayTrie2::apply(trie_actor* actor) {
  /* actor->if_siat_do_once(this);
   for (int index = 0; index < 3; index++) {
      if (bits[index]==1) {
         actor->if_array(this, index);
         if (wordBits[index]==1) {
            actor->if_array_word(this, index);
         }
         else {
            if (branches[index]!=NULL) {
               branches[index]->apply(actor);
            }
            actor->if_array_after_children(this, index);
         }
      }
   }
   actor->if_siat_do_once_after_children(this);*/
}

//is now being used to get if it's full. 
//sorry about that.
int SmallIntArrayTrie2::size() {
   if (wordBits[0] == 1 || (wordBits[1] == 1 && wordBits[2] == 1)) {
     // std::cout << "Returning true!" << std::endl;
      return 1;
   }
   return 0;
}

//CurrentDepth is redundant with myLayer...
void SmallIntArrayTrie2::getAllContainingBoxesB(
                  const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth) const
{ //TODO: separate out cases for speed?
   int value = input.at(currentDepth);
   /*int index = 0; //this was for abandoned method
   if (std::abs(value) == myLayer) { //examine only a subset
      prevWord.push_back(value);
      index = 2;
      if (value < 0) {
         index = 1;
      }
      currentDepth++;
   }*/
   int index = value - 1;
   prevWord.at(myLayer) = value;
   
   for (; index >= 0; index = (index + 1) / 2 - 1) {
      if (bits[index] == 1) { //<-- this check is redundant
         if (wordBits[index] == 1) { 
            prevWord.at(myLayer+1) = -1; //_CNFINT_KILL
            output.push_back(prevWord); //should not be possible to have output
            //undo the kill command
            prevWord.at(myLayer+1) = 1;
            break;                      //if we're not branching left or right.
         }

         if (branches.at(index)!=NULL) {
            currentDepth++;
            branches.at(index)->getAllContainingBoxesB(
                                   input, 
                                   output, 
                                   prevWord, 
                                   currentDepth);
            currentDepth--;
         }
      }//end if(bits)
      prevWord.at(myLayer) = 1; //Lambda
   }
   
   //we don't have to undo the above pre-push anymore!
}

bool SmallIntArrayTrie2::remainingInputEmpty(const vector<int>& input, int start) {
   for (int i = start; i < input.size(); i++) {
      if (input.at(i) > 1) {
         return false;
      }
      else if (input.at(i) < 0) {
         return true;
      }
   }
   return true;
}

bool SmallIntArrayTrie2::isLastInput(const vector<int>& input, int start) {
   if (input.at(start) < 0) {
      return true;
   }
   return false;
}

std::string SmallIntArrayTrie2::getType() {
   return "SmallIntArrayTrie2";
}

bool SmallIntArrayTrie2::append(std::shared_ptr<GenericIntTrie> tr, int index) {
   branches.at(index) = tr;
   return true;
}

std::shared_ptr<GenericIntTrie> SmallIntArrayTrie2::getChild(int index) {
   return branches.at(index);
}
