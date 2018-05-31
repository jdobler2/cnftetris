//Base243TrieRelation_Tables.cpp
#include "Base243TrieRelation.h"
//#include "SIMD_InnerGIAT.h"
#include "BigOr243Trie.h"

//As below, we're just precalculating lots of stuff
void Base243TrieRelation::layerSkipFlat(
   const int& input1,
   const int& input2,
   int& output) const
{
   	switch(input1) {
	case 0:
		switch(input2) {
		case 0:
			output = 0;
			break;
		}
		break;
	case 1:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 1:
			output = 1;
			break;
		}
		break;
	case 2:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 2:
			output = 2;
			break;
		}
		break;
	case 3:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 3:
			output = 3;
			break;
		}
		break;
	case 4:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 3:
			output = 3;
			break;
		case 1:
			output = 4;
			break;
		case 4:
			output = 4;
			break;
		}
		break;
	case 5:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 3:
			output = 3;
			break;
		case 2:
			output = 5;
			break;
		case 5:
			output = 5;
			break;
		}
		break;
	case 6:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 6:
			output = 6;
			break;
		}
		break;
	case 7:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 6:
			output = 6;
			break;
		case 1:
			output = 7;
			break;
		case 7:
			output = 7;
			break;
		}
		break;
	case 8:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 6:
			output = 6;
			break;
		case 2:
			output = 8;
			break;
		case 8:
			output = 8;
			break;
		}
		break;
	case 9:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		}
		break;
	case 10:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 1:
			output = 10;
			break;
		case 10:
			output = 10;
			break;
		}
		break;
	case 11:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 2:
			output = 11;
			break;
		case 11:
			output = 11;
			break;
		}
		break;
	case 12:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 3:
			output = 12;
			break;
		case 12:
			output = 12;
			break;
		}
		break;
	case 13:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 3:
			output = 12;
			break;
		case 12:
			output = 12;
			break;
		case 1:
			output = 13;
			break;
		case 10:
			output = 13;
			break;
		case 4:
			output = 13;
			break;
		case 13:
			output = 13;
			break;
		}
		break;
	case 14:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 3:
			output = 12;
			break;
		case 12:
			output = 12;
			break;
		case 2:
			output = 14;
			break;
		case 11:
			output = 14;
			break;
		case 5:
			output = 14;
			break;
		case 14:
			output = 14;
			break;
		}
		break;
	case 15:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 6:
			output = 15;
			break;
		case 15:
			output = 15;
			break;
		}
		break;
	case 16:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 6:
			output = 15;
			break;
		case 15:
			output = 15;
			break;
		case 1:
			output = 16;
			break;
		case 10:
			output = 16;
			break;
		case 7:
			output = 16;
			break;
		case 16:
			output = 16;
			break;
		}
		break;
	case 17:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 9:
			output = 9;
			break;
		case 6:
			output = 15;
			break;
		case 15:
			output = 15;
			break;
		case 2:
			output = 17;
			break;
		case 11:
			output = 17;
			break;
		case 8:
			output = 17;
			break;
		case 17:
			output = 17;
			break;
		}
		break;
	case 18:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		}
		break;
	case 19:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 1:
			output = 19;
			break;
		case 19:
			output = 19;
			break;
		}
		break;
	case 20:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 2:
			output = 20;
			break;
		case 20:
			output = 20;
			break;
		}
		break;
	case 21:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 3:
			output = 21;
			break;
		case 21:
			output = 21;
			break;
		}
		break;
	case 22:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 3:
			output = 21;
			break;
		case 21:
			output = 21;
			break;
		case 1:
			output = 22;
			break;
		case 19:
			output = 22;
			break;
		case 4:
			output = 22;
			break;
		case 22:
			output = 22;
			break;
		}
		break;
	case 23:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 3:
			output = 21;
			break;
		case 21:
			output = 21;
			break;
		case 2:
			output = 23;
			break;
		case 20:
			output = 23;
			break;
		case 5:
			output = 23;
			break;
		case 23:
			output = 23;
			break;
		}
		break;
	case 24:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 6:
			output = 24;
			break;
		case 24:
			output = 24;
			break;
		}
		break;
	case 25:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 6:
			output = 24;
			break;
		case 24:
			output = 24;
			break;
		case 1:
			output = 25;
			break;
		case 19:
			output = 25;
			break;
		case 7:
			output = 25;
			break;
		case 25:
			output = 25;
			break;
		}
		break;
	case 26:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 18:
			output = 18;
			break;
		case 6:
			output = 24;
			break;
		case 24:
			output = 24;
			break;
		case 2:
			output = 26;
			break;
		case 20:
			output = 26;
			break;
		case 8:
			output = 26;
			break;
		case 26:
			output = 26;
			break;
		}
		break;
	case 27:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		}
		break;
	case 28:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 1:
			output = 28;
			break;
		case 28:
			output = 28;
			break;
		}
		break;
	case 29:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 2:
			output = 29;
			break;
		case 29:
			output = 29;
			break;
		}
		break;
	case 30:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 3:
			output = 30;
			break;
		case 30:
			output = 30;
			break;
		}
		break;
	case 31:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 3:
			output = 30;
			break;
		case 30:
			output = 30;
			break;
		case 1:
			output = 31;
			break;
		case 28:
			output = 31;
			break;
		case 4:
			output = 31;
			break;
		case 31:
			output = 31;
			break;
		}
		break;
	case 32:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 3:
			output = 30;
			break;
		case 30:
			output = 30;
			break;
		case 2:
			output = 32;
			break;
		case 29:
			output = 32;
			break;
		case 5:
			output = 32;
			break;
		case 32:
			output = 32;
			break;
		}
		break;
	case 33:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 6:
			output = 33;
			break;
		case 33:
			output = 33;
			break;
		}
		break;
	case 34:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 6:
			output = 33;
			break;
		case 33:
			output = 33;
			break;
		case 1:
			output = 34;
			break;
		case 28:
			output = 34;
			break;
		case 7:
			output = 34;
			break;
		case 34:
			output = 34;
			break;
		}
		break;
	case 35:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 6:
			output = 33;
			break;
		case 33:
			output = 33;
			break;
		case 2:
			output = 35;
			break;
		case 29:
			output = 35;
			break;
		case 8:
			output = 35;
			break;
		case 35:
			output = 35;
			break;
		}
		break;
	case 36:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		}
		break;
	case 37:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 1:
			output = 37;
			break;
		case 28:
			output = 37;
			break;
		case 10:
			output = 37;
			break;
		case 37:
			output = 37;
			break;
		}
		break;
	case 38:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 2:
			output = 38;
			break;
		case 29:
			output = 38;
			break;
		case 11:
			output = 38;
			break;
		case 38:
			output = 38;
			break;
		}
		break;
	case 39:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 3:
			output = 39;
			break;
		case 30:
			output = 39;
			break;
		case 12:
			output = 39;
			break;
		case 39:
			output = 39;
			break;
		}
		break;
	case 40:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 3:
			output = 39;
			break;
		case 30:
			output = 39;
			break;
		case 12:
			output = 39;
			break;
		case 39:
			output = 39;
			break;
		case 1:
			output = 40;
			break;
		case 28:
			output = 40;
			break;
		case 10:
			output = 40;
			break;
		case 37:
			output = 40;
			break;
		case 4:
			output = 40;
			break;
		case 31:
			output = 40;
			break;
		case 13:
			output = 40;
			break;
		case 40:
			output = 40;
			break;
		}
		break;
	case 41:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 3:
			output = 39;
			break;
		case 30:
			output = 39;
			break;
		case 12:
			output = 39;
			break;
		case 39:
			output = 39;
			break;
		case 2:
			output = 41;
			break;
		case 29:
			output = 41;
			break;
		case 11:
			output = 41;
			break;
		case 38:
			output = 41;
			break;
		case 5:
			output = 41;
			break;
		case 32:
			output = 41;
			break;
		case 14:
			output = 41;
			break;
		case 41:
			output = 41;
			break;
		}
		break;
	case 42:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 6:
			output = 42;
			break;
		case 33:
			output = 42;
			break;
		case 15:
			output = 42;
			break;
		case 42:
			output = 42;
			break;
		}
		break;
	case 43:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 6:
			output = 42;
			break;
		case 33:
			output = 42;
			break;
		case 15:
			output = 42;
			break;
		case 42:
			output = 42;
			break;
		case 1:
			output = 43;
			break;
		case 28:
			output = 43;
			break;
		case 10:
			output = 43;
			break;
		case 37:
			output = 43;
			break;
		case 7:
			output = 43;
			break;
		case 34:
			output = 43;
			break;
		case 16:
			output = 43;
			break;
		case 43:
			output = 43;
			break;
		}
		break;
	case 44:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 9:
			output = 36;
			break;
		case 36:
			output = 36;
			break;
		case 6:
			output = 42;
			break;
		case 33:
			output = 42;
			break;
		case 15:
			output = 42;
			break;
		case 42:
			output = 42;
			break;
		case 2:
			output = 44;
			break;
		case 29:
			output = 44;
			break;
		case 11:
			output = 44;
			break;
		case 38:
			output = 44;
			break;
		case 8:
			output = 44;
			break;
		case 35:
			output = 44;
			break;
		case 17:
			output = 44;
			break;
		case 44:
			output = 44;
			break;
		}
		break;
	case 45:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		}
		break;
	case 46:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 1:
			output = 46;
			break;
		case 28:
			output = 46;
			break;
		case 19:
			output = 46;
			break;
		case 46:
			output = 46;
			break;
		}
		break;
	case 47:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 2:
			output = 47;
			break;
		case 29:
			output = 47;
			break;
		case 20:
			output = 47;
			break;
		case 47:
			output = 47;
			break;
		}
		break;
	case 48:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 3:
			output = 48;
			break;
		case 30:
			output = 48;
			break;
		case 21:
			output = 48;
			break;
		case 48:
			output = 48;
			break;
		}
		break;
	case 49:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 3:
			output = 48;
			break;
		case 30:
			output = 48;
			break;
		case 21:
			output = 48;
			break;
		case 48:
			output = 48;
			break;
		case 1:
			output = 49;
			break;
		case 28:
			output = 49;
			break;
		case 19:
			output = 49;
			break;
		case 46:
			output = 49;
			break;
		case 4:
			output = 49;
			break;
		case 31:
			output = 49;
			break;
		case 22:
			output = 49;
			break;
		case 49:
			output = 49;
			break;
		}
		break;
	case 50:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 3:
			output = 48;
			break;
		case 30:
			output = 48;
			break;
		case 21:
			output = 48;
			break;
		case 48:
			output = 48;
			break;
		case 2:
			output = 50;
			break;
		case 29:
			output = 50;
			break;
		case 20:
			output = 50;
			break;
		case 47:
			output = 50;
			break;
		case 5:
			output = 50;
			break;
		case 32:
			output = 50;
			break;
		case 23:
			output = 50;
			break;
		case 50:
			output = 50;
			break;
		}
		break;
	case 51:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 6:
			output = 51;
			break;
		case 33:
			output = 51;
			break;
		case 24:
			output = 51;
			break;
		case 51:
			output = 51;
			break;
		}
		break;
	case 52:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 6:
			output = 51;
			break;
		case 33:
			output = 51;
			break;
		case 24:
			output = 51;
			break;
		case 51:
			output = 51;
			break;
		case 1:
			output = 52;
			break;
		case 28:
			output = 52;
			break;
		case 19:
			output = 52;
			break;
		case 46:
			output = 52;
			break;
		case 7:
			output = 52;
			break;
		case 34:
			output = 52;
			break;
		case 25:
			output = 52;
			break;
		case 52:
			output = 52;
			break;
		}
		break;
	case 53:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 27:
			output = 27;
			break;
		case 18:
			output = 45;
			break;
		case 45:
			output = 45;
			break;
		case 6:
			output = 51;
			break;
		case 33:
			output = 51;
			break;
		case 24:
			output = 51;
			break;
		case 51:
			output = 51;
			break;
		case 2:
			output = 53;
			break;
		case 29:
			output = 53;
			break;
		case 20:
			output = 53;
			break;
		case 47:
			output = 53;
			break;
		case 8:
			output = 53;
			break;
		case 35:
			output = 53;
			break;
		case 26:
			output = 53;
			break;
		case 53:
			output = 53;
			break;
		}
		break;
	case 54:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		}
		break;
	case 55:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 1:
			output = 55;
			break;
		case 55:
			output = 55;
			break;
		}
		break;
	case 56:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 2:
			output = 56;
			break;
		case 56:
			output = 56;
			break;
		}
		break;
	case 57:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 3:
			output = 57;
			break;
		case 57:
			output = 57;
			break;
		}
		break;
	case 58:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 3:
			output = 57;
			break;
		case 57:
			output = 57;
			break;
		case 1:
			output = 58;
			break;
		case 55:
			output = 58;
			break;
		case 4:
			output = 58;
			break;
		case 58:
			output = 58;
			break;
		}
		break;
	case 59:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 3:
			output = 57;
			break;
		case 57:
			output = 57;
			break;
		case 2:
			output = 59;
			break;
		case 56:
			output = 59;
			break;
		case 5:
			output = 59;
			break;
		case 59:
			output = 59;
			break;
		}
		break;
	case 60:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 6:
			output = 60;
			break;
		case 60:
			output = 60;
			break;
		}
		break;
	case 61:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 6:
			output = 60;
			break;
		case 60:
			output = 60;
			break;
		case 1:
			output = 61;
			break;
		case 55:
			output = 61;
			break;
		case 7:
			output = 61;
			break;
		case 61:
			output = 61;
			break;
		}
		break;
	case 62:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 6:
			output = 60;
			break;
		case 60:
			output = 60;
			break;
		case 2:
			output = 62;
			break;
		case 56:
			output = 62;
			break;
		case 8:
			output = 62;
			break;
		case 62:
			output = 62;
			break;
		}
		break;
	case 63:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		}
		break;
	case 64:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 1:
			output = 64;
			break;
		case 55:
			output = 64;
			break;
		case 10:
			output = 64;
			break;
		case 64:
			output = 64;
			break;
		}
		break;
	case 65:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 2:
			output = 65;
			break;
		case 56:
			output = 65;
			break;
		case 11:
			output = 65;
			break;
		case 65:
			output = 65;
			break;
		}
		break;
	case 66:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 3:
			output = 66;
			break;
		case 57:
			output = 66;
			break;
		case 12:
			output = 66;
			break;
		case 66:
			output = 66;
			break;
		}
		break;
	case 67:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 3:
			output = 66;
			break;
		case 57:
			output = 66;
			break;
		case 12:
			output = 66;
			break;
		case 66:
			output = 66;
			break;
		case 1:
			output = 67;
			break;
		case 55:
			output = 67;
			break;
		case 10:
			output = 67;
			break;
		case 64:
			output = 67;
			break;
		case 4:
			output = 67;
			break;
		case 58:
			output = 67;
			break;
		case 13:
			output = 67;
			break;
		case 67:
			output = 67;
			break;
		}
		break;
	case 68:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 3:
			output = 66;
			break;
		case 57:
			output = 66;
			break;
		case 12:
			output = 66;
			break;
		case 66:
			output = 66;
			break;
		case 2:
			output = 68;
			break;
		case 56:
			output = 68;
			break;
		case 11:
			output = 68;
			break;
		case 65:
			output = 68;
			break;
		case 5:
			output = 68;
			break;
		case 59:
			output = 68;
			break;
		case 14:
			output = 68;
			break;
		case 68:
			output = 68;
			break;
		}
		break;
	case 69:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 6:
			output = 69;
			break;
		case 60:
			output = 69;
			break;
		case 15:
			output = 69;
			break;
		case 69:
			output = 69;
			break;
		}
		break;
	case 70:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 6:
			output = 69;
			break;
		case 60:
			output = 69;
			break;
		case 15:
			output = 69;
			break;
		case 69:
			output = 69;
			break;
		case 1:
			output = 70;
			break;
		case 55:
			output = 70;
			break;
		case 10:
			output = 70;
			break;
		case 64:
			output = 70;
			break;
		case 7:
			output = 70;
			break;
		case 61:
			output = 70;
			break;
		case 16:
			output = 70;
			break;
		case 70:
			output = 70;
			break;
		}
		break;
	case 71:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 9:
			output = 63;
			break;
		case 63:
			output = 63;
			break;
		case 6:
			output = 69;
			break;
		case 60:
			output = 69;
			break;
		case 15:
			output = 69;
			break;
		case 69:
			output = 69;
			break;
		case 2:
			output = 71;
			break;
		case 56:
			output = 71;
			break;
		case 11:
			output = 71;
			break;
		case 65:
			output = 71;
			break;
		case 8:
			output = 71;
			break;
		case 62:
			output = 71;
			break;
		case 17:
			output = 71;
			break;
		case 71:
			output = 71;
			break;
		}
		break;
	case 72:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		}
		break;
	case 73:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 1:
			output = 73;
			break;
		case 55:
			output = 73;
			break;
		case 19:
			output = 73;
			break;
		case 73:
			output = 73;
			break;
		}
		break;
	case 74:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 2:
			output = 74;
			break;
		case 56:
			output = 74;
			break;
		case 20:
			output = 74;
			break;
		case 74:
			output = 74;
			break;
		}
		break;
	case 75:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 3:
			output = 75;
			break;
		case 57:
			output = 75;
			break;
		case 21:
			output = 75;
			break;
		case 75:
			output = 75;
			break;
		}
		break;
	case 76:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 3:
			output = 75;
			break;
		case 57:
			output = 75;
			break;
		case 21:
			output = 75;
			break;
		case 75:
			output = 75;
			break;
		case 1:
			output = 76;
			break;
		case 55:
			output = 76;
			break;
		case 19:
			output = 76;
			break;
		case 73:
			output = 76;
			break;
		case 4:
			output = 76;
			break;
		case 58:
			output = 76;
			break;
		case 22:
			output = 76;
			break;
		case 76:
			output = 76;
			break;
		}
		break;
	case 77:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 3:
			output = 75;
			break;
		case 57:
			output = 75;
			break;
		case 21:
			output = 75;
			break;
		case 75:
			output = 75;
			break;
		case 2:
			output = 77;
			break;
		case 56:
			output = 77;
			break;
		case 20:
			output = 77;
			break;
		case 74:
			output = 77;
			break;
		case 5:
			output = 77;
			break;
		case 59:
			output = 77;
			break;
		case 23:
			output = 77;
			break;
		case 77:
			output = 77;
			break;
		}
		break;
	case 78:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 6:
			output = 78;
			break;
		case 60:
			output = 78;
			break;
		case 24:
			output = 78;
			break;
		case 78:
			output = 78;
			break;
		}
		break;
	case 79:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 6:
			output = 78;
			break;
		case 60:
			output = 78;
			break;
		case 24:
			output = 78;
			break;
		case 78:
			output = 78;
			break;
		case 1:
			output = 79;
			break;
		case 55:
			output = 79;
			break;
		case 19:
			output = 79;
			break;
		case 73:
			output = 79;
			break;
		case 7:
			output = 79;
			break;
		case 61:
			output = 79;
			break;
		case 25:
			output = 79;
			break;
		case 79:
			output = 79;
			break;
		}
		break;
	case 80:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 54:
			output = 54;
			break;
		case 18:
			output = 72;
			break;
		case 72:
			output = 72;
			break;
		case 6:
			output = 78;
			break;
		case 60:
			output = 78;
			break;
		case 24:
			output = 78;
			break;
		case 78:
			output = 78;
			break;
		case 2:
			output = 80;
			break;
		case 56:
			output = 80;
			break;
		case 20:
			output = 80;
			break;
		case 74:
			output = 80;
			break;
		case 8:
			output = 80;
			break;
		case 62:
			output = 80;
			break;
		case 26:
			output = 80;
			break;
		case 80:
			output = 80;
			break;
		}
		break;
	case 81:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		}
		break;
	case 82:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 1:
			output = 82;
			break;
		case 82:
			output = 82;
			break;
		}
		break;
	case 83:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 2:
			output = 83;
			break;
		case 83:
			output = 83;
			break;
		}
		break;
	case 84:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 3:
			output = 84;
			break;
		case 84:
			output = 84;
			break;
		}
		break;
	case 85:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 3:
			output = 84;
			break;
		case 84:
			output = 84;
			break;
		case 1:
			output = 85;
			break;
		case 82:
			output = 85;
			break;
		case 4:
			output = 85;
			break;
		case 85:
			output = 85;
			break;
		}
		break;
	case 86:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 3:
			output = 84;
			break;
		case 84:
			output = 84;
			break;
		case 2:
			output = 86;
			break;
		case 83:
			output = 86;
			break;
		case 5:
			output = 86;
			break;
		case 86:
			output = 86;
			break;
		}
		break;
	case 87:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 6:
			output = 87;
			break;
		case 87:
			output = 87;
			break;
		}
		break;
	case 88:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 6:
			output = 87;
			break;
		case 87:
			output = 87;
			break;
		case 1:
			output = 88;
			break;
		case 82:
			output = 88;
			break;
		case 7:
			output = 88;
			break;
		case 88:
			output = 88;
			break;
		}
		break;
	case 89:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 6:
			output = 87;
			break;
		case 87:
			output = 87;
			break;
		case 2:
			output = 89;
			break;
		case 83:
			output = 89;
			break;
		case 8:
			output = 89;
			break;
		case 89:
			output = 89;
			break;
		}
		break;
	case 90:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		}
		break;
	case 91:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 1:
			output = 91;
			break;
		case 82:
			output = 91;
			break;
		case 10:
			output = 91;
			break;
		case 91:
			output = 91;
			break;
		}
		break;
	case 92:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 2:
			output = 92;
			break;
		case 83:
			output = 92;
			break;
		case 11:
			output = 92;
			break;
		case 92:
			output = 92;
			break;
		}
		break;
	case 93:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 3:
			output = 93;
			break;
		case 84:
			output = 93;
			break;
		case 12:
			output = 93;
			break;
		case 93:
			output = 93;
			break;
		}
		break;
	case 94:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 3:
			output = 93;
			break;
		case 84:
			output = 93;
			break;
		case 12:
			output = 93;
			break;
		case 93:
			output = 93;
			break;
		case 1:
			output = 94;
			break;
		case 82:
			output = 94;
			break;
		case 10:
			output = 94;
			break;
		case 91:
			output = 94;
			break;
		case 4:
			output = 94;
			break;
		case 85:
			output = 94;
			break;
		case 13:
			output = 94;
			break;
		case 94:
			output = 94;
			break;
		}
		break;
	case 95:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 3:
			output = 93;
			break;
		case 84:
			output = 93;
			break;
		case 12:
			output = 93;
			break;
		case 93:
			output = 93;
			break;
		case 2:
			output = 95;
			break;
		case 83:
			output = 95;
			break;
		case 11:
			output = 95;
			break;
		case 92:
			output = 95;
			break;
		case 5:
			output = 95;
			break;
		case 86:
			output = 95;
			break;
		case 14:
			output = 95;
			break;
		case 95:
			output = 95;
			break;
		}
		break;
	case 96:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 6:
			output = 96;
			break;
		case 87:
			output = 96;
			break;
		case 15:
			output = 96;
			break;
		case 96:
			output = 96;
			break;
		}
		break;
	case 97:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 6:
			output = 96;
			break;
		case 87:
			output = 96;
			break;
		case 15:
			output = 96;
			break;
		case 96:
			output = 96;
			break;
		case 1:
			output = 97;
			break;
		case 82:
			output = 97;
			break;
		case 10:
			output = 97;
			break;
		case 91:
			output = 97;
			break;
		case 7:
			output = 97;
			break;
		case 88:
			output = 97;
			break;
		case 16:
			output = 97;
			break;
		case 97:
			output = 97;
			break;
		}
		break;
	case 98:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 9:
			output = 90;
			break;
		case 90:
			output = 90;
			break;
		case 6:
			output = 96;
			break;
		case 87:
			output = 96;
			break;
		case 15:
			output = 96;
			break;
		case 96:
			output = 96;
			break;
		case 2:
			output = 98;
			break;
		case 83:
			output = 98;
			break;
		case 11:
			output = 98;
			break;
		case 92:
			output = 98;
			break;
		case 8:
			output = 98;
			break;
		case 89:
			output = 98;
			break;
		case 17:
			output = 98;
			break;
		case 98:
			output = 98;
			break;
		}
		break;
	case 99:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		}
		break;
	case 100:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 1:
			output = 100;
			break;
		case 82:
			output = 100;
			break;
		case 19:
			output = 100;
			break;
		case 100:
			output = 100;
			break;
		}
		break;
	case 101:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 2:
			output = 101;
			break;
		case 83:
			output = 101;
			break;
		case 20:
			output = 101;
			break;
		case 101:
			output = 101;
			break;
		}
		break;
	case 102:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 3:
			output = 102;
			break;
		case 84:
			output = 102;
			break;
		case 21:
			output = 102;
			break;
		case 102:
			output = 102;
			break;
		}
		break;
	case 103:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 3:
			output = 102;
			break;
		case 84:
			output = 102;
			break;
		case 21:
			output = 102;
			break;
		case 102:
			output = 102;
			break;
		case 1:
			output = 103;
			break;
		case 82:
			output = 103;
			break;
		case 19:
			output = 103;
			break;
		case 100:
			output = 103;
			break;
		case 4:
			output = 103;
			break;
		case 85:
			output = 103;
			break;
		case 22:
			output = 103;
			break;
		case 103:
			output = 103;
			break;
		}
		break;
	case 104:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 3:
			output = 102;
			break;
		case 84:
			output = 102;
			break;
		case 21:
			output = 102;
			break;
		case 102:
			output = 102;
			break;
		case 2:
			output = 104;
			break;
		case 83:
			output = 104;
			break;
		case 20:
			output = 104;
			break;
		case 101:
			output = 104;
			break;
		case 5:
			output = 104;
			break;
		case 86:
			output = 104;
			break;
		case 23:
			output = 104;
			break;
		case 104:
			output = 104;
			break;
		}
		break;
	case 105:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 6:
			output = 105;
			break;
		case 87:
			output = 105;
			break;
		case 24:
			output = 105;
			break;
		case 105:
			output = 105;
			break;
		}
		break;
	case 106:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 6:
			output = 105;
			break;
		case 87:
			output = 105;
			break;
		case 24:
			output = 105;
			break;
		case 105:
			output = 105;
			break;
		case 1:
			output = 106;
			break;
		case 82:
			output = 106;
			break;
		case 19:
			output = 106;
			break;
		case 100:
			output = 106;
			break;
		case 7:
			output = 106;
			break;
		case 88:
			output = 106;
			break;
		case 25:
			output = 106;
			break;
		case 106:
			output = 106;
			break;
		}
		break;
	case 107:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 18:
			output = 99;
			break;
		case 99:
			output = 99;
			break;
		case 6:
			output = 105;
			break;
		case 87:
			output = 105;
			break;
		case 24:
			output = 105;
			break;
		case 105:
			output = 105;
			break;
		case 2:
			output = 107;
			break;
		case 83:
			output = 107;
			break;
		case 20:
			output = 107;
			break;
		case 101:
			output = 107;
			break;
		case 8:
			output = 107;
			break;
		case 89:
			output = 107;
			break;
		case 26:
			output = 107;
			break;
		case 107:
			output = 107;
			break;
		}
		break;
	case 108:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		}
		break;
	case 109:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 1:
			output = 109;
			break;
		case 82:
			output = 109;
			break;
		case 28:
			output = 109;
			break;
		case 109:
			output = 109;
			break;
		}
		break;
	case 110:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 2:
			output = 110;
			break;
		case 83:
			output = 110;
			break;
		case 29:
			output = 110;
			break;
		case 110:
			output = 110;
			break;
		}
		break;
	case 111:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 3:
			output = 111;
			break;
		case 84:
			output = 111;
			break;
		case 30:
			output = 111;
			break;
		case 111:
			output = 111;
			break;
		}
		break;
	case 112:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 3:
			output = 111;
			break;
		case 84:
			output = 111;
			break;
		case 30:
			output = 111;
			break;
		case 111:
			output = 111;
			break;
		case 1:
			output = 112;
			break;
		case 82:
			output = 112;
			break;
		case 28:
			output = 112;
			break;
		case 109:
			output = 112;
			break;
		case 4:
			output = 112;
			break;
		case 85:
			output = 112;
			break;
		case 31:
			output = 112;
			break;
		case 112:
			output = 112;
			break;
		}
		break;
	case 113:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 3:
			output = 111;
			break;
		case 84:
			output = 111;
			break;
		case 30:
			output = 111;
			break;
		case 111:
			output = 111;
			break;
		case 2:
			output = 113;
			break;
		case 83:
			output = 113;
			break;
		case 29:
			output = 113;
			break;
		case 110:
			output = 113;
			break;
		case 5:
			output = 113;
			break;
		case 86:
			output = 113;
			break;
		case 32:
			output = 113;
			break;
		case 113:
			output = 113;
			break;
		}
		break;
	case 114:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 6:
			output = 114;
			break;
		case 87:
			output = 114;
			break;
		case 33:
			output = 114;
			break;
		case 114:
			output = 114;
			break;
		}
		break;
	case 115:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 6:
			output = 114;
			break;
		case 87:
			output = 114;
			break;
		case 33:
			output = 114;
			break;
		case 114:
			output = 114;
			break;
		case 1:
			output = 115;
			break;
		case 82:
			output = 115;
			break;
		case 28:
			output = 115;
			break;
		case 109:
			output = 115;
			break;
		case 7:
			output = 115;
			break;
		case 88:
			output = 115;
			break;
		case 34:
			output = 115;
			break;
		case 115:
			output = 115;
			break;
		}
		break;
	case 116:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 6:
			output = 114;
			break;
		case 87:
			output = 114;
			break;
		case 33:
			output = 114;
			break;
		case 114:
			output = 114;
			break;
		case 2:
			output = 116;
			break;
		case 83:
			output = 116;
			break;
		case 29:
			output = 116;
			break;
		case 110:
			output = 116;
			break;
		case 8:
			output = 116;
			break;
		case 89:
			output = 116;
			break;
		case 35:
			output = 116;
			break;
		case 116:
			output = 116;
			break;
		}
		break;
	case 117:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		}
		break;
	case 118:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 1:
			output = 118;
			break;
		case 82:
			output = 118;
			break;
		case 28:
			output = 118;
			break;
		case 109:
			output = 118;
			break;
		case 10:
			output = 118;
			break;
		case 91:
			output = 118;
			break;
		case 37:
			output = 118;
			break;
		case 118:
			output = 118;
			break;
		}
		break;
	case 119:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 2:
			output = 119;
			break;
		case 83:
			output = 119;
			break;
		case 29:
			output = 119;
			break;
		case 110:
			output = 119;
			break;
		case 11:
			output = 119;
			break;
		case 92:
			output = 119;
			break;
		case 38:
			output = 119;
			break;
		case 119:
			output = 119;
			break;
		}
		break;
	case 120:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 3:
			output = 120;
			break;
		case 84:
			output = 120;
			break;
		case 30:
			output = 120;
			break;
		case 111:
			output = 120;
			break;
		case 12:
			output = 120;
			break;
		case 93:
			output = 120;
			break;
		case 39:
			output = 120;
			break;
		case 120:
			output = 120;
			break;
		}
		break;
	case 121:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 3:
			output = 120;
			break;
		case 84:
			output = 120;
			break;
		case 30:
			output = 120;
			break;
		case 111:
			output = 120;
			break;
		case 12:
			output = 120;
			break;
		case 93:
			output = 120;
			break;
		case 39:
			output = 120;
			break;
		case 120:
			output = 120;
			break;
		case 1:
			output = 121;
			break;
		case 82:
			output = 121;
			break;
		case 28:
			output = 121;
			break;
		case 109:
			output = 121;
			break;
		case 10:
			output = 121;
			break;
		case 91:
			output = 121;
			break;
		case 37:
			output = 121;
			break;
		case 118:
			output = 121;
			break;
		case 4:
			output = 121;
			break;
		case 85:
			output = 121;
			break;
		case 31:
			output = 121;
			break;
		case 112:
			output = 121;
			break;
		case 13:
			output = 121;
			break;
		case 94:
			output = 121;
			break;
		case 40:
			output = 121;
			break;
		case 121:
			output = 121;
			break;
		}
		break;
	case 122:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 3:
			output = 120;
			break;
		case 84:
			output = 120;
			break;
		case 30:
			output = 120;
			break;
		case 111:
			output = 120;
			break;
		case 12:
			output = 120;
			break;
		case 93:
			output = 120;
			break;
		case 39:
			output = 120;
			break;
		case 120:
			output = 120;
			break;
		case 2:
			output = 122;
			break;
		case 83:
			output = 122;
			break;
		case 29:
			output = 122;
			break;
		case 110:
			output = 122;
			break;
		case 11:
			output = 122;
			break;
		case 92:
			output = 122;
			break;
		case 38:
			output = 122;
			break;
		case 119:
			output = 122;
			break;
		case 5:
			output = 122;
			break;
		case 86:
			output = 122;
			break;
		case 32:
			output = 122;
			break;
		case 113:
			output = 122;
			break;
		case 14:
			output = 122;
			break;
		case 95:
			output = 122;
			break;
		case 41:
			output = 122;
			break;
		case 122:
			output = 122;
			break;
		}
		break;
	case 123:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 6:
			output = 123;
			break;
		case 87:
			output = 123;
			break;
		case 33:
			output = 123;
			break;
		case 114:
			output = 123;
			break;
		case 15:
			output = 123;
			break;
		case 96:
			output = 123;
			break;
		case 42:
			output = 123;
			break;
		case 123:
			output = 123;
			break;
		}
		break;
	case 124:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 6:
			output = 123;
			break;
		case 87:
			output = 123;
			break;
		case 33:
			output = 123;
			break;
		case 114:
			output = 123;
			break;
		case 15:
			output = 123;
			break;
		case 96:
			output = 123;
			break;
		case 42:
			output = 123;
			break;
		case 123:
			output = 123;
			break;
		case 1:
			output = 124;
			break;
		case 82:
			output = 124;
			break;
		case 28:
			output = 124;
			break;
		case 109:
			output = 124;
			break;
		case 10:
			output = 124;
			break;
		case 91:
			output = 124;
			break;
		case 37:
			output = 124;
			break;
		case 118:
			output = 124;
			break;
		case 7:
			output = 124;
			break;
		case 88:
			output = 124;
			break;
		case 34:
			output = 124;
			break;
		case 115:
			output = 124;
			break;
		case 16:
			output = 124;
			break;
		case 97:
			output = 124;
			break;
		case 43:
			output = 124;
			break;
		case 124:
			output = 124;
			break;
		}
		break;
	case 125:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 9:
			output = 117;
			break;
		case 90:
			output = 117;
			break;
		case 36:
			output = 117;
			break;
		case 117:
			output = 117;
			break;
		case 6:
			output = 123;
			break;
		case 87:
			output = 123;
			break;
		case 33:
			output = 123;
			break;
		case 114:
			output = 123;
			break;
		case 15:
			output = 123;
			break;
		case 96:
			output = 123;
			break;
		case 42:
			output = 123;
			break;
		case 123:
			output = 123;
			break;
		case 2:
			output = 125;
			break;
		case 83:
			output = 125;
			break;
		case 29:
			output = 125;
			break;
		case 110:
			output = 125;
			break;
		case 11:
			output = 125;
			break;
		case 92:
			output = 125;
			break;
		case 38:
			output = 125;
			break;
		case 119:
			output = 125;
			break;
		case 8:
			output = 125;
			break;
		case 89:
			output = 125;
			break;
		case 35:
			output = 125;
			break;
		case 116:
			output = 125;
			break;
		case 17:
			output = 125;
			break;
		case 98:
			output = 125;
			break;
		case 44:
			output = 125;
			break;
		case 125:
			output = 125;
			break;
		}
		break;
	case 126:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		}
		break;
	case 127:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 1:
			output = 127;
			break;
		case 82:
			output = 127;
			break;
		case 28:
			output = 127;
			break;
		case 109:
			output = 127;
			break;
		case 19:
			output = 127;
			break;
		case 100:
			output = 127;
			break;
		case 46:
			output = 127;
			break;
		case 127:
			output = 127;
			break;
		}
		break;
	case 128:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 2:
			output = 128;
			break;
		case 83:
			output = 128;
			break;
		case 29:
			output = 128;
			break;
		case 110:
			output = 128;
			break;
		case 20:
			output = 128;
			break;
		case 101:
			output = 128;
			break;
		case 47:
			output = 128;
			break;
		case 128:
			output = 128;
			break;
		}
		break;
	case 129:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 3:
			output = 129;
			break;
		case 84:
			output = 129;
			break;
		case 30:
			output = 129;
			break;
		case 111:
			output = 129;
			break;
		case 21:
			output = 129;
			break;
		case 102:
			output = 129;
			break;
		case 48:
			output = 129;
			break;
		case 129:
			output = 129;
			break;
		}
		break;
	case 130:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 3:
			output = 129;
			break;
		case 84:
			output = 129;
			break;
		case 30:
			output = 129;
			break;
		case 111:
			output = 129;
			break;
		case 21:
			output = 129;
			break;
		case 102:
			output = 129;
			break;
		case 48:
			output = 129;
			break;
		case 129:
			output = 129;
			break;
		case 1:
			output = 130;
			break;
		case 82:
			output = 130;
			break;
		case 28:
			output = 130;
			break;
		case 109:
			output = 130;
			break;
		case 19:
			output = 130;
			break;
		case 100:
			output = 130;
			break;
		case 46:
			output = 130;
			break;
		case 127:
			output = 130;
			break;
		case 4:
			output = 130;
			break;
		case 85:
			output = 130;
			break;
		case 31:
			output = 130;
			break;
		case 112:
			output = 130;
			break;
		case 22:
			output = 130;
			break;
		case 103:
			output = 130;
			break;
		case 49:
			output = 130;
			break;
		case 130:
			output = 130;
			break;
		}
		break;
	case 131:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 3:
			output = 129;
			break;
		case 84:
			output = 129;
			break;
		case 30:
			output = 129;
			break;
		case 111:
			output = 129;
			break;
		case 21:
			output = 129;
			break;
		case 102:
			output = 129;
			break;
		case 48:
			output = 129;
			break;
		case 129:
			output = 129;
			break;
		case 2:
			output = 131;
			break;
		case 83:
			output = 131;
			break;
		case 29:
			output = 131;
			break;
		case 110:
			output = 131;
			break;
		case 20:
			output = 131;
			break;
		case 101:
			output = 131;
			break;
		case 47:
			output = 131;
			break;
		case 128:
			output = 131;
			break;
		case 5:
			output = 131;
			break;
		case 86:
			output = 131;
			break;
		case 32:
			output = 131;
			break;
		case 113:
			output = 131;
			break;
		case 23:
			output = 131;
			break;
		case 104:
			output = 131;
			break;
		case 50:
			output = 131;
			break;
		case 131:
			output = 131;
			break;
		}
		break;
	case 132:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 6:
			output = 132;
			break;
		case 87:
			output = 132;
			break;
		case 33:
			output = 132;
			break;
		case 114:
			output = 132;
			break;
		case 24:
			output = 132;
			break;
		case 105:
			output = 132;
			break;
		case 51:
			output = 132;
			break;
		case 132:
			output = 132;
			break;
		}
		break;
	case 133:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 6:
			output = 132;
			break;
		case 87:
			output = 132;
			break;
		case 33:
			output = 132;
			break;
		case 114:
			output = 132;
			break;
		case 24:
			output = 132;
			break;
		case 105:
			output = 132;
			break;
		case 51:
			output = 132;
			break;
		case 132:
			output = 132;
			break;
		case 1:
			output = 133;
			break;
		case 82:
			output = 133;
			break;
		case 28:
			output = 133;
			break;
		case 109:
			output = 133;
			break;
		case 19:
			output = 133;
			break;
		case 100:
			output = 133;
			break;
		case 46:
			output = 133;
			break;
		case 127:
			output = 133;
			break;
		case 7:
			output = 133;
			break;
		case 88:
			output = 133;
			break;
		case 34:
			output = 133;
			break;
		case 115:
			output = 133;
			break;
		case 25:
			output = 133;
			break;
		case 106:
			output = 133;
			break;
		case 52:
			output = 133;
			break;
		case 133:
			output = 133;
			break;
		}
		break;
	case 134:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 27:
			output = 108;
			break;
		case 108:
			output = 108;
			break;
		case 18:
			output = 126;
			break;
		case 99:
			output = 126;
			break;
		case 45:
			output = 126;
			break;
		case 126:
			output = 126;
			break;
		case 6:
			output = 132;
			break;
		case 87:
			output = 132;
			break;
		case 33:
			output = 132;
			break;
		case 114:
			output = 132;
			break;
		case 24:
			output = 132;
			break;
		case 105:
			output = 132;
			break;
		case 51:
			output = 132;
			break;
		case 132:
			output = 132;
			break;
		case 2:
			output = 134;
			break;
		case 83:
			output = 134;
			break;
		case 29:
			output = 134;
			break;
		case 110:
			output = 134;
			break;
		case 20:
			output = 134;
			break;
		case 101:
			output = 134;
			break;
		case 47:
			output = 134;
			break;
		case 128:
			output = 134;
			break;
		case 8:
			output = 134;
			break;
		case 89:
			output = 134;
			break;
		case 35:
			output = 134;
			break;
		case 116:
			output = 134;
			break;
		case 26:
			output = 134;
			break;
		case 107:
			output = 134;
			break;
		case 53:
			output = 134;
			break;
		case 134:
			output = 134;
			break;
		}
		break;
	case 135:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		}
		break;
	case 136:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 1:
			output = 136;
			break;
		case 82:
			output = 136;
			break;
		case 55:
			output = 136;
			break;
		case 136:
			output = 136;
			break;
		}
		break;
	case 137:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 2:
			output = 137;
			break;
		case 83:
			output = 137;
			break;
		case 56:
			output = 137;
			break;
		case 137:
			output = 137;
			break;
		}
		break;
	case 138:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 3:
			output = 138;
			break;
		case 84:
			output = 138;
			break;
		case 57:
			output = 138;
			break;
		case 138:
			output = 138;
			break;
		}
		break;
	case 139:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 3:
			output = 138;
			break;
		case 84:
			output = 138;
			break;
		case 57:
			output = 138;
			break;
		case 138:
			output = 138;
			break;
		case 1:
			output = 139;
			break;
		case 82:
			output = 139;
			break;
		case 55:
			output = 139;
			break;
		case 136:
			output = 139;
			break;
		case 4:
			output = 139;
			break;
		case 85:
			output = 139;
			break;
		case 58:
			output = 139;
			break;
		case 139:
			output = 139;
			break;
		}
		break;
	case 140:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 3:
			output = 138;
			break;
		case 84:
			output = 138;
			break;
		case 57:
			output = 138;
			break;
		case 138:
			output = 138;
			break;
		case 2:
			output = 140;
			break;
		case 83:
			output = 140;
			break;
		case 56:
			output = 140;
			break;
		case 137:
			output = 140;
			break;
		case 5:
			output = 140;
			break;
		case 86:
			output = 140;
			break;
		case 59:
			output = 140;
			break;
		case 140:
			output = 140;
			break;
		}
		break;
	case 141:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 6:
			output = 141;
			break;
		case 87:
			output = 141;
			break;
		case 60:
			output = 141;
			break;
		case 141:
			output = 141;
			break;
		}
		break;
	case 142:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 6:
			output = 141;
			break;
		case 87:
			output = 141;
			break;
		case 60:
			output = 141;
			break;
		case 141:
			output = 141;
			break;
		case 1:
			output = 142;
			break;
		case 82:
			output = 142;
			break;
		case 55:
			output = 142;
			break;
		case 136:
			output = 142;
			break;
		case 7:
			output = 142;
			break;
		case 88:
			output = 142;
			break;
		case 61:
			output = 142;
			break;
		case 142:
			output = 142;
			break;
		}
		break;
	case 143:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 6:
			output = 141;
			break;
		case 87:
			output = 141;
			break;
		case 60:
			output = 141;
			break;
		case 141:
			output = 141;
			break;
		case 2:
			output = 143;
			break;
		case 83:
			output = 143;
			break;
		case 56:
			output = 143;
			break;
		case 137:
			output = 143;
			break;
		case 8:
			output = 143;
			break;
		case 89:
			output = 143;
			break;
		case 62:
			output = 143;
			break;
		case 143:
			output = 143;
			break;
		}
		break;
	case 144:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		}
		break;
	case 145:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 1:
			output = 145;
			break;
		case 82:
			output = 145;
			break;
		case 55:
			output = 145;
			break;
		case 136:
			output = 145;
			break;
		case 10:
			output = 145;
			break;
		case 91:
			output = 145;
			break;
		case 64:
			output = 145;
			break;
		case 145:
			output = 145;
			break;
		}
		break;
	case 146:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 2:
			output = 146;
			break;
		case 83:
			output = 146;
			break;
		case 56:
			output = 146;
			break;
		case 137:
			output = 146;
			break;
		case 11:
			output = 146;
			break;
		case 92:
			output = 146;
			break;
		case 65:
			output = 146;
			break;
		case 146:
			output = 146;
			break;
		}
		break;
	case 147:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 3:
			output = 147;
			break;
		case 84:
			output = 147;
			break;
		case 57:
			output = 147;
			break;
		case 138:
			output = 147;
			break;
		case 12:
			output = 147;
			break;
		case 93:
			output = 147;
			break;
		case 66:
			output = 147;
			break;
		case 147:
			output = 147;
			break;
		}
		break;
	case 148:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 3:
			output = 147;
			break;
		case 84:
			output = 147;
			break;
		case 57:
			output = 147;
			break;
		case 138:
			output = 147;
			break;
		case 12:
			output = 147;
			break;
		case 93:
			output = 147;
			break;
		case 66:
			output = 147;
			break;
		case 147:
			output = 147;
			break;
		case 1:
			output = 148;
			break;
		case 82:
			output = 148;
			break;
		case 55:
			output = 148;
			break;
		case 136:
			output = 148;
			break;
		case 10:
			output = 148;
			break;
		case 91:
			output = 148;
			break;
		case 64:
			output = 148;
			break;
		case 145:
			output = 148;
			break;
		case 4:
			output = 148;
			break;
		case 85:
			output = 148;
			break;
		case 58:
			output = 148;
			break;
		case 139:
			output = 148;
			break;
		case 13:
			output = 148;
			break;
		case 94:
			output = 148;
			break;
		case 67:
			output = 148;
			break;
		case 148:
			output = 148;
			break;
		}
		break;
	case 149:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 3:
			output = 147;
			break;
		case 84:
			output = 147;
			break;
		case 57:
			output = 147;
			break;
		case 138:
			output = 147;
			break;
		case 12:
			output = 147;
			break;
		case 93:
			output = 147;
			break;
		case 66:
			output = 147;
			break;
		case 147:
			output = 147;
			break;
		case 2:
			output = 149;
			break;
		case 83:
			output = 149;
			break;
		case 56:
			output = 149;
			break;
		case 137:
			output = 149;
			break;
		case 11:
			output = 149;
			break;
		case 92:
			output = 149;
			break;
		case 65:
			output = 149;
			break;
		case 146:
			output = 149;
			break;
		case 5:
			output = 149;
			break;
		case 86:
			output = 149;
			break;
		case 59:
			output = 149;
			break;
		case 140:
			output = 149;
			break;
		case 14:
			output = 149;
			break;
		case 95:
			output = 149;
			break;
		case 68:
			output = 149;
			break;
		case 149:
			output = 149;
			break;
		}
		break;
	case 150:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 6:
			output = 150;
			break;
		case 87:
			output = 150;
			break;
		case 60:
			output = 150;
			break;
		case 141:
			output = 150;
			break;
		case 15:
			output = 150;
			break;
		case 96:
			output = 150;
			break;
		case 69:
			output = 150;
			break;
		case 150:
			output = 150;
			break;
		}
		break;
	case 151:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 6:
			output = 150;
			break;
		case 87:
			output = 150;
			break;
		case 60:
			output = 150;
			break;
		case 141:
			output = 150;
			break;
		case 15:
			output = 150;
			break;
		case 96:
			output = 150;
			break;
		case 69:
			output = 150;
			break;
		case 150:
			output = 150;
			break;
		case 1:
			output = 151;
			break;
		case 82:
			output = 151;
			break;
		case 55:
			output = 151;
			break;
		case 136:
			output = 151;
			break;
		case 10:
			output = 151;
			break;
		case 91:
			output = 151;
			break;
		case 64:
			output = 151;
			break;
		case 145:
			output = 151;
			break;
		case 7:
			output = 151;
			break;
		case 88:
			output = 151;
			break;
		case 61:
			output = 151;
			break;
		case 142:
			output = 151;
			break;
		case 16:
			output = 151;
			break;
		case 97:
			output = 151;
			break;
		case 70:
			output = 151;
			break;
		case 151:
			output = 151;
			break;
		}
		break;
	case 152:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 9:
			output = 144;
			break;
		case 90:
			output = 144;
			break;
		case 63:
			output = 144;
			break;
		case 144:
			output = 144;
			break;
		case 6:
			output = 150;
			break;
		case 87:
			output = 150;
			break;
		case 60:
			output = 150;
			break;
		case 141:
			output = 150;
			break;
		case 15:
			output = 150;
			break;
		case 96:
			output = 150;
			break;
		case 69:
			output = 150;
			break;
		case 150:
			output = 150;
			break;
		case 2:
			output = 152;
			break;
		case 83:
			output = 152;
			break;
		case 56:
			output = 152;
			break;
		case 137:
			output = 152;
			break;
		case 11:
			output = 152;
			break;
		case 92:
			output = 152;
			break;
		case 65:
			output = 152;
			break;
		case 146:
			output = 152;
			break;
		case 8:
			output = 152;
			break;
		case 89:
			output = 152;
			break;
		case 62:
			output = 152;
			break;
		case 143:
			output = 152;
			break;
		case 17:
			output = 152;
			break;
		case 98:
			output = 152;
			break;
		case 71:
			output = 152;
			break;
		case 152:
			output = 152;
			break;
		}
		break;
	case 153:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		}
		break;
	case 154:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 1:
			output = 154;
			break;
		case 82:
			output = 154;
			break;
		case 55:
			output = 154;
			break;
		case 136:
			output = 154;
			break;
		case 19:
			output = 154;
			break;
		case 100:
			output = 154;
			break;
		case 73:
			output = 154;
			break;
		case 154:
			output = 154;
			break;
		}
		break;
	case 155:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 2:
			output = 155;
			break;
		case 83:
			output = 155;
			break;
		case 56:
			output = 155;
			break;
		case 137:
			output = 155;
			break;
		case 20:
			output = 155;
			break;
		case 101:
			output = 155;
			break;
		case 74:
			output = 155;
			break;
		case 155:
			output = 155;
			break;
		}
		break;
	case 156:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 3:
			output = 156;
			break;
		case 84:
			output = 156;
			break;
		case 57:
			output = 156;
			break;
		case 138:
			output = 156;
			break;
		case 21:
			output = 156;
			break;
		case 102:
			output = 156;
			break;
		case 75:
			output = 156;
			break;
		case 156:
			output = 156;
			break;
		}
		break;
	case 157:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 3:
			output = 156;
			break;
		case 84:
			output = 156;
			break;
		case 57:
			output = 156;
			break;
		case 138:
			output = 156;
			break;
		case 21:
			output = 156;
			break;
		case 102:
			output = 156;
			break;
		case 75:
			output = 156;
			break;
		case 156:
			output = 156;
			break;
		case 1:
			output = 157;
			break;
		case 82:
			output = 157;
			break;
		case 55:
			output = 157;
			break;
		case 136:
			output = 157;
			break;
		case 19:
			output = 157;
			break;
		case 100:
			output = 157;
			break;
		case 73:
			output = 157;
			break;
		case 154:
			output = 157;
			break;
		case 4:
			output = 157;
			break;
		case 85:
			output = 157;
			break;
		case 58:
			output = 157;
			break;
		case 139:
			output = 157;
			break;
		case 22:
			output = 157;
			break;
		case 103:
			output = 157;
			break;
		case 76:
			output = 157;
			break;
		case 157:
			output = 157;
			break;
		}
		break;
	case 158:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 3:
			output = 156;
			break;
		case 84:
			output = 156;
			break;
		case 57:
			output = 156;
			break;
		case 138:
			output = 156;
			break;
		case 21:
			output = 156;
			break;
		case 102:
			output = 156;
			break;
		case 75:
			output = 156;
			break;
		case 156:
			output = 156;
			break;
		case 2:
			output = 158;
			break;
		case 83:
			output = 158;
			break;
		case 56:
			output = 158;
			break;
		case 137:
			output = 158;
			break;
		case 20:
			output = 158;
			break;
		case 101:
			output = 158;
			break;
		case 74:
			output = 158;
			break;
		case 155:
			output = 158;
			break;
		case 5:
			output = 158;
			break;
		case 86:
			output = 158;
			break;
		case 59:
			output = 158;
			break;
		case 140:
			output = 158;
			break;
		case 23:
			output = 158;
			break;
		case 104:
			output = 158;
			break;
		case 77:
			output = 158;
			break;
		case 158:
			output = 158;
			break;
		}
		break;
	case 159:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 6:
			output = 159;
			break;
		case 87:
			output = 159;
			break;
		case 60:
			output = 159;
			break;
		case 141:
			output = 159;
			break;
		case 24:
			output = 159;
			break;
		case 105:
			output = 159;
			break;
		case 78:
			output = 159;
			break;
		case 159:
			output = 159;
			break;
		}
		break;
	case 160:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 6:
			output = 159;
			break;
		case 87:
			output = 159;
			break;
		case 60:
			output = 159;
			break;
		case 141:
			output = 159;
			break;
		case 24:
			output = 159;
			break;
		case 105:
			output = 159;
			break;
		case 78:
			output = 159;
			break;
		case 159:
			output = 159;
			break;
		case 1:
			output = 160;
			break;
		case 82:
			output = 160;
			break;
		case 55:
			output = 160;
			break;
		case 136:
			output = 160;
			break;
		case 19:
			output = 160;
			break;
		case 100:
			output = 160;
			break;
		case 73:
			output = 160;
			break;
		case 154:
			output = 160;
			break;
		case 7:
			output = 160;
			break;
		case 88:
			output = 160;
			break;
		case 61:
			output = 160;
			break;
		case 142:
			output = 160;
			break;
		case 25:
			output = 160;
			break;
		case 106:
			output = 160;
			break;
		case 79:
			output = 160;
			break;
		case 160:
			output = 160;
			break;
		}
		break;
	case 161:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 81:
			output = 81;
			break;
		case 54:
			output = 135;
			break;
		case 135:
			output = 135;
			break;
		case 18:
			output = 153;
			break;
		case 99:
			output = 153;
			break;
		case 72:
			output = 153;
			break;
		case 153:
			output = 153;
			break;
		case 6:
			output = 159;
			break;
		case 87:
			output = 159;
			break;
		case 60:
			output = 159;
			break;
		case 141:
			output = 159;
			break;
		case 24:
			output = 159;
			break;
		case 105:
			output = 159;
			break;
		case 78:
			output = 159;
			break;
		case 159:
			output = 159;
			break;
		case 2:
			output = 161;
			break;
		case 83:
			output = 161;
			break;
		case 56:
			output = 161;
			break;
		case 137:
			output = 161;
			break;
		case 20:
			output = 161;
			break;
		case 101:
			output = 161;
			break;
		case 74:
			output = 161;
			break;
		case 155:
			output = 161;
			break;
		case 8:
			output = 161;
			break;
		case 89:
			output = 161;
			break;
		case 62:
			output = 161;
			break;
		case 143:
			output = 161;
			break;
		case 26:
			output = 161;
			break;
		case 107:
			output = 161;
			break;
		case 80:
			output = 161;
			break;
		case 161:
			output = 161;
			break;
		}
		break;
	case 162:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		}
		break;
	case 163:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 1:
			output = 163;
			break;
		case 163:
			output = 163;
			break;
		}
		break;
	case 164:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 2:
			output = 164;
			break;
		case 164:
			output = 164;
			break;
		}
		break;
	case 165:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 3:
			output = 165;
			break;
		case 165:
			output = 165;
			break;
		}
		break;
	case 166:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 3:
			output = 165;
			break;
		case 165:
			output = 165;
			break;
		case 1:
			output = 166;
			break;
		case 163:
			output = 166;
			break;
		case 4:
			output = 166;
			break;
		case 166:
			output = 166;
			break;
		}
		break;
	case 167:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 3:
			output = 165;
			break;
		case 165:
			output = 165;
			break;
		case 2:
			output = 167;
			break;
		case 164:
			output = 167;
			break;
		case 5:
			output = 167;
			break;
		case 167:
			output = 167;
			break;
		}
		break;
	case 168:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 6:
			output = 168;
			break;
		case 168:
			output = 168;
			break;
		}
		break;
	case 169:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 6:
			output = 168;
			break;
		case 168:
			output = 168;
			break;
		case 1:
			output = 169;
			break;
		case 163:
			output = 169;
			break;
		case 7:
			output = 169;
			break;
		case 169:
			output = 169;
			break;
		}
		break;
	case 170:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 6:
			output = 168;
			break;
		case 168:
			output = 168;
			break;
		case 2:
			output = 170;
			break;
		case 164:
			output = 170;
			break;
		case 8:
			output = 170;
			break;
		case 170:
			output = 170;
			break;
		}
		break;
	case 171:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		}
		break;
	case 172:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 1:
			output = 172;
			break;
		case 163:
			output = 172;
			break;
		case 10:
			output = 172;
			break;
		case 172:
			output = 172;
			break;
		}
		break;
	case 173:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 2:
			output = 173;
			break;
		case 164:
			output = 173;
			break;
		case 11:
			output = 173;
			break;
		case 173:
			output = 173;
			break;
		}
		break;
	case 174:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 3:
			output = 174;
			break;
		case 165:
			output = 174;
			break;
		case 12:
			output = 174;
			break;
		case 174:
			output = 174;
			break;
		}
		break;
	case 175:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 3:
			output = 174;
			break;
		case 165:
			output = 174;
			break;
		case 12:
			output = 174;
			break;
		case 174:
			output = 174;
			break;
		case 1:
			output = 175;
			break;
		case 163:
			output = 175;
			break;
		case 10:
			output = 175;
			break;
		case 172:
			output = 175;
			break;
		case 4:
			output = 175;
			break;
		case 166:
			output = 175;
			break;
		case 13:
			output = 175;
			break;
		case 175:
			output = 175;
			break;
		}
		break;
	case 176:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 3:
			output = 174;
			break;
		case 165:
			output = 174;
			break;
		case 12:
			output = 174;
			break;
		case 174:
			output = 174;
			break;
		case 2:
			output = 176;
			break;
		case 164:
			output = 176;
			break;
		case 11:
			output = 176;
			break;
		case 173:
			output = 176;
			break;
		case 5:
			output = 176;
			break;
		case 167:
			output = 176;
			break;
		case 14:
			output = 176;
			break;
		case 176:
			output = 176;
			break;
		}
		break;
	case 177:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 6:
			output = 177;
			break;
		case 168:
			output = 177;
			break;
		case 15:
			output = 177;
			break;
		case 177:
			output = 177;
			break;
		}
		break;
	case 178:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 6:
			output = 177;
			break;
		case 168:
			output = 177;
			break;
		case 15:
			output = 177;
			break;
		case 177:
			output = 177;
			break;
		case 1:
			output = 178;
			break;
		case 163:
			output = 178;
			break;
		case 10:
			output = 178;
			break;
		case 172:
			output = 178;
			break;
		case 7:
			output = 178;
			break;
		case 169:
			output = 178;
			break;
		case 16:
			output = 178;
			break;
		case 178:
			output = 178;
			break;
		}
		break;
	case 179:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 9:
			output = 171;
			break;
		case 171:
			output = 171;
			break;
		case 6:
			output = 177;
			break;
		case 168:
			output = 177;
			break;
		case 15:
			output = 177;
			break;
		case 177:
			output = 177;
			break;
		case 2:
			output = 179;
			break;
		case 164:
			output = 179;
			break;
		case 11:
			output = 179;
			break;
		case 173:
			output = 179;
			break;
		case 8:
			output = 179;
			break;
		case 170:
			output = 179;
			break;
		case 17:
			output = 179;
			break;
		case 179:
			output = 179;
			break;
		}
		break;
	case 180:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		}
		break;
	case 181:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 1:
			output = 181;
			break;
		case 163:
			output = 181;
			break;
		case 19:
			output = 181;
			break;
		case 181:
			output = 181;
			break;
		}
		break;
	case 182:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 2:
			output = 182;
			break;
		case 164:
			output = 182;
			break;
		case 20:
			output = 182;
			break;
		case 182:
			output = 182;
			break;
		}
		break;
	case 183:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 3:
			output = 183;
			break;
		case 165:
			output = 183;
			break;
		case 21:
			output = 183;
			break;
		case 183:
			output = 183;
			break;
		}
		break;
	case 184:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 3:
			output = 183;
			break;
		case 165:
			output = 183;
			break;
		case 21:
			output = 183;
			break;
		case 183:
			output = 183;
			break;
		case 1:
			output = 184;
			break;
		case 163:
			output = 184;
			break;
		case 19:
			output = 184;
			break;
		case 181:
			output = 184;
			break;
		case 4:
			output = 184;
			break;
		case 166:
			output = 184;
			break;
		case 22:
			output = 184;
			break;
		case 184:
			output = 184;
			break;
		}
		break;
	case 185:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 3:
			output = 183;
			break;
		case 165:
			output = 183;
			break;
		case 21:
			output = 183;
			break;
		case 183:
			output = 183;
			break;
		case 2:
			output = 185;
			break;
		case 164:
			output = 185;
			break;
		case 20:
			output = 185;
			break;
		case 182:
			output = 185;
			break;
		case 5:
			output = 185;
			break;
		case 167:
			output = 185;
			break;
		case 23:
			output = 185;
			break;
		case 185:
			output = 185;
			break;
		}
		break;
	case 186:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 6:
			output = 186;
			break;
		case 168:
			output = 186;
			break;
		case 24:
			output = 186;
			break;
		case 186:
			output = 186;
			break;
		}
		break;
	case 187:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 6:
			output = 186;
			break;
		case 168:
			output = 186;
			break;
		case 24:
			output = 186;
			break;
		case 186:
			output = 186;
			break;
		case 1:
			output = 187;
			break;
		case 163:
			output = 187;
			break;
		case 19:
			output = 187;
			break;
		case 181:
			output = 187;
			break;
		case 7:
			output = 187;
			break;
		case 169:
			output = 187;
			break;
		case 25:
			output = 187;
			break;
		case 187:
			output = 187;
			break;
		}
		break;
	case 188:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 18:
			output = 180;
			break;
		case 180:
			output = 180;
			break;
		case 6:
			output = 186;
			break;
		case 168:
			output = 186;
			break;
		case 24:
			output = 186;
			break;
		case 186:
			output = 186;
			break;
		case 2:
			output = 188;
			break;
		case 164:
			output = 188;
			break;
		case 20:
			output = 188;
			break;
		case 182:
			output = 188;
			break;
		case 8:
			output = 188;
			break;
		case 170:
			output = 188;
			break;
		case 26:
			output = 188;
			break;
		case 188:
			output = 188;
			break;
		}
		break;
	case 189:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		}
		break;
	case 190:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 1:
			output = 190;
			break;
		case 163:
			output = 190;
			break;
		case 28:
			output = 190;
			break;
		case 190:
			output = 190;
			break;
		}
		break;
	case 191:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 2:
			output = 191;
			break;
		case 164:
			output = 191;
			break;
		case 29:
			output = 191;
			break;
		case 191:
			output = 191;
			break;
		}
		break;
	case 192:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 3:
			output = 192;
			break;
		case 165:
			output = 192;
			break;
		case 30:
			output = 192;
			break;
		case 192:
			output = 192;
			break;
		}
		break;
	case 193:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 3:
			output = 192;
			break;
		case 165:
			output = 192;
			break;
		case 30:
			output = 192;
			break;
		case 192:
			output = 192;
			break;
		case 1:
			output = 193;
			break;
		case 163:
			output = 193;
			break;
		case 28:
			output = 193;
			break;
		case 190:
			output = 193;
			break;
		case 4:
			output = 193;
			break;
		case 166:
			output = 193;
			break;
		case 31:
			output = 193;
			break;
		case 193:
			output = 193;
			break;
		}
		break;
	case 194:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 3:
			output = 192;
			break;
		case 165:
			output = 192;
			break;
		case 30:
			output = 192;
			break;
		case 192:
			output = 192;
			break;
		case 2:
			output = 194;
			break;
		case 164:
			output = 194;
			break;
		case 29:
			output = 194;
			break;
		case 191:
			output = 194;
			break;
		case 5:
			output = 194;
			break;
		case 167:
			output = 194;
			break;
		case 32:
			output = 194;
			break;
		case 194:
			output = 194;
			break;
		}
		break;
	case 195:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 6:
			output = 195;
			break;
		case 168:
			output = 195;
			break;
		case 33:
			output = 195;
			break;
		case 195:
			output = 195;
			break;
		}
		break;
	case 196:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 6:
			output = 195;
			break;
		case 168:
			output = 195;
			break;
		case 33:
			output = 195;
			break;
		case 195:
			output = 195;
			break;
		case 1:
			output = 196;
			break;
		case 163:
			output = 196;
			break;
		case 28:
			output = 196;
			break;
		case 190:
			output = 196;
			break;
		case 7:
			output = 196;
			break;
		case 169:
			output = 196;
			break;
		case 34:
			output = 196;
			break;
		case 196:
			output = 196;
			break;
		}
		break;
	case 197:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 6:
			output = 195;
			break;
		case 168:
			output = 195;
			break;
		case 33:
			output = 195;
			break;
		case 195:
			output = 195;
			break;
		case 2:
			output = 197;
			break;
		case 164:
			output = 197;
			break;
		case 29:
			output = 197;
			break;
		case 191:
			output = 197;
			break;
		case 8:
			output = 197;
			break;
		case 170:
			output = 197;
			break;
		case 35:
			output = 197;
			break;
		case 197:
			output = 197;
			break;
		}
		break;
	case 198:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		}
		break;
	case 199:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 1:
			output = 199;
			break;
		case 163:
			output = 199;
			break;
		case 28:
			output = 199;
			break;
		case 190:
			output = 199;
			break;
		case 10:
			output = 199;
			break;
		case 172:
			output = 199;
			break;
		case 37:
			output = 199;
			break;
		case 199:
			output = 199;
			break;
		}
		break;
	case 200:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 2:
			output = 200;
			break;
		case 164:
			output = 200;
			break;
		case 29:
			output = 200;
			break;
		case 191:
			output = 200;
			break;
		case 11:
			output = 200;
			break;
		case 173:
			output = 200;
			break;
		case 38:
			output = 200;
			break;
		case 200:
			output = 200;
			break;
		}
		break;
	case 201:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 3:
			output = 201;
			break;
		case 165:
			output = 201;
			break;
		case 30:
			output = 201;
			break;
		case 192:
			output = 201;
			break;
		case 12:
			output = 201;
			break;
		case 174:
			output = 201;
			break;
		case 39:
			output = 201;
			break;
		case 201:
			output = 201;
			break;
		}
		break;
	case 202:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 3:
			output = 201;
			break;
		case 165:
			output = 201;
			break;
		case 30:
			output = 201;
			break;
		case 192:
			output = 201;
			break;
		case 12:
			output = 201;
			break;
		case 174:
			output = 201;
			break;
		case 39:
			output = 201;
			break;
		case 201:
			output = 201;
			break;
		case 1:
			output = 202;
			break;
		case 163:
			output = 202;
			break;
		case 28:
			output = 202;
			break;
		case 190:
			output = 202;
			break;
		case 10:
			output = 202;
			break;
		case 172:
			output = 202;
			break;
		case 37:
			output = 202;
			break;
		case 199:
			output = 202;
			break;
		case 4:
			output = 202;
			break;
		case 166:
			output = 202;
			break;
		case 31:
			output = 202;
			break;
		case 193:
			output = 202;
			break;
		case 13:
			output = 202;
			break;
		case 175:
			output = 202;
			break;
		case 40:
			output = 202;
			break;
		case 202:
			output = 202;
			break;
		}
		break;
	case 203:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 3:
			output = 201;
			break;
		case 165:
			output = 201;
			break;
		case 30:
			output = 201;
			break;
		case 192:
			output = 201;
			break;
		case 12:
			output = 201;
			break;
		case 174:
			output = 201;
			break;
		case 39:
			output = 201;
			break;
		case 201:
			output = 201;
			break;
		case 2:
			output = 203;
			break;
		case 164:
			output = 203;
			break;
		case 29:
			output = 203;
			break;
		case 191:
			output = 203;
			break;
		case 11:
			output = 203;
			break;
		case 173:
			output = 203;
			break;
		case 38:
			output = 203;
			break;
		case 200:
			output = 203;
			break;
		case 5:
			output = 203;
			break;
		case 167:
			output = 203;
			break;
		case 32:
			output = 203;
			break;
		case 194:
			output = 203;
			break;
		case 14:
			output = 203;
			break;
		case 176:
			output = 203;
			break;
		case 41:
			output = 203;
			break;
		case 203:
			output = 203;
			break;
		}
		break;
	case 204:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 6:
			output = 204;
			break;
		case 168:
			output = 204;
			break;
		case 33:
			output = 204;
			break;
		case 195:
			output = 204;
			break;
		case 15:
			output = 204;
			break;
		case 177:
			output = 204;
			break;
		case 42:
			output = 204;
			break;
		case 204:
			output = 204;
			break;
		}
		break;
	case 205:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 6:
			output = 204;
			break;
		case 168:
			output = 204;
			break;
		case 33:
			output = 204;
			break;
		case 195:
			output = 204;
			break;
		case 15:
			output = 204;
			break;
		case 177:
			output = 204;
			break;
		case 42:
			output = 204;
			break;
		case 204:
			output = 204;
			break;
		case 1:
			output = 205;
			break;
		case 163:
			output = 205;
			break;
		case 28:
			output = 205;
			break;
		case 190:
			output = 205;
			break;
		case 10:
			output = 205;
			break;
		case 172:
			output = 205;
			break;
		case 37:
			output = 205;
			break;
		case 199:
			output = 205;
			break;
		case 7:
			output = 205;
			break;
		case 169:
			output = 205;
			break;
		case 34:
			output = 205;
			break;
		case 196:
			output = 205;
			break;
		case 16:
			output = 205;
			break;
		case 178:
			output = 205;
			break;
		case 43:
			output = 205;
			break;
		case 205:
			output = 205;
			break;
		}
		break;
	case 206:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 9:
			output = 198;
			break;
		case 171:
			output = 198;
			break;
		case 36:
			output = 198;
			break;
		case 198:
			output = 198;
			break;
		case 6:
			output = 204;
			break;
		case 168:
			output = 204;
			break;
		case 33:
			output = 204;
			break;
		case 195:
			output = 204;
			break;
		case 15:
			output = 204;
			break;
		case 177:
			output = 204;
			break;
		case 42:
			output = 204;
			break;
		case 204:
			output = 204;
			break;
		case 2:
			output = 206;
			break;
		case 164:
			output = 206;
			break;
		case 29:
			output = 206;
			break;
		case 191:
			output = 206;
			break;
		case 11:
			output = 206;
			break;
		case 173:
			output = 206;
			break;
		case 38:
			output = 206;
			break;
		case 200:
			output = 206;
			break;
		case 8:
			output = 206;
			break;
		case 170:
			output = 206;
			break;
		case 35:
			output = 206;
			break;
		case 197:
			output = 206;
			break;
		case 17:
			output = 206;
			break;
		case 179:
			output = 206;
			break;
		case 44:
			output = 206;
			break;
		case 206:
			output = 206;
			break;
		}
		break;
	case 207:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		}
		break;
	case 208:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 1:
			output = 208;
			break;
		case 163:
			output = 208;
			break;
		case 28:
			output = 208;
			break;
		case 190:
			output = 208;
			break;
		case 19:
			output = 208;
			break;
		case 181:
			output = 208;
			break;
		case 46:
			output = 208;
			break;
		case 208:
			output = 208;
			break;
		}
		break;
	case 209:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 2:
			output = 209;
			break;
		case 164:
			output = 209;
			break;
		case 29:
			output = 209;
			break;
		case 191:
			output = 209;
			break;
		case 20:
			output = 209;
			break;
		case 182:
			output = 209;
			break;
		case 47:
			output = 209;
			break;
		case 209:
			output = 209;
			break;
		}
		break;
	case 210:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 3:
			output = 210;
			break;
		case 165:
			output = 210;
			break;
		case 30:
			output = 210;
			break;
		case 192:
			output = 210;
			break;
		case 21:
			output = 210;
			break;
		case 183:
			output = 210;
			break;
		case 48:
			output = 210;
			break;
		case 210:
			output = 210;
			break;
		}
		break;
	case 211:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 3:
			output = 210;
			break;
		case 165:
			output = 210;
			break;
		case 30:
			output = 210;
			break;
		case 192:
			output = 210;
			break;
		case 21:
			output = 210;
			break;
		case 183:
			output = 210;
			break;
		case 48:
			output = 210;
			break;
		case 210:
			output = 210;
			break;
		case 1:
			output = 211;
			break;
		case 163:
			output = 211;
			break;
		case 28:
			output = 211;
			break;
		case 190:
			output = 211;
			break;
		case 19:
			output = 211;
			break;
		case 181:
			output = 211;
			break;
		case 46:
			output = 211;
			break;
		case 208:
			output = 211;
			break;
		case 4:
			output = 211;
			break;
		case 166:
			output = 211;
			break;
		case 31:
			output = 211;
			break;
		case 193:
			output = 211;
			break;
		case 22:
			output = 211;
			break;
		case 184:
			output = 211;
			break;
		case 49:
			output = 211;
			break;
		case 211:
			output = 211;
			break;
		}
		break;
	case 212:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 3:
			output = 210;
			break;
		case 165:
			output = 210;
			break;
		case 30:
			output = 210;
			break;
		case 192:
			output = 210;
			break;
		case 21:
			output = 210;
			break;
		case 183:
			output = 210;
			break;
		case 48:
			output = 210;
			break;
		case 210:
			output = 210;
			break;
		case 2:
			output = 212;
			break;
		case 164:
			output = 212;
			break;
		case 29:
			output = 212;
			break;
		case 191:
			output = 212;
			break;
		case 20:
			output = 212;
			break;
		case 182:
			output = 212;
			break;
		case 47:
			output = 212;
			break;
		case 209:
			output = 212;
			break;
		case 5:
			output = 212;
			break;
		case 167:
			output = 212;
			break;
		case 32:
			output = 212;
			break;
		case 194:
			output = 212;
			break;
		case 23:
			output = 212;
			break;
		case 185:
			output = 212;
			break;
		case 50:
			output = 212;
			break;
		case 212:
			output = 212;
			break;
		}
		break;
	case 213:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 6:
			output = 213;
			break;
		case 168:
			output = 213;
			break;
		case 33:
			output = 213;
			break;
		case 195:
			output = 213;
			break;
		case 24:
			output = 213;
			break;
		case 186:
			output = 213;
			break;
		case 51:
			output = 213;
			break;
		case 213:
			output = 213;
			break;
		}
		break;
	case 214:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 6:
			output = 213;
			break;
		case 168:
			output = 213;
			break;
		case 33:
			output = 213;
			break;
		case 195:
			output = 213;
			break;
		case 24:
			output = 213;
			break;
		case 186:
			output = 213;
			break;
		case 51:
			output = 213;
			break;
		case 213:
			output = 213;
			break;
		case 1:
			output = 214;
			break;
		case 163:
			output = 214;
			break;
		case 28:
			output = 214;
			break;
		case 190:
			output = 214;
			break;
		case 19:
			output = 214;
			break;
		case 181:
			output = 214;
			break;
		case 46:
			output = 214;
			break;
		case 208:
			output = 214;
			break;
		case 7:
			output = 214;
			break;
		case 169:
			output = 214;
			break;
		case 34:
			output = 214;
			break;
		case 196:
			output = 214;
			break;
		case 25:
			output = 214;
			break;
		case 187:
			output = 214;
			break;
		case 52:
			output = 214;
			break;
		case 214:
			output = 214;
			break;
		}
		break;
	case 215:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 27:
			output = 189;
			break;
		case 189:
			output = 189;
			break;
		case 18:
			output = 207;
			break;
		case 180:
			output = 207;
			break;
		case 45:
			output = 207;
			break;
		case 207:
			output = 207;
			break;
		case 6:
			output = 213;
			break;
		case 168:
			output = 213;
			break;
		case 33:
			output = 213;
			break;
		case 195:
			output = 213;
			break;
		case 24:
			output = 213;
			break;
		case 186:
			output = 213;
			break;
		case 51:
			output = 213;
			break;
		case 213:
			output = 213;
			break;
		case 2:
			output = 215;
			break;
		case 164:
			output = 215;
			break;
		case 29:
			output = 215;
			break;
		case 191:
			output = 215;
			break;
		case 20:
			output = 215;
			break;
		case 182:
			output = 215;
			break;
		case 47:
			output = 215;
			break;
		case 209:
			output = 215;
			break;
		case 8:
			output = 215;
			break;
		case 170:
			output = 215;
			break;
		case 35:
			output = 215;
			break;
		case 197:
			output = 215;
			break;
		case 26:
			output = 215;
			break;
		case 188:
			output = 215;
			break;
		case 53:
			output = 215;
			break;
		case 215:
			output = 215;
			break;
		}
		break;
	case 216:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		}
		break;
	case 217:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 1:
			output = 217;
			break;
		case 163:
			output = 217;
			break;
		case 55:
			output = 217;
			break;
		case 217:
			output = 217;
			break;
		}
		break;
	case 218:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 2:
			output = 218;
			break;
		case 164:
			output = 218;
			break;
		case 56:
			output = 218;
			break;
		case 218:
			output = 218;
			break;
		}
		break;
	case 219:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 3:
			output = 219;
			break;
		case 165:
			output = 219;
			break;
		case 57:
			output = 219;
			break;
		case 219:
			output = 219;
			break;
		}
		break;
	case 220:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 3:
			output = 219;
			break;
		case 165:
			output = 219;
			break;
		case 57:
			output = 219;
			break;
		case 219:
			output = 219;
			break;
		case 1:
			output = 220;
			break;
		case 163:
			output = 220;
			break;
		case 55:
			output = 220;
			break;
		case 217:
			output = 220;
			break;
		case 4:
			output = 220;
			break;
		case 166:
			output = 220;
			break;
		case 58:
			output = 220;
			break;
		case 220:
			output = 220;
			break;
		}
		break;
	case 221:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 3:
			output = 219;
			break;
		case 165:
			output = 219;
			break;
		case 57:
			output = 219;
			break;
		case 219:
			output = 219;
			break;
		case 2:
			output = 221;
			break;
		case 164:
			output = 221;
			break;
		case 56:
			output = 221;
			break;
		case 218:
			output = 221;
			break;
		case 5:
			output = 221;
			break;
		case 167:
			output = 221;
			break;
		case 59:
			output = 221;
			break;
		case 221:
			output = 221;
			break;
		}
		break;
	case 222:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 6:
			output = 222;
			break;
		case 168:
			output = 222;
			break;
		case 60:
			output = 222;
			break;
		case 222:
			output = 222;
			break;
		}
		break;
	case 223:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 6:
			output = 222;
			break;
		case 168:
			output = 222;
			break;
		case 60:
			output = 222;
			break;
		case 222:
			output = 222;
			break;
		case 1:
			output = 223;
			break;
		case 163:
			output = 223;
			break;
		case 55:
			output = 223;
			break;
		case 217:
			output = 223;
			break;
		case 7:
			output = 223;
			break;
		case 169:
			output = 223;
			break;
		case 61:
			output = 223;
			break;
		case 223:
			output = 223;
			break;
		}
		break;
	case 224:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 6:
			output = 222;
			break;
		case 168:
			output = 222;
			break;
		case 60:
			output = 222;
			break;
		case 222:
			output = 222;
			break;
		case 2:
			output = 224;
			break;
		case 164:
			output = 224;
			break;
		case 56:
			output = 224;
			break;
		case 218:
			output = 224;
			break;
		case 8:
			output = 224;
			break;
		case 170:
			output = 224;
			break;
		case 62:
			output = 224;
			break;
		case 224:
			output = 224;
			break;
		}
		break;
	case 225:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		}
		break;
	case 226:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 1:
			output = 226;
			break;
		case 163:
			output = 226;
			break;
		case 55:
			output = 226;
			break;
		case 217:
			output = 226;
			break;
		case 10:
			output = 226;
			break;
		case 172:
			output = 226;
			break;
		case 64:
			output = 226;
			break;
		case 226:
			output = 226;
			break;
		}
		break;
	case 227:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 2:
			output = 227;
			break;
		case 164:
			output = 227;
			break;
		case 56:
			output = 227;
			break;
		case 218:
			output = 227;
			break;
		case 11:
			output = 227;
			break;
		case 173:
			output = 227;
			break;
		case 65:
			output = 227;
			break;
		case 227:
			output = 227;
			break;
		}
		break;
	case 228:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 3:
			output = 228;
			break;
		case 165:
			output = 228;
			break;
		case 57:
			output = 228;
			break;
		case 219:
			output = 228;
			break;
		case 12:
			output = 228;
			break;
		case 174:
			output = 228;
			break;
		case 66:
			output = 228;
			break;
		case 228:
			output = 228;
			break;
		}
		break;
	case 229:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 3:
			output = 228;
			break;
		case 165:
			output = 228;
			break;
		case 57:
			output = 228;
			break;
		case 219:
			output = 228;
			break;
		case 12:
			output = 228;
			break;
		case 174:
			output = 228;
			break;
		case 66:
			output = 228;
			break;
		case 228:
			output = 228;
			break;
		case 1:
			output = 229;
			break;
		case 163:
			output = 229;
			break;
		case 55:
			output = 229;
			break;
		case 217:
			output = 229;
			break;
		case 10:
			output = 229;
			break;
		case 172:
			output = 229;
			break;
		case 64:
			output = 229;
			break;
		case 226:
			output = 229;
			break;
		case 4:
			output = 229;
			break;
		case 166:
			output = 229;
			break;
		case 58:
			output = 229;
			break;
		case 220:
			output = 229;
			break;
		case 13:
			output = 229;
			break;
		case 175:
			output = 229;
			break;
		case 67:
			output = 229;
			break;
		case 229:
			output = 229;
			break;
		}
		break;
	case 230:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 3:
			output = 228;
			break;
		case 165:
			output = 228;
			break;
		case 57:
			output = 228;
			break;
		case 219:
			output = 228;
			break;
		case 12:
			output = 228;
			break;
		case 174:
			output = 228;
			break;
		case 66:
			output = 228;
			break;
		case 228:
			output = 228;
			break;
		case 2:
			output = 230;
			break;
		case 164:
			output = 230;
			break;
		case 56:
			output = 230;
			break;
		case 218:
			output = 230;
			break;
		case 11:
			output = 230;
			break;
		case 173:
			output = 230;
			break;
		case 65:
			output = 230;
			break;
		case 227:
			output = 230;
			break;
		case 5:
			output = 230;
			break;
		case 167:
			output = 230;
			break;
		case 59:
			output = 230;
			break;
		case 221:
			output = 230;
			break;
		case 14:
			output = 230;
			break;
		case 176:
			output = 230;
			break;
		case 68:
			output = 230;
			break;
		case 230:
			output = 230;
			break;
		}
		break;
	case 231:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 6:
			output = 231;
			break;
		case 168:
			output = 231;
			break;
		case 60:
			output = 231;
			break;
		case 222:
			output = 231;
			break;
		case 15:
			output = 231;
			break;
		case 177:
			output = 231;
			break;
		case 69:
			output = 231;
			break;
		case 231:
			output = 231;
			break;
		}
		break;
	case 232:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 6:
			output = 231;
			break;
		case 168:
			output = 231;
			break;
		case 60:
			output = 231;
			break;
		case 222:
			output = 231;
			break;
		case 15:
			output = 231;
			break;
		case 177:
			output = 231;
			break;
		case 69:
			output = 231;
			break;
		case 231:
			output = 231;
			break;
		case 1:
			output = 232;
			break;
		case 163:
			output = 232;
			break;
		case 55:
			output = 232;
			break;
		case 217:
			output = 232;
			break;
		case 10:
			output = 232;
			break;
		case 172:
			output = 232;
			break;
		case 64:
			output = 232;
			break;
		case 226:
			output = 232;
			break;
		case 7:
			output = 232;
			break;
		case 169:
			output = 232;
			break;
		case 61:
			output = 232;
			break;
		case 223:
			output = 232;
			break;
		case 16:
			output = 232;
			break;
		case 178:
			output = 232;
			break;
		case 70:
			output = 232;
			break;
		case 232:
			output = 232;
			break;
		}
		break;
	case 233:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 9:
			output = 225;
			break;
		case 171:
			output = 225;
			break;
		case 63:
			output = 225;
			break;
		case 225:
			output = 225;
			break;
		case 6:
			output = 231;
			break;
		case 168:
			output = 231;
			break;
		case 60:
			output = 231;
			break;
		case 222:
			output = 231;
			break;
		case 15:
			output = 231;
			break;
		case 177:
			output = 231;
			break;
		case 69:
			output = 231;
			break;
		case 231:
			output = 231;
			break;
		case 2:
			output = 233;
			break;
		case 164:
			output = 233;
			break;
		case 56:
			output = 233;
			break;
		case 218:
			output = 233;
			break;
		case 11:
			output = 233;
			break;
		case 173:
			output = 233;
			break;
		case 65:
			output = 233;
			break;
		case 227:
			output = 233;
			break;
		case 8:
			output = 233;
			break;
		case 170:
			output = 233;
			break;
		case 62:
			output = 233;
			break;
		case 224:
			output = 233;
			break;
		case 17:
			output = 233;
			break;
		case 179:
			output = 233;
			break;
		case 71:
			output = 233;
			break;
		case 233:
			output = 233;
			break;
		}
		break;
	case 234:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		}
		break;
	case 235:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 1:
			output = 235;
			break;
		case 163:
			output = 235;
			break;
		case 55:
			output = 235;
			break;
		case 217:
			output = 235;
			break;
		case 19:
			output = 235;
			break;
		case 181:
			output = 235;
			break;
		case 73:
			output = 235;
			break;
		case 235:
			output = 235;
			break;
		}
		break;
	case 236:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 2:
			output = 236;
			break;
		case 164:
			output = 236;
			break;
		case 56:
			output = 236;
			break;
		case 218:
			output = 236;
			break;
		case 20:
			output = 236;
			break;
		case 182:
			output = 236;
			break;
		case 74:
			output = 236;
			break;
		case 236:
			output = 236;
			break;
		}
		break;
	case 237:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 3:
			output = 237;
			break;
		case 165:
			output = 237;
			break;
		case 57:
			output = 237;
			break;
		case 219:
			output = 237;
			break;
		case 21:
			output = 237;
			break;
		case 183:
			output = 237;
			break;
		case 75:
			output = 237;
			break;
		case 237:
			output = 237;
			break;
		}
		break;
	case 238:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 3:
			output = 237;
			break;
		case 165:
			output = 237;
			break;
		case 57:
			output = 237;
			break;
		case 219:
			output = 237;
			break;
		case 21:
			output = 237;
			break;
		case 183:
			output = 237;
			break;
		case 75:
			output = 237;
			break;
		case 237:
			output = 237;
			break;
		case 1:
			output = 238;
			break;
		case 163:
			output = 238;
			break;
		case 55:
			output = 238;
			break;
		case 217:
			output = 238;
			break;
		case 19:
			output = 238;
			break;
		case 181:
			output = 238;
			break;
		case 73:
			output = 238;
			break;
		case 235:
			output = 238;
			break;
		case 4:
			output = 238;
			break;
		case 166:
			output = 238;
			break;
		case 58:
			output = 238;
			break;
		case 220:
			output = 238;
			break;
		case 22:
			output = 238;
			break;
		case 184:
			output = 238;
			break;
		case 76:
			output = 238;
			break;
		case 238:
			output = 238;
			break;
		}
		break;
	case 239:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 3:
			output = 237;
			break;
		case 165:
			output = 237;
			break;
		case 57:
			output = 237;
			break;
		case 219:
			output = 237;
			break;
		case 21:
			output = 237;
			break;
		case 183:
			output = 237;
			break;
		case 75:
			output = 237;
			break;
		case 237:
			output = 237;
			break;
		case 2:
			output = 239;
			break;
		case 164:
			output = 239;
			break;
		case 56:
			output = 239;
			break;
		case 218:
			output = 239;
			break;
		case 20:
			output = 239;
			break;
		case 182:
			output = 239;
			break;
		case 74:
			output = 239;
			break;
		case 236:
			output = 239;
			break;
		case 5:
			output = 239;
			break;
		case 167:
			output = 239;
			break;
		case 59:
			output = 239;
			break;
		case 221:
			output = 239;
			break;
		case 23:
			output = 239;
			break;
		case 185:
			output = 239;
			break;
		case 77:
			output = 239;
			break;
		case 239:
			output = 239;
			break;
		}
		break;
	case 240:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 6:
			output = 240;
			break;
		case 168:
			output = 240;
			break;
		case 60:
			output = 240;
			break;
		case 222:
			output = 240;
			break;
		case 24:
			output = 240;
			break;
		case 186:
			output = 240;
			break;
		case 78:
			output = 240;
			break;
		case 240:
			output = 240;
			break;
		}
		break;
	case 241:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 6:
			output = 240;
			break;
		case 168:
			output = 240;
			break;
		case 60:
			output = 240;
			break;
		case 222:
			output = 240;
			break;
		case 24:
			output = 240;
			break;
		case 186:
			output = 240;
			break;
		case 78:
			output = 240;
			break;
		case 240:
			output = 240;
			break;
		case 1:
			output = 241;
			break;
		case 163:
			output = 241;
			break;
		case 55:
			output = 241;
			break;
		case 217:
			output = 241;
			break;
		case 19:
			output = 241;
			break;
		case 181:
			output = 241;
			break;
		case 73:
			output = 241;
			break;
		case 235:
			output = 241;
			break;
		case 7:
			output = 241;
			break;
		case 169:
			output = 241;
			break;
		case 61:
			output = 241;
			break;
		case 223:
			output = 241;
			break;
		case 25:
			output = 241;
			break;
		case 187:
			output = 241;
			break;
		case 79:
			output = 241;
			break;
		case 241:
			output = 241;
			break;
		}
		break;
	case 242:
		switch(input2) {
		case 0:
			output = 0;
			break;
		case 162:
			output = 162;
			break;
		case 54:
			output = 216;
			break;
		case 216:
			output = 216;
			break;
		case 18:
			output = 234;
			break;
		case 180:
			output = 234;
			break;
		case 72:
			output = 234;
			break;
		case 234:
			output = 234;
			break;
		case 6:
			output = 240;
			break;
		case 168:
			output = 240;
			break;
		case 60:
			output = 240;
			break;
		case 222:
			output = 240;
			break;
		case 24:
			output = 240;
			break;
		case 186:
			output = 240;
			break;
		case 78:
			output = 240;
			break;
		case 240:
			output = 240;
			break;
		case 2:
			output = 242;
			break;
		case 164:
			output = 242;
			break;
		case 56:
			output = 242;
			break;
		case 218:
			output = 242;
			break;
		case 20:
			output = 242;
			break;
		case 182:
			output = 242;
			break;
		case 74:
			output = 242;
			break;
		case 236:
			output = 242;
			break;
		case 8:
			output = 242;
			break;
		case 170:
			output = 242;
			break;
		case 62:
			output = 242;
			break;
		case 224:
			output = 242;
			break;
		case 26:
			output = 242;
			break;
		case 188:
			output = 242;
			break;
		case 80:
			output = 242;
			break;
		case 242:
			output = 242;
			break;
		}
		break;
	}
}



