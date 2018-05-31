#include "TrieRelation.h"
#include <cmath>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "TrieActors.h"

using std::vector;
using std::multiset;

//=======begin simpleMergerActor===============================================
void TrieRelation::simpleMergerActor::after_children
      (trieNode* tn, vector<string> currentWord) {
   if (tn->leftChild!=NULL && tn->rightChild!=NULL) {
      if (tn->leftChild->isWord() && tn->rightChild->isWord()) {
         delete tn->leftChild;
         delete tn->rightChild;
         delete tn->branchChild;
         tn->leftChild = NULL;
         tn->rightChild = NULL;
         tn->branchChild = NULL;
      }
   }
}
//=======end simpleMergerActor=================================================


//=======begin getAllWordsActor================================================
void TrieRelation::getAllWordsActor::if_interval
      (IntervalTrie* intTrie) {
   
   container.push_back(intTrie->getIntervals());
}
//=======end getAllWordsActor==================================================

//=======begin mlMergerActor===================================================
TrieRelation::mlMergerActor::mlMergerActor(GenericTrie* tr) {
      t = tr;
}   

TrieRelation::mlMergerActor::~mlMergerActor() {
}

void TrieRelation::mlMergerActor::setTrie(GenericTrie* tr) {
   t = tr;
}
   
bool TrieRelation::mlMergerActor::br_down_if
      (trieNode* tn, vector<string> currentWord) {
   return false;
}
   
void TrieRelation::mlMergerActor::after_children
      (trieNode* tn, vector<string> currentWord) {
   if ((tn->leftChild!=NULL) && (tn->rightChild!=NULL) ) {
      
      //std::cout << "Attempting merge at: " << currentWord[0] << std::endl;

      //setting up gawaL, gawaR
      int flag = 0;
      TrieRelation::getAllWordsActor* gawaL = 
            new TrieRelation::getAllWordsActor();
      
      TrieRelation::getAllWordsActor* gawaR = 
            new TrieRelation::getAllWordsActor();
      
      if (tn->leftChild->branchChild!=NULL) {
         GenericTrie* leftRoot = tn->leftChild->branchChild;
         leftRoot->apply(gawaL);
      }
      else if (tn->leftChild->isWord()) {
         set<size_t> tempInts;
         tempInts.insert(0);
         tempInts.insert((1 << (maxDepth + 1)) - 1);
         gawaL->container.push_back(tempInts);
         flag+=1;
      }
      else {
         delete gawaL;
         delete gawaR;
         return;
      }
      
      if (tn->rightChild->branchChild!=NULL) {
         GenericTrie* rightRoot = tn->rightChild->branchChild; 
         rightRoot->apply(gawaR);
      }
      else if (tn->rightChild->isWord()) {
         set<size_t> tempInts;
         tempInts.insert(0);
         tempInts.insert((1 << (maxDepth + 1)) - 1);
         gawaR->container.push_back(tempInts);
         flag+=2;
      }
      else {
         delete gawaL;
         delete gawaR;
         return;
      }
      
      //assert: gawaL, gawaR set up
      //check for equality
      if (gawaL->container==gawaR->container) {
         //std::cout << "made it" <<std::endl;
         if (flag ==0) {
            delete tn->rightChild->branchChild;
            tn->rightChild->branchChild=NULL;
            delete tn->leftChild->branchChild;
            tn->leftChild->branchChild=NULL;

         }
         else if (flag==1) {
            delete tn->rightChild->branchChild;
            tn->rightChild->branchChild=NULL;
         }
         else if (flag==2) {
            delete tn->leftChild->branchChild;
            tn->leftChild->branchChild=NULL;
         }
         else if (flag==3) {
            delete tn->leftChild;
            delete tn->rightChild;
            tn->leftChild=NULL;
            tn->rightChild=NULL;
            
            delete gawaL;
            delete gawaR;
            return;
         }
      }
      
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
            } else { //is right
               if (currentlyOnLeft==2) {
                  finishedIntervals.insert(*it);
               }
               currentlyOnLeft--;
            }
         }
         
         if (finishedIntervals.size()%2!=0) {
            std::cout << "ERROR: combining went wrong!" << std::endl;
         }
         
         IntervalTrie* intTrie = new IntervalTrie(maxNodeID);
         intTrie->setIntervals(finishedIntervals);
         
         tn->branchChild = intTrie;
       
      }
      delete gawaL;
      delete gawaR;
   } // end if 
}


