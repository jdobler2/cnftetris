//Base243TrieRelation.cpp

#include "Base243TrieRelation.h"
#include "varMap.h"
#include "error_handling.h"
#include "Base243GIAT.h"
#include "Base243InnerGIAT.h"
#include "BigOr243Trie.h"
#include <utility>

Base243TrieRelation::Base243TrieRelation() {
   maxDepth = 5;
   _LAYER_SIZE = 5;
   shift = 121; //I don't know what/how much this breaks
   //tree = new IATDummy(new SIMD_InnerGIAT());
   //creating tree moved to insertData
   //sharedInit();
   ratio = gvars.getDouble(RATIO);
}

//
void Base243TrieRelation::fillZero(weightedBox& input, int& index) {
   this->fillZero(input.box, index);
}

void Base243TrieRelation::fillZero(vector<int>& input, int& index) {
 //  std::cout << "FinalDegree:" << finalDegree << std::endl;
 //  std::cout << "Index:" << index << std::endl;
  /* switch(input.at(index)) {
	case 0:
		input.at(index) = 121;
		break;
	case 1:
		input.at(index) = 1;
		break;
	case 2:
		input.at(index) = 2;
		break;
	case 3:
		input.at(index) = 4;
		break;
	case 4:
		input.at(index) = 4;
		break;
	case 5:
		input.at(index) = 5;
		break;
	case 6:
		input.at(index) = 7;
		break;
	case 7:
		input.at(index) = 7;
		break;
	case 8:
		input.at(index) = 8;
		break;
	case 9:
		input.at(index) = 13;
		break;
	case 10:
		input.at(index) = 10;
		break;
	case 11:
		input.at(index) = 11;
		break;
	case 12:
		input.at(index) = 13;
		break;
	case 13:
		input.at(index) = 13;
		break;
	case 14:
		input.at(index) = 14;
		break;
	case 15:
		input.at(index) = 16;
		break;
	case 16:
		input.at(index) = 16;
		break;
	case 17:
		input.at(index) = 17;
		break;
	case 18:
		input.at(index) = 22;
		break;
	case 19:
		input.at(index) = 19;
		break;
	case 20:
		input.at(index) = 20;
		break;
	case 21:
		input.at(index) = 22;
		break;
	case 22:
		input.at(index) = 22;
		break;
	case 23:
		input.at(index) = 23;
		break;
	case 24:
		input.at(index) = 25;
		break;
	case 25:
		input.at(index) = 25;
		break;
	case 26:
		input.at(index) = 26;
		break;
	case 27:
		input.at(index) = 40;
		break;
	case 28:
		input.at(index) = 28;
		break;
	case 29:
		input.at(index) = 29;
		break;
	case 30:
		input.at(index) = 31;
		break;
	case 31:
		input.at(index) = 31;
		break;
	case 32:
		input.at(index) = 32;
		break;
	case 33:
		input.at(index) = 34;
		break;
	case 34:
		input.at(index) = 34;
		break;
	case 35:
		input.at(index) = 35;
		break;
	case 36:
		input.at(index) = 40;
		break;
	case 37:
		input.at(index) = 37;
		break;
	case 38:
		input.at(index) = 38;
		break;
	case 39:
		input.at(index) = 40;
		break;
	case 40:
		input.at(index) = 40;
		break;
	case 41:
		input.at(index) = 41;
		break;
	case 42:
		input.at(index) = 43;
		break;
	case 43:
		input.at(index) = 43;
		break;
	case 44:
		input.at(index) = 44;
		break;
	case 45:
		input.at(index) = 49;
		break;
	case 46:
		input.at(index) = 46;
		break;
	case 47:
		input.at(index) = 47;
		break;
	case 48:
		input.at(index) = 49;
		break;
	case 49:
		input.at(index) = 49;
		break;
	case 50:
		input.at(index) = 50;
		break;
	case 51:
		input.at(index) = 52;
		break;
	case 52:
		input.at(index) = 52;
		break;
	case 53:
		input.at(index) = 53;
		break;
	case 54:
		input.at(index) = 67;
		break;
	case 55:
		input.at(index) = 55;
		break;
	case 56:
		input.at(index) = 56;
		break;
	case 57:
		input.at(index) = 58;
		break;
	case 58:
		input.at(index) = 58;
		break;
	case 59:
		input.at(index) = 59;
		break;
	case 60:
		input.at(index) = 61;
		break;
	case 61:
		input.at(index) = 61;
		break;
	case 62:
		input.at(index) = 62;
		break;
	case 63:
		input.at(index) = 67;
		break;
	case 64:
		input.at(index) = 64;
		break;
	case 65:
		input.at(index) = 65;
		break;
	case 66:
		input.at(index) = 67;
		break;
	case 67:
		input.at(index) = 67;
		break;
	case 68:
		input.at(index) = 68;
		break;
	case 69:
		input.at(index) = 70;
		break;
	case 70:
		input.at(index) = 70;
		break;
	case 71:
		input.at(index) = 71;
		break;
	case 72:
		input.at(index) = 76;
		break;
	case 73:
		input.at(index) = 73;
		break;
	case 74:
		input.at(index) = 74;
		break;
	case 75:
		input.at(index) = 76;
		break;
	case 76:
		input.at(index) = 76;
		break;
	case 77:
		input.at(index) = 77;
		break;
	case 78:
		input.at(index) = 79;
		break;
	case 79:
		input.at(index) = 79;
		break;
	case 80:
		input.at(index) = 80;
		break;
	case 81:
		input.at(index) = 121;
		break;
	case 82:
		input.at(index) = 82;
		break;
	case 83:
		input.at(index) = 83;
		break;
	case 84:
		input.at(index) = 85;
		break;
	case 85:
		input.at(index) = 85;
		break;
	case 86:
		input.at(index) = 86;
		break;
	case 87:
		input.at(index) = 88;
		break;
	case 88:
		input.at(index) = 88;
		break;
	case 89:
		input.at(index) = 89;
		break;
	case 90:
		input.at(index) = 94;
		break;
	case 91:
		input.at(index) = 91;
		break;
	case 92:
		input.at(index) = 92;
		break;
	case 93:
		input.at(index) = 94;
		break;
	case 94:
		input.at(index) = 94;
		break;
	case 95:
		input.at(index) = 95;
		break;
	case 96:
		input.at(index) = 97;
		break;
	case 97:
		input.at(index) = 97;
		break;
	case 98:
		input.at(index) = 98;
		break;
	case 99:
		input.at(index) = 103;
		break;
	case 100:
		input.at(index) = 100;
		break;
	case 101:
		input.at(index) = 101;
		break;
	case 102:
		input.at(index) = 103;
		break;
	case 103:
		input.at(index) = 103;
		break;
	case 104:
		input.at(index) = 104;
		break;
	case 105:
		input.at(index) = 106;
		break;
	case 106:
		input.at(index) = 106;
		break;
	case 107:
		input.at(index) = 107;
		break;
	case 108:
		input.at(index) = 121;
		break;
	case 109:
		input.at(index) = 109;
		break;
	case 110:
		input.at(index) = 110;
		break;
	case 111:
		input.at(index) = 112;
		break;
	case 112:
		input.at(index) = 112;
		break;
	case 113:
		input.at(index) = 113;
		break;
	case 114:
		input.at(index) = 115;
		break;
	case 115:
		input.at(index) = 115;
		break;
	case 116:
		input.at(index) = 116;
		break;
	case 117:
		input.at(index) = 121;
		break;
	case 118:
		input.at(index) = 118;
		break;
	case 119:
		input.at(index) = 119;
		break;
	case 120:
		input.at(index) = 121;
		break;
	case 121:
		input.at(index) = 121;
		break;
	case 122:
		input.at(index) = 122;
		break;
	case 123:
		input.at(index) = 124;
		break;
	case 124:
		input.at(index) = 124;
		break;
	case 125:
		input.at(index) = 125;
		break;
	case 126:
		input.at(index) = 130;
		break;
	case 127:
		input.at(index) = 127;
		break;
	case 128:
		input.at(index) = 128;
		break;
	case 129:
		input.at(index) = 130;
		break;
	case 130:
		input.at(index) = 130;
		break;
	case 131:
		input.at(index) = 131;
		break;
	case 132:
		input.at(index) = 133;
		break;
	case 133:
		input.at(index) = 133;
		break;
	case 134:
		input.at(index) = 134;
		break;
	case 135:
		input.at(index) = 148;
		break;
	case 136:
		input.at(index) = 136;
		break;
	case 137:
		input.at(index) = 137;
		break;
	case 138:
		input.at(index) = 139;
		break;
	case 139:
		input.at(index) = 139;
		break;
	case 140:
		input.at(index) = 140;
		break;
	case 141:
		input.at(index) = 142;
		break;
	case 142:
		input.at(index) = 142;
		break;
	case 143:
		input.at(index) = 143;
		break;
	case 144:
		input.at(index) = 148;
		break;
	case 145:
		input.at(index) = 145;
		break;
	case 146:
		input.at(index) = 146;
		break;
	case 147:
		input.at(index) = 148;
		break;
	case 148:
		input.at(index) = 148;
		break;
	case 149:
		input.at(index) = 149;
		break;
	case 150:
		input.at(index) = 151;
		break;
	case 151:
		input.at(index) = 151;
		break;
	case 152:
		input.at(index) = 152;
		break;
	case 153:
		input.at(index) = 157;
		break;
	case 154:
		input.at(index) = 154;
		break;
	case 155:
		input.at(index) = 155;
		break;
	case 156:
		input.at(index) = 157;
		break;
	case 157:
		input.at(index) = 157;
		break;
	case 158:
		input.at(index) = 158;
		break;
	case 159:
		input.at(index) = 160;
		break;
	case 160:
		input.at(index) = 160;
		break;
	case 161:
		input.at(index) = 161;
		break;
	case 162:
		input.at(index) = 202;
		break;
	case 163:
		input.at(index) = 163;
		break;
	case 164:
		input.at(index) = 164;
		break;
	case 165:
		input.at(index) = 166;
		break;
	case 166:
		input.at(index) = 166;
		break;
	case 167:
		input.at(index) = 167;
		break;
	case 168:
		input.at(index) = 169;
		break;
	case 169:
		input.at(index) = 169;
		break;
	case 170:
		input.at(index) = 170;
		break;
	case 171:
		input.at(index) = 175;
		break;
	case 172:
		input.at(index) = 172;
		break;
	case 173:
		input.at(index) = 173;
		break;
	case 174:
		input.at(index) = 175;
		break;
	case 175:
		input.at(index) = 175;
		break;
	case 176:
		input.at(index) = 176;
		break;
	case 177:
		input.at(index) = 178;
		break;
	case 178:
		input.at(index) = 178;
		break;
	case 179:
		input.at(index) = 179;
		break;
	case 180:
		input.at(index) = 184;
		break;
	case 181:
		input.at(index) = 181;
		break;
	case 182:
		input.at(index) = 182;
		break;
	case 183:
		input.at(index) = 184;
		break;
	case 184:
		input.at(index) = 184;
		break;
	case 185:
		input.at(index) = 185;
		break;
	case 186:
		input.at(index) = 187;
		break;
	case 187:
		input.at(index) = 187;
		break;
	case 188:
		input.at(index) = 188;
		break;
	case 189:
		input.at(index) = 202;
		break;
	case 190:
		input.at(index) = 190;
		break;
	case 191:
		input.at(index) = 191;
		break;
	case 192:
		input.at(index) = 193;
		break;
	case 193:
		input.at(index) = 193;
		break;
	case 194:
		input.at(index) = 194;
		break;
	case 195:
		input.at(index) = 196;
		break;
	case 196:
		input.at(index) = 196;
		break;
	case 197:
		input.at(index) = 197;
		break;
	case 198:
		input.at(index) = 202;
		break;
	case 199:
		input.at(index) = 199;
		break;
	case 200:
		input.at(index) = 200;
		break;
	case 201:
		input.at(index) = 202;
		break;
	case 202:
		input.at(index) = 202;
		break;
	case 203:
		input.at(index) = 203;
		break;
	case 204:
		input.at(index) = 205;
		break;
	case 205:
		input.at(index) = 205;
		break;
	case 206:
		input.at(index) = 206;
		break;
	case 207:
		input.at(index) = 211;
		break;
	case 208:
		input.at(index) = 208;
		break;
	case 209:
		input.at(index) = 209;
		break;
	case 210:
		input.at(index) = 211;
		break;
	case 211:
		input.at(index) = 211;
		break;
	case 212:
		input.at(index) = 212;
		break;
	case 213:
		input.at(index) = 214;
		break;
	case 214:
		input.at(index) = 214;
		break;
	case 215:
		input.at(index) = 215;
		break;
	case 216:
		input.at(index) = 229;
		break;
	case 217:
		input.at(index) = 217;
		break;
	case 218:
		input.at(index) = 218;
		break;
	case 219:
		input.at(index) = 220;
		break;
	case 220:
		input.at(index) = 220;
		break;
	case 221:
		input.at(index) = 221;
		break;
	case 222:
		input.at(index) = 223;
		break;
	case 223:
		input.at(index) = 223;
		break;
	case 224:
		input.at(index) = 224;
		break;
	case 225:
		input.at(index) = 229;
		break;
	case 226:
		input.at(index) = 226;
		break;
	case 227:
		input.at(index) = 227;
		break;
	case 228:
		input.at(index) = 229;
		break;
	case 229:
		input.at(index) = 229;
		break;
	case 230:
		input.at(index) = 230;
		break;
	case 231:
		input.at(index) = 232;
		break;
	case 232:
		input.at(index) = 232;
		break;
	case 233:
		input.at(index) = 233;
		break;
	case 234:
		input.at(index) = 238;
		break;
	case 235:
		input.at(index) = 235;
		break;
	case 236:
		input.at(index) = 236;
		break;
	case 237:
		input.at(index) = 238;
		break;
	case 238:
		input.at(index) = 238;
		break;
	case 239:
		input.at(index) = 239;
		break;
	case 240:
		input.at(index) = 241;
		break;
	case 241:
		input.at(index) = 241;
		break;
	case 242:
		input.at(index) = 242;
		break;
	}
   */
   	switch(input.at(index)) {
	case 0:
		input.at(index) = 121;
		break;
	case 1:
		input.at(index) = 1;
		break;
	case 2:
		input.at(index) = 2;
		break;
	case 3:
		input.at(index) = 4;
		break;
	case 4:
		input.at(index) = 4;
		break;
	case 5:
		input.at(index) = 5;
		break;
	case 6:
		input.at(index) = 7;
		break;
	case 7:
		input.at(index) = 7;
		break;
	case 8:
		input.at(index) = 8;
		break;
	case 9:
		input.at(index) = 13;
		break;
	case 10:
		input.at(index) = 10;
		break;
	case 11:
		input.at(index) = 11;
		break;
	case 12:
		input.at(index) = 13;
		break;
	case 13:
		input.at(index) = 13;
		break;
	case 14:
		input.at(index) = 14;
		break;
	case 15:
		input.at(index) = 16;
		break;
	case 16:
		input.at(index) = 16;
		break;
	case 17:
		input.at(index) = 17;
		break;
	case 18:
		input.at(index) = 22;
		break;
	case 19:
		input.at(index) = 19;
		break;
	case 20:
		input.at(index) = 20;
		break;
	case 21:
		input.at(index) = 22;
		break;
	case 22:
		input.at(index) = 22;
		break;
	case 23:
		input.at(index) = 23;
		break;
	case 24:
		input.at(index) = 25;
		break;
	case 25:
		input.at(index) = 25;
		break;
	case 26:
		input.at(index) = 26;
		break;
	case 27:
		input.at(index) = 40;
		break;
	case 28:
		input.at(index) = 28;
		break;
	case 29:
		input.at(index) = 29;
		break;
	case 30:
		input.at(index) = 31;
		break;
	case 31:
		input.at(index) = 31;
		break;
	case 32:
		input.at(index) = 32;
		break;
	case 33:
		input.at(index) = 34;
		break;
	case 34:
		input.at(index) = 34;
		break;
	case 35:
		input.at(index) = 35;
		break;
	case 36:
		input.at(index) = 40;
		break;
	case 37:
		input.at(index) = 37;
		break;
	case 38:
		input.at(index) = 38;
		break;
	case 39:
		input.at(index) = 40;
		break;
	case 40:
		input.at(index) = 40;
		break;
	case 41:
		input.at(index) = 41;
		break;
	case 42:
		input.at(index) = 43;
		break;
	case 43:
		input.at(index) = 43;
		break;
	case 44:
		input.at(index) = 44;
		break;
	case 45:
		input.at(index) = 49;
		break;
	case 46:
		input.at(index) = 46;
		break;
	case 47:
		input.at(index) = 47;
		break;
	case 48:
		input.at(index) = 49;
		break;
	case 49:
		input.at(index) = 49;
		break;
	case 50:
		input.at(index) = 50;
		break;
	case 51:
		input.at(index) = 52;
		break;
	case 52:
		input.at(index) = 52;
		break;
	case 53:
		input.at(index) = 53;
		break;
	case 54:
		input.at(index) = 67;
		break;
	case 55:
		input.at(index) = 55;
		break;
	case 56:
		input.at(index) = 56;
		break;
	case 57:
		input.at(index) = 58;
		break;
	case 58:
		input.at(index) = 58;
		break;
	case 59:
		input.at(index) = 59;
		break;
	case 60:
		input.at(index) = 61;
		break;
	case 61:
		input.at(index) = 61;
		break;
	case 62:
		input.at(index) = 62;
		break;
	case 63:
		input.at(index) = 67;
		break;
	case 64:
		input.at(index) = 64;
		break;
	case 65:
		input.at(index) = 65;
		break;
	case 66:
		input.at(index) = 67;
		break;
	case 67:
		input.at(index) = 67;
		break;
	case 68:
		input.at(index) = 68;
		break;
	case 69:
		input.at(index) = 70;
		break;
	case 70:
		input.at(index) = 70;
		break;
	case 71:
		input.at(index) = 71;
		break;
	case 72:
		input.at(index) = 76;
		break;
	case 73:
		input.at(index) = 73;
		break;
	case 74:
		input.at(index) = 74;
		break;
	case 75:
		input.at(index) = 76;
		break;
	case 76:
		input.at(index) = 76;
		break;
	case 77:
		input.at(index) = 77;
		break;
	case 78:
		input.at(index) = 79;
		break;
	case 79:
		input.at(index) = 79;
		break;
	case 80:
		input.at(index) = 80;
		break;
	case 81:
		input.at(index) = 121;
		break;
	case 82:
		input.at(index) = 82;
		break;
	case 83:
		input.at(index) = 83;
		break;
	case 84:
		input.at(index) = 85;
		break;
	case 85:
		input.at(index) = 85;
		break;
	case 86:
		input.at(index) = 86;
		break;
	case 87:
		input.at(index) = 88;
		break;
	case 88:
		input.at(index) = 88;
		break;
	case 89:
		input.at(index) = 89;
		break;
	case 90:
		input.at(index) = 94;
		break;
	case 91:
		input.at(index) = 91;
		break;
	case 92:
		input.at(index) = 92;
		break;
	case 93:
		input.at(index) = 94;
		break;
	case 94:
		input.at(index) = 94;
		break;
	case 95:
		input.at(index) = 95;
		break;
	case 96:
		input.at(index) = 97;
		break;
	case 97:
		input.at(index) = 97;
		break;
	case 98:
		input.at(index) = 98;
		break;
	case 99:
		input.at(index) = 103;
		break;
	case 100:
		input.at(index) = 100;
		break;
	case 101:
		input.at(index) = 101;
		break;
	case 102:
		input.at(index) = 103;
		break;
	case 103:
		input.at(index) = 103;
		break;
	case 104:
		input.at(index) = 104;
		break;
	case 105:
		input.at(index) = 106;
		break;
	case 106:
		input.at(index) = 106;
		break;
	case 107:
		input.at(index) = 107;
		break;
	case 108:
		input.at(index) = 121;
		break;
	case 109:
		input.at(index) = 109;
		break;
	case 110:
		input.at(index) = 110;
		break;
	case 111:
		input.at(index) = 112;
		break;
	case 112:
		input.at(index) = 112;
		break;
	case 113:
		input.at(index) = 113;
		break;
	case 114:
		input.at(index) = 115;
		break;
	case 115:
		input.at(index) = 115;
		break;
	case 116:
		input.at(index) = 116;
		break;
	case 117:
		input.at(index) = 121;
		break;
	case 118:
		input.at(index) = 118;
		break;
	case 119:
		input.at(index) = 119;
		break;
	case 120:
		input.at(index) = 121;
		break;
	case 121:
		input.at(index) = 121;
		break;
	case 122:
		input.at(index) = 122;
		break;
	case 123:
		input.at(index) = 124;
		break;
	case 124:
		input.at(index) = 124;
		break;
	case 125:
		input.at(index) = 125;
		break;
	case 126:
		input.at(index) = 130;
		break;
	case 127:
		input.at(index) = 127;
		break;
	case 128:
		input.at(index) = 128;
		break;
	case 129:
		input.at(index) = 130;
		break;
	case 130:
		input.at(index) = 130;
		break;
	case 131:
		input.at(index) = 131;
		break;
	case 132:
		input.at(index) = 133;
		break;
	case 133:
		input.at(index) = 133;
		break;
	case 134:
		input.at(index) = 134;
		break;
	case 135:
		input.at(index) = 148;
		break;
	case 136:
		input.at(index) = 136;
		break;
	case 137:
		input.at(index) = 137;
		break;
	case 138:
		input.at(index) = 139;
		break;
	case 139:
		input.at(index) = 139;
		break;
	case 140:
		input.at(index) = 140;
		break;
	case 141:
		input.at(index) = 142;
		break;
	case 142:
		input.at(index) = 142;
		break;
	case 143:
		input.at(index) = 143;
		break;
	case 144:
		input.at(index) = 148;
		break;
	case 145:
		input.at(index) = 145;
		break;
	case 146:
		input.at(index) = 146;
		break;
	case 147:
		input.at(index) = 148;
		break;
	case 148:
		input.at(index) = 148;
		break;
	case 149:
		input.at(index) = 149;
		break;
	case 150:
		input.at(index) = 151;
		break;
	case 151:
		input.at(index) = 151;
		break;
	case 152:
		input.at(index) = 152;
		break;
	case 153:
		input.at(index) = 157;
		break;
	case 154:
		input.at(index) = 154;
		break;
	case 155:
		input.at(index) = 155;
		break;
	case 156:
		input.at(index) = 157;
		break;
	case 157:
		input.at(index) = 157;
		break;
	case 158:
		input.at(index) = 158;
		break;
	case 159:
		input.at(index) = 160;
		break;
	case 160:
		input.at(index) = 160;
		break;
	case 161:
		input.at(index) = 161;
		break;
	case 162:
		input.at(index) = 202;
		break;
	case 163:
		input.at(index) = 163;
		break;
	case 164:
		input.at(index) = 164;
		break;
	case 165:
		input.at(index) = 166;
		break;
	case 166:
		input.at(index) = 166;
		break;
	case 167:
		input.at(index) = 167;
		break;
	case 168:
		input.at(index) = 169;
		break;
	case 169:
		input.at(index) = 169;
		break;
	case 170:
		input.at(index) = 170;
		break;
	case 171:
		input.at(index) = 175;
		break;
	case 172:
		input.at(index) = 172;
		break;
	case 173:
		input.at(index) = 173;
		break;
	case 174:
		input.at(index) = 175;
		break;
	case 175:
		input.at(index) = 175;
		break;
	case 176:
		input.at(index) = 176;
		break;
	case 177:
		input.at(index) = 178;
		break;
	case 178:
		input.at(index) = 178;
		break;
	case 179:
		input.at(index) = 179;
		break;
	case 180:
		input.at(index) = 184;
		break;
	case 181:
		input.at(index) = 181;
		break;
	case 182:
		input.at(index) = 182;
		break;
	case 183:
		input.at(index) = 184;
		break;
	case 184:
		input.at(index) = 184;
		break;
	case 185:
		input.at(index) = 185;
		break;
	case 186:
		input.at(index) = 187;
		break;
	case 187:
		input.at(index) = 187;
		break;
	case 188:
		input.at(index) = 188;
		break;
	case 189:
		input.at(index) = 202;
		break;
	case 190:
		input.at(index) = 190;
		break;
	case 191:
		input.at(index) = 191;
		break;
	case 192:
		input.at(index) = 193;
		break;
	case 193:
		input.at(index) = 193;
		break;
	case 194:
		input.at(index) = 194;
		break;
	case 195:
		input.at(index) = 196;
		break;
	case 196:
		input.at(index) = 196;
		break;
	case 197:
		input.at(index) = 197;
		break;
	case 198:
		input.at(index) = 202;
		break;
	case 199:
		input.at(index) = 199;
		break;
	case 200:
		input.at(index) = 200;
		break;
	case 201:
		input.at(index) = 202;
		break;
	case 202:
		input.at(index) = 202;
		break;
	case 203:
		input.at(index) = 203;
		break;
	case 204:
		input.at(index) = 205;
		break;
	case 205:
		input.at(index) = 205;
		break;
	case 206:
		input.at(index) = 206;
		break;
	case 207:
		input.at(index) = 211;
		break;
	case 208:
		input.at(index) = 208;
		break;
	case 209:
		input.at(index) = 209;
		break;
	case 210:
		input.at(index) = 211;
		break;
	case 211:
		input.at(index) = 211;
		break;
	case 212:
		input.at(index) = 212;
		break;
	case 213:
		input.at(index) = 214;
		break;
	case 214:
		input.at(index) = 214;
		break;
	case 215:
		input.at(index) = 215;
		break;
	case 216:
		input.at(index) = 229;
		break;
	case 217:
		input.at(index) = 217;
		break;
	case 218:
		input.at(index) = 218;
		break;
	case 219:
		input.at(index) = 220;
		break;
	case 220:
		input.at(index) = 220;
		break;
	case 221:
		input.at(index) = 221;
		break;
	case 222:
		input.at(index) = 223;
		break;
	case 223:
		input.at(index) = 223;
		break;
	case 224:
		input.at(index) = 224;
		break;
	case 225:
		input.at(index) = 229;
		break;
	case 226:
		input.at(index) = 226;
		break;
	case 227:
		input.at(index) = 227;
		break;
	case 228:
		input.at(index) = 229;
		break;
	case 229:
		input.at(index) = 229;
		break;
	case 230:
		input.at(index) = 230;
		break;
	case 231:
		input.at(index) = 232;
		break;
	case 232:
		input.at(index) = 232;
		break;
	case 233:
		input.at(index) = 233;
		break;
	case 234:
		input.at(index) = 238;
		break;
	case 235:
		input.at(index) = 235;
		break;
	case 236:
		input.at(index) = 236;
		break;
	case 237:
		input.at(index) = 238;
		break;
	case 238:
		input.at(index) = 238;
		break;
	case 239:
		input.at(index) = 239;
		break;
	case 240:
		input.at(index) = 241;
		break;
	case 241:
		input.at(index) = 241;
		break;
	case 242:
		input.at(index) = 242;
		break;
   default:
      std::cerr << "ILLEGAL INPUT TO B243::FILLZERO" << std::endl;
      break;
   }
   
   while (index < input.size() - 1) {
      input.at(++index) = shift; //= 121, equiv. to all left-branches; i.e., 1's.
   }
}

