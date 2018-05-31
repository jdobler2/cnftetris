//trie.h
#ifndef TRIE_H_
#define TRIE_H_

#include <vector>
#include <string>
#include <iostream>
#include "GenericTrie.h"

using std::vector;
using std::string;

struct trie_actor;

struct trieValuePair {
   trieNode * node;
   vector<string> box;
};


class trie : public GenericTrie {
  protected:
  
   int maxDepth;
   int maxNodeID;
   
   //gets reference to the trieNode corresponding to a set of boxes,
   //or returns 'null' if not present.
   trieValuePair find(vector<string> box);
   trieNode * firstNode;
  public:
   trie();
   ~trie();
   
   struct getBoxesActor : public trie_actor {
      vector<vector<string> > container;
      vector<string> box;
      
      getBoxesActor() {}
      
      void setBox(vector<string>& newBox); 
      void if_word(trieNode* tn, vector<string> currentWord);  
      bool br_left_if(trieNode* tn, vector<string> currentWord);
      bool br_right_if(trieNode* tn, vector<string> currentWord);
   };
   
   bool contains(const vector<string>& box);
   bool insert(const vector<string>& box);
   bool remove(const vector<string>& box);
   void apply(trie_actor* actor);
   int size();
   
   void setMaxDepth(int mD) {maxDepth = mD;}
   void setMaxNodeID(int mNID) {maxNodeID = mNID;}
   
   vector<vector<string> > getAllContainingBoxes(const vector<string>& box);
};

#endif //TRIE_H_
