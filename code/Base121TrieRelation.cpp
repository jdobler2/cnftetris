//Base121TrieRelation.cpp

#include "Base121TrieRelation.h"
#include "SIMD_InnerGIAT.h"
#include "varMap.h"
#include "error_handling.h"
#include "SIMD_SkippingInnerGIAT.h"
#include <utility>

Base121TrieRelation::Base121TrieRelation() {
   
   maxDepth = 4;
   _LAYER_SIZE = 4;
   shift = 40; //necessary for compat. with inherited f().
   //tree = new IATDummy(new SIMD_InnerGIAT());
   std::string treeType = gvars.getStr(DB_TYPE);
   std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   std::cout << "Making tree..." << std::endl;
   if (treeType == "noskips") {
      tree = new IATDummy(new SIMD_InnerGIAT());
   }
   else {
      tree = new IATDummy(new SIMD_SkippingInnerGIAT());
   }
   //sharedInit();
   ratio = gvars.getDouble(RATIO);
   
   print_warning("This relation requires AVX2.\n"
               "If your processor does not support this, the code may crash.");
}

void Base121TrieRelation::fillZero(vector<int>& input, int& index) {
 //  std::cout << "FinalDegree:" << finalDegree << std::endl;
   if (index < SIMD_GIATrie::minLayerShiftedOver) {
      SIMD_GIATrie::minLayerShiftedOver = index;
   }
   while (input.at(index) < shift) {
      input.at(index) = input.at(index) * 3 + 2;
   }
   while (index < input.size() - 1) {
      input.at(++index) = 80;
   }
}

int Base121TrieRelation::highestSetBit(int input) const {
   switch (input) {
     case 0:
     case 1:
      return 0;
     case 2:
     case 3: 
     case 4:
      return 1;
     case 5:
     case 6:
     case 7:
     case 8:
     case 9:
     case 10:
     case 11:
     case 12:
     case 13:
      return 2;
     case 14:
     case 15:
     case 16:
     case 17:
     case 18:
     case 19:
     case 20:
     case 21:
     case 22:
     case 23:
     case 24:
     case 25:
     case 26:
     case 27:
     case 28:
     case 29:
     case 30:
     case 31:
     case 32:
     case 33:
     case 34:
     case 35:
     case 36:
     case 37:
     case 38:
     case 39:
     case 40:
      return 3;
     default:
      return 4;
   }
   /*if (input > 39) return 4;
   if (input > 12) return 3;
   if (input > 3) return 2;
   if (input > 0) return 1;
   return 0; //must be possible*/
   //more accurate version, but slower (???)
   /*switch (input) {
     case 0:
     case 1:
      return 0;
     case 2:
     case 3: 
      return 1;
     case 4:
      return 0;
     case 5:
     case 6:
      return 2;
     case 7:
      return 1;
     case 8:
     case 9:
      return 2;
     case 10:
      return 1;
     case 11:
     case 12:
      return 2;
     case 13: //1 1 1
      return 0;
     case 14: //1 1 2
     case 15:
      return 3;
     case 16:
      return 2;
     case 17:
     case 18:
      return 3;
     case 19: //1 3 1
      return 2;
     case 20:
     case 21:
      return 3;
     case 22:
      return 1;
     case 23:
     case 24:
      return 3;
     case 25:
      return 2;
     case 26:
     case 27:
      return 3;
     case 28: //2 3 1
      return 2;
     case 29:
     case 30:
      return 3;
     case 31: //3 1 1
      return 1;
     case 32:
     case 33:
      return 3;
     case 34:
      return 2;
     case 35:
     case 36:
      return 3;
     case 37: //3 3 1
      return 2;
     case 38:
     case 39:
      return 3;
     case 40: //1 1 1 1
      return 0;
     case 41:
     case 42:
      return 4;
     case 43:
      return 3;
     case 44:
     case 45:
      return 4;
     case 46:
      return 3;
     case 47:
     case 48:
      return 4;
     case 49: //1 2 1 1
      return 2;
     case 50:
     case 51:
      return 4;
     case 52:
      return 3;
     case 53:
     case 54:
      return 4;
     case 55:
      return 3;
     case 56:
     case 57:
      return 4;
     case 58: //1 3 1 1
      return 2; 
     case 59:
     case 60:
      return 4;
     case 61:
      return 3;
     case 62:
     case 63:
      return 4;
     case 64:
      return 3;
     case 65:
     case 66:
      return 4;
     case 67: //2 1 1 1
      return 1;
     case 68:
     case 69:
      return 4;
     case 70:
      return 3;
     case 71:
     case 72:
      return 4;
     case 73:
      return 3;
     case 74:
     case 75:
      return 4;
     case 76://2 2 1 1
      return 2;
     case 77:
     case 78:
      return 4;
     case 79:
      return 3;
     case 80:
     case 81:
      return 4;
     case 82:
      return 3;
     case 83:
     case 84:
      return 4;
     case 85: //2 3 1 1
      return 2;
     case 86:
     case 87:
      return 4;
     case 88:
      return 3;
     case 89:
     case 90:
      return 4;
     case 91:
      return 3;
     case 92:
     case 93:
      return 4;
     case 94: //3 1 1 1
      return 1;
     case 95:
     case 96:
      return 4;
     case 97:
      return 3;
     case 98:
     case 99: //3 1 2 3
      return 4;
     case 100:
      return 3;
     case 101:
     case 102:
      return 4;
     case 103: //3 2 1 1
      return 2;
     case 104:
     case 105:
      return 4;
     case 106:
      return 3;
     case 107:
     case 108:
      return 4;
     case 109:
      return 3;
     case 110:
     case 111:
      return 4;
     case 112://3 3 1 1
      return 2;
     case 113:
     case 114:
      return 4;
     case 115:
      return 3;
     case 116:
     case 117:
      return 4;
     case 118:
      return 3;
     case 119:
     case 120:
      return 4;
     default:
      std::cerr << "wtf in highestSetBit" << std::endl;
      return 4;
   }*/
}