void TrieRelation::mlMergerActor::if_array_after_children
      (ArrayTrie* at, int index) 
{
   if (index < 31) {
      std::cout << "At index: " << index << std::endl;
   }
   if ( (index*2+2 < at->bits.size()) &&
         (at->bits[index*2+1]==1) && (at->bits[index*2+2]==1) ) 
   {
      //std::cout << "Attempting merge at: " << currentWord[0] << std::endl;

      //setting up gawaL, gawaR
      TrieRelation::getAllWordsActor* gawaL = 
            new TrieRelation::getAllWordsActor();
      
      TrieRelation::getAllWordsActor* gawaR = 
            new TrieRelation::getAllWordsActor();
      
      if (at->branches[index*2+1]!=NULL) {
         at->branches[index*2+1]->apply(gawaL);
      }
      else if (at->wordBits[index*2+1]==1) {
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
      
      if (at->branches[index*2+2]!=NULL) {
         at->branches[index*2+2]->apply(gawaR);
      }
      else if (at->wordBits[index*2+2]==1) {
         set<size_t> tempInts;
         tempInts.insert(0);
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
         
         IntervalTrie* intTrie = new IntervalTrie(maxNodeID);
         intTrie->setIntervals(finishedIntervals);
         
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
            if (at->branches[index*2+1]!=NULL) {
               at->branches[index*2+1]->remove_for_size(left, right);
               if (at->branches[index*2+1]->size()==0) {
                  at->branches.at(index*2+1).reset();
               }
            }
            if (at->branches[index*2+2]!=NULL) {
               at->branches[index*2+2]->remove_for_size(left, right);
               if (at->branches[index*2+2]->size()==0) {
                  at->branches.at(index*2+2).reset();
               }
            }
         }//end for (delete from children)
         
      }//end if anything to merge (for loop)
      delete gawaL;
      delete gawaR;
   } // end if 
}

//=======end mlMergerActor=====================================================


//mode: number of backtraces now possible
vector<string> TrieRelation::merge
    (const vector<string>& box1, const vector<string>& box2, int& mode) const{
   vector<string> toBeReturned;
//   mode = 0;
   
   /*
   if (box1.size()!=box2.size()) {
      std::cout << "ERROR: box size does not match" << std::endl;
	   mode = -1;
	   return toBeReturned;
   }*/
   
   for (int i = 0; i < box1.size(); i++) {
      if (box1[i]==box2[i]) {
	      toBeReturned.push_back(box1[i]);
	   } else {
	      if (box1[i].length() > box2[i].length()) {
		      toBeReturned.push_back(box1[i]);
	      } else if (box1[i].length() < box2[i].length()) {
		      toBeReturned.push_back(box2[i]);
	      } else {
		      //final (interesting) layer only
		      //toBeReturned.push_back(box1[i].substr(0,box1[i].length()-1));
            toBeReturned.push_back(box1[i]);
            toBeReturned.back().pop_back();
            if (toBeReturned.back().size()==0) {
               int j = i - 1;
               if (j >= 0) {
                  mode += maxDepth - toBeReturned[j].size();
                  //if (mode % maxDepth !=0) {
             //     if (toBeReturned[j].size()!=0) {
             //        break;
            //      }
           //       j--;
               }//end while
            }
		   }
      } //end else
   }
   
   return toBeReturned;
}

