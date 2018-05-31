//FertileIntervalTrie.cpp

#include "FertileIntervalTrie.h"
#include <iostream>

FertileIntervalTrie::FertileIntervalTrie(int mD) : IntervalTrie(mD) {
   //nothing to do
}

FertileIntervalTrie::~FertileIntervalTrie() {
   for (map<string,GenericTrie*>::iterator it = branches.begin();
      it!=branches.end();
      it++) 
   {
      delete it->second;
   }
}

bool FertileIntervalTrie::isFinalLayer(const vector<string>& box) {
   for (int i = 1; i < box.size(); i++) {
      if (box.at(i)!="") {
         return false;
      }
   }
   return true;
}

//Return value states whether or not the layer is full
bool FertileIntervalTrie::insert(const vector<string>& box) {
   
   vector<string> fakeOutput;
  /* if (this->contains(box, fakeOutput)) {
      //can't add
      std::cout << "Bad input detected!" << std::endl;
      string temp;
      std::cin >> temp;
      
      return false;
   }*/
   
   if (this->isFinalLayer(box)) {
      //just insert it into the intervals
      vector<string> tempBox;
      tempBox.push_back(box.at(0));
      IntervalTrie::insert(tempBox);
   } else {
      //find, insert in branches
      string strVal = box.at(0);
      bool result = false;
      vector<string> subbox;
      for (int i = 1; i < box.size(); i++) {
         subbox.push_back(box.at(i));
      }
      
      if (branches.count(strVal)) {
         result = branches[strVal]->insert(subbox);
      }
      else {
         if (subbox.size() > 1) {
            pair<string, GenericTrie*> tbi(
                  strVal, new FertileIntervalTrie(maxNodeID));
            tbi.second->setMyLayer(myLayer+1);
            tbi.second->insert(subbox);
            branches.insert(tbi);
         } else { //size is exactly one, so just use an IntervalTrie
            pair<string, GenericTrie*> tbi(
                  strVal, new IntervalTrie(maxNodeID));
            tbi.second->setMyLayer(myLayer+1);
            tbi.second->insert(subbox);
            branches.insert(tbi);
         }
      }
      
      //if returned true below, then the corresponding branch is full
      //so we'll merge it up into this layer
   /*   if (result==true) {
         map<string, GenericTrie*>::iterator itStart = branches.find(strVal);
         map<string, GenericTrie*>::iterator itEnd = itStart;
         delete itStart->second;
         itEnd++;
         while (itEnd!=branches.end() && 
               itEnd->first.size() > itStart->first.size()
         ) {
            delete itEnd->second;
            itEnd++;
         }
         branches.erase(itStart, itEnd);
         vector<string> tempBox;
         tempBox.push_back(strVal);
         IntervalTrie::insert(tempBox);
      }*/
      //if result==false, nothing to be done
   }   
   
   //return this->isFull();
   return false;
}

int FertileIntervalTrie::size() {
   return branches.size() + intervals.size();
}

bool FertileIntervalTrie::contains(
      const vector<string>& box, 
      vector<string>& output) 
{
   /*std::cout << "Checking: ";
   for (int i = 0; i < box.size(); i++) {
      std::cout << box.at(i) << ", ";
   }
   std::cout << std::endl;*/
   
   if(IntervalTrie::contains(box, output)) {
      return true;
   }
 //  std::cout << "Going the distance." << std::endl;
   
   //else, search branches
   string strVal = box.at(myLayer);
   map<string,GenericTrie*>::iterator it;
   for (;;) {
    //  std::cout << "Str: " << strVal;
      it = branches.lower_bound(strVal);
      if (it!=branches.end() && it->first == strVal) {
         if (it->second->contains(box, output)) {
            output[myLayer].swap(strVal);
            return true;
         }
      }
      if (strVal.size()==0) {
         break;
      } else {
         strVal.pop_back();
      }
   }
   
   return false;
   
}
