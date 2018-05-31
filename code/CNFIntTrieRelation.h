//CNFIntTrieRelation.h
#ifndef CNF_INT_TRIE_RELATION_H
#define CNF_INT_TRIE_RELATION_H

#include "trie.h"
#include "Relation.h"
#include <set>
#include "SmallIntArrayTrie.h"
#include "SmallIntArrayTrie2.h"
#include "GenericIntTrie.h"
#include "IntTrieRelation.h"
#include "Orderer.h"

class IATDummy : public IntArrayTrie{
   public:
  GenericIntTrie* child;
  
  IATDummy(GenericIntTrie* newChild) {
     child = newChild;
  }
  ~IATDummy() {
     delete child;
  }
  
  int insert(const vector<int>& box) {
     return child->insert(box);
  }
  int insertShort(const vector<int>& box, const vector<int>& raw) {
     return child->insertShort(box, raw);
  }
  
  bool contains(const vector<int>& box, vector<int>& output) {
     return child->contains(box, output);
  }
  
  void getAllContainingBoxesB(const vector<int>& input, vector<vector<int> >& output, vector<int>& prevWord, int& currentLevel) {
     return child->getAllContainingBoxesB(input, output, prevWord, currentLevel);
  }
  
  int insertWeighted(const weightedBox& box) {
     return child->insertWeighted(box);
  }
  
  bool containsWeighted (const weightedBox& box, weightedBox& output) {
     return child->containsWeighted(box, output);
  }
  
  void getAllContainingBoxesWeighted(const weightedBox& input, vector<weightedBox>& output, vector<int>& prevWord, int& currentLevel) {
     return child->getAllContainingBoxesWeighted(input, output, prevWord, currentLevel);
  }
  bool getSingletonData(int& sourceLayer, vector<int>*& candidate, int& extra) {
      return child->getSingletonData(sourceLayer, candidate, extra);
   }
  
};

class CNFIntTrieRelation : public IntTrieRelation {
 protected:
   /* TODO eventually
   struct cnfint_getAllWordsActor : public trie_actor {
      vector<set<size_t> > container;
      vector<int> currentWord;
      void if_interval(IntIntervalTrie* intTrie);
   };
   */
   
   #define _CNFINT_LAMBDA 1
   #define _CNFINT_NEG 2
   #define _CNFINT_POS 3
   #define _CNFINT_KILL -1
   int _LAYER_SIZE;
   
   //this table gives the total number of vars below any given level
   vector<int> depthLUT;
   
   struct cnfint_mlMergerActor : public trie_actor {
      IntArrayTrie* t;
      int maxNodeID;
      int maxDepth;
      
      cnfint_mlMergerActor(IntArrayTrie* tr);
      ~cnfint_mlMergerActor();
      void setTrie(IntArrayTrie* tr);
      
      void if_siat_do_once_after_children(SmallIntArrayTrie* siat);
   }; 
   struct printActorCNF : public trie_actor {
      printActorCNF() {}
      ~printActorCNF() {}
      void if_array_word(IntArrayTrie* siat, int index);
   };
   
   void getAllContainingBoxes(vector<int>& input, 
               vector<pair<dataLayerPair, dataLayerPair> >& output) const;
   
   int getAllContainingBoxesB(vector<int>& input, 
                               vector<vector<int> >& output) const;
                               
   bool getAllContainingBoxesB(vector<int>& input, 
                               vector<int>& output,
                               GenericIntTrie* cdb) const;
   
   /* //TODO: All (most?) of these
   int getLocInTrie(unsigned value, int maxDepth);
   
   unsigned long tetris(GenericIntTrie* cdb) const;

   void popInput(vector<int>& input, int& amount, int& last, int& index) const;
   void popOne(vector<int>& input, int& last, int& index) const;
                 
   int performShrinkage(vector<int>& input, 
                          vector<int>& output,
                          int& index) const;
                          
   void setNext(vector<int>& input, int val, int& index) const;

   void fillZero(vector<int>& input, int& index) const;
   */
   void popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index);
        
   virtual int highestSetBit(vector<int>& input, int& index) const;
   virtual int highestSetBit(int value) const;
         
   int getLambdaCount(vector<int>& input) const;
   virtual int getLambdaCount(vector<int>& input, int maxVal) const;
   
   virtual void insertData(vector<vector<int> >& input, int maxNodeID);
   virtual void outputPop(vector<int>& input, int& index) const {}
   virtual void mergeBoxes(vector<int>& input1, vector<int>& input2, int& index) const;
   
   virtual void buildDepthLUT();
   
   //shared initialization variable
   string ordering;
   unique_ptr<Orderer> orderer;
   int gPreprocess;
   virtual void sharedInit();
   
   //goes from i=start, i < end
   virtual int countLambdas(vector<int>& input, int start, int end) const;
   
   virtual void incrementCountBy(unsigned long amount) const;
   
   virtual void initializePointers(vector<vector<int> >& pastS01s, GenericIntTrie* pTrie);
   
 public:
   //CNFIntTrieRelation(int layers);
   CNFIntTrieRelation();
   ~CNFIntTrieRelation();

   void setOrdering(std::string ordering);
   const unsigned& getKey(size_t index) const {}
   
   const std::vector<unsigned>&  getList(int index) const {}

   const std::pair<unsigned, std::vector<unsigned> >& 
         operator[](const int rhs) const {}

   const std::pair<unsigned, std::vector<unsigned> >& at(int index) const {}

   //returns #layers here (since maxDepth is trivial)
   size_t size() const;
   
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&) {
      std::cout << "ERROR: this relation does not support normal buildIndex!"
                << std::endl;
   }
   
   void buildIndexCNF(std::vector<std::vector<int> >&,
                      int maxNodeID,
                      vector<std::pair<int, int> >& counts);
   
   unsigned long performFroggerTricount(size_t start, size_t end);
   
   unsigned long tetris(GenericIntTrie* cdb);
   
   virtual void buildPrevWord(vector<int>& prevWord) const;
   virtual void resetOutput(vector<int>& output) const;
   virtual void initializeInput(vector<int>& input);
};
#endif //CNF_INT_TRIE_RELATION_H