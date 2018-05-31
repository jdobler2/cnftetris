// ============================================================================
// SIMD_Relation.cpp
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// ============================================================================
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>

#include "error_handling.h"
#include "SIMD_Relation.h"

using std::vector;
using std::pair;
using std::make_pair;
using std::max;
using std::set;

// ----------------------------------------------------------------------------
// BEGIN SIMD_DegreeRelation
// ----------------------------------------------------------------------------

void SIMD_DegreeRelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   pairs.clear();
   pairs.resize(14, make_pair(0, vector<unsigned short>()));

   leaps.clear();
   leaps.resize(14, vector<int>());

   sortRawTuples(rawTuples, true);

   vector<pair<unsigned, vector<unsigned> > > newPairs;
   fillPairs(rawTuples, newPairs);

  //std::map<unsigned, unsigned> mapping;
   size_t i, stackCounter;
   //std::map<int, int> included;
   std::vector<int> included(maxNodeID+1, -1);
   std::vector<int> mapping(maxNodeID+1, -1);

   //need to figure out where everything is for BFS.
   for (i = 0; i < newPairs.size(); i++) {
      included[newPairs[i].first] = i;
   }

   //assert: i = newPairs.size()
   // int boundaryVal = newPairs[newPairs.size()-1].first;
   int overflow_counter = i;
   size_t mapCounter = 0;

   std::vector<unsigned> tempNeighbors;
   std::vector<unsigned> stack(newPairs.size());
   stackCounter = 0;
   // int currentDegree = -1;

   std::vector<std::set<int> > degreeQueues(18, std::set<int>());
   for (i = 0; i < newPairs.size(); i++) {
      if (newPairs[i].second.size() < 17) {
         degreeQueues[newPairs[i].second.size()].insert(i);
      }
      else {
         degreeQueues[17].insert(i);
      }
   }
   std::vector<int> searchOrder;
   searchOrder.push_back(8);
   searchOrder.push_back(7);
   searchOrder.push_back(6);
   searchOrder.push_back(5);
   searchOrder.push_back(16);
   searchOrder.push_back(15);
   searchOrder.push_back(14);
   searchOrder.push_back(13);
   searchOrder.push_back(4);
   searchOrder.push_back(12);
   searchOrder.push_back(3);
   searchOrder.push_back(11);
   searchOrder.push_back(2);
   searchOrder.push_back(10);
   searchOrder.push_back(1);
   searchOrder.push_back(9);
   searchOrder.push_back(17);
   searchOrder.push_back(0);

   std::vector<int> invSearchOrder;
   invSearchOrder.push_back(17);
   invSearchOrder.push_back(14);
   invSearchOrder.push_back(12);
   invSearchOrder.push_back(10);
   invSearchOrder.push_back(8);
   invSearchOrder.push_back(3);
   invSearchOrder.push_back(2);
   invSearchOrder.push_back(1);
   invSearchOrder.push_back(0);
   invSearchOrder.push_back(15);
   invSearchOrder.push_back(13);
   invSearchOrder.push_back(11);
   invSearchOrder.push_back(9);
   invSearchOrder.push_back(7);
   invSearchOrder.push_back(6);
   invSearchOrder.push_back(5);
   invSearchOrder.push_back(4);
   
   //make pairs into lists, so that I can delete from them efficiently
   vector<pair<unsigned, set<unsigned> > > listPairs;
   for (i = 0; i < newPairs.size(); i++) {
      listPairs.push_back(std::make_pair(newPairs[i].first, set<unsigned>())); 
      for (int j=0; j < newPairs[i].second.size(); j++) {
         listPairs[i].second.insert(newPairs[i].second[j]);
      }
   }
   for (i = 0; i < searchOrder.size()-1; i++) {
      if (degreeQueues[searchOrder[i]].size()!=0) {
         auto dq_it = degreeQueues[searchOrder[i]].begin();
         int loc = *dq_it; //degreeQueues[searchOrder[i]].front();
         degreeQueues[searchOrder[i]].erase(dq_it); //degreeQueues[searchOrder[i]].pop_front();

         mapping[listPairs[loc].first] = mapCounter++;

         for (auto j = listPairs[loc].second.begin(); 
                   j != listPairs[loc].second.end(); j++) {
            int locOfChange = included[*j];
            int sizeOfChange = listPairs[locOfChange].second.size();
            if (sizeOfChange > 16) sizeOfChange=17;

            degreeQueues[sizeOfChange].erase(locOfChange);

            int dest = listPairs[locOfChange].second.size() - 1;
            if (dest > 16) dest=17;
            degreeQueues[dest].insert(locOfChange);

            listPairs[locOfChange].second.erase(listPairs[loc].first); 
         } // end inner for
         i = -1;
      }//end if
   } // end for

   while(degreeQueues.front().size() > 0) {
      auto dq_it = degreeQueues.front().begin();
      int loc = *dq_it; //degreeQueues.front().front();
      degreeQueues.front().erase(dq_it); //degreeQueues.front().pop_front();
      mapping[listPairs[loc].first] = mapCounter++;
   }

   //switch back to newPairs
   newPairs.clear();
   for (i = 0; i < listPairs.size(); i++) {
      newPairs.push_back(std::make_pair(listPairs[i].first, vector<unsigned>())); 
      for (auto j=listPairs[i].second.begin(); j != listPairs[i].second.end(); j++) {
         newPairs[i].second.push_back(*j);
      }
   }

   stackCounter = 0;
   stack.clear();
   tempNeighbors.clear();

   std::vector<std::pair<unsigned, std::vector<unsigned> > > tempPairs;
   tempPairs.resize(newPairs.size(), make_pair(0, std::vector<unsigned>()));

   //now, loop through to reassign to all the BFS mapping values
   for (i = 0; i < newPairs.size(); i++) {
      tempPairs[mapping[newPairs[i].first]].second.swap(newPairs[i].second);
   }

   int skips = 0;
   
   //reassign in second's, and re-reassign firsts.
   for (i = 0; i < tempPairs.size(); i++) {
      for (size_t j = 0; j < tempPairs[i].second.size(); j++) {
         tempPairs[i].second[j] = mapping[tempPairs[i].second[j]];
      }
      sort(tempPairs[i].second.begin(), tempPairs[i].second.end());


      //check for empty lines
      if (tempPairs[i].second.size()==0) {
         tempPairs[i].first = maxNodeID + (++skips);
      }
      else {
         tempPairs[i].first = i - skips;
      }
   }
  
   newPairs.resize(tempPairs.size()-skips);

   int resizeSize = newPairs.size();
   //now using the re-reassignment to reassign
   //(there's gotta be a nicer way to do this)
   for (i = 0; i < tempPairs.size(); i++) {
      if (tempPairs[i].first <= maxNodeID) {
         if (tempPairs[i].second.size()==0 ) {
            resizeSize = i;
         }
         newPairs[tempPairs[i].first].second.swap(tempPairs[i].second);
      }
   }

   newPairs.resize(resizeSize);

   pairs.resize(newPairs.size(), make_pair(0, vector<unsigned short>()));
   leaps.resize(newPairs.size(), vector<int>());         
   
   int totesPairs = tempPairs.size();
   // tempPairs = newPairs;

   size_t totalCount = 0;
   for (size_t i = 0; i < pairs.size(); i++) {
      convertToSIMD(newPairs, i);
      totalCount += pairs[i].second.size();
   }
   
   std::cout << "TotalCount: "<< totalCount << std::endl;

}