//alias of the above method (TODO: yeah.)
int Base121TrieRelation::highestSetBitFlat(int input) const {
   return highestSetBit(input);
   switch (input) {
     case 0:
      return 0;
     case 1:
     case 2:
     case 3:
      return 1;
     case 4:
     case 5:
     case 6:
     case 7:
     case 8:
     case 9:
     case 10:
     case 11:
     case 12:
      return 2;
     case 13:
     case 14:
     case 15:
     case 16:
     case 17:
     case 18:
     case 19:
     case 20:
     case 21:
     case 22:
     case 23:
     case 24:
     case 25:
     case 26:
     case 27:
     case 28:
     case 29:
     case 30:
     case 31:
     case 32:
     case 33:
     case 34:
     case 35:
     case 36:
     case 37:
     case 38:
     case 39:
      return 3;
     default:
      return 4;
   }
}

void Base121TrieRelation::popOne(vector<int>& input, int& last, int& index) {
   last = (input.at(index) - 1) % 3 - 1;
   input.at(index) = (input.at(index) - 1) / 3;
   return;
}

void Base121TrieRelation::popOneFlat(vector<int>& input, int& last, int& index) {
   last = (input.at(index) - 1) % 3 - 1;
   input.at(index) = (input.at(index) - 1) / 3;
   return;
}

