#ifndef DEG_DESC_H_
#define DEG_DESC_H_

#include "Orderer.h"

//Idea for this orderer is to simply order in terms of decreasing degree
class DegreeDesc : public Orderer {
  public: 
   virtual ~DegreeDesc();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int layerSize
      );
};
#endif //DEG_DESC_H_