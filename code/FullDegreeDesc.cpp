//FullDegreeDesc.cpp

#include <iostream>
#include "FullDegreeDesc.h"
using std::string;
using std::vector;

FullDegreeDesc::~FullDegreeDesc() {
   //nothing to clean up
}

string FullDegreeDesc::getType() const {
   return string("fullDegreeDesc");
}

vector<int> FullDegreeDesc::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts) 
{
   
   int insertedSoFar = 0;
   
   vector<int> mappings(counts.size());
   
   for (int insertedSoFar = 0; insertedSoFar < counts.size() - 1; insertedSoFar++) {
      std::sort(++counts.begin() + insertedSoFar, counts.end(), 
         [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
         });
               
      int insertedValue = counts.at(1+insertedSoFar).first;
      //remove this edge from every other thingy
      for (int i = 0; i < input.size(); i++) {
         bool flag = false;//determining if input in question contains insertedValue
         for (int j = 0; j < input.at(i).size(); j++) {
            if (input.at(i).at(j) == insertedValue) {
               flag = true;
               break;
            }
         }
         if (flag) { //if so, erase from counts
            for (int j = 0; j < input.at(i).size(); j++) {
               if (input.at(i).at(j) != insertedValue) {
                  for (int k = 2 + insertedSoFar; k < counts.size(); k++) {
                     if (counts.at(k).first == input.at(i).at(j)) {
                        counts.at(k).second--;
                        break;
                     }
                  }//end loop over counts
               }
            }//end loop over each element of input that contains the inserted value
         }
      } //end loop over all inputs
   }//end insertion
    
   //invert the mapping
   for (int i = 1; i < counts.size(); i++) {
      mappings.at(counts.at(i).first) = i;
   }
   
   return mappings;
}