TrieRelation::TrieRelation() {}

TrieRelation::~TrieRelation() {}

size_t TrieRelation::size() const {
   /*countActor* ca = new countActor();
   ca->totalCount = 0;
   tree.apply(ca);
   size_t tbr = ca->totalCount;
   return tbr;*/
   //the above doesn't work with fucking const
   //TODO: make a fucking const version of everything, I guess?
   return 100;
}

string TrieRelation::getBinaryString(unsigned value, int maxDepth) {
   char buffer[100];
   buffer[maxDepth] = '\0';
   int loc = maxDepth - 1;
   
   while (loc >= 0) {
      int modValue = value % 2;
      modValue += '0';
      buffer[loc] = (char)modValue;
      loc--;
      value /= 2;
   }
 //  std::cout << "gbs returning: " << string(buffer) << std::endl;
   return string(buffer);
}

void TrieRelation::buildIndex(vector<std::pair<unsigned, unsigned> >& rawTuples) {   
   
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
   tree.setMaxDepth(maxDepth);
   tree.setMaxNodeID(maxNodeID);
   
   //start with full trie
   vector<string> box;
   box.push_back("");
   tree.insert(box);
   box.clear();
   
   for (int i = 0; i < pairs.size(); i++) {
      //calc first element
      unsigned value = pairs[i].first;
      box.push_back(getBinaryString(value, maxDepth));

      //calc second elements
      for (int j = 0; j < pairs[i].second.size(); j++) {
         value = pairs[i].second[j];
         box.push_back(getBinaryString(value, maxDepth));
         
         tree.remove(box);
         box.pop_back();
      }
         
 //     std::cout << "Back in trierelation" << std::endl;
      box.clear();
   }//end inserting data into trie
   
 //  std::cout << "done inserting" << std::endl;
      
   countActor* ca = new countActor();
   printActor* pa = new printActor();
   
   
   //tree.apply(pa);
   tree.apply(ca);
   std::cout << "Count: " << ca->totalCount << std::endl;
   //run ml merger
   mlMergerActor* mlma = new mlMergerActor(&tree);
   mlma->maxNodeID = maxNodeID;
   mlma->maxDepth = maxDepth;
   std::cout << "about to apply ml" << std::endl;
   tree.apply(mlma);
   delete mlma;
   
   std::cout << "ml merger complete." << std::endl;
   
   ca->totalCount = 0;
   //print for debug
  // tree.apply(pa);
   
   tree.apply(ca);
   
   std::cout << "printer complete." << std::endl;
   std::cout << "Count: " << ca->totalCount << std::endl;
   
   delete ca;
   delete pa;
}

//essentially Tetris-reloaded
unsigned long TrieRelation::performFroggerTricount
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
   for (int i=0; i < 3; i++) {
      input.push_back("");
   }
   std::cout << "Checkpoint 2!" << std::endl;   

   result = tetris(input,cdb,count);
   std::cout << "Checkpoint 3!" << std::endl;   
   
   delete cdb;
   return count;
}
   

