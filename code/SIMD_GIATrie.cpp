//SIMD_GIATrie.cpp

#include "SIMD_GIATrie.h"
#include <math.h>
#include <limits.h>

#include "varMap.h"

#include <nmmintrin.h>
#include <emmintrin.h>  

//definers
constexpr uint32_t SIMD_GIATrie::links[][maxLevel];
constexpr uint32_t SIMD_GIATrie::directLinks[][maxLevel];
constexpr uint32_t SIMD_GIATrie::links64[][maxLevel*2];
constexpr uint32_t SIMD_GIATrie::directLinks64[][maxLevel];
constexpr int SIMD_GIATrie::negArray[121];
constexpr int SIMD_GIATrie::posArray[121];
SIMD_GIATrie::charInputWithNonce SIMD_GIATrie::currentInput(0);
int SIMD_GIATrie::currentNonce = 0;
int SIMD_GIATrie::minLayerShiftedOver = 0;
int SIMD_GIATrie::greatestSingletonDepth = 0;
vector<int> SIMD_GIATrie::singletonCandidate(32);
bool SIMD_GIATrie::useSingletons = false;

SIMD_GIATrie::charInputWithNonce::charInputWithNonce(int newNonce) : nonce(newNonce)
{}

SIMD_GIATrie::SIMD_GIATrie() {
   myLayer = 0;
   insertedCount = 0;
   for (int i = 0; i < maxLevel/2; i++) {
      wordBits[i] = 0;
   }
   useSingletons = gvars.getBool(SINGLETON);
}

SIMD_GIATrie::SIMD_GIATrie(int newLayer) {
   myLayer = newLayer;
   insertedCount = 0;
 //  if (myLayer!=35) std::cout << "MyLayer: " << myLayer << std::endl;
   for (int i = 0; i < maxLevel/2; i++) {
      wordBits[i] = 0;
   }
}

void SIMD_GIATrie::setMaxNodeID(int mNID) {
   maxNodeID = mNID;
}

//need to use doubles for precision
//2^52 > max_int, so we're safe.
//...Does flipping endianness screw this up? Probably.
//assert: 0 <= val <= 2^31-1
int SIMD_GIATrie::log2FloorInv(long val) const {
   double d_val = (double) val; //& operator needs lvalue
   return 31 - (((*(int *) &d_val + 1) >> 20) - 1023); //Grab the exponent
}

//assert: 0 <= val <= ~2^23
int SIMD_GIATrie::log2FloorInv_16(int val) const {
   float d_val = (float) val; //& operator needs lvalue
   return 15 - (((*(int *) &d_val) >> 23) - 127); //Grab the exponent
}

