//Locks243Relation.cpp

#include "Locks243Relation.h"
#include "varMap.h"
#include "Base243GIAT.h"
#include "Base243InnerGIAT.h"
#include "BigOr243Trie.h"

 // struct timeval ltv, ltv2;
 // double l243_totalTime;
 // int iterations = 0;

//TODO: Could super-easily be merged with Base243's version, just need subroutine for binary stuff that's empty in Base243.
void Locks243Relation::insertData(vector<vector<int> >& input, int maxNodeID) {
   _LAYERS = (maxNodeID + 4) / 5;
   std::string treeType = gvars.getStr(DB_TYPE);
   std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   delete tree;
   if (treeType == "bigor") {
      tree = new IATDummy(new BigOr243Trie(_LAYERS, orderer->getExtra()));
   }
   else {
      tree = new IATDummy(new Base243InnerGIAT());
   }
   
   locksLUT.clear();
   locksLUT.offset = maxNodeID+10;
   locksLUT.resize(maxNodeID+20);
   
   reverseLocksLUT.clear();
   reverseLocksLUT.offset = maxNodeID+10;
   reverseLocksLUT.resize(maxNodeID+20);
   
   activeLocks.clear();
   activeLocks.resize(maxNodeID + 10, false);
   
   activeLocksLUT.clear();
   activeLocksLUT.resize(maxNodeID + 10);
   
   reverseActiveLocksLUT.clear();
   reverseActiveLocksLUT.offset = maxNodeID+10;
   reverseActiveLocksLUT.resize(maxNodeID+20, INT_MAX);
   
   _NULLED = B243_ALL_LAMBDA;
   finalDegree = maxNodeID % 5;
   vector<int> insertionVector;
   insertionVector.resize(maxNodeID + 1, B243_CNFLAMBDA);
   vector<int> iv2;
   iv2.resize(_LAYERS + 1);
   vector<int> temp;
   temp.resize(iv2.size(), 1);
   
   std::cout << "Packing " << insertionVector.size() - 1 << " logical layers into " 
             << iv2.size() - 1<< " physical ones\n";
   //insert all boxes into the tree
   //TODO: improve time
   std::cout << "Total terms: " << input.size() << std::endl;
   
   tree->setLayers(_LAYERS);

   tree->setModLayers(0);

   int binaryCount = 0;
   
   for (int i = 0; i < input.size(); i++) {
      //handle binary
      if (input.at(i).size() < 3 && std::abs(input.at(i).back()) < maxNodeID/1) {
         //can't remember if guar'd sorted, so...
         if (std::abs(input.at(i).at(0)) > std::abs(input.at(i).at(1))) {
            std::swap(input.at(i).at(0), input.at(i).at(1));
         }
         //p. sure this is safe
         addToLocksLUT(input.at(i).at(0), -1 * input.at(i).at(1));
          // std::cout << "Inserting binary clause: " << input.at(i).at(0) << ", " << input.at(i).at(1) << ".\n";
         binaryCount++;
         
         continue; //go to next input
      }
      int val;
      int maxVal = 0;
     // std::cout << "current: "; printBox(input.at(i));
      for (int j=0; j < input.at(i).size(); j++) {
         val = input.at(i).at(j);
         if (maxVal < std::abs(val)) {
            maxVal = std::abs(val);
         }
         if (val < 0) {
            insertionVector.at(std::abs(val) - 1) = B243_CNFNEG; 
         } else {
            insertionVector.at(val - 1) = B243_CNFPOS; 
         }
      }
      
      insertionVector.at(std::abs(maxVal)) = _CNFINT_KILL;
      
      int j;
      for (j = 0; j < std::abs(maxVal); j+=5) {
         int sum = 0;
         int endFlag = 0;
         for (int k = j; k < j + 5; k++) {
            if (insertionVector.at(k)==_CNFINT_KILL) {
               endFlag = 1;
               while (k < j + 5) {
                  k++;
                  sum*=3;
               }
               break;
            }
            sum = sum * 3 + insertionVector.at(k);
         }
         iv2.at(j/5) = sum;
         if (endFlag) {
            j+=5;
            break;
         }
      }
      iv2.at(j/5) = _CNFINT_KILL; //= -1; 
  // std::cout << "About to insert "; printBox(iv2); 
      tree->insertShort(iv2, input.at(i));
  // std::cout << "Insertion complete." << std::endl;
    //  insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
  //    std::cout << std::endl; 
  vector<int> output;
  output.resize(iv2.size(), 0);
     if (!tree->contains(iv2, output)) {
         std::cout << "ERROR: input not present!" << std::endl;
         std::cout << "At loop " << i << ", IV is: ";
         for (int i = 0; i < iv2.size(); i++) {
            std::cout << iv2.at(i) << ", ";
         }
         std::cout << std::endl;
         string temp;
         std::cin >> temp;
      }
      
      //prepare for next round
      insertionVector.at(std::abs(maxVal)) = B243_CNFLAMBDA;
      for (int j=0; j < input.at(i).size(); j++) {
         insertionVector.at(std::abs(input.at(i).at(j)) - 1) = B243_CNFLAMBDA;
      }
      
      //progress bar-ish
      if (i % 100000 ==0) {
         std::cout << "i: " << i << std::endl;
      }
   }
   std::cout << binaryCount << " binary clauses detected.\n";
   
   finalDegree = (5 - finalDegree) % 5;
   bitIndex = 0;
   mCap = -1;
   
   tree->setModLayers(finalDegree);
}

