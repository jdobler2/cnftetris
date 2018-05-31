//BigOr243Trie.cpp

#include "BigOr243Trie.h"
#include "Base243InnerGIAT.h"
#include "B243BunchedInnerGIAT.h"
#include <math.h>
#include "varMap.h"
#include <set>

#define LIST_SIZE 1024

constexpr int BigOr243Trie::lambdaLUT[243];

BigOr243Trie::BigOr243Trie(int layers, int lockBoundary) {
   //TODO: Specialized?
   head.reset(new Base243InnerGIAT());  
   
   
   lists.resize(layers);
   listSizes.resize(layers);
   for (int i = 0; i < lists.size(); i++) {
      lists.at(i).reserve(LIST_SIZE);
      listSizes.at(i).resize(lists.size()); //`i` should be safe, but w/e
   }
   
   prevInput.resize(layers, -1);
   mData.resize(layers, 0);
   mData2.resize(layers, 0);
   mData3.resize(layers, 0);
   
   mUseSingleton = gvars.getBool(SINGLETON);
   if (mUseSingleton) {
      mLockBoundary = lockBoundary;
   } else {
      mLockBoundary = 0;
   }
}

int BigOr243Trie::insertShort(const vector<int>& box, const vector<int>& raw) {
   // if (mUseShorts && raw.size() <= 2) {
      // // std::cout << "Raw size is " << raw.size() << std::endl;
      // int index = 0;

      // int loc = mShort_boxes.size();
      // mShort_boxes.push_back(std::make_pair(raw.size(), box));
      
      // for (int i = 0; i < raw.size(); i++) {
         // int bitLoc = std::abs(raw[i]) * 2;
         // if (raw[i] < 0) {
            // bitLoc -= 2;
         // }
         // else {
            // bitLoc -= 1;
         // }
         
         // // std::cout << "Assigning raw of " << raw[i] << " to " << bitLoc << std::endl;

         
         // mShort_lut[bitLoc].push_back(loc);
         // mShort_bits[bitLoc/64] |= 1ull << (63 - (bitLoc % 64));
         
      // }
      
      // return INSERT_SUCCESSFUL;
   // }
   return insert(box);
}

