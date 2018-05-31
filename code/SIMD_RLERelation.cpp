//SIMD_RLERelation.cpp

#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

#include "error_handling.h"
#include "SIMD_RLERelation.h"
#include "utils.h"
#include <boost/thread.hpp>

using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::max;
using std::set;
   

class SIMD_RLE_DegreeComparitor {
   std::vector<std::pair<unsigned, std::vector<unsigned> > >* p_ptr;
 public:
   SIMD_RLE_DegreeComparitor(std::vector<std::pair
                            <unsigned, std::vector<unsigned> > >& input) {
      p_ptr = &input;
   }
   bool operator() (const unsigned& x, const unsigned& y) const {
     return p_ptr->at(x).second.size() >= p_ptr->at(y).second.size(); 
   }
};

void SIMD_RLERelation::orderPairs(
   vector<pair<unsigned, vector<unsigned> > >& newPairs) {
   
      //std::map<unsigned, unsigned> mapping;
   size_t i;
   //std::map<int, int> included;
   vector<int> included(maxNodeID+1, -1);
   vector<int> mapping(maxNodeID+1, -1);

   pairs.resize(newPairs.size(), make_pair(0, vector<unsigned short>()));
   leaps.resize(newPairs.size(), vector<int>());

   size_t numThreads = boost::thread::hardware_concurrency();
   parallelSort(newPairs.begin(), newPairs.end(), numThreads*2, reverseDegreeComparitor);
   
   for (i = 0; i < newPairs.size(); i++) {
      //mapping[newPairs[i].first] = i;
      //   pairs.push_back(make_pair(i, vector<unsigned>()));
      included[newPairs[i].first] = i;
   }
   //assert: i = newPairs.size()
   int boundaryVal = newPairs[newPairs.size()-1].first;
   size_t overflow_counter = i;
   size_t mapCounter = 0;

   //int stackIndex = 0;
   vector<unsigned> queue(0);
   
   priority_queue<unsigned, vector<unsigned>, SIMD_RLE_DegreeComparitor> 
      heap(SIMD_RLE_DegreeComparitor(newPairs), queue);

   for (size_t i = 0; i < newPairs.size(); i++) 
   {
      if (mapping[newPairs[i].first] == -1 && included[newPairs[i].first]!=-1) {
         heap.push(i);
         mapping[newPairs[i].first] = mapCounter++;
      }
      while (heap.size() > 0) {
         size_t loc = heap.top(); // next vertex from heap
         heap.pop();
         for (size_t j = 0; j < newPairs[loc].second.size(); j++) {
            if (included[newPairs[loc].second[j]] == -1) { //if outdegree 0
               if (mapping[newPairs[loc].second[j]] == -1) { //if new
                  // this vertex has out-degree 0, push it to the end of listing
                  // TODO: should we take this into account when partition for
                  //       multi-threading?
                  mapping[newPairs[loc].second[j]] = overflow_counter++;
               }
            } else {
               if (mapping[newPairs[loc].second[j]] == -1) { //if new
                  heap.push(included[newPairs[loc].second[j]]);
                  mapping[newPairs[loc].second[j]] = mapCounter++;
               }
            }
         }
      } // end heap loop
   } // end loop over separated trees

   vector<pair<unsigned, vector<unsigned> > > tempPairs;
   tempPairs.resize(newPairs.size(), make_pair(0, vector<unsigned>()));

   //now, loop through to reassign to all the BFS mapping values
   for (i = 0; i < newPairs.size(); i++) {
      tempPairs[mapping[newPairs[i].first]].second.swap(newPairs[i].second);
   }

   for (i = 0; i < tempPairs.size(); i++) {
      for (size_t j = 0; j < tempPairs[i].second.size(); j++) {
         tempPairs[i].second[j] = mapping[tempPairs[i].second[j]];
      }
      sort(tempPairs[i].second.begin(), tempPairs[i].second.end());
   //   reverse(tempPairs[i].second.begin(), tempPairs[i].second.end());
   }

   //remove duplicate edges
   for (i = 0; i < tempPairs.size(); i++) {
      for (size_t j = 0; j < tempPairs[i].second.size()+1; j++) {
         if (j==tempPairs[i].second.size()) {
            //do nothing
         } else if (tempPairs[i].second[j] <= i) {
            continue;
         }
         
         if (j==0) break;
         tempPairs[i].second.assign(tempPairs[i].second.begin()+j,
                                    tempPairs[i].second.end());
         break;
      }
   }

   overflow_counter = i;
   size_t finalCounter = 0;
   //get rid of empties
   included.resize(tempPairs.size());
   for (i=0; i <tempPairs.size(); i++) {
      if (tempPairs[i].second.size()!=0) {
         included[i] = finalCounter++;
      } else {
         included[i] = ++overflow_counter;
      }
   }
   newPairs.resize(finalCounter);

   //and one last reassignment
   for (i = 0; i < included.size(); i++) {
      if (included[i] < finalCounter) {
         newPairs[included[i]].second.swap(tempPairs[i].second);
      }
   }

   for (i = 0; i < newPairs.size(); i++) {
      for (size_t j = 0; j < newPairs[i].second.size(); j++) {
         newPairs[i].second[j] = included[newPairs[i].second[j]];
      }
      sort(newPairs[i].second.begin(), newPairs[i].second.end());
   }

   pairs.resize(finalCounter);
   leaps.resize(finalCounter);
   
}
   