void Base121TrieRelation::popOne(vector<int>& input, int& index) {
   input.at(index) = (input.at(index) - 1) / 3;
   while(input.at(index) % 3 ==1) {
      input.at(index) = (input.at(index) - 1 ) / 3;
   }
   return;
}
void Base121TrieRelation::popOneFlat(vector<int>& input, int& index) {
   switch(input.at(index)) {
     case(0):
      std::cerr << "ERROR: trying to pop an empty" << std::endl;
   	break;
	  case 1:
		input.at(index) = 1;
		break;
	  case 2:
		input.at(index) = 1;
		break;
	  case 3:
		input.at(index) = 1;
		break;
	  case 4:
		input.at(index) = 4;
		break;
	  case 5:
		input.at(index) = 1;
		break;
	  case 6:
		input.at(index) = 1;
		break;
	  case 7:
		input.at(index) = 1;
		break;
	  case 8:
		input.at(index) = 2;
		break;
	  case 9:
		input.at(index) = 2;
		break;
	  case 10:
		input.at(index) = 1;
		break;
	  case 11:
		input.at(index) = 3;
		break;
	  case 12:
		input.at(index) = 3;
		break;
	  case 13:
		input.at(index) = 13;
		break;
	  case 14:
		input.at(index) = 1;
		break;
	  case 15:
		input.at(index) = 1;
		break;
	  case 16:
		input.at(index) = 1;
		break;
	  case 17:
		input.at(index) = 5;
		break;
	  case 18:
		input.at(index) = 5;
		break;
	  case 19:
		input.at(index) = 1;
		break;
	  case 20:
		input.at(index) = 6;
		break;
	  case 21:
		input.at(index) = 6;
		break;
	  case 22:
		input.at(index) = 1;
		break;
	  case 23:
		input.at(index) = 2;
		break;
	  case 24:
		input.at(index) = 2;
		break;
	  case 25:
		input.at(index) = 2;
		break;
	  case 26:
		input.at(index) = 8;
		break;
	  case 27:
		input.at(index) = 8;
		break;
	  case 28:
		input.at(index) = 2;
		break;
	  case 29:
		input.at(index) = 9;
		break;
	  case 30:
		input.at(index) = 9;
		break;
	  case 31:
		input.at(index) = 1;
		break;
	  case 32:
		input.at(index) = 3;
		break;
	  case 33:
		input.at(index) = 3;
		break;
	  case 34:
		input.at(index) = 3;
		break;
	  case 35:
		input.at(index) = 11;
		break;
	  case 36:
		input.at(index) = 11;
		break;
	  case 37:
		input.at(index) = 3;
		break;
	  case 38:
		input.at(index) = 12;
		break;
	  case 39:
		input.at(index) = 12;
		break;
	  case 40:
		input.at(index) = 40;
		break;
	  case 41:
		input.at(index) = 1;
		break;
	  case 42:
		input.at(index) = 1;
		break;
	  case 43:
		input.at(index) = 1;
		break;
	  case 44:
		input.at(index) = 14;
		break;
	  case 45:
		input.at(index) = 14;
		break;
	  case 46:
		input.at(index) = 1;
		break;
	  case 47:
		input.at(index) = 15;
		break;
	  case 48:
		input.at(index) = 15;
		break;
	  case 49:
		input.at(index) = 1;
		break;
	  case 50:
		input.at(index) = 5;
		break;
	  case 51:
		input.at(index) = 5;
		break;
	  case 52:
		input.at(index) = 5;
		break;
	  case 53:
		input.at(index) = 17;
		break;
	  case 54:
		input.at(index) = 17;
		break;
	  case 55:
		input.at(index) = 5;
		break;
	  case 56:
		input.at(index) = 18;
		break;
	  case 57:
		input.at(index) = 18;
		break;
	  case 58:
		input.at(index) = 1;
		break;
	  case 59:
		input.at(index) = 6;
		break;
	  case 60:
		input.at(index) = 6;
		break;
	  case 61:
		input.at(index) = 6;
		break;
	  case 62:
		input.at(index) = 20;
		break;
	  case 63:
		input.at(index) = 20;
		break;
	  case 64:
		input.at(index) = 6;
		break;
	  case 65:
		input.at(index) = 21;
		break;
	  case 66:
		input.at(index) = 21;
		break;
	  case 67:
		input.at(index) = 1;
		break;
	  case 68:
		input.at(index) = 2;
		break;
	  case 69:
		input.at(index) = 2;
		break;
	  case 70:
		input.at(index) = 2;
		break;
	  case 71:
		input.at(index) = 23;
		break;
	  case 72:
		input.at(index) = 23;
		break;
	  case 73:
		input.at(index) = 2;
		break;
	  case 74:
		input.at(index) = 24;
		break;
	  case 75:
		input.at(index) = 24;
		break;
	  case 76:
		input.at(index) = 2;
		break;
	  case 77:
		input.at(index) = 8;
		break;
	  case 78:
		input.at(index) = 8;
		break;
	  case 79:
		input.at(index) = 8;
		break;
	  case 80:
		input.at(index) = 26;
		break;
	  case 81:
		input.at(index) = 26;
		break;
	  case 82:
		input.at(index) = 8;
		break;
	  case 83:
		input.at(index) = 27;
		break;
	  case 84:
		input.at(index) = 27;
		break;
	  case 85:
		input.at(index) = 2;
		break;
	  case 86:
		input.at(index) = 9;
		break;
	  case 87:
		input.at(index) = 9;
		break;
	  case 88:
		input.at(index) = 9;
		break;
	  case 89:
		input.at(index) = 29;
		break;
	  case 90:
		input.at(index) = 29;
		break;
	  case 91:
		input.at(index) = 9;
		break;
	  case 92:
		input.at(index) = 30;
		break;
	  case 93:
		input.at(index) = 30;
		break;
	  case 94:
		input.at(index) = 1;
		break;
	  case 95:
		input.at(index) = 3;
		break;
	  case 96:
		input.at(index) = 3;
		break;
	  case 97:
		input.at(index) = 3;
		break;
	  case 98:
		input.at(index) = 32;
		break;
	  case 99:
		input.at(index) = 32;
		break;
	  case 100:
		input.at(index) = 3;
		break;
	  case 101:
		input.at(index) = 33;
		break;
	  case 102:
		input.at(index) = 33;
		break;
	  case 103:
		input.at(index) = 3;
		break;
	  case 104:
		input.at(index) = 11;
		break;
	  case 105:
		input.at(index) = 11;
		break;
	  case 106:
		input.at(index) = 11;
		break;
	  case 107:
		input.at(index) = 35;
		break;
	  case 108:
		input.at(index) = 35;
		break;
	  case 109:
		input.at(index) = 11;
		break;
	  case 110:
		input.at(index) = 36;
		break;
	  case 111:
		input.at(index) = 36;
		break;
	  case 112:
		input.at(index) = 3;
		break;
	  case 113:
		input.at(index) = 12;
		break;
	  case 114:
		input.at(index) = 12;
		break;
	  case 115:
		input.at(index) = 12;
		break;
	  case 116:
		input.at(index) = 38;
		break;
	  case 117:
		input.at(index) = 38;
		break;
	  case 118:
		input.at(index) = 12;
		break;
	  case 119:
		input.at(index) = 39;
		break;
	  case 120:
		input.at(index) = 39;
		break;
	}

   /*
   input.at(index) = (input.at(index) - 1) / 3;
   while(input.at(index) % 3 ==1) {
      input.at(index) = (input.at(index) - 1 ) / 3;
   }*/
   return;
}