void Locks243Relation::attachOnEnd(vector<int>& input, int& index) {
   int addValue = 0;
   for (int i = 0; i < finalDegree; i++) {
      addValue = addValue * 3 + 1;
   }
   input.at(index) += addValue;
}

void Locks243Relation::fillZero(vector<int>& input, int& index) {
   // std::cout << "Starting bitIndex: " << bitIndex << std::endl;
  // std::cout << "Fillzero start input: "; printBox(input);
   int hsb = highestSetBit(input[index]);
   int initIndex = index;
   int exactLoc = hsb + initIndex;
   while (index <= input.size() - 1) {
      setNext(input, 0, index);
   }
   index--;
   //bitIndex--;
   static int fzLUT[] = {
      121, 121, 122, 121, 121, 122, 124, 124, 125, //0-8
      121, 121, 122, 121, 121, 122, 124, 124, 125, //9-17
      130, 130, 131, 130, 130, 131, 130, 130, 131, //18-26
      121, 121, 122, 121, 121, 122, 124, 124, 125, //27-35
      121, 121, 122, 121, 121, 122, 124, 124, 125, //36-44
      130, 130, 131, 130, 130, 131, 133, 133, 134, //45-53
      148, 148, 149, 148, 148, 149, 151, 151, 152, //54-62 
      148, 148, 149, 148, 148, 149, 151, 151, 152, //63-71
      157, 157, 158, 157, 157, 158, 160, 160, 161, //72-80
      
      121, 121, 122, 121, 121, 122, 124, 124, 125, //81-89
      121, 121, 122, 121, 121, 122, 124, 124, 125, //90-98
      130, 130, 131, 130, 130, 131, 130, 130, 131, //99-107
      121, 121, 122, 121, 121, 122, 124, 124, 125, //108-116
      121, 121, 122, 121, 121, 122, 124, 124, 125, //117-125
      130, 130, 131, 130, 130, 131, 133, 133, 134, //126-134
      148, 148, 149, 148, 148, 149, 151, 151, 152, //135-143 
      148, 148, 149, 148, 148, 149, 151, 151, 152, //144-152
      157, 157, 158, 157, 157, 158, 160, 160, 161, //153-161
      
      202, 202, 203, 202, 202, 203, 205, 205, 206, //162-170
      202, 202, 203, 202, 202, 203, 205, 205, 206, //171-179
      211, 211, 212, 211, 211, 212, 214, 214, 215, //180-188
      202, 202, 203, 202, 202, 203, 205, 205, 206, //189-197
      202, 202, 203, 202, 202, 203, 205, 205, 206, //198-206
      211, 211, 212, 211, 211, 212, 214, 214, 215, //207-215
      229, 229, 230, 229, 229, 230, 232, 232, 233, //216-224
      229, 229, 230, 229, 229, 230, 232, 232, 233, //225-233
      238, 238, 239, 238, 238, 239, 241, 241, 242};//234-242
      
      for (int i = initIndex; i <= index; i++) {
         input[i] = fzLUT[input[i]];
      }
   //attachOnEnd(input, index);
   // std::cout << "Zero filled. index is " << index << ", bitIndex: " << bitIndex << std::endl;
   
   
}

