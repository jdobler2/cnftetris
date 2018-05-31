//PointerTrie.cpp

#include "PointerTrie.h"

PointerTrie::PointerTrie(const int mD, const int layers, const int newLayer, 
                        std::shared_ptr<GenericIntTrie> child) 
{
   maxNodeID = mD;
   //wastes space, saves time...
   //maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   layerCount = layers;
   myLayer = newLayer;
   tree = child;
}

PointerTrie::~PointerTrie() {
   //nothing to do
}

bool PointerTrie::contains(const vector<int>& box, vector<int>& output) {
 //  std::cout << "Entering contains" << std::endl;
  // vector<int> tempBox(2);
  // tempBox.at(0) = 0;
   for (int i = myLayer; i < layerCount; i++) {
      //tempBox.at(1) = box.at(i);
      tree->setMyLayer(i); //so that we use the right element of box, output
      if (tree->contains(box, output)) {
       //  if (i!=1) {
            //swap if necessary
     //       int temp = output.at(i);
    //        output.at(i) = output.at(1);
    //        output.at(1) = temp;
      //   }
         tree->setMyLayer(myLayer); //HAVE TO FIX BEFORE RETURNING!!!
         return true;
      }
   }

   //TODO: added boxes
   
   //failed to find
   tree->setMyLayer(myLayer); //HAVE TO FIX BEFORE RETURNING!!!
   return false;
}