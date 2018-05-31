// ============================================================================
// DegreeRelation.cpp
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// - implementation of the DegreeRelation class
// ============================================================================
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>

#include "DegreeRelation.h"

using std::vector;
using std::pair;
using std::make_pair;

void DegreeRelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   sortRawTuples(rawTuples, true);
   vector<pair<unsigned, unsigned> >::iterator pairIt;

   // construct the adjacency list from the sorted raw tuples
   vector<pair<unsigned, vector<unsigned> > > adjList;
   fillPairs(rawTuples, adjList);
   
   pairs.clear();
   pairs.resize(adjList.size(), make_pair(0, vector<unsigned>()));

   // redo in degree order
   sort(adjList.begin(), adjList.end(), degreeComparitor);

   size_t i;
   vector<int> included(maxNodeID+1, -1); // TODO: fast but VERY space consuming
   vector<int> mapping(maxNodeID+1, -1);

   for (i = 0; i < adjList.size(); i++) {
      included[adjList[i].first] = i;
      adjList[i].first = i;
   }

   for (i=0; i < adjList.size(); i++) {
      for (size_t j=0; j < adjList[i].second.size(); j++) {
         adjList[i].second[j] = included[adjList[i].second[j]];
      }
      sort(adjList[i].second.begin(), adjList[i].second.end());
   }

   for (i=0; i < adjList.size(); i++) {
      for (size_t j = 0; j < adjList[i].second.size()+1; j++) {
         if (j == adjList[i].second.size()) {
         } else if (adjList[i].second[j] <= i) {
            continue;
         }
         
         if (j==0) break;
         adjList[i].second.assign(adjList[i].second.begin()+j,
                                  adjList[i].second.end());
         break;
      }
   }
   //finish doing in degree order

   //assert: i = adjList.size()
   size_t overflow_counter = i;
   size_t mapCounter = 0;

   //int stackIndex = 0;
   vector<unsigned> tempNeighbors;
   vector<unsigned> stack(adjList.size());
   int stackCounter = 0;
   int exclusionCount = 0;


   for (i=0; i <adjList.size(); i++) {
      if (adjList[i].second.size()!=0) {
         included[i] = i;
      } else {
         included[i] = -1;
         exclusionCount++;
      }
   }

   buildMapping(adjList, stack, mapping, included, mapCounter, overflow_counter);

   stackCounter = 0;
   stack.clear();
   tempNeighbors.clear();

   pairs.resize(mapCounter);

   //now, loop through to reassign to all the BFS mapping values
   for (i=0; i < adjList.size(); i++) {
      int loc = mapping[adjList[i].first];
      if (loc < mapCounter) {
         pairs[loc].second.swap(adjList[i].second);
      }
   }

   for (i=0; i < pairs.size(); i++) {
      for (size_t j=0; j < pairs[i].second.size(); j++) {
         pairs[i].second[j] = mapping[pairs[i].second[j]];
      }
      sort(pairs[i].second.begin(), pairs[i].second.end());
   }

}