int BigOr243Trie::insert(const vector<int>& box) {
   
   if (box.back() == -2) {
      return -1;
   }
   
   //old version, reinserted to simplify for the  moment.
   for (int i = 0; i < lists.size(); i++) {
      lists.at(i).resize(0);
      prevInput[i] = -1;
      for (int j = 0; j < listSizes.at(i).size(); j++) {
         listSizes.at(i).at(j) = 0;
      }
   }
   
   /*int firstActiveLayer = 0;
   while (box.at(firstActiveLayer)==0) {
      firstActiveLayer++;
   }
   if (firstActiveLayer > 0) {
      if (zeroLists[firstActiveLayer].count(box.at(firstActiveLayer))) {
         return zeroLists[firstActiveLayer][box.at(firstActiveLayer)]->insert(box);
      }
      else {
         zeroLists[firstActiveLayer].insert(std::make_pair(
            box.at(firstActiveLayer),
            std::unique_ptr<ChildClass>(new Base243InnerGIAT(firstActiveLayer))
         ));
         int value = zeroLists[firstActiveLayer][box.at(firstActiveLayer)]->insert(box);
         return value;
      }
   }*/
   
   ChildClass* firstNew = NULL;
   int firstNewsLayer = -1;
   int result;
   //return head->insert(box);
   return head->insert(box, firstNewsLayer, firstNew);
   
   
   
   if (firstNewsLayer <= activeLoc) {
      if (firstNew != NULL) {
      //   std::cout << "initSize: " << lists.at(firstNewsLayer).size() << std::endl;
         int destLayer = firstNew->getMyLayer();
         int sourceLayer = 0;
         for (int i = destLayer - 1; i > 0; i--) {
            if (box.at(i)!=0) {
               sourceLayer = i; break;
            }
         }
      //   std::cout << "DestLayer is " << destLayer;
      //   std::cout << " SourceLayer: " << sourceLayer <<" activeLoc: " << activeLoc << std::endl;
         resetLists(destLayer, box);
         prevInput = box;
         lists.at(destLayer).push_back(firstNew);
         for( ; sourceLayer <= destLayer ; sourceLayer++) {
            listSizes.at(destLayer).at(sourceLayer)++;
         }
      //   std::cout << "AfterSize: " << lists.at(firstNewsLayer).size() << std::endl;
         return result;
      }
      else {
         //fall through to old version
      }
   }      
   
   
         //old way
         // int destLayer = firstNew->getMyLayer();
         // std::cout << "DestLayer is " << destLayer;
         // std::cout << " FirstNewsLayer: " << firstNewsLayer <<" activeLoc: " << activeLoc << std::endl;

         // int relativeSize = listSizes.at(destLayer).at(firstNewsLayer);
         // if (relativeSize == lists.at(destLayer).size()) {
            // lists.at(destLayer).push_back(firstNew);
            // for (; firstNewsLayer < destLayer && firstNewsLayer < activeLoc; firstNewsLayer++) {
               // listSizes.at(destLayer).at(firstNewsLayer)++;
            // }
         // }
         // else { //...Do we really need to separate this out?
            // std::cout << "Going to " << destLayer << " from " << firstNewsLayer << "; active set to " << activeLoc << std::endl;

            // lists.at(destLayer).insert(lists.at(destLayer).begin() + listSizes.at(destLayer).at(firstNewsLayer), firstNew);
            // for (; firstNewsLayer < destLayer && firstNewsLayer < activeLoc; firstNewsLayer++) {
               // listSizes.at(destLayer).at(firstNewsLayer)++;
            // }
         // }
         // if (firstNewsLayer < activeLoc) {
            // std::cout << "\tResetting..." << std::endl;
            // resetLists(firstNewsLayer, box);
         // }
         
         // prevInput = box;
      // }
      // else {
         // std::cout << "Hard reset!" << std::endl;
         // resetLists(firstNewsLayer, box);
      // }
   // }
   // if (result < 0) std::cout << "Result is " << result << std::endl;
   // return result;
   
   //old version, kept for reference
   for (int i = 0; i < lists.size(); i++) {
      lists.at(i).resize(0);
      prevInput[i] = -1;
      for (int j = 0; j < listSizes.at(i).size(); j++) {
         listSizes.at(i).at(j) = 0;
      }
   }
      return result;

   // return head->insert(box, firstNewsLayer, firstNew);
}

void BigOr243Trie::resetLists(int i, const vector<int>& input) {   
   int stop = i - 1; 
   activeLoc = i;
   
   // if (stop >= 0) {
      // std::cout << "Stop is: " << stop << std::endl;
      // std::cout << "Hypo. Lists: ";
      // for (int j = 0; j < lists.size(); j++) {
         // std::cout << listSizes.at(j).at(stop) << ", ";
      // }
      // std::cout << std::endl;
   // }
   
   //if stop is -1, reset everything
   if (stop < 0) {
   //if (true) {
      i = 0; //redundant
      for (; i < lists.size(); i++) {
         lists.at(i).clear();
         prevInput[i] = input[i];
         for (int j = 0; j < listSizes.at(i).size(); j++) {
            listSizes.at(i).at(j) = 0;
         }
      }
      activeLoc = 0; //also redundant
      return;
   }
         // if (input.at(lists.size() - 1) == 121) {
            // std::cout << "List sizes checkpoint at: "; printBox(input);
         // }
         

         
   for (; i < lists.size(); i++) {
      int presize = lists.at(i).size();
      lists.at(i).resize(listSizes.at(i).at(stop));
      
      // if (lists.at(i).size() > presize) {
         // std::cout << "W:LKJAT:LKJAE:TLK" << std::endl;
         // std::cout << "i is " << i << ", stop is " << stop << ", new size is " << lists.at(i).size() << ", presize is " << presize << std::endl;
      // }
      // if (i == activeLoc && lists.at(i).size() != presize) {
         // std::cout << "Okay..." << std::endl;
         // std::cout << "i is " << i << ", stop is " << stop << ", new size is " << lists.at(i).size() << ", presize is " << presize << std::endl;
         // std::cout << "prevInput: ";printBox(prevInput);
         // std::cout << "now_Input: "; printBox(input);
      // }
      
      prevInput[i] = input[i];
      
      // pretty sure this is unnec.
      // for (int j = stop + 1; j < listSizes.at(i).size(); j++) {
         // listSizes.at(i).at(j) = listSizes.at(i).at(stop);
      // }
      //end unnec
      
      // if (input.at(lists.size() - 1) == 121) {
         // std::cout << lists.at(i).size() << ", ";
      // }
   }
         // if (input.at(lists.size() - 1) == 121) {
            // std::cout << std::endl << std::endl;
         // }
         
   // std::cout << "Lists at end: ";
   // for (int j = 0; j < lists.size(); j++) {
      // std::cout << lists.at(j).size() << ", ";
   // }
   // std::cout << std::endl;
   
   // string tmp;
   // std::cin >> tmp;
}