int Locks243Relation::firstUnsetBit(int input) const {
   if (input < 81) return 0;
   while (input >= 81) input -= 81;
   if (input < 27) return 1;
   while (input >= 27) input -= 27;
   if (input < 9) return 2;
   while (input >= 9) input -= 9;
   if (input < 3) return 3;
   while (input >= 3) input -= 3;
   if (input == 0) return 4;
   else return 5;
}

void Locks243Relation::setNext(vector<int>& input, int val, int& index) {
     // std::cout << "Pushing " << val << " to " << input.at(index) << ".\n";
   //int bit = firstUnsetBit(input.at(index)); //might mess something up elsewhere...

   bitIndex++;
   while (true) {
      if (bitIndex >= activeLocks.size()) {
         bitIndex--;
         index++;
         return;
      }
       // std::cout << "activeLocks[" << bitIndex << " is " << activeLocks[bitIndex] << "]" << std::endl;
      if (activeLocks[bitIndex]) {
         bitIndex++;
      }
      else {
         break;
      }
   }

   int bit = bitIndex - index * 5 - 1;
   while (bit >= 5) {
      index++; //could overflow index?
      if (index >= input.size() - 1) {
         bitIndex--;
         return;
      }
      bit -= 5;
   }
   // std::cout << "Bit: " << bit << std::endl;
   // std::cout << "BitIndex: " << bitIndex << std::endl;


   int writeLocation = index * 5 + bit + 1;
   if (writeLocation != bitIndex) {
      std::cout << "\t\tERROR!\n";
   }
   
   int sign = (val * 2) - 1; //left is -1, right is 1
   // std::cout << "WL * SIGN: " << writeLocation * sign << std::endl;

   activeLocksLUT[activeLocksLUTLoc].first = writeLocation;
   //no contradictions, so write locks

   for (int i : locksLUT[writeLocation * sign]) {

      int loc = std::abs(i);

      if (activeLocks[loc]) {
         //same-value already existing lock, so don't create a new owner
         continue;
      }         
      
      // std::cout << "\tinserting lock from " << writeLocation * sign << " to " << i << ".\n";

      int value = writeToInput(input, i, 1);
      activeLocks[loc] = value;
      activeLocksLUT[activeLocksLUTLoc].second.insert(i);
//      activeLocksLUT[writeLocation*sign].insert(i);
      reverseActiveLocksLUT[i] = writeLocation*sign;
   }

   //if pushed something to acLUT, advance pointer
   if (activeLocksLUT[activeLocksLUTLoc].second.size()) {
      activeLocksLUTLoc++;
   }
        // gettimeofday(&ltv, NULL);         
   //ASSERT: Locks set up, no contradictions, safe to write
   if (val == 1) {
   static int snLUT[5][2] = { {81, 162},{27, 54}, {9, 18}, {3, 6}, {1,2}}; 
   
   input[index] += snLUT[bit][val];
   }
   
            // gettimeofday(&ltv2, NULL);
      // l243_totalTime+=double(ltv2.tv_sec - ltv.tv_sec) + 
          // double(ltv2.tv_usec - ltv.tv_usec)/1000000;
          
          // iterations++;
       // if (iterations % 500000 == 0) {
          // std::cout << "total time so far: " << l243_totalTime << std::endl;
       // }
}



