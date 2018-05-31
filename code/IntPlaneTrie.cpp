//IntPlaneTrie.cpp

#include "IntPlaneTrie.h"

IntPlaneTrie::IntPlaneTrie(int mD, int layers, int newLayer) {
   maxNodeID = mD;
   //wastes space, saves time...
   //maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   planes.resize(layers);
   myLayer = newLayer;
   for (int i = 0; i < layers; i++) {
      planes.at(i) = new FixedIITrie(mD);
      planes.at(i)->setMyLayer(myLayer + i);
   }
}

IntPlaneTrie::~IntPlaneTrie() {
   for (int i = 0; i < planes.size(); i++) {
      delete planes.at(i);
   }
}

bool IntPlaneTrie::contains(const vector<int>& box, vector<int>& output) {
 //  std::cout << "Entering contains" << std::endl;
   for (int i = 0; i < planes.size(); i++) {

      if (planes.at(i)->contains(box, output)) {
         return true;
      }
   }

   //failed to find
   return false;
}

int IntPlaneTrie::insert(const vector<int>& box) {
 //  std::cout << "Entering insert" << std::endl;

   for (int i = 0; i < planes.size(); i++) {
      if (box.at(i + myLayer)!=1) {
         return planes.at(i)->insert(box);
      }
   }
   //failed somehow
//   std::cout << "losing insert" << std::endl;
   return false;
}

bool IntPlaneTrie::insertPair(
   const pair<dataLayerPair, dataLayerPair>& box) 
{
   return planes.at(box.second.layer - myLayer)->insertPair(box);
}
