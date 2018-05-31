//SIMD_GIATrie2.cpp

#include "SIMD_GIATrie2.h"
#include <math.h>

#include <nmmintrin.h>
#include <emmintrin.h>

//definer
constexpr uint32_t SIMD_GIATrie2::links[][maxLevel];

SIMD_GIATrie2::SIMD_GIATrie2() {
   myLayer = 0;
   for (int i = 0; i < 4; i++) {
      wordBits[i] = 0;
   }
}

SIMD_GIATrie2::SIMD_GIATrie2(int newLayer) {
   myLayer = newLayer;
 //  if (myLayer!=35) std::cout << "MyLayer: " << myLayer << std::endl;
   for (int i = 0; i < 4; i++) {
      wordBits[i] = 0;
   }
}

void SIMD_GIATrie2::setMaxNodeID(int mNID) {
   maxNodeID = mNID;
}

//need to use doubles for precision
//2^52 > max_int, so we're safe.
//...Does flipping endianness screw this up? Probably.
//assert: 0 <= val <= 2^31-1
int SIMD_GIATrie2::log2FloorInv(long val) const {
   double d_val = (double) val; //& operator needs lvalue
   return 31 - (((*(int *) &d_val + 1) >> 20) - 1023); //Grab the exponent
}

//assert: 0 <= val <= ~2^23
int SIMD_GIATrie2::log2FloorInv_16(int val) const {
   float d_val = (float) val; //& operator needs lvalue
   return 15 - (((*(int *) &d_val) >> 23) - 127); //Grab the exponent
}

//lookup table for generating output
//generated from switchGenerator in the sandbox
void SIMD_GIATrie2::contains_outputgen(vector<int>& output, int i_output) const {
   switch(i_output) {
      case(0):
      output.at(myLayer+0) = -1;
      break;

      case(1):
      output.at(myLayer+0) = 1;
      break;

      case(2):
      output.at(myLayer+0) = 2;
      break;

      case(3):
      output.at(myLayer+0) = 3;
      break;

      case(4):
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(5):
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(6):
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(7):
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(8):
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(9):
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(10):
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(11):
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(12):
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(13):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(14):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(15):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(16):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(17):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(18):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(19):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(20):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(21):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(22):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(23):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(24):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(25):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(26):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(27):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(28):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(29):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(30):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(31):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(32):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(33):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(34):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(35):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(36):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(37):
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(38):
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(39):
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(40):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(41):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(42):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(43):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(44):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(45):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(46):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(47):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(48):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 1;
      break;

      case(49):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(50):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(51):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(52):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(53):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(54):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(55):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(56):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(57):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 1;
      break;

      case(58):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(59):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(60):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(61):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(62):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(63):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(64):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(65):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(66):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 1;
      break;

      case(67):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(68):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(69):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(70):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(71):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(72):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(73):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(74):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(75):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 2;
      break;

      case(76):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(77):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(78):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(79):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(80):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(81):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(82):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(83):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(84):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 2;
      break;

      case(85):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(86):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(87):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(88):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(89):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(90):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(91):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(92):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(93):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 2;
      break;

      case(94):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(95):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(96):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(97):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(98):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(99):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(100):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(101):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(102):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 1;
      output.at(myLayer+0) = 3;
      break;

      case(103):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(104):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(105):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(106):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(107):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(108):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(109):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(110):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(111):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 2;
      output.at(myLayer+0) = 3;
      break;

      case(112):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(113):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(114):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 1;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(115):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(116):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(117):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 2;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(118):
      output.at(myLayer+3) = 1;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(119):
      output.at(myLayer+3) = 2;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      case(120):
      output.at(myLayer+3) = 3;
      output.at(myLayer+2) = 3;
      output.at(myLayer+1) = 3;
      output.at(myLayer+0) = 3;
      break;

      }
}

