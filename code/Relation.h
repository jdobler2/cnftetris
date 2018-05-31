// ============================================================================
// Relation.h
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - the base Relation class
// ============================================================================
#ifndef RELATION_H_
#define RELATION_H_

#include <vector>
#include <stdlib.h>
#include <memory>
#include "utils.h"
#include "clause.h"

class Relation 
{
   protected:
      unsigned maxNodeID;
      static bool degreeComparitor(
             std::pair<unsigned, std::vector<unsigned> > a,
             std::pair<unsigned, std::vector<unsigned> > b);
      static bool reverseDegreeComparitor(
             std::pair<unsigned, std::vector<unsigned> > a,
             std::pair<unsigned, std::vector<unsigned> > b);

   public:
      Relation() : maxNodeID(0) {}
      virtual ~Relation() {}

      // returns the i'th vertex, TODO: necessary in all derived classes?
      virtual const unsigned& getKey(size_t i) const =0;

      // get the neighbor list of the i'th vertex
      virtual const std::vector<unsigned>& getList(int i) const =0;

      //perform the initial sort shared by all relations
      virtual void sortRawTuples(
         std::vector<std::pair<unsigned, unsigned> >& rawTuples,
         bool bothDirs);
         
      //build the basic pairs setup used by all relations
      virtual void fillPairs(
         const std::vector<std::pair<unsigned, unsigned> >& rawTuples,
         std::vector<std::pair<unsigned, std::vector<unsigned> > >& newPairs);
         
      virtual void buildMapping(
         std::vector<std::pair<unsigned, std::vector<unsigned> > >& newPairs,
         std::vector<unsigned>& queue,
         std::vector<int>& mapping,
         std::vector<int>& included,
         size_t& includedCounter,
         size_t& overflow_counter);
      
      // build an index for this relation from raw unsorted data
      virtual void buildIndex(std::vector<std::pair<unsigned, unsigned> >&) = 0;
      
      // build an index for CNF (SAT) problems
      virtual void buildIndexCNF(std::vector<std::vector<int> >& v, 
                                 int maxNodeID,
                                 std::vector<std::pair<int, int> >& counts)
      {
         std::cout << "Error: buildIndexCNF not enabled for this relation!"
                   << std::endl;
      }
      
      //build an index for MaxSAT (wcnf format) problems
      //@maxWeight the weight used as a stand-in for infinity, if any
      virtual void buildIndexMax(std::vector<clause>& v, 
                                 int maxNodeID,
                                 std::vector<std::pair<int, int> >& counts,
                                 int maxWeight)
      {
         std::cout << "Error: buildIndexMax not enabled for this relation!"
                   << std::endl;
      }
      
      // returns a pair (vertex, neighbor list) of the i'th vertex
      virtual const std::pair<unsigned, std::vector<unsigned> >& operator[](
            const int i) const =0;

      // same as []; TODO: supposed to throw an exception if index is off
      virtual const std::pair<unsigned, std::vector<unsigned> >& at(int index) const =0;

      // number of pairs stored
      virtual size_t size() const =0;

      // TODO: make this a class by itself, then allow friend access
      virtual unsigned long performFroggerTricount(size_t start, size_t end) = 0;

      virtual unsigned long performPreloadedTricount(
         size_t start, size_t end) 
      {
         std::cout << "ERROR: This relation does not have a preloaded version!"
                   << std::endl;
      } 
      virtual unsigned long performBuildCNFInput(
         size_t start, size_t end)
      {
         std::cout << "ERROR: This relation is not printable!"
                   << std::endl;
      }
      
      virtual unsigned long performMaxSATCount(
         size_t start, size_t end) 
      {
         std::cout << "ERROR: This relation does not have a maxsat version!"
                   << std::endl;
      } 
      
};

#endif // RELATION_H_
