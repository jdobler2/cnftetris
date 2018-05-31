//Fourwidth.h

#ifndef FOURWIDTH_H_
#define FOURWIDTH_H_

#include "Orderer.h"
#include <list>

//Idea for this orderer is to find a composition similar to the treewise
//that allows for us to take full advantage of the four-width nature of the Base121 system.

struct fourwidthDatum {
   int v[5];
   int backtraces[5];
   int remNeighbors[5];
   double interConnectedness;
};

class Fourwidth : public Orderer {

   void buildDataList(list<fourwidthDatum>& data, 
                              vector<vector<int> >& adjMatrix, 
                              vector<vector<double> >& adjMatrixWeighted,
                              vector<std::pair<int, int> >& counts,
                              vector<int>& indicies,
                              int layerSize) const;
   void buildDataListInner(list<fourwidthDatum>& data, 
                              vector<vector<int> >& adjMatrix, 
                              vector<vector<double> >& adjMatrixWeighted,
                              vector<std::pair<int, int> >& counts,
                              vector<int>& indexes) const;
  public: 
   virtual ~Fourwidth();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts
      );
      
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int layerSize
      );
};
#endif //TREEWIDTH_H