//SIMD_GIATrie.h

#ifndef SIMD_GROUPED_INT_ARRAY_TRIE_H_
#define SIMD_GROUPED_INT_ARRAY_TRIE_H_

#include "GenericIntTrie.h"
#include <bitset>
#include <stdint.h>

//have to abandon the IAT framework, since we need an array of bitsets
class SIMD_GIATrie : public GenericIntTrie {
  protected:
   virtual void setMaxNodeID(int mNID);
   #define maxLevel 4
   int maxNodeID;
   int insertedCount;
   vector<int> pathToThis;
   vector<unsigned char> pathAsChar;
   
   struct charInputWithNonce {
      charInputWithNonce(int nonce);
      
      vector<unsigned char> box;
      int nonce;
   };
   
   static charInputWithNonce currentInput;
   static int currentNonce;
   static int minLayerShiftedOver;
   static int greatestSingletonDepth;
   static vector<int> singletonCandidate;
   static bool useSingletons;

   int maxDepthOfFirstInput;

   uint64_t wordBits[maxLevel]; //64 bits  * 4. (second half is for childBits) 
                 //First 121 bits are used. 
   int log2FloorInv(long input) const;
   int log2FloorInv_16(int input) const;
   void contains_outputgen(vector<int>& output, int i_output) const;
   void contains_outputgenWithNeg(vector<int>& output, int i_output) const;
   
   void clearChildren(int loc);

   static constexpr int posArray[121] = {
   0b00000000,0b00000000,0b10000000,0b01000000,0b00000000,0b00100000,0b00010000,0b10000000,0b10100000,0b10010000,0b01000000,0b01100000,0b01010000,0b00000000,0b00001000,0b00000100,0b00100000,0b00101000,0b00100100,0b00010000,0b00011000,0b00010100,0b10000000,0b10001000,0b10000100,0b10100000,0b10101000,0b10100100,0b10010000,0b10011000,0b10010100,0b01000000,0b01001000,0b01000100,0b01100000,0b01101000,0b01100100,0b01010000,0b01011000,0b01010100,0b00000000,0b00000010,0b00000001,0b00001000,0b00001010,0b00001001,0b00000100,0b00000110,0b00000101,0b00100000,0b00100010,0b00100001,0b00101000,0b00101010,0b00101001,0b00100100,0b00100110,0b00100101,0b00010000,0b00010010,0b00010001,0b00011000,0b00011010,0b00011001,0b00010100,0b00010110,0b00010101,0b10000000,0b10000010,0b10000001,0b10001000,0b10001010,0b10001001,0b10000100,0b10000110,0b10000101,0b10100000,0b10100010,0b10100001,0b10101000,0b10101010,0b10101001,0b10100100,0b10100110, 0b10100101,0b10010000,0b10010010,0b10010001,0b10011000,0b10011010,0b10011001,0b10010100,0b10010110,0b10010101,0b01000000,0b01000010,0b01000001,0b01001000,0b01001010,0b01001001,0b01000100,0b01000110, 0b01000101,0b01100000,0b01100010,0b01100001,0b01101000,0b01101010,0b01101001,0b01100100,0b01100110,0b01100101,0b01010000,0b01010010,0b01010001,0b01011000,0b01011010,0b01011001,0b01010100,0b01010110,0b01010101};
   static constexpr int negArray[121] = {
   0b11111111,0b11111111,0b01111111,0b10111111,0b11111111,0b11011111,0b11101111,0b01111111,0b01011111,0b01101111, 0b10111111,0b10011111,0b10101111,0b11111111,0b11110111,0b11111011,0b11011111,0b11010111, 0b11011011,0b11101111, 0b11100111,0b11101011, 0b01111111,0b01110111,0b01111011,0b01011111,0b01010111,0b01011011,0b01101111,0b01100111,0b01101011,0b10111111,0b10110111,0b10111011,0b10011111,0b10010111,0b10011011,0b10101111,0b10100111,0b10101011,0b11111111,0b11111101,0b11111110,0b11110111,0b11110101,0b11110110,0b11111011,0b11111001,0b11111010,0b1101111,0b11011101,0b11011110,0b11010111,0b11010101,0b11010110,0b11011011, 0b11011001,0b11011010, 0b11101111,0b11101101,0b11101110,0b11100111,0b11100101,0b11100110,0b11101011,0b11101001,0b11101010,0b01111111,0b01111101,0b01111110, 0b01110111,0b01110101,0b01110110,0b01111011,0b01111001,0b01111010,0b01011111,0b01011101,0b01011110,0b01010111,0b01010101,0b01010110,0b01011011,0b01011001,0b01011010,0b01101111,0b01101101,0b01101110,0b01100111,0b01100101,0b01100110,0b01101011,0b01101001,0b01101010,0b10111111,0b10111101,0b10111110,0b10110111,0b10110101,0b10110110,0b10111011,0b10111001,0b10111010,0b10011111,0b10011101,0b10011110,0b10010111,0b10010101,0b10010110,0b10011011,0b10011001,0b10011010,0b10101111,0b10101101,0b10101110,0b10100111,0b10100101,0b10100110,0b10101011,0b10101001,0b10101010};
   
   void getUcharFormatNeg(
vector <unsigned char>& output, const vector<int>& input, int start);
   void getUcharFormatPos(
vector <unsigned char>& output, const vector<int>& input, int start);
   
