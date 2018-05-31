//SIMD_InnerGIAT.cpp

#include "SIMD_InnerGIAT.h"
#include <math.h>
#include <sstream>
#include <climits>

#include <immintrin.h>
//#include <x86intrin.h>

//static declarations
vector<vector<int> > SIMD_InnerGIAT::dummy;

SIMD_InnerGIAT::SIMD_InnerGIAT() : branches(81) {
   myLayer = 0;
  // branches.resize(81);
  childBits[0] = 0;
  childBits[1] = 0;
   for (int i = 0; i < 2; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }
   
   mStatus = GIAT_STATUS_EMPTY;
}

SIMD_InnerGIAT::SIMD_InnerGIAT(int newLayer) : branches(81) {
   myLayer = newLayer;
  // branches.resize(81);
   for (int i = 0; i < 2; i++) {
  //    wordBits[i] = 0;
      childBits[i] = 0;
   }
   mStatus = GIAT_STATUS_EMPTY;
}

int SIMD_InnerGIAT::insert(const vector<int>& box) {
   insertedCount++;
   if (insertedCount==1) {
      //store and reduce the last var
      pathToThis = box;
      for (int i = myLayer; i < box.size(); i++) {
         if (pathToThis[i] == -1) {
            int loc = pathToThis[i-1];
            int modVal = loc % 3;
            while (modVal == 1) {
               loc = (loc - 1) / 3;
               modVal = loc % 3;
            }
            pathToThis[i-1] = loc;
            break;
         }
      }
   }
   
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   
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
   }//end if words present
   
   savedInput = -5;

   
   int wordFlag = 0;
   if (box.at(myLayer+1)==-1) {
      wordFlag = 1;
   }
   
  // std::cout << "Inserting " << loc << "  layer " << myLayer << std::endl;
   
   int initialLoc = loc;
   if (wordFlag) {
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
      }
   //  std::cout <<"\nActloc: " << loc << std::endl;
      //Assert: 0 <= loc <= 120
      //I should really wrap this...
      wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
      mStatus |= GIAT_STATUS_WORD_ONLY;
      
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
      mStatus |= GIAT_STATUS_CHILDREN_ONLY;
      if (branches.at(loc-40)==NULL) {
         childBits[loc/64] |= (1ull << (63 - (loc % 64)));
         if (myLayer + 1 < _LAYERS - 1) {
            //std::map<int, std::unique_ptr<GenericIntTrie> >::value_type vt(loc-40, std::unique_ptr<SIMD_InnerGIAT>(new SIMD_Inner;
            branches.at(loc-40).reset(new SIMD_InnerGIAT(myLayer+1));
            //.reset(new SIMD_InnerGIAT(myLayer+1));
         }
         else {//if at the bottom, insert bottom-level SIMD_GIAT.
            //branches[loc-40] = std::unique_ptr<SIMD_GIATrie>(myLayer+1);
            branches.at(loc-40).reset(new SIMD_GIATrie(myLayer+1));
            // branches.at(loc-40).reset(new SIMD_GIATrie(myLayer+1));
         }
      }
      int status = branches[loc-40]->insert(box);
      if (status == INSERT_MERGE_REQ) {
         //TODO: I don't like this method...
         vector<int> tempBox = box;
         tempBox[myLayer+1] = -1;
         return this->insert(tempBox);
      }
      return status;
   }
   
}

