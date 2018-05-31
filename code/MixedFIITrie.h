//MixedFIITrie.h

#ifndef MIXED_F_I_I_TRIE_H_
#define MIXED_F_I_I_TRIE_H_

#include "FixedIITrie.h"

#include "GenericIntTrie.h"
#include "trie.h"
#include <map>

using std::map;
using std::pair;

class MixedIITrie : public GenericIntTrie {

 protected:
   //upperbound, <lowerbound, actVal>
   struct iData {
      int lowBound;
      int layerOffset;
      int actValue;
   };
   
   map<size_t, iData> intervals;
   int maxNodeID;
   int maxDepth;
   int finalLevelStart;
   void buildIData(int& upperBound, idata& data) const;

 public:
   MixedFIITrie(int mD);
   virtual ~MixedFIITrie();
   bool contains(const vector<int>& box, vector<int>& output);
   bool insert(const vector<int>& box);
   
   bool remove(const vector<int>& box);   
   void apply(trie_actor* actor);
   
   map<size_t, iData> getIntervals();
   void setIntervals(map<size_t, iData>& newIntervals);
   
   int size();
};



#endif //MIXED_F_I_I_TRIE_H_