//lookup table for generating output
//generated from switchGenerator in the sandbox
void SIMD_GIATrie::contains_outputgen(vector<int>& output, int i_output) const {
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

int doneSoFar;

//same as above, but inserts the kill command at the end of the vector
void SIMD_GIATrie::contains_outputgenWithNeg(vector<int>& output, int i_output) const {
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

bool SIMD_GIATrie::contains(const vector<int>& box, 
                                   vector<int>& output)
{
//   std::cout << "Calling contains" << std::endl;
 //  if (size()) return true;
   //ASSERT: myLayer + levels <= box.size()
   int loc = box.at(myLayer);

   //START SIMD ====================
   
   __m128i link = _mm_loadu_si128((__m128i*)&links64[loc][0]);
 //     std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;

   __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);
 //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;;

   __m128i and_result = _mm_and_si128(link, data);

   //note: can avoid SSSE4 using _mm_cmpneq_si128
   //but that won't get me the nice packed result that I want...
   
   //find location of first set bit in and_result
   //note that endianness is "backwards" in __m128i's, which is fixed by r/=2.
  /* unsigned int r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(), 
         8, 
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_LEAST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);
   
   if (r >= 8) {
  //    std::cout << "Returning early" << std::endl;
      return false; //op returns MAXSIZE (8) on fail
   }
   r/=2;*/
   //--Everything from here on takes 1/8 of total time
   
   //count leading zeros
   uint64_t dest[2];
   _mm_storeu_si128((__m128i*)dest, and_result);
   
   uint64_t internalVal;
   int r = 0;
   if (dest[0]!=0) {
      internalVal = dest[0];
   }
   else if (dest[1]!=0) {
      internalVal = dest[1];
      r = 1;
   }
   else {
      return false;
   }
   //TODO: test using SIMD version instead
   int i_output = __builtin_clzll(internalVal) + 64 * r;
   //int i_output = log2FloorInv(internalVal) + 32 * r; //<--slower for lg.#
   //END SIMD ======================

   //move i_output data into output
 //  std::cout << "i_output is " << i_output << std::endl;
   //contains_outputgen(output, i_output);
   output.at(myLayer) = i_output;

 //     std::cout << "REturning success" << std::endl;
   return true;
   
}

//generated using ccGenerator in sandbox.cpp
//turns out SIMD here is slightly slower in practice.
void SIMD_GIATrie::clearChildren(int loc) {
   switch(loc) {
	 case(0):
		wordBits[0] &= 9223372036854775808ull;
		break;
	 case(1):
		wordBits[0] &= 13835058055282163712ull;
		break;
	 case(2):
		wordBits[0] &= 18320638894686601215ull;
		wordBits[1] &= 16140901081675726847ull;
		break;
	 case(3):
		wordBits[0] &= 18430981466440597503ull;
		wordBits[1] &= 18446744056529682559ull;
		break;
	 case(4):
		wordBits[0] &= 17870283321406128128ull;
		break;
	 case(5):
		wordBits[0] &= 18405964904482701375ull;
		wordBits[1] &= 18442249270141714431ull;
		break;
	 case(6):
		wordBits[0] &= 18426447028813823936ull;
		wordBits[1] &= 2305834230300475519ull;
		break;
	 case(7):
		wordBits[0] &= 18392696488724529151ull;
		wordBits[1] &= 16140901081675726847ull;
		break;
	 case(8):
		wordBits[0] &= 18446743592673214463ull;
		wordBits[1] &= 18442249270175203327ull;
		break;
	 case(9):
		wordBits[0] &= 18446744013580009471ull;
		wordBits[1] &= 18446735294796398591ull;
		break;
	 case(10):
		wordBits[0] &= 18439988665695338495ull;
		wordBits[1] &= 18446744056529682559ull;
		break;
	 case(11):
		wordBits[0] &= 18446744072770027519ull;
		wordBits[1] &= 18446744073676062719ull;
		break;
	 case(12):
		wordBits[0] &= 18446744073592111103ull;
		wordBits[1] &= 18446744073709486207ull;
		break;
	 case(13):
		wordBits[0] &= 18445618173802708992ull;
		break;
	 case(14):
		wordBits[0] &= 18446663652290589176ull;
		wordBits[1] &= 18194048949412160511ull;
		break;
	 case(15):
		wordBits[0] &= 18446703863000759871ull;
		wordBits[1] &= 2274256118676520063ull;
		break;
	 case(16):
		wordBits[0] &= 18446638038617391167ull;
		wordBits[1] &= 18442249270141714431ull;
		break;
	 case(17):
		wordBits[0] &= 18446743936002159103ull;
		wordBits[1] &= 18446251492496637951ull;
		break;
	 case(18):
		wordBits[0] &= 18446744004855856703ull;
		wordBits[1] &= 18446682501057937407ull;
		break;
	 case(19):
		wordBits[0] &= 18446730819323035584ull;
		wordBits[1] &= 2305834230300475519ull;
		break;
	 case(20):
		wordBits[0] &= 18446744056496127992ull;
		wordBits[1] &= 18446743111636870143ull;
		break;
	 case(21):
		wordBits[0] &= 18446744065102839807ull;
		wordBits[1] &= 2305842888954608767ull;
		break;
	 case(22):
		wordBits[0] &= 18446741883276230655ull;
		wordBits[1] &= 16140901081675726847ull;
		break;
	 case(23):
		wordBits[0] &= 18446743919090728959ull;
		wordBits[1] &= 18194048951294885887ull;
		break;
	 case(24):
		wordBits[0] &= 18446743996400140287ull;
		wordBits[1] &= 18415157183407718399ull;
		break;
	 case(25):
		wordBits[0] &= 18446743867551121407ull;
		wordBits[1] &= 18442249270175203327ull;
		break;
	 case(26):
		wordBits[1] &= 18446251492500307967ull;
		break;
	 case(27):
		wordBits[1] &= 18446682501058396159ull;
		break;
	 case(28):
		wordBits[0] &= 18446744047939747839ull;
		wordBits[1] &= 18446735294796398591ull;
		break;
	 case(29):
		wordBits[1] &= 18446743111636877311ull;
		break;
	 case(30):
		wordBits[1] &= 18446743953450467327ull;
		break;
	 case(31):
		wordBits[0] &= 18446744069431361535ull;
		wordBits[1] &= 18446744056529682559ull;
		break;
	 case(32):
		wordBits[0] &= 18446744073407561727ull;
		wordBits[1] &= 18446744071826826239ull;
		break;
	 case(33):
		wordBits[0] &= 18446744073558556671ull;
		wordBits[1] &= 18446744073474210943ull;
		break;
	 case(34):
		wordBits[0] &= 18446744073306898431ull;
		wordBits[1] &= 18446744073676062719ull;
		break;
	 case(35):
		wordBits[1] &= 18446744073705881599ull;
		break;
	 case(36):
		wordBits[1] &= 18446744073709092863ull;
		break;
	 case(37):
		wordBits[0] &= 18446744073659219967ull;
		wordBits[1] &= 18446744073709486207ull;
		break;
	 case(38):
		wordBits[1] &= 18446744073709544447ull;
		break;
	 case(39):
		wordBits[1] &= 18446744073709550719ull;
		break;
	 case(40):
		wordBits[0] &= 18446744073701163008ull;
		break;
	 case(41):
		wordBits[0] &= 18446744073708952429ull;
		wordBits[1] &= 13176245766935394047ull;
		break;
	 case(42):
		wordBits[0] &= 18446744073709252022ull;
		wordBits[1] &= 15811494920322472831ull;
		break;
	 case(43):
		wordBits[0] &= 18446744073708761592ull;
		wordBits[1] &= 18194048949412160511ull;
		break;
	 case(44):
		wordBits[0] &= 18446744073709550589ull;
		wordBits[1] &= 18374545466767439871ull;
		break;
	 case(45):
		wordBits[0] &= 18446744073709551102ull;
		wordBits[1] &= 18410644770238495743ull;
		break;
	 case(46):
		wordBits[0] &= 18446744073709452863ull;
		wordBits[1] &= 2274256118676520063ull;
		break;
	 case(47):
		wordBits[0] &= 18446744073709551487ull;
		wordBits[1] &= 13826033229414399743ull;
		break;
	 case(48):
		wordBits[0] &= 18446744073709551551ull;
		wordBits[1] &= 16136388651561975679ull;
		break;
	 case(49):
		wordBits[0] &= 18446744073709535295ull;
		wordBits[1] &= 18442249270141714431ull;
		break;
	 case(50):
		wordBits[0] &= 18446744073709550463ull;
		wordBits[1] &= 18445459844118740991ull;
		break;
	 case(51):
		wordBits[0] &= 18446744073709551039ull;
		wordBits[1] &= 18446101958914146303ull;
		break;
	 case(52):
		wordBits[0] &= 18446744073709550079ull;
		wordBits[1] &= 18446251492496637951ull;
		break;
	 case(53):
		wordBits[1] &= 18446603336220147711ull;
		break;
	 case(54):
		wordBits[1] &= 18446673704964849663ull;
		break;
	 case(55):
		wordBits[0] &= 18446744073709551423ull;
		wordBits[1] &= 18446682501057937407ull;
		break;
	 case(56):
		wordBits[1] &= 18446726481523376127ull;
		break;
	 case(57):
		wordBits[1] &= 18446735277616463871ull;
		break;
	 case(58):
		wordBits[0] &= 18446744073709551584ull;
		wordBits[1] &= 2305834230300475519ull;
		break;
	 case(59):
		wordBits[0] &= 18446744073709551613ull;
		wordBits[1] &= 13835055547021244159ull;
		break;
	 case(60):
		wordBits[0] &= 18446744073709551614ull;
		wordBits[1] &= 16140899810365397887ull;
		break;
	 case(61):
		wordBits[0] &= 18446744073709551612ull;
		wordBits[1] &= 18446743111636870143ull;
		break;
	 case(62):
		wordBits[1] &= 18446743798831642623ull;
		break;
	 case(63):
		wordBits[1] &= 18446743936270597119ull;
		break;
	 case(64):
		wordBits[1] &= 11529214925809384575ull;
		break;
	 case(65):
		wordBits[1] &= 18446744039349812991ull;
		break;
	 case(66):
		wordBits[1] &= 18446744056529682303ull;
		break;
	 case(67):
		wordBits[1] &= 17293822586282573823ull;
		break;
	 case(68):
		wordBits[1] &= 18364392542574739455ull;
		break;
	 case(69):
		wordBits[1] &= 18405568308142145535ull;
		break;
	 case(70):
		wordBits[1] &= 18338164139370741759ull;
		break;
	 case(71):
		wordBits[1] &= 18446603061343289343ull;
		break;
	 case(72):
		wordBits[1] &= 18446673567526420479ull;
		break;
	 case(73):
		wordBits[1] &= 18433171581917200383ull;
		break;
	 case(74):
		wordBits[1] &= 18446726447163768831ull;
		break;
	 case(75):
		wordBits[1] &= 18446735260436660223ull;
		break;
	 case(76):
		wordBits[1] &= 18444501069988888575ull;
		break;
	 case(77):
		wordBits[1] &= 18446585744035151871ull;
		break;
	 case(78):
		wordBits[1] &= 18446664908872351743ull;
		break;
	 case(79):
		wordBits[1] &= 18446532967477018623ull;
		break;
	 case(80):
		break;
	 case(81):
		break;
	 case(82):
		wordBits[1] &= 18446717685430484991ull;
		break;
	 case(83):
		break;
	 case(84):
		break;
	 case(85):
		wordBits[1] &= 18446739692842909695ull;
		break;
	 case(86):
		wordBits[1] &= 18446743764471906303ull;
		break;
	 case(87):
		wordBits[1] &= 18446743919090728959ull;
		break;
	 case(88):
		wordBits[1] &= 18446743661392691199ull;
		break;
	 case(89):
		break;
	 case(90):
		break;
	 case(91):
		wordBits[1] &= 18446744022169944063ull;
		break;
	 case(92):
		break;
	 case(93):
		break;
	 case(94):
		wordBits[1] &= 18446744065119617151ull;
		break;
	 case(95):
		wordBits[1] &= 18446744073095984895ull;
		break;
	 case(96):
		wordBits[1] &= 18446744073402768255ull;
		break;
	 case(97):
		wordBits[1] &= 18446744072900568063ull;
		break;
	 case(98):
		wordBits[1] &= 18446744073708500991ull;
		break;
	 case(99):
		wordBits[1] &= 18446744073709026303ull;
		break;
	 case(100):
		wordBits[1] &= 18446744073608428671ull;
		break;
	 case(101):
		wordBits[1] &= 18446744073709420287ull;
		break;
	 case(102):
		wordBits[1] &= 18446744073709485951ull;
		break;
	 case(103):
		wordBits[1] &= 18446744073692839935ull;
		break;
	 case(104):
		wordBits[1] &= 18446744073708371967ull;
		break;
	 case(105):
		wordBits[1] &= 18446744073708961791ull;
		break;
	 case(106):
		wordBits[1] &= 18446744073707978751ull;
		break;
	 case(107):
		break;
	 case(108):
		break;
	 case(109):
		wordBits[1] &= 18446744073709355007ull;
		break;
	 case(110):
		break;
	 case(111):
		break;
	 case(112):
		wordBits[1] &= 18446744073709518975ull;
		break;
	 case(113):
		wordBits[1] &= 18446744073709549311ull;
		break;
	 case(114):
		wordBits[1] &= 18446744073709550463ull;
		break;
	 case(115):
		wordBits[1] &= 18446744073709548543ull;
		break;
	 case(116):
		break;
	 case(117):
		break;
	 case(118):
		wordBits[1] &= 18446744073709551231ull;
		break;
	 case(119):
		break;
	 case(120):
		break;
	}
}

void SIMD_GIATrie::getUcharFormatPos(
vector <unsigned char>& output, const vector<int>& input, int start) {
   maxDepthOfFirstInput = start - 1;
   while (input[++maxDepthOfFirstInput]!=-1) {
      output[maxDepthOfFirstInput] = posArray[input[maxDepthOfFirstInput]];
      
   }
}

void SIMD_GIATrie::getUcharFormatNeg(
vector <unsigned char>& output, const vector<int>& input, int start) {
   int i = minLayerShiftedOver;
   for (; i < input.size(); i++) {
      output[i] = negArray[input[i]];
   }
   
   minLayerShiftedOver = input.size();

}

int SIMD_GIATrie::insert(const vector<int>& box) {
   //Is now fully robust, including removing children
   
   //ASSERT: box.at(myLayer)!=-1
   int i = myLayer + 1;
   int loc = box.at(myLayer);
   
   __m128i link = _mm_loadu_si128((__m128i*)&directLinks64[loc][0]);
   __m128i data = _mm_loadu_si128((__m128i*)&wordBits[0]);

   __m128i and_result = _mm_and_si128(link, data);
   //TODO: Is switching this faster?!?!?!?!??!?!?!??!?!!??!?!??!?!?!?
   unsigned int r = _mm_cmpestri(and_result,
         8,
         _mm_setzero_si128(), 
         8, 
         _SIDD_UWORD_OPS | _SIDD_CMP_EQUAL_EACH |
         _SIDD_LEAST_SIGNIFICANT | _SIDD_NEGATIVE_POLARITY);
   
   if (r < 8) {
      return INSERT_PRESENT;
   }

  // std::cout << "Inserting " << loc << " at layer " << myLayer << std::endl;
   
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
   
   //Assert: 0 <= loc <= 120
   //I should really wrap this...
   wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
   clearChildren(loc);
   //check if we filled the trie
   if (size()) {
      //std::cout << "REturning IMR" << std::endl;
      return INSERT_MERGE_REQ;
   }
     // std::cout << "Insertion successful." << std::endl << std::endl;

   return INSERT_SUCCESSFUL;
   
}

void SIMD_GIATrie::apply(trie_actor* actor) {
   std::cout << "Error: apply not implemented!" << std::endl;
}

//TODO: Update gacb
void SIMD_GIATrie::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, 
                  int& currentDepth) {
  //std::cout << "gaccb base @ layer " << myLayer << "..." << std::endl;
   int loc = input.at(myLayer);
   //START SIMD ====================
   
   __m128i link = _mm_loadu_si128((__m128i*)&links64[loc][0]);
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
      if (myLayer > currentDepth) {
         currentDepth = myLayer;
      }
      return; //op returns MAXSIZE (8) on fail
   }
   r/=4;
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
   uint64_t dest[2];
   _mm_storeu_si128((__m128i*)dest, and_result);
   int initialOutputSize = output.size();
   for (int i = r; i < 2; i++) {
      while (dest[i]!=0) {
         int lzc = __builtin_clzll(dest[i]);
         dest[i] ^= (1ull << (63 - lzc)); //clear the located output point
         output.push_back(prevWord);
         int val = 64 * i + lzc;
         //contains_outputgenWithNeg(output.back(), val);
         output.back().at(myLayer) = val;
         output.back().at(myLayer+1) = -1;
      }
   }
   

}

//tests whether bits 2+3 are 1, or if bit 1 is (or 0, for that matter)
int SIMD_GIATrie::size() {
   //int res = wordBits[0] >> 28;
   //return res >= 3;
   return wordBits[0] >= 0x3000000000000000ull;
 //  return ((wordBits[0] >> 28) >= 3);
   //   return 1;
   //}
}

void SIMD_GIATrie::print() const {
   std::cout << std::hex;
   for (int i = 0; i < maxLevel/2; i++) {
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
   SIMD_GIATrie bob;
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