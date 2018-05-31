//IntTrieRelation.h
#ifndef INT_TRIE_RELATION_H
#define INT_TRIE_RELATION_H

#include "trie.h"
#include "Relation.h"
#include <set>
#include <memory>
#include "IntIntervalTrie.h"
#include "IntArrayTrie.h"
#include "GenericIntTrie.h"

using std::set;

class IntTrieRelation : public Relation {
 protected:
   IntArrayTrie* tree;
   int maxDepth;
   int shift;
   int _LAYERS = 3; //for triangles
   
   struct int_getAllWordsActor : public trie_actor {
      vector<set<size_t> > container;
      vector<int> currentWord;
      void if_interval(IntIntervalTrie* intTrie);
   };
   
   struct int_mlMergerActor : public trie_actor {
      GenericIntTrie* t;
      int maxNodeID;
      int maxDepth;
      
      int_mlMergerActor(GenericIntTrie* tr);
      ~int_mlMergerActor();
      void setTrie(GenericIntTrie* tr);
      
      void if_array_after_children(IntArrayTrie* at, int index);
   };
   
   virtual int getLocInTrie(unsigned value, int maxDepth);
   
   virtual unsigned long tetris(GenericIntTrie* cdb);

   void getAllContainingBoxes(vector<int>& input, 
                  vector<pair<dataLayerPair, dataLayerPair> >& output) const;
   virtual int getAllContainingBoxesB(vector<int>& input,
                  vector<vector<int> >& output) const {
      std::cout << "ERROR: Not implemented!" << std::endl;
      return -1;
   }

   virtual void popInput(vector<int>& input, int& amount, int& last, int& index) const;
   virtual void popOne(vector<int>& input, int& last, int& index);
                 
   virtual void popOne(vector<int>& input, int& index);
                 
   virtual int performShrinkage(vector<int>& input, 
                          vector<int>& output,
                          int& index);
                          
   virtual void setNext(vector<int>& input, int val, int& index);

   virtual void fillZero(vector<int>& input, int& index);
   
   virtual void popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index);
        
   virtual int highestSetBit(int value) const;
         
         
 public:
   IntTrieRelation();
   virtual ~IntTrieRelation();

   const unsigned& getKey(size_t index) const {}
   
   const std::vector<unsigned>&  getList(int index) const {}

   const std::pair<unsigned, std::vector<unsigned> >& 
         operator[](const int rhs) const {}

   const std::pair<unsigned, std::vector<unsigned> >& at(int index) const {}

   size_t size() const;
   
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);
   
   void buildIndexCNF(std::vector<std::vector<int> >&,
                      int maxNodeID);
   
   unsigned long performFroggerTricount(size_t start, size_t end);
   
   unsigned long performPreloadedTricount(size_t start, size_t end);
};
#endif //INT_TRIE_RELATION_H
