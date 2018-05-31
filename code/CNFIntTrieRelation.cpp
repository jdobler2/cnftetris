//CNFIntTrieRelation.cpp

#include "CNFIntTrieRelation.h"
#include <cmath>
#include <sstream>
#include <math.h>
#include <stdio.h>
#include "TrieActors.h"
#include <algorithm>
#include "SIMD_InnerGIAT2.h"
#include "varMap.h"
#include "Preprocessor.h"
#include "SIMD_GIATrie.h"

//including orderers
#include "Orderer.h"
#include "Treewidth.h"
#include "DegreeDesc.h"
#include "FullDegreeDesc.h"
#include "Fourwidth.h"
#include "Minfill.h"
#include "SamplerOrderer.h"
#include "LocksOrder.h"
#include "KillOrder.h"

int GenericIntTrie::_LAYERS = 3;
int GenericIntTrie::_MODLAYERS = 0;

 struct timeval ltv, ltv2;
 double l243_totalTime;
 int iterations = 0;

//START CNFINT_ML_MERGER_ACTOR=================================================
//ASSERT: IntArrayTrie tr is actually a SmallIntArrayTrie
CNFIntTrieRelation::cnfint_mlMergerActor::cnfint_mlMergerActor(
      IntArrayTrie* tr)
{
   t = tr;
}

CNFIntTrieRelation::cnfint_mlMergerActor::~cnfint_mlMergerActor() {}

//ASSERT: tr is actually a SmallIntArrayTrie
void CNFIntTrieRelation::cnfint_mlMergerActor::setTrie(IntArrayTrie* tr) {
   t = tr;
}

void CNFIntTrieRelation::cnfint_mlMergerActor::if_siat_do_once_after_children(
      SmallIntArrayTrie* siat)
{
 //  std::cout << "Welcome!" << std::endl;
   //update wordBits
   for (int i = 2; i >= 0; i --) {
      if (siat->branches.at(i)!=NULL) {
         if (siat->branches.at(i)->getType() == "SmallIntArrayTrie" && 
               siat->branches.at(i)->size() == 1) {
            siat->wordBits[i] = 1;
            siat->branches.at(i).reset();
          //  std::cout << "Full found." << std::endl;
         }
      }
   }
   
   //check for merge
   if (siat->wordBits[1]==1 && siat->wordBits[2]==1) {
      siat->wordBits[0] = 1;
      siat->branches.at(0).reset();
     // std::cout << "Merged!" << std::endl;
   }
   else if (siat->wordBits[0]==1) {
      siat->wordBits[1] = 1;
      siat->branches.at(1).reset();
      siat->wordBits[2] = 1;
      siat->branches.at(2).reset();
      std::cout << "Filled!" << std::endl;
   }
   
}

//END CNFINT_ML_MERGER_ACTOR===================================================

//START PRINT_ACTOR_CNF===================================================
/*void PrintActorCNF::if_siat_do_once(SmallIntArrayTrie* siat) {
   std::cout << "At layer: " << siat->myLayer << ": ";
}*/

void CNFIntTrieRelation::printActorCNF::if_array_word
      (IntArrayTrie* siat, int index) 
{
   std::cout << "At layer: " << siat->myLayer << " w_" << index << std::endl;
}

//END   PRINT_ACTOR_CNF===================================================

CNFIntTrieRelation::CNFIntTrieRelation() {
   maxDepth = 1;
   shift = 2; //neccessary for compat. with inherited f().
   //tree = new SmallIntArrayTrie();
   tree = new IATDummy(new SIMD_InnerGIAT2());
   sharedInit();
}

//helper for below function
template<typename T> 
unique_ptr<Orderer> getPtr() 
{
   return unique_ptr<Orderer>(new T); 
}

void CNFIntTrieRelation::sharedInit() {
   
   setOrdering(gvars.getStr(ORDERING));
   
   gPreprocess = gvars.getBool(PREPROCESS);
}

