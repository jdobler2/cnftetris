// ============================================================================
// SimpleRelation.h
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - a simplest possible Relation implementation
// ============================================================================
#ifndef SIMPLE_RELATION_H_
#define SIMPLE_RELATION_H_

#include "Relation.h"

class SimpleRelation: public Relation 
{
   protected: 
   std::vector<std::pair<unsigned, std::vector<unsigned> > > pairs;

   /**
    * this is the basic gallopping algorithm:
    * it returns the smallest index s such that 
    *   s >= start AND v[s] >= t
    */
   virtual size_t leapfrog(size_t start, 
                           const std::vector<unsigned>& v,
                           unsigned t) const;

   public:
   SimpleRelation() {}
   ~SimpleRelation() {}

   const unsigned& getKey(size_t index) const { 
      return pairs[index].first; 
   }

   const std::vector<unsigned>&  getList(int index) const {
      return pairs[index].second;
   }

   const std::pair<unsigned, std::vector<unsigned> >& operator[](const int rhs) const {
      return pairs[rhs];
   }

   const std::pair<unsigned, std::vector<unsigned> >& at(int index) const {
      return pairs[index];
   }

   size_t size() const { 
      return pairs.size(); 
   }

   // build an index for this relation from raw unsorted data
   void buildIndex(std::vector<std::pair<unsigned, unsigned> >&);

   /**
    * count # of triangles using simple frogging algorithm
    */
   unsigned long performFroggerTricount(size_t start, size_t end);
};

#endif // SIMPLE_RELATION_H_
