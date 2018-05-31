//IterTrieRelation.cpp

#include "IterTrieRelation.h"
#include <cmath>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "TrieActors.h"
#include <sys/time.h>
#include <fstream>
#include <iostream>

//pops the next @amount chars off the end of input
//(will pop everything if amount > size(input))
//@last: whether the last char popped was a 0 or a 1
void IterTrieRelation::popInput(vector<string>& input, int& amount, char& last,
                                int& indexUpper, int& indexLower) const
{
   for (; indexUpper >= 0; indexUpper--) {
      for (; indexLower >= 0; indexLower--) {     
         amount--;
         if (amount==0) {
            last = input.at(indexUpper).back();
            input.at(indexUpper).pop_back();
            indexLower--; //= input.at(indexUpper-1).size();
            return;
         }
         input.at(indexUpper).pop_back();
      }
      indexLower = input.at(indexUpper-1).size()-1;
      amount -= (maxDepth - indexLower - 1);
   }
}

//determines the amount of backtraces @output allows on @input.
int IterTrieRelation::determineShrinkage(vector<string>& input, 
                                         vector<string>& output) const
{
   //currently going to just assume output.size()==input.size()
   int retVal = 0;
   for (int i = input.size()-1; i >= 0; i--) {
      int val = input.at(i).size() - output.at(i).size();
      if (val > 0) {
         retVal += val;
      } else {
         break;
      }
      if (output.at(i).size()!=0) {
         break;
      }
   }
   return (retVal + 1);
}

void IterTrieRelation::setNext(vector<string>& input, char direction, 
                               int& indexUpper, int& indexLower) const
{
/*std::cout << "Input to SN: ";
for (int i = 0; i < input.size(); i++) {
   std::cout << input.at(i) << ", ";
}
std::cout << std::endl;*/
   if ((++indexLower)!=maxDepth) {
      input.at(indexUpper).push_back(direction);
   } 
   else {
      indexUpper++;
      indexLower=0;
      input.at(indexUpper).push_back(direction);
   }
/*std::cout << "Output to SN: ";
for (int i = 0; i < input.size(); i++) {
   std::cout << input.at(i) << ", ";
}
std::cout << std::endl;*/
}

void IterTrieRelation::popAndMerge(vector<string>& input, 
                               vector<string>& output,
                               vector<vector<string> >& pastS01s,
                               GenericTrie* cdb,
                               int& amount,
                               int& indexUpper,
                               int& indexLower) const
{
//   std::cout << "Entering popAndMerge with: " << amount << std::endl;
   char direction = '0';
   while (true) {
  /*    std::cout << "About to pop: ";
      for (int i = 0; i < input.size(); i++) {
         std::cout << input.at(i) << ", ";
      }
      std::cout << std::endl;*/

      popInput(input, amount, direction, indexUpper, indexLower);
      if (direction=='0') {
         //don't swap here!
    /*     std::cout << "Recording ";
         for (int i = 0; i < output.size(); i++) {
            std::cout << output.at(i) << ", ";
         }
         std::cout << "@" << indexUpper*maxDepth + indexLower+1 <<" and progressing" << std::endl;*/
         pastS01s.at(indexUpper*maxDepth + indexLower+1).swap(output);
         setNext(input, '1', indexUpper, indexLower);
         return;
      }
      else { //direction=='1'
      
         vector<string> input2;
         input2.swap(pastS01s.at(indexUpper*maxDepth + indexLower + 1));
         
    //START MERGE==============================================================
         amount = 1;
         //handle last layer first
         output.at(indexUpper).pop_back();
         
         //handle layers 0->next-to-last
         for (int i = 0; i < indexUpper; i++) {
            if (output.at(i).size() < input2.at(i).size()) {
               output.at(i).swap(input2.at(i));
            }
         }
         
         //if there's a layer skip, handle it
         if (indexLower == -1) {
            //if indexUpper==0, nothing else happens, we return with empty input
            //and @amount==0
            if (indexUpper==0) {
               //we're done
               return;
            }
            
            for (int i = indexUpper-1; i >= 0; i--) {
               int val = output.at(i).size();
               //amount += (maxDepth - val);
               int size = input.at(i).size();
               if (val==0) {
                  input.at(i).clear();
                  continue;
               }
               else {
                  //TODO: set direction here!
                  while (size-- > val) {
                     input.at(i).pop_back();
                  }
                  indexUpper = i;
                  indexLower = val - 1;
                  break;
               }
            } //end for(indexUpper)
            
            //insert if "good"
            if (output.front().size() < maxDepth) {
             //  cdb->insert(output);
            }
         } //end if(layer skip)
         //END MERGE==========================
      }//end else dir==1
   } //end while
 //  std::cout << "Leaving popAndMerge" << std::endl;
}

