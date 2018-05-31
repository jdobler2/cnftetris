//IntervalTrie.h

#ifndef INTERVAL_TRIE_H_
#define INTERVAL_TRIE_H_

#include "GenericTrie.h"
#include "trie.h"
#include <set>

using std::set;
using std::pair;

class IntervalTrie : public GenericTrie {

  protected:
   set<size_t> intervals;
   int maxNodeID;
   int maxDepth;
   virtual pair<size_t, size_t> convertToInt(const string& binVal) const;
   virtual string convertToString(size_t lower, size_t multCount) const;
   virtual bool isRightBoundary(size_t val) const;
   virtual bool remove_inner(pair<size_t, size_t>& val);
   string buildDyadic(size_t leftInt, size_t rightInt, 
                              size_t lowBound, size_t upBound) const;
   string quickBuildDyadic(const string& input, 
                              int leftInt, int rightInt, 
                              int lowBound, int upBound) const;
   
  public:
   IntervalTrie(int mD);
   virtual ~IntervalTrie();
   bool contains(const vector<string>& box, vector<string>& output);
   bool insert(const vector<string>& box);
   
   bool remove(const vector<string>& box);
   bool remove_for_size(size_t left, size_t right);
   
   void apply(trie_actor* actor);
   
   virtual set<size_t> getIntervals();
   virtual void setIntervals(set<size_t>& newIntervals);
   
   int size();
   virtual bool isFull();

   vector<vector<string> > getAllContainingBoxes(const vector<string>& input,
                                             vector<string>& prevWord) const;
   friend struct printToFileActor;
};

#endif //INTERVAL_TRIE_H_