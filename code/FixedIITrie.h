//FixedIITrie.h

#ifndef FIXED_I_I_TRIE_H_
#define FIXED_I_I_TRIE_H_

#include "GenericIntTrie.h"
#include "trie.h"
#include <map>

using std::map;
using std::pair;

class FixedIITrie : public GenericIntTrie {

 protected:
   //upperbound, <lowerbound, actVal>
   map<size_t, pair<size_t, size_t> > intervals;
   int maxNodeID;
   int maxDepth;
   int finalLevelStart;
   void buildData(int& index, pair<size_t, size_t>& data) const;

 public:
   FixedIITrie(int mD);
   virtual ~FixedIITrie();
   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box);
   bool insertPair(const pair<dataLayerPair, dataLayerPair>& box);

   bool remove(const vector<int>& box);   
   void apply(trie_actor* actor);
   
   map<size_t, pair<size_t, size_t> > getIntervals();
   void setIntervals(map<size_t, pair<size_t, size_t> >& newIntervals);
   
   int size();

   void getAllContainingBoxes(const vector<int>& input,
                             vector<pair<dataLayerPair, dataLayerPair> >& output,
                             vector<int>& prevWord) const;
};






#endif //FIXED_I_I_TRIE_H_