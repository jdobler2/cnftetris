//Base121TrieRelation.h

#ifndef BASE_121_TRIE_RELATION_H
#define BASE_121_TRIE_RELATION_H

#include "CNFIntTrieRelation.h"

class Base121TrieRelation : public CNFIntTrieRelation {
  protected:
   #define B121_ALL_LAMBDA 40
   
   //flat varients are non-virtual
   double ratio;
   int finalDegree;
   int _NULLED;

   virtual void fillZero(vector<int>& input, int& index);

   //could probably get away without rewriting this one...
   virtual void popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index);
                    
                    
   using CNFIntTrieRelation::highestSetBit;
   virtual int highestSetBit(int value) const;
   virtual int highestSetBitFlat(int value) const;

   
   virtual void popOne(vector<int>& input, int& last, int& index);
   virtual void popOneFlat(vector<int>& input, int& last, int& index);
   virtual void popOneFlat(vector<int>& input, int& index);
   virtual void popOne(vector<int>& input, int& index);
   
   virtual void setNext(vector<int>& input, int val, int& index);
   virtual void setNextFlat(vector<int>& input, int val, int& index);
   virtual int performShrinkage(vector<int>& input, vector<int>& output, int& index);
                    
                    
   virtual void insertData(vector<vector<int> >& input, int maxNodeID);
   virtual void outputPop(vector<int>& input, int& index) const;
   virtual int getLambdaCount(vector<int>& input, int maxVal) const;
   virtual void mergeBoxesFlat(vector<int>& input1, vector<int>& input2, int& index) const;
   virtual void layerSkipFlat(const int& input1, const int& input2, int& output) const;
   
   //@override
   virtual void buildDepthLUT();
   
   virtual int mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower);
   
   //! for Locks243
   virtual void repairLocks(vector<int>& input, int& index, int start, int end);
   virtual int updateBitIndex(vector<int>& input, int& index);
   virtual void setCap(int& diff);
   virtual void removeCap();
   virtual bool isPermitted(vector<int>& output, int& index, int& indexLower, int& il2);
   virtual void checkForAltOutput(vector<int>& input, int& index, vector<int>& output);
   
  public:
   Base121TrieRelation();
   virtual ~Base121TrieRelation() {}
   
   unsigned long performFroggerTricount(size_t start, size_t end);
   
   //@override CNFIntTrieRelation
   void buildPrevWord(vector<int>& prevWord) const;
   void resetOutput(vector<int>& output) const;
   

};

#endif //BASE_121_TRIE_RELATION_H