void Base121TrieRelation::setNext(vector<int>& input, int val, int& index) {
   if (input.at(index) < shift) {
      input.at(index) = input.at(index) * 3 + 2 + val;
   }
   else {
  //    std::cout << "This scares me." << std::endl;
      input.at(++index) = val + 2;
   }
}

void Base121TrieRelation::setNextFlat(vector<int>& input, int val, int& index) {
   if (input.at(index) < shift) {
      input.at(index) = input.at(index) * 3 + 2 + val;
   }
   else {
  //    std::cout << "This scares me." << std::endl;
      input.at(++index) = val + 2;
   }
}

//determines the amount of backtraces @output allows on @input.
int Base121TrieRelation::performShrinkage(vector<int>& input, 
                                       vector<int>& output,
                                       int& index)
{
  /* std::cout << "Shrinking: input: \n";
   for ( int i = 0; i < input.size(); i++) {
      std::cout << input.at(i) << ", ";
   }
   std::cout << std::endl << "With output: \n";
   for ( int i = 0; i < output.size(); i++) {
      std::cout << output.at(i) << ", ";
   }
   std::cout << "\n*/
   for (; index >= 0; index--) {
      layerSkipFlat(input.at(index), output.at(index), input.at(index));
      
      if (input.at(index) <= _NULLED) {
         continue;
      }
      
      //non-null, so exit
      if (index + 1 < output.size()) {
         output.at(index + 1) = -1;
      }
      break;
   }
         /* old version. 
      //TODO: This can be done much faster
      if (output.at(index)<=1) {
         input.at(index) = output.at(index);
         continue;
      }
      else if (output.at(index) == B121_ALL_LAMBDA) {
         input.at(index) = output.at(index) = 1; //for compat with CNFInt functions
         continue;
      }
      int last = 0;
      while(input.at(index) >= output.at(index)) {
         last = input.at(index);
         if (last==0) break;
         input.at(index) = (input.at(index) - 1) / 3;
      }
      input.at(index) = last;
      break;
   }*/
 /*  std::cout << "Result is: \n";
   for ( int i = 0; i < input.size(); i++) {
      std::cout << input.at(i) << ", ";
   }
   std::cout << "\n";*/
   return 1;
}

