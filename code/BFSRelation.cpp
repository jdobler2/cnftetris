// ============================================================================
// BFSRelation.cpp
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// ============================================================================
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>

#include "BFSRelation.h"

void BFSRelation::buildIndex(std::vector<std::pair<unsigned, unsigned> >& rawTuples)
{
   //properly loads the pairs and computes maxNodeID
   SimpleRelation::buildIndex(rawTuples); 

   std::vector<std::pair<unsigned, std::vector<unsigned> > > newPairs;
   newPairs.swap(pairs); // this is VERY efficient, as only pointers are swapped

   std::vector<int> included(maxNodeID+1, -1);
   for (size_t i = 0; i < newPairs.size(); i++) {
      included[newPairs[i].first] = i;
   }

   std::vector<unsigned> queue(newPairs.size());
   std::vector<int> mapping(maxNodeID+1, -1);
   size_t numVisitedVertices = 0; // so far
   size_t overflow_counter = newPairs.size();
   
   buildMapping(newPairs, queue, mapping, included, numVisitedVertices,
                overflow_counter);
   
   pairs.resize(newPairs.size(), make_pair(0, std::vector<unsigned>()));

   // now, loop through to reassign to all the BFS mapping values
   for (size_t i = 0; i < newPairs.size(); i++) {
      size_t idx = mapping[newPairs[i].first];
      pairs[idx].second.swap(newPairs[i].second);
      for (size_t j = 0; j < pairs[idx].second.size(); j++) {
         pairs[idx].second[j] = mapping[pairs[idx].second[j]];
      }
      sort(pairs[idx].second.begin(), pairs[idx].second.end());
   }
}

unsigned long BFSRelation::performFroggerTricount(size_t start, size_t end) 
{
   unsigned long c=0;
   size_t j, tmp, k, l;
   for (size_t i=start; i<end; i++) {
      // compute the intersection of edges[i].second (neighbors of
      // edges[i].first), and the set of values in edges.first
      j = 0, tmp = 0;
      while (true) {
         // leap frogging to next j
         j = pairs[i].second[tmp];

         if (j >= pairs.size()) {
            break;
         }
         k = 0, l = 0;
         while (true) {
            if (k == pairs[i].second.size() || l == pairs[j].second.size())
               break;
            if (pairs[i].second[k] < pairs[j].second[l]) {
               k = leapfrog(k, pairs[i].second, pairs[j].second[l]);
            } else if (pairs[i].second[k] > pairs[j].second[l]) {
               l = leapfrog(l, pairs[j].second, pairs[i].second[k]);
            } else {
               c++; k++; l++;
            }
         }
         tmp++;
         if (tmp == pairs[i].second.size())
            break;
      } // end while (true)
   } // end for
   return c;
}
