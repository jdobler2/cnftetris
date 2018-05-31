//IntTrieRelation.cpp

#include "IntTrieRelation.h"
#include <cmath>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "TrieActors.h"

using std::vector;
using std::multiset;

//=======begin getAllWordsActor================================================
void IntTrieRelation::int_getAllWordsActor::if_interval
      (IntIntervalTrie* intTrie) 
{   
   container.push_back(intTrie->getIntervals());
}
//=======end getAllWordsActor==================================================

//=======begin mlMergerActor===================================================
IntTrieRelation::int_mlMergerActor::int_mlMergerActor(GenericIntTrie* tr) {
      t = tr;
}   

IntTrieRelation::int_mlMergerActor::~int_mlMergerActor() {
}

void IntTrieRelation::int_mlMergerActor::setTrie(GenericIntTrie* tr) {
   t = tr;
}

void IntTrieRelation::int_mlMergerActor::if_array_after_children
      (IntArrayTrie* at, int index) 
{
   if (index < 32) {
      std::cout << "At index: " << index << std::endl;
   }
   if ( (index*2+1 < at->bits.size()) &&
         (at->bits[index*2]==1) && (at->bits[index*2+1]==1) ) 
   {
      //std::cout << "Attempting merge at: " << currentWord[0] << std::endl;

      //setting up gawaL, gawaR
      IntTrieRelation::int_getAllWordsActor* gawaL = 
            new IntTrieRelation::int_getAllWordsActor();
      
      IntTrieRelation::int_getAllWordsActor* gawaR = 
            new IntTrieRelation::int_getAllWordsActor();
      
      if (at->branches[index*2]!=NULL) {
         at->branches[index*2]->apply(gawaL);
      }
      else if (at->wordBits[index*2]==1) {
         set<size_t> tempInts;
         tempInts.insert(0);
         tempInts.insert((1 << (maxDepth + 1)) - 1);
         gawaL->container.push_back(tempInts);
      }
      else {
         delete gawaL;
         delete gawaR;
         return;
      }
      
      if (at->branches[index*2+1]!=NULL) {
         at->branches[index*2+1]->apply(gawaR);
      }
      else if (at->wordBits[index*2+1]==1) {
         set<size_t> tempInts;
         tempInts.insert(0);
    //CHECK: This line.
         tempInts.insert((1 << (maxDepth + 1)) - 1);
         gawaR->container.push_back(tempInts);
      }
      else {
         delete gawaL;
         delete gawaR;
         return;
      }
      
      //assert: gawaL, gawaR set up
      
      for (int i = 0; i < gawaL->container.size(); i++) {
         if (gawaL->container.size()!=1) {
            std::cout << "ERROR: gawaL too big" << std::endl;
         }
         set<size_t> leftIntervals = gawaL->container[0];
         set<size_t> rightIntervals = gawaR->container[0];
       
         multiset<size_t> combinedIntervals;
         
         //throw everything together
         for (set<size_t>::iterator it = leftIntervals.begin(); 
               it != leftIntervals.end(); it++)
         {
            combinedIntervals.insert(*it);
         }
         for (set<size_t>::iterator it = rightIntervals.begin();
               it != rightIntervals.end(); it++)
         {
            combinedIntervals.insert(*it);
         }
         
         //adjust combined intervals so that the result is correct
         int currentlyOnLeft = 0;
         set<size_t> finishedIntervals;
         for (multiset<size_t>::iterator it = combinedIntervals.begin();
               it != combinedIntervals.end(); it++) 
         {
            if (*it%2==0) { //if left
               currentlyOnLeft++;
               if (currentlyOnLeft==2) {
                  finishedIntervals.insert(*it);
               }
               else if (currentlyOnLeft > 2) {
                  std::cout << "da fuq" << std::endl;
               }
            } else { //is right
               if (currentlyOnLeft==2) {
                  finishedIntervals.insert(*it);
               }
               currentlyOnLeft--;
            }
         }
         
        // std::cout << "FinishedIntervals.size()" << finishedIntervals.size() << std::endl;
         if (finishedIntervals.size()==0) {
            //nothing to add, so break
            delete gawaL;
            delete gawaR;
            return;
         }
         
         IntIntervalTrie* intTrie = new IntIntervalTrie(maxNodeID);
         intTrie->setIntervals(finishedIntervals);
         intTrie->setMyLayer(1);
         
         if (at->branches[index]!=NULL) {
            std::cout << "branches already exists?" << std::endl;
            at->branches.at(index).reset();
         }
         at->branches[index].reset(intTrie);
         
         //delete from children
         for (set<size_t>::iterator it = finishedIntervals.begin();
               it!=finishedIntervals.end(); it++)
         {
            size_t left = *it;
            it++;
            size_t right = *it;
            if (at->branches[index*2]!=NULL) {
               at->branches[index*2]->remove_for_size(left, right);
               if (at->branches[index*2]->size()==0) {
                  at->branches.at(index*2).reset();
               }
            }
            if (at->branches[index*2+1]!=NULL) {
               at->branches[index*2+1]->remove_for_size(left, right);
               if (at->branches[index*2+1]->size()==0) {
                  at->branches.at(index*2+1).reset();
               }
            }
         }//end for (delete from children)
         
      }//end if anything to merge (for loop)
      delete gawaL;
      delete gawaR;
   } // end if 
}

