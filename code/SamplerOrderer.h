#ifndef SAMPLER_ORDERER_H_
#define SAMPLER_ORDERER_H_

#include "Orderer.h"

//Here, we'll use sampling to try to determine the best ordering.
class SamplerOrderer : public Orderer {
  public: 
   virtual ~SamplerOrderer();
   virtual std::string getType() const;
   virtual std::vector<int> getOrdering(
         std::vector<std::vector<int> >& input,
         int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int layerSize
      );
   virtual void findBestFromBothMappings(
         const std::vector<std::vector<int> >& maps,
         const std::vector<std::vector<int> >& input,
         const int blockSize, const int maxNodeID,
         std::vector<std::pair<int, int> >& counts,
         int end,
         vector<int>& output
      ) const;
         
};
#endif //SAMPLER_ORDERER_H_