void mergeBoxesCore(
      vector<int>& input1,
      vector<int>& input2,
      int& index
) {
   
   static constexpr int array[243][243] = {
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{1, 1, 1, 4, 4, 4, 7, 7, 7, 10, 10, 10, 13, 13, 13, 16, 16, 16, 19, 19, 19, 22, 22, 22, 25, 25, 25, 28, 28, 28, 31, 31, 31, 34, 34, 34, 37, 37, 37, 40, 40, 40, 43, 43, 43, 46, 46, 46, 49, 49, 49, 52, 52, 52, 55, 55, 55, 58, 58, 58, 61, 61, 61, 64, 64, 64, 67, 67, 67, 70, 70, 70, 73, 73, 73, 76, 76, 76, 79, 79, 79, 82, 82, 82, 85, 85, 85, 88, 88, 88, 91, 91, 91, 94, 94, 94, 97, 97, 97, 100, 100, 100, 103, 103, 103, 106, 106, 106, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 163, 163, 163, 166, 166, 166, 169, 169, 169, 172, 172, 172, 175, 175, 175, 178, 178, 178, 181, 181, 181, 184, 184, 184, 187, 187, 187, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{2, 2, 2, 5, 5, 5, 8, 8, 8, 11, 11, 11, 14, 14, 14, 17, 17, 17, 20, 20, 20, 23, 23, 23, 26, 26, 26, 29, 29, 29, 32, 32, 32, 35, 35, 35, 38, 38, 38, 41, 41, 41, 44, 44, 44, 47, 47, 47, 50, 50, 50, 53, 53, 53, 56, 56, 56, 59, 59, 59, 62, 62, 62, 65, 65, 65, 68, 68, 68, 71, 71, 71, 74, 74, 74, 77, 77, 77, 80, 80, 80, 83, 83, 83, 86, 86, 86, 89, 89, 89, 92, 92, 92, 95, 95, 95, 98, 98, 98, 101, 101, 101, 104, 104, 104, 107, 107, 107, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 164, 164, 164, 167, 167, 167, 170, 170, 170, 173, 173, 173, 176, 176, 176, 179, 179, 179, 182, 182, 182, 185, 185, 185, 188, 188, 188, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{3, 4, 5, 3, 4, 5, 3, 4, 5, 12, 13, 14, 12, 13, 14, 12, 13, 14, 21, 22, 23, 21, 22, 23, 21, 22, 23, 30, 31, 32, 30, 31, 32, 30, 31, 32, 39, 40, 41, 39, 40, 41, 39, 40, 41, 48, 49, 50, 48, 49, 50, 48, 49, 50, 57, 58, 59, 57, 58, 59, 57, 58, 59, 66, 67, 68, 66, 67, 68, 66, 67, 68, 75, 76, 77, 75, 76, 77, 75, 76, 77, 84, 85, 86, 84, 85, 86, 84, 85, 86, 93, 94, 95, 93, 94, 95, 93, 94, 95, 102, 103, 104, 102, 103, 104, 102, 103, 104, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 165, 166, 167, 165, 166, 167, 165, 166, 167, 174, 175, 176, 174, 175, 176, 174, 175, 176, 183, 184, 185, 183, 184, 185, 183, 184, 185, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 13, 13, 13, 13, 13, 13, 13, 13, 13, 22, 22, 22, 22, 22, 22, 22, 22, 22, 31, 31, 31, 31, 31, 31, 31, 31, 31, 40, 40, 40, 40, 40, 40, 40, 40, 40, 49, 49, 49, 49, 49, 49, 49, 49, 49, 58, 58, 58, 58, 58, 58, 58, 58, 58, 67, 67, 67, 67, 67, 67, 67, 67, 67, 76, 76, 76, 76, 76, 76, 76, 76, 76, 85, 85, 85, 85, 85, 85, 85, 85, 85, 94, 94, 94, 94, 94, 94, 94, 94, 94, 103, 103, 103, 103, 103, 103, 103, 103, 103, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 166, 166, 166, 166, 166, 166, 166, 166, 166, 175, 175, 175, 175, 175, 175, 175, 175, 175, 184, 184, 184, 184, 184, 184, 184, 184, 184, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{5, 5, 5, 5, 5, 5, 5, 5, 5, 14, 14, 14, 14, 14, 14, 14, 14, 14, 23, 23, 23, 23, 23, 23, 23, 23, 23, 32, 32, 32, 32, 32, 32, 32, 32, 32, 41, 41, 41, 41, 41, 41, 41, 41, 41, 50, 50, 50, 50, 50, 50, 50, 50, 50, 59, 59, 59, 59, 59, 59, 59, 59, 59, 68, 68, 68, 68, 68, 68, 68, 68, 68, 77, 77, 77, 77, 77, 77, 77, 77, 77, 86, 86, 86, 86, 86, 86, 86, 86, 86, 95, 95, 95, 95, 95, 95, 95, 95, 95, 104, 104, 104, 104, 104, 104, 104, 104, 104, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 167, 167, 167, 167, 167, 167, 167, 167, 167, 176, 176, 176, 176, 176, 176, 176, 176, 176, 185, 185, 185, 185, 185, 185, 185, 185, 185, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{6, 7, 8, 6, 7, 8, 6, 7, 8, 15, 16, 17, 15, 16, 17, 15, 16, 17, 24, 25, 26, 24, 25, 26, 24, 25, 26, 33, 34, 35, 33, 34, 35, 33, 34, 35, 42, 43, 44, 42, 43, 44, 42, 43, 44, 51, 52, 53, 51, 52, 53, 51, 52, 53, 60, 61, 62, 60, 61, 62, 60, 61, 62, 69, 70, 71, 69, 70, 71, 69, 70, 71, 78, 79, 80, 78, 79, 80, 78, 79, 80, 87, 88, 89, 87, 88, 89, 87, 88, 89, 96, 97, 98, 96, 97, 98, 96, 97, 98, 105, 106, 107, 105, 106, 107, 105, 106, 107, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 168, 169, 170, 168, 169, 170, 168, 169, 170, 177, 178, 179, 177, 178, 179, 177, 178, 179, 186, 187, 188, 186, 187, 188, 186, 187, 188, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{7, 7, 7, 7, 7, 7, 7, 7, 7, 16, 16, 16, 16, 16, 16, 16, 16, 16, 25, 25, 25, 25, 25, 25, 25, 25, 25, 34, 34, 34, 34, 34, 34, 34, 34, 34, 43, 43, 43, 43, 43, 43, 43, 43, 43, 52, 52, 52, 52, 52, 52, 52, 52, 52, 61, 61, 61, 61, 61, 61, 61, 61, 61, 70, 70, 70, 70, 70, 70, 70, 70, 70, 79, 79, 79, 79, 79, 79, 79, 79, 79, 88, 88, 88, 88, 88, 88, 88, 88, 88, 97, 97, 97, 97, 97, 97, 97, 97, 97, 106, 106, 106, 106, 106, 106, 106, 106, 106, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 169, 169, 169, 169, 169, 169, 169, 169, 169, 178, 178, 178, 178, 178, 178, 178, 178, 178, 187, 187, 187, 187, 187, 187, 187, 187, 187, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{8, 8, 8, 8, 8, 8, 8, 8, 8, 17, 17, 17, 17, 17, 17, 17, 17, 17, 26, 26, 26, 26, 26, 26, 26, 26, 26, 35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 53, 53, 53, 53, 53, 53, 53, 53, 53, 62, 62, 62, 62, 62, 62, 62, 62, 62, 71, 71, 71, 71, 71, 71, 71, 71, 71, 80, 80, 80, 80, 80, 80, 80, 80, 80, 89, 89, 89, 89, 89, 89, 89, 89, 89, 98, 98, 98, 98, 98, 98, 98, 98, 98, 107, 107, 107, 107, 107, 107, 107, 107, 107, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 170, 170, 170, 170, 170, 170, 170, 170, 170, 179, 179, 179, 179, 179, 179, 179, 179, 179, 188, 188, 188, 188, 188, 188, 188, 188, 188, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{9, 10, 11, 12, 13, 14, 15, 16, 17, 9, 10, 11, 12, 13, 14, 15, 16, 17, 9, 10, 11, 12, 13, 14, 15, 16, 17, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233},
		{10, 10, 10, 13, 13, 13, 16, 16, 16, 10, 10, 10, 13, 13, 13, 16, 16, 16, 10, 10, 10, 13, 13, 13, 16, 16, 16, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232},
		{11, 11, 11, 14, 14, 14, 17, 17, 17, 11, 11, 11, 14, 14, 14, 17, 17, 17, 11, 11, 11, 14, 14, 14, 17, 17, 17, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233},
		{12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 12, 13, 14, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230},
		{13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229},
		{14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230},
		{15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 15, 16, 17, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233},
		{16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232},
		{17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233},
		{18, 19, 20, 21, 22, 23, 24, 25, 26, 18, 19, 20, 21, 22, 23, 24, 25, 26, 18, 19, 20, 21, 22, 23, 24, 25, 26, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{19, 19, 19, 22, 22, 22, 25, 25, 25, 19, 19, 19, 22, 22, 22, 25, 25, 25, 19, 19, 19, 22, 22, 22, 25, 25, 25, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{20, 20, 20, 23, 23, 23, 26, 26, 26, 20, 20, 20, 23, 23, 23, 26, 26, 26, 20, 20, 20, 23, 23, 23, 26, 26, 26, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 21, 22, 23, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 22, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 24, 25, 26, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 25, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 26, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215},
		{28, 28, 28, 31, 31, 31, 34, 34, 34, 37, 37, 37, 40, 40, 40, 43, 43, 43, 46, 46, 46, 49, 49, 49, 52, 52, 52, 28, 28, 28, 31, 31, 31, 34, 34, 34, 37, 37, 37, 40, 40, 40, 43, 43, 43, 46, 46, 46, 49, 49, 49, 52, 52, 52, 28, 28, 28, 31, 31, 31, 34, 34, 34, 37, 37, 37, 40, 40, 40, 43, 43, 43, 46, 46, 46, 49, 49, 49, 52, 52, 52, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214},
		{29, 29, 29, 32, 32, 32, 35, 35, 35, 38, 38, 38, 41, 41, 41, 44, 44, 44, 47, 47, 47, 50, 50, 50, 53, 53, 53, 29, 29, 29, 32, 32, 32, 35, 35, 35, 38, 38, 38, 41, 41, 41, 44, 44, 44, 47, 47, 47, 50, 50, 50, 53, 53, 53, 29, 29, 29, 32, 32, 32, 35, 35, 35, 38, 38, 38, 41, 41, 41, 44, 44, 44, 47, 47, 47, 50, 50, 50, 53, 53, 53, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215},
		{30, 31, 32, 30, 31, 32, 30, 31, 32, 39, 40, 41, 39, 40, 41, 39, 40, 41, 48, 49, 50, 48, 49, 50, 48, 49, 50, 30, 31, 32, 30, 31, 32, 30, 31, 32, 39, 40, 41, 39, 40, 41, 39, 40, 41, 48, 49, 50, 48, 49, 50, 48, 49, 50, 30, 31, 32, 30, 31, 32, 30, 31, 32, 39, 40, 41, 39, 40, 41, 39, 40, 41, 48, 49, 50, 48, 49, 50, 48, 49, 50, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212},
		{31, 31, 31, 31, 31, 31, 31, 31, 31, 40, 40, 40, 40, 40, 40, 40, 40, 40, 49, 49, 49, 49, 49, 49, 49, 49, 49, 31, 31, 31, 31, 31, 31, 31, 31, 31, 40, 40, 40, 40, 40, 40, 40, 40, 40, 49, 49, 49, 49, 49, 49, 49, 49, 49, 31, 31, 31, 31, 31, 31, 31, 31, 31, 40, 40, 40, 40, 40, 40, 40, 40, 40, 49, 49, 49, 49, 49, 49, 49, 49, 49, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211},
		{32, 32, 32, 32, 32, 32, 32, 32, 32, 41, 41, 41, 41, 41, 41, 41, 41, 41, 50, 50, 50, 50, 50, 50, 50, 50, 50, 32, 32, 32, 32, 32, 32, 32, 32, 32, 41, 41, 41, 41, 41, 41, 41, 41, 41, 50, 50, 50, 50, 50, 50, 50, 50, 50, 32, 32, 32, 32, 32, 32, 32, 32, 32, 41, 41, 41, 41, 41, 41, 41, 41, 41, 50, 50, 50, 50, 50, 50, 50, 50, 50, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212},
		{33, 34, 35, 33, 34, 35, 33, 34, 35, 42, 43, 44, 42, 43, 44, 42, 43, 44, 51, 52, 53, 51, 52, 53, 51, 52, 53, 33, 34, 35, 33, 34, 35, 33, 34, 35, 42, 43, 44, 42, 43, 44, 42, 43, 44, 51, 52, 53, 51, 52, 53, 51, 52, 53, 33, 34, 35, 33, 34, 35, 33, 34, 35, 42, 43, 44, 42, 43, 44, 42, 43, 44, 51, 52, 53, 51, 52, 53, 51, 52, 53, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215},
		{34, 34, 34, 34, 34, 34, 34, 34, 34, 43, 43, 43, 43, 43, 43, 43, 43, 43, 52, 52, 52, 52, 52, 52, 52, 52, 52, 34, 34, 34, 34, 34, 34, 34, 34, 34, 43, 43, 43, 43, 43, 43, 43, 43, 43, 52, 52, 52, 52, 52, 52, 52, 52, 52, 34, 34, 34, 34, 34, 34, 34, 34, 34, 43, 43, 43, 43, 43, 43, 43, 43, 43, 52, 52, 52, 52, 52, 52, 52, 52, 52, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214},
		{35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 53, 53, 53, 53, 53, 53, 53, 53, 53, 35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 53, 53, 53, 53, 53, 53, 53, 53, 53, 35, 35, 35, 35, 35, 35, 35, 35, 35, 44, 44, 44, 44, 44, 44, 44, 44, 44, 53, 53, 53, 53, 53, 53, 53, 53, 53, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215},
		{36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 36, 37, 38, 39, 40, 41, 42, 43, 44, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206},
		{37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 37, 37, 37, 40, 40, 40, 43, 43, 43, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205},
		{38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 38, 38, 38, 41, 41, 41, 44, 44, 44, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206},
		{39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 39, 40, 41, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203},
		{40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202},
		{41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 41, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203},
		{42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 42, 43, 44, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206},
		{43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205},
		{44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 44, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206},
		{45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 45, 46, 47, 48, 49, 50, 51, 52, 53, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215},
		{46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 46, 46, 46, 49, 49, 49, 52, 52, 52, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214},
		{47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 47, 47, 47, 50, 50, 50, 53, 53, 53, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215},
		{48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 48, 49, 50, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212},
		{49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211},
		{50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212},
		{51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 51, 52, 53, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215},
		{52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 52, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214},
		{53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 53, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215},
		{54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{55, 55, 55, 58, 58, 58, 61, 61, 61, 64, 64, 64, 67, 67, 67, 70, 70, 70, 73, 73, 73, 76, 76, 76, 79, 79, 79, 55, 55, 55, 58, 58, 58, 61, 61, 61, 64, 64, 64, 67, 67, 67, 70, 70, 70, 73, 73, 73, 76, 76, 76, 79, 79, 79, 55, 55, 55, 58, 58, 58, 61, 61, 61, 64, 64, 64, 67, 67, 67, 70, 70, 70, 73, 73, 73, 76, 76, 76, 79, 79, 79, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{56, 56, 56, 59, 59, 59, 62, 62, 62, 65, 65, 65, 68, 68, 68, 71, 71, 71, 74, 74, 74, 77, 77, 77, 80, 80, 80, 56, 56, 56, 59, 59, 59, 62, 62, 62, 65, 65, 65, 68, 68, 68, 71, 71, 71, 74, 74, 74, 77, 77, 77, 80, 80, 80, 56, 56, 56, 59, 59, 59, 62, 62, 62, 65, 65, 65, 68, 68, 68, 71, 71, 71, 74, 74, 74, 77, 77, 77, 80, 80, 80, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{57, 58, 59, 57, 58, 59, 57, 58, 59, 66, 67, 68, 66, 67, 68, 66, 67, 68, 75, 76, 77, 75, 76, 77, 75, 76, 77, 57, 58, 59, 57, 58, 59, 57, 58, 59, 66, 67, 68, 66, 67, 68, 66, 67, 68, 75, 76, 77, 75, 76, 77, 75, 76, 77, 57, 58, 59, 57, 58, 59, 57, 58, 59, 66, 67, 68, 66, 67, 68, 66, 67, 68, 75, 76, 77, 75, 76, 77, 75, 76, 77, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{58, 58, 58, 58, 58, 58, 58, 58, 58, 67, 67, 67, 67, 67, 67, 67, 67, 67, 76, 76, 76, 76, 76, 76, 76, 76, 76, 58, 58, 58, 58, 58, 58, 58, 58, 58, 67, 67, 67, 67, 67, 67, 67, 67, 67, 76, 76, 76, 76, 76, 76, 76, 76, 76, 58, 58, 58, 58, 58, 58, 58, 58, 58, 67, 67, 67, 67, 67, 67, 67, 67, 67, 76, 76, 76, 76, 76, 76, 76, 76, 76, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{59, 59, 59, 59, 59, 59, 59, 59, 59, 68, 68, 68, 68, 68, 68, 68, 68, 68, 77, 77, 77, 77, 77, 77, 77, 77, 77, 59, 59, 59, 59, 59, 59, 59, 59, 59, 68, 68, 68, 68, 68, 68, 68, 68, 68, 77, 77, 77, 77, 77, 77, 77, 77, 77, 59, 59, 59, 59, 59, 59, 59, 59, 59, 68, 68, 68, 68, 68, 68, 68, 68, 68, 77, 77, 77, 77, 77, 77, 77, 77, 77, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{60, 61, 62, 60, 61, 62, 60, 61, 62, 69, 70, 71, 69, 70, 71, 69, 70, 71, 78, 79, 80, 78, 79, 80, 78, 79, 80, 60, 61, 62, 60, 61, 62, 60, 61, 62, 69, 70, 71, 69, 70, 71, 69, 70, 71, 78, 79, 80, 78, 79, 80, 78, 79, 80, 60, 61, 62, 60, 61, 62, 60, 61, 62, 69, 70, 71, 69, 70, 71, 69, 70, 71, 78, 79, 80, 78, 79, 80, 78, 79, 80, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{61, 61, 61, 61, 61, 61, 61, 61, 61, 70, 70, 70, 70, 70, 70, 70, 70, 70, 79, 79, 79, 79, 79, 79, 79, 79, 79, 61, 61, 61, 61, 61, 61, 61, 61, 61, 70, 70, 70, 70, 70, 70, 70, 70, 70, 79, 79, 79, 79, 79, 79, 79, 79, 79, 61, 61, 61, 61, 61, 61, 61, 61, 61, 70, 70, 70, 70, 70, 70, 70, 70, 70, 79, 79, 79, 79, 79, 79, 79, 79, 79, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{62, 62, 62, 62, 62, 62, 62, 62, 62, 71, 71, 71, 71, 71, 71, 71, 71, 71, 80, 80, 80, 80, 80, 80, 80, 80, 80, 62, 62, 62, 62, 62, 62, 62, 62, 62, 71, 71, 71, 71, 71, 71, 71, 71, 71, 80, 80, 80, 80, 80, 80, 80, 80, 80, 62, 62, 62, 62, 62, 62, 62, 62, 62, 71, 71, 71, 71, 71, 71, 71, 71, 71, 80, 80, 80, 80, 80, 80, 80, 80, 80, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 63, 64, 65, 66, 67, 68, 69, 70, 71, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233},
		{64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 64, 64, 64, 67, 67, 67, 70, 70, 70, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232},
		{65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 65, 65, 65, 68, 68, 68, 71, 71, 71, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233},
		{66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 66, 67, 68, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230},
		{67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229},
		{68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 68, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230},
		{69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 69, 70, 71, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233},
		{70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232},
		{71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 71, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233},
		{72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 72, 73, 74, 75, 76, 77, 78, 79, 80, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 73, 73, 73, 76, 76, 76, 79, 79, 79, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 74, 74, 74, 77, 77, 77, 80, 80, 80, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 75, 76, 77, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 77, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 78, 79, 80, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 79, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 80, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161},
		{82, 82, 82, 85, 85, 85, 88, 88, 88, 91, 91, 91, 94, 94, 94, 97, 97, 97, 100, 100, 100, 103, 103, 103, 106, 106, 106, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 82, 82, 82, 85, 85, 85, 88, 88, 88, 91, 91, 91, 94, 94, 94, 97, 97, 97, 100, 100, 100, 103, 103, 103, 106, 106, 106, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 82, 82, 82, 85, 85, 85, 88, 88, 88, 91, 91, 91, 94, 94, 94, 97, 97, 97, 100, 100, 100, 103, 103, 103, 106, 106, 106, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160},
		{83, 83, 83, 86, 86, 86, 89, 89, 89, 92, 92, 92, 95, 95, 95, 98, 98, 98, 101, 101, 101, 104, 104, 104, 107, 107, 107, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 83, 83, 83, 86, 86, 86, 89, 89, 89, 92, 92, 92, 95, 95, 95, 98, 98, 98, 101, 101, 101, 104, 104, 104, 107, 107, 107, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 83, 83, 83, 86, 86, 86, 89, 89, 89, 92, 92, 92, 95, 95, 95, 98, 98, 98, 101, 101, 101, 104, 104, 104, 107, 107, 107, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161},
		{84, 85, 86, 84, 85, 86, 84, 85, 86, 93, 94, 95, 93, 94, 95, 93, 94, 95, 102, 103, 104, 102, 103, 104, 102, 103, 104, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 84, 85, 86, 84, 85, 86, 84, 85, 86, 93, 94, 95, 93, 94, 95, 93, 94, 95, 102, 103, 104, 102, 103, 104, 102, 103, 104, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 84, 85, 86, 84, 85, 86, 84, 85, 86, 93, 94, 95, 93, 94, 95, 93, 94, 95, 102, 103, 104, 102, 103, 104, 102, 103, 104, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158},
		{85, 85, 85, 85, 85, 85, 85, 85, 85, 94, 94, 94, 94, 94, 94, 94, 94, 94, 103, 103, 103, 103, 103, 103, 103, 103, 103, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 85, 85, 85, 85, 85, 85, 85, 85, 85, 94, 94, 94, 94, 94, 94, 94, 94, 94, 103, 103, 103, 103, 103, 103, 103, 103, 103, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 85, 85, 85, 85, 85, 85, 85, 85, 85, 94, 94, 94, 94, 94, 94, 94, 94, 94, 103, 103, 103, 103, 103, 103, 103, 103, 103, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157},
		{86, 86, 86, 86, 86, 86, 86, 86, 86, 95, 95, 95, 95, 95, 95, 95, 95, 95, 104, 104, 104, 104, 104, 104, 104, 104, 104, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 86, 86, 86, 86, 86, 86, 86, 86, 86, 95, 95, 95, 95, 95, 95, 95, 95, 95, 104, 104, 104, 104, 104, 104, 104, 104, 104, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 86, 86, 86, 86, 86, 86, 86, 86, 86, 95, 95, 95, 95, 95, 95, 95, 95, 95, 104, 104, 104, 104, 104, 104, 104, 104, 104, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158},
		{87, 88, 89, 87, 88, 89, 87, 88, 89, 96, 97, 98, 96, 97, 98, 96, 97, 98, 105, 106, 107, 105, 106, 107, 105, 106, 107, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 87, 88, 89, 87, 88, 89, 87, 88, 89, 96, 97, 98, 96, 97, 98, 96, 97, 98, 105, 106, 107, 105, 106, 107, 105, 106, 107, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 87, 88, 89, 87, 88, 89, 87, 88, 89, 96, 97, 98, 96, 97, 98, 96, 97, 98, 105, 106, 107, 105, 106, 107, 105, 106, 107, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161},
		{88, 88, 88, 88, 88, 88, 88, 88, 88, 97, 97, 97, 97, 97, 97, 97, 97, 97, 106, 106, 106, 106, 106, 106, 106, 106, 106, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 88, 88, 88, 88, 88, 88, 88, 88, 88, 97, 97, 97, 97, 97, 97, 97, 97, 97, 106, 106, 106, 106, 106, 106, 106, 106, 106, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 88, 88, 88, 88, 88, 88, 88, 88, 88, 97, 97, 97, 97, 97, 97, 97, 97, 97, 106, 106, 106, 106, 106, 106, 106, 106, 106, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160},
		{89, 89, 89, 89, 89, 89, 89, 89, 89, 98, 98, 98, 98, 98, 98, 98, 98, 98, 107, 107, 107, 107, 107, 107, 107, 107, 107, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 89, 89, 89, 89, 89, 89, 89, 89, 89, 98, 98, 98, 98, 98, 98, 98, 98, 98, 107, 107, 107, 107, 107, 107, 107, 107, 107, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 89, 89, 89, 89, 89, 89, 89, 89, 89, 98, 98, 98, 98, 98, 98, 98, 98, 98, 107, 107, 107, 107, 107, 107, 107, 107, 107, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161},
		{90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 90, 91, 92, 93, 94, 95, 96, 97, 98, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152},
		{91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 91, 91, 91, 94, 94, 94, 97, 97, 97, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151},
		{92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 92, 92, 92, 95, 95, 95, 98, 98, 98, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152},
		{93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 93, 94, 95, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149},
		{94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 94, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148},
		{95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149},
		{96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 96, 97, 98, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152},
		{97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151},
		{98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152},
		{99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 99, 100, 101, 102, 103, 104, 105, 106, 107, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161},
		{100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 100, 100, 100, 103, 103, 103, 106, 106, 106, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160},
		{101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 101, 101, 101, 104, 104, 104, 107, 107, 107, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161},
		{102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 102, 103, 104, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158},
		{103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157},
		{104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158},
		{105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 105, 106, 107, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161},
		{106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160},
		{107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161},
		{108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134},
		{109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133, 109, 109, 109, 112, 112, 112, 115, 115, 115, 118, 118, 118, 121, 121, 121, 124, 124, 124, 127, 127, 127, 130, 130, 130, 133, 133, 133},
		{110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134, 110, 110, 110, 113, 113, 113, 116, 116, 116, 119, 119, 119, 122, 122, 122, 125, 125, 125, 128, 128, 128, 131, 131, 131, 134, 134, 134},
		{111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131, 111, 112, 113, 111, 112, 113, 111, 112, 113, 120, 121, 122, 120, 121, 122, 120, 121, 122, 129, 130, 131, 129, 130, 131, 129, 130, 131},
		{112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130, 112, 112, 112, 112, 112, 112, 112, 112, 112, 121, 121, 121, 121, 121, 121, 121, 121, 121, 130, 130, 130, 130, 130, 130, 130, 130, 130},
		{113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131, 113, 113, 113, 113, 113, 113, 113, 113, 113, 122, 122, 122, 122, 122, 122, 122, 122, 122, 131, 131, 131, 131, 131, 131, 131, 131, 131},
		{114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134, 114, 115, 116, 114, 115, 116, 114, 115, 116, 123, 124, 125, 123, 124, 125, 123, 124, 125, 132, 133, 134, 132, 133, 134, 132, 133, 134},
		{115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133, 115, 115, 115, 115, 115, 115, 115, 115, 115, 124, 124, 124, 124, 124, 124, 124, 124, 124, 133, 133, 133, 133, 133, 133, 133, 133, 133},
		{116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134, 116, 116, 116, 116, 116, 116, 116, 116, 116, 125, 125, 125, 125, 125, 125, 125, 125, 125, 134, 134, 134, 134, 134, 134, 134, 134, 134},
		{117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125, 117, 118, 119, 120, 121, 122, 123, 124, 125},
		{118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124, 118, 118, 118, 121, 121, 121, 124, 124, 124},
		{119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125, 119, 119, 119, 122, 122, 122, 125, 125, 125},
		{120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122, 120, 121, 122},
		{121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121, 121},
		{122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122, 122},
		{123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125, 123, 124, 125},
		{124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124, 124},
		{125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125, 125},
		{126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134, 126, 127, 128, 129, 130, 131, 132, 133, 134},
		{127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133, 127, 127, 127, 130, 130, 130, 133, 133, 133},
		{128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134, 128, 128, 128, 131, 131, 131, 134, 134, 134},
		{129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131, 129, 130, 131},
		{130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130},
		{131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131, 131},
		{132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134, 132, 133, 134},
		{133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133, 133},
		{134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134, 134},
		{135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161},
		{136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160, 136, 136, 136, 139, 139, 139, 142, 142, 142, 145, 145, 145, 148, 148, 148, 151, 151, 151, 154, 154, 154, 157, 157, 157, 160, 160, 160},
		{137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161, 137, 137, 137, 140, 140, 140, 143, 143, 143, 146, 146, 146, 149, 149, 149, 152, 152, 152, 155, 155, 155, 158, 158, 158, 161, 161, 161},
		{138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158, 138, 139, 140, 138, 139, 140, 138, 139, 140, 147, 148, 149, 147, 148, 149, 147, 148, 149, 156, 157, 158, 156, 157, 158, 156, 157, 158},
		{139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157, 139, 139, 139, 139, 139, 139, 139, 139, 139, 148, 148, 148, 148, 148, 148, 148, 148, 148, 157, 157, 157, 157, 157, 157, 157, 157, 157},
		{140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158, 140, 140, 140, 140, 140, 140, 140, 140, 140, 149, 149, 149, 149, 149, 149, 149, 149, 149, 158, 158, 158, 158, 158, 158, 158, 158, 158},
		{141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161, 141, 142, 143, 141, 142, 143, 141, 142, 143, 150, 151, 152, 150, 151, 152, 150, 151, 152, 159, 160, 161, 159, 160, 161, 159, 160, 161},
		{142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160, 142, 142, 142, 142, 142, 142, 142, 142, 142, 151, 151, 151, 151, 151, 151, 151, 151, 151, 160, 160, 160, 160, 160, 160, 160, 160, 160},
		{143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161, 143, 143, 143, 143, 143, 143, 143, 143, 143, 152, 152, 152, 152, 152, 152, 152, 152, 152, 161, 161, 161, 161, 161, 161, 161, 161, 161},
		{144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152, 144, 145, 146, 147, 148, 149, 150, 151, 152},
		{145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151, 145, 145, 145, 148, 148, 148, 151, 151, 151},
		{146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152, 146, 146, 146, 149, 149, 149, 152, 152, 152},
		{147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149, 147, 148, 149},
		{148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148, 148},
		{149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149, 149},
		{150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152, 150, 151, 152},
		{151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151, 151},
		{152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152, 152},
		{153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161, 153, 154, 155, 156, 157, 158, 159, 160, 161},
		{154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160, 154, 154, 154, 157, 157, 157, 160, 160, 160},
		{155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161, 155, 155, 155, 158, 158, 158, 161, 161, 161},
		{156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158, 156, 157, 158},
		{157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157, 157},
		{158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158, 158},
		{159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161, 159, 160, 161},
		{160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160, 160},
		{161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161, 161},
		{162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{163, 163, 163, 166, 166, 166, 169, 169, 169, 172, 172, 172, 175, 175, 175, 178, 178, 178, 181, 181, 181, 184, 184, 184, 187, 187, 187, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 163, 163, 163, 166, 166, 166, 169, 169, 169, 172, 172, 172, 175, 175, 175, 178, 178, 178, 181, 181, 181, 184, 184, 184, 187, 187, 187, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 163, 163, 163, 166, 166, 166, 169, 169, 169, 172, 172, 172, 175, 175, 175, 178, 178, 178, 181, 181, 181, 184, 184, 184, 187, 187, 187, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{164, 164, 164, 167, 167, 167, 170, 170, 170, 173, 173, 173, 176, 176, 176, 179, 179, 179, 182, 182, 182, 185, 185, 185, 188, 188, 188, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 164, 164, 164, 167, 167, 167, 170, 170, 170, 173, 173, 173, 176, 176, 176, 179, 179, 179, 182, 182, 182, 185, 185, 185, 188, 188, 188, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 164, 164, 164, 167, 167, 167, 170, 170, 170, 173, 173, 173, 176, 176, 176, 179, 179, 179, 182, 182, 182, 185, 185, 185, 188, 188, 188, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{165, 166, 167, 165, 166, 167, 165, 166, 167, 174, 175, 176, 174, 175, 176, 174, 175, 176, 183, 184, 185, 183, 184, 185, 183, 184, 185, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 165, 166, 167, 165, 166, 167, 165, 166, 167, 174, 175, 176, 174, 175, 176, 174, 175, 176, 183, 184, 185, 183, 184, 185, 183, 184, 185, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 165, 166, 167, 165, 166, 167, 165, 166, 167, 174, 175, 176, 174, 175, 176, 174, 175, 176, 183, 184, 185, 183, 184, 185, 183, 184, 185, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{166, 166, 166, 166, 166, 166, 166, 166, 166, 175, 175, 175, 175, 175, 175, 175, 175, 175, 184, 184, 184, 184, 184, 184, 184, 184, 184, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 166, 166, 166, 166, 166, 166, 166, 166, 166, 175, 175, 175, 175, 175, 175, 175, 175, 175, 184, 184, 184, 184, 184, 184, 184, 184, 184, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 166, 166, 166, 166, 166, 166, 166, 166, 166, 175, 175, 175, 175, 175, 175, 175, 175, 175, 184, 184, 184, 184, 184, 184, 184, 184, 184, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{167, 167, 167, 167, 167, 167, 167, 167, 167, 176, 176, 176, 176, 176, 176, 176, 176, 176, 185, 185, 185, 185, 185, 185, 185, 185, 185, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 167, 167, 167, 167, 167, 167, 167, 167, 167, 176, 176, 176, 176, 176, 176, 176, 176, 176, 185, 185, 185, 185, 185, 185, 185, 185, 185, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 167, 167, 167, 167, 167, 167, 167, 167, 167, 176, 176, 176, 176, 176, 176, 176, 176, 176, 185, 185, 185, 185, 185, 185, 185, 185, 185, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{168, 169, 170, 168, 169, 170, 168, 169, 170, 177, 178, 179, 177, 178, 179, 177, 178, 179, 186, 187, 188, 186, 187, 188, 186, 187, 188, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 168, 169, 170, 168, 169, 170, 168, 169, 170, 177, 178, 179, 177, 178, 179, 177, 178, 179, 186, 187, 188, 186, 187, 188, 186, 187, 188, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 168, 169, 170, 168, 169, 170, 168, 169, 170, 177, 178, 179, 177, 178, 179, 177, 178, 179, 186, 187, 188, 186, 187, 188, 186, 187, 188, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{169, 169, 169, 169, 169, 169, 169, 169, 169, 178, 178, 178, 178, 178, 178, 178, 178, 178, 187, 187, 187, 187, 187, 187, 187, 187, 187, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 169, 169, 169, 169, 169, 169, 169, 169, 169, 178, 178, 178, 178, 178, 178, 178, 178, 178, 187, 187, 187, 187, 187, 187, 187, 187, 187, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 169, 169, 169, 169, 169, 169, 169, 169, 169, 178, 178, 178, 178, 178, 178, 178, 178, 178, 187, 187, 187, 187, 187, 187, 187, 187, 187, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{170, 170, 170, 170, 170, 170, 170, 170, 170, 179, 179, 179, 179, 179, 179, 179, 179, 179, 188, 188, 188, 188, 188, 188, 188, 188, 188, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 170, 170, 170, 170, 170, 170, 170, 170, 170, 179, 179, 179, 179, 179, 179, 179, 179, 179, 188, 188, 188, 188, 188, 188, 188, 188, 188, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 170, 170, 170, 170, 170, 170, 170, 170, 170, 179, 179, 179, 179, 179, 179, 179, 179, 179, 188, 188, 188, 188, 188, 188, 188, 188, 188, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 171, 172, 173, 174, 175, 176, 177, 178, 179, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233},
		{172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 172, 172, 172, 175, 175, 175, 178, 178, 178, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232},
		{173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 173, 173, 173, 176, 176, 176, 179, 179, 179, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233},
		{174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 174, 175, 176, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230},
		{175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 175, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229},
		{176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 176, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230},
		{177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 177, 178, 179, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233},
		{178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 178, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232},
		{179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 179, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233},
		{180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 180, 181, 182, 183, 184, 185, 186, 187, 188, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 181, 181, 181, 184, 184, 184, 187, 187, 187, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 182, 182, 182, 185, 185, 185, 188, 188, 188, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 183, 184, 185, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 185, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 186, 187, 188, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 187, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 188, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215},
		{190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214, 190, 190, 190, 193, 193, 193, 196, 196, 196, 199, 199, 199, 202, 202, 202, 205, 205, 205, 208, 208, 208, 211, 211, 211, 214, 214, 214},
		{191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215, 191, 191, 191, 194, 194, 194, 197, 197, 197, 200, 200, 200, 203, 203, 203, 206, 206, 206, 209, 209, 209, 212, 212, 212, 215, 215, 215},
		{192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212, 192, 193, 194, 192, 193, 194, 192, 193, 194, 201, 202, 203, 201, 202, 203, 201, 202, 203, 210, 211, 212, 210, 211, 212, 210, 211, 212},
		{193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211, 193, 193, 193, 193, 193, 193, 193, 193, 193, 202, 202, 202, 202, 202, 202, 202, 202, 202, 211, 211, 211, 211, 211, 211, 211, 211, 211},
		{194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212, 194, 194, 194, 194, 194, 194, 194, 194, 194, 203, 203, 203, 203, 203, 203, 203, 203, 203, 212, 212, 212, 212, 212, 212, 212, 212, 212},
		{195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215, 195, 196, 197, 195, 196, 197, 195, 196, 197, 204, 205, 206, 204, 205, 206, 204, 205, 206, 213, 214, 215, 213, 214, 215, 213, 214, 215},
		{196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214, 196, 196, 196, 196, 196, 196, 196, 196, 196, 205, 205, 205, 205, 205, 205, 205, 205, 205, 214, 214, 214, 214, 214, 214, 214, 214, 214},
		{197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215, 197, 197, 197, 197, 197, 197, 197, 197, 197, 206, 206, 206, 206, 206, 206, 206, 206, 206, 215, 215, 215, 215, 215, 215, 215, 215, 215},
		{198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206, 198, 199, 200, 201, 202, 203, 204, 205, 206},
		{199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205, 199, 199, 199, 202, 202, 202, 205, 205, 205},
		{200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206, 200, 200, 200, 203, 203, 203, 206, 206, 206},
		{201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203, 201, 202, 203},
		{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202},
		{203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203, 203},
		{204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206, 204, 205, 206},
		{205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205},
		{206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206, 206},
		{207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215, 207, 208, 209, 210, 211, 212, 213, 214, 215},
		{208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214, 208, 208, 208, 211, 211, 211, 214, 214, 214},
		{209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215, 209, 209, 209, 212, 212, 212, 215, 215, 215},
		{210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212, 210, 211, 212},
		{211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211, 211},
		{212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212, 212},
		{213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215, 213, 214, 215},
		{214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214, 214},
		{215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215, 215},
		{216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241, 217, 217, 217, 220, 220, 220, 223, 223, 223, 226, 226, 226, 229, 229, 229, 232, 232, 232, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242, 218, 218, 218, 221, 221, 221, 224, 224, 224, 227, 227, 227, 230, 230, 230, 233, 233, 233, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239, 219, 220, 221, 219, 220, 221, 219, 220, 221, 228, 229, 230, 228, 229, 230, 228, 229, 230, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238, 220, 220, 220, 220, 220, 220, 220, 220, 220, 229, 229, 229, 229, 229, 229, 229, 229, 229, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239, 221, 221, 221, 221, 221, 221, 221, 221, 221, 230, 230, 230, 230, 230, 230, 230, 230, 230, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242, 222, 223, 224, 222, 223, 224, 222, 223, 224, 231, 232, 233, 231, 232, 233, 231, 232, 233, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241, 223, 223, 223, 223, 223, 223, 223, 223, 223, 232, 232, 232, 232, 232, 232, 232, 232, 232, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242, 224, 224, 224, 224, 224, 224, 224, 224, 224, 233, 233, 233, 233, 233, 233, 233, 233, 233, 242, 242, 242, 242, 242, 242, 242, 242, 242},
		{225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233, 225, 226, 227, 228, 229, 230, 231, 232, 233},
		{226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232, 226, 226, 226, 229, 229, 229, 232, 232, 232},
		{227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233, 227, 227, 227, 230, 230, 230, 233, 233, 233},
		{228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230, 228, 229, 230},
		{229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229, 229},
		{230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230},
		{231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233, 231, 232, 233},
		{232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232, 232},
		{233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233, 233},
		{234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242, 234, 235, 236, 237, 238, 239, 240, 241, 242},
		{235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241, 235, 235, 235, 238, 238, 238, 241, 241, 241},
		{236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242, 236, 236, 236, 239, 239, 239, 242, 242, 242},
		{237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239, 237, 238, 239},
		{238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238, 238},
		{239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239, 239},
		{240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242, 240, 241, 242},
		{241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241},
		{242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242}
	};
   
   for (int i = 0; i <= index; i++) {
      input1.at(i) = array[input1.at(i)][input2.at(i)];
   }
}


//basic idea is to precalculate all the pairings.
// This should(?) be quicker than doing it "live."
// It handles layers 0->next-to-last.
void Base243TrieRelation::mergeBoxesFlat(
      vector<int>& input1,
      vector<int>& input2,
      int& index
) const {
   mergeBoxesCore(input1, input2, index);
}

void BigOr243Trie::mergeBoxesFlat(
      vector<int>& input1,
      vector<int>& input2,
      int& index
) const {
   mergeBoxesCore(input1, input2, index);
}