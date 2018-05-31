//B243BunchedInnerGIAT.h

#ifndef BASE_243_INNER_BUNCHED_GROUPED_INT_ARRAY_TRIE_H_
#define BASE_243_INNER_BUNCHED_GROUPED_INT_ARRAY_TRIE_H_

#include "Base243GIAT.h"
#include <map>
using std::map;

class B243BunchedInnerGIAT : public Base243GIAT {
   
   vector<map<int, std::unique_ptr<GenericIntTrie> > > branches;
   int savedInput = -5;
   vector<int> savedChildren;
   
   //void clearChildBits(int loc); //TODO!
   
 public:
   B243BunchedInnerGIAT();
   B243BunchedInnerGIAT(int newLayer);
   virtual ~B243BunchedInnerGIAT() {

   };
   
   bool contains(const vector<int>& box, vector<int>& output);
   bool contains(const vector<int>& box, int currentLayer, vector<int>& output) {
      std::cout << "NOT IMPLEMENTED" << std::endl;
   }
   bool containsWeighted(const weightedBox& wbox, weightedBox& output);

   //defined elsewhere, repeated here for convenience
  // const int INSERT_ZIP_BROKEN = 0;
   //0 (false): ZIP needs to be broken
  // const int INSERT_SUCCESSFUL = 1;
   //1 (true): Successful insertion
  // const int INSERT_PRESENT = 2;
   //2: Already present
  // cosnt int INSERT_MERGE_REQ = 3;
   //3: Child was filled; a merge is requested
   int insert(const vector<int>& box);
   int insertWeighted(const weightedBox& box);
   int insert(const vector<int>& box, int& firstNewsLayer, Base243GIAT*& firstNew);
   
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
  // void apply(trie_actor* actor); //TODO!
   
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth);
   void getAllContainingBoxesWeighted( const weightedBox& input,
                  vector<weightedBox>& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth);

   std::string getType() {
      return string("Base243InnerGIAT");
   }
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index) {
      std::cout << "ERROR: Not implemented!" << std::endl;
   }
   std::shared_ptr<GenericIntTrie> getChild(int index) {
      std::cout << "ERROR: Not implemented!" << std::endl;
   }
   
   Base243GIAT* get243Child(int index) {
      std::cout << "ERROR: Not implemented!" << std::endl;
   }
   
   void add243Children(std::vector<std::vector<Base243GIAT*> >& lists, 
      int index, int& remaining);
   
   int getNextActiveLayer(const vector<int>& box) const;
   
   void forcedInsertAtZero(GenericIntTrie* trie);
   
   friend class CNFIntTrieRelation;
  
   void resetPrevWord(vector<int>& prevWord, int& myLayer) const;
};

#endif