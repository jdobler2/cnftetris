//Base243TrieRelation.h

#ifndef BASE_243_TRIE_RELATION_H
#define BASE_243_TRIE_RELATION_H

#include "Base121TrieRelation.h"
#include "clause.h"

class Base243TrieRelation : public Base121TrieRelation {
   
protected:
   #define B243_ALL_LAMBDA 0
   #define B243_CNFLAMBDA 0
   #define B243_CNFNEG 1
   #define B243_CNFPOS 2
   #define LAYER_SIZE 5
   
   unsigned long long mMaxWeight;
   std::shared_ptr<GenericIntTrie> localCDB;
   
   //flat varients are non-virtual
   //double ratio;
   //int finalDegree;
   void fillZero(vector<int>& input, int& index);
   void fillZero(weightedBox& input, int& index);

   int highestSetBit(int value) const;
   int highestSetBitFlat(int value) const;

   
   void popOne(vector<int>& input, int& last, int& index);
   void popOneFlat(vector<int>& input, int& last, int& index);
   void popOneFlat(vector<int>& input, int& index);
   void popOne(vector<int>& input, int& index);
   //this is ugh. Done to give version that won't look at activeLocks.
      //TODO: Find a better way?
   void popOneConst(vector<int>& input, int& index) const;
   
   void setNext(vector<int>& input, int val, int& index);
   void setNextFlat(vector<int>& input, int val, int& index);
   int performShrinkage(vector<int>& input, vector<int>& output, int& index);
                    
                    
   void insertData(vector<vector<int> >& input, int maxNodeID);
   void outputPop(vector<int>& input, int& index) const;
   void mergeBoxesFlat(vector<int>& input1, vector<int>& input2, int& index) const;
   void layerSkipFlat(const int& input1, const int& input2, int& output) const;
   
   void insertData(vector<clause>& input, int maxNodeID);

   using Base121TrieRelation::popAndMerge;
   void popAndMerge(weightedBox& input, weightedBox& output,
                    vector<weightedBox>& pastS01s,
                    std::shared_ptr<GenericIntTrie> cdb,
                    int& index);
   void advanceByOne(weightedBox& input,
                     vector<weightedBox>& pastS01s,
                     int& index);
   
   //@override
   void buildDepthLUT();
   virtual int countLambdas(vector<int>& input, int start, int end) const;
   
   //for locks243
   virtual void fixMaxDepth(int& maxDepth) const;
   
  public:
   Base243TrieRelation();
   ~Base243TrieRelation();
   
   unsigned long performFroggerTricount(size_t start, size_t end);
   
   //@override CNFIntTrieRelation
   void buildPrevWord(vector<int>& prevWord) const;
   
   void resetOutput(vector<int>& output) const;
   void resetOutput(weightedBox& output) const;

   void initializeInput(vector<int>& input);
   void initializeInput(weightedBox& input) const;

   void buildIndexMax(std::vector<clause>& v, 
                                 int maxNodeID,
                                 std::vector<std::pair<int, int> >& counts,
                                 int maxWeight);
   unsigned long performMaxSATCount(
         size_t start, size_t end);      
   unsigned long weightedTetris(std::shared_ptr<GenericIntTrie> cdb);

   int getAllContainingBoxesB(
      vector<int>& input, 
      vector<vector<int> >& output) const;
   
   int getAllContainingBoxesWeighted(weightedBox& input, 
                                      vector<weightedBox>& output) const;
                                      
   void printBox(weightedBox& input) const;
   void printBox(vector<int>& input) const;
   
   void unsafeBuild(vector<vector<int> >& input, int maxNodeID);

};

#endif //BASE_243_TRIE_RELATION_H