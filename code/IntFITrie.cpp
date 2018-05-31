//IntFITrie.cpp

#include "IntFITrie.h"
#include <iostream>

IntFITrie::IntFITrie(int mD) : IntIntervalTrie(mD) {
   //nothing to do
}

IntFITrie::~IntFITrie() {
   for (map<int,GenericIntTrie*>::iterator it = branches.begin();
      it!=branches.end();
      it++) 
   {
      delete it->second;
   }
}

bool IntFITrie::isFinalLayer(const vector<int>& box) {
   for (int i = myLayer+1; i < box.size(); i++) {
      if (box.at(i)!=0) {
         return false;
      }
   }
   return true;
}

//Return value states whether or not the layer is full
int IntFITrie::insert(const vector<int>& box) {
   
   if (this->isFinalLayer(box)) {
      //just insert it into the intervals
      IntIntervalTrie::insert(box);
   } else {
      //find, insert in branches
      int val = box.at(myLayer);
      bool result = false;
      
      if (branches.count(val)) {
         result = branches[val]->insert(box);
      }
      else {
         pair<int, GenericIntTrie*> tbi;
         tbi.first = val;
         if (box.size() > 2) {
            tbi.second = new IntFITrie(maxNodeID);
         } else { //size is exactly one, so just use an IntervalTrie
            tbi.second = new IntIntervalTrie(maxNodeID);
         }
         tbi.second->setMyLayer(myLayer+1);
         tbi.second->insert(box);
         branches.insert(tbi);
      }
   }   
   
   return false;
}

int IntFITrie::size() {
   return branches.size() + intervals.size();
}

bool IntFITrie::contains(const vector<int>& box, vector<int>& output) {
   /*std::cout << "Checking: ";
   for (int i = 0; i < box.size(); i++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl;*/
   
   if(IntIntervalTrie::contains(box, output)) {
      return true;
   }
 //  std::cout << "Going the distance." << std::endl;
   
   //else, search branches
   int val = box.at(myLayer);
   map<int,GenericIntTrie*>::iterator it;
   for (int val = box.at(myLayer); val > 0; val >>=1 ) {
    //  std::cout << "Str: " << strVal;
      it = branches.lower_bound(val);
      if (it!=branches.end() && it->first == val) {
         if (it->second->contains(box, output)) {
            output[myLayer] = val;
            return true;
         }
      }
   }
   
   return false;
   
}

