//PointerTrie.h

//IntPlaneTrie.h

#ifndef POINTER_TRIE_H_
#define POINTER_TRIE_H_

#include "GenericIntTrie.h"
#include "IntervalTrie.h"
#include "FixedIITrie.h"
#include <iostream>
#include "boost/dynamic_bitset.hpp"

using std::pair;

class PointerTrie : public GenericIntTrie {
  protected:
   std::shared_ptr<GenericIntTrie> tree;
   int maxNodeID;
   int maxDepth;
   int layerCount;
  public:
   PointerTrie(const int mD, const int layers,
               const int newLayer, std::shared_ptr<GenericIntTrie> child);
   virtual ~PointerTrie();
   
   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box) {
  //    std::cout << "ERROR: PointerTrie::insert not implemented!" << std::endl;
      return false;
   }
   bool insertPair(const pair<dataLayerPair, dataLayerPair>& box){
 //     std::cout << "ERROR: PointerTrie::insertPair not implemented!" << std::endl;
      return false;
   }
   bool remove(const vector<int>& box) {
      std::cout << "ERROR: PointerTrie::remove not implemented!" << std::endl;
   }
   void apply(trie_actor* actor) {
      std::cout << "ERROR: PointerTrie::apply not implemented!" << std::endl;
   }
   int size() {
      return layerCount;
   }
   
};

#endif //POINTER_TRIE_H_