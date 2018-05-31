//TrieActors.cpp
#include "TrieActors.h"

void printActor::if_word(trieNode* tn, vector<string> currentWord){
   /*for (int i=0; i < currentWord.size(); i++) {
     std::cout << currentWord[i];
    if (currentWord[i].length()==0) {
       std::cout << "*";
     }
    if (i < currentWord.size()-1) {
       std::cout << "/";
     }
   }
  std::cout << std::endl;*/
  std::cout << "\tI'm a word!" << std::endl;
}

void printActor::if_interval(IntervalTrie* intTrie) {
   set<size_t> intervals = intTrie->getIntervals();
   std::cout << "{";
   for (set<size_t>::iterator it=intervals.begin(); 
         it != intervals.end(); it++) {
      std::cout << *it <<", ";
   }
   std::cout << "}" << std::endl;
}

void printActor::if_interval(IntIntervalTrie* intTrie) {
   set<size_t> intervals = intTrie->getIntervals();
   std::cout << "{";
   for (set<size_t>::iterator it=intervals.begin(); 
         it != intervals.end(); it++) {
      std::cout << *it <<", ";
   }
   std::cout << "}" << std::endl;
}

void printActor::if_array(ArrayTrie* arrTrie, int index) {
   std::cout << "at " << index <<": ";
}

void printActor::if_array(IntArrayTrie* arrTrie, int index) {
   std::cout << "at " << index << ": ";
}

//===============END PRINT ACTOR================================

//===============BEGIN PRINT_TO_FILE ACTOR======================
printToFileActor::printToFileActor(string filename, int numBits, int cSize) {
   file.open(filename);
   std::cout << "Assuming maxDepth of " << numBits << std::endl;
      cliqueSize = cSize;
   file << "p cnf " << numBits * cliqueSize << " 50\n";
   
   //default mode is clique
   mode = 'k';
   printHelp = 0;
}

printToFileActor::~printToFileActor() {
   file.close();
}

void printToFileActor::if_interval(IntervalTrie* intTrie) {
   set<size_t> intervals = intTrie->getIntervals();
   for (set<size_t>::iterator it=intervals.begin(); 
         it != intervals.end(); it++) {
      int loc = *it;
      int lower = *it;
      it++;
      int upper = *it;
    //  std::cout << "P0" << std::endl;
      while (loc <= upper) {
         string temp = intTrie->buildDyadic(lower, upper, loc, loc+1);
         //print to file
         for (int x = 0; x < cliqueSize-1; x++) {
            if (printHelp==1 && lhs.size()!=0) {
               for (int y = 0; y < x; y++) {
                  for (int i = 0; i < lhs.size(); i++) {
                     if (lhs.at(i)=='0') {
                        file << -1 * (i + (x * maxDepth) + 1) << " ";
                     }
                     else {
                        file <<  (i + (x * maxDepth) + 1) << " ";
                     }
                  }
                  for (int i = 0; i < temp.size(); i++) {
                     if (temp.at(i)=='0') {
                        file << -1 * (i + (y * maxDepth) + 1) << " ";
                     }
                     else {
                        file << (i + (y * maxDepth) + 1) << " ";
                     }
                  }
                  file << " 0\n";
               }
            }
            
            for (int y = x+1; y < cliqueSize; y++) {
               for (int i = 0; i < lhs.size(); i++) {
                  if (lhs.at(i)=='0') {
                     file << -1 * (i + (x * maxDepth) + 1) << " ";
                  }
                  else {
                     file <<  (i + (x * maxDepth) + 1) << " ";
                  }
               }
               for (int i = 0; i < temp.size(); i++) {
                  if (temp.at(i)=='0') {
                     file << -1 * (i + (y * maxDepth) + 1) << " ";
                  }
                  else {
                     file << (i + (y * maxDepth) + 1) << " ";
                  }
               }
               file << " 0\n";
               if (mode=='c') {
                  if (x!=0) {
                     break;
                  }
                  if (y < cliqueSize-2) {
                     y = cliqueSize - 2;
                  }
               }
               else if (mode=='p') {
                  //for a path, no looping, so effectively lock y at x+1
                  break;
               }
            }//end y loop
         }//end x loop
         int difference = maxDepth - temp.size();
         loc += (2 << difference);
      }//end while loop
   }
}

void printToFileActor::if_array(ArrayTrie* arrTrie, int index) {
   string temp;
   if (index==0) {
      lhs = "";
      return;
   }
   
   temp.resize(maxDepth, '0');
   int initialValue = (1 << maxDepth) - 1;
   int currentLocation = maxDepth - 1;
   int originalIndex = index;
   while (index > 0) {
      if (index >= initialValue) {
         if (index % 2 == 1) {
            //commented out b/c preset
            //temp.at(currentLocation) = '0';
         } else {
            temp.at(currentLocation) = '1';
         }
       
         //update index
         index = (index - 1) / 2;
      }
      else { //not at the lowest depths
         temp.pop_back();
      }
      //update other params
      initialValue/=2;
      currentLocation--;
   }
   
   lhs = temp;
}