void BigOr243Trie::resetLists(const vector<int>& input) {
   //TODO: Use SIMD?
   int i;
   for (i = 0; i < activeLoc; i++) {
      if (input.at(i) != prevInput.at(i)) {
         break;
      }
   }
   
   resetLists(i, input);
}

bool BigOr243Trie::contains(const vector<int>& box, vector<int>& output) {
   //return head->contains(box, output);
   //TODO: update everything to shared pointers so this isn't awful
   // if (mUseShorts) {
      // int maxDepth = 0;
      // if (containsShorts(box, output, maxDepth, CONTAINS_MODE)) {
         // return true;
      // }
   // }
   resetLists(box);
   
   lists[0].push_back(head.get());
   activeLoc--;
   //activeLoc = -1;
   int loc;
    __m256i link;
    
   while (activeLoc < _LAYERS - 1) {
      
      activeLoc++;
      loc = box.at(activeLoc);
      
      if (lists[activeLoc].size() == 0) {
         updateListSizes(activeLoc);
         continue;
      }
      link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
      
      if (getWords(link, activeLoc, dummy, output, CONTAINS_MODE)) {
         return true;
      }
      //else, continue forth!
      if (activeLoc + 1 != box.size()) {
         int dummy = UNUSED;
         getChildren(link, activeLoc, dummy);
      } //end if can exist children
      else { //we have a killCommand
         break;
      }
   }
   // std::cout << "Failed to find. " << std::endl;
   
   return false;
}