   static constexpr uint32_t links[121][maxLevel] = {
      {2147483648ul, 0ul, 0ul, 0ul}, // 0
      {3221225472ul, 0ul, 0ul, 0ul}, // 1
      {3758096384ul, 0ul, 0ul, 0ul}, // 2
      {3489660928ul, 0ul, 0ul, 0ul}, // 3
      {3355443200ul, 0ul, 0ul, 0ul}, // 4
      {3422552064ul, 0ul, 0ul, 0ul}, // 5
      {3388997632ul, 0ul, 0ul, 0ul}, // 6
      {3909091328ul, 0ul, 0ul, 0ul}, // 7
      {3984588800ul, 0ul, 0ul, 0ul}, // 8
      {3946840064ul, 0ul, 0ul, 0ul}, // 9
      {3625975808ul, 0ul, 0ul, 0ul}, // 10
      {3694133248ul, 0ul, 0ul, 0ul}, // 11
      {3660054528ul, 0ul, 0ul, 0ul}, // 12
      {3355705344ul, 0ul, 0ul, 0ul}, // 13
      {3355836416ul, 0ul, 0ul, 0ul}, // 14
      {3355770880ul, 0ul, 0ul, 0ul}, // 15
      {3422846976ul, 0ul, 0ul, 0ul}, // 16
      {3422994432ul, 0ul, 0ul, 0ul}, // 17
      {3422920704ul, 0ul, 0ul, 0ul}, // 18
      {3389263872ul, 0ul, 0ul, 0ul}, // 19
      {3389396992ul, 0ul, 0ul, 0ul}, // 20
      {3389330432ul, 0ul, 0ul, 0ul}, // 21
      {3909353984ul, 0ul, 0ul, 0ul}, // 22
      {3909485312ul, 0ul, 0ul, 0ul}, // 23
      {3909419648ul, 0ul, 0ul, 0ul}, // 24
      {3984884288ul, 0ul, 0ul, 0ul}, // 25
      {3985032032ul, 0ul, 0ul, 0ul}, // 26
      {3984958160ul, 0ul, 0ul, 0ul}, // 27
      {3947106824ul, 0ul, 0ul, 0ul}, // 28
      {3947240204ul, 0ul, 0ul, 0ul}, // 29
      {3947173514ul, 0ul, 0ul, 0ul}, // 30
      {3626237953ul, 0ul, 0ul, 0ul}, // 31
      {3626369025ul, 2147483648ul, 0ul, 0ul}, // 32
      {3626303489ul, 1073741824ul, 0ul, 0ul}, // 33
      {3694428161ul, 536870912ul, 0ul, 0ul}, // 34
      {3694575617ul, 2952790016ul, 0ul, 0ul}, // 35
      {3694501889ul, 1744830464ul, 0ul, 0ul}, // 36
      {3660320769ul, 67108864ul, 0ul, 0ul}, // 37
      {3660453889ul, 2248146944ul, 0ul, 0ul}, // 38
      {3660387329ul, 1157627904ul, 0ul, 0ul}, // 39
      {3355705344ul, 8388608ul, 0ul, 0ul}, // 40
      {3355705344ul, 12582912ul, 0ul, 0ul}, // 41
      {3355705344ul, 10485760ul, 0ul, 0ul}, // 42
      {3355836416ul, 9437184ul, 0ul, 0ul}, // 43
      {3355836416ul, 14155776ul, 0ul, 0ul}, // 44
      {3355836416ul, 11796480ul, 0ul, 0ul}, // 45
      {3355770880ul, 8519680ul, 0ul, 0ul}, // 46
      {3355770880ul, 12779520ul, 0ul, 0ul}, // 47
      {3355770880ul, 10649600ul, 0ul, 0ul}, // 48
      {3422846976ul, 8404992ul, 0ul, 0ul}, // 49
      {3422846976ul, 12607488ul, 0ul, 0ul}, // 50
      {3422846976ul, 10506240ul, 0ul, 0ul}, // 51
      {3422994432ul, 9455616ul, 0ul, 0ul}, // 52
      {3422994432ul, 14183424ul, 0ul, 0ul}, // 53
      {3422994432ul, 11819520ul, 0ul, 0ul}, // 54
      {3422920704ul, 8536320ul, 0ul, 0ul}, // 55
      {3422920704ul, 12804480ul, 0ul, 0ul}, // 56
      {3422920704ul, 10670400ul, 0ul, 0ul}, // 57
      {3389263872ul, 8388640ul, 0ul, 0ul}, // 58
      {3389263872ul, 12582960ul, 0ul, 0ul}, // 59
      {3389263872ul, 10485800ul, 0ul, 0ul}, // 60
      {3389396992ul, 9437220ul, 0ul, 0ul}, // 61
      {3389396992ul, 14155830ul, 0ul, 0ul}, // 62
      {3389396992ul, 11796525ul, 0ul, 0ul}, // 63
      {3389330432ul, 8519712ul, 2147483648ul, 0ul}, // 64
      {3389330432ul, 12779568ul, 3221225472ul, 0ul}, // 65
      {3389330432ul, 10649640ul, 2684354560ul, 0ul}, // 66
      {3909353984ul, 8388608ul, 268435456ul, 0ul}, // 67
      {3909353984ul, 12582912ul, 402653184ul, 0ul}, // 68
      {3909353984ul, 10485760ul, 335544320ul, 0ul}, // 69
      {3909485312ul, 9437184ul, 301989888ul, 0ul}, // 70
      {3909485312ul, 14155776ul, 452984832ul, 0ul}, // 71
      {3909485312ul, 11796480ul, 377487360ul, 0ul}, // 72
      {3909419648ul, 8519680ul, 272629760ul, 0ul}, // 73
      {3909419648ul, 12779520ul, 408944640ul, 0ul}, // 74
      {3909419648ul, 10649600ul, 340787200ul, 0ul}, // 75
      {3984884288ul, 8404992ul, 268959744ul, 0ul}, // 76
      {3984884288ul, 12607488ul, 403439616ul, 0ul}, // 77
      {3984884288ul, 10506240ul, 336199680ul, 0ul}, // 78
      {3985032032ul, 9455616ul, 302579712ul, 0ul}, // 79
      {3985032032ul, 14183424ul, 453869568ul, 0ul}, // 80
      {3985032032ul, 11819520ul, 378224640ul, 0ul}, // 81
      {3984958160ul, 8536320ul, 273162240ul, 0ul}, // 82
      {3984958160ul, 12804480ul, 409743360ul, 0ul}, // 83
      {3984958160ul, 10670400ul, 341452800ul, 0ul}, // 84
      {3947106824ul, 8388640ul, 268436480ul, 0ul}, // 85
      {3947106824ul, 12582960ul, 402654720ul, 0ul}, // 86
      {3947106824ul, 10485800ul, 335545600ul, 0ul}, // 87
      {3947240204ul, 9437220ul, 301991040ul, 0ul}, // 88
      {3947240204ul, 14155830ul, 452986560ul, 0ul}, // 89
      {3947240204ul, 11796525ul, 377488800ul, 0ul}, // 90
      {3947173514ul, 8519712ul, 2420114448ul, 0ul}, // 91
      {3947173514ul, 12779568ul, 3630171672ul, 0ul}, // 92
      {3947173514ul, 10649640ul, 3025143060ul, 0ul}, // 93
      {3626237953ul, 8388608ul, 2ul, 0ul}, // 94
      {3626237953ul, 12582912ul, 3ul, 0ul}, // 95
      {3626237953ul, 10485760ul, 2ul, 2147483648ul}, // 96
      {3626369025ul, 2156920832ul, 2ul, 1073741824ul}, // 97
      {3626369025ul, 2161639424ul, 3ul, 1610612736ul}, // 98
      {3626369025ul, 2159280128ul, 2ul, 3489660928ul}, // 99
      {3626303489ul, 1082261504ul, 2ul, 134217728ul}, // 100
      {3626303489ul, 1086521344ul, 3ul, 201326592ul}, // 101
      {3626303489ul, 1084391424ul, 2ul, 2315255808ul}, // 102
      {3694428161ul, 545275904ul, 2ul, 16777216ul}, // 103
      {3694428161ul, 549478400ul, 3ul, 25165824ul}, // 104
      {3694428161ul, 547377152ul, 2ul, 2168455168ul}, // 105
      {3694575617ul, 2962245632ul, 2ul, 1092616192ul}, // 106
      {3694575617ul, 2966973440ul, 3ul, 1638924288ul}, // 107
      {3694575617ul, 2964609536ul, 2ul, 3513253888ul}, // 108
      {3694501889ul, 1753366784ul, 2ul, 151257088ul}, // 109
      {3694501889ul, 1757634944ul, 3ul, 226885632ul}, // 110
      {3694501889ul, 1755500864ul, 2ul, 2336555008ul}, // 111
      {3660320769ul, 75497504ul, 2ul, 32768ul}, // 112
      {3660320769ul, 79691824ul, 3ul, 49152ul}, // 113
      {3660320769ul, 77594664ul, 2ul, 2147524608ul}, // 114
      {3660453889ul, 2257584164ul, 2ul, 1073778688ul}, // 115
      {3660453889ul, 2262302774ul, 3ul, 1610668032ul}, // 116
      {3660453889ul, 2259943469ul, 2ul, 3489707008ul}, // 117
      {3660387329ul, 1166147616ul, 2147483650ul, 134251008ul}, // 118
      {3660387329ul, 1170407472ul, 3221225475ul, 201376512ul}, // 119
      {3660387329ul, 1168277544ul, 2684354562ul, 2315297408ul} // 120

   };
   