int Locks243Relation::performShrinkage(vector<int>& input, 
                                       vector<int>& output,
                                       int& index)
{

   // std::cout << "start index: " << index;
   // std::cout << "start input: "; printBox(input);
   // std::cout << "Reducing on: "; printBox(output);
   for (; index >= 0; index--) {
      //TODO: This can be done much faster
      //Less than is because of CNF_KILL
      if (output.at(index) <= B243_ALL_LAMBDA) {
         input.at(index) = B243_ALL_LAMBDA;
         
         //reinsert values corresponding to locks
         repairLocks(input, index, 4, 0);
         continue;
      }//end dealing with 5lambdas in OUTPUT.
      
      //shortcut for being donezo
      if (index < 0) {
         // std::cout << "Uh-oh.\n";
         return -1;
      }
      
      //need to go from 5 because it still has five values regardless.
      int input_HSB = 5; //highestSetBit(input.at(index));
      //figure out how low we can take the input
      int output_HSB = highestSetBit(output.at(index));
      
      //if this location is locked, we merge with the box that locked it and continue
      
      if (activeLocks[index * 5 + output_HSB]) {
         // std::cout << "Output at start: "; printBox(output);
         int source = 0;
         if (reverseActiveLocksLUT.count(index*5 + output_HSB)) {
            source = reverseActiveLocksLUT[index*5+output_HSB];
         }
         else {
            source = reverseActiveLocksLUT[-1 * (index*5+output_HSB)];
         }
         
         //WARNING: changing invariants
         int tempBI = bitIndex;
         bitIndex = std::abs(index*5+output_HSB);
         int temp = 0;

         //remove output's final bit:
         popOneCore(output, temp, index);
         
         bitIndex = std::abs(source);
         // std::cout << "\tSurgery is at " << bitIndex << std::endl;
         int tempIndex = (bitIndex - 1) / 5;
         // std::cout << "Reassigning " << source << std::endl;
         popOneCore(output, temp, tempIndex);
         writeToInput(output, source, 1);
         
         bitIndex = tempBI; //unnecessary?

         //assert: merger complete, invariants restored
         //need to restart on current level tho
         index++;
                  // std::cout << "Output at end: "; printBox(output);

         continue;
      }
      
      int divCount = 0;

      //bring it that low
      while(input_HSB > output_HSB) {
         input.at(index) /= 3;
         input_HSB--;
         divCount++;
      }
      for (int i = 0; i < divCount; i++) {
         input.at(index) *= 3;
      }
      
      //reinsert lost locks again...
      repairLocks(input, index, 4, output_HSB);
      
      //set bitIndex
      bitIndex = index * 5 + output_HSB;
      

      clearLocksAt(input, bitIndex+1);
      
      break; //final layer handled, no more shrinkage.
   }

   // std::cout << "end index: " << index;
   // std::cout << "end input: "; printBox(input);
   // std::cout << "end bitIndex: " << bitIndex << std::endl;

   return 1;
}

void Locks243Relation::repairLocks(vector<int>& input, int& index, int start, int end) {

   // std::cout << "Repairin' locks from " << start << " to " << end << " at " << index << ".\n";
 //  int writeValueF = 1;
 //  int writeValueT = 2;
   for (int i = start; i >= end; i--) {
      input.at(index) += activeLocks[index*5+1+i];
   }

}

int Locks243Relation::updateBitIndex(vector<int>& input, int& index) {
   bitIndex = 5 * index + highestSetBit(input.at(index));
   // while (activeLocks[bitIndex]) {
      // bitIndex--;
   // }
   // if (bitIndex < 5 * index) bitIndex = 5 * index;
   return bitIndex - 5 * index;
}

// int Locks243Relation::mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower) {
   // std::cout << "\t\tWe're trying shit." << std::endl;
   // performShrinkage(input, output, index);
   
   // std::cout << "\t\tShit has been tried." << std::endl;
   // if (index < 0) return -1;
   
   // //insertion
   // if (index < output.size() - 1) {
      // output.at(index + 1) = -1;
      // if (getLambdaCount(output, index) + (output.size() - index) > output.size() * ratio) {
         // bool result = cdb->insert(output);
      // }
      // std::cout << "Insertion went fine." << std::endl;
   // }
   
   // return 0;
// }


int Locks243Relation::writeToInput(vector<int>& input, int loc, int direction) {
   // std::cout << "Writing " << loc << " to "; printBox(input);
static int witLUT[5][2] = { {81, 162},{27, 54}, {9, 18}, {3, 6}, {1,2}}; 

            
   int abs = std::abs(loc);
   int index = (abs - 1)/5;
   int bit = (abs - 1) % 5;
   int writeValue = (loc > 0 ? 1 : 0);
   // for (int k = 4; k > bit; k--) {
      // writeValue *= 3;
   // }
  writeValue = witLUT[bit][writeValue];
   input.at(index) += writeValue * direction;
   
   return writeValue;
}

