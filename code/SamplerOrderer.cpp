//SamplerOrderer.cpp

#include "SamplerOrderer.h"
#include "Base243TrieRelation.h"
#include <iostream>
using std::string;
using std::vector;

SamplerOrderer::~SamplerOrderer() {
   //nothing to clean up
}

string SamplerOrderer::getType() const {
   return string("samplerOrderer");
}

vector<int> SamplerOrderer::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int layerSize) 
{
   vector<int> mappings(counts.size());
   vector<pair<int, int> > randMappings(counts.size());
   vector<vector<double> > adjMatrix;
   buildAdjacencyMatrix_Weighted(adjMatrix, input, counts);
   
   //First, we're going to use DegreeDesc's method as a baseline.
   int assignedCount = 1;
   for (int i = 2; i < counts.size(); i++) {
      double maxIC = -1.0;
      int maxCount = -1;
      int maxLocation = -1;
      for (int j = i + 1; j < counts.size(); j++) {
         double newIC = 0.0;
         for (int k = 1; k <= assignedCount; k++) {
            newIC += adjMatrix[std::abs(counts.at(j).first)][std::abs(counts.at(i-k).first)];
         }
         int newCount = counts.at(j).second;
         if (newIC > maxIC || newIC == maxIC && newCount > maxCount) {
            maxIC = newIC;
            maxLocation = j;
            maxCount = newCount;
         }
      }
      counts.at(i).swap(counts.at(maxLocation));
      assignedCount++;
      assignedCount%=layerSize;
      if  (assignedCount == 0) {
         std::cout << "Assigned group: ";
         for (int z = layerSize * -1 + 1; z <= 0; z++) {
            std::cout << counts.at(i + z).first << ", ";
         }
         std::cout << std::endl;
      }
      
      //exit if there's not more than a full set of 4 left
      if (assignedCount == 0 && (i + 1 + layerSize) >= counts.size()) break;
   }
            
   //invert the mapping
   for (int i = 1; i < counts.size(); i++) {
      mappings.at(counts.at(i).first) = i;
   }
   std::cout << "Building random mapping..." << std::endl;
   //Next, build random mappings.
   for (int i = 0; i < randMappings.size(); i++) {
      randMappings[i].first = mappings.at(i);
      randMappings[i].second = rand();
   }
   std::sort(randMappings.begin()+1, randMappings.end(), 
      [](pair<int, int> a, pair<int, int> b) {
         return a.second > b.second;
      });
   //Now run algo on some subset of RNG and normal, get times, put fastest at end, and repeat.
   
   vector<int> rMappings2(randMappings.size());
   for (int i = 0; i < randMappings.size(); i++) {
      rMappings2[i] = randMappings.at(i).first;
   }
   
   
   vector<int> lastSet;
   vector<vector<int> > mappingSet;
   mappingSet.push_back(mappings); mappingSet.push_back(rMappings2);
   
   findBestFromBothMappings(mappingSet, input, 10, maxNodeID, counts, maxNodeID+1, lastSet);
   
   //TODO: Handle lastSet, and recurse.
   
   std::cout << "\t\tSampler runs complete." << std::endl;
   return mappings;
}

void SamplerOrderer::findBestFromBothMappings(
      const std::vector<std::vector<int> >& maps,
      const std::vector<std::vector<int> >& input,
      const int blockSize, const int maxNodeID,
      vector<std::pair<int, int> >& counts,
      int end,
      vector<int>& output
   ) const
{
   vector<pair<vector<int>, double> > outputSets;

   for (int mm = 0; mm < maps.size(); mm++) {
      for (int z = 1; z < end; z+=blockSize) {
         vector<vector<int> > candidateInput;
         for (int i = 0; i < input.size(); i++) {
            vector<int> inVector;
            for (int j = 0; j < input.at(i).size(); j++) {
               int currVal = input.at(i).at(j);
               int mapsValue = maps.at(mm).at(std::abs(currVal)); 
               if (currVal < 0) {
                  if ((z <= mapsValue) && 
                       z+blockSize > mapsValue)
                  {
                     inVector.push_back(-1*(mapsValue - z + 1));
                  }
               }
               else {
                  if ((z <= mapsValue) && (z+blockSize > mapsValue)) {
                     inVector.push_back((mapsValue - z) + 1);
                  }
               }
            }
            if (inVector.size() > 0) {
               // std::cout << "inVector is: ";
               // for ( int x = 0; x < inVector.size(); x++) {
                  // std::cout << inVector.at(x) << ", ";
               // }
               // std::cout << std::endl;
               candidateInput.push_back(inVector);
            }
         }//candidate input assembled
         Base243TrieRelation childRel;
         std::string naive("naive");
         childRel.setOrdering(naive);
         
         std::cout << "\n\n\t\t\tFiring " << mm << "." << z << ".\n";
         struct timeval tv;
         gettimeofday(&tv, NULL);     // mark start time
         
         //childRel->buildIndexCNF(candidateInput, maxNodeID, counts); //adjust things to use blockSize instead of maxNoteID?
         childRel.unsafeBuild(candidateInput, blockSize);
         childRel.performFroggerTricount(0, candidateInput.size());
         
         struct timeval tv2;          // mark finish time
         gettimeofday(&tv2, NULL);

         std::cout << "\t\t\tFinished: " << mm << "." << z << " in " << double(tv2.tv_sec - tv.tv_sec) + 
         double(tv2.tv_usec - tv.tv_usec)/1000000 << ".\n";

         vector<int> mappedVars;
         for (int i = 1; i < end; i++) {
            if (maps[mm][i] >= z && maps[mm][i] < z+blockSize) {
               mappedVars.push_back(i);
            }
         }
         outputSets.push_back(make_pair(mappedVars, double(tv2.tv_usec - tv.tv_usec)/1000000));
        
      }
   }
   
   std::sort(outputSets.begin(), outputSets.end(), [](pair<vector<int>, double> a, pair<vector<int>, double> b) {
      return a.second < b.second;
   });
   
   
   
}