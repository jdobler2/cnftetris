//GenericTrie.h

#ifndef GENERIC_TRIE_H_
#define GENERIC_TRIE_H_

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

class GenericTrie;
struct trie_actor;
struct printActor;
class IntervalTrie;
class ArrayTrie;
class FertileIntervalTrie;
class IntIntervalTrie;
class IntArrayTrie;
class IntFITrie;
class SmallIntArrayTrie;

struct trieNode {
   char value; //technically redundant, but makes life easier
   trieNode * leftChild = NULL;
   trieNode * rightChild = NULL;
   GenericTrie * branchChild = NULL;
   trieNode * parent = NULL;
   bool isWord() { return (leftChild==NULL && 
                           rightChild==NULL && 
                           branchChild==NULL); }
   ~trieNode();
   void apply(trie_actor* actor, vector<string> currentWord);
};

struct trie_actor {
   virtual void always_do(trieNode* tn, vector<string> currentWord) {}
   virtual void if_not_root(trieNode* tn, vector<string> currentWord) {}
   virtual void if_root(trieNode* tn, vector<string> currentWord) {}
   virtual void if_word(trieNode* tn, vector<string> currentWord) {}
   virtual void after_children(trieNode* tn, vector<string> currentWord) {}
   virtual bool br_left_if(trieNode* tn, vector<string> currentWord) {
      return true;
   }
   virtual bool br_right_if(trieNode* tn, vector<string> currentWord) {
      return true;
   }
   virtual bool br_down_if(trieNode* tn, vector<string> currentWord) {
      return true;
   }
   
   virtual void if_interval(IntervalTrie* intTrie) {}
   virtual void if_interval(IntIntervalTrie* intTrie) {}
   
   virtual void if_array(ArrayTrie* arrTrie, int index) {}
   virtual void if_array_after_children(ArrayTrie* arrTrie, int index) {}
   virtual void if_array_word(ArrayTrie* arrTrie, int index) {}
   virtual void if_array(IntArrayTrie* arrTrie, int index) {}
   virtual void if_array_after_children(IntArrayTrie* arrTrie, int index) {}
   virtual void if_array_word(IntArrayTrie* arrTrie, int index) {}
   
   virtual void if_siat_do_once(SmallIntArrayTrie* siaTrie) {}
   virtual void if_siat_do_once_after_children(SmallIntArrayTrie* siaTrie) {}
   
   virtual void if_fertileInterval(FertileIntervalTrie* fIntTrie) {}
   virtual void if_fertileInterval(IntFITrie* fIntTrie) {}

};

class GenericTrie {
  protected:
   int myLayer = 0;
  public:
   //both reflect to the other so that, if desired, only one or the other
   //can be implemented. Also, backwards-compat.
   virtual bool contains(const vector<string>& box) {
      vector<string> temp;
      return contains(box, temp);
   }
   virtual bool contains(const vector<string>& box, vector<string>& output) {
      return contains(box);
   }
   virtual bool insert(const vector<string>& box) = 0;
   virtual bool remove(const vector<string>& box) = 0;
   virtual void apply(trie_actor* actor) = 0;
   virtual int size() = 0;
   virtual bool remove_for_size(size_t left, size_t right) {}
   virtual ~GenericTrie() {}
   virtual int setMyLayer(int newLayer) {
      myLayer = newLayer;
   }
   
   //friendApply is for actors that need to be friended by the Trie,
   //and use this to work more efficiently
   virtual vector<vector<string> > getAllContainingBoxes(
         const vector<string>& input,
         vector<string>& prevWords) const
   {
      std::cout << "ERROR: getContainingBoxes not implemented for this Trie!"
                << std::endl;
   }
   
   virtual std::string getType() {
      return "GenericTrie";
   }
   
};
   
#endif //GENERIC_TRIE_H