   static constexpr uint32_t links64[121][maxLevel*2] = {
      {0ul, 2147483648ul, 0ul, 0ul,0ul, 2147483648ul, 0ul, 0ul}, // 0
      {0ul, 3221225472ul, 0ul, 0ul, 0ul, 3221225472ul, 0ul, 0ul}, // 1
      {0ul, 3758096384ul, 0ul, 0ul, 0ul, 3758096384ul, 0ul, 0ul}, // 2
      {0ul, 3489660928ul, 0ul, 0ul, 0ul, 3489660928ul, 0ul, 0ul}, // 3
      {0ul, 3355443200ul, 0ul, 0ul, 0ul, 3355443200ul, 0ul, 0ul}, // 4
      {0ul, 3422552064ul, 0ul, 0ul, 0ul, 3422552064ul, 0ul, 0ul}, // 5
      {0ul, 3388997632ul, 0ul, 0ul, 0ul, 3388997632ul, 0ul, 0ul}, // 6
      {0ul, 3909091328ul, 0ul, 0ul, 0ul, 3909091328ul, 0ul, 0ul}, // 7
      {0ul, 3984588800ul, 0ul, 0ul, 0ul, 3984588800ul, 0ul, 0ul}, // 8
      {0ul, 3946840064ul, 0ul, 0ul, 0ul, 3946840064ul, 0ul, 0ul}, // 9
      {0ul, 3625975808ul, 0ul, 0ul, 0ul, 3625975808ul, 0ul, 0ul}, // 10
      {0ul, 3694133248ul, 0ul, 0ul, 0ul, 3694133248ul, 0ul, 0ul}, // 11
      {0ul, 3660054528ul, 0ul, 0ul, 0ul, 3660054528ul, 0ul, 0ul}, // 12
      {0ul, 3355705344ul, 0ul, 0ul, 0ul, 3355705344ul, 0ul, 0ul}, // 13
      {0ul, 3355836416ul, 0ul, 0ul, 0ul, 3355836416ul, 0ul, 0ul}, // 14
      {0ul, 3355770880ul, 0ul, 0ul, 0ul, 3355770880ul, 0ul, 0ul}, // 15
      {0ul, 3422846976ul, 0ul, 0ul, 0ul, 3422846976ul, 0ul, 0ul}, // 16
      {0ul, 3422994432ul, 0ul, 0ul, 0ul, 3422994432ul, 0ul, 0ul}, // 17
      {0ul, 3422920704ul, 0ul, 0ul, 0ul, 3422920704ul, 0ul, 0ul}, // 18
      {0ul, 3389263872ul, 0ul, 0ul, 0ul, 3389263872ul, 0ul, 0ul}, // 19
      {0ul, 3389396992ul, 0ul, 0ul, 0ul, 3389396992ul, 0ul, 0ul}, // 20
      {0ul, 3389330432ul, 0ul, 0ul, 0ul, 3389330432ul, 0ul, 0ul}, // 21
      {0ul, 3909353984ul, 0ul, 0ul, 0ul, 3909353984ul, 0ul, 0ul}, // 22
      {0ul, 3909485312ul, 0ul, 0ul, 0ul, 3909485312ul, 0ul, 0ul}, // 23
      {0ul, 3909419648ul, 0ul, 0ul, 0ul, 3909419648ul, 0ul, 0ul}, // 24
      {0ul, 3984884288ul, 0ul, 0ul, 0ul, 3984884288ul, 0ul, 0ul}, // 25
      {0ul, 3985032032ul, 0ul, 0ul, 0ul, 3985032032ul, 0ul, 0ul}, // 26
      {0ul, 3984958160ul, 0ul, 0ul, 0ul, 3984958160ul, 0ul, 0ul}, // 27
      {0ul, 3947106824ul, 0ul, 0ul, 0ul, 3947106824ul, 0ul, 0ul}, // 28
      {0ul, 3947240204ul, 0ul, 0ul, 0ul, 3947240204ul, 0ul, 0ul}, // 29
      {0ul, 3947173514ul, 0ul, 0ul, 0ul, 3947173514ul, 0ul, 0ul}, // 30
      {0ul, 3626237953ul, 0ul, 0ul, 0ul, 3626237953ul, 0ul, 0ul}, // 31
      {2147483648ul, 3626369025ul, 0ul, 0ul, 2147483648ul, 3626369025ul, 0ul, 0ul}, // 32
      {1073741824ul, 3626303489ul, 0ul, 0ul, 1073741824ul, 3626303489ul, 0ul, 0ul}, // 33
      {536870912ul, 3694428161ul, 0ul, 0ul, 536870912ul, 3694428161ul, 0ul, 0ul}, // 34
      {2952790016ul, 3694575617ul, 0ul, 0ul, 2952790016ul, 3694575617ul, 0ul, 0ul}, // 35
      {1744830464ul, 3694501889ul, 0ul, 0ul, 1744830464ul, 3694501889ul, 0ul, 0ul}, // 36
      {67108864ul, 3660320769ul, 0ul, 0ul, 67108864ul, 3660320769ul, 0ul, 0ul}, // 37
      {2248146944ul, 3660453889ul, 0ul, 0ul, 2248146944ul, 3660453889ul, 0ul, 0ul}, // 38
      {1157627904ul, 3660387329ul, 0ul, 0ul, 1157627904ul, 3660387329ul, 0ul, 0ul}, // 39
      {8388608ul, 3355705344ul, 0ul, 0ul, 8388608ul, 3355705344ul, 0ul, 0ul}, // 40
      {12582912ul, 3355705344ul, 0ul, 0ul, 12582912ul, 3355705344ul, 0ul, 0ul}, // 41
      {10485760ul, 3355705344ul, 0ul, 0ul, 10485760ul, 3355705344ul, 0ul, 0ul}, // 42
      {9437184ul, 3355836416ul, 0ul, 0ul, 9437184ul, 3355836416ul, 0ul, 0ul}, // 43
      {14155776ul, 3355836416ul, 0ul, 0ul, 14155776ul, 3355836416ul, 0ul, 0ul}, // 44
      {11796480ul, 3355836416ul, 0ul, 0ul, 11796480ul, 3355836416ul, 0ul, 0ul}, // 45
      {8519680ul, 3355770880ul, 0ul, 0ul, 8519680ul, 3355770880ul, 0ul, 0ul}, // 46
      {12779520ul, 3355770880ul, 0ul, 0ul, 12779520ul, 3355770880ul, 0ul, 0ul}, // 47
      {10649600ul, 3355770880ul, 0ul, 0ul, 10649600ul, 3355770880ul, 0ul, 0ul}, // 48
      {8404992ul, 3422846976ul, 0ul, 0ul, 8404992ul, 3422846976ul, 0ul, 0ul}, // 49
      {12607488ul, 3422846976ul, 0ul, 0ul, 12607488ul, 3422846976ul, 0ul, 0ul}, // 50
      {10506240ul, 3422846976ul, 0ul, 0ul, 10506240ul, 3422846976ul, 0ul, 0ul}, // 51
      {9455616ul, 3422994432ul, 0ul, 0ul, 9455616ul, 3422994432ul, 0ul, 0ul}, // 52
      {14183424ul, 3422994432ul, 0ul, 0ul, 14183424ul, 3422994432ul, 0ul, 0ul}, // 53
      {11819520ul, 3422994432ul, 0ul, 0ul, 11819520ul, 3422994432ul, 0ul, 0ul}, // 54
      {8536320ul, 3422920704ul, 0ul, 0ul, 8536320ul, 3422920704ul, 0ul, 0ul}, // 55
      {12804480ul, 3422920704ul, 0ul, 0ul, 12804480ul, 3422920704ul, 0ul, 0ul}, // 56
      {10670400ul, 3422920704ul, 0ul, 0ul, 10670400ul, 3422920704ul, 0ul, 0ul}, // 57
      {8388640ul, 3389263872ul, 0ul, 0ul, 8388640ul, 3389263872ul, 0ul, 0ul}, // 58
      {12582960ul, 3389263872ul, 0ul, 0ul, 12582960ul, 3389263872ul, 0ul, 0ul}, // 59
      {10485800ul, 3389263872ul, 0ul, 0ul, 10485800ul, 3389263872ul, 0ul, 0ul}, // 60
      {9437220ul, 3389396992ul, 0ul, 0ul, 9437220ul, 3389396992ul, 0ul, 0ul}, // 61
      {14155830ul, 3389396992ul, 0ul, 0ul, 14155830ul, 3389396992ul, 0ul, 0ul}, // 62
      {11796525ul, 3389396992ul, 0ul, 0ul, 11796525ul, 3389396992ul, 0ul, 0ul}, // 63
      {8519712ul, 3389330432ul, 0ul, 2147483648ul, 8519712ul, 3389330432ul, 0ul, 2147483648ul}, // 64
      {12779568ul, 3389330432ul, 0ul, 3221225472ul, 12779568ul, 3389330432ul, 0ul, 3221225472ul}, // 65
      {10649640ul, 3389330432ul, 0ul, 2684354560ul, 10649640ul, 3389330432ul, 0ul, 2684354560ul}, // 66
      {8388608ul, 3909353984ul, 0ul, 268435456ul, 8388608ul, 3909353984ul, 0ul, 268435456ul}, // 67
      {12582912ul, 3909353984ul, 0ul, 402653184ul, 12582912ul, 3909353984ul, 0ul, 402653184ul}, // 68
      {10485760ul, 3909353984ul, 0ul, 335544320ul, 10485760ul, 3909353984ul, 0ul, 335544320ul}, // 69
      {9437184ul, 3909485312ul, 0ul, 301989888ul, 9437184ul, 3909485312ul, 0ul, 301989888ul}, // 70
      {14155776ul, 3909485312ul, 0ul, 452984832ul, 14155776ul, 3909485312ul, 0ul, 452984832ul}, // 71
      {11796480ul, 3909485312ul, 0ul, 377487360ul, 11796480ul, 3909485312ul, 0ul, 377487360ul}, // 72
      {8519680ul, 3909419648ul, 0ul, 272629760ul, 8519680ul, 3909419648ul, 0ul, 272629760ul}, // 73
      {12779520ul, 3909419648ul, 0ul, 408944640ul, 12779520ul, 3909419648ul, 0ul, 408944640ul}, // 74
      {10649600ul, 3909419648ul, 0ul, 340787200ul, 10649600ul, 3909419648ul, 0ul, 340787200ul}, // 75
      {8404992ul, 3984884288ul, 0ul, 268959744ul, 8404992ul, 3984884288ul, 0ul, 268959744ul}, // 76
      {12607488ul, 3984884288ul, 0ul, 403439616ul, 12607488ul, 3984884288ul, 0ul, 403439616ul}, // 77
      {10506240ul, 3984884288ul, 0ul, 336199680ul, 10506240ul, 3984884288ul, 0ul, 336199680ul}, // 78
      {9455616ul, 3985032032ul, 0ul, 302579712ul, 9455616ul, 3985032032ul, 0ul, 302579712ul}, // 79
      {14183424ul, 3985032032ul, 0ul, 453869568ul, 14183424ul, 3985032032ul, 0ul, 453869568ul}, // 80
      {11819520ul, 3985032032ul, 0ul, 378224640ul, 11819520ul, 3985032032ul, 0ul, 378224640ul}, // 81
      {8536320ul, 3984958160ul, 0ul, 273162240ul, 8536320ul, 3984958160ul, 0ul, 273162240ul}, // 82
      {12804480ul, 3984958160ul, 0ul, 409743360ul, 12804480ul, 3984958160ul, 0ul, 409743360ul}, // 83
      {10670400ul, 3984958160ul, 0ul, 341452800ul, 10670400ul, 3984958160ul, 0ul, 341452800ul}, // 84
      {8388640ul, 3947106824ul, 0ul, 268436480ul, 8388640ul, 3947106824ul, 0ul, 268436480ul}, // 85
      {12582960ul, 3947106824ul, 0ul, 402654720ul, 12582960ul, 3947106824ul, 0ul, 402654720ul}, // 86
      {10485800ul, 3947106824ul, 0ul, 335545600ul, 10485800ul, 3947106824ul, 0ul, 335545600ul}, // 87
      {9437220ul, 3947240204ul, 0ul, 301991040ul, 9437220ul, 3947240204ul, 0ul, 301991040ul}, // 88
      {14155830ul, 3947240204ul, 0ul, 452986560ul, 14155830ul, 3947240204ul, 0ul, 452986560ul}, // 89
      {11796525ul, 3947240204ul, 0ul, 377488800ul, 11796525ul, 3947240204ul, 0ul, 377488800ul}, // 90
      {8519712ul, 3947173514ul, 0ul, 2420114448ul, 8519712ul, 3947173514ul, 0ul, 2420114448ul}, // 91
      {12779568ul, 3947173514ul, 0ul, 3630171672ul, 12779568ul, 3947173514ul, 0ul, 3630171672ul}, // 92
      {10649640ul, 3947173514ul, 0ul, 3025143060ul, 10649640ul, 3947173514ul, 0ul, 3025143060ul}, // 93
      {8388608ul, 3626237953ul, 0ul, 2ul, 8388608ul, 3626237953ul, 0ul, 2ul}, // 94
      {12582912ul, 3626237953ul, 0ul, 3ul, 12582912ul, 3626237953ul, 0ul, 3ul}, // 95
      {10485760ul, 3626237953ul, 2147483648ul, 2ul, 10485760ul, 3626237953ul, 2147483648ul, 2ul}, // 96
      {2156920832ul, 3626369025ul, 1073741824ul, 2ul, 2156920832ul, 3626369025ul, 1073741824ul, 2ul}, // 97
      {2161639424ul, 3626369025ul, 1610612736ul, 3ul, 2161639424ul, 3626369025ul, 1610612736ul, 3ul}, // 98
      {2159280128ul, 3626369025ul, 3489660928ul, 2ul, 2159280128ul, 3626369025ul, 3489660928ul, 2ul}, // 99
      {1082261504ul, 3626303489ul, 134217728ul, 2ul, 1082261504ul, 3626303489ul, 134217728ul, 2ul}, // 100
      {1086521344ul, 3626303489ul, 201326592ul, 3ul, 1086521344ul, 3626303489ul, 201326592ul, 3ul}, // 101
      {1084391424ul, 3626303489ul, 2315255808ul, 2ul, 1084391424ul, 3626303489ul, 2315255808ul, 2ul}, // 102
      {545275904ul, 3694428161ul, 16777216ul, 2ul, 545275904ul, 3694428161ul, 16777216ul, 2ul}, // 103
      {549478400ul, 3694428161ul, 25165824ul, 3ul, 549478400ul, 3694428161ul, 25165824ul, 3ul}, // 104
      {547377152ul, 3694428161ul, 2168455168ul, 2ul, 547377152ul, 3694428161ul, 2168455168ul, 2ul}, // 105
      {2962245632ul, 3694575617ul, 1092616192ul, 2ul, 2962245632ul, 3694575617ul, 1092616192ul, 2ul}, // 106
      {2966973440ul, 3694575617ul, 1638924288ul, 3ul, 2966973440ul, 3694575617ul, 1638924288ul, 3ul}, // 107
      {2964609536ul, 3694575617ul, 3513253888ul, 2ul, 2964609536ul, 3694575617ul, 3513253888ul, 2ul}, // 108
      {1753366784ul, 3694501889ul, 151257088ul, 2ul, 1753366784ul, 3694501889ul, 151257088ul, 2ul}, // 109
      {1757634944ul, 3694501889ul, 226885632ul, 3ul, 1757634944ul, 3694501889ul, 226885632ul, 3ul}, // 110
      {1755500864ul, 3694501889ul, 2336555008ul, 2ul, 1755500864ul, 3694501889ul, 2336555008ul, 2ul}, // 111
      {75497504ul, 3660320769ul, 32768ul, 2ul, 75497504ul, 3660320769ul, 32768ul, 2ul}, // 112
      {79691824ul, 3660320769ul, 49152ul, 3ul, 79691824ul, 3660320769ul, 49152ul, 3ul}, // 113
      {77594664ul, 3660320769ul, 2147524608ul, 2ul, 77594664ul, 3660320769ul, 2147524608ul, 2ul}, // 114
      {2257584164ul, 3660453889ul, 1073778688ul, 2ul, 2257584164ul, 3660453889ul, 1073778688ul, 2ul}, // 115
      {2262302774ul, 3660453889ul, 1610668032ul, 3ul, 2262302774ul, 3660453889ul, 1610668032ul, 3ul}, // 116
      {2259943469ul, 3660453889ul, 3489707008ul, 2ul, 2259943469ul, 3660453889ul, 3489707008ul, 2ul}, // 117
      {1166147616ul, 3660387329ul, 134251008ul, 2147483650ul, 1166147616ul, 3660387329ul, 134251008ul, 2147483650ul}, // 118
      {1170407472ul, 3660387329ul, 201376512ul, 3221225475ul, 1170407472ul, 3660387329ul, 201376512ul, 3221225475ul}, // 119
      {1168277544ul, 3660387329ul, 2315297408ul, 2684354562ul, 1168277544ul, 3660387329ul, 2315297408ul, 2684354562ul} // 120
   };
   
