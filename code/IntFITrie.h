//IntFITrie.h

#ifndef INT_F_I_TRIE_H_
#define INT_F_I_TRIE_H_

#include "IntIntervalTrie.h"
#include <map>

using std::map;

class IntFITrie : public IntIntervalTrie {
  protected:   
   map<int,GenericIntTrie*> branches;
   bool isFinalLayer(const vector<int>& box);
   
  public:
   IntFITrie(int mD);
   ~IntFITrie();
   
   int insert(const vector<int>& box);
  // void apply(trie_actor* actor);
   int size();
   bool contains(const vector<int>& box, vector<int>& output);

};

#endif //INT_F_I_TRIE_H_