void Base121TrieRelation::insertData(vector<vector<int> >& input, int maxNodeID) {
   
   _LAYERS = (maxNodeID + 3) / 4;
   _NULLED = 1;
   finalDegree = maxNodeID % 4;
   vector<int> insertionVector;
   insertionVector.resize(maxNodeID + 1, _CNFINT_LAMBDA);
   vector<int> iv2;
   iv2.resize(_LAYERS + 1);
   vector<int> temp;
   temp.resize(iv2.size(), 1);
   
   std::cout << insertionVector.size()-1 << ", " << iv2.size() - 1 << std::endl;;
   //insert all boxes into the tree
   //TODO: improve time
   std::cout << "Total terms: " << input.size() << std::endl;
   
   tree->setLayers(_LAYERS);
   tree->setModLayers(0);
   
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
      
      int j;
      for (j = 0; j < std::abs(val); j+=4) {
         int sum = 0;
         int endFlag = 0;
         for (int k = j; k < j + 4; k++) {
            if (insertionVector.at(k)==-1) {
               endFlag = 1;
               break;
            }
            sum = sum * 3 + insertionVector.at(k);
         }
         iv2.at(j/4) = sum;
         if (endFlag) {
            j+=4;
            break;
         }
      }
      iv2.at(j/4) = -1; //this should work
 //  std::cout << "About to insert" << std::endl;
      tree->insert(iv2);
  // std::cout << "Insertion complete." << std::endl;
    //  insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
  //    std::cout << std::endl; 
     /*if (!tree->contains(iv2, temp)) {
         std::cout << "ERROR: input not present!" << std::endl;
         std::cout << "IV is: ";
         for (int i = 0; i < iv2.size(); i++) {
            std::cout << iv2.at(i) << ", ";
         }
         std::cout << std::endl;
         string temp;
         std::cin >> temp;
      }*//*
      else {
         std::cout << "Success!" << std::endl;
         std::cout << "IV is: \t\t ";
         for (int z = 0; z < iv2.size(); z++) {
            std::cout << iv2.at(z) << ", ";
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
   
   finalDegree = (4 - finalDegree) % 4;
   
   tree->setModLayers(finalDegree);
}

int outputPopMatrix[4][121] = {
   {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
   {0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, 11, 11, 11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 15, 15, 15, 16, 16, 16, 17, 17, 17, 18, 18, 18, 19, 19, 19, 20, 20, 20, 21, 21, 21, 22, 22, 22, 23, 23, 23, 24, 24, 24, 25, 25, 25, 26, 26, 26, 27, 27, 27, 28, 28, 28, 29, 29, 29, 30, 30, 30, 31, 31, 31, 32, 32, 32, 33, 33, 33, 34, 34, 34, 35, 35, 35, 36, 36, 36, 37, 37, 37, 38, 38, 38, 39, 39, 39},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6 , 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12},
   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,3, 3, 3, 3, 3, 3, 3, 3, 3}
};

//Aligns the final element from a expanded 4-digit to the actual number of digits
void Base121TrieRelation::outputPop(vector<int>& input, int& index) const {
   input.at(index) = outputPopMatrix[finalDegree][input.at(index)];
   /*//what the matrix outputs, saved for reference
   for(int val = finalDegree; val > 0; val--) { 
      input.at(index) = (input.at(index)-1) / 3;
   }*/
}

