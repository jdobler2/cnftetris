//GroupedIntArrayTrie.cpp
#include "GroupedIntArrayTrie.h"
#include <math.h>

GroupedIntArrayTrie::GroupedIntArrayTrie() {
   myLayer = 0;
   this->setLevels(2);
}

GroupedIntArrayTrie::GroupedIntArrayTrie(int newLayer, int levels) {
   myLayer = newLayer;
   this->setLevels(levels);
}

void GroupedIntArrayTrie::setMaxNodeID(int mNID) {
   maxNodeID = mNID;
}

void GroupedIntArrayTrie::setLevels(int levels) {
   maxLevel = levels;
   //TODO: make this math more efficient (realistically, static/precalc values)
   int size = 3;
   for (int i = 1; i < levels; i++) {
      size = size * 3 + 3; //losing 1 bit is irrelevant--
   }                       //we'll never be a multiple of 8 anyways.
   wordBits.resize(size+1);
   bits.resize(size+1);
   branches.resize(0); //see above
}

GroupedIntArrayTrie::~GroupedIntArrayTrie() {
   //rely on call to superdestructors
}

bool GroupedIntArrayTrie::contains(const vector<int>& box, 
                                   vector<int>& output) 
{
   //ASSERT: myLayer + levels <= box.size()
   int loc = 0;
   for (int i = myLayer; i < box.size(); i++) {
      loc = loc * 3 + box.at(i);
      if (wordBits[loc]) {
         for (int j = myLayer; j <= i; j++) {
            output.at(j) = box.at(j);
         }
         return true;
      }
   }
   //we never hit a location that has it.
   return false;
}

int GroupedIntArrayTrie::insert(const vector<int>& box) {
  return insertRecursively(box, 0, 0);
 /*  int currentLevel;
   int loc = 0;
   for (currentLevel = 0; box.at(myLayer+currentLevel)!=-1; currentLevel++) {
      loc = loc * 3 + box.at(myLayer+currentLevel);
      if (wordBits[loc]==1) return INSERT_PRESENT;
   }
   currentLevel--;
   int status = updateChildren(loc, currentLevel);
   while (status == INSERT_MERGE_REQ) {
      loc = (loc - 1)/ 3;
      currentLevel--;
      if (loc == 0) {
         //merge to above trie
         return status;
      }
      status = updateChildren(loc, currentLevel);
   }*/
}
int GroupedIntArrayTrie::insertRecursively(const vector<int>& box, 
                                           int loc, 
                                           int currLevel) 
{  
//   std::cout << "at loc = " << loc << std::endl;
//   std::cout << "currLevel: " << currLevel << std::endl;
   if (wordBits[loc] == 1) {
      return INSERT_PRESENT;
   }
   bits[loc] = 1;
   //if *, branch out
 //  std::cout << "About to if" << std::endl;
 //  std::cout << "Box.at() is" << box.at(myLayer+currLevel) << std::endl;
   if (box.at(myLayer + currLevel) == 1) {
 //     std::cout << "If'd." << std::endl;
      insertRecursively(box, loc * 3 + 2, currLevel + 1);
      insertRecursively(box, loc * 3 + 3, currLevel + 1);
      //see if filled all
  //    std::cout << "Levels: " << myLayer << ", " << currLevel << ", " << maxLevel << std::endl;
  //    std::cout << "loc*3+2 (" << loc*3+2 <<"): " << wordBits[loc*3+2] << "; +3: " << wordBits[loc*3+3] << std::endl;
      if (wordBits[loc * 3 + 2] == 1 && wordBits[loc * 3 + 3] == 1) {
         std::cout << "Merge~" << std::endl;
         updateChildren(loc, currLevel); //not nec. if i abandon lower dupes
 //       std::cout << "returning from " << loc << " successfully " << std::endl;
         return INSERT_MERGE_REQ;
      }
      //add this line back in if removing all contact w/ 1's.
      //return INSERT_SUCCESSFUL;
   }
//  std::cout << "If over." << std::endl;
   
   //loc = loc * 3 + box.at(myLayer + currLevel);
   
   //if there's another layer, go to it.
   if (!isLastInput(box, myLayer+currLevel+1) ) {
  //    std::cout << "MyLayer: " << myLayer << ", currLevel" << currLevel << ", box.size(): " << box.size() << std::endl;
      insertRecursively(box, loc * 3 + box.at(myLayer + currLevel), currLevel+1);
   }
   else {
 //     std::cout << "We're here with loc = " << loc << std::endl;
      int status = updateChildren(loc * 3 + box.at(myLayer + currLevel), currLevel+1);
      if (status == INSERT_MERGE_REQ) {
  //       std::cout << "Merge~" << std::endl;
         wordBits[loc] = 1;
         if (loc==0) {
            std::cout << "This happens." << std::endl;
            return INSERT_MERGE_REQ;
         }
         if (loc % 3 == 1 || 
            (loc % 3 == 2 && wordBits[loc+1]) || 
            (loc % 3 == 0 && wordBits[loc-1]))
         {
            return INSERT_MERGE_REQ;
         }
         int status = findCousinMerges(loc, currLevel);
      }
   }
//   std::cout << "returning from " << loc << " without info " << std::endl;
   return INSERT_SUCCESSFUL;
}