void CNFIntTrieRelation::setOrdering(std::string ordering) {
   //go to lower case (taken from stackoverflow)
   std::transform(ordering.begin(), ordering.end(), ordering.begin(), ::tolower);
   
   std::map<std::string, unique_ptr<Orderer> (*)()> mymap;
   mymap["treewidth"] = &getPtr<Treewidth>;
   mymap["degreedesc"] = &getPtr<DegreeDesc>;
   mymap["fulldegreedesc"] = &getPtr<FullDegreeDesc>;
   mymap["4width"] = &getPtr<Fourwidth>;
   mymap["fourwidth"] = &getPtr<Fourwidth>;
   mymap["minfill"] = &getPtr<Minfill>;
   mymap["naive"] = &getPtr<Naive>;
   mymap["sampler"] = &getPtr<SamplerOrderer>;
   mymap["samplerOrdering"] = &getPtr<SamplerOrderer>;
   mymap["locks"] = &getPtr<LocksOrder>;
   mymap["locksOrder"] = &getPtr<LocksOrder>;
   mymap["kill"] = &getPtr<KillOrder>;
   mymap["killOrder"] = &getPtr<KillOrder>;
   
   if (mymap.count(ordering)==0) {
      std::cout << "Error: Ordering " << ordering << " cannot be found; using degreeDesc" << std::endl;
      ordering = "degreedesc";
   }
   orderer = mymap[ordering]();
}

CNFIntTrieRelation::~CNFIntTrieRelation() {
}

size_t CNFIntTrieRelation::size() const {
   return _LAYERS;
}

void CNFIntTrieRelation::insertData(vector<vector<int> >& input, int maxNodeID) {
   
   _LAYERS = maxNodeID;
   
   vector<int> insertionVector;
   insertionVector.resize(_LAYERS+1, _CNFINT_LAMBDA);
   vector<int> temp;
   temp.resize(insertionVector.size(), 1);
   
   std::cout << insertionVector.size()-1 << std::endl;;
   //insert all boxes into the tree
   //TODO: improve time
   std::cout << "Total terms: " << input.size() << std::endl;
   
   tree->setLayers(insertionVector.size()-1);
   for (int i = 0; i < input.size(); i++) {
      int val;
      for (int j=0; j < input.at(i).size(); j++) {
        // std::cout << "CV: " << input.at(i).at(j) << std::endl;
         val = input.at(i).at(j);
         if (val < 0) {
            insertionVector.at(std::abs(val) - 1) = _CNFINT_NEG; 
         } else {
            insertionVector.at(val - 1) = _CNFINT_POS; 
         }
      }
      
      insertionVector.at(std::abs(val)) = _CNFINT_KILL;

      tree->insert(insertionVector);
    //  insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
      if (!tree->contains(insertionVector, temp)) {
         std::cout << "ERROR: input not present!" << std::endl;
         std::cout << "At loop " << i << ", IV is: ";
         for (int i = 0; i < insertionVector.size(); i++) {
            std::cout << insertionVector.at(i) << ", ";
         }
         std::cout << std::endl;
         string temp;
         std::cin >> temp;
      }
      /*else {
         std::cout << "Success!" << std::endl;
         std::cout << "IV is: \t\t ";
         for (int z = 0; z < insertionVector.size(); z++) {
            std::cout << insertionVector.at(z) << ", ";
         }
         std::cout << "\nwhile output is: ";
         for (int z =0; z < temp.size(); z++) {
            std::cout << temp.at(z) << ", ";
         }
         std::cout << "\n" << std::endl;
         
         string temps;
         std::cin >> temps;
         
         for (int i = 0; i < temp.size(); i++) {
            temp.at(i) = 1;
         }
      }*/
      
      //prepare for next round
      insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
      for (int j=0; j < input.at(i).size(); j++) {
         insertionVector.at(std::abs(input.at(i).at(j)) - 1) = _CNFINT_LAMBDA;
      }
      
      //progress bar-ish
      if (i % 100000 ==0) {
         std::cout << "i: " << i << std::endl;
      }
   }
}

