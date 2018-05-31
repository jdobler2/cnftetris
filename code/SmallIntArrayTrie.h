//SmallIntArrayTrie.h

#ifndef SMALL_INT_ARRAY_TRIE_H_
#define SMALL_INT_ARRAY_TRIE_H_

#include "IntArrayTrie.h"

class SmallIntArrayTrie : public IntArrayTrie {
  protected:
   bool remainingInputEmpty(const vector<int>& input, int start);
   bool isLastInput(const vector<int>& input, int start);
   void setMaxNodeID(int mNID);
   
  public:
   SmallIntArrayTrie();
   SmallIntArrayTrie(int newLayer);
   ~SmallIntArrayTrie();
   
   bool contains(const vector<int>& box, vector<int>& output);
   bool contains(const vector<int>& box, int currentLayer, vector<int>& output);
   
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
                  int& currentDepth) const;
      
      
   //is now being used to get if it's full. 
   //sorry about that.
   int size();

   std::string getType();
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index);
   std::shared_ptr<GenericIntTrie> getChild(int index);   
   
   friend class CNFIntTrieRelation;
};

#endif //SMALL_INT_ARRAY_TRIE_H_