void BigOr243Trie::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord,
                  int& maxDepth) 
{
   // std::cout << "Input: "; printBox(input);
   // std::cout << "PrevI: "; printBox(prevInput);
   // std::cout << "Init. Lists: ";
   // for (int j = 0; j < lists.size(); j++) {
      // std::cout << lists.at(j).size() << ", ";
   // }
   // std::cout << std::endl;
   
   // if (mUseShorts) {
      // vector<int> dummy;
      // if (containsShorts(input, dummy, maxDepth, GACB_MODE)) {
         // output.push_back(dummy);
         // return;
      // }
   // }
   resetLists(input);
   
   lists[0].push_back(head.get());
   activeLoc--;
   //activeLoc = -1;
   int loc;
   uint64_t dest[4];
   __m256i link;
   
   mSingletonSource = -1;
   int remaining = FIRST_TIME;
   if (!mUseSingleton) remaining = UNUSED;
   
   bool wordFound = false;
   
   while (activeLoc < _LAYERS - 1 - mLockBoundary) {
      activeLoc++;
      loc = input.at(activeLoc);
      if (lists[activeLoc].size() == 0) {
      //   std::cout << "Layer " << layer << " is empty. " << std::endl;
         updateListSizes(activeLoc);
         continue;
      }
      if (activeLoc > maxDepth) maxDepth = activeLoc;
      link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);

      if (getWords(link, activeLoc, output, prevWord, GACB_MODE)) {
         wordFound = true;
         return;
      }
      
      if (activeLoc + 1 != input.size()) {
         getChildren(link, activeLoc, remaining);
         if (mSingletonSource >= 0) {
            //once a singleton's found, we want to shortcut by handling it as a singleton.
            return;
         }
      }
      else { //we have a killCommand
         break;
      }
   }
   
   //handle locked layers
   //note that, if we found a "real" singleton source, we Returned already.
   if (mLockBoundary > 0 && mUseSingleton) {
      // std::cout << "\nNew set\n";
      int count = 0;
      int index = _LAYERS - mLockBoundary;
      vector<int> outputVector(prevWord);
      
      std::vector<std::set<int> > foundVars(_LAYERS);
      for(int i = activeLoc+1; i < _LAYERS; i++) {
         for (auto& t : lists[i]) {
            // std::cout << "Path:"; printBox(t->getPathToThis());
            // if (t->getWordList().size() != t->getNumberInserted()) {
               // std::cout << "\t\tWHAT THE FUCKETY FUCK?!" << std::endl;
               // std::cout << "InsertedCount: " << t->getNumberInserted() << std::endl;
               // std::cout << "WordBits are ";
               // for (int i = 0; i < 4; i++) {
                  // std::cout << t->getWordBitsPtr()[i] << " ";
               // }
               // std::cout << std::endl;
               // std::cout << "ChildBits are ";
               // for (int i = 0; i < 4; i++) {
                  // std::cout << t->getChildBitsPtr()[i] << " ";
               // }
               // std::cout << std::endl;
            // }
            
            //!TODO: Reset *SHOULD* stop this from redundancy-ing, but... Not 100% sure.
            if (t->get243Child(0)!=NULL) {
               lists[t->get243Child(0)->getMyLayer()].push_back(t->get243Child(0));
            }
           for (int value : t->getWordList()) {
              // std::cout << "\t: " << value << std::endl;
            //int value = t->getPathToThis().at(t->getMyLayer());
            int flippedValue = getFlipped(value);
            if (flippedValue < 0) {
               std::cout << "Box is: "; printBox(t->getPathToThis());
               std::cout << "layerGet: " << t->getMyLayer() << "; i: " << i << std::endl;
            }
           
            if (foundVars.at(t->getMyLayer()).count(value)) {
               int indexLessOne = index - 1;
               mergeBoxesFlat(outputVector, t->getPathToThis(), indexLessOne);
               continue;
            }
            //check for, handle contradictions
            else if (foundVars.at(t->getMyLayer()).count(flippedValue)) {
               // std::cout << "Contradiction!" << std::endl;
               for (int j = 0; j < index; j++) {
                  prevWord.at(j) += t->getPathToThis().at(j);
               }
               //find and set prevword for contradictor
               for (auto t2 : lists[i]) {
                  for (int kk : t2->getWordList()) {
                     if (kk == flippedValue) {
                        //for (int j = 0; j < _LAYERS - mLockBoundary; j++) {
                           int indexLessOne = index - 1;
                           mergeBoxesFlat(prevWord, t2->getPathToThis(), indexLessOne);
                          // if (t2->getPathToThis().at(j) !=0) { 
                           //TODO: this breaks if duplicated
                            //  prevWord.at(j) += t2->getPathToThis().at(j);
                           //}
                        //}
                        goto postFlipFound; //break outer
                     }
                  }
               }
               std::cout << "ERROR: FLIP NOT FOUND" << std::endl;
            postFlipFound:
               int finalLoc = index;
               while (prevWord.at(finalLoc) == 0) {
                  finalLoc--;
               }
               prevWord.at(++finalLoc) = -1;
               output.push_back(prevWord);
               return;
            }
            else {
               int indexLessOne = index - 1;
               mergeBoxesFlat(outputVector, t->getPathToThis(), indexLessOne);

               count++;
               foundVars.at(t->getMyLayer()).insert(value);
            }
           }
         }
      }
    //  std::cout << "Setting..." << std::endl;
      // std::cout << "\nAdded ";
      // for (int i = 0; i < foundVars.size(); i++) {
         // for (auto it : foundVars.at(i)) {
            // std::cout << i << "." << it << ", ";
         // }
      // }
      // std::cout << std::endl;
      mSingletonSource = _LAYERS - mLockBoundary; 
      mPartialLambda = count;
      mCandidate = NULL;
      prevWord = outputVector;
      int finalLoc = index;
      while (prevWord.at(finalLoc) == 0) {
         finalLoc--;
      }
      prevWord.at(++finalLoc) = -2;
   }
  
}