void CNFIntTrieRelation::buildIndexCNF(
                      std::vector<std::vector<int> >& input,
                      int maxNodeID,
                      vector<std::pair<int, int> >& counts)
{
   std::cout << "maxNodeID initially: " << maxNodeID << std::endl;
   bool cry = false;
   if (gPreprocess) {
      std::cout << "Preprocessing..." << std::endl;
      Preprocessor p;
      vector<int> removedVars;
      p.preprocess(input, counts, removedVars, maxNodeID); 
      //TODO: handle removedVars
      
      std::cout << "Preprocessing complete; " << removedVars.size() << " vars removed." << std::endl;
      if (maxNodeID <=  0) { //removedVars.size()) {
         std::cout << "ERROR: ALL NODES REMOVED IN PREPROCESS -- UNSAT" << std::endl;
         return;
      }
   }
   
   //need to switch to DNF
   //(i.e. negate every term)
   for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.at(i).size(); j++) {
         input.at(i).at(j) *= -1;
      }
   }
   
   //Get ordering
   cout << "Ordering..." << endl;

   vector<int> mappings(counts.size()); //mappings[i] -> the value to map i to
   mappings = orderer->getOrdering(input, maxNodeID, counts, _LAYER_SIZE);
     std::cout << "Mappings: ";
   for (int i = 0; i < mappings.size(); i++) {
      std::cout << i << ": " << mappings.at(i) << ", ";
   }
   std::cout << std::endl;
   //apply the mapping
   if (strcmp(gvars.getStr(ORDERING).c_str(), "naive")!=0) {
      for (int i = 0; i < input.size(); i++) {
         for (int j = 0; j < input.at(i).size(); j++) {
            int currVal = input.at(i).at(j);
            if (currVal < 0) {
               input.at(i).at(j) = -1 * (mappings.at(currVal * -1));
            }
            else {
               input.at(i).at(j) = mappings.at(currVal);
            }
         }
      }
   }
   //===Mapping complete!
   std::cout << "Mapping complete!" << std::endl;
   
   //need to sort each sub-vector by absolute value
   for (int i = 0; i < input.size(); i++) {
      std::sort(input.at(i).begin(), input.at(i).end(), [](int a, int b) {
         return std::abs(a) < std::abs(b);
      });
   }
      std::cout << "maxNodeID when calling insert: " << maxNodeID << std::endl;

   insertData(input, maxNodeID);
   buildDepthLUT();

   std::cout << "Insertion complete." << std::endl;
   //merge
   cnfint_mlMergerActor* mlma = new cnfint_mlMergerActor(tree);
  // tree->apply(mlma);
   delete mlma;
   
   //print for debug
   printActorCNF* pa = new printActorCNF();
  // tree->apply(pa);
   delete pa;
}

unsigned long CNFIntTrieRelation::performFroggerTricount(
                size_t start,
                size_t end) 
{
   if (start!=0) return 0; //not gonna multithread here ftm.

   //SmallIntArrayTrie* cdb = new SmallIntArrayTrie();
   SIMD_InnerGIAT2* cdb = new SIMD_InnerGIAT2();
   //cdb->setMaxDepth(3);
   //cdb->setMaxNodeID(maxNodeID); <--screws things up?
   
   unsigned long count = tetris(cdb);
   
   delete cdb;
   return count;
}

//int totalContains = 0;
//int doubleContains = 0;
int rounds = 0;
unsigned long outputCount = 0;
   unsigned long maxIncrement = 0;

