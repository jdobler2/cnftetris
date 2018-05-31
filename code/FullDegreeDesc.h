//FullDegreeDesc.h

#ifndef FULL_DEG_DESC_H_
#define FULL_DEG_DESC_H_

#include "Orderer.h"

//Idea for this orderer is to simply order in terms of decreasing degree
class FullDegreeDesc : public Orderer {
  public: 
   virtual ~FullDegreeDesc();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts
      );
};
#endif //FULL_DEG_DESC_H_