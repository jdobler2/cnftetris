//Base243InnerGIAT.cpp

#include "Base243InnerGIAT.h"
#include <math.h>

#include <immintrin.h>

Base243InnerGIAT::Base243InnerGIAT() : branches(243) {
   myLayer = 0;
  //childBits[0] = 0;
  //childBits[1] = 0;
   for (int i = 0; i < 4; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }
   
   
}

Base243InnerGIAT::Base243InnerGIAT(int newLayer) : branches(243) {
   myLayer = newLayer;
   for (int i = 0; i < 4; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }

}

int Base243InnerGIAT::insert(const vector<int>& box) {
   if (mStatus == GIAT_STATUS_EMPTY) {
      pathToThis = box;
   }
   insertedCount++;
   
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   /*TODO
   //check for inclusion
   if (mStatus & GIAT_STATUS_WORD_ONLY) {
      __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      __m128i and_result = _mm_and_si128(link, data);
      
      uint64_t dest[2];
      _mm_storeu_si128((__m128i*)dest, and_result);
      if (dest[0]!=0 || dest[1]!=0) {
         return INSERT_PRESENT;
      }
   }//end if words present*/
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
    
   int initialLoc = loc;
   if (wordFlag) {
      /* TODO
      //TODO: precalc all this?
      int modVal = loc % 3;
      while(true) {
         if (modVal == 1) { //is a *
            //do nothing
         }
         else {
            int altLoc;
            if (modVal == 2) { 
               altLoc = loc + 1;
            }
            else { //modVal == 0 (i.e. 3)
               if (loc==0) break;
               altLoc = loc - 1;
            }
            
            //determine if sibling is set
            if ((wordBits[altLoc/64] & (1ull << (63 - altLoc % 64))) != 0) {
               //merge, which means go to the next step (so do nothing now)
               //we don't have to clear children here b/c clear on actual insert
               //will take care of it.
            }
            else {
               break;
            }
         }
         //prep next round
         loc = (loc - 1) / 3;
         modVal = loc % 3;
      } */
      
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      wordList.push_back(loc);
      //TODO: check if we filled the trie
      /*if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }*/
      //clearChildren(loc);
      //clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word TODO: Add support for skipping
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      if (branches.at(loc)==NULL) {
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < _LAYERS - 1) {
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer));
         }
         else {//if at the bottom, insert bottom-level GIAT.
            branches.at(loc).reset(new Base243GIAT(nextActiveLayer));
         }
      }
      else { //check if there's a skip we need to close
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < branches.at(loc)->getMyLayer()) {
            GenericIntTrie* currentPointer = branches.at(loc).release();
            //observe: new layer must be inner
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer)); 
            branches.at(loc)->forcedInsertAtZero(currentPointer);
         }
      }
      int status = branches[loc]->insert(box);
      /*TODO
      if (status == INSERT_MERGE_REQ) {
         //TODO: I don't like this method...
         vector<int> tempBox = box;
         tempBox[myLayer+1] = -1;
         return this->insert(tempBox);
      }*/
      return status;
   }
}   