//note: updates siblings AND children
int GroupedIntArrayTrie::updateChildren(int loc, int currLevel) {
 //  std::cout << "Updating children at " << loc << ". " << std::endl;
   int status = INSERT_PRESENT;
   if (!wordBits[loc]) {
      if (loc < 4) {
         //std::cout << "Setting " << loc << "..." << std::endl;
      }
      wordBits[loc] = 1;
      bits[loc] = 1;
      status = INSERT_SUCCESSFUL;
  //    std::cout << "CurrLevel: " << currLevel << ", maxLevel: " << maxLevel << std::endl;
      if (currLevel < maxLevel) {
         updateChildren(loc * 3 + 1, currLevel + 1);
      }
      int modValue = loc % 3;
      switch (modValue) {
        case(1):
     //    std::cout << "Case 1" << std::endl;
         updateChildren(loc+1, currLevel);
         updateChildren(loc+2, currLevel);
         status = INSERT_MERGE_REQ;
         break;
        case(2):
      //   std::cout << "Case 2!" << std::endl;
         if (wordBits[loc+1]) { //if merge
       //     std::cout << "--merging at " << loc-1 << std::endl;
            wordBits[loc-1] = 1;
            if (currLevel < maxLevel) {
               updateChildren((loc - 1) * 3 + 1, currLevel + 1);
            }
            status = INSERT_MERGE_REQ;
         }
         break;
        case(0):
         if (wordBits[loc-1]) { //if merge
         //   std::cout << "--merging at " << loc-2 << std::endl;
            wordBits[loc-2] = 1;
            if (currLevel < maxLevel) {
               updateChildren((loc - 2) * 3 + 1, currLevel + 1);
            }
            status = INSERT_MERGE_REQ;
         }
         break;
      }//end switch
      int cousStatus = findCousinMerges(loc, currLevel); //do I need to use this?
      
   }
//   std::cout << "End updatingChildren from " << loc << std::endl;
   return status;
}