//same as above, but inserts the kill command at the end of the vector
void SIMD_GIATrie2::contains_outputgenWithNeg(vector<int>& output, int i_output) const {
   switch(i_output) {
      case(0):
         output.at(myLayer+1) = -1;
         output.at(myLayer+0) = -1;
      break;

      case(1):
         output.at(myLayer+1) = -1;
         output.at(myLayer+0) = 1;
      break;

      case(2):
         output.at(myLayer+1) = -1;
         output.at(myLayer+0) = 2;
      break;

      case(3):
         output.at(myLayer+1) = -1;
         output.at(myLayer+0) = 3;
      break;

      case(4):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(5):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(6):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(7):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(8):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(9):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(10):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(11):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(12):
         output.at(myLayer+2) = -1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(13):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(14):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(15):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(16):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(17):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(18):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(19):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(20):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(21):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(22):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(23):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(24):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(25):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(26):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(27):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(28):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(29):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(30):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(31):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(32):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(33):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(34):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(35):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(36):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(37):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(38):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(39):
         output.at(myLayer+3) = -1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(40):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(41):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(42):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(43):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(44):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(45):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(46):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(47):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(48):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 1;
      break;

      case(49):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(50):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(51):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(52):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(53):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(54):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(55):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(56):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(57):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 1;
      break;

      case(58):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(59):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(60):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(61):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(62):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(63):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(64):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(65):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(66):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 1;
      break;

      case(67):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(68):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(69):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(70):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(71):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(72):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(73):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(74):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(75):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 2;
      break;

      case(76):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(77):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(78):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(79):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(80):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(81):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(82):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(83):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(84):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 2;
      break;

      case(85):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(86):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(87):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(88):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(89):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(90):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(91):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(92):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(93):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 2;
      break;

      case(94):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(95):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(96):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(97):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(98):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(99):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(100):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(101):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(102):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 1;
         output.at(myLayer+0) = 3;
      break;

      case(103):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(104):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(105):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(106):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(107):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(108):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(109):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(110):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(111):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 2;
         output.at(myLayer+0) = 3;
      break;

      case(112):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(113):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(114):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 1;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(115):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(116):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(117):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 2;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(118):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 1;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(119):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 2;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

      case(120):
         output.at(myLayer+4) = -1;
         output.at(myLayer+3) = 3;
         output.at(myLayer+2) = 3;
         output.at(myLayer+1) = 3;
         output.at(myLayer+0) = 3;
      break;

   }
}

