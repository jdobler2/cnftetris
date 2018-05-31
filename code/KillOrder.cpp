//KillOrder.cpp

#include "KillOrder.h"
#include <iostream>
#include <unordered_set>

using std::string;
using std::vector;
using std::unordered_set;

KillOrder::KillOrder() {
}

KillOrder::~KillOrder() {
	//nothing to clean up
}

string KillOrder::getType() const {
	return string("killOrder");
}

vector<int> KillOrder::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   vector<int> mappings(counts.size());
   vector<unordered_set<int> > pairNeighbors(counts.size());
   
   //build pairNeighbors
   for (auto& v : input) {
      if (v.size() > 2) continue; //consider making bigger than 2?
      for (int i = 0; i < v.size(); i++) {
         int loc1 = std::abs(v[i]);
         for (int j = 0; j < v.size(); j++) {
            if (i==j) continue;
            pairNeighbors.at(loc1).insert(std::abs(v[j]));
         }
      }
   }
   
   vector<int> liveCounts(counts.size());
   int maxLoc = 0;
   int maxSize = pairNeighbors.at(0).size();
   for (int i = 1; i < pairNeighbors.size(); i++) {
      if (pairNeighbors.at(i).size() > maxSize) {
         maxLoc = i; 
         maxSize = pairNeighbors.at(i).size();
      }
   }
   counts.at(1).swap(counts.at(maxLoc));
   for (int i : pairNeighbors.at(maxLoc)) {
      liveCounts.at(i)++;
   }
   
   //main loop.  n^2.
   for (int i = 2; i < counts.size() - 1; i++) {
      int maxLoc = i;
      int maxSize = pairNeighbors.at(counts.at(i).first).size();
      int maxLive = liveCounts.at(counts.at(i).first);
      for (int j = i + 1; j < counts.size(); j++) {
         int newLoc = counts.at(j).first;
         int oldLoc = counts.at(i).first;
         if (liveCounts.at(newLoc) > maxLive || (liveCounts.at(newLoc) == maxLive && pairNeighbors.at(newLoc).size() > maxSize)) {
            maxLoc = j;
            maxSize = pairNeighbors.at(newLoc).size();
            maxLive = liveCounts.at(newLoc);
         }
      }
      
      int finalLoc = counts.at(maxLoc).first;
      counts.at(i).swap(counts.at(maxLoc));
      for (int j : pairNeighbors.at(finalLoc)) {
         liveCounts.at(j)++;
      }
   }
   
   //invert the mapping
   for (int i = 1; i < counts.size(); i++) {
      mappings.at(counts.at(i).first) = i;
   }
   
   return mappings;
}