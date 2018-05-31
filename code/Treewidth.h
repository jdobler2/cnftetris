//Treedwith.h

#ifndef TREEWIDTH_H_
#define TREEWIDTH_H_

#include "Orderer.h"

//Idea for this orderer is to find the treewise decomposition, 
//then use that to get the elimination order
class Treewidth : public Orderer {
  public: 
   virtual ~Treewidth();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts
      );
};
#endif //TREEWIDTH_H