bool SIMD_GIATrie2::contains(const vector<int>& box,
                                   vector<int>& output)
{
//   std::cout << "Calling contains" << std::endl;
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   int loc = 0;
   for (int i = myLayer; i < box.size() && box.at(i)!=-1; i++) {
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

   if (r >= 8) {
  //    std::cout << "Returning early" << std::endl;
      return false; //op returns MAXSIZE (8) on fail
   }
   r/=2;
   //--Everything from here on takes 1/8 of total time

   //count leading zeros
   unsigned int dest[4];
   _mm_storeu_si128((__m128i*)dest, and_result);

   unsigned int internalVal = dest[r];
   //TODO: test using SIMD version instead
   int i_output = __builtin_clz(internalVal) + 32 * r;
   //int i_output = log2FloorInv(internalVal) + 32 * r; //<--slower for lg.#
   //END SIMD ======================

   //move i_output data into output
 //  std::cout << "i_output is " << i_output << std::endl;
   contains_outputgen(output, i_output);

 //     std::cout << "REturning success" << std::endl;
   return true;

}

//generated using ccGenerator in sandbox.cpp
//turns out SIMD here is slightly slower in practice.
void SIMD_GIATrie2::clearChildren(int loc) {
   switch(loc) {
     case(0):
        wordBits[0] &= 2147483648ul;
        wordBits[1] &= 0ul;
        wordBits[2] &= 0ul;
        wordBits[3] &= 127ul; //oddity caused by last 7 bits being !used
        break;
     case(1):
        wordBits[0] &= 3221225472ul;
        wordBits[1] &= 0ul;
        wordBits[2] &= 0ul;
        wordBits[3] &= 127ul;
        break;
     case(2):
        wordBits[0] &= 4265606145ul;
        wordBits[2] &= 3758096387ul;
        break;
     case(3):
        wordBits[0] &= 4291297278ul;
        wordBits[1] &= 16777215ul;
        wordBits[2] &= 4294967292ul;
        wordBits[3] &= 127ul;
        break;
     case(4):
        wordBits[0] &= 4160749568ul;
        wordBits[1] &= 0ul;
        wordBits[2] &= 0ul;
        wordBits[3] &= 127ul;
        break;
     case(5):
        wordBits[0] &= 4285472655ul;
        wordBits[1] &= 3355410495ul;
        wordBits[2] &= 4293920767ul;
        wordBits[3] &= 4261478399ul;
        break;
     case(6):
        wordBits[0] &= 4290241521ul;
        wordBits[1] &= 4177526720ul;
        wordBits[2] &= 536868867ul;
        wordBits[3] &= 4294901887ul;
        break;
     case(7):
        wordBits[0] &= 4282383361ul;
        wordBits[2] &= 3758096387ul;
        break;
     case(8):
        wordBits[0] &= 4294967183ul;
        wordBits[2] &= 4293920767ul;
        break;
     case(9):
        wordBits[0] &= 4294967281ul;
        wordBits[2] &= 4294965251ul;
        break;
     case(10):
        wordBits[0] &= 4293394430ul;
        wordBits[1] &= 16777215ul;
        wordBits[2] &= 4294967292ul;
        wordBits[3] &= 127ul;
        break;
     case(11):
        wordBits[1] &= 3355443199ul;
        wordBits[3] &= 4261478399ul;
        break;
     case(12):
        wordBits[1] &= 4177526783ul;
        wordBits[3] &= 4294901887ul;
        break;
     case(13):
        wordBits[0] &= 4294705152ul;
        wordBits[1] &= 0ul;
        wordBits[2] &= 0ul;
        wordBits[3] &= 127ul;
        break;
     case(14):
        wordBits[0] &= 4294948571ul;
        wordBits[1] &= 1843655160ul;
        wordBits[2] &= 4236132127ul;
        wordBits[3] &= 2412241919ul;
        break;
     case(15):
        wordBits[0] &= 4294957933ul;
        wordBits[1] &= 3070000703ul;
        wordBits[2] &= 529516515ul;
        wordBits[3] &= 4059626623ul;
        break;
     case(16):
        wordBits[0] &= 4294942607ul;
        wordBits[1] &= 3355410495ul;
        wordBits[2] &= 4293920767ul;
        wordBits[3] &= 4261478399ul;
        break;
     case(17):
        wordBits[0] &= 4294967263ul;
        wordBits[1] &= 4026528255ul;
        wordBits[2] &= 4294852607ul;
        wordBits[3] &= 4291297279ul;
        break;
     case(18):
        wordBits[0] &= 4294967279ul;
        wordBits[1] &= 4160749119ul;
        wordBits[2] &= 4294952959ul;
        wordBits[3] &= 4294508543ul;
        break;
     case(19):
        wordBits[0] &= 4294964209ul;
        wordBits[1] &= 4177526720ul;
        wordBits[2] &= 536868867ul;
        wordBits[3] &= 4294901887ul;
        break;
     case(20):
        wordBits[0] &= 4294967291ul;
        wordBits[1] &= 4261412856ul;
        wordBits[2] &= 4294967071ul;
        wordBits[3] &= 4294960127ul;
        break;
     case(21):
        wordBits[0] &= 4294967293ul;
        wordBits[1] &= 4278190079ul;
        wordBits[2] &= 536870883ul;
        wordBits[3] &= 4294966399ul;
        break;
     case(22):
        wordBits[0] &= 4294966785ul;
        wordBits[2] &= 3758096387ul;
        break;
     case(23):
        wordBits[0] &= 4294967259ul;
        wordBits[2] &= 4236132127ul;
        break;
     case(24):
        wordBits[0] &= 4294967277ul;
        wordBits[2] &= 4287612899ul;
        break;
     case(25):
        wordBits[0] &= 4294967247ul;
        wordBits[2] &= 4293920767ul;
        break;
     case(26):
        wordBits[2] &= 4294852607ul;
        break;
     case(27):
        wordBits[2] &= 4294952959ul;
        break;
     case(28):
        wordBits[0] &= 4294967289ul;
        wordBits[2] &= 4294965251ul;
        break;
     case(29):
        wordBits[2] &= 4294967071ul;
        break;
     case(30):
        wordBits[2] &= 4294967267ul;
        break;
     case(31):
        wordBits[1] &= 16777215ul;
        wordBits[2] &= 4294967292ul;
        wordBits[3] &= 127ul;
        break;
     case(32):
        wordBits[1] &= 3992977407ul;
        wordBits[3] &= 2412241919ul;
        break;
     case(33):
        wordBits[1] &= 4143972351ul;
        wordBits[3] &= 4059626623ul;
        break;
     case(34):
        wordBits[1] &= 3892314111ul;
        wordBits[3] &= 4261478399ul;
        break;
     case(35):
        wordBits[3] &= 4291297279ul;
        break;
     case(36):
        wordBits[3] &= 4294508543ul;
        break;
     case(37):
        wordBits[1] &= 4244635647ul;
        wordBits[3] &= 4294901887ul;
        break;
     case(38):
        wordBits[3] &= 4294960127ul;
        break;
     case(39):
        wordBits[3] &= 4294966399ul;
        break;
     case(40):
        wordBits[1] &= 4286578688ul;
        wordBits[2] &= 0ul;
        wordBits[3] &= 127ul;
        break;
     case(41):
        wordBits[1] &= 4294368109ul;
        wordBits[2] &= 3067833782ul;
        wordBits[3] &= 3681400575ul;
        break;
     case(42):
        wordBits[1] &= 4294667702ul;
        wordBits[2] &= 3681400539ul;
        wordBits[3] &= 1840700287ul;
        break;
     case(43):
        wordBits[1] &= 4294177272ul;
        wordBits[2] &= 4236132127ul;
        wordBits[3] &= 2412241919ul;
        break;
     case(44):
        wordBits[1] &= 4294966269ul;
        wordBits[2] &= 4278157247ul;
        wordBits[3] &= 3757045759ul;
        break;
     case(45):
        wordBits[1] &= 4294966782ul;
        wordBits[2] &= 4286562271ul;
        wordBits[3] &= 4026006527ul;
        break;
     case(46):
        wordBits[1] &= 4294868543ul;
        wordBits[2] &= 529516515ul;
        wordBits[3] &= 4059626623ul;
        break;
     case(47):
        wordBits[1] &= 4294967167ul;
        wordBits[2] &= 3219124215ul;
        wordBits[3] &= 4227727103ul;
        break;
     case(48):
        wordBits[1] &= 4294967231ul;
        wordBits[2] &= 3757045755ul;
        wordBits[3] &= 4261347199ul;
        break;
     case(49):
        wordBits[1] &= 4294950975ul;
        wordBits[2] &= 4293920767ul;
        wordBits[3] &= 4261478399ul;
        break;
     case(50):
        wordBits[1] &= 4294966143ul;
        wordBits[2] &= 4294668287ul;
        wordBits[3] &= 4285399039ul;
        break;
     case(51):
        wordBits[1] &= 4294966719ul;
        wordBits[2] &= 4294817791ul;
        wordBits[3] &= 4290183167ul;
        break;
     case(52):
        wordBits[1] &= 4294965759ul;
        wordBits[2] &= 4294852607ul;
        wordBits[3] &= 4291297279ul;
        break;
     case(53):
        wordBits[2] &= 4294934527ul;
        wordBits[3] &= 4293918719ul;
        break;
     case(54):
        wordBits[2] &= 4294950911ul;
        wordBits[3] &= 4294443007ul;
        break;
     case(55):
        wordBits[1] &= 4294967103ul;
        wordBits[2] &= 4294952959ul;
        wordBits[3] &= 4294508543ul;
        break;
     case(56):
        wordBits[2] &= 4294963199ul;
        wordBits[3] &= 4294836223ul;
        break;
     case(57):
        wordBits[2] &= 4294965247ul;
        wordBits[3] &= 4294901759ul;
        break;
     case(58):
        wordBits[1] &= 4294967264ul;
        wordBits[2] &= 536868867ul;
        wordBits[3] &= 4294901887ul;
        break;
     case(59):
        wordBits[1] &= 4294967293ul;
        wordBits[2] &= 3221224887ul;
        wordBits[3] &= 4294948607ul;
        break;
     case(60):
        wordBits[1] &= 4294967294ul;
        wordBits[2] &= 3758096091ul;
        wordBits[3] &= 4294957951ul;
        break;
     case(61):
        wordBits[1] &= 4294967292ul;
        wordBits[2] &= 4294967071ul;
        wordBits[3] &= 4294960127ul;
        break;
     case(62):
        wordBits[2] &= 4294967231ul;
        wordBits[3] &= 4294965247ul;
        break;
     case(63):
        wordBits[2] &= 4294967263ul;
        wordBits[3] &= 4294966271ul;
        break;
     case(64):
        wordBits[2] &= 2684354531ul;
        wordBits[3] &= 4294966399ul;
        break;
     case(65):
        wordBits[2] &= 4294967287ul;
        wordBits[3] &= 4294967039ul;
        break;
     case(66):
        wordBits[2] &= 4294967291ul;
        wordBits[3] &= 4294967167ul;
        break;
     case(67):
        wordBits[2] &= 4026531843ul;
        break;
     case(68):
        wordBits[2] &= 4275793335ul;
        break;
     case(69):
        wordBits[2] &= 4285380315ul;
        break;
     case(70):
        wordBits[2] &= 4269686559ul;
        break;
     case(71):
        wordBits[2] &= 4294934463ul;
        break;
     case(72):
        wordBits[2] &= 4294950879ul;
        break;
     case(73):
        wordBits[2] &= 4291807203ul;
        break;
     case(74):
        wordBits[2] &= 4294963191ul;
        break;
     case(75):
        wordBits[2] &= 4294965243ul;
        break;
     case(76):
        wordBits[2] &= 4294445055ul;
        break;
     case(77):
        wordBits[2] &= 4294930431ul;
        break;
     case(78):
        wordBits[2] &= 4294948863ul;
        break;
     case(79):
        wordBits[2] &= 4294918143ul;
        break;
     case(80):
        break;
     case(81):
        break;
     case(82):
        wordBits[2] &= 4294961151ul;
        break;
     case(83):
        break;
     case(84):
        break;
     case(85):
        wordBits[2] &= 4294966275ul;
        break;
     case(86):
        wordBits[2] &= 4294967223ul;
        break;
     case(87):
        wordBits[2] &= 4294967259ul;
        break;
     case(88):
        wordBits[2] &= 4294967199ul;
        break;
     case(89):
        break;
     case(90):
        break;
     case(91):
        wordBits[2] &= 4294967283ul;
        break;
     case(92):
        break;
     case(93):
        break;
     case(94):
        wordBits[2] &= 4294967294ul;
        wordBits[3] &= 127ul;
        break;
     case(95):
        wordBits[3] &= 3681400575ul;
        break;
     case(96):
        wordBits[3] &= 3988183935ul;
        break;
     case(97):
        wordBits[3] &= 3485983743ul;
        break;
     case(98):
        wordBits[3] &= 4293916671ul;
        break;
     case(99):
        wordBits[3] &= 4294441983ul;
        break;
     case(100):
        wordBits[3] &= 4193844351ul;
        break;
     case(101):
        wordBits[3] &= 4294835967ul;
        break;
     case(102):
        wordBits[3] &= 4294901631ul;
        break;
     case(103):
        wordBits[3] &= 4278255615ul;
        break;
     case(104):
        wordBits[3] &= 4293787647ul;
        break;
     case(105):
        wordBits[3] &= 4294377471ul;
        break;
     case(106):
        wordBits[3] &= 4293394431ul;
        break;
     case(107):
        break;
     case(108):
        break;
     case(109):
        wordBits[3] &= 4294770687ul;
        break;
     case(110):
        break;
     case(111):
        break;
     case(112):
        wordBits[3] &= 4294934655ul;
        break;
     case(113):
        wordBits[3] &= 4294964991ul;
        break;
     case(114):
        wordBits[3] &= 4294966143ul;
        break;
     case(115):
        wordBits[3] &= 4294964223ul;
        break;
     case(116):
        break;
     case(117):
        break;
     case(118):
        wordBits[3] &= 4294966911ul;
        break;
     case(119):
        break;
     case(120):
        break;
    }

}

int SIMD_GIATrie2::insert(const vector<int>& box) {
   //Is now fully robust, including removing children

   //slightly inefficient... Also should be !nec in full impl?
 //  if (size()) { std::cout << "Size prekilled" << std::endl; return INSERT_MERGE_REQ;}

   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);

   for (; i < box.size() && box.at(i)!=-1; i++) {
      loc = loc * 3 + box.at(i);
      if ((wordBits[loc/32] & (1 << (31 - (loc % 32)))) != 0) {
         return INSERT_PRESENT;
      }
      //if I ever switch to 120-base, do a mini-contains check to check for presence.
   }
 //  std::cout << "Inserting " << loc << std::endl;

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

   //Assert: 0 <= loc <= 120
   //I should really wrap this...
   wordBits[loc/32] |= (1 << (31 - (loc % 32)));
   clearChildren(loc);
   //check if we filled the trie
   if (size()) {
      std::cout << "REturning IMR" << std::endl << std::endl;
      return INSERT_MERGE_REQ;
   }
     // std::cout << "Insertion successful." << std::endl << std::endl;

   return INSERT_SUCCESSFUL;

}