int BigOr243Trie::getFlipped(int input) {
   switch(input) {
      case 1:
         return 2;
      case 2:
         return 1;
      case 3:
         return 6;
      case 6:
         return 3;
      case 9:
         return 18;
      case 18:
         return 9;
      case 27:
         return 54;
      case 54:
         return 27;
      case 81:
         return 162;
      case 162:
         return 81;
      default:
         std::cout << "ERROR: getFlipped: Cannot handle " << input << std::endl;
         return -1;
   }
}

void convertToShort(const vector<int>& input, vector<uint64_t>& output) {
   int index = 0;
   for (int i = 0; i < input.size(); i++) {
      if (input.at(i) < 0) break;
      // if (input.at(i) == 0) {
         // index+=2;
         // continue;
      // }
      vector<int> data (5, 0);
      int value = input.at(i);
      for (int j = 4; j >= 0; j--) {
         data[j] = value % 3;
         value /= 3;
      }
      for (int j = 0; j < data.size(); j++) {
         if (data[j] == 1) {
            // std::cout << input[i] << " gets a bit set at " << index << std::endl;
            output[index/64] |= 1ull << (63 - (index % 64));
         }
         else if (data[j] == 2) {
         // std::cout << input[i] << " gets a bit set at " << index+1 << std::endl;
            output[index/64] |= 1ull << (62 - (index % 64));
         }
         index+=2;
      }
   }
}

int BigOr243Trie::containsShorts(const vector<int>& input,
                  vector<int>& output,
                  int& maxDepth,
                  int mode) 
{
   // vector<uint64_t> inputAsShort(mShort_bits.size());
   // convertToShort(input, inputAsShort);
   // // std::cout << "Input as short: ";
   // // for (int i = 0; i < inputAsShort.size(); i++) {
      // // std::cout << inputAsShort[i] << ", ";
   // // }
   // // std::cout << std::endl;
   // // std::cout << "Bits: ";
   // // for (int i = 0; i < mShort_bits.size(); i++) {
      // // std::cout << mShort_bits[i] << ", ";
   // // }
   // // std::cout << std::endl;
   
   // __m256i input1, input2, result;
   // uint64_t dest[4];
   
   // std::unordered_map<int, int> counts;
   
   // for (int i = 0; i < mShort_bits.size(); i+=4) {
      // input1 = _mm256_loadu_si256((__m256i*) (inputAsShort.data() + i));
      // input2 = _mm256_loadu_si256((__m256i*) (mShort_bits.data() + i));
      // result = _mm256_and_si256(input1, input2);
      // _mm256_store_si256((__m256i*)dest, result);
      
      // for (int j = 0; j < 4; j++) {
         // while (dest[j] != 0) {
            // int lzc = __builtin_clzll(dest[j]);
            // int val = 64 * (i + j) + lzc;
            // maxDepth = (((val - 1) / 2) / 5);
            // dest[j] ^= (1ull << (63 - lzc)); //clear the searched output point
            
            // // std::cout << "Val of " << val << " detected." << std::endl;
            // // std::cout << "does the shortlut exist? count says " << mShort_lut.count(val) << std::endl;
            
            // for (int i : mShort_lut[val]) {
               // if (counts.count(i)) {
                  // counts[i]++;
               // }
               // else {
                  // counts[i] = 1;
               // }
               // if (counts[i] >= mShort_boxes[i].first) {
                  // output = mShort_boxes[i].second;
                  // return true;
               // }
            // }
         // }
      // }

   // }
   
   return false;
}
              