//the integer is the number of stages to go back
//(==0 -> "true" in the paper)
pair<int, vector<string> > TrieRelation::tetris(
      vector<string>& input, 
      GenericTrie* cdb,
      unsigned long& count) const
{
   pair<int, vector<string> > output;
   //shortcutting output point later, since I don't see how to do it here
 //  std::cout << "Checking CDB for input..." << std::endl;
   output.second.resize(3, "");
   if (cdb->contains(input, output.second)) {
      output.first=0;
      while (output.second.size() < input.size()) {
         output.second.push_back("");
      }
      
      //output.second = input;
      return output;
   }
   if (input.back().size()==maxDepth) {//=== is a unit box

      vector<vector<string> > allBoxes = getAllContainingBoxes(input);
 //     std::cout << "Back from gacb" << std::endl;
      if (allBoxes.size()==0) { //is an output point

         count++;
         //cdb->insert(input);
         output.first=0;
         output.second.swap(input);
         if (count % 10000 == 0) {
            std::cout << "Current count: " << count << std::endl;
         }
         return output;
      } else { //negative witness found
         
         //insert all
         //NOTE: the guarantee that the best one is at 0 is assured from GACB
         //(TODO: check that better? I think it might be off...)
     //    std::cout << "========NEW SET==========" << std::endl;
         for (int i = 0; i < allBoxes.size(); i++) {
            cdb->insert(allBoxes.at(i));
      /*      for (int j = 0; j < allBoxes.at(i).size(); j++) {
               std::cout << allBoxes.at(i).at(j) << ", ";
            }
            std::cout << std::endl;*/
            
    /*        for (int j = allBoxes.at(i).size()-1; j >= 0; j--) {
               if (allBoxes.at(i).at(j).size() < allBoxes.at(0).at(j).size()) {
                  std::cout << "ERROR: Superior Found!" << std::endl;
                  string temp;
                  std::cin >> temp;
               }
               else if (allBoxes.at(i).at(j).size() > allBoxes.at(0).at(j).size()) {
                  break;
               }
            }*/
         }
         
         output.second.swap(allBoxes.at(0));
         for (int i = output.second.size()-1; i >= 0; i--) {
            output.first += (maxDepth - output.second.at(i).size());
            
            if (output.second.at(i).size()!=0) {
               break;
            }
         }
         return output;
      }
   }
   else {
      // Need to split and recurse 

      vector<string> input1;
      vector<string> input2;
      splitFirstSplittableDim(input1, input2, input);
      
      pair<int, vector<string> > subOutput1;
      subOutput1 = tetris(input1, cdb, count);
    //  std::cout << "Back from making suboutput1" << std::endl;
    
      //negative trip:
      if (subOutput1.first > 0) {
         subOutput1.first--;
         return subOutput1;
      }
      
   //   std::cout << "Making suboutput2" << std::endl;
      
      //going to the other half
      pair<int, vector<string> > subOutput2;
      subOutput2 = tetris(input2, cdb, count);
 
      //negative trip
      //(can occur post-merge)
      if (subOutput2.first > 0) {
         subOutput2.first--;
         return subOutput2;
      }
      
      //merge the outputs
      output.first = 0;
      output.second = merge(subOutput1.second, subOutput2.second,output.first);     
      //cdb->insert(output.second); //<- it's unnecessary to add the box!  
      return output;
   }
}

void TrieRelation::splitFirstSplittableDim(
      vector<string>& input1, 
      vector<string>& input2, 
      const vector<string>& input) const
{
   //find first splittlable dim
   int fsd = input.size()-1;
   for (; fsd > 0; fsd--) {
      if (input.at(fsd)!="") {
         break;
      }
   }
   if (input.at(fsd).size() == maxDepth) {
      fsd++;
   }
   
   //assert:fsd==first splittable dim
   input2 = input1 = input;
   input1[fsd].push_back('0');
   input2[fsd].push_back('1');
}

//note: lambdas must be explicit! (i.e. assuming left.size()==right.size())
//also this can be made way more efficient...
bool TrieRelation::subsumes(vector<string>& left, vector<string>& right) const{
   for (int i = 0; i < right.size(); i++) {
      if (left.at(i)!=right.at(i).substr(0,left.at(i).size())) {
         return false;
      }
   }
   return true;
}

