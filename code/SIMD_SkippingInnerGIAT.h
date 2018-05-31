//SIMD_SkippingInnerGIAT.cpp

#ifndef SIMD_SKIPPING_INNER_GIAT_H
#define SIMD_SKIPPING_INNER_GIAT_H

#include "SIMD_InnerGIAT.h"

class SIMD_SkippingInnerGIAT : public SIMD_InnerGIAT {
   
  public:
   SIMD_SkippingInnerGIAT();
   SIMD_SkippingInnerGIAT(int newLayer);
   virtual ~SIMD_SkippingInnerGIAT() {

   }; 
   
   //return codes (defined elsewhere, repeated here for convenience)
   // const int INSERT_ZIP_BROKEN = 0;
   //0 (false): ZIP needs to be broken
   // const int INSERT_SUCCESSFUL = 1;
   //1 (true): Successful insertion
   // const int INSERT_PRESENT = 2;
   //2: Already present
   // cosnt int INSERT_MERGE_REQ = 3;
   //3: Child was filled; a merge is requested
   //@override
   int insert(const vector<int>& box);
   
   //for use in insertion, when closing a zip
   void forcedInsertAtZero(GenericIntTrie* trie);
   
   //gets the next layer that is not all-lambdas.
   int getNextActiveLayer(const vector<int>& box) const;
   
   //@override SIMD_InnerGIAT
   void resetPrevWord(vector<int>& prevWord, int& myLayer) const;

};

#endif //SIMD_SKIPPING_INNER_GIAT_H