//Preprocessor.cpp

#include "Preprocessor.h"
#include <algorithm>
#include <iostream>
#include "varMap.h"
#include <set>
#include <ctime>
#include <cstdlib>

using std::set;

Preprocessor::Preprocessor() {}

Preprocessor::~Preprocessor() {}

void Preprocessor::preprocess(
	   vector<vector<int> >& input,
       vector<pair<int, int> >& counts,
       vector<int>& removedVars,
       int& maxNodeID)
{  
   vector<int> newRemovedVars; //set found in current it
   vector<int> currentRemovedVars; //set being removed in current it
   
   
   // int keyElement = 1;
    // std::srand(std::time(0));
   // keyElement = (std::rand() % (maxNodeID - 1)) + 1;
   // std::cout << "Key element is " << keyElement << std::endl;
   // //get rid of clauses not connected to key element
   // vector<int> deleteValues;
   // vector<bool> varPresence(maxNodeID+1, false);
   // for (int i = 0; i < input.size(); i++) {
      // bool flag = false;
      // for (int j = 0; j < input.at(i).size(); j++) {
         // if (std::abs(input.at(i).at(j)) == keyElement) {
            // for (int k = 0; k < input.at(i).size(); k++) {
               // varPresence[std::abs(input.at(i).at(k))] = true;
            // }
            // flag = true;
            // break;
         // }
      // }
      // if (flag == false) {
         // deleteValues.push_back(i);
      // }
   // }
   // std::cout << "stage 1 done" << std::endl;
   // for (int i = deleteValues.size() - 1; i >= 0; i--) {
      // bool flag = true;
      // for (int j = 0; j < input.at(deleteValues.at(i)).size(); j++) {
         // if (!varPresence[std::abs(input.at(deleteValues.at(i)).at(j))]) {
            // flag = false;
            // break;
         // }
      // }
      // if (flag) continue;
      // input.erase(input.begin() + deleteValues.at(i));
   // }
   // std::cout << "Input contains " << input.size() << " clauses." << std::endl;
   // for (int i = 0; i < input.size(); i++) {
      // for (int j = 0; j < input.at(i).size(); j++) {
         // std::cout << input[i][j] << ", ";
      // }
      // std::cout << std::endl;
   // }
   
   // //find vars not connected to key element
   // // vector<bool> varPresence(maxNodeID+1, false);
   // // for (int i = 0; i < input.size(); i++) {
      // // for (int j = 0; j < input.at(i).size(); j++) {
         // // varPresence[std::abs(input.at(i).at(j))] = true;
      // // }
   // // }
   // //formally mark for deletion
   // for (int i = 1; i <= maxNodeID; i++) {
      // if (!varPresence.at(i)) {
         // removedVars.push_back(i);
      // }
   // }
   // std::cout << "Prelude brings us to " << maxNodeID - removedVars.size() << " vars.\n";
   
   std::string presets = gvars.getStr(PREDEFS);
   if (presets != "") {
      int pointer = 0;
      for (;;) {
         int value = 0;
         while (pointer < presets.length() && 
               (presets.at(pointer) >= '0' && presets.at(pointer) <= '9'))
         {
            value = value * 10 + presets.at(pointer) - '0';
            pointer++;
         }
         if (pointer >= presets.length()) {
            break;
         }
         char sign = presets.at(pointer);
         if (sign != '+' && sign != '-') break;
         if (sign == '-') value *= -1;
         currentRemovedVars.push_back(value);
         removedVars.push_back(value);
         
         pointer++;
      }
   }
         
   
   do {
      newRemovedVars.clear();
      for (int i = 0; i < input.size(); i++) {

         for (int j = 0; j < input.at(i).size(); j++) {
            for (int l = 0; l !=currentRemovedVars.size(); l++) {
               if (std::abs(currentRemovedVars.at(l)) == std::abs(input.at(i).at(j))) { 
                  //if different sign, remove from the edge
                  if (currentRemovedVars.at(l) != input.at(i).at(j)) {
                     vector<int> inputTemp;
                     for (int k = 0; k < input.at(i).size(); k++) {
                        if (k!=j) {
                           inputTemp.push_back(input.at(i).at(k));
                        }
                     }
                     if (!inputTemp.size()) {
                        std::cout << "Input temp is empty; skipping." << std::endl;
                        break;
                     }
                     input.at(i) = inputTemp;
                     j--;
                     break; //restart j-loop on current index, essentially
                  }
                  else { //signs are same, so clause is already sat'd, so remove
                     input.at(i).clear();
                     break; //inner for loop no longer valid, but j-loop will exit safely.
                  }
               }
            }
         }

         if (input.at(i).size()==1) {
            if (std::find(newRemovedVars.begin(), newRemovedVars.end(), input.at(i).at(0)) == newRemovedVars.end()) {
               newRemovedVars.push_back(input.at(i).at(0));
            }
            input.at(i).clear();
         }
      }
      
      
      for (int i = 0; i < newRemovedVars.size(); i++) {
         removedVars.push_back(newRemovedVars.at(i));
      }
      currentRemovedVars = newRemovedVars;
      std::sort(removedVars.begin(), removedVars.end(), 
         [](int a, int b) {
            return std::abs(a) < std::abs(b);
         });
         
   } while (newRemovedVars.size()!=0);
   //sort input to get rid of 0-length
   std::sort(input.begin(), input.end(),
      [](vector<int> a, vector<int> b) {
         return a.size() > b.size();
      });
   
   while (input.back().size()==0) {
      input.pop_back();
   }
   
   std::sort(removedVars.begin(), removedVars.end(), 
      [](int a, int b) {
         return std::abs(a) < std::abs(b);
      });
   
   std::cout << "Counts.size(): " << counts.size();
   vector<pair<int, int> > newCounts;
   int loc = 0;
   if (removedVars.size() > 0) {
      for (int i = 0; i < counts.size(); i++) {
         if (counts.at(i).first == std::abs(removedVars.at(loc))) {
            loc++;
            if (loc == removedVars.size()) {
               i++;
               for (; i < counts.size(); i++) {
                  newCounts.push_back(counts.at(i));
               }
            }
         } else {
            newCounts.push_back(counts.at(i));
         }
      }
      counts = newCounts;

   }
         std::cout << "; Counts.size(): " << counts.size() << std::endl;

      std::cout << "Remapping..." << std::endl;
   //remap
   int destination = 0;
   int rvIndex = 0;
   vector<int> mapping(counts.size()+removedVars.size());
   for (int i = 0; i < mapping.size(); i++) {
      if (rvIndex < removedVars.size() && std::abs(removedVars.at(rvIndex)) == i) {
         mapping.at(i) = mapping.size()-1;
         rvIndex++;

      }
      else {
         mapping.at(i) = destination;
         destination++;
      }
   }
   for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.at(i).size(); j++) {
         if (input.at(i).at(j) > 0) {
            
            input.at(i).at(j) = mapping.at(input.at(i).at(j));
         }
         else {
            input.at(i).at(j) = -1 * mapping.at(-1*input.at(i).at(j));
         }
      }
   }

   //clean up maxNodeID
   maxNodeID-=removedVars.size();
         
   for (int i = 0; i < counts.size(); i++) {
      counts.at(i).first = mapping.at(counts.at(i).first);
   }
         
}