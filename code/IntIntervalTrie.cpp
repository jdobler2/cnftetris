//IntIntervalTrie.cpp

#include "IntIntervalTrie.h"
#include <iostream>
#include <cmath>

IntIntervalTrie::IntIntervalTrie(int mD) {
   maxNodeID = mD;
   //waste space, saves time...
   maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   finalLevelStart = (1 << maxDepth);
}

IntIntervalTrie::~IntIntervalTrie() {
}

pair<size_t, size_t> IntIntervalTrie::convertToPair(const int& binValue) const {
   size_t leftID = binValue;
   size_t difference = 1;
   
   while (leftID < finalLevelStart) {
      leftID = (2 * leftID);
      difference *= 2;
   }
   
   size_t rightID = leftID + difference;
   
   //adjust so we count from 0
   leftID -= finalLevelStart;
   rightID -= finalLevelStart;
   
   //double them to tell apart lefts, rights
   leftID = leftID * 2;
   rightID = rightID * 2 - 1;
   
   pair<size_t, size_t> tbr(leftID, rightID);
   
   return tbr;
}

bool IntIntervalTrie::isRightBoundary(size_t val) const {
   return (val % 2 == 1);
}

//almost identical
bool IntIntervalTrie::contains(const vector<int>& box, vector<int>& output){
      
   pair<size_t, size_t> val = convertToPair(box.at(myLayer));
   
   set<size_t>::iterator it_lower = intervals.lower_bound(val.first);
   set<size_t>::iterator it_upper = intervals.lower_bound(val.second);
   
   if (it_upper==intervals.end() || !isRightBoundary(*it_upper)) {
      return false;
   }
   
   if (isRightBoundary(*it_lower)) {
      it_lower--;
   }
   
  /* std::cout << "lower: " << *it_lower << ", upper: " << *it_upper << ", first: " <<  val.first << ", second: " << val.second << std::endl; */
   
   if ((*it_lower<=val.first) && (*it_upper>=val.second)) {
      if ((++it_lower)==it_upper) {
         it_lower--;
         output.at(myLayer) = quickBuildDyadic(
                                  box.at(myLayer), *it_lower, *it_upper,
                                  val.first, val.second);
         return true;
      }
   }

   return false;
}

//mostly identical
int IntIntervalTrie::insert(const vector<int>& box) {
/*   std::cout << "box-size is: " << box.size() << "; my layer is " << myLayer << std::endl;
  std::cout << "inserting... " << box.at(myLayer) << std::endl;
   std::cout << "Size: " << intervals.size() << std::endl;*/
   pair<size_t, size_t> val = convertToPair(box.at(myLayer));

//   std::cout << "pair: " << val.first << ", " << val.second << std::endl;
   
   //for simplicity, just insert it if empty
   if (intervals.size()==0) {
      intervals.insert(val.first);
      intervals.insert(val.second);

      return this->isFull();
   }
   
   set<size_t>::iterator it_lower = intervals.upper_bound(val.first);
   set<size_t>::iterator it_upper = intervals.lower_bound(val.second);
   
   bool needInsertLeft = true;
   bool needInsertRight = true;
   
   //handle left side
   if (it_lower!=intervals.begin()) {
      it_lower--;
      if (isRightBoundary(*it_lower)) {
         //do nothing
      } else {
         needInsertLeft = false;
      }
      it_lower++;
   }

   //handle right side
   if (it_upper!=intervals.end()) {
      if (isRightBoundary(*it_upper)) { 
         needInsertRight = false;
      } else {
         //do nothing--want to delete up through where it_upper is
      }
   }
   
   
   if (it_upper == intervals.end() || *it_lower < *it_upper) { //necessary?
      intervals.erase(it_lower, it_upper);
   }
   
   if (needInsertLeft) {
      intervals.insert(val.first);
   }
   if (needInsertRight) {
      intervals.insert(val.second);
   }
    
   //return this->isFull();
    
   return false;
}

//100% identical
bool IntIntervalTrie::remove_inner(pair<size_t, size_t>& val) {
   set<size_t>::iterator it_lower = intervals.lower_bound(val.first);
   set<size_t>::iterator it_upper = intervals.upper_bound(val.second);

   bool needInsertLeft = false;
   size_t leftInsertVal = 0;
   bool needInsertRight = false;
   size_t rightInsertVal = 0;
   bool retValue = false;
   
   //delete from left
   if (it_lower==intervals.end() || !isRightBoundary(*it_lower)) {
      //do nothing--we want to delete
   } else { //is a right bound, so we need to insert a new boundary
            //before where we currently are
      needInsertLeft = true;
      leftInsertVal = val.first - 1;
   }
   
   //delete from right
   if (it_upper == intervals.end() || !isRightBoundary(*it_upper)) {
      if (it_upper!=intervals.end() && *it_upper==val.second+1) {
         it_upper++;
      }
   } else {
      needInsertRight = true;
      rightInsertVal = val.second + 1;
   }
   
   intervals.erase(it_lower, it_upper);
   
   //remove subsumed intervals
   if (needInsertLeft) {
      intervals.insert(leftInsertVal);
   }
   if (needInsertRight) {
      intervals.insert(rightInsertVal);
   }
   
   return retValue;
}

