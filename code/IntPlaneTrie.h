//IntPlaneTrie.h

#ifndef INT_PLANE_TRIE_H_
#define INT_PLANE_TRIE_H_

#include "GenericIntTrie.h"
#include "IntervalTrie.h"
#include "FixedIITrie.h"
#include <iostream>

using std::pair;

class IntPlaneTrie : public GenericIntTrie {
  protected:
   vector<FixedIITrie*> planes;
   int maxNodeID;
   int maxDepth;
  public:
   IntPlaneTrie(int mD, int layers, int newLayer);
   virtual ~IntPlaneTrie();
   
   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box); 
   bool insertPair(const pair<dataLayerPair, dataLayerPair>& box);

   bool remove(const vector<int>& box) {
      std::cout << "ERROR: PlaneTrie::remove not implemented!" << std::endl;
   }
   void apply(trie_actor* actor) {
      std::cout << "ERROR: PlaneTrie::apply not implemented!" << std::endl;
   }
   int size() {
      return planes.size();
   }
   
};

#endif //INT_PLANE_TRIE_H_