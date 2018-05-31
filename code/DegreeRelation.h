// ============================================================================
// DegreeRelation.h
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - the DegreeRelation class
// ============================================================================
#ifndef DEGREE_RELATION_H_
#define DEGREE_RELATION_H_

#include "BFSRelation.h"

class DegreeRelation : virtual public BFSRelation 
{
   public:
   DegreeRelation() = default;
   ~DegreeRelation() = default;

   // build an index for this relation from raw unsorted data
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);
};

#endif // SIMD_RELATION_H_

