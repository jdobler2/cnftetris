//Orderer.cpp

#include "Orderer.h"
#include <iostream>

void Orderer::buildAdjacencyMatrix(vector<vector<int> >& adjMatrix, 
                                   vector<vector<int> >& input, 
                                   vector<std::pair<int, int> >& counts) const 
{
   adjMatrix.resize(counts.size());
   for (int i = 0; i < adjMatrix.size(); i++) {
      adjMatrix.at(i).resize(counts.size(), 0);
   }
   for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.at(i).size()-1; j++) {
         for (int k = j+1; k < input.at(i).size(); k++) {
            adjMatrix.at(std::abs(input.at(i).at(j)))
                     .at(std::abs(input.at(i).at(k)))
                        ++;
            adjMatrix.at(std::abs(input.at(i).at(k)))
                     .at(std::abs(input.at(i).at(j)))
                        ++;
         }
      }
   }
}

void Orderer::buildAdjacencyMatrix_Weighted(vector<vector<double> >& adjMatrix,
                             vector<vector<int> >& input,
                             vector<pair<int, int> >& counts) const 
{
   adjMatrix.resize(counts.size());
   for (int i = 0; i < adjMatrix.size(); i++) {
      adjMatrix.at(i).resize(counts.size(), 0.0);
   }
   for (int i = 0; i < input.size(); i++) {
      double newValue = 1 / ((double)input.at(i).size() - 1); //undefined behavior if /0, should be fine?
      for (int j = 0; j < input.at(i).size()-1; j++) {
         for (int k = j+1; k < input.at(i).size(); k++) {
            double oldValue = adjMatrix.at(std::abs(input[i][j])).at(std::abs(input[i][k]));
            if (newValue > oldValue) {
               adjMatrix.at(std::abs(input.at(i).at(j)))
                        .at(std::abs(input.at(i).at(k)))
                           = newValue;
               adjMatrix.at(std::abs(input.at(i).at(k)))
                        .at(std::abs(input.at(i).at(j)))
                           = newValue;
            }
         }
      }
   }
}

//by default, simply return the version without the layers value
//note that, if neither is defined by a subclass, we have an infinite loop.
std::vector<int> Orderer::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      std::vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   return this->getOrdering(input, maxNodeID, counts);
}

//by default, assume a layerSize of 4
std::vector<int> Orderer::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      std::vector<std::pair<int, int> >& counts) 
{
   return this->getOrdering(input, maxNodeID, counts, 4);
}