int Base243TrieRelation::highestSetBit(int input) const {
   if (input == 0) return 0;
   else if (input % 3 != 0) return 5;
   else if (input % 9 != 0) return 4;
   else if (input % 27 != 0) return 3;
   else if (input % 81 != 0) return 2;
   else return 1;
}

//TODO!
int Base243TrieRelation::highestSetBitFlat(int input) const {
   return highestSetBit(input);
}

void Base243TrieRelation::popOne(vector<int>& input, int& last, int& index) {
   int lastBitSet = highestSetBit(input.at(index));

   switch (lastBitSet) {
      case 0:
         std::cerr << "ERROR: Popping an empty" << std::endl;
         break;
      case 5:
         last = input.at(index)%3 - 1;
         input.at(index) = input.at(index) - (last + 1);
         break;
      case 4:
         last = input.at(index)% 9;
         input.at(index) -= last;
         last = (last / 3) - 1;
         break;
      case 3:
         last = input.at(index) % 27;
         input.at(index) -= last;
         last = (last / 9) - 1;
         break;
      case 2:
         last = input.at(index) % 81;
         input.at(index) -= last;
         last = (last / 27) - 1;
         break;
      case 1:
         last = input.at(index); //%243 is redundant
         input.at(index) = 0;
         last = (last / 81) - 1;
         break;
      default:
         std::cerr << "ERROR: Highest set bit greater than five???" << std::endl;
   }
   return;
}