int Base121TrieRelation::getLambdaCount(vector<int>& input, int maxVal) const {
   int output = 0;
  /* for (int i = 0; i < maxVal; i++) {
      output += input.at(i);
   }*/
   for (int i = 0; i < maxVal; i++) {
      if (input.at(i) <= 1) {
         output++;
      }
   }
   /*for (int i = 0; i < maxVal; i++) {
      if (input.at(i) < shift) {
         output++;
      }
   }*/
   return output;
}

void Base121TrieRelation::checkForAltOutput(vector<int>& input, int& index, vector<int>& output) {
   //do nothing
}
   

//deliberately separated version, for runtime's sake.
void Base121TrieRelation::popAndMerge(vector<int>& input, vector<int>& output,
                    vector<vector<int> >& pastS01s,
                    GenericIntTrie* cdb,
                    int& index)
{
   int direction = 0;
   while(true) {
      // std::cout << "\nNew loop at index " << index << "." << std::endl;
      // for (int i = 0; i < input.size(); i++) {
         // std::cout << input.at(i) << ", ";
      // }
      // std::cout << std::endl;
      popOneFlat(input, direction, index);
         // std::cout << "Dir=" << direction << std::endl;
     //    checkForAltOutput(input, index, output);

      if (direction==0) {
         int indexLower = highestSetBit(input, index);
         // std::cout << "IndexLower is " << indexLower << std::endl;
         pastS01s.at(index*maxDepth + indexLower).swap(output);
         // std::cout << "Set successful" << std::endl;
         setNext(input, 1, index);
         return;
      }
      else { //dir==1
         vector<int> input2;
         input2.resize(_LAYERS, 1);
         int indexLower = highestSetBit(input, index); 
         
         // std::cout << "Index at top: " << index << std::endl;
          // std::cout << "il: " << indexLower << std::endl;

         input2.swap(pastS01s.at(index*maxDepth + indexLower));

         // std::cout << "Pre-pop: " << std::endl;
          // std::cout << "Output is: \n";
         // for (int i = 0; i < output.size(); i++) {
            // std::cout << output.at(i) << ", ";
         // }
         // std::cout << std::endl;
         // std::cout << "Input 2: \n";
         // for (int i = 0; i < input2.size(); i++) {
            // std::cout << input2.at(i) << ", ";
         // }
         // std::cout << std::endl;
         popOneFlat(output, index);
         popOneFlat(input2, index);

         // std::cout << "Output is: \n";
         // for (int i = 0; i < output.size(); i++) {
            // std::cout << output.at(i) << ", ";
         // }
         // std::cout << std::endl;
         
         // std::cout << "Input 2: \n";
         // for (int i = 0; i < input2.size(); i++) {
            // std::cout << input2.at(i) << ", ";
         // }
         // std::cout << std::endl;
         // std::cout << "While index is " << index << std::endl;
         
         //handle layers 0->next-to-last
          // std::cout << "About to merge." << std::endl;
         mergeBoxesFlat(output, input2, index);

         // std::cout << "Output is: \n";
         // for (int i = 0; i < output.size(); i++) {
            // std::cout << output.at(i) << ", ";
         // }
         // std::cout << std::endl;
         
  // std::cout << "Merge complete." << std::endl;
  
         int msResult = mergeShrink(input, output, index, cdb, indexLower);
         if (msResult < 0) {
            return;
         }
             
         
      } //end else dir==1
   } //end while(true)
   // std::cout << "Returning..." << std::endl;
}