//=======end mlMergerActor=====================================================

int IntTrieRelation::getLocInTrie(unsigned value, int maxDepth) {
   //int shift = (1 << maxDepth) - 1;
   return value + shift;
}

unsigned long IntTrieRelation::tetris(GenericIntTrie* cdb) {
   int index = _LAYERS - 1;
   
   vector<int> input;
   vector<int> output;
   output.resize(_LAYERS, 1); //E cheaper way

   unsigned long count = 0;
   
   //initialize pastSO1s
   vector<vector<int> > pastSO1s; //<--functions essentially as a hash table
   pastSO1s.resize(maxDepth * _LAYERS);
   for (int i = 0; i < pastSO1s.size(); i++) {
      pastSO1s.at(i).resize(_LAYERS, 1);
   }
      
   //set up the input so that it is at the first interesting point
   for (int i = 0; i < _LAYERS; i++) {
      input.push_back(shift);
   }
      
   while(input.front() > 1) {
      if (input.back() >= shift) {//=== is a unit box
     //    std::cout << "About to call contains" << std::endl;
         if (cdb->contains(input, output)) {
      //      std::cout << "Contains gave true" << std::endl;
           /* std::cout << "Input: " << std::endl;
            for (int i = 0; i < input.size(); i++) {
               std::cout << input.at(i) << ", ";
            }
            std::cout << std::endl;
            std::cout << "Output: " << std::endl;
            for (int i = 0; i < output.size(); i++) {
               std::cout << output.at(i) << ", ";
            }
            std::cout << std::endl;
            string alwgj;
            std::cin >> alwgj; */
            performShrinkage(input, output, index);
            popAndMerge(input, output, pastSO1s, cdb, index);
            
            for (int i = 0; i < _LAYERS; i++) {
               output.at(i) = 1;
            }
            continue;
         }
       //  std::cout << "Contains gave false." << std::endl;
         vector<pair<dataLayerPair, dataLayerPair> > allBoxes;
         getAllContainingBoxes(input, allBoxes);
         if (allBoxes.size()==0) { //is an output point
            count++;
            if (count%10000==0) {
               std::cout << "Count is: " << count << std::endl;
            }
            //return count;
            output = input; //note: MUST COPY
            popAndMerge(input, output, pastSO1s, cdb, index);
 //           std::cout << "Returned in UB" << std::endl;
            for (int i = 0; i < _LAYERS; i++) {
               output.at(i) = 1;
            }
            continue; //restart loop
         }
         
         else { //negative witness found
            for (int i = 0; i < allBoxes.size(); i++) {
               cdb->insertPair(allBoxes.at(i));
            }
            
            //TODO: this is a temp solution
            vector<int> tempBox;
            tempBox.resize(_LAYERS, 1);
            tempBox.at(allBoxes.at(0).first.layer) = allBoxes.at(0).first.data;
            tempBox.at(allBoxes.at(0).second.layer) = allBoxes.at(0).second.data;
            
            performShrinkage(input, tempBox, index);
            popAndMerge(input, tempBox, pastSO1s, cdb, index);
   //         std::cout << "Returned in NW" << std::endl;
            continue; //restart loop
         }
      } //end if unit box
   
      else {
         //progress downwards
         fillZero(input, index);
         continue;
      } //end else
   
   } //end while
   
   return count;
}

