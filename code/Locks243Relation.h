//Locks243Relation.h

#ifndef LOCKS_243_RELATION_H
#define LOCKS_243_RELATION_H

#include "Base243TrieRelation.h"
#include <unordered_map>
#include <set>

using std::unordered_map;
using std::set;

class Locks243Relation : public Base243TrieRelation {
   /* defined elsewhere, repeated for convenience
   #define B243_ALL_LAMBDA 0
   #define B243_CNFLAMBDA 0
   #define B243_CNFNEG 1
   #define B243_CNFPOS 2
   #define LAYER_SIZE 5
   */
   
   struct pastDatum {
      vector<int> pProbePoint;
      vector<bool> pActiveLocks;
      map<int, set<int> > pActiveLocksLUT;
      map<int, int> pReverseActiveLocksLUT;
   };
   
   //pointers for a couple things to make a few dumb things work.
   vector<vector<int> >* mPastS01s;
   GenericIntTrie* mCdb;
   int bitIndex;
   int mCap;
   int mPrevSource;
   bool mLegalReduction;
   vector<pastDatum> mPastData;
   
   template <typename T> 
   struct offsetVector {
      int offset;
      T eraseValue;
      vector<T> data;

      offsetVector() {
         offset = 0;
      }
      offsetVector(int i) {
         offset = i;
      }
      T& operator[](int i) {
         return data[offset + i];
      }
      void clear() {
         data.clear();
      }
      void resize(int i) {
         data.resize(i*2);
      }
      void resize(int i, T j) {
         data.resize(i*2, j);
         eraseValue = j;
      }
      int count(int i) {
         return (data[offset+i] != eraseValue);
      }
      void erase(int i) {
         data[offset+i] = eraseValue;
      }
      
   };
   //not 100% sure if set best here... Also, maybe vector for first?
      //but as-is, i'm putting negatives in as first coordinate!
      //also, note that ALL of these are counting from 1!
   //vector<int, set<int> > locksLUT;
   offsetVector<set<int> > locksLUT;
   offsetVector<set<int> > reverseLocksLUT;
   vector<int> activeLocks; //note: NO SIGN! Store the act. value.
   vector<std::pair<int, set<int> > > activeLocksLUT; //note: is forwards. Sign on coordinates!
   int activeLocksLUTLoc; //points to back() + 1
   offsetVector<int> reverseActiveLocksLUT; //Sign on both coordinates!
   
   void insertData(vector<vector<int> >& input, int maxNodeID);
   void fillZero(vector<int>& input, int& index);
   //PopAndMerge
   
   void setNext(vector<int>& input, int val, int& index);
   void setNextFlat(vector<int>& input, int val, int& index) {
      setNext(input, val, index);
   }
   
   int performShrinkage(vector<int>& input, 
                        vector<int>& output,
                        int& index); //TODO: Ditto
                        
   //!@direction: 1 = positive, -1 = subtraction. @return: value written
   int writeToInput(vector<int>& input, int loc, int direction = 1);
   
   //! This is for anything that is not the probe point itself
   void popOne(vector<int>& input, int& index);
   
   //! this is for the probe point itself
   void popOne(vector<int>& input, int& last, int& index);
   
   //! do not call directly.
   void popOneCore(vector<int>& input, int& last, int& index);
   
   //return value is if anything were already there.
   //loc MUST be positive!
   bool clearLocksAt(vector<int>& input, int loc);
   
   int highestSetBit(vector<int>& input, int& index) const;
   int highestSetBit(int input) const;
   int firstUnsetBit(int input) const;
   
   //@override CNFIntTrieRelation
   void initializePointers(vector<vector<int> >& pastS01s, GenericIntTrie* pTrie);
   
   void initializeInput(vector<int>& input);
   
   void addChainsToLocksLUT(int source, int destination);
   void addReverseChainsToLocksLUT(int source, int destination);
   void checkNonselfContradictions(int source, int destination);
   void checkSelfContradictions(int source, int destination);
   void addToLocksLUT(int source, int destination);
   
   void attachOnEnd(vector<int>& input, int& index);
   void outputPop(vector<int>& input, int& index) const;

   //@override Base121
   // int mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower);

   //@override Base121, technically
   void repairLocks(vector<int>& input, int& index, int start, int end);
   int updateBitIndex(vector<int>& input, int& index);
   void setCap(int& diff);
   void removeCap();
   bool isPermitted(vector<int>& output, int& index, int& indexLower, int& il2);
   void checkForAltOutput(vector<int>& input, int& index, vector<int>& output);
   
   //@override Base243, technically
   void fixMaxDepth(int& maxDepth) const;
   
   int mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower);
   
};

#endif //LOCKS_243_RELATION_H