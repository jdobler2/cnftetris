//SIMD_InnerGIAT.h

#ifndef SIMD_INNER_GROUPED_INT_ARRAY_TRIE_H_
#define SIMD_INNER_GROUPED_INT_ARRAY_TRIE_H_

#include "SIMD_GIATrie.h"
#include <map>

//have to abandon the IAT framework, since we need an array of bitsets
class SIMD_InnerGIAT : public SIMD_GIATrie {
  protected:

   //uint64_t * const childBits = wordBits + 2; //64 bits (1 ulonglong) * 2 have been allocated for it.
                 //First 121 bits are used. 
   #define childBits (wordBits + 2)
   vector<std::unique_ptr<GenericIntTrie> > branches;
   
   int savedInput = -5;
   vector<int> savedChildren;
   
   void clearChildBits(int loc);
   
   static vector<vector<int> > dummy;
   
   bool handleSingleton(const vector<int>& box, 
                        vector<int>& output, 
                        vector<vector<int> >& setOfOutputs, 
                        int mode, int& currentDepth);
   //singleton modes
   #define MODE_CONTAINS               0x0000
   #define MODE_GACB                   0x0001
   
   #define GIAT_STATUS_EMPTY           0x0000
   #define GIAT_STATUS_CHILDREN_ONLY   0x0001
   #define GIAT_STATUS_WORD_ONLY       0x0002
   #define GIAT_STATUS_BOTH            0x0003
   int mStatus;

  public:
   SIMD_InnerGIAT();
   SIMD_InnerGIAT(int newLayer);
   virtual ~SIMD_InnerGIAT() {

   };
   
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
   
   virtual void resetPrevWord(vector<int>& prevWord, int& myLayer) const;
};

#endif //SIMD_InnerGIAT_H_