unsigned long CNFIntTrieRelation::tetris(GenericIntTrie* cdb) {
   int index = 0;
   vector<int> input;
   vector<int> output;
   output.resize(_LAYERS, 1); //E cheaper way
   resetOutput(output);

   outputCount = 0;
   SIMD_GIATrie::greatestSingletonDepth = 0;
   
   //initialize pastSO1s
   vector<vector<int> > pastSO1s; //<--functions essentially as a hash table
   pastSO1s.resize(_LAYERS * maxDepth);
   for (int i = 0; i < pastSO1s.size(); i++) {
      pastSO1s.at(i).resize(_LAYERS, 1);
   }
      
   //set up the input so that it is at the first interesting point
   initializeInput(input);
   input.resize(_LAYERS, 2);
   fillZero(input, index);
   string tempString;
   initializePointers(pastSO1s, cdb);
   for(;;) {
      rounds++;
      // if (rounds % 100 == 1) {
  // std::cout << "\nInput: " << std::endl;
               // for (int i = 0; i < input.size(); i++) {
                  // std::cout << input.at(i) << ", ";
               // }
            // std::cout << std::endl;
            
    //  }
            /*if (rounds > 980) {
             //  return count;
               if (rounds % 1 == 0) {
                  string stemp;
                  std::cin >> stemp;
               }
            }*/
      if (input.back() >= shift) {//=== is a unit box
     // std::cout << "About to call contains" << std::endl;
     //    if (getAllContainingBoxesB(input, output, cdb)) {
        gettimeofday(&ltv, NULL);   
         if (cdb->contains(input, output)) {
                  gettimeofday(&ltv2, NULL);
      l243_totalTime+=double(ltv2.tv_sec - ltv.tv_sec) + 
          double(ltv2.tv_usec - ltv.tv_usec)/1000000;
          
          iterations++;
       if (iterations % 500000 == 0) {
          std::cout << "total time so far: " << l243_totalTime << std::endl;
       }
   //         totalContains++;
              // std::cout << "\tContained by ";
              // for (int i = 0; i < output.size(); i++) {
                 // std::cout << output.at(i) << ", ";
              // }
              // std::cout << std::endl;
            performShrinkage(input, output, index);
    //        std::cout << "Shrink shrunk." << std::endl;
            popAndMerge(input, output, pastSO1s, cdb, index);
    //        std::cout << "Merge popped" << std::endl;
            if (index < 0) break;
            
            resetOutput(output);
        //    std::cout << "Output reset." << std::endl;
            fillZero(input, index);
            continue;
         }
               gettimeofday(&ltv2, NULL);
      l243_totalTime+=double(ltv2.tv_sec - ltv.tv_sec) + 
          double(ltv2.tv_usec - ltv.tv_usec)/1000000;
          
          iterations++;
       if (iterations % 500000 == 0) {
          std::cout << "total time so far: " << l243_totalTime << std::endl;
       }
         // std::cout << "Contains gave false." << std::endl;
    /*     std::cout << "Input: " << std::endl;
         for (int i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ", ";
         }
         std::cout << std::endl; */
         vector<vector<int> > allBoxes;
         int maxDepth = getAllContainingBoxesB(input, allBoxes);
         // std::cout << "GACB(b) returned with size " << allBoxes.size()
                   // << std::endl;
         if (allBoxes.size()==0) { //is an output point
            unsigned long incrementAmount = 1ull << depthLUT.at(maxDepth);
            if (incrementAmount > 1) {
               // std::cout << "Increase amount of " << incrementAmount << std::endl;
        //       std::string temp;
         //      std::cin >> temp;
            }

            outputCount+=incrementAmount;
              // std::cout << "\tOutput point found." << std::endl;
        /*    std::cout << "Output point is: ";
            for (int i = 0; i < input.size(); i++) {
               std::cout << input.at(i) << ", ";
            }
            std::cout << std::endl;*/
            // if (count%10000==0) {
               // std::cout << "\t\tCount is: " << count << std::endl;
            // }
      //      return count;
        //    std::cout << "About to PAM" << std::endl;
            
            //0 out nulled blocks
            outputPop(input, index); //for children (e.g. Base121) that need to adjust from an assumed size to the actual size

            while (index > maxDepth) {
               input.at(index) = 0;
               index--;
            }
                  
            output = input; //note: MUST COPY //TODO: I'm still not 100% sure if it's safe to move it after outputPop, but it should be!
 
            //note: except in Locks, this does nothing.
            performShrinkage(input, output, index);
            popAndMerge(input, output, pastSO1s, cdb, index);
            
            if (index < 0) break;
            
          //  std::cout << "Returned in UB" << std::endl;
            resetOutput(output);
            fillZero(input, index);

            continue; //restart loop
         }
         
         else { //negative witness found
             // std::cout << "About to add" << std::endl;
            // for (int i = 0; i < 1/*allBoxes.size()*/; i++) {
               // std::cout << "Box " << i << ": ";
               // for (int j = 0; j < allBoxes.at(i).size(); j++) {
                  // std::cout << allBoxes.at(i).at(j) << ", ";
               // }
               // std::cout << std::endl;
            // }
            
            //TODO: Add variable for this
            for (int i = 0; i < allBoxes.size(); i++) {
               cdb->insert(allBoxes.at(i));
            }
            
        //    std::cout << "About to build." << std::endl;
            //TODO: find a better way to build this vector
          //  vector<int> tempBox;
          //  tempBox.resize(_LAYERS, 1);
          //  for (int i = 0; allBoxes.at(0).at(i)!=_CNFINT_KILL; i++) {
          //     tempBox.at(i) = allBoxes.at(0).at(i);
          //  }
            
            // std::cout << "About to shrink" << std::endl;
            performShrinkage(input, allBoxes.at(0), index);
            // std::cout << "Shrinkage complete" << std::endl;
         /*   std::cout << "values pre-pop: ";
            for (int i = 0; i < input.size(); i++) {
               std::cout << input.at(i) << ", ";
            }
            std::cout << std::endl;*/
            popAndMerge(input, allBoxes.at(0), pastSO1s, cdb, index);

            if (index < 0) break;
            
            // std::cout << "Returned in NW" << std::endl;
            fillZero(input, index);
            // std::cout << "Filled." << std::endl;
            continue; //restart loop
         }
      } //end if unit box
   
      else {
         //progress downwards
         fillZero(input, index);
         continue;
      } //end else
   
   } //end while
   std::cout << "Rounds: " << rounds << std::endl;
   rounds = 0;
   return outputCount;
}

