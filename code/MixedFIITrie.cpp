//MixedFIITrie.cpp

#include "MixedFIITrie.h"
#include <iostream>
#include <cmath>

MixedFIITrie::MixedFIITrie(int mD) {
   maxNodeID = mD;
   //waste space, saves time...
   maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   finalLevelStart = (1 << maxDepth);
}

MixedFIITrie::~MixedFIITrie() {
}

void MixedFIITrie::convertToPair(int& upperBound, iData& data) const {
   data.lowBound = data.actValue;

   size_t difference = 1;
   
   while (data.lowBound < finalLevelStart) {
      data.lowBound *= 2;
      difference *= 2;
   }
   
   upperBound = data.lowerBound + difference - 1;   
}

bool FixedIITrie::contains(const vector<int>& box, vector<int>& output){
         
   map<size_t, pair<size_t, size_t> >::iterator it = 
         intervals.lower_bound(box.at(myLayer));
   
   if (it!=intervals.end()) {
      if (it->second.lowBound <= box.at(myLayer)) {
         output.at(myLayer) = it->second.second;
         return true;
      }
   }

   return false;
}