//TODO: PARALLELIZE THIS!!!
void IntTrieRelation::getAllContainingBoxes(
      vector<int>& input, 
      vector<pair<dataLayerPair, dataLayerPair> >& output
      /*vector<int>& pattern*/) const 
{
   vector<int> testBox;
   testBox.resize(2, 1);
   vector<int> prevWord;
   
   //Pattern's not actually used yet, but implementing it from here's simple
   for (int x = 0; x < input.size(); x++) {
      for (int y = x + 1; y < input.size(); y++) {
         testBox.at(0) = input.at(x);
         testBox.at(1) = input.at(y);
   
         tree->getAllContainingBoxes(testBox, output, prevWord);
   
         for (int i = 0; i < output.size(); i++) {
            output.at(i).first.layer = x;
            output.at(i).second.layer = y;
         }
         if (output.size() > 0) return; //goto skip; //semantically, break outer
      }
      
   }
   
   //skip:
   /* TODO: Rewrite this!
   //simpler alternative for determining opt.
   //It's slightly slower, but it's also actually scalable:
   for (int i = 1; i < output.size(); i++) {
      for (int j = 2; j >= 0; j--) { //<- for generic, change init here
         int a = output.front().at(j);
         int b = output.at(i).at(j);
         if (a < b) { //current is smaller
            break;
         }
         else if (a > b) { //newcomer is smaller
            output.front().swap(output.at(i));
            break;
         }
         else { //equivalent
            //check next layer
            continue;
         }
      } //end inner for
   }//end outer for   
   */
}

//pops the next @amount layers off of input
//(udef behavior if amount > size(input))
//@last: whether the last val popped was a 0 or a 1
void IntTrieRelation::popInput(vector<int>& input, 
               int& amount, int& last, int& index) const
{
   for (; index >= 0; index--) {
      while (input.at(index) > 1) {     
         amount--;
         if (amount==0) {
            last = (input.at(index)) % 2;
            input.at(index) >>= 1;
            return;
         }
         input.at(index) >>=1;
      }
      int duplicate = input.at(index-1);
      //TODO: speed this up
      while (duplicate < shift) {
         amount--;
         duplicate = 2 * duplicate;
      }
   }
}

//because it turns out I'm always popping one, here's a simpler version
void IntTrieRelation::popOne(vector<int>& input, int& last, int& index) {
   while (input.at(index) <= 0) index--;
   last = (input.at(index)) % 2;
   input.at(index) >>=1;
   return;
}

void IntTrieRelation::popOne(vector<int>& input, int& index) {
   while (input.at(index) <= 0) index--;   
   input.at(index) >>=1;
   return;
}

//determines the amount of backtraces @output allows on @input.
int IntTrieRelation::performShrinkage(vector<int>& input, 
                                       vector<int>& output,
                                       int& index)
{
  /*  std::cout << "Shrinking: input: \n";
   for ( int i = 0; i < input.size(); i++) {
      std::cout << input.at(i) << ", ";
   }
   std::cout << std::endl << "With output: \n";
   for ( int i = 0; i < output.size(); i++) {
      std::cout << output.at(i) << ", ";
   }
   std::cout << "\n";*/
   for (; index >= 0; index--) {
      input.at(index) = output.at(index);
      if (output.at(index)>1) {
         break;
      }
   }
   return 1;
}

