//Base243GIAT.cpp

#include "Base243GIAT.h"
#include <math.h>

#include <nmmintrin.h>
#include <emmintrin.h> 
#include <immintrin.h>


constexpr uint64_t Base243GIAT::links64[][maxLevel];

Base243GIAT::Base243GIAT() {
   myLayer = 0;
   for (int i = 0; i < maxLevel; i++) {
      wordBits[i] = 0;
   //   childBits[i] = 0;
   }
   mWeights.resize(256, 0);
   mDataPtr.resize(256);
   
   mStatus = GIAT_STATUS_EMPTY;
}

Base243GIAT::Base243GIAT(int newLayer) {
   myLayer = newLayer;
 //  if (myLayer!=35) std::cout << "MyLayer: " << myLayer << std::endl;
   for (int i = 0; i < maxLevel; i++) {
      wordBits[i] = 0;
   //   childBits[i] = 0;
   }
   mWeights.resize(256, 0);
   mDataPtr.resize(256);
   
   mStatus = GIAT_STATUS_EMPTY;
}

bool Base243GIAT::contains(const vector<int>& box, 
                                   vector<int>& output)
{
   //ASSERT: myLayer + levels <= box.size()
   int loc = box.at(myLayer);
   
   //START SIMD ====================
   
   __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
 //     std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;

   __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
 //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;;

   __m256i and_result = _mm256_and_si256(link, data);
   
   uint64_t dest[4];
   _mm256_store_si256((__m256i*)dest, and_result);

   //TODO: Switch back to a shortcutter to find the first set bit using e.g. _mm_cmpestri (see SIMD_GIATrie::contains)?
   for (int i = 0; i < 4; i++) {
      if (dest[i]!=0) {
         int lzc = __builtin_clzll(dest[i]);
         //dest[i] ^= (1ull << (63 - lzc)); //No need to clear the located output point here!
         int val = 64 * i + lzc;
         
         output.at(myLayer) = val;
         return true;
      }
   }
   
   return false;
}

//TODO: merge with normal contains
bool Base243GIAT::containsWeighted(const weightedBox& wbox, 
                                         weightedBox& output)
{
   vector<int> box = wbox.box;
   
   //ASSERT: myLayer + levels <= box.size()
   int loc = box.at(myLayer);
   
   //START SIMD ====================
   
   __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
 //     std::cout << "Link: " << links64[loc][0] << " " << links64[loc][1] << " " << links64[loc][2] << " " << links64[loc][3] << std::endl;

   __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);
 //  std::cout << "Data: " << wordBits[0] << " " << wordBits[1] << std::endl;;

   __m256i and_result = _mm256_and_si256(link, data);
   
   uint64_t dest[4];
   _mm256_store_si256((__m256i*)dest, and_result);

   //TODO: Switch back to a shortcutter to find the first set bit using e.g. _mm_cmpestri (see SIMD_GIATrie::contains)?
   for (int i = 0; i < 4; i++) {
      if (dest[i]!=0) {
         int lzc = __builtin_clzll(dest[i]);
         //dest[i] ^= (1ull << (63 - lzc)); //No need to clear the located output point here!
         int val = 64 * i + lzc;
         
         output.box.at(myLayer) = val;
         return true;
      }
   }
   
   return false;
}

int Base243GIAT::insert(const vector<int>& box) {
   int loc = insertCore(box);
  
   if (loc == 0) { //should be equivalent to full size
      return INSERT_MERGE_REQ;
   }
   else if (loc == -1) {
      return INSERT_PRESENT;
   }
   else return INSERT_SUCCESSFUL;
}

int Base243GIAT::insert(const vector<int>& box, int& firstNewsLayer, Base243GIAT*& firstNew) {
   int loc = insertCore(box);
   
  
   if (loc == 0) { //should be equivalent to full size
      return INSERT_MERGE_REQ;
   }
   else if (loc == -1) {
      return INSERT_PRESENT;
   }
   else {
      firstNewsLayer = myLayer;
      firstNew = NULL;
      return INSERT_SUCCESSFUL;
   }
}