void SIMD_GIATrie2::apply(trie_actor* actor) {
   std::cout << "Error: apply not implemented!" << std::endl;
}

void SIMD_GIATrie2::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord,
                  int& currentDepth) {
 //  std::cout << "Starting..." << std::endl;
   int loc = 0;
   for (int i = myLayer; i < input.size() && input.at(i)!=-1; i++) {
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

   if (r >= 8) {
  //    std::cout << "Returning early" << std::endl;
      return; //op returns MAXSIZE (8) on fail
   }
   r/=2;
   /*
   //--Everything from here on takes 1/8 of total time

   //count leading zeros
   unsigned int dest[4];
   _mm_storeu_si128((__m128i*)dest, and_result);

   unsigned int internalVal = dest[r];
   //TODO: test using SIMD version instead
   int i_output = __builtin_clz(internalVal) + 32 * r;
   //int i_output = log2FloorInv(internalVal) + 32 * r; //<--slower for lg.#
   //END SIMD ======================

   //move i_output data into output
   output.push_back(prevWord);
   contains_outputgenWithNeg(output.back(), i_output);

 //     std::cout << "REturning success" << std::endl;
  // return true;
   */
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

//tests whether bits 2+3 are 1, or if bit 1 is (or 0, for that matter)
int SIMD_GIATrie2::size() {
   //int res = wordBits[0] >> 28;
   //return res >= 3;
   return wordBits[0] >= 0x30000000ul;
 //  return ((wordBits[0] >> 28) >= 3);
   //   return 1;
   //}
}

void SIMD_GIATrie2::print() const {
   std::cout << std::hex;
   for (int i = 0; i < maxLevel; i++) {
      std::cout << wordBits[i] << "; ";
   }
   std::cout << std::dec << std::endl;
}

/*
#include <time.h>
#include <sys/time.h>
#include "SmallIntArrayTrie.h"


int main() {
   vector<int> insert = {1, 1, 1, 3};
   vector<int> output;
   output.resize(4, 0);
   SIMD_GIATrie2 bob;
  // SmallIntArrayTrie bob;

   std::cout << "Inserting..." << std::endl;
      struct timeval totalTime;

   totalTime.tv_sec = 0;
   totalTime.tv_usec = 0;

   struct timeval tv;
   gettimeofday(&tv, NULL);     // mark start time
   for (doneSoFar = 0; doneSoFar < 50000000; doneSoFar++) {
      for (int j = 0; j < 4; j++) {
         insert.at(j) = (rand() % 4);
         if (insert.at(j)==0) insert.at(j) = -1;
      }
//      std::cout << "Ins." << std::endl;
      if (insert.at(0)==-1) {
         continue;
      }
      bob.insert(insert);
  //    std::cout << "past" << std::endl;
      int count = 0;
      if (!bob.contains(insert, output)) {
         std::cout << ";_;" << std::endl;
      }
   }
   struct timeval tv2;
   gettimeofday(&tv2, NULL);

   totalTime.tv_sec = tv2.tv_sec-tv.tv_sec;
   totalTime.tv_usec = tv2.tv_usec - tv.tv_usec;
   while (totalTime.tv_usec > 1000000) {
      totalTime.tv_sec += 1;
      totalTime.tv_usec -= 1000000;
   }

   std::cout << "Simple: " << double(totalTime.tv_sec) +
            double(totalTime.tv_usec)/1000000 << std::endl;
   std::cout <<"Inserted, boss!" << std::endl;
 //  bob.print();
}*/