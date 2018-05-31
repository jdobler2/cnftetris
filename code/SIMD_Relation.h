// ============================================================================
// SIMD_Relation.h
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - the SIMD_Relation classes
// ============================================================================
#ifndef SIMD_RELATION_H_
#define SIMD_RELATION_H_

#include "error_handling.h"
#include "BFSRelation.h"
#include <nmmintrin.h>
#include <emmintrin.h>       
        
class SIMD_BFSRelation: public Relation 
{
   protected:
      std::vector<std::pair<unsigned, std::vector<unsigned short> > > pairs;
      std::vector<std::vector<int> > leaps;

   public:

      const unsigned& getKey(size_t index) const {
         return pairs[index].first;
      }

      const std::vector<unsigned>& getList(int index) const;

      const std::pair<unsigned, std::vector<unsigned> >& 
         operator[](const int rhs) const;
      const std::pair<unsigned, std::vector<unsigned> >& at(int index) const;
      size_t size() const { return pairs.size(); }

      // build an index for this relation from raw unsorted data
      void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);

      // TODO: make this a separate class and be-friend it
      unsigned long performFroggerTricount(size_t start, size_t end) ;
      
      //handle conversion of data to SIMD format
      virtual void convertToSIMD(
         std::vector<
         std::pair<unsigned, std::vector<unsigned> > >& newPairs, size_t& i);
         
      //handle SIMD comparison of two sets of eight points
      virtual void execSIMDPoints(
         const size_t& i, const size_t& j, 
         const size_t& k, const size_t& l, unsigned long& c) const;
      
      //handle SIMD comparison of two sets of four ranges
      //(used in subclasses)
      virtual void execSIMDRanges(
         const size_t& i, const size_t& j, 
         const size_t& k, const size_t& l, unsigned long& c) const;
      
      //handle SIMD comparison of one set of four ranges 
      //                     and one set of eight points
      //(used in subclasses)
      virtual void execSIMDMixed(
         const size_t& i, const size_t& j, 
         const size_t& k, const size_t& l, unsigned long& c) const;
         
      //the set of ops methods for execSIMDRanges
      unsigned short op1(
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const;
      unsigned short op2(
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const;
      unsigned short op3(
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const;
      /* unsigned short op0(__m128i& v_a, 
                   const short unsigned* A, unsigned short& offset_a,
                   const short unsigned* B, unsigned short& offset_b,
                   const size_t& i) const; */
                   
      virtual void leapfrog(size_t& leapIndex, 
                            const vector<int>& leaps,
                            const vector<unsigned short>& pairs,
                            size_t& k, 
                            const unsigned short& target) const;
                   
      SIMD_BFSRelation() {
         print_warning("This relation requires SSE4.2.\n"
               "If your processor does not support this, the code may crash.");
      }
      ~SIMD_BFSRelation() {}
};

class SIMD_DegreeRelation: virtual public SIMD_BFSRelation 
{
   protected:
      double __degreeMultiplier;

   public:
      SIMD_DegreeRelation(double degreeMultiplier = 2) {
         __degreeMultiplier = degreeMultiplier;
      }
      ~SIMD_DegreeRelation() {}

      // build an index for this relation from raw unsorted data
      void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);

};


#endif // SIMD_RELATION_H_
