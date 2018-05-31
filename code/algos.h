// ============================================================================
// algos.h
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// - functions that call various algorithms for triangle counting
// ============================================================================
#ifndef ALGOS_H_
#define ALGOS_H_

#include <vector>
#include "Relation.h"

/**
 * pointer to a function that does the counting strategy
 */
typedef unsigned long (*tricount_strategy_t)(Relation&, size_t, size_t);

/**
 * This implements the Leapfrog Triejoin strategy for counting
 * the number of triangles.
 * - the input is an edge set, where (u,v) in rel only when u<=v
 * - 0 <= start < end <= rel.size() is a subrange [start, end), 
 *   indicating a subset of vertices we are computing the # triangles on
 *   this is to facilitate the multithreading version later
 */
unsigned long froggerTricount(Relation& rel, size_t start, size_t end);

/**
 * This implements the basic Minesweeper strategy for counting
 * the number of triangles.
 */
unsigned long basicMSTricount(Relation&, size_t, size_t);

/**
 * This implements an advanced Minesweeper strategy for counting
 * the number of triangles. It inserts intervals it discovers into
 * the top of the CDS too, because all three relations are the same
 */
unsigned long advancedMSTricount(Relation&, size_t, size_t);

/**
 * This implements the dyadic-based counting strategy in PODS'14 paper
 */
unsigned long dyadicMSTricount(Relation&, size_t, size_t);

/**
 * This implements a preloaded version of an algorithm, where applicable
 */
 
 unsigned long preloadedTricount(Relation&, size_t, size_t);
 
 /**
  * This executes the solver on a maxSAT problem instance
  */
  
 unsigned long maxSATCount(Relation&, size_t start, size_t end);

#endif // ALGOS_H_
