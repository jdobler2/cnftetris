//GroupedIntArrayTrie.h

#ifndef GROUPED_INT_ARRAY_TRIE_H_
#define GROUPED_INT_ARRAY_TRIE_H_

#include "SmallIntArrayTrie.h"

class GroupedIntArrayTrie : public SmallIntArrayTrie {
  protected:
   void setMaxNodeID(int mNID);
   int maxLevel;
   void setLevels(int levels);
   
   //internal inserter
   int insertRecursively(const vector<int>& box, int loc, int currLevel);
   int updateChildren(int loc, int currLevel);
   int findCousinMerges(int loc, int currLevel);
   
  public:
   GroupedIntArrayTrie();
   GroupedIntArrayTrie(int newLayer, int levels);
   ~GroupedIntArrayTrie();
   
   bool contains(const vector<int>& box, vector<int>& output);
   bool contains(const vector<int>& box, int currentLayer, vector<int>& output) {
      std::cout << "NOT IMPLEMENTED" << std::endl;
   }
  // const int INSERT_ZIP_BROKEN = 0;
   //0 (false): ZIP needs to be broken
  // const int INSERT_SUCCESSFUL = 1;
   //1 (true): Successful insertion
  // const int INSERT_PRESENT = 2;
   //2: Already present
  // cosnt int INSERT_MERGE_REQ = 3;
   //3: Child was filled; a merge is requested
   int insert(const vector<int>& box);
   
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
   void apply(trie_actor* actor); 
   
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int currentDepth) const;
      
      
   //still being used to get if it's full. 
   //still sorry about that.
   int size();

   std::string getType();
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index) {
      std::cout << "ERROR: This trie has no children!" << std::endl;
   }
   std::shared_ptr<GenericIntTrie> getChild(int index) {
      std::cout << "ERROR: This trie has no children!" << std::endl;
   }
   
   void print();
   
   friend class CNFIntTrieRelation;
};

#endif //SMALL_INT_ARRAY_TRIE_H_