void Locks243Relation::popOneCore(vector<int>& input, int& last, int& index) {
   //int lastBitSet = highestSetBit(input, index);
   /*int lastBitSet = bitIndex % 5;
   if (lastBitSet == 0) lastBitSet = 5;*/
   int lastBitSet = highestSetBit(input, index); //this does the above now
   switch (lastBitSet) {
      case 0:
         //popping an empty, do nothing
         // std::cout << "\tERROR: L243Rel::popOne::Popping an empty" << std::endl;
         // std::cout << "Input (index: " << index << "): "; printBox(input);
         break;
      case 5:
         last = input.at(index)%3 - 1;
         input.at(index) = input.at(index) - (last + 1);
         break;
      case 4:
         last = ((input.at(index)% 9)/3) * 3;
         input.at(index) -= last;
         last = (last / 3) - 1;
         break;
      case 3:
         last = ((input.at(index) % 27)/9) * 9;
         input.at(index) -= last;
         last = (last / 9) - 1;
         break;
      case 2:
         last = ((input.at(index) % 81)/27) * 27;

         input.at(index) -= last;
         last = (last / 27) - 1;
         break;
      case 1:
         last = ((input.at(index)) / 81) * 81; //%243 is redundant
         input.at(index) -= last;
         last = (last / 81) - 1;
         break;
      default:
         std::cout << "\tERROR: Highest set bit greater than five???" << std::endl;
   }
   // std::cout << "Core deleted " << last << " at " << bitIndex << std::endl;
}

//! This version is for everything but the input! 
//! (Yes, this is annoying and silly. I'm sorry.)
void Locks243Relation::popOne(vector<int>& input, int& index) {
   int coreVal = 0;
   bitIndex++;
   //int currBitIndex = bitIndex;
   //bitIndex = mPrevSource;
   popOneCore(input, coreVal, index);
   if (coreVal == -1) {
      mLegalReduction = false;
   }
   //bitIndex = currBitIndex;
   bitIndex--;
}

void Locks243Relation::setCap(int& lowBound) {
   mCap = bitIndex - (bitIndex % 5 - lowBound);
   // std::cout << "Cap has been set at " << mCap << ".\n";
}

bool Locks243Relation::isPermitted(vector<int>& output, int& index, int& indexLower, int& il2) {
   return true;
   //if the actually popped bit doesn't exist, we can't safely reduce.
   //TODO: There might be better ways, based on watching locks
   if (!mLegalReduction) {
      return false;
   }
   
   //check if mPrevSource is in the same band. If yes, make sure there's not something above indexLower.
   if ((mPrevSource - 1) / 5 == index) {
      return il2 <= indexLower;
      // return true;
   } 
   
   //see if there's any non-zeros between index and mPrevSource
   int pastIndex = (mPrevSource - 1) / 5;
   for (int i = index + 1; i <= pastIndex; i++) {
      if (output.at(i) > 0) {
         return false;
      }
   }
   
   return true;
}

void Locks243Relation::removeCap() {
   mCap = -1;
}

void Locks243Relation::popOne(vector<int>& input, int& last, int& index) {
   // std::cout << "Starting loc: " << mPrevSource << std::endl;
   // std::cout << "Popping at bitIndex " << bitIndex << std::endl;
   mPrevSource = bitIndex;
   mLegalReduction = true;
   if (bitIndex <= mCap) return;
   while (activeLocks[bitIndex]) {
      if (bitIndex == mCap) return;
      bitIndex--;
   }
   if (bitIndex == mCap) return;

   while (index * 5 >= bitIndex) {
      index--;
   } //TODO: check for <0?
   popOneCore(input, last, index);
   
   //handle cleared locks
   // std::cout << "Popper is clearing locks from " << bitIndex << std::endl;
   clearLocksAt(input, bitIndex);
   // std::cout << "After pop, input is now "; printBox(input);
      bitIndex--; //Pretty sure I don't want to move index here?

   return;
}