void IntTrieRelation::setNext(vector<int>& input, int val, int& index) {
   if (input.at(index) < shift) {
      input.at(index) = input.at(index) * 2 + val;
   }
   else {
      input.at(++index) = val + 2;
   }
}

//takes the left branch until this leads to a unit box
void IntTrieRelation::fillZero(vector<int>& input, int& index) {
   while (input.at(index) < shift) {
      input.at(index) = input.at(index) * 2;
   }
   while (index < input.size() - 1) {
      input.at(++index) = shift;
   }
}

int IntTrieRelation::highestSetBit(int val) const {
   float d_val = (float) val; //& operator needs lvalue
   return (((*(int *) &d_val) & 0x7F800000) >> 23) - 128; //Grab the exponent
}

void IntTrieRelation::popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index)
{
   int direction = 0;
   while(true) {
      popOne(input, direction, index);
      if (direction==0) {
         int indexLower = highestSetBit(input.at(index));
   //      std::cout << "il: " << indexLower << std::endl;
         pastS01s.at(index*maxDepth + indexLower+1).swap(output);
         setNext(input, 1, index);
         return;
      }
      else { //dir==1
         vector<int> input2;
         input2.resize(_LAYERS, 1);
         int indexLower = highestSetBit(input.at(index));
         input2.swap(pastS01s.at(index*maxDepth + indexLower + 1));
         
         //handle last layer
         output.at(index) >>= 1;
         
         //handle layers 0->next-to-last
         for (int i = 0; i < index; i++) {
            if (output.at(i) < input2.at(i)) {
               output.at(i) = input2.at(i);
            }
         }
         
         //if there's a layer skip, handle it
         if (indexLower < 0) {
            //if indexUpper==0, nothing else happens, we return with empty input
            if (index==0) {
               //we're done
               return;
            }
            
            for (index = index-1; index >= 0; index--) {
               
               if (output.at(index) < input.at(index)) {
                  input.at(index) = output.at(index);
                  if (input.at(index)==1) {
                     continue;
                  }
               }
               break;
            } //end for(indexUpper)
   //         std::cout << "Index is: " << index << std::endl;
            //insert if "good"
            if (output.front() < shift) {
               cdb->insert(output);
            }
         } //end if(layer skip)         
         
      } //end else dir==1
   } //end while(true)
}

IntTrieRelation::IntTrieRelation() {
   tree = new IntArrayTrie();
}
IntTrieRelation::~IntTrieRelation() {
   delete tree;
}

size_t IntTrieRelation::size() const {
   return maxNodeID;
}