void Base121TrieRelation::setCap(int& diff) {
   //do nothing
}

void Base121TrieRelation::removeCap() {
   //do nothing
}

bool Base121TrieRelation::isPermitted(vector<int>& output, int& index, int& indexLower, int& il2) {
   return true;
}

int Base121TrieRelation::mergeShrink(vector<int>& input, vector<int>& output, int& index, GenericIntTrie* cdb, int& indexLower) {
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
   
   //performShrinkage(input, output, index);

   
   if (indexLower >= 1) {
      // std::cout << "il2: " << il2 << std::endl;
      if (il2 < indexLower) {
         setCap(il2);
         for (; indexLower > il2; indexLower--) {
            int tempIgnored = 0;
            popOne(input, tempIgnored, index);
            //commented line is equiv in B121, but not children
            //input.at(index) = (input.at(index) - 1 ) / 3; 
         }
         removeCap();
      }
   }
   // std::cout << "IndexLower is : " << indexLower << std::endl;
   //if there's a layer skip, handle it
   if (indexLower < 1 ) {
     // output.at(index) = 0; //TODO: IS THIS SAFE?!
      for (index = index-1; index >= 0; index--) {   
         // std::cout << "Performing layer skip over " << index << std::endl;
        layerSkipFlat(input.at(index), output.at(index), input.at(index));
        
         if (input.at(index)<=_NULLED) {
            repairLocks(input, index, 4, 0);
            continue;
         }
         
         repairLocks(input, index, 4, updateBitIndex(input, index));
         
         output.at(index + 1) = -1;
         // std::cout << "Exiting layer skips.\n";
         break;
      } //end for(indexUpper)
      //Check to see if we cleared it
      
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
      
   } //end if(layer skip)    

   return 0;
}

void Base121TrieRelation::repairLocks(vector<int>& input, int& index, int start, int end) {
   
}

int Base121TrieRelation::updateBitIndex(vector<int>& input, int& index) {
   return 0;
}


unsigned long Base121TrieRelation::performFroggerTricount(
                size_t start,
                size_t end) 
{
   if (start!=0) return 0; //not gonna multithread here ftm.
   std::string treeType = gvars.getStr(CDB_TYPE);
   SIMD_InnerGIAT* cdb;
   std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   if (treeType == "noskips") {
      cdb = new SIMD_InnerGIAT();
   }
   else {
      cdb = new SIMD_SkippingInnerGIAT();
   }
   unsigned long count = tetris(cdb);
   
   delete cdb;
   return count;
}

void Base121TrieRelation::buildDepthLUT() {
   depthLUT.resize(_LAYERS);
   int i = depthLUT.size() - 1;
   depthLUT.at(i--) = 0;
   depthLUT.at(i--) = 4 - finalDegree;
   for (; i >= 0; i--) {
      depthLUT.at(i) = depthLUT.at(i+1) + 4;
   }
}

void Base121TrieRelation::buildPrevWord(vector<int>& prevWord) const {
   prevWord.resize(_LAYERS+1, B121_ALL_LAMBDA); //1-1-1-1, i.e. all lambdas
   prevWord.back() = -1;
}

void Base121TrieRelation::resetOutput(vector<int>& output) const {
   for (int i = 0; i < _LAYERS; i++) {
      output.at(i) = 40;
   }
}