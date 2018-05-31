//ZipIntTrie.h

#ifndef ZIP_INT_TRIE_H_
#define ZIP_INT_TRIE_H_

#include "GenericIntTrie.h"

class ZipIntTrie : public GenericIntTrie {
  protected:
   int layersSkipped;
   std::shared_ptr<GenericIntTrie> child;
  public:
   ZipIntTrie(int newLayer, int newLayersSkipped);
   ~ZipIntTrie();

   bool contains(const vector<int>& box, vector<int>& output);
   int insert(const vector<int>& box);
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
   void apply(trie_actor* actor); 
  
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth) const;
                  
   //is now being used to get layers skipped. 
   //...I should rename size to "generic size-related number thingy".
   int size();
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index);
   std::shared_ptr<GenericIntTrie> getChild(int index);
};

#endif //ZIP_INT_TRIE_H_