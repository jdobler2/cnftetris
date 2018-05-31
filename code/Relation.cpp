// ============================================================================
// Relation.cpp
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// ============================================================================
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>

#include "Relation.h"
#include <boost/thread.hpp>
#include "TrieActors.h"

using std::vector;
using std::max;
using std::pair;
using std::make_pair;

void Relation::sortRawTuples(
      vector<pair<unsigned, unsigned> >& rawTuples,
      bool bothDirs) 
{
   // orient edges from x --> y when x <= y
   maxNodeID = 0;
   size_t rt_size = rawTuples.size();
   for (size_t i=0; i<rt_size; i++) {
      if (rawTuples[i].first > rawTuples[i].second) {
         maxNodeID = max(rawTuples[i].first, maxNodeID);
         if (!bothDirs) {
            std::swap(rawTuples[i].first, rawTuples[i].second);
         }
      } else {
         maxNodeID = max(rawTuples[i].second, maxNodeID);
      }
      if (bothDirs) {
         rawTuples.push_back(make_pair(rawTuples[i].second, rawTuples[i].first));
      }

   }

   // sort then erase duplicate edges
   size_t numThreads = boost::thread::hardware_concurrency();
   parallelSort(rawTuples.begin(), rawTuples.end(), numThreads*2);
  // bucketSort(rawTuples, rawTuples.size(), numThreads);

   rawTuples.erase(unique(rawTuples.begin(), rawTuples.end()), rawTuples.end());
}

void Relation::fillPairs(
      const vector<pair<unsigned, unsigned> >& rawTuples,
      vector<pair<unsigned, vector<unsigned> > >& newPairs) 
{

   vector<pair<unsigned, unsigned> >::const_iterator pairIt;
   vector<unsigned> neighbors;
   for (pairIt = rawTuples.cbegin(); pairIt != rawTuples.cend(); ++pairIt)
   {
      if (newPairs.empty()) {
         newPairs.push_back(make_pair(pairIt->first, vector<unsigned>()));
      } else if (newPairs.back().first != pairIt->first) {
         newPairs.back().second.swap(neighbors);
         newPairs.push_back(make_pair(pairIt->first, vector<unsigned>()));
      }
      neighbors.push_back(pairIt->second);
   }
   newPairs.back().second.swap(neighbors);
}

void Relation::buildMapping(
      std::vector<std::pair<unsigned, std::vector<unsigned> > >& newPairs,
      std::vector<unsigned>& queue,
      std::vector<int>& mapping,
      std::vector<int>& included,
      size_t& includedCounter,
      size_t& overflow_counter) 
{
   size_t queueCounter = 0;

   for (size_t i = 0; i < newPairs.size(); i++) 
   {
      if (mapping[newPairs[i].first] == -1 && included[newPairs[i].first]!=-1) {
         queue[includedCounter] = i;
         mapping[newPairs[i].first] = includedCounter++;
      }
      while (queueCounter < includedCounter) {
         size_t loc = queue[queueCounter]; // next vertex from queue
         for (size_t j = 0; j < newPairs[loc].second.size(); j++) {
            if (included[newPairs[loc].second[j]] == -1) {
               if (mapping[newPairs[loc].second[j]] == -1) {
                  // this vertex has out-degree 0, push it to the end of listing
                  // TODO: should we take this into account when partition for
                  //       multi-threading?
                  mapping[newPairs[loc].second[j]] = overflow_counter++;
               }
            } else {
               if (mapping[newPairs[loc].second[j]] == -1) {
                  queue[includedCounter] = included[newPairs[loc].second[j]];
                  mapping[newPairs[loc].second[j]] = includedCounter++;
               }
            }
         }
         queueCounter++;
      } // end queue loop
   } // end loop over separated trees
}

bool Relation::degreeComparitor(
      std::pair<unsigned, std::vector<unsigned> > a,
      std::pair<unsigned, std::vector<unsigned> > b) 
{
   return a.second.size() < b.second.size();
}

bool Relation::reverseDegreeComparitor(
      std::pair<unsigned, std::vector<unsigned> > a,
      std::pair<unsigned, std::vector<unsigned> > b) 
{
   return a.second.size() > b.second.size();
}
