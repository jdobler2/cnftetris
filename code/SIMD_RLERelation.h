//SIMD_RLERelation.h

#ifndef SIMD_RLERELATION_H_
#define SIMD_RLERELATION_H_

#include "error_handling.h"
#include "SIMD_Relation.h"

class SIMD_RLERelation: virtual public SIMD_BFSRelation
{
   public:
      SIMD_RLERelation();
      ~SIMD_RLERelation() {}
      
      //do all the work of getting the pairs ordered properly
      virtual void orderPairs(
         std::vector<std::pair<unsigned, std::vector<unsigned> > >& tempPairs);
      
      //convert to SIMD ranges
      virtual void convertToSIMDRanges(
         std::vector<std::pair<unsigned, std::vector<unsigned> > >& tempPairs, size_t& i);
      
      //build an index from raw unsorted data
      void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);

      //find number of triangles
      unsigned long performFroggerTricount(size_t start, size_t end);
      
};
#endif // SIMD_RLERELATION_H_
