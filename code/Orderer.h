#ifndef ORDERER_H_
#define ORDERER_H_

#include <vector>
#include <string>
#include <stdlib.h>
#include <utility>
#include <algorithm>

using namespace std;

class Orderer {
  public: 
   virtual ~Orderer() {}
   virtual std::string getType() const = 0;
   virtual void buildAdjacencyMatrix(std::vector<std::vector<int> >& adjMatrix, 
                             std::vector<std::vector<int> >& input, 
                             std::vector<std::pair<int, int> >& counts) const;
   virtual void buildAdjacencyMatrix_Weighted(std::vector<std::vector<double> >& adjMatrix,
                             std::vector<std::vector<int> >& input,
                             std::vector<std::pair<int, int> >& counts) const;
                             
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
      
   virtual int getExtra() const {
      return 0;
   }
};

class Naive : public Orderer {
   public:
   Naive() {}
   std::string getType() const {return std::string("Naive");}
   ~Naive() {}
   std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts
      )
   {
      vector<int> mappings(counts.size());
      for (int i = 1; i < counts.size(); i++) {
         mappings.at(counts.at(i).first) = i;
      }
      return mappings;
   }
};
#endif //ORDERER_H_