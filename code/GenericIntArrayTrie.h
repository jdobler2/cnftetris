//GenericIntArrayTrie.h

#ifndef GENERIC_INT_ARRAY_TRIE_H_
#define GENERIC_INT_ARRAY_TRIE_H_

#include "GenericIntTrie.h"

using std::vector;
using std::string;
struct trie_actor;

class GenericIntArrayTrie : GenericIntTrie {
   vector<std::shared_ptr<SmallIntArrayTrie> > branches;
   int maxDepth;
   int maxNodeID;
   boost::dynamic_bitset<> bits;
   boost::dynamic_bitset<> wordBits;

   virtual void getAllContainingBoxes(const vector<int>& input,
                  vector<pair<dataLayerPair, dataLayerPair> >& output,
                  vector<int>& prevWord) const = 0;

   virtual void setMaxNodeID;
};




#endif //GENERIC_INT_ARRAY_TRIE_H_