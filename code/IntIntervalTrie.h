//IntIntervalTrie.h

#ifndef INT_INTERVAL_TRIE_H_
#define INT_INTERVAL_TRIE_H_

#include "GenericIntTrie.h"
#include "trie.h"
#include <set>

using std::set;
using std::pair;

class IntIntervalTrie : public GenericIntTrie {

  protected:
   set<size_t> intervals;
   int maxNodeID;
   int maxDepth;
   int finalLevelStart;
   virtual pair<size_t, size_t> convertToPair(const int& index) const;
 //  virtual int convertToIndex(size_t lower, size_t multCount) const;
   virtual bool isRightBoundary(size_t val) const;
   virtual bool remove_inner(pair<size_t, size_t>& val);
  // int buildDyadic(size_t leftInt, size_t rightInt, 
  //                            size_t lowBound, size_t upBound) const;
   int quickBuildDyadic(const int& input, 
                              int leftInt, int rightInt, 
                              int lowBound, int upBound) const;
   
  public:
   IntIntervalTrie(int mD);
   virtual ~IntIntervalTrie();
   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box);
   
   bool remove(const vector<int>& box);
   bool remove_for_size(size_t left, size_t right);
   
   void apply(trie_actor* actor);
   
   virtual set<size_t> getIntervals();
   virtual void setIntervals(set<size_t>& newIntervals);
   
   int size();
   virtual bool isFull();

  void getAllContainingBoxes(const vector<int>& input,
                       vector<pair<dataLayerPair, dataLayerPair> >& output,
                       vector<int>& prevWord) const;
   friend struct printToFileActor;
};

#endif //INT_INTERVAL_TRIE_H_