void CNFIntTrieRelation::getAllContainingBoxes(
      vector<int>& input,
      vector<pair<dataLayerPair, dataLayerPair> >& output
      ) const
{
   std::cout << "ERROR: Do not call this!" << std::endl;
}

bool CNFIntTrieRelation::getAllContainingBoxesB(
      vector<int>& input, 
      vector<int>& finalOutput,
      GenericIntTrie* cdb) const 
{
   vector<int> prevWord;
   vector<vector<int> > output;
   this->buildPrevWord(prevWord);
   
   int maxDepth = 0;
   cdb->getAllContainingBoxesB(input, output, prevWord, maxDepth);
   //grab opt
   //where we define opt as the box ending with the most 1's.
   if (output.size() >= 1) {
      int maxStars = 0;
      for (int i = 0; i < output.size(); i++) {
         int currStars = 0;
         for (int j = output.at(i).size()-1; j >= 0; j--) {
            if (output.at(i).at(j) <= 1) {
               currStars++;
            }
            else {//hit a non-star
               if ((currStars > maxStars) || (currStars == maxStars && output.at(i).at(j) < output.at(0).at(j))) {
                  output.at(0).swap(output.at(i));
                  maxStars = currStars;
               }
               break;
            }
         }
      }
   } else {
      //finalOutput = output.at(0);
      return false; 
   }
   finalOutput = output.at(0);
   return true;
   
   //where we define opt as the box with the most 1's.
  /* if (output.size() > 1) {
      int maxStars = getLambdaCount(output.at(0));
      for (int i = 1; i < output.size(); i++) {
         int newVal = getLambdaCount(output.at(i));
         if (newVal > maxStars) {
            output.at(0).swap(output.at(i));
            maxStars = newVal;
         }
      }
   }*/
   
//  std::cout << "TO so far: " << totalOutput << std::endl << std::endl;
   
}

int totalOutput = 0;
//have I been overthinking this?
//is it actually this simple here?
int CNFIntTrieRelation::getAllContainingBoxesB(
      vector<int>& input, 
      vector<vector<int> >& output) const 
{
   vector<int> prevWord;

   this->buildPrevWord(prevWord);
   
   int maxDepth = 0;
   tree->getAllContainingBoxesB(input, output, prevWord, maxDepth);
   totalOutput+=output.size();
   //grab opt
   //where we define opt as the box ending with the most 1's.
   if (output.size() > 1) {
      int maxStars = 0;
      for (int i = 0; i < output.size(); i++) {
         int currStars = 0;
         for (int j = output.at(i).size()-1; j >= 0; j--) {
            if (output.at(i).at(j) <= 1) {
               currStars++;
            }
            else {//hit a non-star
               if ((currStars > maxStars) || (currStars == maxStars && output.at(i).at(j) < output.at(0).at(j))) {
                  output.at(0).swap(output.at(i));
                  maxStars = currStars;
               }
               break;
            }
         }
      }
   } else {
      // std::cout << "Input: ";
      // for (int i = 0; i < input.size(); i++) {
         // std::cout << input.at(i) << ", ";
      // }
      // std::cout << std::endl;
      // std::cout << "singletonDepth: " << SIMD_GIATrie::greatestSingletonDepth << " and maxDepth: " << maxDepth << std::endl;
      // string tmp;
      // std::cin >> tmp;
      // if (output.size() > 0) {
         // for (int i = 0; i < output.back().size(); i++) {
            // std::cout << output.back().at(i) << ", ";
         // }
         // std::cout << std::endl;
         // std::cout << std::endl;
      // }
      if (output.size() == 0 &&
          SIMD_GIATrie::greatestSingletonDepth > maxDepth /*&&
          SIMD_GIATrie::greatestSingletonDepth > 0 &&
          maxDepth != input.size() - 1*/)
      {
         //STEP ONE: Count the lambdas 
         //we do need to know the --exact-- number of lambdas, not 4-sets
         //I think I can do the count starting from GSD+1? doing it from equal is going to be problematic...
         maxDepth++;
         int lambdaCount = countLambdas(
               SIMD_GIATrie::singletonCandidate,
               maxDepth, 
               input.size());
         //STEP TWO: Increment count by 2^(lambdaCount)
         //TODO: Verify correctness!
         unsigned long nonIncrementValue = 1ull << (lambdaCount - (4-depthLUT.at(_LAYERS - 2)));
         unsigned long potentialIncrementValue = 1ull << depthLUT.at(maxDepth-1);

         incrementCountBy(potentialIncrementValue - nonIncrementValue);
         
         //STEP THREE: Insert megabox
         for (int i = 0; i < maxDepth; i++) {
            prevWord.at(i) = input.at(i);
         }
         prevWord.at(maxDepth) = -1;
         output.push_back(prevWord);
      }
      else {
         maxDepth = (SIMD_GIATrie::greatestSingletonDepth > maxDepth ? SIMD_GIATrie::greatestSingletonDepth : maxDepth);
     }
      return maxDepth; 
   }
   return 0;
   
   //where we define opt as the box with the most 1's.
  /* if (output.size() > 1) {
      int maxStars = getLambdaCount(output.at(0));
      for (int i = 1; i < output.size(); i++) {
         int newVal = getLambdaCount(output.at(i));
         if (newVal > maxStars) {
            output.at(0).swap(output.at(i));
            maxStars = newVal;
         }
      }
   }*/
   
//  std::cout << "TO so far: " << totalOutput << std::endl << std::endl;
   
}