//for compat reasons... 
//I should fill this in at some point with an actual flattened version.
void Base243TrieRelation::popOneFlat(vector<int>& input, int& last, int& index) {
   this->popOne(input, last, index);
}

//Pops until non-lambda at the end...
void Base243TrieRelation::popOne(vector<int>& input, int& index) {
   	switch(input.at(index)) {
	case 0:
		input.at(index) = 0;
		break;
	case 1:
		input.at(index) = 0;
		break;
	case 2:
		input.at(index) = 0;
		break;
	case 3:
		input.at(index) = 0;
		break;
	case 4:
		input.at(index) = 3;
		break;
	case 5:
		input.at(index) = 3;
		break;
	case 6:
		input.at(index) = 0;
		break;
	case 7:
		input.at(index) = 6;
		break;
	case 8:
		input.at(index) = 6;
		break;
	case 9:
		input.at(index) = 0;
		break;
	case 10:
		input.at(index) = 9;
		break;
	case 11:
		input.at(index) = 9;
		break;
	case 12:
		input.at(index) = 9;
		break;
	case 13:
		input.at(index) = 12;
		break;
	case 14:
		input.at(index) = 12;
		break;
	case 15:
		input.at(index) = 9;
		break;
	case 16:
		input.at(index) = 15;
		break;
	case 17:
		input.at(index) = 15;
		break;
	case 18:
		input.at(index) = 0;
		break;
	case 19:
		input.at(index) = 18;
		break;
	case 20:
		input.at(index) = 18;
		break;
	case 21:
		input.at(index) = 18;
		break;
	case 22:
		input.at(index) = 21;
		break;
	case 23:
		input.at(index) = 21;
		break;
	case 24:
		input.at(index) = 18;
		break;
	case 25:
		input.at(index) = 24;
		break;
	case 26:
		input.at(index) = 24;
		break;
	case 27:
		input.at(index) = 0;
		break;
	case 28:
		input.at(index) = 27;
		break;
	case 29:
		input.at(index) = 27;
		break;
	case 30:
		input.at(index) = 27;
		break;
	case 31:
		input.at(index) = 30;
		break;
	case 32:
		input.at(index) = 30;
		break;
	case 33:
		input.at(index) = 27;
		break;
	case 34:
		input.at(index) = 33;
		break;
	case 35:
		input.at(index) = 33;
		break;
	case 36:
		input.at(index) = 27;
		break;
	case 37:
		input.at(index) = 36;
		break;
	case 38:
		input.at(index) = 36;
		break;
	case 39:
		input.at(index) = 36;
		break;
	case 40:
		input.at(index) = 39;
		break;
	case 41:
		input.at(index) = 39;
		break;
	case 42:
		input.at(index) = 36;
		break;
	case 43:
		input.at(index) = 42;
		break;
	case 44:
		input.at(index) = 42;
		break;
	case 45:
		input.at(index) = 27;
		break;
	case 46:
		input.at(index) = 45;
		break;
	case 47:
		input.at(index) = 45;
		break;
	case 48:
		input.at(index) = 45;
		break;
	case 49:
		input.at(index) = 48;
		break;
	case 50:
		input.at(index) = 48;
		break;
	case 51:
		input.at(index) = 45;
		break;
	case 52:
		input.at(index) = 51;
		break;
	case 53:
		input.at(index) = 51;
		break;
	case 54:
		input.at(index) = 0;
		break;
	case 55:
		input.at(index) = 54;
		break;
	case 56:
		input.at(index) = 54;
		break;
	case 57:
		input.at(index) = 54;
		break;
	case 58:
		input.at(index) = 57;
		break;
	case 59:
		input.at(index) = 57;
		break;
	case 60:
		input.at(index) = 54;
		break;
	case 61:
		input.at(index) = 60;
		break;
	case 62:
		input.at(index) = 60;
		break;
	case 63:
		input.at(index) = 54;
		break;
	case 64:
		input.at(index) = 63;
		break;
	case 65:
		input.at(index) = 63;
		break;
	case 66:
		input.at(index) = 63;
		break;
	case 67:
		input.at(index) = 66;
		break;
	case 68:
		input.at(index) = 66;
		break;
	case 69:
		input.at(index) = 63;
		break;
	case 70:
		input.at(index) = 69;
		break;
	case 71:
		input.at(index) = 69;
		break;
	case 72:
		input.at(index) = 54;
		break;
	case 73:
		input.at(index) = 72;
		break;
	case 74:
		input.at(index) = 72;
		break;
	case 75:
		input.at(index) = 72;
		break;
	case 76:
		input.at(index) = 75;
		break;
	case 77:
		input.at(index) = 75;
		break;
	case 78:
		input.at(index) = 72;
		break;
	case 79:
		input.at(index) = 78;
		break;
	case 80:
		input.at(index) = 78;
		break;
	case 81:
		input.at(index) = 0;
		break;
	case 82:
		input.at(index) = 81;
		break;
	case 83:
		input.at(index) = 81;
		break;
	case 84:
		input.at(index) = 81;
		break;
	case 85:
		input.at(index) = 84;
		break;
	case 86:
		input.at(index) = 84;
		break;
	case 87:
		input.at(index) = 81;
		break;
	case 88:
		input.at(index) = 87;
		break;
	case 89:
		input.at(index) = 87;
		break;
	case 90:
		input.at(index) = 81;
		break;
	case 91:
		input.at(index) = 90;
		break;
	case 92:
		input.at(index) = 90;
		break;
	case 93:
		input.at(index) = 90;
		break;
	case 94:
		input.at(index) = 93;
		break;
	case 95:
		input.at(index) = 93;
		break;
	case 96:
		input.at(index) = 90;
		break;
	case 97:
		input.at(index) = 96;
		break;
	case 98:
		input.at(index) = 96;
		break;
	case 99:
		input.at(index) = 81;
		break;
	case 100:
		input.at(index) = 99;
		break;
	case 101:
		input.at(index) = 99;
		break;
	case 102:
		input.at(index) = 99;
		break;
	case 103:
		input.at(index) = 102;
		break;
	case 104:
		input.at(index) = 102;
		break;
	case 105:
		input.at(index) = 99;
		break;
	case 106:
		input.at(index) = 105;
		break;
	case 107:
		input.at(index) = 105;
		break;
	case 108:
		input.at(index) = 81;
		break;
	case 109:
		input.at(index) = 108;
		break;
	case 110:
		input.at(index) = 108;
		break;
	case 111:
		input.at(index) = 108;
		break;
	case 112:
		input.at(index) = 111;
		break;
	case 113:
		input.at(index) = 111;
		break;
	case 114:
		input.at(index) = 108;
		break;
	case 115:
		input.at(index) = 114;
		break;
	case 116:
		input.at(index) = 114;
		break;
	case 117:
		input.at(index) = 108;
		break;
	case 118:
		input.at(index) = 117;
		break;
	case 119:
		input.at(index) = 117;
		break;
	case 120:
		input.at(index) = 117;
		break;
	case 121:
		input.at(index) = 120;
		break;
	case 122:
		input.at(index) = 120;
		break;
	case 123:
		input.at(index) = 117;
		break;
	case 124:
		input.at(index) = 123;
		break;
	case 125:
		input.at(index) = 123;
		break;
	case 126:
		input.at(index) = 108;
		break;
	case 127:
		input.at(index) = 126;
		break;
	case 128:
		input.at(index) = 126;
		break;
	case 129:
		input.at(index) = 126;
		break;
	case 130:
		input.at(index) = 129;
		break;
	case 131:
		input.at(index) = 129;
		break;
	case 132:
		input.at(index) = 126;
		break;
	case 133:
		input.at(index) = 132;
		break;
	case 134:
		input.at(index) = 132;
		break;
	case 135:
		input.at(index) = 81;
		break;
	case 136:
		input.at(index) = 135;
		break;
	case 137:
		input.at(index) = 135;
		break;
	case 138:
		input.at(index) = 135;
		break;
	case 139:
		input.at(index) = 138;
		break;
	case 140:
		input.at(index) = 138;
		break;
	case 141:
		input.at(index) = 135;
		break;
	case 142:
		input.at(index) = 141;
		break;
	case 143:
		input.at(index) = 141;
		break;
	case 144:
		input.at(index) = 135;
		break;
	case 145:
		input.at(index) = 144;
		break;
	case 146:
		input.at(index) = 144;
		break;
	case 147:
		input.at(index) = 144;
		break;
	case 148:
		input.at(index) = 147;
		break;
	case 149:
		input.at(index) = 147;
		break;
	case 150:
		input.at(index) = 144;
		break;
	case 151:
		input.at(index) = 150;
		break;
	case 152:
		input.at(index) = 150;
		break;
	case 153:
		input.at(index) = 135;
		break;
	case 154:
		input.at(index) = 153;
		break;
	case 155:
		input.at(index) = 153;
		break;
	case 156:
		input.at(index) = 153;
		break;
	case 157:
		input.at(index) = 156;
		break;
	case 158:
		input.at(index) = 156;
		break;
	case 159:
		input.at(index) = 153;
		break;
	case 160:
		input.at(index) = 159;
		break;
	case 161:
		input.at(index) = 159;
		break;
	case 162:
		input.at(index) = 0;
		break;
	case 163:
		input.at(index) = 162;
		break;
	case 164:
		input.at(index) = 162;
		break;
	case 165:
		input.at(index) = 162;
		break;
	case 166:
		input.at(index) = 165;
		break;
	case 167:
		input.at(index) = 165;
		break;
	case 168:
		input.at(index) = 162;
		break;
	case 169:
		input.at(index) = 168;
		break;
	case 170:
		input.at(index) = 168;
		break;
	case 171:
		input.at(index) = 162;
		break;
	case 172:
		input.at(index) = 171;
		break;
	case 173:
		input.at(index) = 171;
		break;
	case 174:
		input.at(index) = 171;
		break;
	case 175:
		input.at(index) = 174;
		break;
	case 176:
		input.at(index) = 174;
		break;
	case 177:
		input.at(index) = 171;
		break;
	case 178:
		input.at(index) = 177;
		break;
	case 179:
		input.at(index) = 177;
		break;
	case 180:
		input.at(index) = 162;
		break;
	case 181:
		input.at(index) = 180;
		break;
	case 182:
		input.at(index) = 180;
		break;
	case 183:
		input.at(index) = 180;
		break;
	case 184:
		input.at(index) = 183;
		break;
	case 185:
		input.at(index) = 183;
		break;
	case 186:
		input.at(index) = 180;
		break;
	case 187:
		input.at(index) = 186;
		break;
	case 188:
		input.at(index) = 186;
		break;
	case 189:
		input.at(index) = 162;
		break;
	case 190:
		input.at(index) = 189;
		break;
	case 191:
		input.at(index) = 189;
		break;
	case 192:
		input.at(index) = 189;
		break;
	case 193:
		input.at(index) = 192;
		break;
	case 194:
		input.at(index) = 192;
		break;
	case 195:
		input.at(index) = 189;
		break;
	case 196:
		input.at(index) = 195;
		break;
	case 197:
		input.at(index) = 195;
		break;
	case 198:
		input.at(index) = 189;
		break;
	case 199:
		input.at(index) = 198;
		break;
	case 200:
		input.at(index) = 198;
		break;
	case 201:
		input.at(index) = 198;
		break;
	case 202:
		input.at(index) = 201;
		break;
	case 203:
		input.at(index) = 201;
		break;
	case 204:
		input.at(index) = 198;
		break;
	case 205:
		input.at(index) = 204;
		break;
	case 206:
		input.at(index) = 204;
		break;
	case 207:
		input.at(index) = 189;
		break;
	case 208:
		input.at(index) = 207;
		break;
	case 209:
		input.at(index) = 207;
		break;
	case 210:
		input.at(index) = 207;
		break;
	case 211:
		input.at(index) = 210;
		break;
	case 212:
		input.at(index) = 210;
		break;
	case 213:
		input.at(index) = 207;
		break;
	case 214:
		input.at(index) = 213;
		break;
	case 215:
		input.at(index) = 213;
		break;
	case 216:
		input.at(index) = 162;
		break;
	case 217:
		input.at(index) = 216;
		break;
	case 218:
		input.at(index) = 216;
		break;
	case 219:
		input.at(index) = 216;
		break;
	case 220:
		input.at(index) = 219;
		break;
	case 221:
		input.at(index) = 219;
		break;
	case 222:
		input.at(index) = 216;
		break;
	case 223:
		input.at(index) = 222;
		break;
	case 224:
		input.at(index) = 222;
		break;
	case 225:
		input.at(index) = 216;
		break;
	case 226:
		input.at(index) = 225;
		break;
	case 227:
		input.at(index) = 225;
		break;
	case 228:
		input.at(index) = 225;
		break;
	case 229:
		input.at(index) = 228;
		break;
	case 230:
		input.at(index) = 228;
		break;
	case 231:
		input.at(index) = 225;
		break;
	case 232:
		input.at(index) = 231;
		break;
	case 233:
		input.at(index) = 231;
		break;
	case 234:
		input.at(index) = 216;
		break;
	case 235:
		input.at(index) = 234;
		break;
	case 236:
		input.at(index) = 234;
		break;
	case 237:
		input.at(index) = 234;
		break;
	case 238:
		input.at(index) = 237;
		break;
	case 239:
		input.at(index) = 237;
		break;
	case 240:
		input.at(index) = 234;
		break;
	case 241:
		input.at(index) = 240;
		break;
	case 242:
		input.at(index) = 240;
		break;
	}
   return;
}