//TODO: PARALLELIZE THIS!!!
vector<vector<string > > TrieRelation::getAllContainingBoxes(
      vector<string>& input) const 
{
   if (input.size()!=3) {
      std::cout << "input not 3 in trierelation::gacb?" << std::endl;
   }
   vector<string> testBox;
 //  int cap = 999;
   
   testBox.push_back(input.at(0));
   testBox.push_back(input.at(1));
   vector<string> prevWord;
   vector<vector<string> > output = 
         tree.getAllContainingBoxes(testBox, prevWord);
   /*int initSize = output.size();
   
   for (int i = 1; i < initSize; i++) {
      if (output.at(i).back().size() < output.front().back().size()) {
         output.front().swap(output.at(i));
      }
   }*/
   
   for (int i = 0; i < output.size(); i++) {
    /*  if (output.at(i).at(0)=="") {
         cap = output.at(i).at(1).size();
      }*/
      output.at(i).push_back("");
   }
   
   prevWord.clear();
   testBox.pop_back();
   testBox.push_back(input.at(2));
   vector<vector<string> > tempOutput = 
      tree.getAllContainingBoxes(testBox, prevWord);
      
   for (int i = 0; i < tempOutput.size(); i++) {
      //check for duplicates (roughly a wash in terms of time)
      if (tempOutput.at(i).at(1)=="") continue;
      
      vector<string> temp;
      temp.push_back(tempOutput.at(i).at(0));
      temp.push_back("");
      temp.push_back(tempOutput.at(i).at(1));
      output.push_back(temp);
   }
   //int midSize = output.size();
   
   prevWord.clear();
   testBox[0] = input.at(1);
   //tempOutput = tree.getAllContainingBoxes(testBox, prevWord, cap);
   tempOutput = tree.getAllContainingBoxes(testBox, prevWord);              
      
   for (int i = 0; i < tempOutput.size(); i++) {
      //check for duplicates
      if (tempOutput.at(i).at(0)=="") continue;
      //NOTE: there can be dupes with a blank at 1,
      //but they are sometimes unique, so we can't delete them!
   
      vector<string> temp;
      temp.push_back("");
      temp.push_back(tempOutput.at(i).at(0));
      temp.push_back(tempOutput.at(i).at(1));
      output.push_back(temp);
   }
   /*
   if (initSize==0) {
      for (int i = 1; i < output.size(); i++) {
         if (output.front().back().size() > output.at(i).back().size()) {
            output.front().swap(output.at(i));
         }
      }
   } 
   else if (output.front().at(1).size()!=0) {
      for (int i = midSize; i < output.size(); i++) {
         if (output.at(i).back().size()==0) {
            if (output.front().at(1).size() >= output.at(i).at(1).size()) {
               output.front().swap(output.at(i));
               break;
            }
         }
      }
   }*/
   
   //simpler alternative for determining opt.
   //It's slightly slower, but it's also actually scalable:
   for (int i = 1; i < output.size(); i++) {
      for (int j = 2; j >= 0; j--) { //<- for generic, change init here
         int a = output.front().at(j).size();
         int b = output.at(i).at(j).size();
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
      }
   }
            
   
   //return regardless of size
   return output;
}
      
unsigned long TrieRelation::performBuildCNFInput(
         size_t start, size_t end)
{
    //handle printing for CNF inputs
   std::string response;
   std::string filename;
   std::cout << "Enter file name:" << std::endl;
   std::cin >> filename;
   std::cout << "Enter mode (c=cycle, k=clique, p=path): " << std::endl;
   std::cin >> response;
   char mode = response.at(0);
   std::cout << "Enter size:" << std::endl;
   std::cin >> response;
   int cSize = atoi(response.c_str());
   std::cout << "Bonus data? (y/n) " << std::endl;
   std::cin >> response;
   char bonusData = response.at(0);
   while (cSize<=0) {
      std::cout << "ERROR: Bad size. Try again." << endl;
      std::cin >> response;
      int cSize = atoi(response.c_str());
   }
   
   //TODO: you gotta make those const versions man.
   printToFileActor* ptfa = new printToFileActor(filename, maxDepth, cSize);
   ptfa->maxDepth = maxDepth;
   ptfa->mode = mode;
   if (bonusData=='y') {
      ptfa->printHelp = 1;
   }
   tree.apply(ptfa);
   delete ptfa;
}