// ----------------------------------------------------------------------------
// END SIMD_DegreeRelation
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
// BEGIN SIMD_BFSRELATION
// ----------------------------------------------------------------------------
const vector<unsigned>&  SIMD_BFSRelation::getList(int index) const {
   //TODO: rewrite this to make it work
   //return pairs[index].second;
}

void SIMD_BFSRelation::buildIndex(vector<pair<unsigned, unsigned> >& rawTuples)
{
   sortRawTuples(rawTuples, false);

   vector<pair<unsigned, vector<unsigned> > > newPairs;
   fillPairs(rawTuples, newPairs);

   //std::map<unsigned, unsigned> mapping;
   size_t i, stackCounter;
   //std::map<int, int> included;
   vector<int> included(maxNodeID+1, -1);
   vector<int> mapping(maxNodeID+1, -1);

   pairs.resize(newPairs.size(), make_pair(0, vector<unsigned short>()));
   leaps.resize(newPairs.size(), vector<int>());

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
   vector<unsigned> tempNeighbors;
   vector<unsigned> stack(newPairs.size());
   stackCounter = 0;

   buildMapping(newPairs, stack, mapping, included, mapCounter, overflow_counter);

   stackCounter = 0;
   stack.clear();
   tempNeighbors.clear();

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
  //    reverse(tempPairs[i].second.begin(), tempPairs[i].second.end());
   }
   
   //rewrite data in SIMD format
   size_t totalCount = 0;
   for (size_t i = 0; i < pairs.size(); i++) {
      convertToSIMD(tempPairs, i);
      totalCount += pairs[i].second.size();
   }
   
   std::cout << "TotalCount: "<< totalCount << std::endl;
}

