
//SIMD_InnerGIAT2.cpp

#include "SIMD_InnerGIAT2.h"
#include <math.h>

#include <nmmintrin.h>
#include <emmintrin.h>

SIMD_InnerGIAT2::SIMD_InnerGIAT2() {
   myLayer = 0;
   branches.resize(81);
   for (int i = 0; i < 4; i++) {
      wordBits[i] = 0;
      childBits[i] = 0;
   }
}

SIMD_InnerGIAT2::SIMD_InnerGIAT2(int newLayer) {
   myLayer = newLayer;
   branches.resize(81);
   for (int i = 0; i < 4; i++) {
      wordBits[i] = 0;
      childBits[i] = 0;
   }
}

int SIMD_InnerGIAT2::insert(const vector<int>& box) {
//std::cout << "MyLayer: " << myLayer << std::endl;
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);

   //this line is disgusting. just make all inputs kill-terminated already.
   //or do 120 base like a man.
   int wordFlag = 0;
   for (int i = 1;; i++) {
      if (i+myLayer < box.size() && box.at(i+myLayer)==-1) {
         wordFlag = 1;
         break;
      }
      else if (i >= maxLevel) {
         break;
      }
      loc = loc * 3 + box.at(i+myLayer);
      if ((wordBits[loc/32] & (1 << (31 - (loc % 32)))) != 0) {
         return INSERT_PRESENT;
      }
      //if I ever switch to 120-base, do a mini-contains check to check for presence.
   }
  // std::cout << "Inserting " << loc << std::endl;


   if (wordFlag) {
    //  std::cout << "Word." << std::endl;
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
            if ((wordBits[altLoc/32] & (1 << (31 - altLoc % 32))) != 0) {
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
      }
  //   std::cout <<"Actloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/32] |= (1 << (31 - (loc % 32)));
      //check if we filled the trie
      if (size()) {
       //  std::cout << "REturning IMR" << std::endl << std::endl;
         return INSERT_MERGE_REQ;
      }
      clearChildren(loc);
      clearChildBits(loc); //saves time to do it here.

        // std::cout << "Insertion successful." << std::endl << std::endl;

      return INSERT_SUCCESSFUL;
   }
   else { //not a word
      if (branches.at(loc-40)==NULL) {
         childBits[loc/32] |= (1 << (31 - (loc % 32)));
         if (myLayer + maxLevel < _LAYERS - maxLevel) {
            branches.at(loc-40).reset(new SIMD_InnerGIAT2(myLayer+maxLevel));
         }
         else {//if at the bottom, insert bottom-level SIMD_GIAT.
            branches.at(loc-40).reset(new SIMD_GIATrie2(myLayer+maxLevel));
         }
      }
      int status = branches.at(loc-40)->insert(box);
      if (status == INSERT_MERGE_REQ) {
         //I don't like this method...
         vector<int> tempBox = box;
     //    std::cout << "reentering" << std::endl;
         tempBox[myLayer+maxLevel] = -1;
         return this->insert(tempBox);
      }
      return status;
   }

}