void SIMD_RLERelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   sortRawTuples(rawTuples, true);

   vector<pair<unsigned, vector<unsigned> > > newPairs;
   fillPairs(rawTuples, newPairs);

   orderPairs(newPairs);

   // rewrite data in SIMD format
   size_t totalCount = 0;
   for (size_t i = 0; i < pairs.size(); i++) {
      SIMD_RLERelation::convertToSIMDRanges(newPairs, i);
      totalCount+=pairs[i].second.size();
   }
   
   /*
   //print out pairs
   for (int i = 0; i < pairs.size(); i++) {
      std::cout << "i: " << i << std::endl << "   ";
      for (int j=0; j < pairs[i].second.size(); j++) {
         std::cout << pairs[i].second[j] << "; ";
      }
      std::cout << std::endl;
   }
   */
   std::cout << "TotalCount: " << totalCount << std::endl;
   
}

unsigned long SIMD_RLERelation::performFroggerTricount(size_t start, size_t end) 
{
   unsigned long c=0;
   // unsigned int target;
   size_t j = -1, upperIndex, lowerIndex, k, l;
   unsigned int leapIndex_i, leapIndex_j;
   //const unsigned short * dataPointer A, B;
   //unsigned short lengthA, lengthB;

   //setting up command vector
  
   for (size_t i=start; i<end; i++) {
      // compute the intersection of edges[i].second (neighbors of
      // edges[i].first), and the set of values in edges.first
      upperIndex = 0, lowerIndex = 2;
      size_t leapIndex_i_outer = 0;
      j = -1;
      size_t maxInc = -1;
      while (true) {
        
        // jumping to next j         
         if (j < maxInc) {
            j++;
         }
         else {
            j = (65536 * ((unsigned int) pairs[i].second[upperIndex])) +
            ((unsigned int) pairs[i].second[upperIndex+lowerIndex]);
            maxInc = (65536 * ((unsigned int) pairs[i].second[upperIndex])) +
            ((unsigned int) pairs[i].second[upperIndex+lowerIndex+1]);
            lowerIndex+=2;
         }
         
         if (j>=pairs.size()) {
            break;
         }
         leapIndex_i = leapIndex_i_outer;
         k = leaps[i][leapIndex_i], l = 0;
         leapIndex_j = 0;
         while (true) {

            if (k >= pairs[i].second.size() || 
                  l >= pairs[j].second.size())
               break;
            if (pairs[i].second[k] < pairs[j].second[l]) {
               k = leaps[i][++leapIndex_i];
               //note: using leapfrog slower in practice
            } else if (pairs[i].second[k] > pairs[j].second[l]) {
               l = leaps[j][++leapIndex_j];
            } else { //checking lower!
               execSIMDRanges(i,j,k,l,c);
               k = k + 2 + pairs[i].second[k+1];
               l = l + 2 + pairs[j].second[l+1];
            }
         }

         if (lowerIndex==2 + pairs[i].second[upperIndex+1] && j==maxInc) {
            upperIndex = upperIndex + lowerIndex;
            leapIndex_i_outer++;
            if (upperIndex >= pairs[i].second.size()) {
               break;
            }
            lowerIndex = 2;
         }
      } // end while (true)
   } // end for
   return c;
}

void SIMD_RLERelation::convertToSIMDRanges(
      vector<pair<unsigned, vector<unsigned> > >& tempPairs, size_t& i) {
   unsigned short currentTop = 0;
   std::vector<unsigned short> tempQueue;
   unsigned short count = 0;
   unsigned short prevBottom = 0;
   
   for (size_t j = 0; j < tempPairs[i].second.size(); j++) {
      unsigned short newTop = (unsigned short) (tempPairs[i].second[j]/65536);
      unsigned short newBottom = (unsigned short) (tempPairs[i].second[j] % 65536);

      if (newTop!=currentTop || leaps[i].size()==0) {
         if (leaps[i].size()!=0) {
            //bookkeeping
            tempQueue.push_back(prevBottom);
            count++;
            
            pairs[i].second.push_back(currentTop);
            pairs[i].second.push_back(count);
            
            for (size_t k = 0; k < tempQueue.size(); k++) {
               pairs[i].second.push_back(tempQueue[k]);
            }

            leaps[i].push_back(leaps[i].back()+count+2);

            count = 1;
            prevBottom = newBottom;
            tempQueue.clear();
            tempQueue.push_back(newBottom);
         }
         else { //leaps[i].size==0, i.e. brand new
            count++;
            prevBottom = newBottom;
            tempQueue.push_back(newBottom);
            
            leaps[i].push_back(0);
         }
         currentTop = newTop;
      } else if (newBottom > prevBottom + 1) { //starting new set
         //finish old set
         count++;
         tempQueue.push_back(prevBottom);
         
         //start new set
         prevBottom = newBottom;
         tempQueue.push_back(newBottom);
         count++;
      } else { //continuing old set
         prevBottom = newBottom;
      }
      
   }
   if (tempQueue.size()!=0) {
      count++;
      tempQueue.push_back(prevBottom);
   
      //add in last set
      pairs[i].second.push_back(currentTop);
      pairs[i].second.push_back(count);
               
      for (size_t k=0; k < tempQueue.size(); k++) {
         pairs[i].second.push_back(tempQueue[k]);
      }

      leaps[i].push_back(65537);

      tempQueue.clear();
   }
}

SIMD_RLERelation::SIMD_RLERelation() {
   
}