//Pops until non-lambda at the end... This is ugh btw.
void Base243TrieRelation::popOneConst(vector<int>& input, int& index) const {
   	switch(input.at(index)) {
	case 0:
		input.at(index) = 0;
		break;
	case 1:
		input.at(index) = 0;
		break;
	case 2:
		input.at(index) = 0;
		break;
	case 3:
		input.at(index) = 0;
		break;
	case 4:
		input.at(index) = 3;
		break;
	case 5:
		input.at(index) = 3;
		break;
	case 6:
		input.at(index) = 0;
		break;
	case 7:
		input.at(index) = 6;
		break;
	case 8:
		input.at(index) = 6;
		break;
	case 9:
		input.at(index) = 0;
		break;
	case 10:
		input.at(index) = 9;
		break;
	case 11:
		input.at(index) = 9;
		break;
	case 12:
		input.at(index) = 9;
		break;
	case 13:
		input.at(index) = 12;
		break;
	case 14:
		input.at(index) = 12;
		break;
	case 15:
		input.at(index) = 9;
		break;
	case 16:
		input.at(index) = 15;
		break;
	case 17:
		input.at(index) = 15;
		break;
	case 18:
		input.at(index) = 0;
		break;
	case 19:
		input.at(index) = 18;
		break;
	case 20:
		input.at(index) = 18;
		break;
	case 21:
		input.at(index) = 18;
		break;
	case 22:
		input.at(index) = 21;
		break;
	case 23:
		input.at(index) = 21;
		break;
	case 24:
		input.at(index) = 18;
		break;
	case 25:
		input.at(index) = 24;
		break;
	case 26:
		input.at(index) = 24;
		break;
	case 27:
		input.at(index) = 0;
		break;
	case 28:
		input.at(index) = 27;
		break;
	case 29:
		input.at(index) = 27;
		break;
	case 30:
		input.at(index) = 27;
		break;
	case 31:
		input.at(index) = 30;
		break;
	case 32:
		input.at(index) = 30;
		break;
	case 33:
		input.at(index) = 27;
		break;
	case 34:
		input.at(index) = 33;
		break;
	case 35:
		input.at(index) = 33;
		break;
	case 36:
		input.at(index) = 27;
		break;
	case 37:
		input.at(index) = 36;
		break;
	case 38:
		input.at(index) = 36;
		break;
	case 39:
		input.at(index) = 36;
		break;
	case 40:
		input.at(index) = 39;
		break;
	case 41:
		input.at(index) = 39;
		break;
	case 42:
		input.at(index) = 36;
		break;
	case 43:
		input.at(index) = 42;
		break;
	case 44:
		input.at(index) = 42;
		break;
	case 45:
		input.at(index) = 27;
		break;
	case 46:
		input.at(index) = 45;
		break;
	case 47:
		input.at(index) = 45;
		break;
	case 48:
		input.at(index) = 45;
		break;
	case 49:
		input.at(index) = 48;
		break;
	case 50:
		input.at(index) = 48;
		break;
	case 51:
		input.at(index) = 45;
		break;
	case 52:
		input.at(index) = 51;
		break;
	case 53:
		input.at(index) = 51;
		break;
	case 54:
		input.at(index) = 0;
		break;
	case 55:
		input.at(index) = 54;
		break;
	case 56:
		input.at(index) = 54;
		break;
	case 57:
		input.at(index) = 54;
		break;
	case 58:
		input.at(index) = 57;
		break;
	case 59:
		input.at(index) = 57;
		break;
	case 60:
		input.at(index) = 54;
		break;
	case 61:
		input.at(index) = 60;
		break;
	case 62:
		input.at(index) = 60;
		break;
	case 63:
		input.at(index) = 54;
		break;
	case 64:
		input.at(index) = 63;
		break;
	case 65:
		input.at(index) = 63;
		break;
	case 66:
		input.at(index) = 63;
		break;
	case 67:
		input.at(index) = 66;
		break;
	case 68:
		input.at(index) = 66;
		break;
	case 69:
		input.at(index) = 63;
		break;
	case 70:
		input.at(index) = 69;
		break;
	case 71:
		input.at(index) = 69;
		break;
	case 72:
		input.at(index) = 54;
		break;
	case 73:
		input.at(index) = 72;
		break;
	case 74:
		input.at(index) = 72;
		break;
	case 75:
		input.at(index) = 72;
		break;
	case 76:
		input.at(index) = 75;
		break;
	case 77:
		input.at(index) = 75;
		break;
	case 78:
		input.at(index) = 72;
		break;
	case 79:
		input.at(index) = 78;
		break;
	case 80:
		input.at(index) = 78;
		break;
	case 81:
		input.at(index) = 0;
		break;
	case 82:
		input.at(index) = 81;
		break;
	case 83:
		input.at(index) = 81;
		break;
	case 84:
		input.at(index) = 81;
		break;
	case 85:
		input.at(index) = 84;
		break;
	case 86:
		input.at(index) = 84;
		break;
	case 87:
		input.at(index) = 81;
		break;
	case 88:
		input.at(index) = 87;
		break;
	case 89:
		input.at(index) = 87;
		break;
	case 90:
		input.at(index) = 81;
		break;
	case 91:
		input.at(index) = 90;
		break;
	case 92:
		input.at(index) = 90;
		break;
	case 93:
		input.at(index) = 90;
		break;
	case 94:
		input.at(index) = 93;
		break;
	case 95:
		input.at(index) = 93;
		break;
	case 96:
		input.at(index) = 90;
		break;
	case 97:
		input.at(index) = 96;
		break;
	case 98:
		input.at(index) = 96;
		break;
	case 99:
		input.at(index) = 81;
		break;
	case 100:
		input.at(index) = 99;
		break;
	case 101:
		input.at(index) = 99;
		break;
	case 102:
		input.at(index) = 99;
		break;
	case 103:
		input.at(index) = 102;
		break;
	case 104:
		input.at(index) = 102;
		break;
	case 105:
		input.at(index) = 99;
		break;
	case 106:
		input.at(index) = 105;
		break;
	case 107:
		input.at(index) = 105;
		break;
	case 108:
		input.at(index) = 81;
		break;
	case 109:
		input.at(index) = 108;
		break;
	case 110:
		input.at(index) = 108;
		break;
	case 111:
		input.at(index) = 108;
		break;
	case 112:
		input.at(index) = 111;
		break;
	case 113:
		input.at(index) = 111;
		break;
	case 114:
		input.at(index) = 108;
		break;
	case 115:
		input.at(index) = 114;
		break;
	case 116:
		input.at(index) = 114;
		break;
	case 117:
		input.at(index) = 108;
		break;
	case 118:
		input.at(index) = 117;
		break;
	case 119:
		input.at(index) = 117;
		break;
	case 120:
		input.at(index) = 117;
		break;
	case 121:
		input.at(index) = 120;
		break;
	case 122:
		input.at(index) = 120;
		break;
	case 123:
		input.at(index) = 117;
		break;
	case 124:
		input.at(index) = 123;
		break;
	case 125:
		input.at(index) = 123;
		break;
	case 126:
		input.at(index) = 108;
		break;
	case 127:
		input.at(index) = 126;
		break;
	case 128:
		input.at(index) = 126;
		break;
	case 129:
		input.at(index) = 126;
		break;
	case 130:
		input.at(index) = 129;
		break;
	case 131:
		input.at(index) = 129;
		break;
	case 132:
		input.at(index) = 126;
		break;
	case 133:
		input.at(index) = 132;
		break;
	case 134:
		input.at(index) = 132;
		break;
	case 135:
		input.at(index) = 81;
		break;
	case 136:
		input.at(index) = 135;
		break;
	case 137:
		input.at(index) = 135;
		break;
	case 138:
		input.at(index) = 135;
		break;
	case 139:
		input.at(index) = 138;
		break;
	case 140:
		input.at(index) = 138;
		break;
	case 141:
		input.at(index) = 135;
		break;
	case 142:
		input.at(index) = 141;
		break;
	case 143:
		input.at(index) = 141;
		break;
	case 144:
		input.at(index) = 135;
		break;
	case 145:
		input.at(index) = 144;
		break;
	case 146:
		input.at(index) = 144;
		break;
	case 147:
		input.at(index) = 144;
		break;
	case 148:
		input.at(index) = 147;
		break;
	case 149:
		input.at(index) = 147;
		break;
	case 150:
		input.at(index) = 144;
		break;
	case 151:
		input.at(index) = 150;
		break;
	case 152:
		input.at(index) = 150;
		break;
	case 153:
		input.at(index) = 135;
		break;
	case 154:
		input.at(index) = 153;
		break;
	case 155:
		input.at(index) = 153;
		break;
	case 156:
		input.at(index) = 153;
		break;
	case 157:
		input.at(index) = 156;
		break;
	case 158:
		input.at(index) = 156;
		break;
	case 159:
		input.at(index) = 153;
		break;
	case 160:
		input.at(index) = 159;
		break;
	case 161:
		input.at(index) = 159;
		break;
	case 162:
		input.at(index) = 0;
		break;
	case 163:
		input.at(index) = 162;
		break;
	case 164:
		input.at(index) = 162;
		break;
	case 165:
		input.at(index) = 162;
		break;
	case 166:
		input.at(index) = 165;
		break;
	case 167:
		input.at(index) = 165;
		break;
	case 168:
		input.at(index) = 162;
		break;
	case 169:
		input.at(index) = 168;
		break;
	case 170:
		input.at(index) = 168;
		break;
	case 171:
		input.at(index) = 162;
		break;
	case 172:
		input.at(index) = 171;
		break;
	case 173:
		input.at(index) = 171;
		break;
	case 174:
		input.at(index) = 171;
		break;
	case 175:
		input.at(index) = 174;
		break;
	case 176:
		input.at(index) = 174;
		break;
	case 177:
		input.at(index) = 171;
		break;
	case 178:
		input.at(index) = 177;
		break;
	case 179:
		input.at(index) = 177;
		break;
	case 180:
		input.at(index) = 162;
		break;
	case 181:
		input.at(index) = 180;
		break;
	case 182:
		input.at(index) = 180;
		break;
	case 183:
		input.at(index) = 180;
		break;
	case 184:
		input.at(index) = 183;
		break;
	case 185:
		input.at(index) = 183;
		break;
	case 186:
		input.at(index) = 180;
		break;
	case 187:
		input.at(index) = 186;
		break;
	case 188:
		input.at(index) = 186;
		break;
	case 189:
		input.at(index) = 162;
		break;
	case 190:
		input.at(index) = 189;
		break;
	case 191:
		input.at(index) = 189;
		break;
	case 192:
		input.at(index) = 189;
		break;
	case 193:
		input.at(index) = 192;
		break;
	case 194:
		input.at(index) = 192;
		break;
	case 195:
		input.at(index) = 189;
		break;
	case 196:
		input.at(index) = 195;
		break;
	case 197:
		input.at(index) = 195;
		break;
	case 198:
		input.at(index) = 189;
		break;
	case 199:
		input.at(index) = 198;
		break;
	case 200:
		input.at(index) = 198;
		break;
	case 201:
		input.at(index) = 198;
		break;
	case 202:
		input.at(index) = 201;
		break;
	case 203:
		input.at(index) = 201;
		break;
	case 204:
		input.at(index) = 198;
		break;
	case 205:
		input.at(index) = 204;
		break;
	case 206:
		input.at(index) = 204;
		break;
	case 207:
		input.at(index) = 189;
		break;
	case 208:
		input.at(index) = 207;
		break;
	case 209:
		input.at(index) = 207;
		break;
	case 210:
		input.at(index) = 207;
		break;
	case 211:
		input.at(index) = 210;
		break;
	case 212:
		input.at(index) = 210;
		break;
	case 213:
		input.at(index) = 207;
		break;
	case 214:
		input.at(index) = 213;
		break;
	case 215:
		input.at(index) = 213;
		break;
	case 216:
		input.at(index) = 162;
		break;
	case 217:
		input.at(index) = 216;
		break;
	case 218:
		input.at(index) = 216;
		break;
	case 219:
		input.at(index) = 216;
		break;
	case 220:
		input.at(index) = 219;
		break;
	case 221:
		input.at(index) = 219;
		break;
	case 222:
		input.at(index) = 216;
		break;
	case 223:
		input.at(index) = 222;
		break;
	case 224:
		input.at(index) = 222;
		break;
	case 225:
		input.at(index) = 216;
		break;
	case 226:
		input.at(index) = 225;
		break;
	case 227:
		input.at(index) = 225;
		break;
	case 228:
		input.at(index) = 225;
		break;
	case 229:
		input.at(index) = 228;
		break;
	case 230:
		input.at(index) = 228;
		break;
	case 231:
		input.at(index) = 225;
		break;
	case 232:
		input.at(index) = 231;
		break;
	case 233:
		input.at(index) = 231;
		break;
	case 234:
		input.at(index) = 216;
		break;
	case 235:
		input.at(index) = 234;
		break;
	case 236:
		input.at(index) = 234;
		break;
	case 237:
		input.at(index) = 234;
		break;
	case 238:
		input.at(index) = 237;
		break;
	case 239:
		input.at(index) = 237;
		break;
	case 240:
		input.at(index) = 234;
		break;
	case 241:
		input.at(index) = 240;
		break;
	case 242:
		input.at(index) = 240;
		break;
	}
   return;
}