int CNFIntTrieRelation::countLambdas(vector<int>& input, int start, int end) const
{
   int output = 0;
   for (int i = start; i < end; i++) {
      switch(input[i]) {
   case(-1):
      output += 4;
      break;
   case(0):
		output += 4;
		break;
	 case(1):
		output += 4;
		break;
	 case(2):
		output += 3;
		break;
	 case(3):
		output += 3;
		break;
	 case(4):
		output += 4;
		break;
	 case(5):
		output += 3;
		break;
	 case(6):
		output += 3;
		break;
	 case(7):
		output += 3;
		break;
	 case(8):
		output += 2;
		break;
	 case(9):
		output += 2;
		break;
	 case(10):
		output += 3;
		break;
	 case(11):
		output += 2;
		break;
	 case(12):
		output += 2;
		break;
	 case(13):
		output += 4;
		break;
	 case(14):
		output += 3;
		break;
	 case(15):
		output += 3;
		break;
	 case(16):
		output += 3;
		break;
	 case(17):
		output += 2;
		break;
	 case(18):
		output += 2;
		break;
	 case(19):
		output += 3;
		break;
	 case(20):
		output += 2;
		break;
	 case(21):
		output += 2;
		break;
	 case(22):
		output += 3;
		break;
	 case(23):
		output += 2;
		break;
	 case(24):
		output += 2;
		break;
	 case(25):
		output += 2;
		break;
	 case(26):
		output += 1;
		break;
	 case(27):
		output += 1;
		break;
	 case(28):
		output += 2;
		break;
	 case(29):
		output += 1;
		break;
	 case(30):
		output += 1;
		break;
	 case(31):
		output += 3;
		break;
	 case(32):
		output += 2;
		break;
	 case(33):
		output += 2;
		break;
	 case(34):
		output += 2;
		break;
	 case(35):
		output += 1;
		break;
	 case(36):
		output += 1;
		break;
	 case(37):
		output += 2;
		break;
	 case(38):
		output += 1;
		break;
	 case(39):
		output += 1;
		break;
	 case(40):
		output += 4;
		break;
	 case(41):
		output += 3;
		break;
	 case(42):
		output += 3;
		break;
	 case(43):
		output += 3;
		break;
	 case(44):
		output += 2;
		break;
	 case(45):
		output += 2;
		break;
	 case(46):
		output += 3;
		break;
	 case(47):
		output += 2;
		break;
	 case(48):
		output += 2;
		break;
	 case(49):
		output += 3;
		break;
	 case(50):
		output += 2;
		break;
	 case(51):
		output += 2;
		break;
	 case(52):
		output += 2;
		break;
	 case(53):
		output += 1;
		break;
	 case(54):
		output += 1;
		break;
	 case(55):
		output += 2;
		break;
	 case(56):
		output += 1;
		break;
	 case(57):
		output += 1;
		break;
	 case(58):
		output += 3;
		break;
	 case(59):
		output += 2;
		break;
	 case(60):
		output += 2;
		break;
	 case(61):
		output += 2;
		break;
	 case(62):
		output += 1;
		break;
	 case(63):
		output += 1;
		break;
	 case(64):
		output += 2;
		break;
	 case(65):
		output += 1;
		break;
	 case(66):
		output += 1;
		break;
	 case(67):
		output += 3;
		break;
	 case(68):
		output += 2;
		break;
	 case(69):
		output += 2;
		break;
	 case(70):
		output += 2;
		break;
	 case(71):
		output += 1;
		break;
	 case(72):
		output += 1;
		break;
	 case(73):
		output += 2;
		break;
	 case(74):
		output += 1;
		break;
	 case(75):
		output += 1;
		break;
	 case(76):
		output += 2;
		break;
	 case(77):
		output += 1;
		break;
	 case(78):
		output += 1;
		break;
	 case(79):
		output += 1;
		break;
	 case(80):
		output += 0;
		break;
	 case(81):
		output += 0;
		break;
	 case(82):
		output += 1;
		break;
	 case(83):
		output += 0;
		break;
	 case(84):
		output += 0;
		break;
	 case(85):
		output += 2;
		break;
	 case(86):
		output += 1;
		break;
	 case(87):
		output += 1;
		break;
	 case(88):
		output += 1;
		break;
	 case(89):
		output += 0;
		break;
	 case(90):
		output += 0;
		break;
	 case(91):
		output += 1;
		break;
	 case(92):
		output += 0;
		break;
	 case(93):
		output += 0;
		break;
	 case(94):
		output += 3;
		break;
	 case(95):
		output += 2;
		break;
	 case(96):
		output += 2;
		break;
	 case(97):
		output += 2;
		break;
	 case(98):
		output += 1;
		break;
	 case(99):
		output += 1;
		break;
	 case(100):
		output += 2;
		break;
	 case(101):
		output += 1;
		break;
	 case(102):
		output += 1;
		break;
	 case(103):
		output += 2;
		break;
	 case(104):
		output += 1;
		break;
	 case(105):
		output += 1;
		break;
	 case(106):
		output += 1;
		break;
	 case(107):
		output += 0;
		break;
	 case(108):
		output += 0;
		break;
	 case(109):
		output += 1;
		break;
	 case(110):
		output += 0;
		break;
	 case(111):
		output += 0;
		break;
	 case(112):
		output += 2;
		break;
	 case(113):
		output += 1;
		break;
	 case(114):
		output += 1;
		break;
	 case(115):
		output += 1;
		break;
	 case(116):
		output += 0;
		break;
	 case(117):
		output += 0;
		break;
	 case(118):
		output += 1;
		break;
	 case(119):
		output += 0;
		break;
	 case(120):
		output += 0;
		break;
         
      }
   }
   
   return output;
}

