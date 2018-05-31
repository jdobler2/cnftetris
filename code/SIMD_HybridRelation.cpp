//SIMD_HybridRelation.cpp

#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

#include "error_handling.h"
#include "SIMD_HybridRelation.h"

using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::max;
using std::set;
   
void SIMD_HybridRelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   std::cout << "Checkpoint A" << std::endl;
   sortRawTuples(rawTuples, true);
      std::cout << "Checkpoint B" << std::endl;

   vector<pair<unsigned, vector<unsigned> > > newPairs;
   fillPairs(rawTuples, newPairs);
   std::cout << "Checkpoint c" << std::endl;

   
 //  matchModes.resize(newPairs.size(), 0);

   orderPairs(newPairs);
   matchModes.resize(pairs.size());
      std::cout << "Checkpoint d" << std::endl;


   // rewrite data in SIMD format
   size_t totalCount = 0;
   size_t totalEdgeCount = 0;
   size_t totalVerts = 0;
   for (size_t i = 0; i < newPairs.size(); i++) {
      totalEdgeCount+=newPairs[i].second.size();
      if (newPairs[i].second.size() != 0) {
         totalVerts++;
      }
   }
   size_t averageEdgeCount = totalEdgeCount / totalVerts;
   std::cout << "averageEdgeCount: " << averageEdgeCount << std::endl;
   for (size_t i = 0; i < pairs.size(); i++) {
      
      convertToSIMDRanges(newPairs, i); //builds assuming ranges
      
      //check if we should keep ranges or switch to points
      int sizeOfRanges = pairs[i].second.size();
      size_t ourMode = 1;
      if (sizeOfRanges * 2 > newPairs[i].second.size()) { //switch to points
         pairs[i].second.clear();
         leaps[i].clear();
         convertToSIMD(newPairs, i); //builds assuming points
         ourMode = 0;
      }

      matchModes[i] = ourMode;
      
      totalCount+=pairs[i].second.size();
   }

   /*
   //print out pairs
   for (int i = 0; i < pairs.size(); i++) {
      std::cout << "i: " << i << "; mode: " << matchModes[i] << std::endl << "\t";
      for (int j=0; j < pairs[i].second.size(); j++) {
         std::cout << pairs[i].second[j] << "; ";
      }
      std::cout << std::endl;
   }*/
   
   std::cout << "TotalCount: " << totalCount << std::endl;
   
}

unsigned long SIMD_HybridRelation::performFroggerTricount(size_t start, size_t end) 
{
   unsigned long c=0;
   // unsigned int target;
   size_t j = -1, upperIndex, lowerIndex, k, l;
   unsigned int leapIndex_i, leapIndex_j;
   //const unsigned short * dataPointer A, B;
   //unsigned short lengthA, lengthB;
  
   for (size_t i=start; i<end; i++) {
      // compute the intersection of edges[i].second (neighbors of
      // edges[i].first), and the set of values in edges.first
      upperIndex = 0, lowerIndex = 2;
      j = -1;
      size_t maxInc = -1;

      unsigned int upperValue;
      upperValue = 65536 * ((unsigned int) pairs[i].second[upperIndex]);
      
      while (true) {
        
        // jumping to next j         
         if (j < maxInc) {
            j++;
         }
         else {
            j = upperValue +
            ((unsigned int) pairs[i].second[upperIndex+lowerIndex]);
           
           if (matchModes[i]) {
               maxInc = upperValue +
               ((unsigned int) pairs[i].second[upperIndex+lowerIndex+1]);
               lowerIndex+=2;
            }
            else {
               maxInc=j;
               lowerIndex+=1;
            }
         }
         
         if (j>=pairs.size()) {
            break;
         }
         leapIndex_i = 0;
         k = leaps[i][leapIndex_i], l = 0;
         leapIndex_j = 0;
         while (true) {

            if (k >= pairs[i].second.size() || 
                  l >= pairs[j].second.size())
               break;
               
            if (pairs[i].second[k] < pairs[j].second[l]) {
               k = leaps[i][++leapIndex_i];
             /*  size_t stepSize = 1;
               //++leapIndex_i;
               while(leapIndex_i < leaps[i].size() 
                     && k < pairs[i].second.size() 
                     && pairs[i].second[k] < pairs[j].second[l]) {
                  if (leapIndex_i + stepSize < leaps[i].size() &&
                  leaps[i][leapIndex_i+stepSize] < pairs[i].second.size() &&
                  pairs[i].second[leaps[i][leapIndex_i+stepSize]] < 
                           pairs[j].second[l]) {
                     leapIndex_i += stepSize;
                     stepSize*=2;
                  } else {
                     leapIndex_i++;
                     stepSize = 1;
                  }
                  k = leaps[i][leapIndex_i];
               } //end leapfrog while
               */
            } else if (pairs[i].second[k] > pairs[j].second[l]) {
               l = leaps[j][++leapIndex_j];
           /*    size_t stepSize = 1;
              // ++leapIndex_j;
               while(leapIndex_j < leaps[j].size() 
                     && l < pairs[j].second.size() 
                     && pairs[j].second[l] < pairs[i].second[k]) {
                  if (leapIndex_j + stepSize < leaps[j].size() &&
                  leaps[j][leapIndex_j+stepSize] < pairs[j].second.size() &&
                  pairs[j].second[leaps[j][leapIndex_j+stepSize]] < 
                           pairs[i].second[k]) {
                     leapIndex_j += stepSize;
                     stepSize*=2;
                  } else {
                     leapIndex_j++;
                     stepSize = 1;
                  }
                  l = leaps[j][leapIndex_j];
               } //end leapfrog while
             */  
            } else { //checking lower!
               //determine mode of execution
               size_t mode = (matchModes[i] << 1) + matchModes[j];
               switch(mode) {
                  case 0: //points with points
                     execSIMDPoints(i,j,k,l,c);
                     break;
                  case 1: //points with ranges
                     execSIMDMixed(j,i,l,k,c);
                     break;
                  case 2: //ranges with points
                     execSIMDMixed(i,j,k,l,c);
                     break;
                  case 3: //ranges with range
                     execSIMDRanges(i,j,k,l,c);
                     break;
               }
               k = k + 2 + pairs[i].second[k+1];
               l = l + 2 + pairs[j].second[l+1];
            }
         }
         //lowerIndex++;

         if (lowerIndex==2 + pairs[i].second[upperIndex+1] && j==maxInc) {
            upperIndex = upperIndex + lowerIndex;
            if (upperIndex >= pairs[i].second.size()) {
               break;
            }
            upperValue = 65536 * ((unsigned int) pairs[i].second[upperIndex]);
            lowerIndex = 2;
         }
      } // end while (true)
   } // end for
   return c;
}