void SIMD_InnerGIAT::clearChildBits(int loc) {
   //std::cout << "Calling me." << std::endl;
   switch(loc) {
	 case(0):
	  { // i = 0
		uint64_t temp = childBits[0] & 16777215ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073692774400ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 18446744073709551488ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 127ull;
	  }
		break;
	 case(1):
	  { // i = 0
		uint64_t temp = childBits[0] & 16777215ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073692774400ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 18446744073709551488ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 127ull;
	  }
		break;
	 case(2):
	  { // i = 1
		uint64_t temp = childBits[1] & 2305842992033824768ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16140901081675726847ull;
	  }
		break;
	 case(3):
	  { // i = 1
		uint64_t temp = childBits[1] & 17179869056ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744056529682559ull;
	  }
		break;
	 case(4):
	  { // i = 0
		uint64_t temp = childBits[0] & 16777215ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073692774400ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 18446744073709551488ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 127ull;
	  }
		break;
	 case(5):
	  { // i = 0
		uint64_t temp = childBits[0] & 32704ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709518911ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803567837184ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270141714431ull;
	  }
		break;
	 case(6):
	  { // i = 0
		uint64_t temp = childBits[0] & 63ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709551552ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 16140909843409076096ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2305834230300475519ull;
	  }
		break;
	 case(7):
	  { // i = 1
		uint64_t temp = childBits[1] & 2305842992033824768ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16140901081675726847ull;
	  }
		break;
	 case(8):
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803534348288ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270175203327ull;
	  }
		break;
	 case(9):
	  { // i = 1
		uint64_t temp = childBits[1] & 8778913153024ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446735294796398591ull;
	  }
		break;
	 case(10):
	  { // i = 1
		uint64_t temp = childBits[1] & 17179869056ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744056529682559ull;
	  }
		break;
	 case(11):
	  { // i = 1
		uint64_t temp = childBits[1] & 33488896ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073676062719ull;
	  }
		break;
	 case(12):
	  { // i = 1
		uint64_t temp = childBits[1] & 65408ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073709486207ull;
	  }
		break;
	 case(13):
	  { // i = 0
		uint64_t temp = childBits[0] & 16777215ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073692774400ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 18446744073709551488ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 127ull;
	  }
		break;
	 case(14):
	  { // i = 0
		uint64_t temp = childBits[0] & 1838599ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073707713016ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 252695124297391104ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18194048949412160511ull;
	  }
		break;
	 case(15):
	  { // i = 0
		uint64_t temp = childBits[0] & 229824ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709321791ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 16172487955033031552ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2274256118676520063ull;
	  }
		break;
	 case(16):
	  { // i = 0
		uint64_t temp = childBits[0] & 32704ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709518911ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803567837184ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270141714431ull;
	  }
		break;
	 case(17):
	  { // i = 0
		branches.at(14).reset();
		branches.at(13).reset();
		branches.at(12).reset();
		childBits[0] &= 18446744073709548031ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 492581212913664ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446251492496637951ull;
	  }
		break;
	 case(18):
	  { // i = 0
		branches.at(17).reset();
		branches.at(16).reset();
		branches.at(15).reset();
		childBits[0] &= 18446744073709551167ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 61572651614208ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446682501057937407ull;
	  }
		break;
	 case(19):
	  { // i = 0
		uint64_t temp = childBits[0] & 63ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709551552ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 16140909843409076096ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2305834230300475519ull;
	  }
		break;
	 case(20):
	  { // i = 0
		branches.at(23).reset();
		branches.at(22).reset();
		branches.at(21).reset();
		childBits[0] &= 18446744073709551608ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 962072681472ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446743111636870143ull;
	  }
		break;
	 case(21):
	  { // i = 1
		uint64_t temp = childBits[1] & 16140901184754942848ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2305842888954608767ull;
	  }
		break;
	 case(22):
	  { // i = 1
		uint64_t temp = childBits[1] & 2305842992033824768ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16140901081675726847ull;
	  }
		break;
	 case(23):
	  { // i = 1
		uint64_t temp = childBits[1] & 252695122414665728ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18194048951294885887ull;
	  }
		break;
	 case(24):
	  { // i = 1
		uint64_t temp = childBits[1] & 31586890301833216ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18415157183407718399ull;
	  }
		break;
	 case(25):
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803534348288ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270175203327ull;
	  }
		break;
	 case(26):
	  { // i = 1
		branches.at(41).reset();
		branches.at(40).reset();
		branches.at(39).reset();
		childBits[1] &= 18446251492500307967ull;
	  }
		break;
	 case(27):
	  { // i = 1
		branches.at(44).reset();
		branches.at(43).reset();
		branches.at(42).reset();
		childBits[1] &= 18446682501058396159ull;
	  }
		break;
	 case(28):
	  { // i = 1
		uint64_t temp = childBits[1] & 8778913153024ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446735294796398591ull;
	  }
		break;
	 case(29):
	  { // i = 1
		branches.at(50).reset();
		branches.at(49).reset();
		branches.at(48).reset();
		childBits[1] &= 18446743111636877311ull;
	  }
		break;
	 case(30):
	  { // i = 1
		branches.at(53).reset();
		branches.at(52).reset();
		branches.at(51).reset();
		childBits[1] &= 18446743953450467327ull;
	  }
		break;
	 case(31):
	  { // i = 1
		uint64_t temp = childBits[1] & 17179869056ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744056529682559ull;
	  }
		break;
	 case(32):
	  { // i = 1
		uint64_t temp = childBits[1] & 1882725376ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744071826826239ull;
	  }
		break;
	 case(33):
	  { // i = 1
		uint64_t temp = childBits[1] & 235340672ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073474210943ull;
	  }
		break;
	 case(34):
	  { // i = 1
		uint64_t temp = childBits[1] & 33488896ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073676062719ull;
	  }
		break;
	 case(35):
	  { // i = 1
		branches.at(68).reset();
		branches.at(67).reset();
		branches.at(66).reset();
		childBits[1] &= 18446744073705881599ull;
	  }
		break;
	 case(36):
	  { // i = 1
		branches.at(71).reset();
		branches.at(70).reset();
		branches.at(69).reset();
		childBits[1] &= 18446744073709092863ull;
	  }
		break;
	 case(37):
	  { // i = 1
		uint64_t temp = childBits[1] & 65408ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073709486207ull;
	  }
		break;
	 case(38):
	  { // i = 1
		branches.at(77).reset();
		branches.at(76).reset();
		branches.at(75).reset();
		childBits[1] &= 18446744073709544447ull;
	  }
		break;
	 case(39):
	  { // i = 1
		branches.at(80).reset();
		branches.at(79).reset();
		branches.at(78).reset();
		childBits[1] &= 18446744073709550719ull;
	  }
		break;
	 case(40):
	  { // i = 0
		uint64_t temp = childBits[0] & 16777215ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073692774400ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 18446744073709551488ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 127ull;
	  }
		break;
	 case(41):
	  { // i = 0
		uint64_t temp = childBits[0] & 4793490ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073704758125ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 5270498306774157568ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 13176245766935394047ull;
	  }
		break;
	 case(42):
	  { // i = 0
		uint64_t temp = childBits[0] & 2396745ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073707154870ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 2635249153387078784ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 15811494920322472831ull;
	  }
		break;
	 case(43):
	  { // i = 0
		uint64_t temp = childBits[0] & 1838599ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073707713016ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 252695124297391104ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18194048949412160511ull;
	  }
		break;
	 case(44):
	  { // i = 0
		branches.at(22).reset();
		branches.at(13).reset();
		branches.at(4).reset();
		childBits[0] &= 18446744073709026301ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 72198606942111744ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18374545466767439871ull;
	  }
		break;
	 case(45):
	  { // i = 0
		branches.at(23).reset();
		branches.at(14).reset();
		branches.at(5).reset();
		childBits[0] &= 18446744073709288958ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 36099303471055872ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18410644770238495743ull;
	  }
		break;
	 case(46):
	  { // i = 0
		uint64_t temp = childBits[0] & 229824ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709321791ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 16172487955033031552ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2274256118676520063ull;
	  }
		break;
	 case(47):
	  { // i = 0
		branches.at(16).reset();
		branches.at(7).reset();
		childBits[0] &= 18446744073709485951ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 4620710844295151872ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 13826033229414399743ull;
	  }
		break;
	 case(48):
	  { // i = 0
		branches.at(17).reset();
		branches.at(8).reset();
		childBits[0] &= 18446744073709518783ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 2310355422147575936ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16136388651561975679ull;
	  }
		break;
	 case(49):
	  { // i = 0
		uint64_t temp = childBits[0] & 32704ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709518911ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803567837184ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270141714431ull;
	  }
		break;
	 case(50):
	  { // i = 0
		branches.at(16).reset();
		branches.at(13).reset();
		branches.at(10).reset();
		childBits[0] &= 18446744073709542271ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 1284229590810624ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18445459844118740991ull;
	  }
		break;
	 case(51):
	  { // i = 0
		branches.at(17).reset();
		branches.at(14).reset();
		branches.at(11).reset();
		childBits[0] &= 18446744073709546943ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 642114795405312ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446101958914146303ull;
	  }
		break;
	 case(52):
	  { // i = 0
		branches.at(14).reset();
		branches.at(13).reset();
		branches.at(12).reset();
		childBits[0] &= 18446744073709548031ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 492581212913664ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446251492496637951ull;
	  }
		break;
	 case(53):
	  { // i = 0
		branches.at(13).reset();
		childBits[0] &= 18446744073709550591ull;
	  }
	  { // i = 1
		branches.at(67).reset();
		branches.at(40).reset();
		childBits[1] &= 18446603336220147711ull;
	  }
		break;
	 case(54):
	  { // i = 0
		branches.at(14).reset();
		childBits[0] &= 18446744073709551103ull;
	  }
	  { // i = 1
		branches.at(68).reset();
		branches.at(41).reset();
		childBits[1] &= 18446673704964849663ull;
	  }
		break;
	 case(55):
	  { // i = 0
		branches.at(17).reset();
		branches.at(16).reset();
		branches.at(15).reset();
		childBits[0] &= 18446744073709551167ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 61572651614208ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446682501057937407ull;
	  }
		break;
	 case(56):
	  { // i = 0
		branches.at(16).reset();
		childBits[0] &= 18446744073709551487ull;
	  }
	  { // i = 1
		branches.at(70).reset();
		branches.at(43).reset();
		childBits[1] &= 18446726481523376127ull;
	  }
		break;
	 case(57):
	  { // i = 0
		branches.at(17).reset();
		childBits[0] &= 18446744073709551551ull;
	  }
	  { // i = 1
		branches.at(71).reset();
		branches.at(44).reset();
		childBits[1] &= 18446735277616463871ull;
	  }
		break;
	 case(58):
	  { // i = 0
		uint64_t temp = childBits[0] & 63ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 0 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[0] &= 18446744073709551552ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 16140909843409076096ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2305834230300475519ull;
	  }
		break;
	 case(59):
	  { // i = 0
		branches.at(22).reset();
		branches.at(19).reset();
		childBits[0] &= 18446744073709551597ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 4611688526688307456ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 13835055547021244159ull;
	  }
		break;
	 case(60):
	  { // i = 0
		branches.at(23).reset();
		branches.at(20).reset();
		childBits[0] &= 18446744073709551606ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 2305844263344153728ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16140899810365397887ull;
	  }
		break;
	 case(61):
	  { // i = 0
		branches.at(23).reset();
		branches.at(22).reset();
		branches.at(21).reset();
		childBits[0] &= 18446744073709551608ull;
	  }
	  { // i = 1
		uint64_t temp = childBits[1] & 962072681472ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446743111636870143ull;
	  }
		break;
	 case(62):
	  { // i = 0
		branches.at(22).reset();
		childBits[0] &= 18446744073709551613ull;
	  }
	  { // i = 1
		branches.at(76).reset();
		branches.at(49).reset();
		childBits[1] &= 18446743798831642623ull;
	  }
		break;
	 case(63):
	  { // i = 0
		branches.at(23).reset();
		childBits[0] &= 18446744073709551614ull;
	  }
	  { // i = 1
		branches.at(77).reset();
		branches.at(50).reset();
		childBits[1] &= 18446743936270597119ull;
	  }
		break;
	 case(64):
	  { // i = 1
		uint64_t temp = childBits[1] & 16140901184754942848ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 2305842888954608767ull;
	  }
		break;
	 case(65):
	  { // i = 1
		branches.at(79).reset();
		branches.at(52).reset();
		branches.at(25).reset();
		childBits[1] &= 13835058020922425087ull;
	  }
		break;
	 case(66):
	  { // i = 1
		branches.at(80).reset();
		branches.at(53).reset();
		branches.at(26).reset();
		childBits[1] &= 16140901047315988351ull;
	  }
		break;
	 case(67):
	  { // i = 1
		uint64_t temp = childBits[1] & 2305842992033824768ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 16140901081675726847ull;
	  }
		break;
	 case(68):
	  { // i = 1
		uint64_t temp = childBits[1] & 658812283438235648ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 17787931790271315967ull;
	  }
		break;
	 case(69):
	  { // i = 1
		uint64_t temp = childBits[1] & 329406141719117824ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18117337931990433791ull;
	  }
		break;
	 case(70):
	  { // i = 1
		uint64_t temp = childBits[1] & 252695122414665728ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18194048951294885887ull;
	  }
		break;
	 case(71):
	  { // i = 1
		branches.at(49).reset();
		branches.at(40).reset();
		branches.at(31).reset();
		childBits[1] &= 18374545467305361407ull;
	  }
		break;
	 case(72):
	  { // i = 1
		branches.at(50).reset();
		branches.at(41).reset();
		branches.at(32).reset();
		childBits[1] &= 18410644770507456511ull;
	  }
		break;
	 case(73):
	  { // i = 1
		uint64_t temp = childBits[1] & 31586890301833216ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18415157183407718399ull;
	  }
		break;
	 case(74):
	  { // i = 1
		branches.at(52).reset();
		branches.at(43).reset();
		branches.at(34).reset();
		childBits[1] &= 18437719247909027839ull;
	  }
		break;
	 case(75):
	  { // i = 1
		branches.at(53).reset();
		branches.at(44).reset();
		branches.at(35).reset();
		childBits[1] &= 18442231660809289727ull;
	  }
		break;
	 case(76):
	  { // i = 1
		uint64_t temp = childBits[1] & 4494803534348288ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18442249270175203327ull;
	  }
		break;
	 case(77):
	  { // i = 1
		branches.at(43).reset();
		branches.at(40).reset();
		branches.at(37).reset();
		childBits[1] &= 18445459844128309247ull;
	  }
		break;
	 case(78):
	  { // i = 1
		branches.at(44).reset();
		branches.at(41).reset();
		branches.at(38).reset();
		childBits[1] &= 18446101958918930431ull;
	  }
		break;
	 case(79):
	  { // i = 1
		branches.at(41).reset();
		branches.at(40).reset();
		branches.at(39).reset();
		childBits[1] &= 18446251492500307967ull;
	  }
		break;
	 case(80):
	  { // i = 1
		branches.at(40).reset();
		childBits[1] &= 18446603336221196287ull;
	  }
		break;
	 case(81):
	  { // i = 1
		branches.at(41).reset();
		childBits[1] &= 18446673704965373951ull;
	  }
		break;
	 case(82):
	  { // i = 1
		branches.at(44).reset();
		branches.at(43).reset();
		branches.at(42).reset();
		childBits[1] &= 18446682501058396159ull;
	  }
		break;
	 case(83):
	  { // i = 1
		branches.at(43).reset();
		childBits[1] &= 18446726481523507199ull;
	  }
		break;
	 case(84):
	  { // i = 1
		branches.at(44).reset();
		childBits[1] &= 18446735277616529407ull;
	  }
		break;
	 case(85):
	  { // i = 1
		uint64_t temp = childBits[1] & 8778913153024ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446735294796398591ull;
	  }
		break;
	 case(86):
	  { // i = 1
		branches.at(52).reset();
		branches.at(49).reset();
		branches.at(46).reset();
		childBits[1] &= 18446741565448650751ull;
	  }
		break;
	 case(87):
	  { // i = 1
		branches.at(53).reset();
		branches.at(50).reset();
		branches.at(47).reset();
		childBits[1] &= 18446742819579101183ull;
	  }
		break;
	 case(88):
	  { // i = 1
		branches.at(50).reset();
		branches.at(49).reset();
		branches.at(48).reset();
		childBits[1] &= 18446743111636877311ull;
	  }
		break;
	 case(89):
	  { // i = 1
		branches.at(49).reset();
		childBits[1] &= 18446743798831644671ull;
	  }
		break;
	 case(90):
	  { // i = 1
		branches.at(50).reset();
		childBits[1] &= 18446743936270598143ull;
	  }
		break;
	 case(91):
	  { // i = 1
		branches.at(53).reset();
		branches.at(52).reset();
		branches.at(51).reset();
		childBits[1] &= 18446743953450467327ull;
	  }
		break;
	 case(92):
	  { // i = 1
		branches.at(52).reset();
		childBits[1] &= 18446744039349813247ull;
	  }
		break;
	 case(93):
	  { // i = 1
		branches.at(53).reset();
		childBits[1] &= 18446744056529682431ull;
	  }
		break;
	 case(94):
	  { // i = 1
		uint64_t temp = childBits[1] & 17179869056ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744056529682559ull;
	  }
		break;
	 case(95):
	  { // i = 1
		uint64_t temp = childBits[1] & 4908534016ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744068801017599ull;
	  }
		break;
	 case(96):
	  { // i = 1
		uint64_t temp = childBits[1] & 2454267008ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744071255284607ull;
	  }
		break;
	 case(97):
	  { // i = 1
		uint64_t temp = childBits[1] & 1882725376ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744071826826239ull;
	  }
		break;
	 case(98):
	  { // i = 1
		branches.at(76).reset();
		branches.at(67).reset();
		branches.at(58).reset();
		childBits[1] &= 18446744073171630079ull;
	  }
		break;
	 case(99):
	  { // i = 1
		branches.at(77).reset();
		branches.at(68).reset();
		branches.at(59).reset();
		childBits[1] &= 18446744073440590847ull;
	  }
		break;
	 case(100):
	  { // i = 1
		uint64_t temp = childBits[1] & 235340672ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073474210943ull;
	  }
		break;
	 case(101):
	  { // i = 1
		branches.at(79).reset();
		branches.at(70).reset();
		branches.at(61).reset();
		childBits[1] &= 18446744073642311423ull;
	  }
		break;
	 case(102):
	  { // i = 1
		branches.at(80).reset();
		branches.at(71).reset();
		branches.at(62).reset();
		childBits[1] &= 18446744073675931519ull;
	  }
		break;
	 case(103):
	  { // i = 1
		uint64_t temp = childBits[1] & 33488896ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073676062719ull;
	  }
		break;
	 case(104):
	  { // i = 1
		branches.at(70).reset();
		branches.at(67).reset();
		branches.at(64).reset();
		childBits[1] &= 18446744073699983359ull;
	  }
		break;
	 case(105):
	  { // i = 1
		branches.at(71).reset();
		branches.at(68).reset();
		branches.at(65).reset();
		childBits[1] &= 18446744073704767487ull;
	  }
		break;
	 case(106):
	  { // i = 1
		branches.at(68).reset();
		branches.at(67).reset();
		branches.at(66).reset();
		childBits[1] &= 18446744073705881599ull;
	  }
		break;
	 case(107):
	  { // i = 1
		branches.at(67).reset();
		childBits[1] &= 18446744073708503039ull;
	  }
		break;
	 case(108):
	  { // i = 1
		branches.at(68).reset();
		childBits[1] &= 18446744073709027327ull;
	  }
		break;
	 case(109):
	  { // i = 1
		branches.at(71).reset();
		branches.at(70).reset();
		branches.at(69).reset();
		childBits[1] &= 18446744073709092863ull;
	  }
		break;
	 case(110):
	  { // i = 1
		branches.at(70).reset();
		childBits[1] &= 18446744073709420543ull;
	  }
		break;
	 case(111):
	  { // i = 1
		branches.at(71).reset();
		childBits[1] &= 18446744073709486079ull;
	  }
		break;
	 case(112):
	  { // i = 1
		uint64_t temp = childBits[1] & 65408ull;
		while (temp!=0) {
			int tzc = __builtin_ctzll(temp);
			int val = 64 + (63 - tzc);
			branches.at(val - 40).reset();
			temp ^= (1ull << (tzc));
		}
		childBits[1] &= 18446744073709486207ull;
	  }
		break;
	 case(113):
	  { // i = 1
		branches.at(79).reset();
		branches.at(76).reset();
		branches.at(73).reset();
		childBits[1] &= 18446744073709532927ull;
	  }
		break;
	 case(114):
	  { // i = 1
		branches.at(80).reset();
		branches.at(77).reset();
		branches.at(74).reset();
		childBits[1] &= 18446744073709542271ull;
	  }
		break;
	 case(115):
	  { // i = 1
		branches.at(77).reset();
		branches.at(76).reset();
		branches.at(75).reset();
		childBits[1] &= 18446744073709544447ull;
	  }
		break;
	 case(116):
	  { // i = 1
		branches.at(76).reset();
		childBits[1] &= 18446744073709549567ull;
	  }
		break;
	 case(117):
	  { // i = 1
		branches.at(77).reset();
		childBits[1] &= 18446744073709550591ull;
	  }
		break;
	 case(118):
	  { // i = 1
		branches.at(80).reset();
		branches.at(79).reset();
		branches.at(78).reset();
		childBits[1] &= 18446744073709550719ull;
	  }
		break;
	 case(119):
	  { // i = 1
		branches.at(79).reset();
		childBits[1] &= 18446744073709551359ull;
	  }
		break;
	 case(120):
	  { // i = 1
		branches.at(80).reset();
		childBits[1] &= 18446744073709551487ull;
	  }
		break;
	}

}

      struct timeval totalTime;
      int leRound = 0;