int BigOr243Trie::getWords(__m256i& link, int& layer,
                    vector<vector<int> >& setOfOutputs, vector<int>& output,
                    int mode)
{
   __m256i bigOr, data, and_result;
   uint64_t dest[4];
   uint64_t dest2[4];
   
   auto it = lists[layer].begin(); //assert: begin != end
   // bigOr = _mm256_loadu_si256((__m256i*) ((*it)->getWordBitsPtr()));
   
   // it++;
   while (it != lists[layer].end()) {
      data = _mm256_loadu_si256((__m256i*) ((*it)->getWordBitsPtr()));
      bigOr = _mm256_or_si256(bigOr, data);
      it++;
   }
   
   and_result = _mm256_and_si256(link, bigOr);
   __m256i zero256 = _mm256_setzero_si256();
   __m256i compareEqual = _mm256_cmpeq_epi64(and_result, zero256);
   int mask = _mm256_movemask_epi8(compareEqual);
   if (mask==0xFFFFFFFF) {
      return false;
   }
   
   //find location of first set bit in and_result
   _mm256_store_si256((__m256i*)dest, and_result);

   for (int i = 0; i < 4; i++) {
      while (dest[i]!=0) {
         int lzc = __builtin_clzll(dest[i]);
         int val = 64 * i + lzc;
         
         for(it = lists[layer].begin(); it != lists[layer].end(); it++) {
            if ((*it)->getWordBit(val)) {
               vector<int> path = (*it)->getPathToThis();
               for (int j = 0; j < layer; j++) { 
                  output.at(j) = path.at(j);
               }
               output.at(layer) = val;
               if (mode == GACB_MODE) {
                  output.at(layer + 1) = -1;
                  setOfOutputs.push_back(output);
               }
               else { //mode == CONTAINS_MODE
                  return true;
               }
            }//end if(word)
         }//end for loop
      
         dest[i] ^= (1ull << (63 - lzc)); //clear the searched output point
      }//end while loop
   }//end outer for
   return setOfOutputs.size(); //in CONTAINS_MODE, == false
}

//NONE OF THIS WORKS.
bool BigOr243Trie::searchForSingleton(vector<int>& input, int& maxDepth, int& numSolutions) {
   //bit lazy here, but should be fine-ish
   //ASSERT: lists[maxDepth].size() >= 0
   //(we don't currently know how to deal with fat layers)
   if (lists[maxDepth].size() > 1 && lists[maxDepth].front()->getInsertedCount()==1) { 
      return false;
   }
   singletonCandidate.resize(_LAYERS+1);
   int splitDepth = maxDepth - 1;
   while (lists[splitDepth].size() == 0) { 
      splitDepth--;
   }
         
   //I'm not sure why I thought this was right before?
   //vector<int> path = lists[splitDepth].front()->getPathToThis();
   int i;
   for (i = 0; i <= splitDepth; i++) {
      //singletonCandidate[i] = path[i]; //ditto (TODO: can I use the candidate's?)
      singletonCandidate[i] = input[i];
   }
   for (i = splitDepth + 1; i <= maxDepth; i++) {
      singletonCandidate[i] = 0;
   }
   singletonCandidate[i+1] = -1;
   
   //figure out numSolutions
   int lambdaCount = getTotalLambdaCount(lists[maxDepth].front()->getPathToThis(), splitDepth+1);
   numSolutions = 1 << lambdaCount;
   
   //bookkeeping
   greatestSingletonDepth = maxDepth;
   maxDepth = splitDepth;
   
   return true;
}


int BigOr243Trie::getTotalLambdaCount(const vector<int>& path, int start) {
   int totalLambdas = 0;
   for (int i = start; i < path.size(); i++) {
      totalLambdas += lambdaLUT[path.at(i)];
   }
   
   return totalLambdas;
}

void BigOr243Trie::updateListSizes(int& layer) {

   for (int i = layer+1; i < lists.size(); i++) {
      listSizes[i][layer] = lists[i].size();
   }
}