//finds merges amongst cousins to place in parents
//Do I need to do this after updateChildren instead? (DONE)
//Or move sibling-finding here? Or both?
int GroupedIntArrayTrie::findCousinMerges(int loc, int currLevel) {
 //  std::cout << "Finding cousins from " << loc << "." << std::endl;
   int diff = 1;
   int divisor = 1;
   int startLevel = currLevel;
   currLevel--; //because we've already handled sibs
   while (currLevel > 0) {
      diff = diff * 3 + 1;
      divisor *= 3;
      int modValue = ((loc - diff) / divisor) % 3;
      int partnerLoc;
      
      switch(modValue) {
        case(0):
         //is a star node at this level, do nothing
         break;
         
        case(1):
         //left node at this level
         partnerLoc = loc + divisor;
 //        std::cout << "partnerLoc is " << partnerLoc << std::endl;
         if (wordBits[partnerLoc] == 1) { //if merge
            int newLoc = loc - divisor;
            int status = updateChildren(newLoc, startLevel);
            //This causes redundancies that cause problems
/*            while (status == INSERT_MERGE_REQ) {
               newLoc = (newLoc - 1) / 3;
               status = updateChildren(newLoc, startLevel - 1);
            }*/
         }
         break;
         
        case(2):
         //right node at this level
         partnerLoc = loc - divisor;
 //        std::cout << "partnerLoc is " << partnerLoc << std::endl;
         if (wordBits[partnerLoc] == 1) { //if merge
            int newLoc = partnerLoc - divisor;
            int status = updateChildren(newLoc, startLevel);
            //This causes redundancies that cause problems
/*            while (status == INSERT_MERGE_REQ) {
               newLoc = (newLoc - 1) / 3;
               status = updateChildren(newLoc, startLevel - 1);
            }*/
         }
         break;
      } //end switch
      
      currLevel--;
   }
//   std::cout << "End cousins from "<< loc << std::endl;
   return 1; //not sure what info to push back anymore...
}

//TODO: this doesn't work!
void GroupedIntArrayTrie::apply(trie_actor* actor) {
   std::cout << "WARNING: You shouldn't have done that Dave." << std::endl;
   for (int i = 1; i < wordBits.size(); i++) {
      actor->if_array_word(this,i);
   }
   actor->if_siat_do_once_after_children(this); // <-- safe?
}

//why aren't I just having all of these just get one?
//food for thought.
//i mean, just call contains and gj, but...
void GroupedIntArrayTrie::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int currentDepth) const
{
//   std::cout << "Starting GACBB" << std::endl;
   int loc = 0;
   for (int i = currentDepth; i < input.size(); i++) {
      loc = 3 * loc + input.at(i);
      if (wordBits[loc]) {
         //as stopgap, just return the one. i guess.
         //TODO: get all.
         output.push_back(prevWord);
         for ( int j = currentDepth; j <= i; j++) {
            output.back().at(j) = input.at(j);
         }
         output.back().at(i+1) = -1;
  //       std::cout << "Returning succ." << std::endl;
         return; 
      }
   }
   //is contained by nothing
//  std::cout << "Returning unsucc." << std::endl;
}

int GroupedIntArrayTrie::size() {
   if (wordBits[1] || (wordBits[2] && wordBits[3])) { //long form nec?
      return true;
   }
   return false;
}

std::string GroupedIntArrayTrie::getType() {
   return string("GroupedIntArrayTrie");
}

void GroupedIntArrayTrie::print() {
   std::cout << "This contains: ";
   for (int i = 0; i < wordBits.size(); i++) {
      if (wordBits[i]) {
         std::cout << i << ", ";
      }
   }
   std::cout << "." << std::endl;
}

/*
//testing porpoises.
int main() {
   GroupedIntArrayTrie bob(0, 3);
   vector<int> testVector;
   testVector.push_back(3);
   testVector.push_back(3);
   bob.insert(testVector);
   testVector.at(0) = 1; testVector.at(1) = 2;
   std::cout << std::endl;
   bob.print();
   std::cout << std::endl;

   bob.insert(testVector);
   std::cout << std::endl;
   bob.print();
   std::cout << std::endl;

   testVector.at(0) = 2; testVector.pop_back();
   bob.insert(testVector);
   std::cout << "Insertion complete" << std::endl;
   std::cout << std::endl;
   bob.print();
   std::cout << std::endl;
   vector<int> output;
   output.resize(2, -1);
   bool result = bob.contains(testVector, output);
   std::cout << "Result is: " << result << std::endl;
}*/