#include <sys/time.h>

bool SIMD_InnerGIAT::handleSingleton(
   const vector<int>& box, 
   vector<int>& output, 
   vector<vector<int> >& setOfOutputs, 
   int mode, int& currentDepth)
{
   // struct timeval tv1;
   // gettimeofday(&tv1, NULL);     // mark start time
   //convert everything to char
   if (currentNonce != currentInput.nonce) {
      if (!currentInput.nonce) {
         currentInput.box.resize(((box.size()/32)+1)*32, 0);
         singletonCandidate.resize(currentInput.box.size());
         minLayerShiftedOver = 0;
      }
      getUcharFormatNeg(currentInput.box, box, myLayer);
      currentInput.nonce = currentNonce;
      greatestSingletonDepth = 0;
   }
   // struct timeval tv2;          // mark finish time
   // gettimeofday(&tv2, NULL);
   // totalTime.tv_sec += tv2.tv_sec - tv1.tv_sec;
   // totalTime.tv_usec += tv2.tv_usec - tv1.tv_usec;
   
   // if (++leRound % 1000000 == 0) {
      // std::stringstream oss;
      // oss 
         // << "seconds elapsed: " 
         // << double(totalTime.tv_sec) + 
         // double(totalTime.tv_usec)/1000000;
      // std::cout << oss.str() << std::endl;  
   // }         
   
   for (int i = 0; i < box.size(); i+=32) {
      __m256i _path = _mm256_loadu_si256((__m256i*)(pathAsChar.data()+i));
      __m256i _box  = _mm256_loadu_si256((__m256i*)(currentInput.box.data()+i));
      
      __m256i orResult = _mm256_and_si256(_path, _box);
      __m256i zero256 = _mm256_setzero_si256();
      __m256i compareEqual = _mm256_cmpeq_epi8(orResult, zero256);
    
      unsigned int mask = _mm256_movemask_epi8(compareEqual);         
      if (mask != 0xFFFFFFFF) {
         if (mode == MODE_GACB) {
            //calculate currentDepth
            mask = ~mask;
            int tzc = __builtin_ctz(mask);
            int newCurrentDepth = i * 32 + tzc;
            
            //check for new singleton
            if (newCurrentDepth > greatestSingletonDepth) {
               //std::cout << "New one at depth " << myLayer << " breaking at " << newCurrentDepth << " continuing through " << maxDepthOfFirstInput << std::endl;
               //make sure we don't have a deeper normal spot
               if (newCurrentDepth > currentDepth) {
                  if (greatestSingletonDepth > currentDepth) {
                     currentDepth = greatestSingletonDepth;
                  }
                  greatestSingletonDepth = newCurrentDepth;
                  for (int i = 0; i < maxDepthOfFirstInput; i++) {
                     singletonCandidate.at(i) = pathToThis.at(i);
                  }
                  for (int i = maxDepthOfFirstInput; i < singletonCandidate.size(); i++) {
                     singletonCandidate.at(i) = 40;
                  }
               }         
            }
            else { //we do not have a new singleton
               if (newCurrentDepth > currentDepth) {
                  currentDepth = newCurrentDepth;
               }
            }
            
            // if (newCurrentDepth > currentDepth) {
               // currentDepth = newCurrentDepth;
               // if (maxDepthOfFirstInput < greatestSingletonDepth) {
                  // greatestSingletonDepth = maxDepthOfFirstInput;
                  // for (int i = 0; i < maxDepthOfFirstInput; i++) {
                     // singletonCandidate.at(i) = pathToThis.at(i);
                  // }
               // }
            // }
         }
         //nothing to do if contains
         return false;
      }

   }
   if (mode == MODE_CONTAINS) {
      for (int i = myLayer; i < maxDepthOfFirstInput; i++) {
         output.at(i) = pathToThis.at(i);
      }
   }
   else { // (mode == MODE_GACB)
      setOfOutputs.push_back(output);
      vector<int>* printingOutput = &(setOfOutputs.back());
      for (int i = myLayer; i < maxDepthOfFirstInput; i++) {
         (*printingOutput)[i] = pathToThis[i];
      }
      (*printingOutput).at(maxDepthOfFirstInput) = -1;
   }
   //note: nothing special to do if mode == MODE_CONTAINS
   return true;
}

