//LocksOrder.cpp

#include "LocksOrder.h"
#include <iostream>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

LocksOrder::LocksOrder() {
   mAssignedAtEnd = 0;
}

LocksOrder::~LocksOrder() {
	//nothing to clean up
}

string LocksOrder::getType() const {
	return string("locksOrder");
}

vector<int> LocksOrder::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   vector<int> mappings(counts.size());
   vector<vector<double> > adjMatrix;
   buildAdjacencyMatrix_Weighted(adjMatrix, input, counts);
   // std::cout << "Adjmatrix: \n";
   // for (int i = 0; i < adjMatrix.size(); i++) {
      // for (int j = 0; j < adjMatrix[i].size(); j++) {
         // std::cout << adjMatrix[i][j] << ", ";
      // }
      // std::cout << std::endl;
   // }
   // std::cout << std::endl;
   
   //sorting, not really done anymore.
   // std::sort(++counts.begin(), counts.end(), 
      // [](pair<int, int> a, pair<int, int> b) {
         // return a.second > b.second;
      // });
      
   mAssignedAtEnd = 0;
   unordered_set<int> assignedValues;
   bool cry = false;
   while (!cry) {
      cry = true;
      int bestCandidateLoc = -1;
      int bestCandidateSize = counts.size() * 2;
      //cycle over all, find best
      for (int i = 1; i < counts.size() - mAssignedAtEnd; i++) {
         int loc = std::abs(counts.at(i).first);
         if (assignedValues.count(loc)) {
            continue;
         }
         vector<int> toAdd;
         for (int j = 0; j < adjMatrix[loc].size(); j++) {
            if (adjMatrix[loc][j] > 0 && !assignedValues.count(j)) {
               toAdd.push_back(j);
            }
         }
         if (toAdd.size() < bestCandidateSize) {
            bestCandidateSize = toAdd.size();
            bestCandidateLoc = i;
            cry = false;
         }
      }
      //grab best one
      if (!cry) {
         vector<int> toAdd;
         int loc = std::abs(counts.at(bestCandidateLoc).first);
         for (int j = 0; j < adjMatrix[loc].size(); j++) {
            if (adjMatrix[loc][j] > 0) {
               toAdd.push_back(j);
            }
         }
         //std::cout << "Ruling out " << toAdd.size() << " vars." << std::endl;
         assignedValues.insert(toAdd.begin(), toAdd.end());
         // std::cout << "Total banned: " << assignedValues.size() << std::endl;
         // std::cout << "Placing " << loc << " at end." << std::endl;
         counts.at(bestCandidateLoc).swap(counts.at(counts.size()-1-mAssignedAtEnd));
         mAssignedAtEnd++;
      }
   }
   
   std::cout << "Assigned " << mAssignedAtEnd << " at end." << std::endl;
      
   //! Do remainder in DegreeDesc ordering.
   int assignedCount = 1;
   for (int i = 2; i < counts.size() - mAssignedAtEnd; i++) {
      double maxIC = -1.0;
      int maxCount = -1;
      int maxLocation = -1;
      for (int j = i; j < counts.size() - mAssignedAtEnd; j++) {
         double newIC = 0.0;
         for (int k = 1; k <= assignedCount; k++) {
            newIC += adjMatrix[std::abs(counts.at(j).first)][std::abs(counts.at(i-k).first)];
         }
         int newCount = counts.at(j).second;
         if (newIC > maxIC || (newIC == maxIC && newCount > maxCount)) {
            maxIC = newIC;
            maxLocation = j;
            maxCount = newCount;
         }
      }
      counts.at(i).swap(counts.at(maxLocation));
      assignedCount++;
      assignedCount%=layerSize;
      //note that, if assignedCount==0, a full group has been assigned
      
      //exit if there's not more than a full set of layerSize left
      if (assignedCount == 0 && (i + 1 + layerSize) >= counts.size()) break;
   }
            
   //invert the mapping
   for (int i = 1; i < counts.size(); i++) {
      mappings.at(counts.at(i).first) = i;
   }
   
   //make mAssignedAtEnd correspond to number of layers
   int modLayers = (counts.size() - 1) % layerSize;
   int temp = mAssignedAtEnd;
   mAssignedAtEnd = ((mAssignedAtEnd - modLayers)/layerSize);
   if (modLayers != 0 && temp > modLayers) mAssignedAtEnd++;
   std::cout << "declaring last " << mAssignedAtEnd << " layers to be locked." << std::endl;
   
   return mappings;
}

int LocksOrder::getExtra() const {
   return mAssignedAtEnd;
}
