//GenericIntTrie.h

#ifndef GENERIC_INT_TRIE_H_
#define GENERIC_INT_TRIE_H_

#include <vector>
#include <string>
#include <iostream>
#include <memory>

//number of layers remaining at which point to switch to GIAT or SIMD_GIAT
//(Grouped Int Array Trie)
//set to 4 for SIMD_GIAT!!!
#define GIAT_SWITCH -1

using std::vector;
using std::string;
using std::pair;

class GenericTrie;
struct trie_actor;
struct printActor;
class IntervalTrie;
class ArrayTrie;
class FertileIntervalTrie;
class Base243GIAT;

struct dataLayerPair {
   int data;
   int layer;
   dataLayerPair(int nData = 1, int nLayer = 1): data(nData), layer(nLayer) {} 
};

struct weightedBox {
   vector<int> box;
   long long weight; 
   void* data;
};

class GenericIntTrie {
  protected:
   int myLayer = 0;
   static int _LAYERS;
   static int _MODLAYERS;
   
  public:
   //both reflect to the other so that, if desired, only one or the other
   //can be implemented. Also, backwards-compat.
   virtual bool contains(const vector<int>& box) {
      vector<int> temp;
      return contains(box, temp);
   }
   virtual bool contains(const vector<int>& box, vector<int>& output) {
      return contains(box);
   }
   
   virtual bool containsWeighted(const weightedBox& box, weightedBox& output) {
      std::cout << "ERROR: containsWeighted not implemented for this trie!" 
                << std::endl;
   }
   
   #define INSERT_ZIP_BROKEN 0
   //0 (false): ZIP needs to be broken
   #define INSERT_SUCCESSFUL 1
   //1 (true): Successful insertion
   #define INSERT_PRESENT 2
   //2: Already present
   #define INSERT_MERGE_REQ 3
   //3: Child was filled; a merge is requested
   
   virtual int insert(const vector<int>& box) = 0;
   virtual bool insertPair(const pair<
         dataLayerPair, dataLayerPair>& box) {
      std::cout << "ERROR: insertPair not implemented for this trie!" 
                << std::endl;
   }
   
   virtual int insertWeighted(const weightedBox& wbox) {
      std::cout << "ERROR: insertWeighted not implemented for this trie!"
                << std::endl;
   }
   virtual int insert(const vector<int>& box, int& firstNewsLayer, Base243GIAT*& firstNew) {
      std::cout << "ERROR: insert(3) not implemented for this trie!"
                << std::endl;
   }
   
   virtual int insertShort(const vector<int>& box, const vector<int>& raw) {
      insert(box);
   }

   
   virtual bool remove(const vector<int>& box) = 0;
   virtual void apply(trie_actor* actor) = 0;
   virtual int size() = 0;
   virtual bool remove_for_size(size_t left, size_t right) {}
   virtual ~GenericIntTrie() {}
   virtual int setMyLayer(int newLayer) {
      myLayer = newLayer;
   }
   virtual int getMyLayer() {
      return myLayer;
   }
   virtual int setLayers(int newLayer) {
      _LAYERS = newLayer;
   }
   virtual int setModLayers(int newModLayer) {
      _MODLAYERS = newModLayer;
   }
   
   virtual void getAllContainingBoxes(
         const vector<int>& input,
         vector<pair<dataLayerPair, dataLayerPair> >& output,
         vector<int>& prevWord) const
   {
      std::cout << "ERROR: getContainingBoxes not implemented for this Trie!"
                << std::endl;
   }
   virtual void getAllContainingBoxesB( 
                  const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth)
   {
      std::cout << "ERROR: getContainingBoxesB not implemented for this Trie!"
                << std::endl;
   }
   
   virtual void getAllContainingBoxesWeighted( 
                  const weightedBox& input,
                  vector<weightedBox>& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input's box!
                  int& currentDepth)
   {
      std::cout << "ERROR: getContainingBoxesWeighted not implemented for this Trie!"
                << std::endl;
   }
   
   virtual string getType() {
      return "GenericIntTrie";
   }
   
   virtual bool append(std::shared_ptr<GenericIntTrie> tr, int index) {
      std::cout << "ERROR: Append is not implemented in this trie!" 
                << std::endl;
   }

   virtual std::shared_ptr<GenericIntTrie> getChild(int index) {
      std::cout << "ERROR: getChild is not implemented in this trie!"
                << std::endl;
   }
   
   //for the SIMD_SkippingInnerGIAT
   virtual void forcedInsertAtZero(GenericIntTrie* trie) {
      std::cerr << "Error: ForcedInsertAtZero not defined for this trie!" << std::endl;
   }
   
   void printBox(vector<int> box) {
      for (int i = 0; i < box.size(); i++) {
         std::cout << box.at(i) << ", ";
      }
      std::cout << std::endl;
   }
   
   //for getting singleton data where applicable
   //returns false if no singleton, or if unsupported. True otherwise.
   virtual bool getSingletonData(int& sourceLayer, vector<int>*& candidate, int& extra) {
      return false;
   }
};
   
#endif //GENERIC_INT_TRIE_H