void IntTrieRelation::buildIndex(
      std::vector<std::pair<unsigned, unsigned> >& rawTuples)
{
   //properly loads the pairs and computes maxNodeID
   sortRawTuples(rawTuples, false);
   std::vector<std::pair<unsigned, std::vector<unsigned> > > pairs;
   pairs.clear();
   fillPairs(rawTuples, pairs);
   
   std::vector<std::pair<unsigned, std::vector<unsigned> > > newPairs;
   newPairs.swap(pairs); 

   std::vector<int> included(maxNodeID+1, -1);
   for (size_t i = 0; i < newPairs.size(); i++) {
      included[newPairs[i].first] = i;
   }

   std::vector<unsigned> queue(newPairs.size());
   std::vector<int> mapping(maxNodeID+1, -1);
   size_t numVisitedVertices = 0; // so far
   size_t overflow_counter = newPairs.size();
   
   buildMapping(newPairs, queue, mapping, included, numVisitedVertices,
                overflow_counter);
   
   pairs.resize(newPairs.size(), make_pair(0, std::vector<unsigned>()));

   // now, loop through to reassign to all the BFS mapping values
   for (size_t i = 0; i < newPairs.size(); i++) {
      pairs[i].first = i;
   
      size_t idx = mapping[newPairs[i].first];
      pairs[idx].second.swap(newPairs[i].second);
      for (size_t j = 0; j < pairs[idx].second.size(); j++) {
         pairs[idx].second[j] = mapping[pairs[idx].second[j]];
      }
      sort(pairs[idx].second.begin(), pairs[idx].second.end());
   }

   //BFSing complete
   
   std::cout << "Sorting complete" << std::endl;

   //adjust maxNodeID to what is now the maximum node ID.
   maxNodeID = overflow_counter-1;
   //insert data into trie
   maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   shift = (1 << maxDepth);
   
   tree->setMaxDepth(maxDepth);
   tree->setMaxNodeID(maxNodeID);
   
   //start with full trie
   vector<int> box;
   box.push_back(0);
   tree->insert(box);
   box.clear();

   
   for (int i = 0; i < pairs.size(); i++) {
      //calc first element
      unsigned value = pairs[i].first;
      box.push_back(getLocInTrie(value, maxDepth));

      //calc second elements
      for (int j = 0; j < pairs[i].second.size(); j++) {
         value = pairs[i].second[j];
         box.push_back(getLocInTrie(value, maxDepth));
         
         tree->remove(box);
         box.pop_back();
      }
         
 //     std::cout << "Back in trierelation" << std::endl;
      box.clear();
   }//end inserting data into trie
   
 //  std::cout << "done inserting" << std::endl;
      
   countActor* ca = new countActor();
   printActor* pa = new printActor();
 //  printToFileActor* ptfa = new printToFileActor("output.txt", maxDepth);
 //  ptfa->maxDepth = maxDepth;
   
//   tree.apply(pa); 
   tree->apply(ca);
   std::cout << "Count: " << ca->totalCount << std::endl;
   //run ml merger
   int_mlMergerActor* mlma = new int_mlMergerActor(tree);
   mlma->maxNodeID = maxNodeID;
   mlma->maxDepth = maxDepth;
   std::cout << "about to apply ml" << std::endl;
   tree->apply(mlma);
   delete mlma;
   
   std::cout << "ml merger complete." << std::endl;
   
   ca->totalCount = 0;
   //print for debug
  // tree->apply(pa);
  // tree->apply(ptfa);
   tree->apply(ca);
   
   std::cout << "printer complete." << std::endl;
   std::cout << "Count: " << ca->totalCount << std::endl;
   
   delete ca;
   delete pa;
  // delete ptfa;
}


void IntTrieRelation::buildIndexCNF(
         vector<vector<int> >& rawTuples,
         int newMaxNodeID) {
   maxNodeID = newMaxNodeID;
   
   std::vector<std::pair<int, std::vector<int> > > pairs;
  // fillPairsSigned(rawTuples, pairs);
  std::cout << "ERROR: IntTrieRelation::buildIndexCNF does not work." 
            << std::endl;
}

unsigned long IntTrieRelation::performFroggerTricount(
                 size_t start, size_t end) 
{
   if (start!=0) return 0; //not gonna multithread here ftm.
      
   unsigned long count = 0;
   IntArrayTrie* cdb = new IntArrayTrie();
   cdb->setMaxDepth(maxDepth);
   cdb->setMaxNodeID(maxNodeID);
   cdb->setInsertionMode(1);
   
   count = tetris(cdb);
   
   delete cdb;
   return count;
}

unsigned long IntTrieRelation::performPreloadedTricount(
                  size_t start, size_t end)
{
   if (start!=0) return 0; //not gonna multithread here ftm.
   
   unsigned long count = 0;
   IntArrayTrie* cdb = new IntArrayTrie();
   std::cout << "About to clone..." << std::endl;
   cdb->pointerClone(*tree);
   std::cout << "Cloning complete." << std::endl;
   
   count = tetris(cdb);
   
   delete cdb;
   return count;
}
