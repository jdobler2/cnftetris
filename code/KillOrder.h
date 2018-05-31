// KillOrder.h

#ifndef KILL_ORDER_H
#define KILL_ORDER_H

#include "Orderer.h"

//Idea for this orderer is to try to kill off as many clauses as early as possible.
class KillOrder : public Orderer {
  public: 
   KillOrder();
   virtual ~KillOrder();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int layerSize
      );
};
#endif //KILL_ORDER_H