void SIMD_BFSRelation::convertToSIMD(
      vector<pair<unsigned, vector<unsigned> > >& newPairs, size_t& i) {
   // rewrite data in SIMD format
   
   unsigned short currentTop = 0;
   std::vector<unsigned short> tempQueue;
   unsigned short count = 0;

   for (size_t j = 0; j < newPairs[i].second.size(); j++) {
      //was in SIMD_Degree only... I don't think this is nec. anymore? 
      //It breaks SMD_BFS.
     /* if (newPairs[i].second[j] <= i) {
         continue;
      }*/
      unsigned short newTop = (unsigned short) (newPairs[i].second[j]/65536);

      if (newTop!=currentTop || leaps[i].size()==0) {
         if (leaps[i].size()!=0) {
            pairs[i].second.push_back(currentTop);
            pairs[i].second.push_back(count);
            for (size_t k = 0; k < tempQueue.size(); k++) {
               pairs[i].second.push_back(tempQueue[k]);
            }

            leaps[i].push_back(leaps[i].back()+count+2);

            //totalCount+=count;
            count = 0;
            tempQueue.clear();
         }
         else {
            leaps[i].push_back(0);
         }
         currentTop = newTop;
      }
      count++;
      tempQueue.push_back(newPairs[i].second[j] % 65536);
   }
   if (tempQueue.size()!=0) {
      //add in last set
      pairs[i].second.push_back(currentTop);
      pairs[i].second.push_back(count);
      for (size_t k=0; k < tempQueue.size(); k++) {
         pairs[i].second.push_back(tempQueue[k]);
      }

      leaps[i].push_back(65537);

      tempQueue.clear();
   }
   else {
      //nothing was actually here!
   }

}

const pair<unsigned, vector<unsigned> >&
SIMD_BFSRelation::operator[](const int index) const {
   //TODO: make this work.
   //return pairs[index];
}

// alias of above
const pair<unsigned, vector<unsigned> >&
SIMD_BFSRelation::at(int index) const 
{
   // TODO: make this work.
   // return pairs[index];
}