  static constexpr uint32_t directLinks[121][maxLevel] = {
      {2147483648ul, 0ul, 0ul, 0ul}, // 0
      {3221225472ul, 0ul, 0ul, 0ul}, // 1
      {2684354560ul, 0ul, 0ul, 0ul}, // 2
      {2415919104ul, 0ul, 0ul, 0ul}, // 3
      {3355443200ul, 0ul, 0ul, 0ul}, // 4
      {3288334336ul, 0ul, 0ul, 0ul}, // 5
      {3254779904ul, 0ul, 0ul, 0ul}, // 6
      {2701131776ul, 0ul, 0ul, 0ul}, // 7
      {2692743168ul, 0ul, 0ul, 0ul}, // 8
      {2688548864ul, 0ul, 0ul, 0ul}, // 9
      {2418016256ul, 0ul, 0ul, 0ul}, // 10
      {2416967680ul, 0ul, 0ul, 0ul}, // 11
      {2416443392ul, 0ul, 0ul, 0ul}, // 12
      {3355705344ul, 0ul, 0ul, 0ul}, // 13
      {3355574272ul, 0ul, 0ul, 0ul}, // 14
      {3355508736ul, 0ul, 0ul, 0ul}, // 15
      {3288367104ul, 0ul, 0ul, 0ul}, // 16
      {3288350720ul, 0ul, 0ul, 0ul}, // 17
      {3288342528ul, 0ul, 0ul, 0ul}, // 18
      {3254784000ul, 0ul, 0ul, 0ul}, // 19
      {3254781952ul, 0ul, 0ul, 0ul}, // 20
      {3254780928ul, 0ul, 0ul, 0ul}, // 21
      {2701132288ul, 0ul, 0ul, 0ul}, // 22
      {2701132032ul, 0ul, 0ul, 0ul}, // 23
      {2701131904ul, 0ul, 0ul, 0ul}, // 24
      {2692743232ul, 0ul, 0ul, 0ul}, // 25
      {2692743200ul, 0ul, 0ul, 0ul}, // 26
      {2692743184ul, 0ul, 0ul, 0ul}, // 27
      {2688548872ul, 0ul, 0ul, 0ul}, // 28
      {2688548868ul, 0ul, 0ul, 0ul}, // 29
      {2688548866ul, 0ul, 0ul, 0ul}, // 30
      {2418016257ul, 0ul, 0ul, 0ul}, // 31
      {2418016256ul, 2147483648ul, 0ul, 0ul}, // 32
      {2418016256ul, 1073741824ul, 0ul, 0ul}, // 33
      {2416967680ul, 536870912ul, 0ul, 0ul}, // 34
      {2416967680ul, 268435456ul, 0ul, 0ul}, // 35
      {2416967680ul, 134217728ul, 0ul, 0ul}, // 36
      {2416443392ul, 67108864ul, 0ul, 0ul}, // 37
      {2416443392ul, 33554432ul, 0ul, 0ul}, // 38
      {2416443392ul, 16777216ul, 0ul, 0ul}, // 39
      {3355705344ul, 8388608ul, 0ul, 0ul}, // 40
      {3355705344ul, 4194304ul, 0ul, 0ul}, // 41
      {3355705344ul, 2097152ul, 0ul, 0ul}, // 42
      {3355574272ul, 1048576ul, 0ul, 0ul}, // 43
      {3355574272ul, 524288ul, 0ul, 0ul}, // 44
      {3355574272ul, 262144ul, 0ul, 0ul}, // 45
      {3355508736ul, 131072ul, 0ul, 0ul}, // 46
      {3355508736ul, 65536ul, 0ul, 0ul}, // 47
      {3355508736ul, 32768ul, 0ul, 0ul}, // 48
      {3288367104ul, 16384ul, 0ul, 0ul}, // 49
      {3288367104ul, 8192ul, 0ul, 0ul}, // 50
      {3288367104ul, 4096ul, 0ul, 0ul}, // 51
      {3288350720ul, 2048ul, 0ul, 0ul}, // 52
      {3288350720ul, 1024ul, 0ul, 0ul}, // 53
      {3288350720ul, 512ul, 0ul, 0ul}, // 54
      {3288342528ul, 256ul, 0ul, 0ul}, // 55
      {3288342528ul, 128ul, 0ul, 0ul}, // 56
      {3288342528ul, 64ul, 0ul, 0ul}, // 57
      {3254784000ul, 32ul, 0ul, 0ul}, // 58
      {3254784000ul, 16ul, 0ul, 0ul}, // 59
      {3254784000ul, 8ul, 0ul, 0ul}, // 60
      {3254781952ul, 4ul, 0ul, 0ul}, // 61
      {3254781952ul, 2ul, 0ul, 0ul}, // 62
      {3254781952ul, 1ul, 0ul, 0ul}, // 63
      {3254780928ul, 0ul, 2147483648ul, 0ul}, // 64
      {3254780928ul, 0ul, 1073741824ul, 0ul}, // 65
      {3254780928ul, 0ul, 536870912ul, 0ul}, // 66
      {2701132288ul, 0ul, 268435456ul, 0ul}, // 67
      {2701132288ul, 0ul, 134217728ul, 0ul}, // 68
      {2701132288ul, 0ul, 67108864ul, 0ul}, // 69
      {2701132032ul, 0ul, 33554432ul, 0ul}, // 70
      {2701132032ul, 0ul, 16777216ul, 0ul}, // 71
      {2701132032ul, 0ul, 8388608ul, 0ul}, // 72
      {2701131904ul, 0ul, 4194304ul, 0ul}, // 73
      {2701131904ul, 0ul, 2097152ul, 0ul}, // 74
      {2701131904ul, 0ul, 1048576ul, 0ul}, // 75
      {2692743232ul, 0ul, 524288ul, 0ul}, // 76
      {2692743232ul, 0ul, 262144ul, 0ul}, // 77
      {2692743232ul, 0ul, 131072ul, 0ul}, // 78
      {2692743200ul, 0ul, 65536ul, 0ul}, // 79
      {2692743200ul, 0ul, 32768ul, 0ul}, // 80
      {2692743200ul, 0ul, 16384ul, 0ul}, // 81
      {2692743184ul, 0ul, 8192ul, 0ul}, // 82
      {2692743184ul, 0ul, 4096ul, 0ul}, // 83
      {2692743184ul, 0ul, 2048ul, 0ul}, // 84
      {2688548872ul, 0ul, 1024ul, 0ul}, // 85
      {2688548872ul, 0ul, 512ul, 0ul}, // 86
      {2688548872ul, 0ul, 256ul, 0ul}, // 87
      {2688548868ul, 0ul, 128ul, 0ul}, // 88
      {2688548868ul, 0ul, 64ul, 0ul}, // 89
      {2688548868ul, 0ul, 32ul, 0ul}, // 90
      {2688548866ul, 0ul, 16ul, 0ul}, // 91
      {2688548866ul, 0ul, 8ul, 0ul}, // 92
      {2688548866ul, 0ul, 4ul, 0ul}, // 93
      {2418016257ul, 0ul, 2ul, 0ul}, // 94
      {2418016257ul, 0ul, 1ul, 0ul}, // 95
      {2418016257ul, 0ul, 0ul, 2147483648ul}, // 96
      {2418016256ul, 2147483648ul, 0ul, 1073741824ul}, // 97
      {2418016256ul, 2147483648ul, 0ul, 536870912ul}, // 98
      {2418016256ul, 2147483648ul, 0ul, 268435456ul}, // 99
      {2418016256ul, 1073741824ul, 0ul, 134217728ul}, // 100
      {2418016256ul, 1073741824ul, 0ul, 67108864ul}, // 101
      {2418016256ul, 1073741824ul, 0ul, 33554432ul}, // 102
      {2416967680ul, 536870912ul, 0ul, 16777216ul}, // 103
      {2416967680ul, 536870912ul, 0ul, 8388608ul}, // 104
      {2416967680ul, 536870912ul, 0ul, 4194304ul}, // 105
      {2416967680ul, 268435456ul, 0ul, 2097152ul}, // 106
      {2416967680ul, 268435456ul, 0ul, 1048576ul}, // 107
      {2416967680ul, 268435456ul, 0ul, 524288ul}, // 108
      {2416967680ul, 134217728ul, 0ul, 262144ul}, // 109
      {2416967680ul, 134217728ul, 0ul, 131072ul}, // 110
      {2416967680ul, 134217728ul, 0ul, 65536ul}, // 111
      {2416443392ul, 67108864ul, 0ul, 32768ul}, // 112
      {2416443392ul, 67108864ul, 0ul, 16384ul}, // 113
      {2416443392ul, 67108864ul, 0ul, 8192ul}, // 114
      {2416443392ul, 33554432ul, 0ul, 4096ul}, // 115
      {2416443392ul, 33554432ul, 0ul, 2048ul}, // 116
      {2416443392ul, 33554432ul, 0ul, 1024ul}, // 117
      {2416443392ul, 16777216ul, 0ul, 512ul}, // 118
      {2416443392ul, 16777216ul, 0ul, 256ul}, // 119
      {2416443392ul, 16777216ul, 0ul, 128ul} // 120
  };
   