//since only version is flat, this is just a pointer to the flat version.
void Base243TrieRelation::popOneFlat(vector<int>& input, int& index) {
   this->popOne(input, index);
}

//val = 0 for left, 1 for right.
void Base243TrieRelation::setNextFlat(vector<int>& input, int val, int& index) {
      switch(input.at(index)) {
	case 0:
		input.at(index) += (val+1) * 81;
		break;
	case 3:
		input.at(index) += (val+1) * 1;
		break;
	case 6:
		input.at(index) += (val+1) * 1;
		break;
	case 9:
		input.at(index) += (val+1) * 3;
		break;
	case 12:
		input.at(index) += (val+1) * 1;
		break;
	case 15:
		input.at(index) += (val+1) * 1;
		break;
	case 18:
		input.at(index) += (val+1) * 3;
		break;
	case 21:
		input.at(index) += (val+1) * 1;
		break;
	case 24:
		input.at(index) += (val+1) * 1;
		break;
	case 27:
		input.at(index) += (val+1) * 9;
		break;
	case 30:
		input.at(index) += (val+1) * 1;
		break;
	case 33:
		input.at(index) += (val+1) * 1;
		break;
	case 36:
		input.at(index) += (val+1) * 3;
		break;
	case 39:
		input.at(index) += (val+1) * 1;
		break;
	case 42:
		input.at(index) += (val+1) * 1;
		break;
	case 45:
		input.at(index) += (val+1) * 3;
		break;
	case 48:
		input.at(index) += (val+1) * 1;
		break;
	case 51:
		input.at(index) += (val+1) * 1;
		break;
	case 54:
		input.at(index) += (val+1) * 9;
		break;
	case 57:
		input.at(index) += (val+1) * 1;
		break;
	case 60:
		input.at(index) += (val+1) * 1;
		break;
	case 63:
		input.at(index) += (val+1) * 3;
		break;
	case 66:
		input.at(index) += (val+1) * 1;
		break;
	case 69:
		input.at(index) += (val+1) * 1;
		break;
	case 72:
		input.at(index) += (val+1) * 3;
		break;
	case 75:
		input.at(index) += (val+1) * 1;
		break;
	case 78:
		input.at(index) += (val+1) * 1;
		break;
	case 81:
		input.at(index) += (val+1) * 27;
		break;
	case 84:
		input.at(index) += (val+1) * 1;
		break;
	case 87:
		input.at(index) += (val+1) * 1;
		break;
	case 90:
		input.at(index) += (val+1) * 3;
		break;
	case 93:
		input.at(index) += (val+1) * 1;
		break;
	case 96:
		input.at(index) += (val+1) * 1;
		break;
	case 99:
		input.at(index) += (val+1) * 3;
		break;
	case 102:
		input.at(index) += (val+1) * 1;
		break;
	case 105:
		input.at(index) += (val+1) * 1;
		break;
	case 108:
		input.at(index) += (val+1) * 9;
		break;
	case 111:
		input.at(index) += (val+1) * 1;
		break;
	case 114:
		input.at(index) += (val+1) * 1;
		break;
	case 117:
		input.at(index) += (val+1) * 3;
		break;
	case 120:
		input.at(index) += (val+1) * 1;
		break;
	case 123:
		input.at(index) += (val+1) * 1;
		break;
	case 126:
		input.at(index) += (val+1) * 3;
		break;
	case 129:
		input.at(index) += (val+1) * 1;
		break;
	case 132:
		input.at(index) += (val+1) * 1;
		break;
	case 135:
		input.at(index) += (val+1) * 9;
		break;
	case 138:
		input.at(index) += (val+1) * 1;
		break;
	case 141:
		input.at(index) += (val+1) * 1;
		break;
	case 144:
		input.at(index) += (val+1) * 3;
		break;
	case 147:
		input.at(index) += (val+1) * 1;
		break;
	case 150:
		input.at(index) += (val+1) * 1;
		break;
	case 153:
		input.at(index) += (val+1) * 3;
		break;
	case 156:
		input.at(index) += (val+1) * 1;
		break;
	case 159:
		input.at(index) += (val+1) * 1;
		break;
	case 162:
		input.at(index) += (val+1) * 27;
		break;
	case 165:
		input.at(index) += (val+1) * 1;
		break;
	case 168:
		input.at(index) += (val+1) * 1;
		break;
	case 171:
		input.at(index) += (val+1) * 3;
		break;
	case 174:
		input.at(index) += (val+1) * 1;
		break;
	case 177:
		input.at(index) += (val+1) * 1;
		break;
	case 180:
		input.at(index) += (val+1) * 3;
		break;
	case 183:
		input.at(index) += (val+1) * 1;
		break;
	case 186:
		input.at(index) += (val+1) * 1;
		break;
	case 189:
		input.at(index) += (val+1) * 9;
		break;
	case 192:
		input.at(index) += (val+1) * 1;
		break;
	case 195:
		input.at(index) += (val+1) * 1;
		break;
	case 198:
		input.at(index) += (val+1) * 3;
		break;
	case 201:
		input.at(index) += (val+1) * 1;
		break;
	case 204:
		input.at(index) += (val+1) * 1;
		break;
	case 207:
		input.at(index) += (val+1) * 3;
		break;
	case 210:
		input.at(index) += (val+1) * 1;
		break;
	case 213:
		input.at(index) += (val+1) * 1;
		break;
	case 216:
		input.at(index) += (val+1) * 9;
		break;
	case 219:
		input.at(index) += (val+1) * 1;
		break;
	case 222:
		input.at(index) += (val+1) * 1;
		break;
	case 225:
		input.at(index) += (val+1) * 3;
		break;
	case 228:
		input.at(index) += (val+1) * 1;
		break;
	case 231:
		input.at(index) += (val+1) * 1;
		break;
	case 234:
		input.at(index) += (val+1) * 3;
		break;
	case 237:
		input.at(index) += (val+1) * 1;
		break;
	case 240:
		input.at(index) += (val+1) * 1;
		break;
	default:
      //this should only trigger when input.at(index) is full.
      //also, this scares me.
      input.at(++index) = val + 2;
      break;
	}
}

//compat reasons again.
void Base243TrieRelation::setNext(vector<int>& input, int val, int& index) {
   this->setNextFlat(input, val, index);
}

//determines the amount of backtraces @output allows on @input.
//output must fully contain input.
//TODO: flatten.
int Base243TrieRelation::performShrinkage(vector<int>& input, 
                                       vector<int>& output,
                                       int& index)
{
   
   // std::cout << "Start is: \n";
   // for ( int i = 0; i < input.size(); i++) {
      // std::cout << input.at(i) << ", ";
   // }
   // std::cout << "\n with: ";
   // for (int i = 0; i < output.size(); i++) {
      // std::cout << output.at(i) << ", ";
   // }
   // std::cout << "\n";
  // std::cout << "Starting..." << std::endl;
   for (; index >= 0; index--) {
      
      if (output.at(index) <= B243_ALL_LAMBDA) {
         input.at(index) = B243_ALL_LAMBDA;
         continue;
      }
      
      layerSkipFlat(input.at(index), output.at(index), input.at(index));
      if (input.at(index) <= _NULLED) {
         continue;
      }
      
      //non-null, so exit
      // if (index + 1 < output.size()) {
         // output.at(index + 1) = -1;
      // }
      break;
   }
 //  std::cout << "Returning with index " << index << std::endl;
      //Old version
      // //TODO: This can be done much faster
      // //Less than is because of CNF_KILL
      // if (output.at(index) <= B243_ALL_LAMBDA) {
         // input.at(index) = B243_ALL_LAMBDA;
         // continue;
      // }
      // /*wrapped up in above now.
      // else if (output.at(index) == B243_ALL_LAMBDA) {
         // //input.at(index) = output.at(index) = 1; //for compat with CNFInt functions TODO: DOES NOT DOING THIS BREAK ANYTHING?!
         // continue;
      // }*/
      // //need to go from 5 because it still has five values regardless.
      // int input_HSB = 5; //highestSetBit(input.at(index));
      // //figure out how low we can take the input
      // int output_HSB = highestSetBit(output.at(index));
      // int divCount = 0;

      // //bring it that low
      // while(input_HSB > output_HSB) {
         // input.at(index) /= 3;
         // input_HSB--;
         // divCount++;
      // }
      // for (int i = 0; i < divCount; i++) {
         // input.at(index) *= 3;
      // }
      // break;
   // }
   // std::cout << "Result is: \n";
   // for ( int i = 0; i < input.size(); i++) {
      // std::cout << input.at(i) << ", ";
   // }
   // std::cout << "\n";
   return 1;
}