//TODO: Merge with standard insert?
int Base243InnerGIAT::insert(const vector<int>& box, int& firstNewsLayer, Base243GIAT*& firstNew) {
   if (mStatus == GIAT_STATUS_EMPTY) {
      pathToThis = box;
   }
   insertedCount++;
   
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   /*TODO
   //check for inclusion
   if (mStatus & GIAT_STATUS_WORD_ONLY) {
      __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      __m128i and_result = _mm_and_si128(link, data);
      
      uint64_t dest[2];
      _mm_storeu_si128((__m128i*)dest, and_result);
      if (dest[0]!=0 || dest[1]!=0) {
         return INSERT_PRESENT;
      }
   }//end if words present*/
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   else if (box.at(myLayer+1) < 0) {
      return INSERT_PRESENT;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
    
   int initialLoc = loc;
   if (wordFlag) {
      /* TODO
      //TODO: precalc all this?
      int modVal = loc % 3;
      while(true) {
         if (modVal == 1) { //is a *
            //do nothing
         }
         else {
            int altLoc;
            if (modVal == 2) { 
               altLoc = loc + 1;
            }
            else { //modVal == 0 (i.e. 3)
               if (loc==0) break;
               altLoc = loc - 1;
            }
            
            //determine if sibling is set
            if ((wordBits[altLoc/64] & (1ull << (63 - altLoc % 64))) != 0) {
               //merge, which means go to the next step (so do nothing now)
               //we don't have to clear children here b/c clear on actual insert
               //will take care of it.
            }
            else {
               break;
            }
         }
         //prep next round
         loc = (loc - 1) / 3;
         modVal = loc % 3;
      } */
      
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      wordList.push_back(loc);

      
      firstNewsLayer = myLayer;
      firstNew = NULL;
      
      //TODO: check if we filled the trie
      /*if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }*/
      //clearChildren(loc);
      //clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      int status;
      if (branches.at(loc)==NULL) {
         
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < _LAYERS - 1) {
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer));
         }
         else {//if at the bottom, insert bottom-level GIAT.
            branches.at(loc).reset(new Base243GIAT(nextActiveLayer));
         }
         
         firstNewsLayer = myLayer;
         firstNew = this; //(Base243GIAT*) branches.at(loc).get();
         
         status = branches[loc]->insert(box, firstNewsLayer, firstNew);
      }
      else { //check if there's a skip we need to close
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < branches.at(loc)->getMyLayer()) {
            GenericIntTrie* currentPointer = branches.at(loc).release();
            //observe: new layer must be inner
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer)); 
            branches.at(loc)->forcedInsertAtZero(currentPointer);
         }
         status = branches[loc]->insert(box, firstNewsLayer, firstNew);

      }
      /*TODO
      if (status == INSERT_MERGE_REQ) {
         //TODO: I don't like this method...
         vector<int> tempBox = box;
         tempBox[myLayer+1] = -1;
         return this->insert(tempBox);
      }*/
      return status;
   }
}

//todo: merge
int Base243InnerGIAT::insertWeighted(const weightedBox& wbox) {
   //ASSERT: box.at(myLayer)!=-1
   vector<int> box = wbox.box;
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   /*TODO
   //check for inclusion
   if (mStatus & GIAT_STATUS_WORD_ONLY) {
      __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
      __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

      __m128i and_result = _mm_and_si128(link, data);
      
      uint64_t dest[2];
      _mm_storeu_si128((__m128i*)dest, and_result);
      if (dest[0]!=0 || dest[1]!=0) {
         return INSERT_PRESENT;
      }
   }//end if words present*/
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
    
   int initialLoc = loc;
   if (wordFlag) {
      /* TODO
      //TODO: precalc all this?
      int modVal = loc % 3;
      while(true) {
         if (modVal == 1) { //is a *
            //do nothing
         }
         else {
            int altLoc;
            if (modVal == 2) { 
               altLoc = loc + 1;
            }
            else { //modVal == 0 (i.e. 3)
               if (loc==0) break;
               altLoc = loc - 1;
            }
            
            //determine if sibling is set
            if ((wordBits[altLoc/64] & (1ull << (63 - altLoc % 64))) != 0) {
               //merge, which means go to the next step (so do nothing now)
               //we don't have to clear children here b/c clear on actual insert
               //will take care of it.
            }
            else {
               break;
            }
         }
         //prep next round
         loc = (loc - 1) / 3;
         modVal = loc % 3;
      } */
      
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      mWeights[loc] = wbox.weight;
      mDataPtr[loc] = wbox.data;
      wordList.push_back(loc);
      
      //TODO: check if we filled the trie
      /*if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }*/
      //clearChildren(loc);
      //clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word TODO: Add support for skipping
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      if (branches.at(loc)==NULL) {
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < _LAYERS - 1) {
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer));
         }
         else {//if at the bottom, insert bottom-level GIAT.
            branches.at(loc).reset(new Base243GIAT(nextActiveLayer));
         }
      }
      else { //check if there's a skip we need to close
         int nextActiveLayer = getNextActiveLayer(box);
         if (nextActiveLayer < branches.at(loc)->getMyLayer()) {
            GenericIntTrie* currentPointer = branches.at(loc).release();
            //observe: new layer must be inner
            branches.at(loc).reset(new Base243InnerGIAT(nextActiveLayer)); 
            branches.at(loc)->forcedInsertAtZero(currentPointer);
         }
      }
      int status = branches[loc]->insertWeighted(wbox);
      /*TODO
      if (status == INSERT_MERGE_REQ) {
         //TODO: I don't like this method...
         vector<int> tempBox = box;
         tempBox[myLayer+1] = -1;
         return this->insert(tempBox);
      }*/
      return status;
   }
}   