//mostly ident
bool IntIntervalTrie::remove(const vector<int>& box) {

   pair<size_t, size_t> val = convertToPair(box.at(myLayer));
   //check for empty intervals
   if (intervals.size()==0) {
      return false;
   }
   
   return remove_inner(val);
}

//100% identical
bool IntIntervalTrie::remove_for_size(size_t left, size_t right) {
   set<size_t>::iterator it_lower = intervals.lower_bound(left);
   set<size_t>::iterator it_upper = intervals.lower_bound(right);
   
   int correctLeft = left;
   int correctRight = right;
   //(check for legality is unnecessary
   
   
   //handling left side
   if (*it_lower==left) { //check for guaranteed safety on left
      //left is good
   } 
   else { //it_lower passed left and is on the next right-hand bound
      it_lower--; //adjust to correct LHB
      int val = *it_lower;
      while (val < left) {
         int distance = 4;
         while (val % distance == 0 && val + distance <= *it_upper + 1) {
            distance*=2;
         }
         distance/=2;
         
         if (val + distance > correctLeft) 
         {
            correctLeft = val + distance;
         }
         
         val+=distance;
      }
   }
   
   //handling right side
   if (*it_upper==right) { //check for guaranteed safety on right
      //right is good
   } 
   else { //it_upper is past right, on the RHB.
      int val = *it_upper;
      val++;
      while (val > right + 1) {
         int distance = 4;
         while (val % distance == 0 && val-distance >= *it_lower) {
            distance*=2;
         }
         distance/=2;
         
         if (val - distance - 1 < correctRight) 
         {
            correctRight = val - distance - 1;
         }
         val-=distance;
      }
   }
   
   /*
   std::cout << "Left: " << left << ", Right: " << right << std::endl;
   std::cout << "Lower: " << *it_lower << ", upper: " << *it_upper << std::endl;
   std::cout << "CorrectLeft: " << correctLeft << ", CorrectRight: " << correctRight << std::endl;
   */
   //remove if possible
   if (correctLeft < correctRight) {
      pair<size_t, size_t> temp(correctLeft, correctRight);
      return remove_inner(temp);
   }
   
}

//identical
void IntIntervalTrie::apply(trie_actor* actor) {
   actor->if_interval(this);
}

//identical
int IntIntervalTrie::size() {
   //TODO: make more thorough?
   return intervals.size();
}

//identical
set<size_t> IntIntervalTrie::getIntervals() {
   return intervals;
}

//identical
void IntIntervalTrie::setIntervals(set<size_t>& newIntervals) {
   intervals = newIntervals;
}

//identical
bool IntIntervalTrie::isFull() {
   if (this->size()==2) {
      set<size_t>::iterator it = intervals.begin();
      if (*it == 0) {
         if (*(it++)==maxNodeID*2+1) {
            return true;
         }
      }
   }
   return false;
}

//completely different
void IntIntervalTrie::getAllContainingBoxes(
   const vector<int>& input,
   vector<pair<dataLayerPair, dataLayerPair> >& output,
   vector<int>& prevWord) const
{
 //  std::cout << "In IV::gacb" << std::endl;
   pair<size_t, size_t> val = convertToPair(input.at(myLayer));
 
   set<size_t>::iterator it_lower = intervals.lower_bound(val.second);
   set<size_t>::iterator it_upper;
   if (it_lower!=intervals.end()) {
      if (isRightBoundary(*it_lower)) {
         //need to build dyadic box out of the two bounds
         it_upper = it_lower;
         it_lower--;
         
         output.push_back(pair<dataLayerPair, dataLayerPair>(
            dataLayerPair(prevWord.front(), 1), 
            dataLayerPair(quickBuildDyadic(input.at(myLayer),
                  *it_lower, *it_upper, val.first, val.second),
               1)
            ));
            
         return;
      }
   }
}

//Test this heavily!
int IntIntervalTrie::quickBuildDyadic(const int& input, 
                              int leftInt, int rightInt, 
                              int lowBound, int upBound) const 
{
   int output = input;
   
   //If input isn't a point, we're screwed.
   /*
   if (input < finalLevelStart) {
      std::cout << "ERR: IIT::QBD -- input too small!" << std::endl;
   }*/
   
   int mult = 2;
   
   for(;;) {
      if (output % 2 == 0) { //left hand side
         upBound+=mult;
         if (upBound > rightInt) {
            break;
         }
      } else { // is == 1 -- i.e., right-hand side
         lowBound-=mult;
         if (lowBound < leftInt) {
            break;
         }
      }
      //go another round
      output >>= 1;
      mult*=2;
   }
   
 //  std::cout << "Input: " << input << " in bounds " << leftInt << ", " <<rightInt << "produced " << output << std::endl;
   //TODO: switch to not returning? I'm passing by ref anyways...
   //Const probs tho.
   return output;
}