//a lot (not all) duplicated because a bunch of hardcoded 4's are now hardcoded 5's...
void Base243TrieRelation::insertData(vector<vector<int> >& input, int maxNodeID) {
   _LAYERS = (maxNodeID + 4) / 5;
   std::string treeType = gvars.getStr(DB_TYPE);
   std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   delete tree;
   if (treeType == "bigor") {
      tree = new IATDummy(new BigOr243Trie(_LAYERS, orderer->getExtra()));
   }
   else {
      tree = new IATDummy(new Base243InnerGIAT());
   }
   
   _NULLED = B243_ALL_LAMBDA;
   finalDegree = maxNodeID % 5;
   vector<int> insertionVector;
   insertionVector.resize(maxNodeID + 1, B243_CNFLAMBDA);
   vector<int> iv2;
   iv2.resize(_LAYERS + 1);
   vector<int> temp;
   temp.resize(iv2.size(), 1);
   
   std::cout << "Packing " << insertionVector.size() - 1 << " logical layers into " 
             << iv2.size() - 1<< " physical ones\n";
   //insert all boxes into the tree
   //TODO: improve time
   std::cout << "Total terms: " << input.size() << std::endl;
   
   tree->setLayers(_LAYERS);

   tree->setModLayers(0);

   for (int i = 0; i < input.size(); i++) {
      int val;
      int maxVal = 0;
     // std::cout << "current: "; printBox(input.at(i));
      for (int j=0; j < input.at(i).size(); j++) {
         val = input.at(i).at(j);
         if (maxVal < std::abs(val)) {
            maxVal = std::abs(val);
         }
         if (val < 0) {
            insertionVector.at(std::abs(val) - 1) = B243_CNFNEG; 
         } else {
            insertionVector.at(val - 1) = B243_CNFPOS; 
         }
      }
      
      insertionVector.at(std::abs(maxVal)) = _CNFINT_KILL;
      
      int j;
      for (j = 0; j < std::abs(maxVal); j+=5) {
         int sum = 0;
         int endFlag = 0;
         for (int k = j; k < j + 5; k++) {
            if (insertionVector.at(k)==_CNFINT_KILL) {
               endFlag = 1;
               while (k < j + 5) {
                  k++;
                  sum*=3;
               }
               break;
            }
            sum = sum * 3 + insertionVector.at(k);
         }
         iv2.at(j/5) = sum;
         if (endFlag) {
            j+=5;
            break;
         }
      }
      iv2.at(j/5) = _CNFINT_KILL; //= -1; 
  // std::cout << "About to insert "; printBox(iv2); 
      tree->insertShort(iv2, input.at(i));
  // std::cout << "Insertion complete." << std::endl;
    //  insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
  //    std::cout << std::endl; 
  vector<int> output;
  output.resize(iv2.size(), 0);
     if (!tree->contains(iv2, output)) {
         std::cout << "ERROR: input not present!" << std::endl;
         std::cout << "At loop " << i << ", IV is: ";
         for (int i = 0; i < iv2.size(); i++) {
            std::cout << iv2.at(i) << ", ";
         }
         std::cout << std::endl;
         string temp;
         std::cin >> temp;
      }
      /*else if (insertionVector.at(0)!=B243_CNFNEG && 
               insertionVector.at(1)!=B243_CNFPOS && 
               insertionVector.at(2)!=B243_CNFNEG && 
               insertionVector.at(3)!=B243_CNFPOS && 
               insertionVector.at(4)!=B243_CNFPOS) 
      {
         std::cout << "Success!" << std::endl;
         std::cout << "IV is: \t\t ";
         for (int z = 0; z < iv2.size(); z++) {
            std::cout << iv2.at(z) << ", ";
         }
         std::cout << "\nwhile output is: ";
         for (int z =0; z < output.size(); z++) {
            std::cout << output.at(z) << ", ";
         }
         std::cout << "\n" << std::endl;
         
         string temps;
         std::cin >> temps;
         
       //  for (int i = 0; i < temp.size(); i++) {
        //    temp.at(i) = 1;
         //}
      }*/
      
      //prepare for next round
      insertionVector.at(std::abs(maxVal)) = B243_CNFLAMBDA;
      for (int j=0; j < input.at(i).size(); j++) {
         insertionVector.at(std::abs(input.at(i).at(j)) - 1) = B243_CNFLAMBDA;
      }
      
      //progress bar-ish
      if (i % 100000 ==0) {
         std::cout << "i: " << i << std::endl;
      }
   }
   
   finalDegree = (5 - finalDegree) % 5;
   
   tree->setModLayers(finalDegree);
}

int B243_outputPopMatrix[5][243] = {
   {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
   {2, 2, 2, 5, 5, 5, 8, 8, 8, 11, 11, 11, 14, 14, 14, 17, 17, 17, 20, 20, 20, 23, 23, 23, 26, 26, 26, 29, 29, 29, 32, 32, 32, 35, 35, 35, 38, 38, 38, 41, 41, 41, 44, 44, 44, 47, 47, 47, 50, 50, 50, 53, 53, 53, 56, 56, 56, 59, 59, 59, 62, 62, 62, 65, 65, 65, 68, 68, 68, 71, 71, 71, 74, 74, 74, 77, 77, 77, 80, 80, 80, 83, 83, 83, 86, 86, 86, 89, 89, 89, 92, 92, 92, 95, 95, 95, 98, 98, 98, 101, 101, 101, 104, 104, 104, 107, 107, 107, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 164, 164, 164, 167, 167, 167, 170, 170, 170, 173, 173, 173, 176, 176, 176, 179, 179, 179, 182, 182, 182, 185, 185, 185, 188, 188, 188, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242},
   {8, 8, 8, 8, 8, 8, 8, 8, 8, 17, 17, 17, 17, 17, 17, 17, 17, 17, 26, 26, 26, 26, 26, 26, 26, 26, 26, 35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 53, 53, 53, 53, 53, 53, 53, 53, 53, 62, 62, 62, 62, 62, 62, 62, 62, 62, 71, 71, 71, 71, 71, 71, 71, 71, 71, 80, 80, 80, 80, 80, 80, 80, 80, 80, 89, 89, 89, 89, 89, 89, 89, 89, 89, 98, 98, 98, 98, 98, 98, 98, 98, 98, 107, 107, 107, 107, 107, 107, 107, 107, 107, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 170, 170, 170, 170, 170, 170, 170, 170, 170, 179, 179, 179, 179, 179, 179, 179, 179, 179, 188, 188, 188, 188, 188, 188, 188, 188, 188, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242},
   {26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242},
   {80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242}
};

//Adjusts the final element(s) from a expanded 5-digit to simulate having fewer
//it does so by replacing the last (5-finalDegree) elements with 2's.
void Base243TrieRelation::outputPop(vector<int>& input, int& index) const {
   //std::cout << "finalDegree is " << finalDegree << std::endl;
   input.at(index) = B243_outputPopMatrix[finalDegree][input.at(index)];
}

//getLambdaCount is kept.
//popAndMerge should be keepable...

unsigned long Base243TrieRelation::performFroggerTricount(
                size_t start,
                size_t end) 
{
   if (start!=0) return 0; //not gonna multithread here ftm.
   std::string treeType = gvars.getStr(CDB_TYPE);
   GenericIntTrie* cdb;
   std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   if (treeType == "bigor") {
      cdb = new BigOr243Trie(_LAYERS);
   }
   else {
      cdb = new Base243InnerGIAT(); 
   }
   unsigned long count = tetris(cdb);
   
   delete cdb;
   return count;
}

void Base243TrieRelation::buildDepthLUT() {
   depthLUT.resize(_LAYERS);
   int i = depthLUT.size() - 1;
   depthLUT.at(i--) = 0;
   if (i >= 0) {
      depthLUT.at(i--) = 5 - finalDegree;
   }
   for (; i >= 0; i--) {
      depthLUT.at(i) = depthLUT.at(i+1) + 5;
   }
}

void Base243TrieRelation::buildPrevWord(vector<int>& prevWord) const {
   prevWord.resize(_LAYERS+1, B243_ALL_LAMBDA); //0-0-0-0-0, i.e. all lambdas
   prevWord.back() = -1;
}

void Base243TrieRelation::resetOutput(vector<int>& output) const {
   for (int i = 0; i < _LAYERS; i++) {
      output.at(i) = B243_ALL_LAMBDA; //=0
   }
}

void Base243TrieRelation::resetOutput(weightedBox& output) const {
   for (int i = 0; i < _LAYERS; i++) {
      output.box.at(i) = B243_ALL_LAMBDA; //=0
   }
   output.weight = 0;
   output.data = NULL;
}

void Base243TrieRelation::initializeInput(vector<int>& input) {
   input.resize(_LAYERS, 121);
}

void Base243TrieRelation::initializeInput(weightedBox& input) const {
   input.box.resize(_LAYERS, 121);
}

//TODO: merge with CNFITR::buildIndexCNF (reuses a lot of code lazily)
void Base243TrieRelation::buildIndexMax(std::vector<clause>& input, 
                                 int maxNodeID,
                                 std::vector<std::pair<int, int> >& counts,
                                 int maxWeight) 
{
   if (maxWeight > 0) {
      mMaxWeight = maxWeight;
   }
   else {
      mMaxWeight = ULONG_MAX;
   }
   
   //TODO: support for preprocessing
   /*
   if (gPreprocess) {
      std::cout << "Preprocessing..." << std::endl;
      Preprocessor p;
      vector<int> removedVars;
      p.preprocess(input, counts, removedVars, maxNodeID); 
      //TODO: handle removedVars
      
      std::cout << "Preprocessing complete; " << removedVars.size() << " vars removed." << std::endl;
   }*/
   
   //need to switch to DNF
   //(i.e. negate every term)
   for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.at(i).values.size(); j++) {
         input.at(i).values.at(j) *= -1;
      }
   }
   
   //Get ordering
   //for the time being, we'll copy over to a vector so the Orderings can deal with it
   //in the future, I dunno.
   vector<vector<int> > tempInput;
   for (int i = 0; i < input.size(); i++) {
      if (input.at(i).weight >= mMaxWeight || mMaxWeight == ULONG_MAX) {
         tempInput.push_back(input.at(i).values);
      }
   }
   cout << "Ordering..." << endl;
   vector<int> mappings(counts.size()); //mappings[i] -> the value to map i to
   mappings = orderer->getOrdering(tempInput, maxNodeID, counts, _LAYER_SIZE);
     std::cout << "Mappings: ";
   for (int i = 0; i < mappings.size(); i++) {
      std::cout << i << ": " << mappings.at(i) << ", ";
   }
   std::cout << std::endl;
   //apply the mapping
   for (int i = 0; i < input.size(); i++) {
      for (int j = 0; j < input.at(i).values.size(); j++) {
         int currVal = input.at(i).values.at(j);
         if (currVal < 0) {
            input.at(i).values.at(j) = -1 * (mappings.at(currVal * -1));
         }
         else {
            input.at(i).values.at(j) = mappings.at(currVal);
         }
      }
   }
   //===Mapping complete!
   std::cout << "Mapping complete!" << std::endl;
   
   //need to sort each sub-vector by absolute value
   for (int i = 0; i < input.size(); i++) {
      std::sort(input.at(i).values.begin(), input.at(i).values.end(), [](int a, int b) {
         return std::abs(a) < std::abs(b);
      });
   }
   
   insertData(input, maxNodeID);
   buildDepthLUT();

   std::cout << "Insertion complete." << std::endl;
   
}

//TODO: merge with non-weighted version
void Base243TrieRelation::insertData(vector<clause>& input, int maxNodeID) {
   
   localCDB.reset(new IATDummy(new Base243InnerGIAT()));
   
   _LAYERS = (maxNodeID + 4) / 5;
   _NULLED = B243_ALL_LAMBDA;
   finalDegree = maxNodeID % 5;
   vector<int> insertionVector;
   insertionVector.resize(maxNodeID + 1, B243_CNFLAMBDA);
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
      int maxVal = 0; //keeps track of end of input string
      for (int j=0; j < input.at(i).values.size(); j++) {
        // std::cout << "CV: " << input.at(i).at(j) << std::endl;
         val = input.at(i).values.at(j);
         if (maxVal < std::abs(val)) {
            maxVal = std::abs(val);
         }
         if (val < 0) {
            insertionVector.at(std::abs(val) - 1) = B243_CNFNEG; 
         } else {
            insertionVector.at(val - 1) = B243_CNFPOS; 
         }
      }
      
      insertionVector.at(std::abs(maxVal)) = _CNFINT_KILL;
      
      int j;
      for (j = 0; j < std::abs(maxVal); j+=5) {
         int sum = 0;
         int endFlag = 0;
         for (int k = j; k < j + 5; k++) {
            if (insertionVector.at(k)==_CNFINT_KILL) {
               endFlag = 1;
               while (k < j + 5) {
                  k++;
                  sum*=3;
               }
               break;
            }
            sum = sum * 3 + insertionVector.at(k);
         }
         iv2.at(j/5) = sum;
         if (endFlag) {
            j+=5;
            break;
         }
      }
      iv2.at(j/5) = _CNFINT_KILL; //= -1; 
 //  std::cout << "About to insert" << std::endl;
      weightedBox tempClause;
      tempClause.box = iv2;
      tempClause.weight = input.at(i).weight;
      tempClause.data = NULL;
      
      if (tempClause.weight >= mMaxWeight) {
         localCDB->insertWeighted(tempClause);
      }
      else {
         tree->insertWeighted(tempClause);
      }
  // std::cout << "Insertion complete." << std::endl;
    //  insertionVector.at(std::abs(val)) = _CNFINT_LAMBDA;
  //    std::cout << std::endl; 
  weightedBox output;
  output.box.resize(iv2.size(), 0);
     // if (!tree->containsWeighted(tempClause, output)) { //TODO: TEST WITH NEW CONTAINS
         // std::cout << "ERROR: input not present!" << std::endl;
         // std::cout << "IV is: ";
         // for (int i = 0; i < iv2.size(); i++) {
            // std::cout << iv2.at(i) << ", ";
         // }
         // std::cout << std::endl;
         // string temp;
         // std::cin >> temp;
      // }
      /*else if (insertionVector.at(0)!=B243_CNFNEG && 
               insertionVector.at(1)!=B243_CNFPOS && 
               insertionVector.at(2)!=B243_CNFNEG && 
               insertionVector.at(3)!=B243_CNFPOS && 
               insertionVector.at(4)!=B243_CNFPOS) 
      {
         std::cout << "Success!" << std::endl;
         std::cout << "IV is: \t\t ";
         for (int z = 0; z < iv2.size(); z++) {
            std::cout << iv2.at(z) << ", ";
         }
         std::cout << "\nwhile output is: ";
         for (int z =0; z < output.size(); z++) {
            std::cout << output.at(z) << ", ";
         }
         std::cout << "\n" << std::endl;
         
         string temps;
         std::cin >> temps;
         
       //  for (int i = 0; i < temp.size(); i++) {
        //    temp.at(i) = 1;
         //}
      }*/
      
      //prepare for next round
      insertionVector.at(std::abs(maxVal)) = B243_CNFLAMBDA;
      for (int j=0; j < input.at(i).values.size(); j++) {
         insertionVector.at(std::abs(input.at(i).values.at(j)) - 1) = B243_CNFLAMBDA;
      }
      
      //progress bar-ish
      if (i % 100000 ==0 && i!=0) {
         std::cout << "i: " << i << std::endl;
      }
   }
   
   finalDegree = (5 - finalDegree) % 5;
   
   tree->setModLayers(finalDegree);
}

