//IntArrayTrie.h

#ifndef INT_ARRAY_TRIE_H_
#define INT_ARRAY_TRIE_H_

#include "ArrayTrie.h"
#include "GenericIntTrie.h"

using std::vector;
using std::string;

struct trie_actor;

//TODO: have an arch-class that both this and ArrayTrie inherit from,
//to reduce duplicate code!!
class IntArrayTrie : public GenericIntTrie {
  protected:
  
   int insertionMode;
   //0: index
   //1: CDB
   //2: mid-level CDB
   //3: single-bit trie
   
   int maxDepth;
   int maxNodeID;
   boost::dynamic_bitset<> bits;
   boost::dynamic_bitset<> wordBits;
   vector<std::shared_ptr<GenericIntTrie> > branches;
   
   bool deleteChildren(int index);
   virtual bool remainingInputEmpty(const vector<int>& input, int start);
   
  public:
   IntArrayTrie();
   IntArrayTrie(int mD, int newMode, int newLayer);
   IntArrayTrie(int mD) {
      this->setMaxNodeID(mD);
            std::cout << "done creating" << std::endl;
   }
   virtual ~IntArrayTrie();
     
   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box);
   virtual int insertShort(const vector<int>& box, const vector<int>& raw) {
      std::cout << "ERROR: insertShort Not implemented for this trie!";
   }
   bool insertPair(const pair<dataLayerPair, dataLayerPair>& box);
   
   bool remove(const vector<int>& box);
   void apply(trie_actor* actor, int index);
   void apply(trie_actor* actor);
   int size();
   
   virtual void setMaxDepth(int mD);
   virtual void setMaxNodeID(int mNID);
   void setInsertionMode(int mode) {
      insertionMode = mode;
   }
   
   void getAllContainingBoxes(const vector<int>& input,
                  vector<pair<dataLayerPair, dataLayerPair> >& output,
                  vector<int>& prevWord) const;
   
   
   void pointerClone(const IntArrayTrie& rhs);
   
   friend class IntTrieRelation; 
   friend class CNFIntTrieRelation;
};

#endif //IntArrayTrie.h