bool SIMD_InnerGIAT::contains(const vector<int>& box, 
                                   vector<int>& output)
{
   if (myLayer == 0) {
      currentNonce++;
   }
//  std::cout << "Calling inner contains" << std::endl;
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   int loc = box.at(myLayer);
      
    
   //detect and handle singletons
   if (useSingletons &&
       (insertedCount == 1 ) && 
       (mStatus == GIAT_STATUS_CHILDREN_ONLY)) 
   {
      int dummyDepth;
      return handleSingleton(box, output, dummy, MODE_CONTAINS, dummyDepth);
   }
   
   if (loc==savedInput) {
   
      for(int i = 0; i < savedChildren.size(); i++) {   
         if (branches.at(savedChildren.at(i) - 40)->contains(box, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.at(myLayer) = savedChildren.at(i);
            return true;
         }
      }//end for (all possible outputs)
      //if we've reached here, no children have it, and we don't have it
      return false;
      
   }
      
   //START SIMD ====================
  // if (mStatus & GIAT_STATUS_BOTH) {
      __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
      __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
    //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
    //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
      
      __m256i and_result = _mm256_and_si256(link, data);
      
      //find location of first set bit in and_result
      uint64_t dest[4];
      _mm256_store_si256((__m256i*)dest, and_result);

      for (int i = 0; i < 2; i++) {
         while (dest[i]!=0) {
            int lzc = __builtin_clzll(dest[i]);
            //dest[i] ^= (1ull << (63 - lzc)); //No need to clear the located output point here!
            int val = 64 * i + lzc;
            
            output.at(myLayer) = val;
            return true;
         }
      }
 ///  }//end if (words exist)
   
 //  if (mStatus | GIAT_STATUS_CHILDREN_ONLY) {
      //If we've reached here, we got no word matches, so check children!
   //    std::cout << "checking children" << std::endl;
      if (myLayer + 1 >= box.size() || box.at(myLayer+1)==-1) {
         return false;
      }

      //it's a new input and we need children, so update the list
      savedInput = loc;
      savedChildren.clear();
      
      //SIMD results already calculated in dest[2:3]
      for(int i = 3; i >= 2; i--) {
         while (dest[i]!=0) {
            //note that we prefer higher numbers on searching children
            int tzc = __builtin_ctzll(dest[i]);
            int val;
            val = 64 * (i-2) + (63 - tzc);
            savedChildren.push_back(val);
            dest[i] ^= (1ull << (tzc)); //clear the searched output point

         }
      }
      
      for(int i = 0; i < savedChildren.size(); i++) {
         
         if (branches.at(savedChildren.at(i) - 40)->contains(box, output)) {
   //           std::cout << "Output at layer " << myLayer << "is val " << val << std::endl;
            output.at(myLayer) = savedChildren.at(i);
           // contains_outputgen(output, val);
            return true;
         }
      }//end for (all possible outputs)
//   }//end if (children exist)
   //if we've reached here, no children have it, and we don't have it
   return false;

}

void SIMD_InnerGIAT::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, 
                  int& currentDepth)                   
{
   if (myLayer == 0) {
      greatestSingletonDepth = 0;
   }
   
   if (useSingletons &&
       (insertedCount == 1 ) && 
       (mStatus == GIAT_STATUS_CHILDREN_ONLY)) 
    {
      //handleSingleton(input, dupePrevword, dupeOutput, MODE_GACB, dupeCurrentDepth);      
      handleSingleton(input, prevWord, output, MODE_GACB, currentDepth);
      return;
   }
                     
   if (currentDepth < myLayer) {
      currentDepth = myLayer;
   }
   
  //std::cout << "gacbb inner layer " << myLayer <<" with count " << insertedCount <<" and status " <<std::hex << mStatus << std::dec <<"..." << std::endl;
   int loc = input.at(myLayer);
   //START SIMD ====================
   
   //detect and handle singletons
   // vector<vector<int> > dupeOutput(output);
   // vector<int> dupePrevword(prevWord);
   // int dupeCurrentDepth = currentDepth;
   
   if (loc != savedInput) {
      
      //match words
      __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
   __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
 //  std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;
 //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;
   
   __m256i and_result = _mm256_and_si256(link, data);
   
   //find location of first set bit in and_result
   uint64_t dest[4];
   _mm256_store_si256((__m256i*)dest, and_result);

      for (int i = 0; i < 2; i++) {
         while (dest[i]!=0) {
            int lzc = __builtin_clzll(dest[i]);
            dest[i] ^= (1ull << (63 - lzc)); //clear the located output point
            int val = 64 * i + lzc;
            //contains_outputgenWithNeg(output.back(), val);       
            
            output.push_back(prevWord);
            output.back().at(myLayer) = val;
            output.back().at(myLayer+1) = -1;

            return;
         }
      }
      
      //check children!
      //if there are no further data, return false
      /*if (myLayer + 1 >= input.size() || input.at(myLayer+1)==-1) {
         return;
      }*/
      
      savedInput = loc; //only save if i can guarantee all vectors will be set.
      savedChildren.clear();      

      for(int i = 3; i >= 2; i--) {
         while (dest[i]!=0) {
            int tzc = __builtin_ctzll(dest[i]);
            int val = 64 * (i-2) + (63 - tzc);
            
            dest[i] ^= (1ull << (tzc)); //clear the searched output point
            
            savedChildren.push_back(val);
         }
      }//end for (all possible outputs)
     // return;
   }//end (if input not saved)
   
   
   //if there are no further data, return
   if (myLayer + 1 >= input.size() || input.at(myLayer+1)==-1) {

      return;
   }
   
   //check children
   for (int i = 0; i < savedChildren.size(); i++) {
      prevWord.at(myLayer) = savedChildren.at(i);
      branches.at(savedChildren.at(i)-40)->getAllContainingBoxesB(
            input, output, prevWord, currentDepth);
            
      this->resetPrevWord(prevWord, myLayer);
      
      if ((insertedCount == 1)
               && (mStatus == GIAT_STATUS_CHILDREN_ONLY))
      {
         // if (prevWord != dupePrevword || output != dupeOutput || currentDepth != dupeCurrentDepth) {
            // std::cout << "ERROR MISMATCH IS HUMAN: " << myLayer << std::endl;
            // std::cout << "prevWord: "; printBox(prevWord);
            // std::cout << "dupePrev: "; printBox(dupePrevword);
            // std::cout << "outputBack: "; printBox(output.back());
            // std::cout << "dupeOutBac: "; printBox(dupeOutput.back());
            // std::cout << "currentDepth: " << currentDepth << std::endl;
            // std::cout << "dupCurrDepth: " << dupeCurrentDepth << std::endl;
            // string temp;
            // std::cin >> temp;
         // }
      }
   }
   
}

void SIMD_InnerGIAT::resetPrevWord(vector<int>& prevWord, int& myLayer) const {
   prevWord.at(myLayer) = -1;
}
