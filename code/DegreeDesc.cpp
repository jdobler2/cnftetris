//DegreeDesc.cpp

#include "DegreeDesc.h"
#include <iostream>
using std::string;
using std::vector;


DegreeDesc::~DegreeDesc() {
   //nothing to clean up
}

string DegreeDesc::getType() const {
   return string("degreeDesc");
}

vector<int> DegreeDesc::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   vector<int> mappings(counts.size());
   vector<vector<double> > adjMatrix;
   buildAdjacencyMatrix_Weighted(adjMatrix, input, counts);
   // std::cout << "Adjmatrix: \n";
   // for (int i = 0; i < adjMatrix.size(); i++) {
      // for (int j = 0; j < adjMatrix[i].size(); j++) {
         // std::cout << adjMatrix[i][j] << ", ";
      // }
      // std::cout << std::endl;
   // }
   // std::cout << std::endl;
   /*std::sort(++counts.begin(), counts.end(), 
      [](pair<int, int> a, pair<int, int> b) {
         return a.second > b.second;
      });*/
   int assignedCount = 1;
   for (int i = 2; i < counts.size(); i++) {
      double maxIC = -1.0;
      int maxCount = -1;
      int maxLocation = -1;
      for (int j = i; j < counts.size(); j++) {
         double newIC = 0.0;
         for (int k = 1; k <= assignedCount; k++) {
            newIC += adjMatrix[std::abs(counts.at(j).first)][std::abs(counts.at(i-k).first)];
         }
         int newCount = counts.at(j).second;
         if (newIC > maxIC || (newIC == maxIC && newCount > maxCount)) {
            maxIC = newIC;
            maxLocation = j;
            maxCount = newCount;
         }
      }
      counts.at(i).swap(counts.at(maxLocation));
      assignedCount++;
      assignedCount%=layerSize;
      if  (assignedCount == 0) {
      /*   std::cout << "Assigned group: ";
         for (int z = layerSize * -1 + 1; z <= 0; z++) {
            std::cout << counts.at(i + z).first << ", ";
         }
         std::cout << std::endl;*/
      }
      
      //exit if there's not more than a full set of 4 left
      if (assignedCount == 0 && (i + 1 + layerSize) >= counts.size()) break;
   }
            
   //invert the mapping
   for (int i = 1; i < counts.size(); i++) {
      mappings.at(counts.at(i).first) = i;
   }
   
   return mappings;
}