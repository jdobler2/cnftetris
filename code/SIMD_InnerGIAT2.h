//SIMD_InnerGIAT.h

#ifndef SIMD_INNER_GROUPED_INT_ARRAY_TRIE_2_H_
#define SIMD_INNER_GROUPED_INT_ARRAY_TRIE_2_H_

#include "SIMD_GIATrie2.h"

//have to abandon the IAT framework, since we need an array of bitsets
class SIMD_InnerGIAT2 : public SIMD_GIATrie2 {
  protected:

   uint32_t childBits[maxLevel]; //32 bits (1 ulong) * 4. 
                 //First 120 bits are used. 
   vector<std::shared_ptr<GenericIntTrie> > branches;
   
   void clearChildBits(int loc);

  public:
   SIMD_InnerGIAT2();
   SIMD_InnerGIAT2(int newLayer);
   ~SIMD_InnerGIAT2() {};
   
   bool contains(const vector<int>& box, vector<int>& output);
   bool contains(const vector<int>& box, int currentLayer, vector<int>& output) {
      std::cout << "NOT IMPLEMENTED" << std::endl;
   }
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
   
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
  // void apply(trie_actor* actor); //TODO!
   
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth);
      

   std::string getType() {
      return string("SIMD_GIATrie");
   }
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index) {
      std::cout << "ERROR: Not implemented!" << std::endl;
   }
   std::shared_ptr<GenericIntTrie> getChild(int index) {
      std::cout << "ERROR: Not implemented!" << std::endl;
   }
   
   friend class CNFIntTrieRelation;
};

#endif //SIMD_InnerGIAT_2_H_