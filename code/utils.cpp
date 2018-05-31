//utils.cpp
//created 7/28/2014 by jdobler

#include <vector>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "utils.h"

using std::vector;

bool Comparitor(int a, int b) { return a < b; } 

int main(int argc, char **argv) {
   vector<int> test;
   test.push_back(4);
   test.push_back(1);
   test.push_back(8);
   test.push_back(2);
   test.push_back(7);
   test.push_back(11);
   test.push_back(0);
   test.push_back(5);
   test.push_back(3);
   
  // parallelSort(test.begin(), test.end(), 8);
   bucketSort(test, test.size(), 4);

   for (int i = 0; i < test.size(); i++) {
      std::cout << test[i] << std::endl;
   }
   
   return 0;
}
