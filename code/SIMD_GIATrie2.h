//SIMD_GIATrie.h

#ifndef SIMD_GROUPED_INT_ARRAY_TRIE_2_H_
#define SIMD_GROUPED_INT_ARRAY_TRIE_2_H_

#include "GenericIntTrie.h"
#include <bitset>

//have to abandon the IAT framework, since we need an array of bitsets
class SIMD_GIATrie2 : public GenericIntTrie {
  protected:
   void setMaxNodeID(int mNID);
   #define maxLevel 4
   int maxNodeID;

   uint32_t wordBits[maxLevel]; //32 bits (1 ulong) * 4. 
                 //First 120 bits are used. 
   int log2FloorInv(long input) const;
   int log2FloorInv_16(int input) const;
   void contains_outputgen(vector<int>& output, int i_output) const;
   void contains_outputgenWithNeg(vector<int>& output, int i_output) const;
   
   void clearChildren(int loc);

   
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
   
  public:
   SIMD_GIATrie2();
   SIMD_GIATrie2(int newLayer);
   ~SIMD_GIATrie2() {};
   
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
   
   friend class CNFIntTrieRelation;
};

#endif //SMALL_INT_ARRAY_TRIE_H_