//note: clears all locks THROUGH a given index.
bool Locks243Relation::clearLocksAt(vector<int>& input, int loc) {
   
   while (activeLocksLUT[activeLocksLUTLoc - 1].first >= loc) {
      
      activeLocksLUTLoc--;
      for (int j : activeLocksLUT[activeLocksLUTLoc].second) {
         writeToInput(input, j, -1);
         reverseActiveLocksLUT.erase(j);
         activeLocks[std::abs(j)] = false;
      }
      activeLocksLUT[activeLocksLUTLoc].second.clear();
   }

   return true;
}

int Locks243Relation::highestSetBit(vector<int>& input, int& index) const {
   int returnValue = bitIndex % 5;
   if (returnValue == 0) {
      if (bitIndex == index * 5) {
         return 0;
      }
      else {
         return 5;
      }
   }
   return returnValue;
   
   /* //old version follows
   // int initIndex = index - 1;
   // int returnValue = 1;
   // while (initIndex != index) {
      // initIndex = index;
      // returnValue = 1;
      // if (input.at(index) == 0) returnValue = 0;
      // else if (input.at(index) % 3 != 0) returnValue = 5;
      // else if (input.at(index) % 9 != 0) returnValue = 4;
      // else if (input.at(index) % 27 != 0) returnValue = 3;
      // else if (input.at(index) % 81 != 0) returnValue = 2;
   // //   else returnValue = 1; //redundant
      
      // int loc = index * 5 + returnValue;
      // while (activeLocks[loc]) {
         // returnValue--;
         // loc--;
         // if (loc <= 0) break; //TODO: Dunno if necessary.
      // }
      // //adjust for if we changed layers
      // while (returnValue < 0) {
         // index--;
         // returnValue+=5;
      // }
      // if (index < 0) return 0;
   // }
   
   // return returnValue;
   */
}

int L243_HSB[244] = {0, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2, 
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2,
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 1,
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2, 
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2,
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 1,
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2, 
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 2,
                        5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 3, 5, 5, 4, 5, 5, 4, 5, 5, 1};

int Locks243Relation::highestSetBit(int input) const {
   return L243_HSB[input];
   /*
   int returnValue = 1;
   if (input == 0) returnValue = 0;
   else if (input % 3 != 0) returnValue = 5;
   else if (input % 9 != 0) returnValue = 4;
   else if (input % 27 != 0) returnValue = 3;
   else if (input % 81 != 0) returnValue = 2;
   return returnValue*/
      
}

void Locks243Relation::initializePointers(vector<vector<int> >& pastS01s, GenericIntTrie* pTrie) {
   mPastS01s = &pastS01s;
   mCdb = pTrie;
}

void Locks243Relation::initializeInput(vector<int>& input) {
   input.resize(_LAYERS, 0);
   if (locksLUT[0].size()) {
      for (int j : locksLUT[0]) {
         int value = writeToInput(input, j);
         activeLocks[std::abs(j)] = value;
         activeLocksLUT[0].first = 0;
         activeLocksLUT[0].second.insert(j);
         reverseActiveLocksLUT[j] = 0;;
      }
   }
   mPastData.resize(_LAYERS * 5 + 1);
   activeLocksLUTLoc = 1;
}

void Locks243Relation::addChainsToLocksLUT(int source, int destination) {
   if (locksLUT[destination].size()) { //if there is chaining
      for (int j : locksLUT[destination]) {
         if (!locksLUT[source].count(j)) { //if does not already exist
            addToLocksLUT(source, j);
         }
      }
   }
}

void Locks243Relation::addReverseChainsToLocksLUT(int source, int destination) {
   if (reverseLocksLUT[source].size()) { //if there is chaining
      for (int j : reverseLocksLUT[source]) {
         if (!locksLUT[j].count(source)) { //if does not already exist
            addToLocksLUT(j, source);
         }
      }
   }
}

void Locks243Relation::checkNonselfContradictions(int source, int destination) {
   if (reverseLocksLUT[-1*destination].size()) {
      for (int j : reverseLocksLUT[-1 * destination]) {
         if (j != -1 * source) {
            int min = (std::abs(source) < std::abs(j) ? source : j);
            int max = (std::abs(source) < std::abs(j) ? j : source);
            if (!locksLUT[min].count(-1 * max)) {
               //std::cout << "Combining " 
               //   << source << ", " << destination 
               //   << " with " << j << "," << -1*destination 
               //   << " to get " << min << "," << max << ".\n";
               addToLocksLUT(min, -1 * max);
            }
         }
      }
   }
}

