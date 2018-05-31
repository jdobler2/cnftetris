// LocksOrder.h

#ifndef LOCKS_ORDER_H_
#define LOCKS_ORDER_H_

#include "Orderer.h"

//Idea for this orderer is to simply order in terms of decreasing degree
class LocksOrder : public Orderer {
   int mAssignedAtEnd;
  public: 
   LocksOrder();
   virtual ~LocksOrder();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int layerSize
      );
   virtual int getExtra() const;
};
#endif //LOCKS_ORDER_H_