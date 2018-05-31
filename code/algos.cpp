// ============================================================================
// algos.cpp
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - basic counting algorithms
// ============================================================================

#include <stdexcept>
#include <iostream>
#include <vector>
#include "term_control.h"
#include "error_handling.h"
#include "algos.h"

unsigned long froggerTricount(Relation& edges, size_t start, size_t end)
{
	return edges.performFroggerTricount(start, end);
}

unsigned long basicMSTricount(
        Relation& edges, 
        size_t start, 
        size_t end)
{
    throw std::runtime_error("basic MS: TBD");
    return 0;
}

unsigned long advancedMSTricount(
        Relation& edges, 
        size_t start, 
        size_t end)
{
    throw std::runtime_error("advanced MS: TBD");
    return 0;
}

unsigned long dyadicMSTricount(Relation& edges, size_t start, size_t end)
{
    throw std::runtime_error("dyadic MS: TBD");
    return 0;
}

unsigned long preloadedTricount(
         Relation& edges, 
         size_t start, size_t end) 
{
   return edges.performPreloadedTricount(start, end);
}

unsigned long maxSATCount(
         Relation& edges, 
         size_t start, size_t end) 
{
   return edges.performMaxSATCount(start, end);
}
