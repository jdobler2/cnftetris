//IterTrieRelation.h
#ifndef ITER_TRIE_RELATION_H_
#define ITER_TRIE_RELATION_H_

#include "TrieRelation.h"

class IterTrieRelation : public TrieRelation {
  protected:
   void popInput(vector<string>& input, int& amount, char& last,
                 int& indexUpper, int& indexLower) const;
   
   int determineShrinkage(vector<string>& input, 
                          vector<string>& output) const;
   
   void setNext(vector<string>& input, char val, 
                int& indexUpper, int& indexLower) const;
               
   void popAndMerge(vector<string>& input, vector<string>& output,
                    vector<vector<string> >& pastS01s,
                    GenericTrie* cdb,
                    int& amount,
                    int& indexUpper,
                    int& indexLower) const;
                    
   unsigned long tetrisUnfolded(GenericTrie* cdb) const;
 
  public:
   unsigned long performFroggerTricount(size_t start, size_t end);
};

#endif //ITER_TRIE_RELATION_H_