unsigned long SIMD_BFSRelation::performFroggerTricount(size_t start, size_t end) 
{
   unsigned long c=0;
   // unsigned int target;
   size_t j, upperIndex, lowerIndex, k, l;
   unsigned int leapIndex_i, leapIndex_j;
   //const unsigned short * dataPointer A, B;
   //unsigned short lengthA, lengthB;

   for (size_t i=start; i<end; i++) {
      // compute the intersection of edges[i].second (neighbors of
      // edges[i].first), and the set of values in edges.first
      upperIndex = 0, lowerIndex = 2;
      size_t leapIndex_i_outer = 0;
      while (true) {
         // leap frogging to next j
         j = (65536 * ((unsigned int) pairs[i].second[upperIndex])) +
            ((unsigned int) pairs[i].second[upperIndex+lowerIndex]);
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
               //leapIndex_i = leapfrog(leapIndex_i, leaps[i], l);
               //note: using leapfrog slower in practice
            } else if (pairs[i].second[k] > pairs[j].second[l]) {
               l = leaps[j][++leapIndex_j];
            } else { //checking lower!
               execSIMDPoints(i,j,k,l,c);
               k = k + 2 + pairs[i].second[k+1];
               l = l + 2 + pairs[j].second[l+1];
            }
         } //end inner while(true)
         lowerIndex++;

         if (lowerIndex==2 + pairs[i].second[upperIndex+1]) {
            upperIndex = upperIndex + lowerIndex;
//            leapIndex_i_outer++;
            if (upperIndex >= pairs[i].second.size()) {
               break;
            }
            lowerIndex = 2;
         }
      } // end while (true)
   } // end for
   return c;
}

void SIMD_BFSRelation::execSIMDPoints(
      const size_t& i, const size_t& j, const size_t& k, const size_t& l, unsigned long& c) const{
   short unsigned offset_a = 0, offset_b = 0;
   const short unsigned* A = pairs[i].second.data() + k + 2;
   const short unsigned* B = pairs[j].second.data() + l + 2;
   int numToCheckB = 8;
   int numToCheckA = 8;
   unsigned short a_size = pairs[i].second[k+1];
   unsigned short b_size = pairs[j].second[l+1];
   if (numToCheckA > a_size) {
      numToCheckA = a_size;
   }
   if (numToCheckB > b_size) {
      numToCheckB = b_size;
   }

   while (true) {
      //load vectors 
      __m128i v_a = _mm_loadu_si128((__m128i*)&A[offset_a]);
      __m128i v_b = _mm_loadu_si128((__m128i*)&B[offset_b]);

      //full comparison
      __m128i res_v = _mm_cmpestrm(v_b, numToCheckB, 
            v_a, numToCheckA,
            _SIDD_UWORD_OPS|_SIDD_CMP_EQUAL_ANY|_SIDD_BIT_MASK);
      int r = _mm_extract_epi32(res_v, 0);

      //count common values
      //these parts write tri's
      //__m128i p = _mm_shuffle_epi8(v_a, sh_mask[r]);
      //_mm_storeu_si128((__m128i*)&C[count], p); 
      c += _mm_popcnt_u32(r);

      //check for break
      int aVal = A[offset_a+numToCheckA-1];
      if (aVal <= B[offset_b+numToCheckB-1]) {
         offset_a += 8;
         if ((offset_a + 7) >= a_size) {
            if (offset_a >= a_size) {
               break;
            }
            numToCheckA = a_size - offset_a; 
         }
      }
      if (B[offset_b+numToCheckB-1] <= aVal) {
         offset_b += 8;
         if ((offset_b + 7) >= b_size) {
            if (offset_b >= b_size) {
               break;
            }
            numToCheckB = b_size - offset_b;
         }
      }
   } //end simd-loop
} 

