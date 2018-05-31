//GenericIntArrayTrie.cpp

//note: is abstract class

#include "GenericIntArrayTrie.h"

void GenericIntArrayTrie::setMaxNodeID(int mNID) {
   maxNodeID = mNID; 
   
   int tempMaxNodeID = 1 << (int)ceil(log2(maxNodeID+1));
  // bits.resize(tempMaxNodeID-1+maxNodeID, false);
  // wordBits.resize(tempMaxNodeID-1+maxNodeID, false);
   bits.resize(2*tempMaxNodeID, false);
   wordBits.resize(2*tempMaxNodeID, false);
 //  bits[0] = 1;
 //  wordBits[0] = 1;
   branches.resize(2*tempMaxNodeID);

}