//note: not a const operation, since we have to kill old edges in the trie.
unsigned long Base243TrieRelation::performMaxSATCount(
         size_t start, size_t end) 
{
   if (start!=0) return 0; //not gonna multithread here ftm.
   std::string treeType = gvars.getStr(CDB_TYPE);
   // GenericIntTrie* cdb;
   // std::transform(treeType.begin(), treeType.end(), treeType.begin(), ::tolower);
   // if (treeType == "noskips") {
      // cdb = new Base243InnerGIAT();
   // }
   // else {
      // cdb = new Base243InnerGIAT(); 
   // }
   unsigned long count = weightedTetris(localCDB);
   
  // delete cdb;
   return count;
}

unsigned long Base243TrieRelation::weightedTetris(shared_ptr<GenericIntTrie> cdb) {
   int index = 0;
   int rounds = 0;
   
   weightedBox input;
   weightedBox output;
   output.box.resize(_LAYERS, 1); //E cheaper way
   resetOutput(output);

   unsigned long count = 0;
   
   unsigned long long currentWeight = 0;
   std::string initialMax = gvars.getStr(INITIAL_MAX);
   std::transform(initialMax.begin(), initialMax.end(), initialMax.begin(), ::tolower);
   unsigned long long maxWeight;
   if (initialMax == "fromfile") {
      maxWeight = mMaxWeight; 
   }
   else { //infinity
      maxWeight = ULONG_MAX;
   }

   //initialize pastSO1s
   vector<weightedBox > pastSO1s; //<--functions essentially as a hash table
   pastSO1s.resize(_LAYERS * maxDepth);
   for (int i = 0; i < pastSO1s.size(); i++) {
      pastSO1s.at(i).box.resize(_LAYERS, 1);
   }
      
   //set up the input so that it is at the first interesting point
   initializeInput(input);
   input.box.resize(_LAYERS, 2);
   fillZero(input, index);
   string tempString;
   for(;;) {
      rounds++;
      if (rounds % 10000000 == 0) {
         std::cout << "At input " << rounds << ": ";
         printBox(input);
      }
      // std::cout << "Input is: ";
      // printBox(input);
      if (input.box.back() >= shift) {//=== is a unit box
     // std::cout << "About to call contains" << std::endl;
         if (cdb->contains(input.box, output.box)) { //cdb only contains elements greater than current known max solution
   //         totalContains++;
            // std::cout << "Contains!" << std::endl;
            performShrinkage(input.box, output.box, index);
    //        std::cout << "Shrink shrunk." << std::endl;
            popAndMerge(input, output, pastSO1s, cdb, index); //TODO: Figure this out.
    //        std::cout << "Merge popped" << std::endl;
            if (index < 0) break;
            
            resetOutput(output);
        //    std::cout << "Output reset." << std::endl;
            fillZero(input, index);
            continue;
         }
         // std::cout << "Contains gave false." << std::endl;
    /*     std::cout << "Input: " << std::endl;
         for (int i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ", ";
         }
         std::cout << std::endl; */
         vector<weightedBox> allBoxes;
         int maxDepth = getAllContainingBoxesWeighted(input, allBoxes);
         // std::cout << "GACB(b) returned with size " << allBoxes.size()
                   // << std::endl;
         if (allBoxes.size()==0) { //is a perfect solution
            std::cout << "0-cost solution found." << std::endl;
            return 1;
         }
         
         else { //negative witness found
            // std::cout << "About to add" << std::endl;
           /* for (int i = 0; i < allBoxes.size(); i++) {
               std::cout << "Box " << i << ": ";
               for (int j = 0; j < allBoxes.at(i).size(); j++) {
                  std::cout << allBoxes.at(i).at(j) << ", ";
               }
               std::cout << std::endl;
            } */
            
            //TODO: Add variable for this
            //TODO: Handle this in Max-world
            // for (int i = 0; i < allBoxes.size(); i++) {
               // cdb->insertWeighted(allBoxes.at(i));
            // }
            
        //    std::cout << "About to build." << std::endl;
            //TODO: find a better way to build this vector
          //  vector<int> tempBox;
          //  tempBox.resize(_LAYERS, 1);
          //  for (int i = 0; allBoxes.at(0).at(i)!=_CNFINT_KILL; i++) {
          //     tempBox.at(i) = allBoxes.at(0).at(i);
          //  }
            bool flag = true;
            int i;
            for (i = 0; i < allBoxes.size(); i++) {
               currentWeight += allBoxes.at(i).weight;
               if (allBoxes.at(i).weight >= maxWeight) {
                  std::cout << "AllBoxes is of size " << allBoxes.size() << "; we broke at the " << i << "th" << std::endl;
                  cdb->insert(allBoxes.at(i).box);
                  performShrinkage(input.box, allBoxes.at(i).box, index);
                  popAndMerge(input, allBoxes.at(i), pastSO1s, cdb, index); //TODO: see earlier PaM
                  currentWeight = 0;
                  flag = false;
                  break;
               }
               else if (currentWeight >= maxWeight) {
                  break;
               }
            }
            if (flag && currentWeight >= maxWeight) {
               //this can't be the right path. Backtrack based on the one that put us over.
               performShrinkage(input.box, allBoxes.at(i).box, index); 
               popAndMerge(input, allBoxes.at(i), pastSO1s, cdb, index); //TODO: see earlier PaM
               //advanceByOne(input, pastSO1s, index);
               if (index < 0) break;
               fillZero(input, index);
            }
            else if (flag) {
               //We have a new best candidate!
               maxWeight = currentWeight;
               std::cout << "New best candidate found with weight " << currentWeight << std::endl;
               advanceByOne(input, pastSO1s, index);
            }
            currentWeight = 0;
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
   return count;
}

//TODO: actually perform merging
void Base243TrieRelation::popAndMerge(weightedBox& input, weightedBox& output,
                                      vector<weightedBox>& pastS01s,
                                      shared_ptr<GenericIntTrie> cdb,
                                      int& index) 
{
   int direction = 0;
   while(true) {
      // std::cout << "Input pam is: ";
      // printBox(input);
      popOneFlat(input.box, direction, index);
      // std::cout << "Input pam post-pop is: ";
      // printBox(input);
       // std::cout << "Dir=" << direction << std::endl;
      if (direction==0) {
         int indexLower = highestSetBitFlat(input.box.at(index));

         //swapping weighted boxes...
         weightedBox temp = pastS01s.at(index*maxDepth + indexLower);
         pastS01s.at(index*maxDepth + indexLower) = output;
         output = temp;
         
         setNext(input.box, 1, index);
         return;
      }
      else { //dir==1
         //For now, we're ignoring merging, since I keep failing to get it to work...
         
         int indexLower = highestSetBitFlat(input.box.at(index)); 
         if (indexLower < 1) {
            index--;
         }
         continue;
      }
   }
}

void Base243TrieRelation::printBox(weightedBox& input) const {
   for (int i = 0; i < input.box.size(); i++) {
      std::cout << input.box.at(i) << ", ";
   }
   std::cout << std::endl;
}

void Base243TrieRelation::printBox(vector<int>& input) const {
   for (int i = 0; i < input.size(); i++) {
      std::cout << input.at(i) << ", ";
   }
   std::cout << std::endl;
}

//Note: atm, identical to PopAndMerge because it's not merging.
//TODO: merge them?
void Base243TrieRelation::advanceByOne(weightedBox& input,
                                       vector<weightedBox>& pastS01s,
                                       int& index) 
{
   int direction = 0;
   while(true) {
      // std::cout << "Input is: ";
      // printBox(input);
      popOneFlat(input.box, direction, index);
      // std::cout << "Input post-pop is: ";
      // printBox(input);
      // std::string temps;
      // std::cin >> temps;
       // std::cout << "Dir=" << direction << std::endl;
      if (direction==0) {
         int indexLower = highestSetBitFlat(input.box.at(index));
         weightedBox output;
         output = input; //copy
         
         //swapping weighted boxes...
         weightedBox temp = pastS01s.at(index*maxDepth + indexLower);
         pastS01s.at(index*maxDepth + indexLower) = output;
         output = temp;
         
         setNext(input.box, 1, index);
         return;
      }
      else { //dir==1
         //we just keep on popping.
         int indexLower = highestSetBitFlat(input.box.at(index));
         if (indexLower < 1) {
            index--;
         }
         continue;
      }
   }
}


int totalOutput243 = 0;

int Base243TrieRelation::getAllContainingBoxesWeighted(
      weightedBox& input, 
      vector<weightedBox>& output) const 
{
   vector<int> prevWord;

   this->buildPrevWord(prevWord);
   
   int maxDepth = 0;
   tree->getAllContainingBoxesWeighted(input, output, prevWord, maxDepth);
   totalOutput243+=output.size();
   //sort boxes by length, shortest to longest.
   //TODO: switch off of n^2 algo? might not be worth.
   vector<int> stars;
   stars.resize(output.size(), 0);
   if (output.size() > 1) {
      for (int i = 0; i < output.size(); i++) {
         int currStars = 0;
         for (int j = output.at(i).box.size()-1; j >= 0; j--) {
            if (output.at(i).box.at(j) <= 0) {
               currStars++;
            }
            else {//hit a non-star
               stars.at(i) = currStars;
               
               //if ((currStars > stars.at(0)) || (currStars == stars.at(0) && output.at(i).box.at(j) < output.at(0).box.at(j))) {
               for (int k = 0; k < i; k++) {
                  if (currStars > stars.at(k)) {
                     
                     //output.at(0).swap(output.at(i));
                     //swapping weighted boxes...
                     weightedBox temp = output.at(k);
                     output.at(k) = output.at(i);
                     output.at(i) = temp;
                                          
                     break; //k-loop, which leads to breaking j-loop and continuing i-loop
                  }
               }
               break; //j-loop; i.e., continue i-loop
            }
         }
      }
   } else {
      return maxDepth; 
   }
   // std::cout << "gacbw output: " << std::endl;
   // for (int i = 0; i < output.size(); i++) {
      // printBox(output.at(i));
   // }
   // string temp;
   // std::cin >> temp;
   
   
   return 0;
  
   
//  std::cout << "TO so far: " << totalOutput243 << std::endl << std::endl;
   
}

//goes from i=start, i < end
int Base243TrieRelation::countLambdas(
   vector<int>& input, int start, int end) const
{
   int output = 0;
   for (int i = start; i < end; i++) {
      switch(input[i]) {
   case(-1):
      output += 5;
      break;
   case(0):
		output += 5;
		break;
	 case(1):
		output += 4;
		break;
	 case(2):
		output += 4;
		break;
	 case(3):
		output += 4;
		break;
	 case(4):
		output += 3;
		break;
	 case(5):
		output += 3;
		break;
	 case(6):
		output += 4;
		break;
	 case(7):
		output += 3;
		break;
	 case(8):
		output += 3;
		break;
	 case(9):
		output += 4;
		break;
	 case(10):
		output += 3;
		break;
	 case(11):
		output += 3;
		break;
	 case(12):
		output += 3;
		break;
	 case(13):
		output += 2;
		break;
	 case(14):
		output += 2;
		break;
	 case(15):
		output += 3;
		break;
	 case(16):
		output += 2;
		break;
	 case(17):
		output += 2;
		break;
	 case(18):
		output += 4;
		break;
	 case(19):
		output += 3;
		break;
	 case(20):
		output += 3;
		break;
	 case(21):
		output += 3;
		break;
	 case(22):
		output += 2;
		break;
	 case(23):
		output += 2;
		break;
	 case(24):
		output += 3;
		break;
	 case(25):
		output += 2;
		break;
	 case(26):
		output += 2;
		break;
	 case(27):
		output += 4;
		break;
	 case(28):
		output += 3;
		break;
	 case(29):
		output += 3;
		break;
	 case(30):
		output += 3;
		break;
	 case(31):
		output += 2;
		break;
	 case(32):
		output += 2;
		break;
	 case(33):
		output += 3;
		break;
	 case(34):
		output += 2;
		break;
	 case(35):
		output += 2;
		break;
	 case(36):
		output += 3;
		break;
	 case(37):
		output += 2;
		break;
	 case(38):
		output += 2;
		break;
	 case(39):
		output += 2;
		break;
	 case(40):
		output += 1;
		break;
	 case(41):
		output += 1;
		break;
	 case(42):
		output += 2;
		break;
	 case(43):
		output += 1;
		break;
	 case(44):
		output += 1;
		break;
	 case(45):
		output += 3;
		break;
	 case(46):
		output += 2;
		break;
	 case(47):
		output += 2;
		break;
	 case(48):
		output += 2;
		break;
	 case(49):
		output += 1;
		break;
	 case(50):
		output += 1;
		break;
	 case(51):
		output += 2;
		break;
	 case(52):
		output += 1;
		break;
	 case(53):
		output += 1;
		break;
	 case(54):
		output += 4;
		break;
	 case(55):
		output += 3;
		break;
	 case(56):
		output += 3;
		break;
	 case(57):
		output += 3;
		break;
	 case(58):
		output += 2;
		break;
	 case(59):
		output += 2;
		break;
	 case(60):
		output += 3;
		break;
	 case(61):
		output += 2;
		break;
	 case(62):
		output += 2;
		break;
	 case(63):
		output += 3;
		break;
	 case(64):
		output += 2;
		break;
	 case(65):
		output += 2;
		break;
	 case(66):
		output += 2;
		break;
	 case(67):
		output += 1;
		break;
	 case(68):
		output += 1;
		break;
	 case(69):
		output += 2;
		break;
	 case(70):
		output += 1;
		break;
	 case(71):
		output += 1;
		break;
	 case(72):
		output += 3;
		break;
	 case(73):
		output += 2;
		break;
	 case(74):
		output += 2;
		break;
	 case(75):
		output += 2;
		break;
	 case(76):
		output += 1;
		break;
	 case(77):
		output += 1;
		break;
	 case(78):
		output += 2;
		break;
	 case(79):
		output += 1;
		break;
	 case(80):
		output += 1;
		break;
	 case(81):
		output += 4;
		break;
	 case(82):
		output += 3;
		break;
	 case(83):
		output += 3;
		break;
	 case(84):
		output += 3;
		break;
	 case(85):
		output += 2;
		break;
	 case(86):
		output += 2;
		break;
	 case(87):
		output += 3;
		break;
	 case(88):
		output += 2;
		break;
	 case(89):
		output += 2;
		break;
	 case(90):
		output += 3;
		break;
	 case(91):
		output += 2;
		break;
	 case(92):
		output += 2;
		break;
	 case(93):
		output += 2;
		break;
	 case(94):
		output += 1;
		break;
	 case(95):
		output += 1;
		break;
	 case(96):
		output += 2;
		break;
	 case(97):
		output += 1;
		break;
	 case(98):
		output += 1;
		break;
	 case(99):
		output += 3;
		break;
	 case(100):
		output += 2;
		break;
	 case(101):
		output += 2;
		break;
	 case(102):
		output += 2;
		break;
	 case(103):
		output += 1;
		break;
	 case(104):
		output += 1;
		break;
	 case(105):
		output += 2;
		break;
	 case(106):
		output += 1;
		break;
	 case(107):
		output += 1;
		break;
	 case(108):
		output += 3;
		break;
	 case(109):
		output += 2;
		break;
	 case(110):
		output += 2;
		break;
	 case(111):
		output += 2;
		break;
	 case(112):
		output += 1;
		break;
	 case(113):
		output += 1;
		break;
	 case(114):
		output += 2;
		break;
	 case(115):
		output += 1;
		break;
	 case(116):
		output += 1;
		break;
	 case(117):
		output += 2;
		break;
	 case(118):
		output += 1;
		break;
	 case(119):
		output += 1;
		break;
	 case(120):
		output += 1;
		break;
	 case(121):
		output += 0;
		break;
	 case(122):
		output += 0;
		break;
	 case(123):
		output += 1;
		break;
	 case(124):
		output += 0;
		break;
	 case(125):
		output += 0;
		break;
	 case(126):
		output += 2;
		break;
	 case(127):
		output += 1;
		break;
	 case(128):
		output += 1;
		break;
	 case(129):
		output += 1;
		break;
	 case(130):
		output += 0;
		break;
	 case(131):
		output += 0;
		break;
	 case(132):
		output += 1;
		break;
	 case(133):
		output += 0;
		break;
	 case(134):
		output += 0;
		break;
	 case(135):
		output += 3;
		break;
	 case(136):
		output += 2;
		break;
	 case(137):
		output += 2;
		break;
	 case(138):
		output += 2;
		break;
	 case(139):
		output += 1;
		break;
	 case(140):
		output += 1;
		break;
	 case(141):
		output += 2;
		break;
	 case(142):
		output += 1;
		break;
	 case(143):
		output += 1;
		break;
	 case(144):
		output += 2;
		break;
	 case(145):
		output += 1;
		break;
	 case(146):
		output += 1;
		break;
	 case(147):
		output += 1;
		break;
	 case(148):
		output += 0;
		break;
	 case(149):
		output += 0;
		break;
	 case(150):
		output += 1;
		break;
	 case(151):
		output += 0;
		break;
	 case(152):
		output += 0;
		break;
	 case(153):
		output += 2;
		break;
	 case(154):
		output += 1;
		break;
	 case(155):
		output += 1;
		break;
	 case(156):
		output += 1;
		break;
	 case(157):
		output += 0;
		break;
	 case(158):
		output += 0;
		break;
	 case(159):
		output += 1;
		break;
	 case(160):
		output += 0;
		break;
	 case(161):
		output += 0;
		break;
	 case(162):
		output += 4;
		break;
	 case(163):
		output += 3;
		break;
	 case(164):
		output += 3;
		break;
	 case(165):
		output += 3;
		break;
	 case(166):
		output += 2;
		break;
	 case(167):
		output += 2;
		break;
	 case(168):
		output += 3;
		break;
	 case(169):
		output += 2;
		break;
	 case(170):
		output += 2;
		break;
	 case(171):
		output += 3;
		break;
	 case(172):
		output += 2;
		break;
	 case(173):
		output += 2;
		break;
	 case(174):
		output += 2;
		break;
	 case(175):
		output += 1;
		break;
	 case(176):
		output += 1;
		break;
	 case(177):
		output += 2;
		break;
	 case(178):
		output += 1;
		break;
	 case(179):
		output += 1;
		break;
	 case(180):
		output += 3;
		break;
	 case(181):
		output += 2;
		break;
	 case(182):
		output += 2;
		break;
	 case(183):
		output += 2;
		break;
	 case(184):
		output += 1;
		break;
	 case(185):
		output += 1;
		break;
	 case(186):
		output += 2;
		break;
	 case(187):
		output += 1;
		break;
	 case(188):
		output += 1;
		break;
	 case(189):
		output += 3;
		break;
	 case(190):
		output += 2;
		break;
	 case(191):
		output += 2;
		break;
	 case(192):
		output += 2;
		break;
	 case(193):
		output += 1;
		break;
	 case(194):
		output += 1;
		break;
	 case(195):
		output += 2;
		break;
	 case(196):
		output += 1;
		break;
	 case(197):
		output += 1;
		break;
	 case(198):
		output += 2;
		break;
	 case(199):
		output += 1;
		break;         
   case(200):
		output += 1;
		break;
	 case(201):
		output += 1;
		break;
	 case(202):
		output += 0;
		break;
	 case(203):
		output += 0;
		break;
	 case(204):
		output += 1;
		break;
	 case(205):
		output += 0;
		break;
	 case(206):
		output += 0;
		break;
	 case(207):
		output += 2;
		break;
	 case(208):
		output += 1;
		break;
	 case(209):
		output += 1;
		break;
	 case(210):
		output += 1;
		break;
	 case(211):
		output += 0;
		break;
	 case(212):
		output += 0;
		break;
	 case(213):
		output += 1;
		break;
	 case(214):
		output += 0;
		break;
	 case(215):
		output += 0;
		break;
	 case(216):
		output += 3;
		break;
	 case(217):
		output += 2;
		break;
	 case(218):
		output += 2;
		break;
	 case(219):
		output += 2;
		break;
	 case(220):
		output += 1;
		break;
	 case(221):
		output += 1;
		break;
	 case(222):
		output += 2;
		break;
	 case(223):
		output += 1;
		break;
	 case(224):
		output += 1;
		break;
	 case(225):
		output += 2;
		break;
	 case(226):
		output += 1;
		break;
	 case(227):
		output += 1;
		break;
	 case(228):
		output += 1;
		break;
	 case(229):
		output += 0;
		break;
	 case(230):
		output += 0;
		break;
	 case(231):
		output += 1;
		break;
	 case(232):
		output += 0;
		break;
	 case(233):
		output += 0;
		break;
	 case(234):
		output += 2;
		break;
	 case(235):
		output += 1;
		break;
	 case(236):
		output += 1;
		break;
	 case(237):
		output += 1;
		break;
	 case(238):
		output += 0;
		break;
	 case(239):
		output += 0;
		break;
	 case(240):
		output += 1;
		break;
	 case(241):
		output += 0;
		break;
	 case(242):
		output += 0;
		break;
	 default:
      std::cout << "ERROR!" << std::endl;
		output += 3;
		break;
   }
   }
   return output;
}

void Base243TrieRelation::fixMaxDepth(int& maxDepth) const {
   //do nothing
}

//only difference from CNFIntTrieRelatoin's version is singleton handling code. Could sep out...
int Base243TrieRelation::getAllContainingBoxesB(
      vector<int>& input, 
      vector<vector<int> >& output) const 
{
   vector<int> prevWord;

   this->buildPrevWord(prevWord);
   
   int maxDepth = 0;
   tree->getAllContainingBoxesB(input, output, prevWord, maxDepth);
   fixMaxDepth(maxDepth);
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
      int sourceLayer = -1;
      vector<int>* candidate;
      int partialLambda;
      if (output.size() == 0 && tree->getSingletonData(sourceLayer, candidate, partialLambda))
      {  
         //ALT PATH FOR LOCKS
         //Handled by detecting a NULL candidate
         if (candidate == NULL) {
           // std::cout << "\nThing detected!" << std::endl;
            int fixedCount = partialLambda; //renamed for simplicity
            //STEP ONE-TWO: Increment count by 2^(lambdas - fixedCount)
          //  std::cout << "DepthLUT value: " << depthLUT.at(sourceLayer - 1);
            //std::cout << " and fixedCount: " << fixedCount << std::endl;
            unsigned long potentialIncrementValue = 1ull << (depthLUT.at(sourceLayer - 1) - fixedCount);
            incrementCountBy(potentialIncrementValue);
           // std::cout << "Incremented by " << potentialIncrementValue << std::endl;
            
            //TODO: Figure out better way to do this.
            //STEP THREE: Insert megabox
            //this->buildPrevWord(prevWord);
            // for (int i = 0; i < sourceLayer; i++) {
               // prevWord.at(i) = input.at(i);
            // }
            // prevWord.at(sourceLayer) = -1;
            // prevWord.back() = -2;
           // printBox(prevWord);
            output.push_back(prevWord);
            //std::cout << "Inputting "; printBox(prevWord);
            
            return sourceLayer; //is the actual maxDepth, hopefully
         }
         
         //STEP ONE: Count the lambdas 
         //we do need to know the --exact-- number of lambdas, not 4-sets
         //I think I can do the count starting from GSD+1? doing it from equal is going to be problematic...
         //sourceLayer++; //I'm incrementing in trie instead!
         int lambdaCount = countLambdas(
               *candidate,
               sourceLayer, 
               input.size());
         lambdaCount += partialLambda;

         //STEP TWO: Increment count by 2^(lambdaCount)
         unsigned long nonIncrementValue = 1ull << (lambdaCount - finalDegree);
         unsigned long potentialIncrementValue = 1ull << (depthLUT.at(sourceLayer-1) + partialLambda);
         incrementCountBy(potentialIncrementValue - nonIncrementValue);

         //STEP THREE: Insert megabox
         for (int i = 0; i < sourceLayer; i++) {
            prevWord.at(i) = input.at(i);
         }
         int temp = sourceLayer - 1;
         for (; partialLambda > 0; partialLambda--) {
            popOneConst(prevWord, temp);
         }
            
         prevWord.at(sourceLayer) = -1;
         output.push_back(prevWord);
         
         maxDepth = sourceLayer; //unnec?
      }
      return maxDepth; 
   }
   return 0;
   
}

void Base243TrieRelation::unsafeBuild(vector<vector<int> >& input, int maxNodeID) {
   //need to sort each sub-vector by absolute value
   for (int i = 0; i < input.size(); i++) {
      std::sort(input.at(i).begin(), input.at(i).end(), [](int a, int b) {
         return std::abs(a) < std::abs(b);
      });
   }
   
   insertData(input, maxNodeID);
   buildDepthLUT();
}

Base243TrieRelation::~Base243TrieRelation() {
   //do nothing
}