void SIMD_InnerGIAT2::clearChildBits(int loc) {
   switch(loc) {
     case(0):
      { // i = 1
        unsigned int temp = childBits[1] & 16777215ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4278190080ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 4294967295ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 0ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(1):
      { // i = 1
        unsigned int temp = childBits[1] & 16777215ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4278190080ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 4294967295ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 0ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(2):
      { // i = 2
        unsigned int temp = childBits[2] & 536870908ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3758096387ul;
      }
        break;
     case(3):
      { // i = 2
        branches.at(55).reset();
        branches.at(54).reset();
        childBits[2] &= 4294967292ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(4):
      { // i = 1
        unsigned int temp = childBits[1] & 16777215ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4278190080ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 4294967295ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 0ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(5):
      { // i = 1
        unsigned int temp = childBits[1] & 32704ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294934591ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(6):
      { // i = 1
        unsigned int temp = childBits[1] & 63ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294967232ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 3758098428ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 536868867ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(7):
      { // i = 2
        unsigned int temp = childBits[2] & 536870908ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3758096387ul;
      }
        break;
     case(8):
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
        break;
     case(9):
      { // i = 2
        unsigned int temp = childBits[2] & 2044ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4294965251ul;
      }
        break;
     case(10):
      { // i = 2
        branches.at(55).reset();
        branches.at(54).reset();
        childBits[2] &= 4294967292ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(11):
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(12):
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(13):
      { // i = 1
        unsigned int temp = childBits[1] & 16777215ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4278190080ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 4294967295ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 0ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(14):
      { // i = 1
        unsigned int temp = childBits[1] & 1838599ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4293128696ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 58835168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4236132127ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 1882725376ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 2412241919ul;
      }
        break;
     case(15):
      { // i = 1
        unsigned int temp = childBits[1] & 229824ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294737471ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 3765450780ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 529516515ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 235340672ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4059626623ul;
      }
        break;
     case(16):
      { // i = 1
        unsigned int temp = childBits[1] & 32704ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294934591ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(17):
      { // i = 1
        branches.at(14).reset();
        branches.at(13).reset();
        branches.at(12).reset();
        childBits[1] &= 4294963711ul;
      }
      { // i = 2
        branches.at(41).reset();
        branches.at(40).reset();
        branches.at(39).reset();
        childBits[2] &= 4294852607ul;
      }
      { // i = 3
        branches.at(68).reset();
        branches.at(67).reset();
        branches.at(66).reset();
        childBits[3] &= 4291297279ul;
      }
        break;
     case(18):
      { // i = 1
        branches.at(17).reset();
        branches.at(16).reset();
        branches.at(15).reset();
        childBits[1] &= 4294966847ul;
      }
      { // i = 2
        branches.at(44).reset();
        branches.at(43).reset();
        branches.at(42).reset();
        childBits[2] &= 4294952959ul;
      }
      { // i = 3
        branches.at(71).reset();
        branches.at(70).reset();
        branches.at(69).reset();
        childBits[3] &= 4294508543ul;
      }
        break;
     case(19):
      { // i = 1
        unsigned int temp = childBits[1] & 63ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294967232ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 3758098428ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 536868867ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(20):
      { // i = 1
        branches.at(23).reset();
        branches.at(22).reset();
        branches.at(21).reset();
        childBits[1] &= 4294967288ul;
      }
      { // i = 2
        branches.at(50).reset();
        branches.at(49).reset();
        branches.at(48).reset();
        childBits[2] &= 4294967071ul;
      }
      { // i = 3
        branches.at(77).reset();
        branches.at(76).reset();
        branches.at(75).reset();
        childBits[3] &= 4294960127ul;
      }
        break;
     case(21):
      { // i = 2
        unsigned int temp = childBits[2] & 3758096412ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 536870883ul;
      }
      { // i = 3
        branches.at(80).reset();
        branches.at(79).reset();
        branches.at(78).reset();
        childBits[3] &= 4294966399ul;
      }
        break;
     case(22):
      { // i = 2
        unsigned int temp = childBits[2] & 536870908ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3758096387ul;
      }
        break;
     case(23):
      { // i = 2
        unsigned int temp = childBits[2] & 58835168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4236132127ul;
      }
        break;
     case(24):
      { // i = 2
        unsigned int temp = childBits[2] & 7354396ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4287612899ul;
      }
        break;
     case(25):
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
        break;
     case(26):
      { // i = 2
        branches.at(41).reset();
        branches.at(40).reset();
        branches.at(39).reset();
        childBits[2] &= 4294852607ul;
      }
        break;
     case(27):
      { // i = 2
        branches.at(44).reset();
        branches.at(43).reset();
        branches.at(42).reset();
        childBits[2] &= 4294952959ul;
      }
        break;
     case(28):
      { // i = 2
        unsigned int temp = childBits[2] & 2044ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4294965251ul;
      }
        break;
     case(29):
      { // i = 2
        branches.at(50).reset();
        branches.at(49).reset();
        branches.at(48).reset();
        childBits[2] &= 4294967071ul;
      }
        break;
     case(30):
      { // i = 2
        branches.at(53).reset();
        branches.at(52).reset();
        branches.at(51).reset();
        childBits[2] &= 4294967267ul;
      }
        break;
     case(31):
      { // i = 2
        branches.at(55).reset();
        branches.at(54).reset();
        childBits[2] &= 4294967292ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(32):
      { // i = 3
        unsigned int temp = childBits[3] & 1882725376ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 2412241919ul;
      }
        break;
     case(33):
      { // i = 3
        unsigned int temp = childBits[3] & 235340672ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4059626623ul;
      }
        break;
     case(34):
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(35):
      { // i = 3
        branches.at(68).reset();
        branches.at(67).reset();
        branches.at(66).reset();
        childBits[3] &= 4291297279ul;
      }
        break;
     case(36):
      { // i = 3
        branches.at(71).reset();
        branches.at(70).reset();
        branches.at(69).reset();
        childBits[3] &= 4294508543ul;
      }
        break;
     case(37):
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(38):
      { // i = 3
        branches.at(77).reset();
        branches.at(76).reset();
        branches.at(75).reset();
        childBits[3] &= 4294960127ul;
      }
        break;
     case(39):
      { // i = 3
        branches.at(80).reset();
        branches.at(79).reset();
        branches.at(78).reset();
        childBits[3] &= 4294966399ul;
      }
        break;
     case(40):
      { // i = 1
        unsigned int temp = childBits[1] & 16777215ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4278190080ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 4294967295ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 0ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(41):
      { // i = 1
        unsigned int temp = childBits[1] & 4793490ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4290173805ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1227133513ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3067833782ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 613566720ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 3681400575ul;
      }
        break;
     case(42):
      { // i = 1
        unsigned int temp = childBits[1] & 2396745ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4292570550ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 613566756ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3681400539ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 2454267008ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 1840700287ul;
      }
        break;
     case(43):
      { // i = 1
        unsigned int temp = childBits[1] & 1838599ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4293128696ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 58835168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4236132127ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 1882725376ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 2412241919ul;
      }
        break;
     case(44):
      { // i = 1
        branches.at(22).reset();
        branches.at(13).reset();
        branches.at(4).reset();
        childBits[1] &= 4294441981ul;
      }
      { // i = 2
        branches.at(49).reset();
        branches.at(40).reset();
        branches.at(31).reset();
        childBits[2] &= 4278157247ul;
      }
      { // i = 3
        branches.at(76).reset();
        branches.at(67).reset();
        branches.at(58).reset();
        childBits[3] &= 3757045759ul;
      }
        break;
     case(45):
      { // i = 1
        branches.at(23).reset();
        branches.at(14).reset();
        branches.at(5).reset();
        childBits[1] &= 4294704638ul;
      }
      { // i = 2
        branches.at(50).reset();
        branches.at(41).reset();
        branches.at(32).reset();
        childBits[2] &= 4286562271ul;
      }
      { // i = 3
        branches.at(77).reset();
        branches.at(68).reset();
        branches.at(59).reset();
        childBits[3] &= 4026006527ul;
      }
        break;
     case(46):
      { // i = 1
        unsigned int temp = childBits[1] & 229824ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294737471ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 3765450780ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 529516515ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 235340672ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4059626623ul;
      }
        break;
     case(47):
      { // i = 1
        branches.at(16).reset();
        branches.at(7).reset();
        childBits[1] &= 4294901631ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1075843080ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3219124215ul;
      }
      { // i = 3
        branches.at(79).reset();
        branches.at(70).reset();
        branches.at(61).reset();
        childBits[3] &= 4227727103ul;
      }
        break;
     case(48):
      { // i = 1
        branches.at(17).reset();
        branches.at(8).reset();
        childBits[1] &= 4294934463ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 537921540ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3757045755ul;
      }
      { // i = 3
        branches.at(80).reset();
        branches.at(71).reset();
        branches.at(62).reset();
        childBits[3] &= 4261347199ul;
      }
        break;
     case(49):
      { // i = 1
        unsigned int temp = childBits[1] & 32704ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294934591ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(50):
      { // i = 1
        branches.at(16).reset();
        branches.at(13).reset();
        branches.at(10).reset();
        childBits[1] &= 4294957951ul;
      }
      { // i = 2
        branches.at(43).reset();
        branches.at(40).reset();
        branches.at(37).reset();
        childBits[2] &= 4294668287ul;
      }
      { // i = 3
        branches.at(70).reset();
        branches.at(67).reset();
        branches.at(64).reset();
        childBits[3] &= 4285399039ul;
      }
        break;
     case(51):
      { // i = 1
        branches.at(17).reset();
        branches.at(14).reset();
        branches.at(11).reset();
        childBits[1] &= 4294962623ul;
      }
      { // i = 2
        branches.at(44).reset();
        branches.at(41).reset();
        branches.at(38).reset();
        childBits[2] &= 4294817791ul;
      }
      { // i = 3
        branches.at(71).reset();
        branches.at(68).reset();
        branches.at(65).reset();
        childBits[3] &= 4290183167ul;
      }
        break;
     case(52):
      { // i = 1
        branches.at(14).reset();
        branches.at(13).reset();
        branches.at(12).reset();
        childBits[1] &= 4294963711ul;
      }
      { // i = 2
        branches.at(41).reset();
        branches.at(40).reset();
        branches.at(39).reset();
        childBits[2] &= 4294852607ul;
      }
      { // i = 3
        branches.at(68).reset();
        branches.at(67).reset();
        branches.at(66).reset();
        childBits[3] &= 4291297279ul;
      }
        break;
     case(53):
      { // i = 1
        branches.at(13).reset();
        childBits[1] &= 4294966271ul;
      }
      { // i = 2
        branches.at(40).reset();
        childBits[2] &= 4294934527ul;
      }
      { // i = 3
        branches.at(67).reset();
        childBits[3] &= 4293918719ul;
      }
        break;
     case(54):
      { // i = 1
        branches.at(14).reset();
        childBits[1] &= 4294966783ul;
      }
      { // i = 2
        branches.at(41).reset();
        childBits[2] &= 4294950911ul;
      }
      { // i = 3
        branches.at(68).reset();
        childBits[3] &= 4294443007ul;
      }
        break;
     case(55):
      { // i = 1
        branches.at(17).reset();
        branches.at(16).reset();
        branches.at(15).reset();
        childBits[1] &= 4294966847ul;
      }
      { // i = 2
        branches.at(44).reset();
        branches.at(43).reset();
        branches.at(42).reset();
        childBits[2] &= 4294952959ul;
      }
      { // i = 3
        branches.at(71).reset();
        branches.at(70).reset();
        branches.at(69).reset();
        childBits[3] &= 4294508543ul;
      }
        break;
     case(56):
      { // i = 1
        branches.at(16).reset();
        childBits[1] &= 4294967167ul;
      }
      { // i = 2
        branches.at(43).reset();
        childBits[2] &= 4294963199ul;
      }
      { // i = 3
        branches.at(70).reset();
        childBits[3] &= 4294836223ul;
      }
        break;
     case(57):
      { // i = 1
        branches.at(17).reset();
        childBits[1] &= 4294967231ul;
      }
      { // i = 2
        branches.at(44).reset();
        childBits[2] &= 4294965247ul;
      }
      { // i = 3
        branches.at(71).reset();
        childBits[3] &= 4294901759ul;
      }
        break;
     case(58):
      { // i = 1
        unsigned int temp = childBits[1] & 63ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 32 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[1] &= 4294967232ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 3758098428ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 536868867ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(59):
      { // i = 1
        branches.at(22).reset();
        branches.at(19).reset();
        childBits[1] &= 4294967277ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 1073742408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3221224887ul;
      }
      { // i = 3
        branches.at(79).reset();
        branches.at(76).reset();
        branches.at(73).reset();
        childBits[3] &= 4294948607ul;
      }
        break;
     case(60):
      { // i = 1
        branches.at(23).reset();
        branches.at(20).reset();
        childBits[1] &= 4294967286ul;
      }
      { // i = 2
        unsigned int temp = childBits[2] & 536871204ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3758096091ul;
      }
      { // i = 3
        branches.at(80).reset();
        branches.at(77).reset();
        branches.at(74).reset();
        childBits[3] &= 4294957951ul;
      }
        break;
     case(61):
      { // i = 1
        branches.at(23).reset();
        branches.at(22).reset();
        branches.at(21).reset();
        childBits[1] &= 4294967288ul;
      }
      { // i = 2
        branches.at(50).reset();
        branches.at(49).reset();
        branches.at(48).reset();
        childBits[2] &= 4294967071ul;
      }
      { // i = 3
        branches.at(77).reset();
        branches.at(76).reset();
        branches.at(75).reset();
        childBits[3] &= 4294960127ul;
      }
        break;
     case(62):
      { // i = 1
        branches.at(22).reset();
        childBits[1] &= 4294967293ul;
      }
      { // i = 2
        branches.at(49).reset();
        childBits[2] &= 4294967231ul;
      }
      { // i = 3
        branches.at(76).reset();
        childBits[3] &= 4294965247ul;
      }
        break;
     case(63):
      { // i = 1
        branches.at(23).reset();
        childBits[1] &= 4294967294ul;
      }
      { // i = 2
        branches.at(50).reset();
        childBits[2] &= 4294967263ul;
      }
      { // i = 3
        branches.at(77).reset();
        childBits[3] &= 4294966271ul;
      }
        break;
     case(64):
      { // i = 2
        unsigned int temp = childBits[2] & 3758096412ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 536870883ul;
      }
      { // i = 3
        branches.at(80).reset();
        branches.at(79).reset();
        branches.at(78).reset();
        childBits[3] &= 4294966399ul;
      }
        break;
     case(65):
      { // i = 2
        branches.at(52).reset();
        branches.at(25).reset();
        childBits[2] &= 3221225463ul;
      }
      { // i = 3
        branches.at(79).reset();
        childBits[3] &= 4294967039ul;
      }
        break;
     case(66):
      { // i = 2
        branches.at(53).reset();
        branches.at(26).reset();
        childBits[2] &= 3758096379ul;
      }
      { // i = 3
        branches.at(80).reset();
        childBits[3] &= 4294967167ul;
      }
        break;
     case(67):
      { // i = 2
        unsigned int temp = childBits[2] & 536870908ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 3758096387ul;
      }
        break;
     case(68):
      { // i = 2
        unsigned int temp = childBits[2] & 153391688ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4141575607ul;
      }
        break;
     case(69):
      { // i = 2
        unsigned int temp = childBits[2] & 76695844ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4218271451ul;
      }
        break;
     case(70):
      { // i = 2
        unsigned int temp = childBits[2] & 58835168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4236132127ul;
      }
        break;
     case(71):
      { // i = 2
        branches.at(49).reset();
        branches.at(40).reset();
        branches.at(31).reset();
        childBits[2] &= 4278157247ul;
      }
        break;
     case(72):
      { // i = 2
        branches.at(50).reset();
        branches.at(41).reset();
        branches.at(32).reset();
        childBits[2] &= 4286562271ul;
      }
        break;
     case(73):
      { // i = 2
        unsigned int temp = childBits[2] & 7354396ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4287612899ul;
      }
        break;
     case(74):
      { // i = 2
        branches.at(52).reset();
        branches.at(43).reset();
        branches.at(34).reset();
        childBits[2] &= 4292866039ul;
      }
        break;
     case(75):
      { // i = 2
        branches.at(53).reset();
        branches.at(44).reset();
        branches.at(35).reset();
        childBits[2] &= 4293916667ul;
      }
        break;
     case(76):
      { // i = 2
        unsigned int temp = childBits[2] & 1046528ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4293920767ul;
      }
        break;
     case(77):
      { // i = 2
        branches.at(43).reset();
        branches.at(40).reset();
        branches.at(37).reset();
        childBits[2] &= 4294668287ul;
      }
        break;
     case(78):
      { // i = 2
        branches.at(44).reset();
        branches.at(41).reset();
        branches.at(38).reset();
        childBits[2] &= 4294817791ul;
      }
        break;
     case(79):
      { // i = 2
        branches.at(41).reset();
        branches.at(40).reset();
        branches.at(39).reset();
        childBits[2] &= 4294852607ul;
      }
        break;
     case(80):
      { // i = 2
        branches.at(40).reset();
        childBits[2] &= 4294934527ul;
      }
        break;
     case(81):
      { // i = 2
        branches.at(41).reset();
        childBits[2] &= 4294950911ul;
      }
        break;
     case(82):
      { // i = 2
        branches.at(44).reset();
        branches.at(43).reset();
        branches.at(42).reset();
        childBits[2] &= 4294952959ul;
      }
        break;
     case(83):
      { // i = 2
        branches.at(43).reset();
        childBits[2] &= 4294963199ul;
      }
        break;
     case(84):
      { // i = 2
        branches.at(44).reset();
        childBits[2] &= 4294965247ul;
      }
        break;
     case(85):
      { // i = 2
        unsigned int temp = childBits[2] & 2044ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 64 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[2] &= 4294965251ul;
      }
        break;
     case(86):
      { // i = 2
        branches.at(52).reset();
        branches.at(49).reset();
        branches.at(46).reset();
        childBits[2] &= 4294966711ul;
      }
        break;
     case(87):
      { // i = 2
        branches.at(53).reset();
        branches.at(50).reset();
        branches.at(47).reset();
        childBits[2] &= 4294967003ul;
      }
        break;
     case(88):
      { // i = 2
        branches.at(50).reset();
        branches.at(49).reset();
        branches.at(48).reset();
        childBits[2] &= 4294967071ul;
      }
        break;
     case(89):
      { // i = 2
        branches.at(49).reset();
        childBits[2] &= 4294967231ul;
      }
        break;
     case(90):
      { // i = 2
        branches.at(50).reset();
        childBits[2] &= 4294967263ul;
      }
        break;
     case(91):
      { // i = 2
        branches.at(53).reset();
        branches.at(52).reset();
        branches.at(51).reset();
        childBits[2] &= 4294967267ul;
      }
        break;
     case(92):
      { // i = 2
        branches.at(52).reset();
        childBits[2] &= 4294967287ul;
      }
        break;
     case(93):
      { // i = 2
        branches.at(53).reset();
        childBits[2] &= 4294967291ul;
      }
        break;
     case(94):
      { // i = 2
        branches.at(55).reset();
        branches.at(54).reset();
        childBits[2] &= 4294967292ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 4294967168ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 127ul;
      }
        break;
     case(95):
      { // i = 2
        branches.at(55).reset();
        childBits[2] &= 4294967294ul;
      }
      { // i = 3
        unsigned int temp = childBits[3] & 613566720ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 3681400575ul;
      }
        break;
     case(96):
      { // i = 3
        unsigned int temp = childBits[3] & 2454267008ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 1840700287ul;
      }
        break;
     case(97):
      { // i = 3
        unsigned int temp = childBits[3] & 1882725376ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 2412241919ul;
      }
        break;
     case(98):
      { // i = 3
        branches.at(76).reset();
        branches.at(67).reset();
        branches.at(58).reset();
        childBits[3] &= 3757045759ul;
      }
        break;
     case(99):
      { // i = 3
        branches.at(77).reset();
        branches.at(68).reset();
        branches.at(59).reset();
        childBits[3] &= 4026006527ul;
      }
        break;
     case(100):
      { // i = 3
        unsigned int temp = childBits[3] & 235340672ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4059626623ul;
      }
        break;
     case(101):
      { // i = 3
        branches.at(79).reset();
        branches.at(70).reset();
        branches.at(61).reset();
        childBits[3] &= 4227727103ul;
      }
        break;
     case(102):
      { // i = 3
        branches.at(80).reset();
        branches.at(71).reset();
        branches.at(62).reset();
        childBits[3] &= 4261347199ul;
      }
        break;
     case(103):
      { // i = 3
        unsigned int temp = childBits[3] & 33488896ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4261478399ul;
      }
        break;
     case(104):
      { // i = 3
        branches.at(70).reset();
        branches.at(67).reset();
        branches.at(64).reset();
        childBits[3] &= 4285399039ul;
      }
        break;
     case(105):
      { // i = 3
        branches.at(71).reset();
        branches.at(68).reset();
        branches.at(65).reset();
        childBits[3] &= 4290183167ul;
      }
        break;
     case(106):
      { // i = 3
        branches.at(68).reset();
        branches.at(67).reset();
        branches.at(66).reset();
        childBits[3] &= 4291297279ul;
      }
        break;
     case(107):
      { // i = 3
        branches.at(67).reset();
        childBits[3] &= 4293918719ul;
      }
        break;
     case(108):
      { // i = 3
        branches.at(68).reset();
        childBits[3] &= 4294443007ul;
      }
        break;
     case(109):
      { // i = 3
        branches.at(71).reset();
        branches.at(70).reset();
        branches.at(69).reset();
        childBits[3] &= 4294508543ul;
      }
        break;
     case(110):
      { // i = 3
        branches.at(70).reset();
        childBits[3] &= 4294836223ul;
      }
        break;
     case(111):
      { // i = 3
        branches.at(71).reset();
        childBits[3] &= 4294901759ul;
      }
        break;
     case(112):
      { // i = 3
        unsigned int temp = childBits[3] & 65408ul;
        while (temp!=0) {
            int tzc = __builtin_ctz(temp);
            int val = 96 + (31 - tzc);
            branches.at(val - 40).reset();
            temp ^= (1 << (tzc));
        }
        childBits[3] &= 4294901887ul;
      }
        break;
     case(113):
      { // i = 3
        branches.at(79).reset();
        branches.at(76).reset();
        branches.at(73).reset();
        childBits[3] &= 4294948607ul;
      }
        break;
     case(114):
      { // i = 3
        branches.at(80).reset();
        branches.at(77).reset();
        branches.at(74).reset();
        childBits[3] &= 4294957951ul;
      }
        break;
     case(115):
      { // i = 3
        branches.at(77).reset();
        branches.at(76).reset();
        branches.at(75).reset();
        childBits[3] &= 4294960127ul;
      }
        break;
     case(116):
      { // i = 3
        branches.at(76).reset();
        childBits[3] &= 4294965247ul;
      }
        break;
     case(117):
      { // i = 3
        branches.at(77).reset();
        childBits[3] &= 4294966271ul;
      }
        break;
     case(118):
      { // i = 3
        branches.at(80).reset();
        branches.at(79).reset();
        branches.at(78).reset();
        childBits[3] &= 4294966399ul;
      }
        break;
     case(119):
      { // i = 3
        branches.at(79).reset();
        childBits[3] &= 4294967039ul;
      }
        break;
     case(120):
      { // i = 3
        branches.at(80).reset();
        childBits[3] &= 4294967167ul;
      }
        break;
    }
}

bool SIMD_InnerGIAT2::contains(const vector<int>& box,
                                   vector<int>& output)
{
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   int loc = 0;
   //again, disgusting conditional right here.
   for (int i = myLayer; i < myLayer + maxLevel && i < box.size() && box.at(i)!=-1; i++) {
      loc = loc * 3 + box.at(i);
   }
   //START SIMD ====================

   __m128i link = _mm_loadu_si128((__m128i*)&links[loc][0]);

   __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);
   
   __m128i and_result = _mm_and_si128(link, data);

   //note: can avoid SSSE4 using _mm_cmpneq_si128
   //but that won't get me the nice packed result that I want...

   //find location of first set bit in and_result
   //note that endianness is "backwards" in __m128i's, which is fixed by r/=2.
   unsigned int r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(),
         8,
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_LEAST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);

      if (r >= 8) { //no word matches here, so check children!
      //if there are no further data, return false
  //    std::cout << "checking children" << std::endl;
      if (myLayer + maxLevel >= box.size() || box.at(myLayer+maxLevel)==-1) {
         return false;
      }
      data = _mm_loadu_si128((__m128i*)&childBits[0]);

      and_result = _mm_and_si128(link, data);

      r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(),
         8,
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_MOST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);

      if (r >= 8) {
         return false; //op returns MAXSIZE (8) on fail
      }
      r/=2;

      unsigned int dest[4];
      _mm_storeu_si128((__m128i*)dest, and_result);
      for(int i = r; i >= 1; i--) {
         while (dest[i]!=0) {
            //note that we prefer higher numbers on searching children
            int tzc = __builtin_ctz(dest[i]);
            int val = 32 * i + (31 - tzc);
            if (branches.at(val - 40)->contains(box, output)) {
        //       std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
               contains_outputgen(output, val);
               return true;
            }
            else {
               dest[i] ^= (1 << (tzc)); //clear the searched output point
            }
         }
      }//end for (all possible outputs)
      //if we've reached here, no children have it, and we don't have it
      return false;
   }//end (checking children)
 //  std::cout << "Found in word; r is " << r << std::endl;

   r/=2;
 //  std::cout << "relevant wb is " << wordBits[r] << std::endl;
   //--Everything from here on takes 1/8 of total time
   //count leading zeros
   unsigned int dest[4];
   _mm_storeu_si128((__m128i*)dest, and_result);

   unsigned int internalVal = dest[r];

   int i_output = __builtin_clz(internalVal) + 32 * r;
   //int i_output = log2FloorInv(internalVal) + 32 * r; //<--slower for lg.#
   //END SIMD ======================

   //move i_output data into output
   contains_outputgen(output, i_output);

 //     std::cout << "REturning success" << std::endl;
   return true;
}

void SIMD_InnerGIAT2::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord,
                  int& currentDepth) {
 //  std::cout << "Starting..." << std::endl;
   int loc = 0;
   //still ugly. still gets auto-fixed if I go to 120-base, which I should.
   for (int i = myLayer; i < myLayer + maxLevel && i < input.size() && input.at(i)!=-1; i++) {
      loc = loc * 3 + input.at(i);
   }
 // if (loc > 120 || loc < 0) std::cout << "Loc is: " << loc << std::endl;
   //START SIMD ====================

   __m128i link = _mm_loadu_si128((__m128i*)&links[loc][0]);
   __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

   __m128i and_result = _mm_and_si128(link, data);


   unsigned int r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(),
         8,
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_LEAST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);

   //TODO: I should still check children when there's a word
   //      but first, I need to add clearing the childBits n' stuff.
   if (r >= 8) {//no word matches here, so check children!
      //if there are no further data, return false
      if (myLayer + maxLevel >= input.size() || input.at(myLayer+maxLevel)==-1) {
         return;
      }
      data = _mm_loadu_si128((__m128i*)&childBits[0]);

      and_result = _mm_and_si128(link, data);

      r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(),
         8,
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_MOST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);
      if (r >= 8) {
         return ; //op returns MAXSIZE (8) on fail
      }

      r/=2;
      unsigned int dest[4];
      _mm_storeu_si128((__m128i*)dest, and_result);
      for(int i = r; i >= 1; i--) {
         while (dest[i]!=0) {
            int tzc = __builtin_ctz(dest[i]);
            int val = 32 * i + (31 - tzc);
            contains_outputgen(prevWord, val); //TODO: Does this work? (alignment issue--but irrelv. if full, which I can guarantee!)
                                            //though once again, if I were in base 120...
            branches.at(val-40)->getAllContainingBoxesB(
                  input, output, prevWord, currentDepth);

            for (int i = 0; i < 4; i++)
               prevWord.at(myLayer+i) = 1;

            dest[i] ^= (1 << (tzc)); //clear the searched output point
         }
      }//end for (all possible outputs)
      return;
   }//end (checking children)

   r/=2;

   unsigned int dest[4];
   _mm_storeu_si128((__m128i*)dest, and_result);
   int initialOutputSize = output.size();
   for (int i = r; i < 4; i++) {
      while (dest[i]!=0) {
         int lzc = __builtin_clz(dest[i]);
         dest[i] ^= (1 << (31 - lzc)); //clear the located output point
         output.push_back(prevWord);
         int val = 32 * i + lzc;
         contains_outputgenWithNeg(output.back(), val);
      }
   }
}
