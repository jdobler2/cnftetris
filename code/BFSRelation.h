// ============================================================================
// BFSRelation.h
// ~~~~~~~~~~~~~~~~
// author: jdobler
// may 23, 2014
// - the BFSRelation
// ============================================================================
#ifndef BFSRELATION_H_
#define BFSRELATION_H_

#include "SimpleRelation.h"

class BFSRelation: virtual public SimpleRelation 
{
   public:
   BFSRelation() {}
   ~BFSRelation() {}

   unsigned long performFroggerTricount(size_t start, size_t end);

   // build an index for this relation from raw unsorted data
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);
};

#endif // BFSRELATION_H_