   static constexpr uint32_t directLinks64[121][maxLevel] = {
      {0ul, 2147483648ul, 0ul, 0ul}, // 0
      {0ul, 3221225472ul, 0ul, 0ul}, // 1
      {0ul, 2684354560ul, 0ul, 0ul}, // 2
      {0ul, 2415919104ul, 0ul, 0ul}, // 3
      {0ul, 3355443200ul, 0ul, 0ul}, // 4
      {0ul, 3288334336ul, 0ul, 0ul}, // 5
      {0ul, 3254779904ul, 0ul, 0ul}, // 6
      {0ul, 2701131776ul, 0ul, 0ul}, // 7
      {0ul, 2692743168ul, 0ul, 0ul}, // 8
      {0ul, 2688548864ul, 0ul, 0ul}, // 9
      {0ul, 2418016256ul, 0ul, 0ul}, // 10
      {0ul, 2416967680ul, 0ul, 0ul}, // 11
      {0ul, 2416443392ul, 0ul, 0ul}, // 12
      {0ul, 3355705344ul, 0ul, 0ul}, // 13
      {0ul, 3355574272ul, 0ul, 0ul}, // 14
      {0ul, 3355508736ul, 0ul, 0ul}, // 15
      {0ul, 3288367104ul, 0ul, 0ul}, // 16
      {0ul, 3288350720ul, 0ul, 0ul}, // 17
      {0ul, 3288342528ul, 0ul, 0ul}, // 18
      {0ul, 3254784000ul, 0ul, 0ul}, // 19
      {0ul, 3254781952ul, 0ul, 0ul}, // 20
      {0ul, 3254780928ul, 0ul, 0ul}, // 21
      {0ul, 2701132288ul, 0ul, 0ul}, // 22
      {0ul, 2701132032ul, 0ul, 0ul}, // 23
      {0ul, 2701131904ul, 0ul, 0ul}, // 24
      {0ul, 2692743232ul, 0ul, 0ul}, // 25
      {0ul, 2692743200ul, 0ul, 0ul}, // 26
      {0ul, 2692743184ul, 0ul, 0ul}, // 27
      {0ul, 2688548872ul, 0ul, 0ul}, // 28
      {0ul, 2688548868ul, 0ul, 0ul}, // 29
      {0ul, 2688548866ul, 0ul, 0ul}, // 30
      {0ul, 2418016257ul, 0ul, 0ul}, // 31
      {2147483648ul, 2418016256ul, 0ul, 0ul}, // 32
      {1073741824ul, 2418016256ul, 0ul, 0ul}, // 33
      {536870912ul, 2416967680ul, 0ul, 0ul}, // 34
      {268435456ul, 2416967680ul, 0ul, 0ul}, // 35
      {134217728ul, 2416967680ul, 0ul, 0ul}, // 36
      {67108864ul, 2416443392ul, 0ul, 0ul}, // 37
      {33554432ul, 2416443392ul, 0ul, 0ul}, // 38
      {16777216ul, 2416443392ul, 0ul, 0ul}, // 39
      {8388608ul, 3355705344ul, 0ul, 0ul}, // 40
      {4194304ul, 3355705344ul, 0ul, 0ul}, // 41
      {2097152ul, 3355705344ul, 0ul, 0ul}, // 42
      {1048576ul, 3355574272ul, 0ul, 0ul}, // 43
      {524288ul, 3355574272ul, 0ul, 0ul}, // 44
      {262144ul, 3355574272ul, 0ul, 0ul}, // 45
      {131072ul, 3355508736ul, 0ul, 0ul}, // 46
      {65536ul, 3355508736ul, 0ul, 0ul}, // 47
      {32768ul, 3355508736ul, 0ul, 0ul}, // 48
      {16384ul, 3288367104ul, 0ul, 0ul}, // 49
      {8192ul, 3288367104ul, 0ul, 0ul}, // 50
      {4096ul, 3288367104ul, 0ul, 0ul}, // 51
      {2048ul, 3288350720ul, 0ul, 0ul}, // 52
      {1024ul, 3288350720ul, 0ul, 0ul}, // 53
      {512ul, 3288350720ul, 0ul, 0ul}, // 54
      {256ul, 3288342528ul, 0ul, 0ul}, // 55
      {128ul, 3288342528ul, 0ul, 0ul}, // 56
      {64ul, 3288342528ul, 0ul, 0ul}, // 57
      {32ul, 3254784000ul, 0ul, 0ul}, // 58
      {16ul, 3254784000ul, 0ul, 0ul}, // 59
      {8ul, 3254784000ul, 0ul, 0ul}, // 60
      {4ul, 3254781952ul, 0ul, 0ul}, // 61
      {2ul, 3254781952ul, 0ul, 0ul}, // 62
      {1ul, 3254781952ul, 0ul, 0ul}, // 63
      {0ul, 3254780928ul, 0ul, 2147483648ul}, // 64
      {0ul, 3254780928ul, 0ul, 1073741824ul}, // 65
      {0ul, 3254780928ul, 0ul, 536870912ul}, // 66
      {0ul, 2701132288ul, 0ul, 268435456ul}, // 67
      {0ul, 2701132288ul, 0ul, 134217728ul}, // 68
      {0ul, 2701132288ul, 0ul, 67108864ul}, // 69
      {0ul, 2701132032ul, 0ul, 33554432ul}, // 70
      {0ul, 2701132032ul, 0ul, 16777216ul}, // 71
      {0ul, 2701132032ul, 0ul, 8388608ul}, // 72
      {0ul, 2701131904ul, 0ul, 4194304ul}, // 73
      {0ul, 2701131904ul, 0ul, 2097152ul}, // 74
      {0ul, 2701131904ul, 0ul, 1048576ul}, // 75
      {0ul, 2692743232ul, 0ul, 524288ul}, // 76
      {0ul, 2692743232ul, 0ul, 262144ul}, // 77
      {0ul, 2692743232ul, 0ul, 131072ul}, // 78
      {0ul, 2692743200ul, 0ul, 65536ul}, // 79
      {0ul, 2692743200ul, 0ul, 32768ul}, // 80
      {0ul, 2692743200ul, 0ul, 16384ul}, // 81
      {0ul, 2692743184ul, 0ul, 8192ul}, // 82
      {0ul, 2692743184ul, 0ul, 4096ul}, // 83
      {0ul, 2692743184ul, 0ul, 2048ul}, // 84
      {0ul, 2688548872ul, 0ul, 1024ul}, // 85
      {0ul, 2688548872ul, 0ul, 512ul}, // 86
      {0ul, 2688548872ul, 0ul, 256ul}, // 87
      {0ul, 2688548868ul, 0ul, 128ul}, // 88
      {0ul, 2688548868ul, 0ul, 64ul}, // 89
      {0ul, 2688548868ul, 0ul, 32ul}, // 90
      {0ul, 2688548866ul, 0ul, 16ul}, // 91
      {0ul, 2688548866ul, 0ul, 8ul}, // 92
      {0ul, 2688548866ul, 0ul, 4ul}, // 93
      {0ul, 2418016257ul, 0ul, 2ul}, // 94
      {0ul, 2418016257ul, 0ul, 1ul}, // 95
      {0ul, 2418016257ul, 2147483648ul, 0ul}, // 96
      {2147483648ul, 2418016256ul, 1073741824ul, 0ul}, // 97
      {2147483648ul, 2418016256ul, 536870912ul, 0ul}, // 98
      {2147483648ul, 2418016256ul, 268435456ul, 0ul}, // 99
      {1073741824ul, 2418016256ul, 134217728ul, 0ul}, // 100
      {1073741824ul, 2418016256ul, 67108864ul, 0ul}, // 101
      {1073741824ul, 2418016256ul, 33554432ul, 0ul}, // 102
      {536870912ul, 2416967680ul, 16777216ul, 0ul}, // 103
      {536870912ul, 2416967680ul, 8388608ul, 0ul}, // 104
      {536870912ul, 2416967680ul, 4194304ul, 0ul}, // 105
      {268435456ul, 2416967680ul, 2097152ul, 0ul}, // 106
      {268435456ul, 2416967680ul, 1048576ul, 0ul}, // 107
      {268435456ul, 2416967680ul, 524288ul, 0ul}, // 108
      {134217728ul, 2416967680ul, 262144ul, 0ul}, // 109
      {134217728ul, 2416967680ul, 131072ul, 0ul}, // 110
      {134217728ul, 2416967680ul, 65536ul, 0ul}, // 111
      {67108864ul, 2416443392ul, 32768ul, 0ul}, // 112
      {67108864ul, 2416443392ul, 16384ul, 0ul}, // 113
      {67108864ul, 2416443392ul, 8192ul, 0ul}, // 114
      {33554432ul, 2416443392ul, 4096ul, 0ul}, // 115
      {33554432ul, 2416443392ul, 2048ul, 0ul}, // 116
      {33554432ul, 2416443392ul, 1024ul, 0ul}, // 117
      {16777216ul, 2416443392ul, 512ul, 0ul}, // 118
      {16777216ul, 2416443392ul, 256ul, 0ul}, // 119
      {16777216ul, 2416443392ul, 128ul, 0ul} // 120
  };
  