int Locks243Relation::mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower) {
   // std::cout << "indexLower: " << indexLower << std::endl;
   int il2 = highestSetBit(output.at(index));

   //this is no longer necessary due to improvements.
   // if (!isPermitted(output, index, indexLower, il2)) {
      // if (index == 0 && indexLower == 0) {
         // index = -1;
         // return -1;
      // }
      // return 0;
   // }
   
   performShrinkage(input, output, index);

   
   // if (indexLower >= 1) {
      // // std::cout << "il2: " << il2 << std::endl;
      // if (il2 < indexLower) {
         // setCap(il2);
         // for (; indexLower > il2; indexLower--) {
            // int tempIgnored = 0;
            // popOne(input, tempIgnored, index);
            // //commented line is equiv in B121, but not children
            // //input.at(index) = (input.at(index) - 1 ) / 3; 
         // }
         // removeCap();
      // }
   // }
   // // std::cout << "IndexLower is : " << indexLower << std::endl;
   // //if there's a layer skip, handle it
   // if (indexLower < 1 ) {
     // // output.at(index) = 0; //TODO: IS THIS SAFE?!
      // for (index = index-1; index >= 0; index--) {   
         // // std::cout << "Performing layer skip over " << index << std::endl;
        // layerSkipFlat(input.at(index), output.at(index), input.at(index));
        
         // if (input.at(index)<=_NULLED) {
            // repairLocks(input, index, 4, 0);
            // continue;
         // }
         
         // repairLocks(input, index, 4, updateBitIndex(input, index));
         
         // output.at(index + 1) = -1;
         // // std::cout << "Exiting layer skips.\n";
         // break;
      // } //end for(indexUpper)
      // //Check to see if we cleared it
      
      if (index < 0) {
         //we're done
         return -1;
      }
      
      //insert if "good"
      //TESTING: insert often
 //     if (output.front() < shift) {
      if (index+1 < output.size()) {
         output.at(index + 1) = -1;
      }
      if (getLambdaCount(output, index) + (output.size() - index) > output.size() * ratio) {
         bool result = cdb->insert(output);
      }
      
   // } //end if(layer skip)    

   return 0;
}

void Locks243Relation::checkSelfContradictions(int source, int destination) {
   if (locksLUT[source].count(destination*-1)) {
      //exists self-contradiction
      if (!locksLUT[0].count(-1*source)) {
         addToLocksLUT(0, -1 * source);
      }
      //for now, we'll assume we're not being giving anything UNSAT.
   }
}

void Locks243Relation::addToLocksLUT(int source, int destination) {
   // std::cout << "Lock added: " << source << " to " << destination << ".\n";
   //if already contained, skip
   // if (locksLUT[source].count(destination)) {
      // return;
   // }
   locksLUT[source].insert(destination);
   reverseLocksLUT[destination].insert(source);
   addChainsToLocksLUT(source, destination);
   addReverseChainsToLocksLUT(source, destination);
   checkNonselfContradictions(source, destination);
   checkSelfContradictions(source,destination);
}