void printToFileActor::if_array_word(ArrayTrie* arrTrie, int index) {
   //print out lhs only
 //  std::cout << "P1" << std::endl;
   for (int x = 0; x < cliqueSize-1; x++) {
      for (int i = 0; i < lhs.size(); i++) {
         if (lhs.at(i)=='0') {
            file << -1 * (i + (x * maxDepth) + 1) << " ";
         }
         else {
            file <<  (i + (x * maxDepth) + 1) << " ";
         }
      }
      file << " 0\n";
   }
}

//==============BEGIN COUNT ACTOR===============================
void countActor::if_interval(IntervalTrie* intTrie) {
   totalCount += intTrie->size();
}

void countActor::if_interval(IntIntervalTrie* intTrie) {
   totalCount+= intTrie->size();
}

//===============END COUNT ACTOR================================

//==============BEGIN REMOVE ACTOR==============================
removeActor::removeActor(vector<string> newWord, int mnID) {
   word = newWord;
   level = 0;
   depth = 0;
   mode = 0;
   maxNodeID = mnID;
}

//alwaysDo's job here is to check if the node for the next step exists.
//If it does not, create it.
void removeActor::always_do(trieNode* tn, vector<string> currentWord) {
   if (mode!=0) return;
   
   if (depth==word[level].size()) {
      
      if (level==word.size()-1) { //if removing this node
         if (tn->leftChild!=NULL) {
            delete tn->leftChild;
            tn->leftChild = NULL;
         } if (tn->rightChild!=NULL) {
            delete tn->rightChild;
            tn->rightChild = NULL;
         } if (tn->branchChild!=NULL) {
            delete tn->branchChild;
            tn->branchChild = NULL;
         }
         
         mode = 1; //enter backtrace mode
      }
   
      //create branch child only!
      if (tn->branchChild==NULL) {
         if (level == word.size()-2) {
            tn->branchChild = new IntervalTrie(maxNodeID);
         } else {
            std::cout << "ERROR: not implemented" << std::endl;
            std::cout << "Level is: " << level << std::endl;
            std::cout << "Size is: " << word.size() << std::endl;
         }
      }
      return;
   }
   
   if (tn->isWord()) {
      //if it's a word, we need to create on both sides
      tn->leftChild = new trieNode();
      tn->leftChild->value = '0';
      tn->leftChild->parent = tn;
      
      tn->rightChild = new trieNode();
      tn->rightChild->value = '1';
      tn->rightChild->parent = tn;
      
      return;
   }
   
   if (word[level][depth]=='0') {
      if (tn->leftChild==NULL) {
         tn->leftChild = new trieNode();
         tn->leftChild->value = '0';
         tn->leftChild->parent = tn;
      }
      return;
   }
   
   if (word[level][depth]=='1') {
      if (tn->rightChild==NULL) {
         tn->rightChild = new trieNode();
         tn->rightChild->value = '1';
         tn->rightChild->parent = tn;
      }
      return;
   }
   
   std::cout << "We entered no branches?" << std::endl;
}

bool removeActor::br_left_if(trieNode* tn, vector<string> currentWord) {
   if (depth < word[level].size()) {
      if (word[level][depth]=='0') {
         depth++;
         return true;
      }
   }
   return false;
}

bool removeActor::br_right_if(trieNode* tn, vector<string> currentWord) {
   if (depth < word[level].size()) {
      if (word[level][depth]=='1') {
         depth++;
         return true;
      }
   }
   return false;
}

bool removeActor::br_down_if(trieNode* tn, vector<string> currentWord) {
   if (depth == word[level].size()) {
      level++;
      depth = 0;
      return true;
   }
}

void removeActor::after_children(trieNode* tn, vector<string> currentWord) {
   if (mode!=1) return;
   
   depth--;
   if (word[level].size()==depth) {
      if (tn->branchChild->size()==0) {
         delete tn->branchChild;
         tn->branchChild = NULL;
      }
   }
   else {
      if (word[level][depth]=='0') {
         delete tn->leftChild;
         tn->leftChild = NULL;
      }
      else if (word[level][depth]=='1') {
         delete tn->rightChild;
         tn->rightChild = NULL;
      }
   }
   
   if (tn->isWord()==false) {
      mode = 2;
   }
   
   if (depth==0) {
      if (level > 0) {
         depth = word[level-1].size()+1;
      } 
      else {
         depth = -1;
      }
   }
}

void removeActor::if_interval(IntervalTrie* intTrie) {
   
   intTrie->remove(word);
   if (intTrie->size() ==0) {
      mode = 1;
   } else {
      mode = 2;
   }
   //setup for reversal
   level--;
   depth = word[level].size()+1;
}

//===============END REMOVE ACTOR================================

//===============BEGIN GETALLCONTAININGBOXES ACTOR===============
/*
void getAllContActor::if_array(ArrayTrie* arrTrie) {
   
}

void getAllContActor::if_fertileInterval(FertileIntervalTrie* fIntTrie) {
   
}
*/
//===============END GETALLCONTAININGBOXES ACTOR=================