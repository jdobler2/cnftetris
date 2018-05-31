#ifndef TRIE_RELATION_H_
#define TRIE_RELATION_H_

#include "trie.h"
#include "Relation.h"
#include <set>
#include "IntervalTrie.h"
#include "ArrayTrie.h"

using std::set;

class TrieRelation : public Relation {
  protected:
   //trie tree;
   ArrayTrie tree;
   int maxDepth;
   const int _LAYERS = 3; //This needs to be mutable eventually, but for now...

   struct simpleMergerActor : public trie_actor {
      void after_children(trieNode* tn, vector<string> currentWord);
   };
   
   struct getAllWordsActor : public trie_actor {
      vector<set<size_t> > container;
      vector<string> currentWord;
      void if_interval(IntervalTrie* intTrie);
   };
   
   struct mlMergerActor : public trie_actor {
      GenericTrie* t;
      int maxNodeID;
      int maxDepth;
      
      mlMergerActor(GenericTrie* tr);
      ~mlMergerActor();
      void setTrie(GenericTrie* tr);
      bool br_down_if(trieNode* tn, vector<string> currentWord);
      void after_children(trieNode* tn, vector<string> currentWord);
      
      void if_array_after_children(ArrayTrie* at, int index);
      
   };
   
   string getBinaryString(unsigned value, int maxDepth);
   
   pair<int, vector<string> > tetris(
      vector<string>& input, 
      GenericTrie* cdb,
      unsigned long& count) const;

   void splitFirstSplittableDim(
      vector<string>& input1, 
      vector<string>& input2, 
      const vector<string>& input) const;
      
   //tests if right is a subset of left
   bool subsumes(vector<string>& left, vector<string>& right) const;
   
   vector<vector<string> > getAllContainingBoxes(vector<string>& input) const;
  
  public:
   TrieRelation();
   ~TrieRelation();
   
   vector<string> merge
     (const vector<string>& box1, const vector<string>& box2, int& mode) const;
   
   const unsigned& getKey(size_t index) const {}
   
   const std::vector<unsigned>&  getList(int index) const {}

   const std::pair<unsigned, std::vector<unsigned> >& 
         operator[](const int rhs) const {}

   const std::pair<unsigned, std::vector<unsigned> >& at(int index) const {}

   size_t size() const;
   
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);
   
   unsigned long performFroggerTricount(size_t start, size_t end);
   
   unsigned long performBuildCNFInput(size_t start, size_t end);
};

#endif //TRIE_RELATION_H_
