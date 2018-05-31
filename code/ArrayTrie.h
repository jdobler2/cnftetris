//ArrayTrie.h

#ifndef ARRAY_TRIE_H_
#define ARRAY_TRIE_H_

#include <vector>
#include <string>
#include <iostream>
#include "GenericTrie.h"
#include "boost/dynamic_bitset.hpp"

using std::vector;
using std::string;

struct trie_actor;

class ArrayTrie : public GenericTrie {
  protected:
  
   int maxDepth;
   int maxNodeID;
   boost::dynamic_bitset<> bits;
   boost::dynamic_bitset<> wordBits;
   vector<std::unique_ptr<GenericTrie> > branches;
   
   bool deleteChildren(int index);
   bool remainingInputEmpty(const vector<string>& input, int start);
   
  public:
   ArrayTrie();
   ArrayTrie(int mD) {
      this->setMaxNodeID(mD);
   }
   ~ArrayTrie();
     
   bool contains(const vector<string>& box, vector<string>& output);
   bool insert(const vector<string>& box);
   bool remove(const vector<string>& box);
   void apply(trie_actor* actor, int index);
   void apply(trie_actor* actor);
   int size();
   
   void setMaxDepth(int mD);
   void setMaxNodeID(int mNID);
   
   vector<vector<string> > getAllContainingBoxes(const vector<string>& input,
                                            vector<string>& prevWord) const;
   
   vector<vector<string> > getAllContainingBoxes(const vector<string>& input,
                                            vector<string>& prevWord,
                                            int cap) const;
   
   friend class TrieRelation; 
};

#endif //ArrayTrie.h