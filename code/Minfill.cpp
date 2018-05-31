//Minfill.cpp
//TODO: make weighted?

#include "Minfill.h"
#include <climits>

using std::string;
using std::vector;

Minfill::~Minfill() {
   //nothing to clean up
}

string Minfill::getType() const {
   return string("minfill");
}

void Minfill::fillCount(vector<vector<int> >& adjMatrix, 
                        vector<int>& fillCounts) const
{
   fillCounts.push_back(0);
   for (int i = 1; i < adjMatrix.size(); i++) {
      int curCount = 0;
      for (int j = 1; j < adjMatrix.at(i).size(); j++) {
         if (adjMatrix[i][j]) {
            for (int k = 1; k < adjMatrix.at(i).size(); k++) {
               if (k!=j && adjMatrix[i][k] && !adjMatrix[j][k]) {
                  curCount++;
               }
            }
         }
      }
      fillCounts.push_back(curCount);
   }
}

void Minfill::addFillEdges(vector<vector<int> >& adjMatrix, int removedNode, vector<int>& fillCounts) const
{
   for (int i = 1; i < adjMatrix.at(removedNode).size(); i++) {
      if (adjMatrix[removedNode][i]) {
         for (int j = 1; j < adjMatrix.at(removedNode).size(); j++) {
            if (j!=i && adjMatrix[removedNode][j] && !adjMatrix[i][j]) {
               //adjust fillCounts and add the edge [i][j].
               for (int k = 1; k < adjMatrix.at(removedNode).size(); k++) {
                  if (adjMatrix[k][j] && adjMatrix[k][i]) {
                     fillCounts.at(k)--;
                  }
                  else if (adjMatrix[k][j] || adjMatrix[k][i]) {
                     fillCounts.at(k)--;
                  }
               }
               adjMatrix[i][j] = 1;
               adjMatrix[j][i] = 1;
            }
         }
      }
   }
   
   for (int i = 1; i < adjMatrix.at(removedNode).size(); i++) {
      if (adjMatrix[removedNode][i]) {
         for (int j = 1; j < adjMatrix.at(removedNode).size(); j++) {
            if (j!=removedNode && adjMatrix[i][j]) {
               if (!adjMatrix[j][removedNode]) {
                  fillCounts.at(i)--;
               }
            }
         }
      }
   }   
}

vector<int> Minfill::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts) 
{
   vector<int> mappings(counts.size());
   
   //build adjacency matrix
   vector<vector<int> > adjMatrix;
   buildAdjacencyMatrix(adjMatrix, input, counts);
   
   vector<int> fillCounts;
   fillCount(adjMatrix, fillCounts);
   
   for (int i = mappings.size()-1; i >= 1; i--) {
   //for (int i = 1; i < mappings.size(); i++) {
      int location = 1;
      int minCount = fillCounts.at(1);
      
      //get min count
      for (int j = 2; j < fillCounts.size(); j++) {
         if (fillCounts.at(j) < minCount) {
            minCount = fillCounts.at(j);
            location = j;
         }
      }
      
      mappings[i] = location;
      
      addFillEdges(adjMatrix, location, fillCounts);
      //"delete" added vertex
      fillCounts.at(location) = INT_MAX;

   }
   
   return mappings;
}