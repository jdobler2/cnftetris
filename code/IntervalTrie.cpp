//IntervalTrie.cpp

#include "IntervalTrie.h"
#include <iostream>
#include <cmath>

IntervalTrie::IntervalTrie(int mD) {
   maxNodeID = mD;
   //wastes space, saves time...
   maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
}

IntervalTrie::~IntervalTrie() {
}

pair<size_t, size_t> IntervalTrie::convertToInt(const string& binValue) const {
   size_t leftID = 0;
   for (int i = 0 ; i < binValue.length(); i++) {
      leftID *= 2;
      leftID += (binValue[i] - '0');
   }
 //  int maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   int additionalDoublings = maxDepth - binValue.length();
   size_t difference = 1;
   for (int i = 0; i < additionalDoublings; i++) {
      leftID *= 2;
      difference *= 2;
   }
   
   size_t rightID = leftID + difference;
   //if (rightID > maxNodeID) {rightID = maxNodeID+1;}
   
   //double them to tell apart lefts, rights
   leftID = leftID * 2;
   rightID = rightID * 2 - 1;
   
   pair<size_t, size_t> tbr(leftID, rightID);
   
   return tbr;
}

bool IntervalTrie::isRightBoundary(size_t val) const {
   return (val % 2 == 1);
}

bool IntervalTrie::contains(const vector<string>& box, vector<string>& output){
      
   pair<size_t, size_t> val = convertToInt(box.at(myLayer));
   
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

bool IntervalTrie::insert(const vector<string>& box) {
//   std::cout << "inserting..." << std::endl;
//   std::cout << "Size: " << intervals.size() << std::endl;
   pair<size_t, size_t> val = convertToInt(box.at(box.size()-1));

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

bool IntervalTrie::remove_inner(pair<size_t, size_t>& val) {
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

bool IntervalTrie::remove(const vector<string>& box) {

   pair<size_t, size_t> val = convertToInt(box.at(box.size()-1));
   //check for empty intervals
   if (intervals.size()==0) {
      return false;
   }
   
   return remove_inner(val);
}

bool IntervalTrie::remove_for_size(size_t left, size_t right) {
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

void IntervalTrie::apply(trie_actor* actor) {
   actor->if_interval(this);
}

int IntervalTrie::size() {
   //TODO: make more thorough?
   return intervals.size();
}

set<size_t> IntervalTrie::getIntervals() {
   return intervals;
}

void IntervalTrie::setIntervals(set<size_t>& newIntervals) {
   intervals = newIntervals;
}

bool IntervalTrie::isFull() {
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

//hey, this is always being called on a point, right?
//I can use that
vector<vector<string> > IntervalTrie::getAllContainingBoxes(
   const vector<string>& input,
   vector<string>& prevWord) const
{
 //  std::cout << "In IV::gacb" << std::endl;
   vector<vector<string> > output;
   int locInInput = prevWord.size();
   pair<size_t, size_t> val = convertToInt(input.at(locInInput));

 //  std::cout << "Val is: " << val.first << ", " << val.second << std::endl;
 //  std::cout << "Prevword is: " << prevWord.back() << std::endl;
 
   set<size_t>::iterator it_lower = intervals.lower_bound(val.first);
   set<size_t>::iterator it_upper = intervals.lower_bound(val.second);
   if (it_upper!=intervals.end()) {
      if (isRightBoundary(*it_upper)) {
         if (!isRightBoundary(*it_lower)) {
            if (*it_lower<=val.first && *it_upper >= val.second) {
            
               //since it's a point, I don't have to check they're neighbors.
               
               //need to build dyadic box out of the two bounds
               vector<string> box;
               for (int i = 0; i < prevWord.size(); i++) {
                  box.push_back(prevWord.at(i));
               }
               box.push_back(quickBuildDyadic(input.at(locInInput),
                  *it_lower, *it_upper, val.first, val.second));

               output.push_back(box);
               return output;
            }
         } else { //it_lower is a right boundary
            if (it_lower==it_upper) {
               //need to build dyadic box out of the two bounds
               it_lower--;
               vector<string> box;
               for (int i = 0; i < prevWord.size(); i++) {
                  box.push_back(prevWord.at(i));
               }
               box.push_back(quickBuildDyadic(
                       input.at(locInInput), 
                       *it_lower, *it_upper, 
                       val.first, val.second)
               );
                
               output.push_back(box);
               return output;
            }
         }//end boundary check on it_lower
      }//if it_upper is a left boundary, we're out-of-bounds for sure
   }
   //if we're here, it wasn't in Intervals. 
  // std::cout << "Failed to find." << std::endl;
   return output;
}

string IntervalTrie::quickBuildDyadic(const string& input, 
                              int leftInt, int rightInt, 
                              int lowBound, int upBound) const 
{
   string output = input;
   int diff = maxDepth - output.size();
   int mult = 2;
   while (diff > 0) {
      mult*=2;
      diff--;
   }
   
   for(;;) {
      if (output.back()=='0') {
         upBound+=mult;
         if (upBound > rightInt) {
            break;
         }
      } else { //is a '1'
         lowBound-=mult;
         if (lowBound < leftInt) {
            break;
         }
      }
      //go another round
      output.pop_back();
      mult*=2;
   }
   
   //TODO: switch to not returning? I'm passing by ref anyways...
   //Const probs tho.
   return output;
}

//deprecated
string IntervalTrie::buildDyadic(size_t leftInt, size_t rightInt, 
                                 size_t lowBound, size_t upBound) const 
{
   //idea is to create power-of-two blocks until we can't do so anymore,
   //then figure out what the ocrresponding string is
   if (lowBound!=upBound-1) {
      std::cout << "ERR: Not prepared to handle such a big point!"<< std::endl;
      string temp;
      std::cin >> temp;
   }
   
 //  std::cout << "Init leftInt: " << leftInt << ", init rightInt: " << rightInt << std::endl;
   
   //converting to non-multiplied, to make life easier. TODO: don't do this?
   leftInt = (leftInt)/2;
   rightInt = (rightInt)/2;
   lowBound = (lowBound)/2;
   upBound = (upBound)/2;
   //=======================================================================
   //NOTE: Unlike inside the IntervalTrie, all bounds here will be INCLUSIVE.
   //=======================================================================
   
   size_t multCount = 0;
   
   //now, to expand to dyadic bounds.
   for (size_t mod = 2;;mod*=2) {
      size_t newLowerBound = (lowBound/mod)*mod;
      size_t newUpperBound = (lowBound/mod)*mod+mod-1;
      if (newLowerBound < leftInt || newUpperBound > rightInt) {
         break;
      }
      lowBound = newLowerBound;
      upBound = newUpperBound;
      multCount++;
   }
   
   //print results for debug
 //  std::cout << "Lowbound: " << lowBound << ", upBound: " << upBound << ", leftInt: " << leftInt << ", rightInt: " << rightInt << std::endl;
   
   
   //convert to string
   return convertToString(lowBound, multCount);
   
}

//currently unused, but may be useful in the future.
string IntervalTrie::convertToString(size_t lower, size_t multCount) const {
 //  std::cout << "Lower: " << lower << ", multCount: " << multCount << std::endl;
   char buffer[100];
   buffer[maxDepth-multCount] = '\0';
   int loc = maxDepth - 1 - multCount;
   
   while (multCount > 0) {
      lower/=2;
      multCount--;
   }
   
   while (loc >= 0) {
      int modValue = lower % 2;
      modValue += '0';
      buffer[loc] = (char)modValue;
      loc--;
      lower /= 2;
   }
   
   return string(buffer);
}
