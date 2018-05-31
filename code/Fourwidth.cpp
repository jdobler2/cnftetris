//Treewidth.cpp

#include "Fourwidth.h"
#include <iostream>
#include <list>
#include <climits>

using std::string;
using std::vector;
using std::list;

Fourwidth::~Fourwidth() {
   //nothing to clean up
}

string Fourwidth::getType() const {
   return string("fourwidth");
}

void Fourwidth::buildDataListInner(list<fourwidthDatum>& data, 
                              vector<vector<int> >& adjMatrix, 
                              vector<vector<double> >& adjMatrixWeighted,
                              vector<std::pair<int, int> >& counts,
                              vector<int>& indexes) const
{
   
   //get interconnectedness
   double localConnections = 0;
   for (int i = 0; i < indexes.size(); i++) {
      for (int j = i + 1; j < indexes.size(); j++) {
         localConnections+= adjMatrixWeighted[indexes.at(i)][indexes.at(j)];
         // if (adjMatrix[i][j] > 0) localConnections++;
      }
   }

   //std::cout << "IC is " << localConnections << std::endl;
   
   //initial remaining neighbors is counts, minus any local connections
   vector<int> remNeighbors(indexes.size(), 0);
   for (int i = 0; i < indexes.size(); i++) {
      remNeighbors[i] = counts.at(indexes.at(i)).second;
      for (int j = 0; j < indexes.size(); j++) {
         if (i==j) {
            continue;
         }
         else if (adjMatrix[indexes.at(i)][indexes.at(j)] > 0) {
            remNeighbors[i]--;
         }
      }
   }
   
   //construct vector
   fourwidthDatum innerData;
   for (int i = 0; i < indexes.size(); i++) {
      innerData.v[i] = indexes.at(i);
      innerData.backtraces[i] = 0;
      innerData.remNeighbors[i] = remNeighbors[i];
   }
   innerData.interConnectedness = (double) localConnections;
   
   data.push_back(innerData);
                                 
}

//recursively build indicies set, then execute inner
void Fourwidth::buildDataList(list<fourwidthDatum>& data, 
                              vector<vector<int> >& adjMatrix, 
                              vector<vector<double> >& adjMatrixWeighted,
                              vector<std::pair<int, int> >& counts,
                              vector<int>& indicies,
                              int layerSize) const 
{
   int i = 0;
   if (indicies.size()) {
      i = indicies.back() + 1;
   }
   for (; i < counts.size() - (layerSize - 1 - indicies.size()); i++) {
      indicies.push_back(i);
      if (indicies.size() == layerSize) {
         buildDataListInner(data, adjMatrix, adjMatrixWeighted, counts, indicies);
      }
      else {
         if (indicies.size() == 1) {
            std::cout << "Outermost is at " << indicies.at(0) << std::endl;
         }
         buildDataList(data, adjMatrix, adjMatrixWeighted, counts, indicies, layerSize);
      }
      indicies.pop_back();
   }
      
}

vector<int> Fourwidth::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   vector<int> mappings(counts.size());
   
   //build adjacency matrix
   vector<vector<int> > adjMatrix;
   buildAdjacencyMatrix(adjMatrix, input, counts);
   vector<vector<double> > adjMatrix_weighted;
   buildAdjacencyMatrix_Weighted(adjMatrix_weighted, input, counts);
   std::cout << "Adj list constructed." << std::endl;
   //param list: v1, v2, v3, v4, interconnectedness [0-6], v1's backtraces, v1's remaining neighbors, then same for v2 through v4.
   list<fourwidthDatum> data;
   vector<int> indicies;
   buildDataList(data, adjMatrix, adjMatrix_weighted, counts, indicies, layerSize);
   
   std::cout << "Data constructed." << std::endl;
   vector<int> hasBeenPicked(counts.size(), 0);
   
   int i;
   for (i = 0; i < (mappings.size() / layerSize) - 1; i++) {
    //  std::cout << "Starting new loop." << std::endl;
      double maxIC = 0;
      int maxRemNeighbors = INT_MIN;
      int minPastNeighbors = INT_MAX;
      std::list<fourwidthDatum>::iterator loc;
      for (auto it = data.begin(); it != data.end(); it++) {
         double IC = (*it).interConnectedness;
         if (IC >= maxIC) {
            int newRemNeighbors = 0;
            int newPastNeighbors = 0;
            for (int i = 0; i < layerSize; i++) {
               newRemNeighbors += counts.at((*it).v[i]).second;
               //newRemNeighbors += (*it).remNeighbors[i];
               //newPastNeighbors += (*it).backtraces[i];
            }

            if (IC > maxIC ||
               (newPastNeighbors < minPastNeighbors) || 
                (newPastNeighbors <= minPastNeighbors && newRemNeighbors > maxRemNeighbors)
               )
            {
            // if (newPastNeighbors < minPastNeighbors ||
                // (*it).at(4) > maxIC)
            // {
               loc = it; 
               minPastNeighbors = newPastNeighbors;
               maxRemNeighbors = newRemNeighbors;
               maxIC = IC;

            }
         }
      }
      std::cout << "Assigning where IC is " << maxIC <<", minPastNeigh: " << minPastNeighbors << ", maxRemNeigh: " << maxRemNeighbors << std::endl;

     // std::cout << "Forloop cleared." << std::endl;

      vector<int> v(layerSize, 0);
      for (int j = 0; j < layerSize; j++) {
         v[j] = (*loc).v[j];
     //    std::cout << "V[j] is : " << v[j] << std::endl;
         hasBeenPicked.at(v[j]) = 1;
         mappings.at(v[j]) = i*layerSize + j + 1;
         //std::cout << "i: " << i << ", j: " << j << ", v[j]: " << v[j] << ", mapVal: " << mappings.at(v[j]) << std::endl;
      }      
            std::cout << "Points are " << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ", " << v[4] << "\n";

    //  std::cout << "About to erase." << std::endl;
      data.erase(loc);
      
      //update remNeighbors
      for (auto it = data.begin(); it!=data.end(); it++) {
loopStart:
         vector<int> values(layerSize, 0);
         for (int j = 0; j < layerSize; j++) {
            values[j] = (*it).v[j];
         }
         
         //check for overlap, remove if nec.
         for (int j = 0; j < layerSize; j++) {
            for (int k = 0; k < layerSize; k++) {
               if (values[j] == v[k]) {
                  auto temp = it;
                  it++;
                  data.erase(temp);
                  if (it==data.end()) {
                     goto loopEnd;
                  }
                  goto loopStart;
               }
            }
         }

//std::cout << "Going into updating data values." << std::endl;
         //update data values
         for (int j = 0; j < layerSize; j++) {
            for (int k = 0; k < layerSize; k++) {
               (*it).remNeighbors[j] -= adjMatrix[v[j]][values[k]];
               (*it).backtraces[j] += (adjMatrix[v[j]][values[k]] > 0 ? 1 : 0);
            }
         }
      }//end of update remNeighbors loop
loopEnd:
      ;
   }
   
   std::cout << "Most assignments complete" << std::endl;
   //assign remainder that didn't fit nicely into a 4-pack
   int k = 1;
   for (int j = 1; j < hasBeenPicked.size(); j++) {
      if (!hasBeenPicked[j]) {
         mappings.at(j) = i*layerSize + k;
         k++;
      }
   }
     std::cout << "All assignments complete." << std::endl; 
   return mappings;
}

//for compat reasons -- assume 4
vector<int> Fourwidth::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts) 
{
   return this->getOrdering(input, maxNodeID, counts, 4);
}