unsigned long IterTrieRelation::tetrisUnfolded(GenericTrie* cdb) const
{
   int indexUpper = 2;
   int indexLower = maxDepth - 1;
   
   struct timeval totalTime;
   
   totalTime.tv_sec = 0;
   totalTime.tv_usec = 0;
   
   std::fstream outputFile("outputNew.txt", std::ios::out | std::ios::app);
   bool performOutput = false;
   
   vector<string> input;
   vector<string> output;
   unsigned long count = 0;
   vector<vector<string> > pastSO1s; //<--functions essentially as a hash table
   pastSO1s.resize(maxDepth * _LAYERS);
   
   //set up the input so that it is at the first interesting point
   string temp;
   for (int i = 0; i < maxDepth; i++) {
      temp.push_back('0');
   }
   for (int i = 0; i < 3; i++) {
      input.push_back(temp);
   }
   
   int amount = 0;
   
   while(input.front().size()!=0) {

  /*    std::cout << "Current input: ";
      for (int i = 0; i < input.size(); i++) {
         std::cout << input.at(i) << ", ";
      }
      std::cout << std::endl;
      std::cout << "Indexes: " << indexUpper << "/" << indexLower << std::endl;*/
   //   std::cin >> temp;
   
      output.clear();
      output.resize(_LAYERS, "");
      
      if (input.back().size()==maxDepth) {//=== is a unit box
      
         if (cdb->contains(input, output)) {
            //std::cout << "We're all the way out" << std::endl;

         /*  std::cout << "Output is: ";
            for (int i = 0; i < output.size(); i++) {
               std::cout << output.at(i) << ", ";
            }
            std::cout << std::endl;*/
            
            amount = determineShrinkage(input, output);
            popAndMerge(input, output, pastSO1s, cdb, amount,
                        indexUpper, indexLower);
       //     std::cout << "Returned in Contains" << std::endl;
            continue;
         } //end: if contains
      
    //     struct timeval tv;
     //    gettimeofday(&tv, NULL);     // mark start time
         vector<vector<string> > allBoxes = getAllContainingBoxes(input);
     /*   struct timeval tv2;
         gettimeofday(&tv2, NULL);     // mark end time
         
         totalTime.tv_sec += tv2.tv_sec-tv.tv_sec;
         totalTime.tv_usec += tv2.tv_usec - tv.tv_usec;
         while (totalTime.tv_usec > 1000000) {
            totalTime.tv_sec += 1;
            totalTime.tv_usec -= 1000000;
         }*/
         
         if (allBoxes.size()==0) { //is an output point
            if (performOutput) {
               for (int x = 0; x < input.size(); x++) {
                  for (int i = 0; i < input.at(x).size(); i++) {
                     if (input.at(x).at(i)=='0') {
                        outputFile << -1 * (i + (x * maxDepth) + 1) << " ";
                     }
                     else {
                        outputFile <<  (i + (x * maxDepth) + 1) << " ";
                     }
                  }
               }
               outputFile << " 0\n";
            }
            count++;
            if (count%10000==0) {
               std::cout << "Count is: " << count << std::endl;
            }
            amount = 1;
       /*     std::cout << "Inserting: ";
            for (int i = 0; i < input.size(); i++) {
               std::cout << input.at(i) << ", ";
            }
            std::cout << std::endl;*/
            output = input; //note: MUST COPY
            popAndMerge(input, output, pastSO1s, cdb, amount,
                        indexUpper, indexLower);
 //           std::cout << "Returned in UB" << std::endl;
            continue; //restart loop
         }
         else { //negative witness found
         
            //insert all
            //NOTE: the guarantee that the best one is at 0 assured from GACB
            for (int i = 0; i < allBoxes.size(); i++) {
               cdb->insert(allBoxes.at(i));
            }
           // output = allBoxes.at(0);
    /*        std::cout << "Output is: ";
            for (int i = 0; i < output.size(); i++) {
               std::cout << output.at(i) << ", ";
            }
            std::cout << std::endl;*/
            
            amount = determineShrinkage(input, allBoxes.at(0));
            popAndMerge(input, allBoxes.at(0), pastSO1s, cdb, amount,
                        indexUpper, indexLower);
   //         std::cout << "Returned in NW" << std::endl;
            continue; //restart loop
         }
      } //end if unit box
      
      else {
         //progress downwards
         setNext(input, '0', indexUpper, indexLower);
  //       std::cout << "Advancing dumbly" << std::endl;
         continue;
      } //end else
   } //end while (nonempty input)
   
  /* std::cout << "seconds elapsed: " << double(totalTime.tv_sec) + 
            double(totalTime.tv_usec)/1000000 << std::endl;*/
   outputFile.close();
   return count;
}

//essentially Tetris-reloaded, done iteratively!
unsigned long IterTrieRelation::performFroggerTricount
   (size_t start, size_t end) 
{
   //std::cout << "Checkpoint 0!" << std::endl;   
   if (start!=0) return 0; //not gonna multithread here ftm.
      
   std::cout << "Checkpoint 1!" << std::endl;   
   
   unsigned long count = 0;
   ArrayTrie* cdb = new ArrayTrie();
   cdb->setMaxDepth(maxDepth);
   cdb->setMaxNodeID(maxNodeID);
   
   pair<int, vector<string> > result;
   result.first = false;
   vector<string> input;
   /*for (int i=0; i < 3; i++) {
      input.push_back("");
   }
   std::cout << "Checkpoint 2!" << std::endl;   

   result = tetris(input,cdb,count);*/
   count = tetrisUnfolded(cdb);
   std::cout << "Checkpoint 3!" << std::endl;   
   
   delete cdb;
   return count;
}
