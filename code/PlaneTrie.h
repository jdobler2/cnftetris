//PlaneTrie.h

#ifndef PLANE_TRIE_H_
#define PLANE_TRIE_H_

#include "GenericTrie.h"
#include "IntervalTrie.h"
#include <iostream>

using std::pair;

class PlaneTrie : public GenericTrie {
  protected:
   vector<IntervalTrie*> planes;
   int maxNodeID;
   int maxDepth;
  public:
   PlaneTrie(int mD, int layers, int newLayer);
   virtual ~PlaneTrie();
   
   bool contains(const vector<string>& box, vector<string>& output);
   bool insert(const vector<string>& box); 
   bool remove(const vector<string>& box) {
      std::cout << "ERROR: PlaneTrie::remove not implemented!" << std::endl;
   }
   void apply(trie_actor* actor) {
      std::cout << "ERROR: PlaneTrie::apply not implemented!" << std::endl;
   }
   int size() {
      return planes.size();
   }
   
};

#endif //PLANE_TRIE_H_