int Base243GIAT::insertWeighted(const weightedBox& box) {
   int loc = insertCore(box.box);

   if (loc == 0) { //should be equivalent to full size
      return INSERT_MERGE_REQ;
   }
   else if (loc == -1) {
      return INSERT_PRESENT;
   }
   else {
      mWeights.at(loc) = box.weight;
      mDataPtr.at(loc) = box.data;
      return INSERT_SUCCESSFUL;
   }
}

int Base243GIAT::insertCore(const vector<int>& box) {
   if (mStatus == GIAT_STATUS_EMPTY) {
      pathToThis = box;
      mStatus |= GIAT_STATUS_WORD_ONLY;
   }
   insertedCount++;

   //ASSERT: box.at(myLayer)!=-1
   //TODO: Check for presence
   int loc = box.at(myLayer);
   //TODO: Check for merger here
   
   //Assert: 0 <= loc <= 243
   insertIntoBits(wordBits, loc); //wordBits[loc/64] |= (1ull << (63 - (loc % 64)));
   wordList.push_back(loc);
   //clearChildren(loc) //TODO!
   return loc;
}

void Base243GIAT::apply(trie_actor* actor) {
   std::cout << "Error: Base243GIAT::apply not implemented!" << std::endl;
}

#include <iomanip>
void Base243GIAT::getAllContainingBoxesB( const vector<int>& input,
                  vector<vector<int> >& output,
                  vector<int>& prevWord, 
                  int& currentDepth) {
                //     std::cout << "Base..." << std::endl;
      currentDepth = myLayer;
   
   int loc = input.at(myLayer);
   //START SIMD ====================
   // std::cout << "Loc: " << loc << std::endl;
   // std::cout << "links:    " << std::hex << links64[loc][0] << ", " << links64[loc][1] << ", " << links64[loc][2] << ", " << links64[loc][3] << std::dec << std::endl;
   // std::cout << "wordBits: " << std::hex << wordBits[0] << ", " << wordBits[1] << ", " << wordBits[2] << ", " << wordBits[3] << std::dec << std::endl;
   __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
   __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);

   __m256i and_result = _mm256_and_si256(link, data);
      
   uint64_t dest[4];
   _mm256_store_si256((__m256i*)dest, and_result);

   //TODO: Switch back to a shortcutter to find the first set bit using e.g. _mm_cmpestri (see SIMD_GIATrie::contains)?
   for (int i = 0; i < 4; i++) {
      while (dest[i]!=0) {
      //   std::cout << "Adding box..." << std::endl;
         int lzc = __builtin_clzll(dest[i]);
         dest[i] ^= (1ull << (63 - lzc)); //Need to clear the located output point here!
         int val = 64 * i + lzc;

         output.push_back(prevWord);
         output.back().at(myLayer) = val;
         output.back().at(myLayer+1) = -1;
      }
   }
   return;
}

//todo: merge with non-weighted
void Base243GIAT::getAllContainingBoxesWeighted( const weightedBox& wInput,
                  vector<weightedBox>& output,
                  vector<int>& prevWord, //note: prevWord is a subset of input!
                  int& currentDepth) 
{   

   vector<int> input = wInput.box;
   
   currentDepth = myLayer;
   
   int loc = input.at(myLayer);
   //START SIMD ====================
   // std::cout << "Loc: " << loc << std::endl;
   // std::cout << "links:    " << std::hex << links64[loc][0] << ", " << links64[loc][1] << ", " << links64[loc][2] << ", " << links64[loc][3] << std::dec << std::endl;
   // std::cout << "wordBits: " << std::hex << wordBits[0] << ", " << wordBits[1] << ", " << wordBits[2] << ", " << wordBits[3] << std::dec << std::endl;
   __m256i link = _mm256_loadu_si256((__m256i*)&links64[loc][0]);
   __m256i data = _mm256_loadu_si256((__m256i*)&wordBits[0]);

   __m256i and_result = _mm256_and_si256(link, data);
      
   uint64_t dest[4];
   _mm256_store_si256((__m256i*)dest, and_result);

   //TODO: Switch back to a shortcutter to find the first set bit using e.g. _mm_cmpestri (see SIMD_GIATrie::contains)?
   for (int i = 0; i < 4; i++) {
      while (dest[i]!=0) {
      //   std::cout << "Adding box..." << std::endl;
         int lzc = __builtin_clzll(dest[i]);
         dest[i] ^= (1ull << (63 - lzc)); //Need to clear the located output point here!
         int val = 64 * i + lzc;

         weightedBox temp;
         temp.box = prevWord;
         temp.box.at(myLayer) = val;
         temp.box.at(myLayer+1) = -1;
         temp.weight = mWeights.at(val);
         temp.data = mDataPtr.at(val);
         output.push_back(temp);
      }
   }
   return;     
}

