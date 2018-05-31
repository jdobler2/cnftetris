//SIMD_HybridRelation.h

#ifndef SIMD_HYBRIDRELATION_H_
#define SIMD_HYBRIDRELATION_H_

#include "error_handling.h"
#include "SIMD_RLERelation.h"

class SIMD_HybridRelation: virtual public SIMD_RLERelation
{
   protected:
      std::vector<size_t> matchModes;
      
   public:
      SIMD_HybridRelation() = default;
      ~SIMD_HybridRelation() {}
      
      //build an index from raw unsorted data
      void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);

      //find number of triangles
      unsigned long performFroggerTricount(size_t start, size_t end);
      
};




#endif //SIMD_HYBRIDRELATION_H_