//SIMD_SkippingInnerGIAT.cpp

#include "SIMD_SkippingInnerGIAT.h"
#include <math.h>
#include <immintrin.h>

SIMD_SkippingInnerGIAT::SIMD_SkippingInnerGIAT() : SIMD_InnerGIAT() {

}

SIMD_SkippingInnerGIAT::SIMD_SkippingInnerGIAT(int newLayer) : SIMD_InnerGIAT(newLayer) {
   
}

int SIMD_SkippingInnerGIAT::insert(const vector<int>& box) {
      //ASSERT: box.at(myLayer)!=-1
   insertedCount++;
   if (insertedCount==1) {
      //store and reduce the last var
      pathToThis = box;
      for (int i = myLayer; i < box.size(); i++) {
         if (pathToThis[i] == -1) {
            int loc = pathToThis[i-1];
            int modVal = loc % 3;
            while (modVal == 1) {
               loc = (loc - 1) / 3;
               modVal = loc % 3;
            }
            pathToThis[i-1] = loc;
            break;
         }
      }
      
      pathAsChar.resize(((box.size()/32)+1)*32);
      getUcharFormatPos(pathAsChar, pathToThis, myLayer);
   }
   
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   
   //check for inclusion 
   if (mStatus & GIAT_STATUS_WORD_ONLY) {
      __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      __m128i and_result = _mm_and_si128(link, data);
      
      uint64_t dest[2];
      _mm_storeu_si128((__m128i*)dest, and_result);
      if (dest[0]!=0 || dest[1]!=0) {
         return INSERT_PRESENT;
      }
   }
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
   int initialLoc = loc;
   if (wordFlag) {
      //TODO: precalc all this?
      int modVal = loc % 3;
      while(true) {
         if (modVal == 1) { //is a *
            //do nothing
         }
         else {
            int altLoc;
            if (modVal == 2) { 
               altLoc = loc + 1;
            }
            else { //modVal == 0 (i.e. 3)
               if (loc==0) break;
               altLoc = loc - 1;
            }
            
            //determine if sibling is set
            if ((wordBits[altLoc/64] & (1ull << (63 - altLoc % 64))) != 0) {
               //merge, which means go to the next step (so do nothing now)
               //we don't have to clear children here b/c clear on actual insert
               //will take care of it.
            }
            else {
               break;
            }
         }
         //prep next round
         loc = (loc - 1) / 3;
         modVal = loc % 3;
      }
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      
      //check if we filled the trie
      if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }
      clearChildren(loc);
      clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      if (branches.at(loc-40)==NULL) {
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < _LAYERS - 1) {
            branches.at(loc-40).reset(new SIMD_SkippingInnerGIAT(nextActiveLayer));
         }
         else {//if at the bottom, insert bottom-level SIMD_GIAT.
            branches.at(loc-40).reset(new SIMD_GIATrie(nextActiveLayer));
         }
      }
      else { //check if there's a skip we need to close
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < branches.at(loc-40)->getMyLayer()) {
            GenericIntTrie* currentPointer = branches.at(loc-40).release();
            branches.at(loc-40).reset(new SIMD_SkippingInnerGIAT(nextActiveLayer));
            branches.at(loc-40)->forcedInsertAtZero(currentPointer);
         }
      }
      int status = branches[loc-40]->insert(box);
      if (status == INSERT_MERGE_REQ) {
         //TODO: I don't like this method...
         vector<int> tempBox = box;
         tempBox[myLayer+1] = -1;
         return this->insert(tempBox);
      }
      return status;
   }
}

int SIMD_SkippingInnerGIAT::getNextActiveLayer(const vector<int>& box) const {
   int nextLayer = myLayer + 1;
   while (box.at(nextLayer) == 40) { //<= WILL cause crashes.
      nextLayer++; //assert: there exists a fully-defined box eventually.
   }
   return nextLayer;
}

void SIMD_SkippingInnerGIAT::forcedInsertAtZero(GenericIntTrie* trie) {
   childBits[0] |= (1ull << (23)); //23 = 63 - (40 % 64)
   mStatus |= GIAT_STATUS_CHILDREN_ONLY;
   branches.at(0).reset(trie);
   insertedCount+=2;
}

void SIMD_SkippingInnerGIAT::resetPrevWord(vector<int>& prevWord, int& myLayer) const {
   prevWord.at(myLayer) = 40;
}