  public:
   SIMD_GIATrie();
   SIMD_GIATrie(int newLayer);
   ~SIMD_GIATrie() {};
   
   bool contains(const vector<int>& box, vector<int>& output);
   bool contains(const vector<int>& box, int currentLayer, vector<int>& output) {
      std::cout << "NOT IMPLEMENTED" << std::endl;
   }
   //defined elsewhere, repeated here for convenience
  // const int INSERT_ZIP_BROKEN = 0;
   //0 (false): ZIP needs to be broken
  // const int INSERT_SUCCESSFUL = 1;
   //1 (true): Successful insertion
  // const int INSERT_PRESENT = 2;
   //2: Already present
  // cosnt int INSERT_MERGE_REQ = 3;
   //3: Child was filled; a merge is requested
   int insert(const vector<int>& box);
   
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
   void apply(trie_actor* actor); 
   
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth);
      
      
   //still being used to get if it's full. 
   //still sorry about that.
   int size();

   std::string getType() {
      return string("SIMD_GIATrie");
   }
   
   bool append(std::shared_ptr<GenericIntTrie> tr, int index) {
      std::cout << "ERROR: This trie has no children!" << std::endl;
   }
   std::shared_ptr<GenericIntTrie> getChild(int index) {
      std::cout << "ERROR: This trie has no children!" << std::endl;
   }
   
   void print() const;
   
   //! get the number of items inserted into this trie
   virtual int getInsertedCount() const {
      return insertedCount;
   }
   
   friend class CNFIntTrieRelation;
   friend class Base121TrieRelation;
};

#endif //SMALL_INT_ARRAY_TRIE_H_