void BigOr243Trie::getChildren(
   __m256i& link,
   int& layer,
   int& remaining)
{
   double current = mData[layer] * mData2[layer];
   current += lists[layer].size();
   mData2[layer]+=1.0;
   mData[layer] = current / mData2[layer];
   if (mData3[layer] < lists[layer].size()) mData3[layer] = lists[layer].size();
   
   if (remaining == UNUSED) {
      //do nothing
   }
   else if (remaining == FIRST_TIME) { //count number PAST this layer
    //  std::cout << "First time detected; layer is " << layer << "." << std::endl;
      remaining = 0;
      for (int i = layer + 1; i < _LAYERS - 1; i++) {
         remaining += lists[i].size();
      }
   //   std::cout << "Remaining initialized to " << remaining << std::endl;
   }
   else { //remove this layer's from remaining
      remaining -= lists[layer].size();
   //   std::cout << "Layer " << layer << "; Remaining updated to " << remaining << std::endl;
   }
   //ASSERT: remaining is set up or set to ignored.
   
   __m256i bigOr, data, and_result;
   uint64_t dest[4];
   
   // for (int startVal = 0; startVal < lists[layer].size(); startVal+=LIST_SIZE) {
      //int z = 0; //startVal;
      //bigOr = _mm256_loadu_si256((__m256i*) (lists[layer][z]->getChildBitsPtr()));
      auto it = lists[layer].begin();
      //z++;
      while (it != lists[layer].end()) {
         data = _mm256_loadu_si256((__m256i*) ((*it)->getChildBitsPtr()));      
         bigOr = _mm256_or_si256(bigOr, data);
         it++;
      }
      
      and_result = _mm256_and_si256(link, bigOr);
      __m256i zero256 = _mm256_setzero_si256();
      __m256i compareEqual = _mm256_cmpeq_epi64(and_result, zero256);
      int mask = _mm256_movemask_epi8(compareEqual);
      if (mask==0xFFFFFFFF) {
         //no children
         updateListSizes(layer);
         return;
         // continue;
      }
   
      _mm256_store_si256((__m256i*)dest, and_result);
      
      Base243GIAT* candidate = NULL;
      int val = -1;
      vector<int> valList;
      valList.reserve(256);
      
      for(int i = 0; i < 4; i++) {
         while (dest[i]!=0) {
            //note that we prefer higher numbers on searching children
            int tzc = __builtin_ctzll(dest[i]);
            int val = 64 * (i) + (63 - tzc);
            valList.push_back(val);
            
            //TODO: Used mixed tests thingy (syphilis thingy) to do faster than a linear search
            for(auto it = lists[layer].begin(); it != lists[layer].end(); it++) {
               //BUNCHED CHANGE POINT!!!
               //(*it)->add243Children(lists, val, remaining);
               candidate = (*it)->get243Child(val);
               if (candidate != NULL) {
                  lists[candidate->getMyLayer()].push_back(candidate);
                  remaining++;
               }
            }
            
            dest[i] ^= (1ull << (tzc)); //clear the searched output point
         }
      }
      
      //handle singleton stuff
      if (remaining == 1) {
         if (mSingletonSource == -1) //if we haven't found a singleton
         {
            if (candidate != NULL) {  
               if (candidate->getInsertedCount()==1 &&  //if it's a singleton
                  (candidate->getMyLayer() > layer + 1 || candidate->getStatus()!=GIAT_STATUS_WORD_ONLY))  //if it's a "real" singleton
               {
                 // std::cout << "Setting (started with " << lists[layer].size() << "; matched " candidate->)..." << std::endl;
                  mSingletonSource = layer+1;
                  mCandidate = &candidate->getPathToThis();

                  mPartialLambda = 0;
                  _mm256_store_si256((__m256i*)dest, bigOr);
                  for (int zz = 0; zz < 4; zz++) {
                     while (dest[zz]!=0) {
                        int tzc = __builtin_ctzll(dest[zz]);
                        int val = 64 * (zz) + (63 - tzc);
                        int newLC = getEndLambdaCount(val);
                        if (newLC < mPartialLambda) {
                           mPartialLambda = newLC;
                           if (newLC == 0) break;
                        }
                        dest[zz] ^= (1ull << (tzc)); //clear the searched output point

                     }
                  }
               }
            }
            
            else { //singleton, but the sole remainer is on another floor!
               int layerCopy = layer;
               while (!lists[++layer].size()) {} //advance to layer with the remaining one.
               candidate = lists[layer][0];
               if (candidate->getInsertedCount()==1 &&
                     (candidate->getStatus()!=GIAT_STATUS_WORD_ONLY || candidate->getMyLayer() > layerCopy + 1)) 
               {
                  mSingletonSource = layerCopy+1;
                  mCandidate = &candidate->getPathToThis();
                  mPartialLambda = 5;
                  _mm256_store_si256((__m256i*)dest, bigOr);
                  for (int zz = 0; zz < 4; zz++)
                  while (dest[zz]!=0) {
                     int tzc = __builtin_ctzll(dest[zz]);
                     int val = 64 * (zz) + (63 - tzc);
                     int newLC = getEndLambdaCount(val);
                     if (newLC < mPartialLambda) {
                        mPartialLambda = newLC;
                        if (newLC == 0) break;
                     }
                     dest[zz] ^= (1ull << (tzc)); //clear the searched output point

                  }

               }
               else {
                  layer--;
               }
            }
         }
       } //else if (remaining == 2 && mSingletonSource == -1) {
         // int layerCopy = layer;
         
         // //get, handle first one.
         // while (!lists[++layer].size()) {} //advance to layer with the remaining one.
         // candidate = lists[layer][0];
         // if (candidate->getInsertedCount()==1 &&
               // (candidate->getStatus()!=GIAT_STATUS_WORD_ONLY || candidate->getMyLayer() > layerCopy + 1)) 
         // {
            // mSingletonSource = layerCopy+1;
            // mCandidate = &candidate->getPathToThis();
            // mPartialLambda = 5;
            // _mm256_store_si256((__m256i*)dest, bigOr);
            // for (int zz = 0; zz < 4; zz++)
            // while (dest[zz]!=0) {
               // int tzc = __builtin_ctzll(dest[zz]);
               // int val = 64 * (zz) + (63 - tzc);
               // int newLC = getEndLambdaCount(val);
               // if (newLC < mPartialLambda) {
                  // mPartialLambda = newLC;
                  // if (newLC == 0) break;
               // }
               // dest[zz] ^= (1ull << (tzc)); //clear the searched output point

            // }
            
         // }
         // else {
            // layer--;
         // }
      // }
   //}
   
   updateListSizes(layer);
}