void Base243InnerGIAT::forcedInsertAtZero(GenericIntTrie* trie) {
   childBits[0] |= (1ull << (63)); //63 = 63 - (63 % 64)
   branches.at(0).reset(trie);
}

bool Base243InnerGIAT::contains(const vector<int>& box, 
                                   vector<int>& output)
{
//  std::cout << "Calling inner contains" << std::endl;
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   int loc = box.at(myLayer);
   
   if (loc==savedInput) {
   
      for(int i = 0; i < savedChildren.size(); i++) {   
         if (branches.at(savedChildren.at(i))->contains(box, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.at(myLayer) = savedChildren.at(i);
            return true;
         }
      }//end for (all possible outputs)
      //if we've reached here, no children have it, and we don't have it
      return false;
      
   }
      
   //START SIMD ====================
   __m256i data, link, and_result;
   uint64_t dest[4];
   if (mStatus | GIAT_STATUS_WORD_ONLY) {
      data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
      link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
    //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
    //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
      
      and_result = _mm256_and_si256(link, data);
      
      //find location of first set bit in and_result
      _mm256_store_si256((__m256i*)dest, and_result);

      for (int i = 0; i < 4; i++) {
         while (dest[i]!=0) {
            int lzc = __builtin_clzll(dest[i]);
            //dest[i] ^= (1ull << (63 - lzc)); //No need to clear the located output point here!
            int val = 64 * i + lzc;
            
            output.at(myLayer) = val;
            return true;
         }
      }
   }//end if (words exist)
   
   if (mStatus | GIAT_STATUS_CHILDREN_ONLY) {
      //If we've reached here, we got no word matches, so check children!
   //    std::cout << "checking children" << std::endl;
      if (myLayer + 1 >= box.size() || box.at(myLayer+1)==-1) {
         return false;
      }

      //it's a new input and we need children, so update the list
      savedInput = loc;
      savedChildren.clear();
      
      //Restart SIMD, update dest with results.
      data = _mm256_loadu_si256((__m256i*)&childBits[0]);
      and_result = _mm256_and_si256(link, data);
      _mm256_store_si256((__m256i*)dest, and_result);
      //End SIMD part 2
      
      for(int i = 3; i >= 0; i--) {
         while (dest[i]!=0) {
            //note that we prefer higher numbers on searching children
            int tzc = __builtin_ctzll(dest[i]);
            int val;
            val = 64 * (i) + (63 - tzc);
            savedChildren.push_back(val);
            dest[i] ^= (1ull << (tzc)); //clear the searched output point

         }
      }
      
      for(int i = 0; i < savedChildren.size(); i++) {
         
         if (branches.at(savedChildren.at(i))->contains(box, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.at(myLayer) = savedChildren.at(i);
           // contains_outputgen(output, val);
            return true;
         }
      }//end for (all possible outputs)
   }//end if (children exist)
   //if we've reached here, no children have it, and we don't have it
   return false;

}

bool Base243InnerGIAT::containsWeighted(const weightedBox& wbox, 
                                   weightedBox& output)
{
//  std::cout << "Calling inner contains" << std::endl;
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   vector<int> box = wbox.box;
   int loc = box.at(myLayer);
   
   if (loc==savedInput) {
   
      for(int i = 0; i < savedChildren.size(); i++) {   
         if (branches.at(savedChildren.at(i))->containsWeighted(wbox, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.box.at(myLayer) = savedChildren.at(i);
            return true;
         }
      }//end for (all possible outputs)
      //if we've reached here, no children have it, and we don't have it
      return false;
      
   }
      
   //START SIMD ====================
   __m256i data, link, and_result;
   uint64_t dest[4];
   if (mStatus | GIAT_STATUS_WORD_ONLY) {
      data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
      link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
    //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
    //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
      
      and_result = _mm256_and_si256(link, data);
      
      //find location of first set bit in and_result
      _mm256_store_si256((__m256i*)dest, and_result);

      for (int i = 0; i < 4; i++) {
         while (dest[i]!=0) {
            int lzc = __builtin_clzll(dest[i]);
            //dest[i] ^= (1ull << (63 - lzc)); //No need to clear the located output point here!
            int val = 64 * i + lzc;
            
            output.weight = mWeights[val];
            output.data = mDataPtr[val];
            output.box.at(myLayer) = val;
            return true;
         }
      }
   }//end if (words exist)
   
   if (mStatus | GIAT_STATUS_CHILDREN_ONLY) {
      //If we've reached here, we got no word matches, so check children!
   //    std::cout << "checking children" << std::endl;
      if (myLayer + 1 >= box.size() || box.at(myLayer+1)==-1) {
         return false;
      }

      //it's a new input and we need children, so update the list
      savedInput = loc;
      savedChildren.clear();
      
      //Restart SIMD, update dest with results.
      data = _mm256_loadu_si256((__m256i*)&childBits[0]);
      and_result = _mm256_and_si256(link, data);
      _mm256_store_si256((__m256i*)dest, and_result);
      //End SIMD part 2
      
      for(int i = 3; i >= 0; i--) {
         while (dest[i]!=0) {
            //note that we prefer higher numbers on searching children
            int tzc = __builtin_ctzll(dest[i]);
            int val;
            val = 64 * (i) + (63 - tzc);
            savedChildren.push_back(val);
            dest[i] ^= (1ull << (tzc)); //clear the searched output point

         }
      }
      
      for(int i = 0; i < savedChildren.size(); i++) {
         
         if (branches.at(savedChildren.at(i))->containsWeighted(wbox, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.box.at(myLayer) = savedChildren.at(i);
           // contains_outputgen(output, val);
            return true;
         }
      }//end for (all possible outputs)
   }//end if (children exist)
   //if we've reached here, no children have it, and we don't have it
   return false;

}

void Base243InnerGIAT::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, 
                  int& currentDepth) {
   if (currentDepth < myLayer) {
      currentDepth = myLayer;
   }
 //  std::cout << "gacbb inner..." << std::endl;
   int loc = input.at(myLayer);
   //START SIMD ====================
   
   if (loc != savedInput) {
      
      __m256i data, link, and_result;
      uint64_t dest[4];
      if (mStatus | GIAT_STATUS_WORD_ONLY) {
      // std::cout << "Loc: " << loc << std::endl;
   // std::cout << "links:    " << std::hex << links64[loc][0] << ", " << links64[loc][1] << ", " << links64[loc][2] << ", " << links64[loc][3] << std::dec << std::endl;
   // std::cout << "wordBits: " << std::hex << wordBits[0] << ", " << wordBits[1] << ", " << wordBits[2] << ", " << wordBits[3] << std::dec << std::endl;
      //match words
      data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
      link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
    //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
    //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
      
      and_result = _mm256_and_si256(link, data);
      
      //find location of first set bit in and_result
      _mm256_store_si256((__m256i*)dest, and_result);
      for (int i = 0; i < 4; i++) {
         while (dest[i]!=0) {
            int lzc = __builtin_clzll(dest[i]);
            dest[i] ^= (1ull << (63 - lzc)); //clear the located output point
            int val = 64 * i + lzc;
            //contains_outputgenWithNeg(output.back(), val);       
            
            output.push_back(prevWord);
            output.back().at(myLayer) = val;
            output.back().at(myLayer+1) = -1;

           // std::cout << "Word found early." << std::endl;
            return;
         }
      }
      }
      if (mStatus | GIAT_STATUS_CHILDREN_ONLY) {
      //check children!
      //if there are no further data, return false
      /*if (myLayer + 1 >= input.size() || input.at(myLayer+1)==-1) {
         return;
      }*/
      
      //Restart SIMD, update dest with results.
      data = _mm256_loadu_si256((__m256i*)&childBits[0]);
   //std::cout << "childBits: " << std::hex << childBits[0] << ", " << childBits[1] << ", " << childBits[2] << ", " << childBits[3] << std::dec << std::endl;
      and_result = _mm256_and_si256(link, data);
      _mm256_store_si256((__m256i*)dest, and_result);
      //End SIMD part 2
      
      savedInput = loc; //only save if i can guarantee all vectors will be set.
      savedChildren.clear();      

      for(int i = 3; i >= 0; i--) {
         while (dest[i]!=0) {
            int tzc = __builtin_ctzll(dest[i]);
            int val = 64 * (i) + (63 - tzc);
            
            dest[i] ^= (1ull << (tzc)); //clear the searched output point
            
            savedChildren.push_back(val);
         }
      }//end for (all possible outputs)
     // return;
   }}//end (if input not saved)
   
   //check children
   for (int i = 0; i < savedChildren.size(); i++) {
      prevWord.at(myLayer) = savedChildren.at(i);
      branches.at(savedChildren.at(i))->getAllContainingBoxesB(
            input, output, prevWord, currentDepth);

      this->resetPrevWord(prevWord, myLayer);
   }
   
}

void Base243InnerGIAT::getAllContainingBoxesWeighted( const weightedBox& winput,
                  vector<weightedBox>& output,
                  vector<int>& prevWord, 
                  int& currentDepth) {
   if (currentDepth < myLayer) {
      currentDepth = myLayer;
   }
   vector<int> input = winput.box;
 //  std::cout << "gacbb inner..." << std::endl;
   int loc = input.at(myLayer);
   //START SIMD ====================
   
   if (loc != savedInput) {
      
      __m256i data, link, and_result;
      uint64_t dest[4];
      if (mStatus | GIAT_STATUS_WORD_ONLY) {
         // std::cout << "Loc: " << loc << std::endl;
      // std::cout << "links:    " << std::hex << links64[loc][0] << ", " << links64[loc][1] << ", " << links64[loc][2] << ", " << links64[loc][3] << std::dec << std::endl;
      // std::cout << "wordBits: " << std::hex << wordBits[0] << ", " << wordBits[1] << ", " << wordBits[2] << ", " << wordBits[3] << std::dec << std::endl;
         //match words
         data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
         link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
       //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
       //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
         
         and_result = _mm256_and_si256(link, data);
         
         //find location of first set bit in and_result
         _mm256_store_si256((__m256i*)dest, and_result);
         for (int i = 0; i < 4; i++) {
            while (dest[i]!=0) {
               int lzc = __builtin_clzll(dest[i]);
               dest[i] ^= (1ull << (63 - lzc)); //clear the located output point
               int val = 64 * i + lzc;
               //contains_outputgenWithNeg(output.back(), val);       
               
               weightedBox temp;
               temp.box = prevWord;
               temp.box.at(myLayer) = val;
               temp.box.at(myLayer+1) = -1;
               temp.weight = mWeights.at(val);
               temp.data = mDataPtr.at(val);
               output.push_back(temp);

              // std::cout << "Word found early." << std::endl;
               return;
            }
         }
      }
      if (mStatus | GIAT_STATUS_CHILDREN_ONLY) {
      //check children!
      //if there are no further data, return false
      /*if (myLayer + 1 >= input.size() || input.at(myLayer+1)==-1) {
         return;
      }*/
      
      //Restart SIMD, update dest with results.
      data = _mm256_loadu_si256((__m256i*)&childBits[0]);
   //std::cout << "childBits: " << std::hex << childBits[0] << ", " << childBits[1] << ", " << childBits[2] << ", " << childBits[3] << std::dec << std::endl;
      and_result = _mm256_and_si256(link, data);
      _mm256_store_si256((__m256i*)dest, and_result);
      //End SIMD part 2
      
      savedInput = loc; //only save if i can guarantee all vectors will be set.
      savedChildren.clear();      

      for(int i = 3; i >= 0; i--) {
         while (dest[i]!=0) {
            int tzc = __builtin_ctzll(dest[i]);
            int val = 64 * (i) + (63 - tzc);
            
            dest[i] ^= (1ull << (tzc)); //clear the searched output point
            
            savedChildren.push_back(val);
         }
      }//end for (all possible outputs)
     // return;
   }}//end (if input not saved)
   
   //check children
   for (int i = 0; i < savedChildren.size(); i++) {
      prevWord.at(myLayer) = savedChildren.at(i);
      branches.at(savedChildren.at(i))->getAllContainingBoxesWeighted(
            winput, output, prevWord, currentDepth);

      this->resetPrevWord(prevWord, myLayer);
   }
   
}

void Base243InnerGIAT::resetPrevWord(vector<int>& prevWord, int& myLayer) const {
   prevWord.at(myLayer) = 0;
}

int Base243InnerGIAT::getNextActiveLayer(const vector<int>& box) const {
   int nextLayer = myLayer + 1;
   while (box.at(nextLayer) == 0) { //<= WILL cause crashes.
      nextLayer++; //assert: there exists a fully-defined box eventually.
   }
   return nextLayer;
}

void Base243InnerGIAT::add243Children(
   std::vector<std::vector<Base243GIAT*> >& lists, 
   int index, int& remaining) 
{
   
   Base243GIAT* candidate = NULL;
   candidate = (Base243GIAT*) branches.at(index).get();
   if (candidate != NULL) {
      lists.at(candidate->getMyLayer()).push_back(candidate);
      remaining++;
   }
   
}