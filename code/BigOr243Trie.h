//BigOr243Trie.h

#ifndef BIG_OR_243_TRIE_H_
#define BIG_OR_243_TRIE_H_

#include "Base243GIAT.h"
#include <nmmintrin.h>
#include <emmintrin.h> 
#include <immintrin.h>
#include <list>
#include <unordered_map>

typedef Base243GIAT ChildClass;

class BigOr243Trie : public Base243GIAT {
   
  protected: 
   std::unique_ptr<ChildClass> head;
   std::vector<std::vector<ChildClass*> > lists;
   
   //first coordinate is destLayer, second coordinate is sourceLayer
   vector<vector<int> > listSizes;
   int activeLoc;
   
   //singleton members
   int mSingletonSource;
   vector<int>* mCandidate;
   bool mUseSingleton;
   int mPartialLambda;
   
   vector<double> mData;
   vector<double> mData2;
   vector<double> mData3;
   
   vector<vector<int> > dummy;
   vector<int> prevInput;
   
   int mLockBoundary;
   // bool mUseShorts;
   // vector<uint64_t> mShort_bits;
   // //key is bit index, value is indexes in mShort_boxes to increment.
   // std::unordered_map<int, vector<int> > mShort_lut;
   // //first param is size, second is formatted input
   // vector<pair<int,vector<int> > > mShort_boxes;
      
   //todo: figure out some way to deal with the container prob
   //      so getAllContaining on words can get everything it wants
   #define CONTAINS_MODE 0x00
   #define GACB_MODE     0x01
   int getWords(__m256i& link, int& layer,
                vector<vector<int> >&setOfOutputs, vector<int>& output,
                int mode);
                    
                    
   #define UNUSED       -10000000
   #define FIRST_TIME   -1
   void getChildren(__m256i& link, int& layer, int& remaining);
                    
   void resetLists(const vector<int>& input);
   //this is both the inner method for the above, and a full method in its own right
   void resetLists(int i, const vector<int>& input);

   void updateListSizes(int& layer);
   int getFlipped(int input);
   
   void mergeBoxesFlat(vector<int>&, vector<int>&, int&) const;
   
  public:
   BigOr243Trie(int layers, int lockBoundary = 0);
   ~BigOr243Trie();
   
   bool contains(const vector<int>& box, vector<int>& output);
   int containsShorts(const vector<int>& input,
                  vector<int>& output,
                  int& maxDepth,
                  int mode);
   int insert(const vector<int>& box);
   int insertShort(const vector<int>& box, const vector<int>& raw);
   bool remove(const vector<int>& box) {} //todo
   void apply(trie_actor* actor, int index) {} //todo?
   
   void getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth);
                  
   std::string getType() {
      return string("BigOr243Trie");
   }
   
   bool searchForSingleton(vector<int>& input, int& maxDepth, int& numSolutions);
   int getTotalLambdaCount(const vector<int>& path, int start);
   static constexpr int lambdaLUT[243] = { 
   5, //0
   4, //1
   4, //2
   4, //3
   3, //4
   3, //5
   4, //6
   3, //7
   3, //8
   4, //9
   3, //10
   3, //11
   3, //12
   2, //13
   2, //14
   3, //15
   2, //16
   2, //17
   4, //18
   3, //19
   3, //20
   3, //21
   2, //22
   2, //23
   3, //24
   2, //25
   2, //26
   4, //27
   3, //28
   3, //29
   3, //30
   2, //31
   2, //32
   3, //33
   2, //34
   2, //35
   3, //36
   2, //37
   2, //38
   2, //39
   1, //40
   1, //41
   2, //42
   1, //43
   1, //44
   3, //45
   2, //46
   2, //47
   2, //48
   1, //49
   1, //50
   2, //51
   1, //52
   1, //53
   4, //54
   3, //55
   3, //56
   3, //57
   2, //58
   2, //59
   3, //60
   2, //61
   2, //62
   3, //63
   2, //64
   2, //65
   2, //66
   1, //67
   1, //68
   2, //69
   1, //70
   1, //71
   3, //72
   2, //73
   2, //74
   2, //75
   1, //76
   1, //77
   2, //78
   1, //79
   1, //80
   4, //81
   3, //82
   3, //83
   3, //84
   2, //85
   2, //86
   3, //87
   2, //88
   2, //89
   3, //90
   2, //91
   2, //92
   2, //93
   1, //94
   1, //95
   2, //96
   1, //97
   1, //98
   3, //99
   2, //100
   2, //101
   2, //102
   1, //103
   1, //104
   2, //105
   1, //106
   1, //107
   3, //108
   2, //109
   2, //110
   2, //111
   1, //112
   1, //113
   2, //114
   1, //115
   1, //116
   2, //117
   1, //118
   1, //119
   1, //120
   0, //121
   0, //122
   1, //123
   0, //124
   0, //125
   2, //126
   1, //127
   1, //128
   1, //129
   0, //130
   0, //131
   1, //132
   0, //133
   0, //134
   3, //135
   2, //136
   2, //137
   2, //138
   1, //139
   1, //140
   2, //141
   1, //142
   1, //143
   2, //144
   1, //145
   1, //146
   1, //147
   0, //148
   0, //149
   1, //150
   0, //151
   0, //152
   2, //153
   1, //154
   1, //155
   1, //156
   0, //157
   0, //158
   1, //159
   0, //160
   0, //161
   4, //162
   3, //163
   3, //164
   3, //165
   2, //166
   2, //167
   3, //168
   2, //169
   2, //170
   3, //171
   2, //172
   2, //173
   2, //174
   1, //175
   1, //176
   2, //177
   1, //178
   1, //179
   3, //180
   2, //181
   2, //182
   2, //183
   1, //184
   1, //185
   2, //186
   1, //187
   1, //188
   3, //189
   2, //190
   2, //191
   2, //192
   1, //193
   1, //194
   2, //195
   1, //196
   1, //197
   2, //198
   1, //199
   1, //200
   1, //201
   0, //202
   0, //203
   1, //204
   0, //205
   0, //206
   2, //207
   1, //208
   1, //209
   1, //210
   0, //211
   0, //212
   1, //213
   0, //214
   0, //215
   3, //216
   2, //217
   2, //218
   2, //219
   1, //220
   1, //221
   2, //222
   1, //223
   1, //224
   2, //225
   1, //226
   1, //227
   1, //228
   0, //229
   0, //230
   1, //231
   0, //232
   0, //233
   2, //234
   1, //235
   1, //236
   1, //237
   0, //238
   0, //239
   1, //240
   0, //241
   0, //242
};

   //override GIT
   bool getSingletonData(int& sourceLayer, vector<int>*& candidate, int& extra);
   int getEndLambdaCount(int& val);
   
   friend class CNFIntTrieRelation;
   friend class Base243TrieRelation;
};
#endif //BIG_OR_243_TRIE_H_