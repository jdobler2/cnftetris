//FertileIntervalTrie.h

#ifndef FERTILE_INTERVAL_TRIE_H_
#define FERTILE_INTERVAL_TRIE_H_

#include "IntervalTrie.h"
#include <map>

using std::map;

class FertileIntervalTrie : public IntervalTrie {
  protected:   
   map<string,GenericTrie*> branches;
   bool isFinalLayer(const vector<string>& box);
   
  public:
   FertileIntervalTrie(int mD);
   ~FertileIntervalTrie();
   
   bool insert(const vector<string>& box);
  // void apply(trie_actor* actor);
   int size();
   bool contains(const vector<string>& box, vector<string>& output);

};

#endif //FERTILE_INTERVAL_TRIE_H_