void SIMD_BFSRelation::execSIMDRanges(
      const size_t& i, const size_t& j, const size_t& k, const size_t& l, unsigned long& c) const{
   
   //various setup
   short unsigned offset_a = 0, offset_b = 0;
   const short unsigned* A = pairs[i].second.data() + k + 2;
   const short unsigned* B = pairs[j].second.data() + l + 2;
   int numToCheckB = 8;
   int numToCheckA = 8;
   unsigned short a_size = pairs[i].second[k+1];
   unsigned short b_size = pairs[j].second[l+1];

   if (numToCheckA > a_size) {
      numToCheckA = a_size;
   }
   
   if (numToCheckB > b_size) {
      numToCheckB = b_size;
   }

   __m128i v_a; 
   __m128i v_b;
   
   while (true) { //simd loop
      //load vectors 
      v_a = _mm_loadu_si128((__m128i*)&A[offset_a]);
      v_b = _mm_loadu_si128((__m128i*)&B[offset_b]);
      
      //For each character c in b, 
      //determine whether a0 <= c <= a1 or a2 <= c <= a3... 
      __m128i res_v = _mm_cmpestrm(v_a, numToCheckA, 
            v_b, numToCheckB,
            _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
            
      int r = _mm_extract_epi32(res_v, 0); 
      size_t diff = 0;

      if (r!=0) {
      size_t r_count = _mm_popcnt_u32(r);
      //note: since r!=0, we can guarantee at least 1 execution of this loop
         do {          
            unsigned short loc = offset_a + diff;
            
            res_v = _mm_cmpestrm(v_a, 2,
               v_b, numToCheckB,
               _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
            
            int r_inner = _mm_extract_epi32(res_v, 0); 
            
            size_t z = 0;
                              
            if (r_inner!=0) do {
               //get value corresponding to current bytes
               size_t miniVal = r_inner & 3; // equiv. to r % 4, but faster

               switch(miniVal) {
                  //note: positive case 0's are impossible
                  
                 case 1:
                  c+=op1(A, loc, B, offset_b, z);
                  r_count--;
                  break;
                 case 2:
                  c+=op2(A, loc, B, offset_b, z);
                  r_count--;
                  break;
                 case 3:
                  c+=op3(B, offset_b, z);
                  r_count-=2;
                  break;
               }
               r_inner >>= 2;
               z+=2;
            } while (r_inner!=0 );     
            
            else { //r_inner==0, so check reverse inclusion.
            
               __m128i res_v2 = _mm_cmpestrm(v_b, numToCheckB, 
               v_a, 2,
               _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
               
               int r2 = _mm_extract_epi32(res_v2, 0);    
                              
               //count common values
               //get value corresponding to current bytes
               if (r2==3) {
                 c+=op3(A, loc, 0);
               }               
            }//end if 0's remain
            diff+=2;

            //shifts v_a right 4 bytes == two shorts 
            v_a = _mm_srli_si128(v_a,4);

         } while (r_count!=0);
      } //end if r!=0
      
      if (diff < numToCheckA) { //only type 0's are still possible.
   
        //Simply restating what v_a and v_b are at this point.
        //there is no need to actually perform the loads.
     //    v_a = _mm_loadu_si128((__m128i*)&A[offset_a+diff]);
     //    v_b = _mm_loadu_si128((__m128i*)&B[offset_b]);
            
         __m128i res_v2 = _mm_cmpestrm(v_b, numToCheckB, 
               v_a, numToCheckA-diff,
               _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
               
         int r2 = _mm_extract_epi32(res_v2, 0);    
         
         size_t z = diff;
         while (r2!=0) {
            //count common values
            //get value corresponding to current bytes
            size_t miniVal = r2 & 3; // equiv. to r % 4, but faster
            if (miniVal == 3) {
               c+=op3(A, offset_a, z);
            }
            
            r2 >>= 2; //note: max 4 cycles
            z+=2;
         }

      } //end checking remaining type 0's.

      //check for break
      int aVal = A[offset_a + numToCheckA - 1];
      if (aVal <= B[offset_b+numToCheckB-1]) {
         offset_a += 8;
         if ((offset_a + 6) >= a_size) {
            if (offset_a >= a_size) {
               break;
            }
            numToCheckA = a_size - offset_a;            
         }
      }
      
      if (B[offset_b+numToCheckB-1] <= aVal) {
         offset_b += 8;
         if ((offset_b + 6) >= b_size) {
            if (offset_b >= b_size) {
               break;
            }
            numToCheckB = b_size - offset_b;
         }
      }//finish checking for breaks

   } //end simd-loop
   
} 
  
//note: i,j should refer to the ranged data set
//      k,l to the points
void SIMD_BFSRelation::execSIMDMixed(
      const size_t& i, const size_t& j, const size_t& k, const size_t& l, unsigned long& c) const{
   short unsigned offset_a = 0, offset_b = 0;
   const short unsigned* A = pairs[i].second.data() + k + 2;
   const short unsigned* B = pairs[j].second.data() + l + 2;
   int numToCheckB = 8;
   int numToCheckA = 8;
   unsigned short a_size = pairs[i].second[k+1];
   unsigned short b_size = pairs[j].second[l+1];
   if (numToCheckA > a_size) {
      numToCheckA = a_size;
   }
   if (numToCheckB > b_size) {
      numToCheckB = b_size;
   }

   while (true) {
      //load vectors 
      __m128i v_a = _mm_loadu_si128((__m128i*)&A[offset_a]);
      __m128i v_b = _mm_loadu_si128((__m128i*)&B[offset_b]);

      //for each char in B, check to see if between e.g. a1, a2.
      __m128i res_v = _mm_cmpestrm(v_a, numToCheckA, 
            v_b, numToCheckB,
            _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
      int r = _mm_extract_epi32(res_v, 0);
      //count common values 
      c += _mm_popcnt_u32(r);

      //check for break
      int aVal = A[offset_a+numToCheckA-1];
      if (aVal <= B[offset_b+numToCheckB-1]) {
         offset_a += 8;
         if ((offset_a + 6) >= a_size) {
            if (offset_a >= a_size) {
               break;
            }
            numToCheckA = a_size - offset_a; 
         }
      }
      if (B[offset_b+numToCheckB-1] <= aVal) {
         offset_b += 8;
         if ((offset_b + 7) >= b_size) {
            if (offset_b >= b_size) {
               break;
            }
            numToCheckB = b_size - offset_b;
         }
      }
   } //end simd-loop
} 

//NOTE: Commented out at present because not actually called,
//and was causing problems when porting to Raiders5 for some
//reason. The code itself is fine, and may be useful
//in the future.
/*
//00: check for reverse inclusion
//can be either:
//A:  --         OR    --                OR        --
//B: ----                     -----          ----
unsigned short SIMD_BFSRelation::op0(__m128i& v_a, 
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const {
   __m128i v_b = _mm_loadu_si128((__m128i*)&B[offset_b+i]);
   __m128i res_v = _mm_cmpestrm(v_b, 2, 
                  v_a, 2,
                  _SIDD_UWORD_OPS|_SIDD_CMP_RANGES|_SIDD_BIT_MASK);
      
   //we only need to check if the residue is non-zero.      
   if (_mm_extract_epi32(res_v, 0)) {
      return A[offset_a+1] - A[offset_a] + 1;
   } else {
      return 0;
   }
}
*/

//01:A: ----
//   B:   ----
unsigned short SIMD_BFSRelation::op1(
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const {
   return A[offset_a + 1] - B[offset_b + i] + 1;
}

//10: A:   ----
//    B: ----
unsigned short SIMD_BFSRelation::op2(
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const {
   return B[offset_b + i + 1] - A[offset_a] + 1;
}

//11: A: ------
//    B:   --
unsigned short SIMD_BFSRelation::op3(
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const {
   
   return B[offset_b + i + 1] - B[offset_b + i] + 1;
}
  
void SIMD_BFSRelation::leapfrog(size_t& leapIndex, 
                                const vector<int>& leaps, 
                                const vector<unsigned short>& pairs,
                                size_t& k,
                                const unsigned short& target) const {
   size_t stepSize = 1;
   while(leapIndex < leaps.size() 
         && k < pairs.size() 
         && pairs[k] < target) {
      if (leapIndex + stepSize < leaps.size() &&
          leaps[leapIndex + stepSize] < pairs.size() &&
          pairs[leaps[leapIndex + stepSize]] < target) {
         leapIndex += stepSize;
         stepSize*=2;
      } else {
         leapIndex++;
         stepSize = 1;
      }
      k = leaps[leapIndex];
   } //end leapfrog while
}
  
// ----------------------------------------------------------------------------
// END SIMD_BFSRELATION
// ----------------------------------------------------------------------------