//i don't know how to do this here...
int Base243GIAT::size() {
   return mStatus;
}

void Base243GIAT::print() const {
   std::cout << std::hex;
   for (int i = 0; i < maxLevel; i++) {
      std::cout << wordBits[i] << "; ";
   }
   //TODO: print children.
   std::cout << std::dec << std::endl;
}

void Base243GIAT::insertIntoBits(uint64_t* bits, int loc) {
   bits[loc/64] |= (1ull << (63 - (loc % 64)));
}

//switch between big-end and little-end, essentially
void Base243GIAT::convert(int& val) const {
   switch(val) {
         case 0:
      val = 0;
      break;
   case 1:
      val = 81;
      break;
   case 2:
      val = 162;
      break;
   case 3:
      val = 27;
      break;
   case 4:
      val = 108;
      break;
   case 5:
      val = 189;
      break;
   case 6:
      val = 54;
      break;
   case 7:
      val = 135;
      break;
   case 8:
      val = 216;
      break;
   case 9:
      val = 9;
      break;
   case 10:
      val = 90;
      break;
   case 11:
      val = 171;
      break;
   case 12:
      val = 36;
      break;
   case 13:
      val = 117;
      break;
   case 14:
      val = 198;
      break;
   case 15:
      val = 63;
      break;
   case 16:
      val = 144;
      break;
   case 17:
      val = 225;
      break;
   case 18:
      val = 18;
      break;
   case 19:
      val = 99;
      break;
   case 20:
      val = 180;
      break;
   case 21:
      val = 45;
      break;
   case 22:
      val = 126;
      break;
   case 23:
      val = 207;
      break;
   case 24:
      val = 72;
      break;
   case 25:
      val = 153;
      break;
   case 26:
      val = 234;
      break;
   case 27:
      val = 3;
      break;
   case 28:
      val = 84;
      break;
   case 29:
      val = 165;
      break;
   case 30:
      val = 30;
      break;
   case 31:
      val = 111;
      break;
   case 32:
      val = 192;
      break;
   case 33:
      val = 57;
      break;
   case 34:
      val = 138;
      break;
   case 35:
      val = 219;
      break;
   case 36:
      val = 12;
      break;
   case 37:
      val = 93;
      break;
   case 38:
      val = 174;
      break;
   case 39:
      val = 39;
      break;
   case 40:
      val = 120;
      break;
   case 41:
      val = 201;
      break;
   case 42:
      val = 66;
      break;
   case 43:
      val = 147;
      break;
   case 44:
      val = 228;
      break;
   case 45:
      val = 21;
      break;
   case 46:
      val = 102;
      break;
   case 47:
      val = 183;
      break;
   case 48:
      val = 48;
      break;
   case 49:
      val = 129;
      break;
   case 50:
      val = 210;
      break;
   case 51:
      val = 75;
      break;
   case 52:
      val = 156;
      break;
   case 53:
      val = 237;
      break;
   case 54:
      val = 6;
      break;
   case 55:
      val = 87;
      break;
   case 56:
      val = 168;
      break;
   case 57:
      val = 33;
      break;
   case 58:
      val = 114;
      break;
   case 59:
      val = 195;
      break;
   case 60:
      val = 60;
      break;
   case 61:
      val = 141;
      break;
   case 62:
      val = 222;
      break;
   case 63:
      val = 15;
      break;
   case 64:
      val = 96;
      break;
   case 65:
      val = 177;
      break;
   case 66:
      val = 42;
      break;
   case 67:
      val = 123;
      break;
   case 68:
      val = 204;
      break;
   case 69:
      val = 69;
      break;
   case 70:
      val = 150;
      break;
   case 71:
      val = 231;
      break;
   case 72:
      val = 24;
      break;
   case 73:
      val = 105;
      break;
   case 74:
      val = 186;
      break;
   case 75:
      val = 51;
      break;
   case 76:
      val = 132;
      break;
   case 77:
      val = 213;
      break;
   case 78:
      val = 78;
      break;
   case 79:
      val = 159;
      break;
   case 80:
      val = 240;
      break;
   case 81:
      val = 1;
      break;
   case 82:
      val = 82;
      break;
   case 83:
      val = 163;
      break;
   case 84:
      val = 28;
      break;
   case 85:
      val = 109;
      break;
   case 86:
      val = 190;
      break;
   case 87:
      val = 55;
      break;
   case 88:
      val = 136;
      break;
   case 89:
      val = 217;
      break;
   case 90:
      val = 10;
      break;
   case 91:
      val = 91;
      break;
   case 92:
      val = 172;
      break;
   case 93:
      val = 37;
      break;
   case 94:
      val = 118;
      break;
   case 95:
      val = 199;
      break;
   case 96:
      val = 64;
      break;
   case 97:
      val = 145;
      break;
   case 98:
      val = 226;
      break;
   case 99:
      val = 19;
      break;
   case 100:
      val = 100;
      break;
   case 101:
      val = 181;
      break;
   case 102:
      val = 46;
      break;
   case 103:
      val = 127;
      break;
   case 104:
      val = 208;
      break;
   case 105:
      val = 73;
      break;
   case 106:
      val = 154;
      break;
   case 107:
      val = 235;
      break;
   case 108:
      val = 4;
      break;
   case 109:
      val = 85;
      break;
   case 110:
      val = 166;
      break;
   case 111:
      val = 31;
      break;
   case 112:
      val = 112;
      break;
   case 113:
      val = 193;
      break;
   case 114:
      val = 58;
      break;
   case 115:
      val = 139;
      break;
   case 116:
      val = 220;
      break;
   case 117:
      val = 13;
      break;
   case 118:
      val = 94;
      break;
   case 119:
      val = 175;
      break;
   case 120:
      val = 40;
      break;
   case 121:
      val = 121;
      break;
   case 122:
      val = 202;
      break;
   case 123:
      val = 67;
      break;
   case 124:
      val = 148;
      break;
   case 125:
      val = 229;
      break;
   case 126:
      val = 22;
      break;
   case 127:
      val = 103;
      break;
   case 128:
      val = 184;
      break;
   case 129:
      val = 49;
      break;
   case 130:
      val = 130;
      break;
   case 131:
      val = 211;
      break;
   case 132:
      val = 76;
      break;
   case 133:
      val = 157;
      break;
   case 134:
      val = 238;
      break;
   case 135:
      val = 7;
      break;
   case 136:
      val = 88;
      break;
   case 137:
      val = 169;
      break;
   case 138:
      val = 34;
      break;
   case 139:
      val = 115;
      break;
   case 140:
      val = 196;
      break;
   case 141:
      val = 61;
      break;
   case 142:
      val = 142;
      break;
   case 143:
      val = 223;
      break;
   case 144:
      val = 16;
      break;
   case 145:
      val = 97;
      break;
   case 146:
      val = 178;
      break;
   case 147:
      val = 43;
      break;
   case 148:
      val = 124;
      break;
   case 149:
      val = 205;
      break;
   case 150:
      val = 70;
      break;
   case 151:
      val = 151;
      break;
   case 152:
      val = 232;
      break;
   case 153:
      val = 25;
      break;
   case 154:
      val = 106;
      break;
   case 155:
      val = 187;
      break;
   case 156:
      val = 52;
      break;
   case 157:
      val = 133;
      break;
   case 158:
      val = 214;
      break;
   case 159:
      val = 79;
      break;
   case 160:
      val = 160;
      break;
   case 161:
      val = 241;
      break;
   case 162:
      val = 2;
      break;
   case 163:
      val = 83;
      break;
   case 164:
      val = 164;
      break;
   case 165:
      val = 29;
      break;
   case 166:
      val = 110;
      break;
   case 167:
      val = 191;
      break;
   case 168:
      val = 56;
      break;
   case 169:
      val = 137;
      break;
   case 170:
      val = 218;
      break;
   case 171:
      val = 11;
      break;
   case 172:
      val = 92;
      break;
   case 173:
      val = 173;
      break;
   case 174:
      val = 38;
      break;
   case 175:
      val = 119;
      break;
   case 176:
      val = 200;
      break;
   case 177:
      val = 65;
      break;
   case 178:
      val = 146;
      break;
   case 179:
      val = 227;
      break;
   case 180:
      val = 20;
      break;
   case 181:
      val = 101;
      break;
   case 182:
      val = 182;
      break;
   case 183:
      val = 47;
      break;
   case 184:
      val = 128;
      break;
   case 185:
      val = 209;
      break;
   case 186:
      val = 74;
      break;
   case 187:
      val = 155;
      break;
   case 188:
      val = 236;
      break;
   case 189:
      val = 5;
      break;
   case 190:
      val = 86;
      break;
   case 191:
      val = 167;
      break;
   case 192:
      val = 32;
      break;
   case 193:
      val = 113;
      break;
   case 194:
      val = 194;
      break;
   case 195:
      val = 59;
      break;
   case 196:
      val = 140;
      break;
   case 197:
      val = 221;
      break;
   case 198:
      val = 14;
      break;
   case 199:
      val = 95;
      break;
   case 200:
      val = 176;
      break;
   case 201:
      val = 41;
      break;
   case 202:
      val = 122;
      break;
   case 203:
      val = 203;
      break;
   case 204:
      val = 68;
      break;
   case 205:
      val = 149;
      break;
   case 206:
      val = 230;
      break;
   case 207:
      val = 23;
      break;
   case 208:
      val = 104;
      break;
   case 209:
      val = 185;
      break;
   case 210:
      val = 50;
      break;
   case 211:
      val = 131;
      break;
   case 212:
      val = 212;
      break;
   case 213:
      val = 77;
      break;
   case 214:
      val = 158;
      break;
   case 215:
      val = 239;
      break;
   case 216:
      val = 8;
      break;
   case 217:
      val = 89;
      break;
   case 218:
      val = 170;
      break;
   case 219:
      val = 35;
      break;
   case 220:
      val = 116;
      break;
   case 221:
      val = 197;
      break;
   case 222:
      val = 62;
      break;
   case 223:
      val = 143;
      break;
   case 224:
      val = 224;
      break;
   case 225:
      val = 17;
      break;
   case 226:
      val = 98;
      break;
   case 227:
      val = 179;
      break;
   case 228:
      val = 44;
      break;
   case 229:
      val = 125;
      break;
   case 230:
      val = 206;
      break;
   case 231:
      val = 71;
      break;
   case 232:
      val = 152;
      break;
   case 233:
      val = 233;
      break;
   case 234:
      val = 26;
      break;
   case 235:
      val = 107;
      break;
   case 236:
      val = 188;
      break;
   case 237:
      val = 53;
      break;
   case 238:
      val = 134;
      break;
   case 239:
      val = 215;
      break;
   case 240:
      val = 80;
      break;
   case 241:
      val = 161;
      break;
   case 242:
      val = 242;
      break;
   }
         
}

uint64_t* Base243GIAT::getWordBitsPtr() {
   return &wordBits[0];
}
uint64_t* Base243GIAT::getChildBitsPtr() {
   return &childBits[0];
}

vector<int> Base243GIAT::getWordList() {
   return wordList;
}