int Locks_outputPopMatrix[5][243] = {
   {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
   {0, 0, 0, 3, 3, 3, 6, 6, 6, 9, 9, 9, 12, 12, 12, 15, 15, 15, 18, 18, 18, 21, 21, 21, 24, 24, 24, 27, 27, 27, 30, 30, 30, 33, 33, 33, 36, 36, 36, 39, 39, 39, 42, 42, 42, 45, 45, 45, 48, 48, 48, 51, 51, 51, 54, 54, 54, 57, 57, 57, 60, 60, 60, 63, 63, 63, 66, 66, 66, 69, 69, 69, 72, 72, 72, 75, 75, 75, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 94, 94, 94, 97, 97, 97, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120, 123, 123, 123, 126, 126, 126, 129, 129, 129, 132, 132, 132, 135, 135, 135, 138, 138, 138, 141, 141, 141, 144, 144, 144, 147, 147, 147, 150, 150, 150, 153, 153, 153, 156, 156, 156, 159, 159, 159, 162, 162, 162, 165, 165, 165, 168, 168, 168, 171, 171, 171, 174, 174, 174, 177, 177, 177, 180, 180, 180, 183, 183, 183, 186, 186, 186, 189, 189, 189, 192, 192, 192, 195, 195, 195, 198, 198, 198, 201, 201, 201, 204, 204, 204, 207, 207, 207, 210, 210, 210, 213, 213, 213, 216, 216, 216, 219, 219, 219, 222, 222, 222, 225, 225, 225, 228, 228, 228, 231, 231, 231, 234, 234, 234, 237, 237, 237, 240, 240, 240},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 18, 18, 18, 18, 18, 18, 18, 18, 18, 27, 27, 27, 27, 27, 27, 27, 27, 27, 36, 36, 36, 36, 36, 36, 36, 36, 36, 45, 45, 45, 45, 45, 45, 45, 45, 45, 54, 54, 54, 54, 54, 54, 54, 54, 54, 63, 63, 63, 63, 63, 63, 63, 63, 63, 72, 72, 72, 72, 72, 72, 72, 72, 72, 81, 81, 81, 81, 81, 81, 81, 81, 81, 90, 90, 90, 90, 90, 90, 90, 90, 90, 99, 99, 99, 99, 99, 99, 99, 99, 99, 108, 108, 108, 108, 108, 108, 108, 108, 108, 117, 117, 117, 117, 117, 117, 117, 117, 117, 126, 126, 126, 126, 126, 126, 126, 126, 126, 135, 135, 135, 135, 135, 135, 135, 135, 135, 144, 144, 144, 144, 144, 144, 144, 144, 144, 153, 153, 153, 153, 153, 153, 153, 153, 153, 162, 162, 162, 162, 162, 162, 162, 162, 162, 171, 171, 171, 171, 171, 171, 171, 171, 171, 180, 180, 180, 180, 180, 180, 180, 180, 180, 189, 189, 189, 189, 189, 189, 189, 189, 189, 198, 198, 198, 198, 198, 198, 198, 198, 198, 207, 207, 207, 207, 207, 207, 207, 207, 207, 216, 216, 216, 216, 216, 216, 216, 216, 216, 225, 225, 225, 225, 225, 225, 225, 225, 225, 234, 234, 234, 234, 234, 234, 234, 234, 234},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 27, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 54, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 135, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 189, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216, 216},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162, 162}
};

//Adjusts the final element(s) from a expanded 5-digit to simulate having fewer
//it does so by replacing the last (5-finalDegree) elements with 0's.
void Locks243Relation::outputPop(vector<int>& input, int& index) const {
   input.at(index) = Locks_outputPopMatrix[finalDegree][input.at(index)];
}

void Locks243Relation::fixMaxDepth(int& maxDepth) const {
   for (int i = bitIndex; i >= (maxDepth+1)*5; i--) {
      if (activeLocks[i]) {
         maxDepth = (i - 1) / 5;
         return;
      }
   }
}

void Locks243Relation::checkForAltOutput(vector<int>& input, int& index, vector<int>& output) {
   if (mPrevSource == bitIndex + 1) {
      //keep standard output
      return;
   }
   else {
      // std::cout << "Start: "; printBox(output);
      for (int i = mPrevSource; i > bitIndex; i--) {
         int dest = i;
         int sign = 1;
         if (!reverseActiveLocksLUT.count(dest)) {
            sign = -1;
            if (!reverseActiveLocksLUT.count(dest * sign)) {
               // std::cout << "Abort: lock source passed" << std::endl;
               continue;
            }
         }
         int source = reverseActiveLocksLUT[dest * sign];
         
         int tempBI = bitIndex;
         bitIndex = std::abs(source);
         
         int temp = 0;
         int tempIndex = (bitIndex - 1) / 5;
         // std::cout << "Reassigning " << source << std::endl;
         popOneCore(output, temp, tempIndex);
         writeToInput(output, source, 1);
         
         bitIndex = tempBI;
      }
      // std::cout << "End: "; printBox(output);
   }
}