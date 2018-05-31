//PlaneTrie.cpp

#include "IntervalTrie.h"
#include "PlaneTrie.h"
#include <cmath>

PlaneTrie::PlaneTrie(int mD, int layers, int newLayer) {
   maxNodeID = mD;
   //wastes space, saves time...
   //maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   planes.resize(layers);
   myLayer = newLayer;
   for (int i = 0; i < layers; i++) {
      planes.at(i) = new IntervalTrie(mD);
      planes.at(i)->setMyLayer(myLayer + i);
   }
}

PlaneTrie::~PlaneTrie() {
   for (int i = 0; i < planes.size(); i++) {
      delete planes.at(i);
   }
}

bool PlaneTrie::contains(const vector<string>& box, vector<string>& output) {
 //  std::cout << "Entering contains" << std::endl;
   for (int i = 0; i < planes.size(); i++) {

      if (planes.at(i)->contains(box, output)) {
  //       std::cout << "leaving contains a winner at " << i << std::endl;
     //    std::cout << "Input " << box.at(i) << " contained by " << output.back() << std::endl;
    //     string temp;
    //     std::cin >> temp;
         return true;
      }
   }
 //     std::cout << "leaving contains a failure" << std::endl;

   return false;
}

bool PlaneTrie::insert(const vector<string>& box) {
 //  std::cout << "Entering insert" << std::endl;

   for (int i = 0; i < planes.size(); i++) {
      if (box.at(i)!="") {
         vector<string> subbox;
         subbox.push_back(box.at(i));
         return planes.at(i)->insert(subbox);
      }
   }
   //failed somehow
//   std::cout << "losing insert" << std::endl;
   return false;
}
