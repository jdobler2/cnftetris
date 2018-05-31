// ============================================================================
// SimpleRelation.cpp
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// ============================================================================
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>

#include "SimpleRelation.h"

using std::vector;
using std::max;
using std::pair;
using std::make_pair;

void SimpleRelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   sortRawTuples(rawTuples, false);
   
   pairs.clear();
   fillPairs(rawTuples, pairs);
}

unsigned long SimpleRelation::performFroggerTricount(size_t start, size_t end) 
{
   unsigned long c = 0;
   unsigned int target;
   size_t j, tmp, stepSize;
   for (size_t i=start; i<end; i++) {
      // compute the intersection of edges[i].second (neighbors of
      // edges[i].first), and the set of values in edges.first
      j = start, tmp = 0;
      while (true) {
         if (tmp == this->getList(i).size())
            break;
         if (this->getKey(j) < this->getList(i)[tmp]) {
            // leap frogging to next j
            stepSize = 1;
            target = this->getList(i)[tmp];
            // move to Relation?
            while (j < this->size() && this->getKey(j) < target) { 
               if (j+stepSize < this->size() &&              
                     this->getKey(j+stepSize) < target) {        
                  j += stepSize;
                  stepSize *= 2;
               } else {
                  j++;
                  stepSize = 1;
               }
            }
            if (j>=this->size()) {
               break;
            }
         } else if (this->getKey(j) > this->getList(i)[tmp]) {
            // leapfrogging to next tmp
            stepSize = 1;
            // target = this->getKey(j);
            tmp = leapfrog(tmp, this->getList(i), this->getKey(j));
         } else {
            size_t k = 0, l = 0;
            while (true) {
               if (k == this->getList(i).size() || 
                     l == this->getList(j).size())
                  break;
               if (this->getList(i)[k] < this->getList(j)[l]) {
                  k = leapfrog(k, this->getList(i), this->getList(j)[l]);
               } else if (this->getList(i)[k] > this->getList(j)[l]) {
                  l = leapfrog(l, this->getList(j), this->getList(i)[k]);
               } else {
                  c++; k++; l++;
               }
            }
            j++; 
            tmp++;
         }
      } // end while (true)
   } // end for
   return c;
}

size_t SimpleRelation::leapfrog(size_t start, const vector<unsigned>& v, 
                                unsigned t) const
{
   size_t stepSize = 1;
   while (start < v.size() && v[start] < t) {      
      if (start + stepSize < v.size() && v[start+stepSize] < t) {
         start += stepSize;
         stepSize *= 2;
      } else {                                                      
         start+=1;
         stepSize = 1;
      }
   }
   //start is the value we're looking for
   return start;
}
