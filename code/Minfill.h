//Minfill.h

#ifndef MINFILL_H_
#define MINFILL_H_

#include "Orderer.h"
#include <list>


class Minfill : public Orderer {

  public: 
   virtual ~Minfill();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts
      );
      
   void fillCount(std::vector<std::vector<int> >& adjMatrix, 
                        std::vector<int>& fillCounts) const;
                        
   void addFillEdges(vector<vector<int> >& adjMatrix, int removedNode, vector<int>& fillCounts) const;

};
#endif //MINFILL_H