void CNFIntTrieRelation::incrementCountBy(unsigned long amount) const {
   outputCount += amount;
}

void CNFIntTrieRelation::buildPrevWord(vector<int>& prevWord) const {
      prevWord.resize(_LAYERS+1, _CNFINT_KILL);
  // prevWord.resize(_LAYERS+1,0);
}

int CNFIntTrieRelation::getLambdaCount(vector<int>& input) const {
   return getLambdaCount(input, input.size());
}

int CNFIntTrieRelation::getLambdaCount(vector<int>& input, int maxVal) const {
   int output = 0;
   for (int i = 0; i < maxVal; i++) {
      if (input.at(i) < shift) {
         output++;
      }
   }
   return output;
}

/* These two methods almost certainly aren't useful since the 6/20 redesign
int CNFIntTrieRelation::performShrinkage(vector<int>& input, 
                                       vector<int>& output,
                                       int& index) const
{
   for (; index > 0; index--) {
      input.at(index) = output.at(index);
      if (output.at(index)!=0) {
         break;
      }
   }
   return 1;
}
*/

int totalInsert = 0;
double averageInsert = 0.0;

int CNFIntTrieRelation::highestSetBit(int value) const {
   return value/2;
}


//Note: Mostly c/p'd, but there are a few changes d.t. optimizations in ITR
//that aren't possible here. Could possibly be merged with some effort.
void CNFIntTrieRelation::popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index)
{
/*   std::cout << "Input entering pop: " << std::endl;
   for (int i = 0; i < input.size(); i++) {
      std::cout << input.at(i) << ", ";
   }
   std::cout << std::endl;*/
   int direction = 0;
   while(true) {
  /*    std::cout << "New loop." << std::endl;
      for (int i = 0; i < input.size(); i++) {
         std::cout << input.at(i) << ", ";
      }*/
  //    std::cout << "Index is: " << index << std::endl;*/
      popOne(input, direction, index);
      //std::cout << "Dir=" << direction << std::endl;
      if (direction==0) {
         int indexLower = highestSetBit(input,index);
     //    std::cout << "il: " << indexLower << std::endl;

         pastS01s.at(index*maxDepth + indexLower).swap(output);
         setNext(input, 1, index);
         return;
      }
      else { //dir==1
         vector<int> input2;
         input2.resize(_LAYERS, 1);
         int indexLower = highestSetBit(input, index); 
    //     std::cout << "il: " << indexLower << std::endl;

   //      std::cout << "Loc: " << index * maxDepth + indexLower + 1 << std::endl;
         input2.swap(pastS01s.at(index*maxDepth + indexLower));
    //     std::cout << " fetch successful." << std::endl;
         
         //handle last layer
    //     std::cout << "Last layer: " << output.at(index) << std::endl;
         popOne(output, index);
         popOne(input2, index);
         
    //     std::cout << "Index is: " << index << "; size is " << output.size() << "; inputSize is: " << input2.size() << std::endl;
         
        /* std::cout << "Output is initially: ";
         for (int i = 0; i < output.size(); i++) {
            std::cout << output.at(i) << ", ";
         }
         std::cout << std::endl;
         
         std::cout << "Input2 is: ";
         for (int i = 0; i < input2.size(); i++) {
            std::cout << input2.at(i) << ", ";
         }
         std::cout << std::endl;*/
         
         //handle layers 0->next-to-last
         //TODO: I do not trust this in mode11 one bit
         mergeBoxes(output, input2, index);
         
         
      /*   std::cout << "Output is: ";
         for (int i = 0; i < output.size(); i++) {
            std::cout << output.at(i) << ", ";
         }
         std::cout << std::endl;*/
           
         if (indexLower >= 1) {
            int il2 = highestSetBit(output.at(index));
            if (il2 < indexLower) {
               for (; indexLower > il2; indexLower--) {
                  input.at(index) = (input.at(index) - 1 ) / 3;
               }
            }
         }
         //if there's a layer skip, handle it
         if (indexLower < 1 ) {
            
            for (index = index-1; index >= 0; index--) {
           //    std::cout << "Index: " << index << std::endl;
             //  std::cout << "Output: " << output.at(index) << "; input: " << input.at(index) << std::endl;
               if ((output.at(index) < input.at(index)) && (output.at(index) < shift)) {
           //       std::cout << "Applying." << std::endl;
             //     std::cout << "Output: " << output.at(index) << "; shift: " << shift << std::endl;
                  input.at(index) = output.at(index);
                  //ASSERT: input.at(index)==1
                  if (input.at(index)<=1) {
                     continue;
                  }
               }
               output.at(index + 1) = -1;
               break;
            } //end for(indexUpper)
            
            //Check to see if we cleared it
            if (index < 0) {
               //we're done
      //         std::cout << "We're done." << std::endl;
               return;
            }
            
            //insert if "good"
            //TESTING: insert often
       //     if (output.front() < shift) {
            if (getLambdaCount(output) > output.size() * .5) {
         /*      averageInsert = ((averageInsert * totalInsert) + getLambdaCount(output)) / (totalInsert + 1);
               totalInsert++;
               if (totalInsert % 100 == 0) {
             //     std::cout << "Average is " << averageInsert << std::endl;
               }*/
               
               bool result = cdb->insert(output);
            }
         } //end if(layer skip)         
         
      } //end else dir==1
   } //end while(true)
   std::cout << "Returning..." << std::endl;
}

void CNFIntTrieRelation::mergeBoxes(
      vector<int>& output, 
      vector<int>& input2, 
      int& index
) const {
   for (int i = 0; i <= index; i++) {
      if (output.at(i) < input2.at(i)) {
         output.at(i) = input2.at(i);
      }
   }
}

void CNFIntTrieRelation::buildDepthLUT() {
   depthLUT.resize(_LAYERS);
   for (int i = 0; i < depthLUT.size(); i++) {
    //  depthLUT.at(i) = _LAYERS - i - 1; //not supported by the tries yet
    depthLUT.at(i) = 0;
   }
}

void CNFIntTrieRelation::resetOutput(vector<int>& output) const {
   for (int i = 0; i < _LAYERS; i++) {
      output.at(i) = 1;
   }
}

void CNFIntTrieRelation::initializeInput(vector<int>& input) {
   input.resize(_LAYERS, 2);
}

int CNFIntTrieRelation::highestSetBit(vector<int>& input, int& index) const {
   
   return this->highestSetBit(input.at(index));
}

void CNFIntTrieRelation::initializePointers(vector<vector<int> >& pastS01s, GenericIntTrie* pTrie) {
   //no pointers to assign for this trie
}