int BigOr243Trie::getEndLambdaCount(int& val) {
   switch(val) {
      default: 
         return 0;
      case 0:
         return 5;
      case 3:
      case 6:
		case 12:
		case 15:
		case 21:
		case 24:
		case 30:
		case 33:
		case 39:
		case 42:
		case 48:
		case 51:
		case 57:
		case 60:
		case 66:
		case 69:
		case 75:
		case 78:
		case 84:
		case 87:
		case 93:
		case 96:
		case 102:
		case 105:
		case 111:
		case 114:
		case 120:
		case 123:
		case 129:
		case 132:
		case 138:
		case 141:
		case 147:
		case 150:
		case 156:
		case 159:
		case 165:
		case 168:
		case 174:
		case 177:
		case 183:
		case 186:
		case 192:
		case 195:
		case 201:
		case 204:
		case 210:
		case 213:
		case 219:
		case 222:
		case 228:
		case 231:
		case 237:
		case 240:
         return 1;
      case 9:
		case 18:
		case 36:
		case 45:
		case 63:
		case 72:
		case 90:
		case 99:
		case 117:
		case 126:
		case 144:
		case 153:
		case 171:
		case 180:
		case 198:
		case 207:
		case 225:
		case 234:
         return 2;
      case 27:
		case 54:
		case 108:
		case 135:
		case 189:
		case 216:
         return 3;
      case 81:
		case 162:
         return 4;
   }
}


bool BigOr243Trie::getSingletonData(int& sourceLayer, vector<int>*& candidate, int& extra) {
   //std::cout << "mSingletonSource: " << mSingletonSource << std::endl;
   if (mSingletonSource < 0) return false;
   sourceLayer = mSingletonSource;
   candidate = mCandidate;
   extra = mPartialLambda;
   return mUseSingleton;
}

BigOr243Trie::~BigOr243Trie() {
   // std::cout << "mData: ";
   // for (int i=0; i < mData.size(); i++) {
      // std::cout << mData[i] << ", ";
   // }
   // std::cout << std::endl;
   
   // std::cout << "mData3: ";
   // for (int i=0; i < mData3.size(); i++) {
      // std::cout << mData3[i] << ", ";
   // }
   // std::cout << std::endl;
}