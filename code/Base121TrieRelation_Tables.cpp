//Base121TrieRelation_Tables.cpp
#include "Base121TrieRelation.h"
#include "SIMD_InnerGIAT.h"

//As below, we're just precalculating lots of stuff
void Base121TrieRelation::layerSkipFlat(
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
		  case 1:
			output = 1;
			break;
		}
		break;
	  case 2:
		switch(input2) {
		  case 2:
			output = 2;
			break;
		  case 1:
			output = 1;
			break;
		}
		break;
	  case 3:
		switch(input2) {
		  case 3:
			output = 3;
			break;
		  case 1:
			output = 1;
			break;
		}
		break;
	  case 4:
		switch(input2) {
		  case 4:
			output = 4;
			break;
		}
		break;
	  case 5:
		switch(input2) {
		  case 5:
			output = 5;
			break;
		  case 4:
			output = 4;
			break;
		}
		break;
	  case 6:
		switch(input2) {
		  case 6:
			output = 6;
			break;
		  case 4:
			output = 4;
			break;
		}
		break;
	  case 7:
		switch(input2) {
		  case 7:
			output = 7;
			break;
		  case 4:
			output = 4;
			break;
		}
		break;
	  case 8:
		switch(input2) {
		  case 8:
			output = 8;
			break;
		  case 5:
			output = 8;
			break;
		  case 4:
			output = 4;
			break;
		  case 7:
			output = 7;
			break;
		}
		break;
	  case 9:
		switch(input2) {
		  case 9:
			output = 9;
			break;
		  case 6:
			output = 9;
			break;
		  case 4:
			output = 4;
			break;
		  case 7:
			output = 7;
			break;
		}
		break;
	  case 10:
		switch(input2) {
		  case 10:
			output = 10;
			break;
		  case 4:
			output = 4;
			break;
		}
		break;
	  case 11:
		switch(input2) {
		  case 11:
			output = 11;
			break;
		  case 5:
			output = 11;
			break;
		  case 4:
			output = 4;
			break;
		  case 10:
			output = 10;
			break;
		}
		break;
	  case 12:
		switch(input2) {
		  case 12:
			output = 12;
			break;
		  case 6:
			output = 12;
			break;
		  case 4:
			output = 4;
			break;
		  case 10:
			output = 10;
			break;
		}
		break;
	  case 13:
		switch(input2) {
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 14:
		switch(input2) {
		  case 14:
			output = 14;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 15:
		switch(input2) {
		  case 15:
			output = 15;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 16:
		switch(input2) {
		  case 16:
			output = 16;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 17:
		switch(input2) {
		  case 17:
			output = 17;
			break;
		  case 14:
			output = 17;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 16;
			break;
		}
		break;
	  case 18:
		switch(input2) {
		  case 18:
			output = 18;
			break;
		  case 15:
			output = 18;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 16;
			break;
		}
		break;
	  case 19:
		switch(input2) {
		  case 19:
			output = 19;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 20:
		switch(input2) {
		  case 20:
			output = 20;
			break;
		  case 14:
			output = 20;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 19;
			break;
		}
		break;
	  case 21:
		switch(input2) {
		  case 21:
			output = 21;
			break;
		  case 15:
			output = 21;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 19;
			break;
		}
		break;
	  case 22:
		switch(input2) {
		  case 22:
			output = 22;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 23:
		switch(input2) {
		  case 23:
			output = 23;
			break;
		  case 14:
			output = 23;
			break;
		  case 13:
			output = 13;
			break;
		  case 22:
			output = 22;
			break;
		}
		break;
	  case 24:
		switch(input2) {
		  case 24:
			output = 24;
			break;
		  case 15:
			output = 24;
			break;
		  case 13:
			output = 13;
			break;
		  case 22:
			output = 22;
			break;
		}
		break;
	  case 25:
		switch(input2) {
		  case 25:
			output = 25;
			break;
		  case 16:
			output = 25;
			break;
		  case 13:
			output = 13;
			break;
		  case 22:
			output = 22;
			break;
		}
		break;
	  case 26:
		switch(input2) {
		  case 26:
			output = 26;
			break;
		  case 17:
			output = 26;
			break;
		  case 14:
			output = 26;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 25;
			break;
		  case 23:
			output = 26;
			break;
		  case 22:
			output = 22;
			break;
		  case 25:
			output = 25;
			break;
		}
		break;
	  case 27:
		switch(input2) {
		  case 27:
			output = 27;
			break;
		  case 18:
			output = 27;
			break;
		  case 15:
			output = 27;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 25;
			break;
		  case 24:
			output = 27;
			break;
		  case 22:
			output = 22;
			break;
		  case 25:
			output = 25;
			break;
		}
		break;
	  case 28:
		switch(input2) {
		  case 28:
			output = 28;
			break;
		  case 19:
			output = 28;
			break;
		  case 13:
			output = 13;
			break;
		  case 22:
			output = 22;
			break;
		}
		break;
	  case 29:
		switch(input2) {
		  case 29:
			output = 29;
			break;
		  case 20:
			output = 29;
			break;
		  case 14:
			output = 29;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 28;
			break;
		  case 23:
			output = 29;
			break;
		  case 22:
			output = 22;
			break;
		  case 28:
			output = 28;
			break;
		}
		break;
	  case 30:
		switch(input2) {
		  case 30:
			output = 30;
			break;
		  case 21:
			output = 30;
			break;
		  case 15:
			output = 30;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 28;
			break;
		  case 24:
			output = 30;
			break;
		  case 22:
			output = 22;
			break;
		  case 28:
			output = 28;
			break;
		}
		break;
	  case 31:
		switch(input2) {
		  case 31:
			output = 31;
			break;
		  case 13:
			output = 13;
			break;
		}
		break;
	  case 32:
		switch(input2) {
		  case 32:
			output = 32;
			break;
		  case 14:
			output = 32;
			break;
		  case 13:
			output = 13;
			break;
		  case 31:
			output = 31;
			break;
		}
		break;
	  case 33:
		switch(input2) {
		  case 33:
			output = 33;
			break;
		  case 15:
			output = 33;
			break;
		  case 13:
			output = 13;
			break;
		  case 31:
			output = 31;
			break;
		}
		break;
	  case 34:
		switch(input2) {
		  case 34:
			output = 34;
			break;
		  case 16:
			output = 34;
			break;
		  case 13:
			output = 13;
			break;
		  case 31:
			output = 31;
			break;
		}
		break;
	  case 35:
		switch(input2) {
		  case 35:
			output = 35;
			break;
		  case 17:
			output = 35;
			break;
		  case 14:
			output = 35;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 34;
			break;
		  case 32:
			output = 35;
			break;
		  case 31:
			output = 31;
			break;
		  case 34:
			output = 34;
			break;
		}
		break;
	  case 36:
		switch(input2) {
		  case 36:
			output = 36;
			break;
		  case 18:
			output = 36;
			break;
		  case 15:
			output = 36;
			break;
		  case 13:
			output = 13;
			break;
		  case 16:
			output = 34;
			break;
		  case 33:
			output = 36;
			break;
		  case 31:
			output = 31;
			break;
		  case 34:
			output = 34;
			break;
		}
		break;
	  case 37:
		switch(input2) {
		  case 37:
			output = 37;
			break;
		  case 19:
			output = 37;
			break;
		  case 13:
			output = 13;
			break;
		  case 31:
			output = 31;
			break;
		}
		break;
	  case 38:
		switch(input2) {
		  case 38:
			output = 38;
			break;
		  case 20:
			output = 38;
			break;
		  case 14:
			output = 38;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 37;
			break;
		  case 32:
			output = 38;
			break;
		  case 31:
			output = 31;
			break;
		  case 37:
			output = 37;
			break;
		}
		break;
	  case 39:
		switch(input2) {
		  case 39:
			output = 39;
			break;
		  case 21:
			output = 39;
			break;
		  case 15:
			output = 39;
			break;
		  case 13:
			output = 13;
			break;
		  case 19:
			output = 37;
			break;
		  case 33:
			output = 39;
			break;
		  case 31:
			output = 31;
			break;
		  case 37:
			output = 37;
			break;
		}
		break;
	  case 40:
		switch(input2) {
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 41:
		switch(input2) {
		  case 41:
			output = 41;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 42:
		switch(input2) {
		  case 42:
			output = 42;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 43:
		switch(input2) {
		  case 43:
			output = 14;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 44:
		switch(input2) {
		  case 44:
			output = 44;
			break;
		  case 41:
			output = 44;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 14;
			break;
		}
		break;
	  case 45:
		switch(input2) {
		  case 45:
			output = 45;
			break;
		  case 42:
			output = 45;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 14;
			break;
		}
		break;
	  case 46:
		switch(input2) {
		  case 46:
			output = 15;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 47:
		switch(input2) {
		  case 47:
			output = 47;
			break;
		  case 41:
			output = 47;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 15;
			break;
		}
		break;
	  case 48:
		switch(input2) {
		  case 48:
			output = 48;
			break;
		  case 42:
			output = 48;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 15;
			break;
		}
		break;
	  case 49:
		switch(input2) {
		  case 49:
			output = 5;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 50:
		switch(input2) {
		  case 50:
			output = 50;
			break;
		  case 41:
			output = 50;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 5;
			break;
		}
		break;
	  case 51:
		switch(input2) {
		  case 51:
			output = 51;
			break;
		  case 42:
			output = 51;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 5;
			break;
		}
		break;
	  case 52:
		switch(input2) {
		  case 52:
			output = 17;
			break;
		  case 43:
			output = 17;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 5;
			break;
		}
		break;
	  case 53:
		switch(input2) {
		  case 53:
			output = 53;
			break;
		  case 44:
			output = 53;
			break;
		  case 41:
			output = 53;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 17;
			break;
		  case 50:
			output = 53;
			break;
		  case 49:
			output = 5;
			break;
		  case 52:
			output = 17;
			break;
		}
		break;
	  case 54:
		switch(input2) {
		  case 54:
			output = 54;
			break;
		  case 45:
			output = 54;
			break;
		  case 42:
			output = 54;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 17;
			break;
		  case 51:
			output = 54;
			break;
		  case 49:
			output = 5;
			break;
		  case 52:
			output = 17;
			break;
		}
		break;
	  case 55:
		switch(input2) {
		  case 55:
			output = 18;
			break;
		  case 46:
			output = 18;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 5;
			break;
		}
		break;
	  case 56:
		switch(input2) {
		  case 56:
			output = 56;
			break;
		  case 47:
			output = 56;
			break;
		  case 41:
			output = 56;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 18;
			break;
		  case 50:
			output = 56;
			break;
		  case 49:
			output = 5;
			break;
		  case 55:
			output = 18;
			break;
		}
		break;
	  case 57:
		switch(input2) {
		  case 57:
			output = 57;
			break;
		  case 48:
			output = 57;
			break;
		  case 42:
			output = 57;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 18;
			break;
		  case 51:
			output = 57;
			break;
		  case 49:
			output = 5;
			break;
		  case 55:
			output = 18;
			break;
		}
		break;
	  case 58:
		switch(input2) {
		  case 58:
			output = 6;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 59:
		switch(input2) {
		  case 59:
			output = 59;
			break;
		  case 41:
			output = 59;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 6;
			break;
		}
		break;
	  case 60:
		switch(input2) {
		  case 60:
			output = 60;
			break;
		  case 42:
			output = 60;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 6;
			break;
		}
		break;
	  case 61:
		switch(input2) {
		  case 61:
			output = 20;
			break;
		  case 43:
			output = 20;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 6;
			break;
		}
		break;
	  case 62:
		switch(input2) {
		  case 62:
			output = 62;
			break;
		  case 44:
			output = 62;
			break;
		  case 41:
			output = 62;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 20;
			break;
		  case 59:
			output = 62;
			break;
		  case 58:
			output = 6;
			break;
		  case 61:
			output = 20;
			break;
		}
		break;
	  case 63:
		switch(input2) {
		  case 63:
			output = 63;
			break;
		  case 45:
			output = 63;
			break;
		  case 42:
			output = 63;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 20;
			break;
		  case 60:
			output = 63;
			break;
		  case 58:
			output = 6;
			break;
		  case 61:
			output = 20;
			break;
		}
		break;
	  case 64:
		switch(input2) {
		  case 64:
			output = 21;
			break;
		  case 46:
			output = 21;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 6;
			break;
		}
		break;
	  case 65:
		switch(input2) {
		  case 65:
			output = 65;
			break;
		  case 47:
			output = 65;
			break;
		  case 41:
			output = 65;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 21;
			break;
		  case 59:
			output = 65;
			break;
		  case 58:
			output = 6;
			break;
		  case 64:
			output = 21;
			break;
		}
		break;
	  case 66:
		switch(input2) {
		  case 66:
			output = 66;
			break;
		  case 48:
			output = 66;
			break;
		  case 42:
			output = 66;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 21;
			break;
		  case 60:
			output = 66;
			break;
		  case 58:
			output = 6;
			break;
		  case 64:
			output = 21;
			break;
		}
		break;
	  case 67:
		switch(input2) {
		  case 67:
			output = 2;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 68:
		switch(input2) {
		  case 68:
			output = 68;
			break;
		  case 41:
			output = 68;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 69:
		switch(input2) {
		  case 69:
			output = 69;
			break;
		  case 42:
			output = 69;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 70:
		switch(input2) {
		  case 70:
			output = 23;
			break;
		  case 43:
			output = 23;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 71:
		switch(input2) {
		  case 71:
			output = 71;
			break;
		  case 44:
			output = 71;
			break;
		  case 41:
			output = 71;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 23;
			break;
		  case 68:
			output = 71;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 23;
			break;
		}
		break;
	  case 72:
		switch(input2) {
		  case 72:
			output = 72;
			break;
		  case 45:
			output = 72;
			break;
		  case 42:
			output = 72;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 23;
			break;
		  case 69:
			output = 72;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 23;
			break;
		}
		break;
	  case 73:
		switch(input2) {
		  case 73:
			output = 24;
			break;
		  case 46:
			output = 24;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 74:
		switch(input2) {
		  case 74:
			output = 74;
			break;
		  case 47:
			output = 74;
			break;
		  case 41:
			output = 74;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 24;
			break;
		  case 68:
			output = 74;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 24;
			break;
		}
		break;
	  case 75:
		switch(input2) {
		  case 75:
			output = 75;
			break;
		  case 48:
			output = 75;
			break;
		  case 42:
			output = 75;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 24;
			break;
		  case 69:
			output = 75;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 24;
			break;
		}
		break;
	  case 76:
		switch(input2) {
		  case 76:
			output = 8;
			break;
		  case 49:
			output = 8;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 77:
		switch(input2) {
		  case 77:
			output = 77;
			break;
		  case 50:
			output = 77;
			break;
		  case 41:
			output = 77;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 8;
			break;
		  case 68:
			output = 77;
			break;
		  case 67:
			output = 2;
			break;
		  case 76:
			output = 8;
			break;
		}
		break;
	  case 78:
		switch(input2) {
		  case 78:
			output = 78;
			break;
		  case 51:
			output = 78;
			break;
		  case 42:
			output = 78;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 8;
			break;
		  case 69:
			output = 78;
			break;
		  case 67:
			output = 2;
			break;
		  case 76:
			output = 8;
			break;
		}
		break;
	  case 79:
		switch(input2) {
		  case 79:
			output = 26;
			break;
		  case 52:
			output = 26;
			break;
		  case 43:
			output = 26;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 8;
			break;
		  case 70:
			output = 26;
			break;
		  case 67:
			output = 2;
			break;
		  case 76:
			output = 8;
			break;
		}
		break;
	  case 80:
		switch(input2) {
		  case 80:
			output = 80;
			break;
		  case 53:
			output = 80;
			break;
		  case 44:
			output = 80;
			break;
		  case 41:
			output = 80;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 26;
			break;
		  case 50:
			output = 80;
			break;
		  case 49:
			output = 8;
			break;
		  case 52:
			output = 26;
			break;
		  case 71:
			output = 80;
			break;
		  case 68:
			output = 80;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 26;
			break;
		  case 77:
			output = 80;
			break;
		  case 76:
			output = 8;
			break;
		  case 79:
			output = 26;
			break;
		}
		break;
	  case 81:
		switch(input2) {
		  case 81:
			output = 81;
			break;
		  case 54:
			output = 81;
			break;
		  case 45:
			output = 81;
			break;
		  case 42:
			output = 81;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 26;
			break;
		  case 51:
			output = 81;
			break;
		  case 49:
			output = 8;
			break;
		  case 52:
			output = 26;
			break;
		  case 72:
			output = 81;
			break;
		  case 69:
			output = 81;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 26;
			break;
		  case 78:
			output = 81;
			break;
		  case 76:
			output = 8;
			break;
		  case 79:
			output = 26;
			break;
		}
		break;
	  case 82:
		switch(input2) {
		  case 82:
			output = 27;
			break;
		  case 55:
			output = 27;
			break;
		  case 46:
			output = 27;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 8;
			break;
		  case 73:
			output = 27;
			break;
		  case 67:
			output = 2;
			break;
		  case 76:
			output = 8;
			break;
		}
		break;
	  case 83:
		switch(input2) {
		  case 83:
			output = 83;
			break;
		  case 56:
			output = 83;
			break;
		  case 47:
			output = 83;
			break;
		  case 41:
			output = 83;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 27;
			break;
		  case 50:
			output = 83;
			break;
		  case 49:
			output = 8;
			break;
		  case 55:
			output = 27;
			break;
		  case 74:
			output = 83;
			break;
		  case 68:
			output = 83;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 27;
			break;
		  case 77:
			output = 83;
			break;
		  case 76:
			output = 8;
			break;
		  case 82:
			output = 27;
			break;
		}
		break;
	  case 84:
		switch(input2) {
		  case 84:
			output = 84;
			break;
		  case 57:
			output = 84;
			break;
		  case 48:
			output = 84;
			break;
		  case 42:
			output = 84;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 27;
			break;
		  case 51:
			output = 84;
			break;
		  case 49:
			output = 8;
			break;
		  case 55:
			output = 27;
			break;
		  case 75:
			output = 84;
			break;
		  case 69:
			output = 84;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 27;
			break;
		  case 78:
			output = 84;
			break;
		  case 76:
			output = 8;
			break;
		  case 82:
			output = 27;
			break;
		}
		break;
	  case 85:
		switch(input2) {
		  case 85:
			output = 9;
			break;
		  case 58:
			output = 9;
			break;
		  case 40:
			output = 1;
			break;
		  case 67:
			output = 2;
			break;
		}
		break;
	  case 86:
		switch(input2) {
		  case 86:
			output = 86;
			break;
		  case 59:
			output = 86;
			break;
		  case 41:
			output = 86;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 9;
			break;
		  case 68:
			output = 86;
			break;
		  case 67:
			output = 2;
			break;
		  case 85:
			output = 9;
			break;
		}
		break;
	  case 87:
		switch(input2) {
		  case 87:
			output = 87;
			break;
		  case 60:
			output = 87;
			break;
		  case 42:
			output = 87;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 9;
			break;
		  case 69:
			output = 87;
			break;
		  case 67:
			output = 2;
			break;
		  case 85:
			output = 9;
			break;
		}
		break;
	  case 88:
		switch(input2) {
		  case 88:
			output = 29;
			break;
		  case 61:
			output = 29;
			break;
		  case 43:
			output = 29;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 9;
			break;
		  case 70:
			output = 29;
			break;
		  case 67:
			output = 2;
			break;
		  case 85:
			output = 9;
			break;
		}
		break;
	  case 89:
		switch(input2) {
		  case 89:
			output = 89;
			break;
		  case 62:
			output = 89;
			break;
		  case 44:
			output = 89;
			break;
		  case 41:
			output = 89;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 29;
			break;
		  case 59:
			output = 89;
			break;
		  case 58:
			output = 9;
			break;
		  case 61:
			output = 29;
			break;
		  case 71:
			output = 89;
			break;
		  case 68:
			output = 89;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 29;
			break;
		  case 86:
			output = 89;
			break;
		  case 85:
			output = 9;
			break;
		  case 88:
			output = 29;
			break;
		}
		break;
	  case 90:
		switch(input2) {
		  case 90:
			output = 90;
			break;
		  case 63:
			output = 90;
			break;
		  case 45:
			output = 90;
			break;
		  case 42:
			output = 90;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 29;
			break;
		  case 60:
			output = 90;
			break;
		  case 58:
			output = 9;
			break;
		  case 61:
			output = 29;
			break;
		  case 72:
			output = 90;
			break;
		  case 69:
			output = 90;
			break;
		  case 67:
			output = 2;
			break;
		  case 70:
			output = 29;
			break;
		  case 87:
			output = 90;
			break;
		  case 85:
			output = 9;
			break;
		  case 88:
			output = 29;
			break;
		}
		break;
	  case 91:
		switch(input2) {
		  case 91:
			output = 30;
			break;
		  case 64:
			output = 30;
			break;
		  case 46:
			output = 30;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 9;
			break;
		  case 73:
			output = 30;
			break;
		  case 67:
			output = 2;
			break;
		  case 85:
			output = 9;
			break;
		}
		break;
	  case 92:
		switch(input2) {
		  case 92:
			output = 92;
			break;
		  case 65:
			output = 92;
			break;
		  case 47:
			output = 92;
			break;
		  case 41:
			output = 92;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 30;
			break;
		  case 59:
			output = 92;
			break;
		  case 58:
			output = 9;
			break;
		  case 64:
			output = 30;
			break;
		  case 74:
			output = 92;
			break;
		  case 68:
			output = 92;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 30;
			break;
		  case 86:
			output = 92;
			break;
		  case 85:
			output = 9;
			break;
		  case 91:
			output = 30;
			break;
		}
		break;
	  case 93:
		switch(input2) {
		  case 93:
			output = 93;
			break;
		  case 66:
			output = 93;
			break;
		  case 48:
			output = 93;
			break;
		  case 42:
			output = 93;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 30;
			break;
		  case 60:
			output = 93;
			break;
		  case 58:
			output = 9;
			break;
		  case 64:
			output = 30;
			break;
		  case 75:
			output = 93;
			break;
		  case 69:
			output = 93;
			break;
		  case 67:
			output = 2;
			break;
		  case 73:
			output = 30;
			break;
		  case 87:
			output = 93;
			break;
		  case 85:
			output = 9;
			break;
		  case 91:
			output = 30;
			break;
		}
		break;
	  case 94:
		switch(input2) {
		  case 94:
			output = 3;
			break;
		  case 40:
			output = 1;
			break;
		}
		break;
	  case 95:
		switch(input2) {
		  case 95:
			output = 95;
			break;
		  case 41:
			output = 95;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 96:
		switch(input2) {
		  case 96:
			output = 96;
			break;
		  case 42:
			output = 96;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 97:
		switch(input2) {
		  case 97:
			output = 32;
			break;
		  case 43:
			output = 32;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 98:
		switch(input2) {
		  case 98:
			output = 98;
			break;
		  case 44:
			output = 98;
			break;
		  case 41:
			output = 98;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 32;
			break;
		  case 95:
			output = 98;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 32;
			break;
		}
		break;
	  case 99:
		switch(input2) {
		  case 99:
			output = 99;
			break;
		  case 45:
			output = 99;
			break;
		  case 42:
			output = 99;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 32;
			break;
		  case 96:
			output = 99;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 32;
			break;
		}
		break;
	  case 100:
		switch(input2) {
		  case 100:
			output = 33;
			break;
		  case 46:
			output = 33;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 101:
		switch(input2) {
		  case 101:
			output = 101;
			break;
		  case 47:
			output = 101;
			break;
		  case 41:
			output = 101;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 33;
			break;
		  case 95:
			output = 101;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 33;
			break;
		}
		break;
	  case 102:
		switch(input2) {
		  case 102:
			output = 102;
			break;
		  case 48:
			output = 102;
			break;
		  case 42:
			output = 102;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 33;
			break;
		  case 96:
			output = 102;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 33;
			break;
		}
		break;
	  case 103:
		switch(input2) {
		  case 103:
			output = 11;
			break;
		  case 49:
			output = 11;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 104:
		switch(input2) {
		  case 104:
			output = 104;
			break;
		  case 50:
			output = 104;
			break;
		  case 41:
			output = 104;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 11;
			break;
		  case 95:
			output = 104;
			break;
		  case 94:
			output = 3;
			break;
		  case 103:
			output = 11;
			break;
		}
		break;
	  case 105:
		switch(input2) {
		  case 105:
			output = 105;
			break;
		  case 51:
			output = 105;
			break;
		  case 42:
			output = 105;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 11;
			break;
		  case 96:
			output = 105;
			break;
		  case 94:
			output = 3;
			break;
		  case 103:
			output = 11;
			break;
		}
		break;
	  case 106:
		switch(input2) {
		  case 106:
			output = 35;
			break;
		  case 52:
			output = 35;
			break;
		  case 43:
			output = 35;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 11;
			break;
		  case 97:
			output = 35;
			break;
		  case 94:
			output = 3;
			break;
		  case 103:
			output = 11;
			break;
		}
		break;
	  case 107:
		switch(input2) {
		  case 107:
			output = 107;
			break;
		  case 53:
			output = 107;
			break;
		  case 44:
			output = 107;
			break;
		  case 41:
			output = 107;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 35;
			break;
		  case 50:
			output = 107;
			break;
		  case 49:
			output = 11;
			break;
		  case 52:
			output = 35;
			break;
		  case 98:
			output = 107;
			break;
		  case 95:
			output = 107;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 35;
			break;
		  case 104:
			output = 107;
			break;
		  case 103:
			output = 11;
			break;
		  case 106:
			output = 35;
			break;
		}
		break;
	  case 108:
		switch(input2) {
		  case 108:
			output = 108;
			break;
		  case 54:
			output = 108;
			break;
		  case 45:
			output = 108;
			break;
		  case 42:
			output = 108;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 35;
			break;
		  case 51:
			output = 108;
			break;
		  case 49:
			output = 11;
			break;
		  case 52:
			output = 35;
			break;
		  case 99:
			output = 108;
			break;
		  case 96:
			output = 108;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 35;
			break;
		  case 105:
			output = 108;
			break;
		  case 103:
			output = 11;
			break;
		  case 106:
			output = 35;
			break;
		}
		break;
	  case 109:
		switch(input2) {
		  case 109:
			output = 36;
			break;
		  case 55:
			output = 36;
			break;
		  case 46:
			output = 36;
			break;
		  case 40:
			output = 1;
			break;
		  case 49:
			output = 11;
			break;
		  case 100:
			output = 36;
			break;
		  case 94:
			output = 3;
			break;
		  case 103:
			output = 11;
			break;
		}
		break;
	  case 110:
		switch(input2) {
		  case 110:
			output = 110;
			break;
		  case 56:
			output = 110;
			break;
		  case 47:
			output = 110;
			break;
		  case 41:
			output = 110;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 36;
			break;
		  case 50:
			output = 110;
			break;
		  case 49:
			output = 11;
			break;
		  case 55:
			output = 36;
			break;
		  case 101:
			output = 110;
			break;
		  case 95:
			output = 110;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 36;
			break;
		  case 104:
			output = 110;
			break;
		  case 103:
			output = 11;
			break;
		  case 109:
			output = 36;
			break;
		}
		break;
	  case 111:
		switch(input2) {
		  case 111:
			output = 111;
			break;
		  case 57:
			output = 111;
			break;
		  case 48:
			output = 111;
			break;
		  case 42:
			output = 111;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 36;
			break;
		  case 51:
			output = 111;
			break;
		  case 49:
			output = 11;
			break;
		  case 55:
			output = 36;
			break;
		  case 102:
			output = 111;
			break;
		  case 96:
			output = 111;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 36;
			break;
		  case 105:
			output = 111;
			break;
		  case 103:
			output = 11;
			break;
		  case 109:
			output = 36;
			break;
		}
		break;
	  case 112:
		switch(input2) {
		  case 112:
			output = 12;
			break;
		  case 58:
			output = 12;
			break;
		  case 40:
			output = 1;
			break;
		  case 94:
			output = 3;
			break;
		}
		break;
	  case 113:
		switch(input2) {
		  case 113:
			output = 113;
			break;
		  case 59:
			output = 113;
			break;
		  case 41:
			output = 113;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 12;
			break;
		  case 95:
			output = 113;
			break;
		  case 94:
			output = 3;
			break;
		  case 112:
			output = 12;
			break;
		}
		break;
	  case 114:
		switch(input2) {
		  case 114:
			output = 114;
			break;
		  case 60:
			output = 114;
			break;
		  case 42:
			output = 114;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 12;
			break;
		  case 96:
			output = 114;
			break;
		  case 94:
			output = 3;
			break;
		  case 112:
			output = 12;
			break;
		}
		break;
	  case 115:
		switch(input2) {
		  case 115:
			output = 38;
			break;
		  case 61:
			output = 38;
			break;
		  case 43:
			output = 38;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 12;
			break;
		  case 97:
			output = 38;
			break;
		  case 94:
			output = 3;
			break;
		  case 112:
			output = 12;
			break;
		}
		break;
	  case 116:
		switch(input2) {
		  case 116:
			output = 116;
			break;
		  case 62:
			output = 116;
			break;
		  case 44:
			output = 116;
			break;
		  case 41:
			output = 116;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 38;
			break;
		  case 59:
			output = 116;
			break;
		  case 58:
			output = 12;
			break;
		  case 61:
			output = 38;
			break;
		  case 98:
			output = 116;
			break;
		  case 95:
			output = 116;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 38;
			break;
		  case 113:
			output = 116;
			break;
		  case 112:
			output = 12;
			break;
		  case 115:
			output = 38;
			break;
		}
		break;
	  case 117:
		switch(input2) {
		  case 117:
			output = 117;
			break;
		  case 63:
			output = 117;
			break;
		  case 45:
			output = 117;
			break;
		  case 42:
			output = 117;
			break;
		  case 40:
			output = 1;
			break;
		  case 43:
			output = 38;
			break;
		  case 60:
			output = 117;
			break;
		  case 58:
			output = 12;
			break;
		  case 61:
			output = 38;
			break;
		  case 99:
			output = 117;
			break;
		  case 96:
			output = 117;
			break;
		  case 94:
			output = 3;
			break;
		  case 97:
			output = 38;
			break;
		  case 114:
			output = 117;
			break;
		  case 112:
			output = 12;
			break;
		  case 115:
			output = 38;
			break;
		}
		break;
	  case 118:
		switch(input2) {
		  case 118:
			output = 39;
			break;
		  case 64:
			output = 39;
			break;
		  case 46:
			output = 39;
			break;
		  case 40:
			output = 1;
			break;
		  case 58:
			output = 12;
			break;
		  case 100:
			output = 39;
			break;
		  case 94:
			output = 3;
			break;
		  case 112:
			output = 12;
			break;
		}
		break;
	  case 119:
		switch(input2) {
		  case 119:
			output = 119;
			break;
		  case 65:
			output = 119;
			break;
		  case 47:
			output = 119;
			break;
		  case 41:
			output = 119;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 39;
			break;
		  case 59:
			output = 119;
			break;
		  case 58:
			output = 12;
			break;
		  case 64:
			output = 39;
			break;
		  case 101:
			output = 119;
			break;
		  case 95:
			output = 119;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 39;
			break;
		  case 113:
			output = 119;
			break;
		  case 112:
			output = 12;
			break;
		  case 118:
			output = 39;
			break;
		}
		break;
	  case 120:
		switch(input2) {
		  case 120:
			output = 120;
			break;
		  case 66:
			output = 120;
			break;
		  case 48:
			output = 120;
			break;
		  case 42:
			output = 120;
			break;
		  case 40:
			output = 1;
			break;
		  case 46:
			output = 39;
			break;
		  case 60:
			output = 120;
			break;
		  case 58:
			output = 12;
			break;
		  case 64:
			output = 39;
			break;
		  case 102:
			output = 120;
			break;
		  case 96:
			output = 120;
			break;
		  case 94:
			output = 3;
			break;
		  case 100:
			output = 39;
			break;
		  case 114:
			output = 120;
			break;
		  case 112:
			output = 12;
			break;
		  case 118:
			output = 39;
			break;
		}
		break;
	}
}

//basic idea is to precalculate all the pairings.
// This should(?) be quicker than doing it "live."
void Base121TrieRelation::mergeBoxesFlat(
      vector<int>& input1,
      vector<int>& input2,
      int& index
) const {
   static constexpr int array[121][121] = {
      {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {2, 2, 2, 3, 7, 8, 9, 7, 8, 9, 10, 11, 12, 22, 23, 24, 25, 26, 27, 28, 29, 30, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {3, 3, 3, 3, 10, 11, 12, 10, 11, 12, 10, 11, 12, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {4, 4, 7, 10, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {5, 5, 8, 11, 5, 5, 6, 8, 8, 9, 11, 11, 12, 16, 17, 18, 16, 17, 18, 19, 20, 21, 25, 26, 27, 25, 26, 27, 28, 29, 30, 34, 35, 36, 34, 35, 36, 37, 38, 39, 49, 50, 51, 52, 53, 54, 55, 56, 57, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {6, 6, 9, 12, 6, 6, 6, 9, 9, 9, 12, 12, 12, 19, 20, 21, 19, 20, 21, 19, 20, 21, 28, 29, 30, 28, 29, 30, 28, 29, 30, 37, 38, 39, 37, 38, 39, 37, 38, 39, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {7, 7, 7, 10, 7, 8, 9, 7, 8, 9, 10, 11, 12, 22, 23, 24, 25, 26, 27, 28, 29, 30, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {8, 8, 8, 11, 8, 8, 9, 8, 8, 9, 11, 11, 12, 25, 26, 27, 25, 26, 27, 28, 29, 30, 25, 26, 27, 25, 26, 27, 28, 29, 30, 34, 35, 36, 34, 35, 36, 37, 38, 39, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {9, 9, 9, 12, 9, 9, 9, 9, 9, 9, 12, 12, 12, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 37, 38, 39, 37, 38, 39, 37, 38, 39, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {10, 10, 10, 10, 10, 11, 12, 10, 11, 12, 10, 11, 12, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {11, 11, 11, 11, 11, 11, 12, 11, 11, 12, 11, 11, 12, 34, 35, 36, 34, 35, 36, 37, 38, 39, 34, 35, 36, 34, 35, 36, 37, 38, 39, 34, 35, 36, 34, 35, 36, 37, 38, 39, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {13, 13, 22, 31, 13, 16, 19, 22, 25, 28, 31, 34, 37, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {14, 14, 23, 32, 14, 17, 20, 23, 26, 29, 32, 35, 38, 14, 14, 15, 17, 17, 18, 20, 20, 21, 23, 23, 24, 26, 26, 27, 29, 29, 30, 32, 32, 33, 35, 35, 36, 38, 38, 39, 43, 44, 45, 43, 44, 45, 46, 47, 48, 52, 53, 54, 52, 53, 54, 55, 56, 57, 61, 62, 63, 61, 62, 63, 64, 65, 66, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {15, 15, 24, 33, 15, 18, 21, 24, 27, 30, 33, 36, 39, 15, 15, 15, 18, 18, 18, 21, 21, 21, 24, 24, 24, 27, 27, 27, 30, 30, 30, 33, 33, 33, 36, 36, 36, 39, 39, 39, 46, 47, 48, 46, 47, 48, 46, 47, 48, 55, 56, 57, 55, 56, 57, 55, 56, 57, 64, 65, 66, 64, 65, 66, 64, 65, 66, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {16, 16, 25, 34, 16, 16, 19, 25, 25, 28, 34, 34, 37, 16, 17, 18, 16, 17, 18, 19, 20, 21, 25, 26, 27, 25, 26, 27, 28, 29, 30, 34, 35, 36, 34, 35, 36, 37, 38, 39, 49, 50, 51, 52, 53, 54, 55, 56, 57, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {17, 17, 26, 35, 17, 17, 20, 26, 26, 29, 35, 35, 38, 17, 17, 18, 17, 17, 18, 20, 20, 21, 26, 26, 27, 26, 26, 27, 29, 29, 30, 35, 35, 36, 35, 35, 36, 38, 38, 39, 52, 53, 54, 52, 53, 54, 55, 56, 57, 52, 53, 54, 52, 53, 54, 55, 56, 57, 61, 62, 63, 61, 62, 63, 64, 65, 66, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {18, 18, 27, 36, 18, 18, 21, 27, 27, 30, 36, 36, 39, 18, 18, 18, 18, 18, 18, 21, 21, 21, 27, 27, 27, 27, 27, 27, 30, 30, 30, 36, 36, 36, 36, 36, 36, 39, 39, 39, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 64, 65, 66, 64, 65, 66, 64, 65, 66, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {19, 19, 28, 37, 19, 19, 19, 28, 28, 28, 37, 37, 37, 19, 20, 21, 19, 20, 21, 19, 20, 21, 28, 29, 30, 28, 29, 30, 28, 29, 30, 37, 38, 39, 37, 38, 39, 37, 38, 39, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {20, 20, 29, 38, 20, 20, 20, 29, 29, 29, 38, 38, 38, 20, 20, 21, 20, 20, 21, 20, 20, 21, 29, 29, 30, 29, 29, 30, 29, 29, 30, 38, 38, 39, 38, 38, 39, 38, 38, 39, 61, 62, 63, 61, 62, 63, 64, 65, 66, 61, 62, 63, 61, 62, 63, 64, 65, 66, 61, 62, 63, 61, 62, 63, 64, 65, 66, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {21, 21, 30, 39, 21, 21, 21, 30, 30, 30, 39, 39, 39, 21, 21, 21, 21, 21, 21, 21, 21, 21, 30, 30, 30, 30, 30, 30, 30, 30, 30, 39, 39, 39, 39, 39, 39, 39, 39, 39, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {22, 22, 22, 31, 22, 25, 28, 22, 25, 28, 31, 34, 37, 22, 23, 24, 25, 26, 27, 28, 29, 30, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {23, 23, 23, 32, 23, 26, 29, 23, 26, 29, 32, 35, 38, 23, 23, 24, 26, 26, 27, 29, 29, 30, 23, 23, 24, 26, 26, 27, 29, 29, 30, 32, 32, 33, 35, 35, 36, 38, 38, 39, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {24, 24, 24, 33, 24, 27, 30, 24, 27, 30, 33, 36, 39, 24, 24, 24, 27, 27, 27, 30, 30, 30, 24, 24, 24, 27, 27, 27, 30, 30, 30, 33, 33, 33, 36, 36, 36, 39, 39, 39, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {25, 25, 25, 34, 25, 25, 28, 25, 25, 28, 34, 34, 37, 25, 26, 27, 25, 26, 27, 28, 29, 30, 25, 26, 27, 25, 26, 27, 28, 29, 30, 34, 35, 36, 34, 35, 36, 37, 38, 39, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {26, 26, 26, 35, 26, 26, 29, 26, 26, 29, 35, 35, 38, 26, 26, 27, 26, 26, 27, 29, 29, 30, 26, 26, 27, 26, 26, 27, 29, 29, 30, 35, 35, 36, 35, 35, 36, 38, 38, 39, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {27, 27, 27, 36, 27, 27, 30, 27, 27, 30, 36, 36, 39, 27, 27, 27, 27, 27, 27, 30, 30, 30, 27, 27, 27, 27, 27, 27, 30, 30, 30, 36, 36, 36, 36, 36, 36, 39, 39, 39, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {28, 28, 28, 37, 28, 28, 28, 28, 28, 28, 37, 37, 37, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 28, 29, 30, 37, 38, 39, 37, 38, 39, 37, 38, 39, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {29, 29, 29, 38, 29, 29, 29, 29, 29, 29, 38, 38, 38, 29, 29, 30, 29, 29, 30, 29, 29, 30, 29, 29, 30, 29, 29, 30, 29, 29, 30, 38, 38, 39, 38, 38, 39, 38, 38, 39, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {30, 30, 30, 39, 30, 30, 30, 30, 30, 30, 39, 39, 39, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 39, 39, 39, 39, 39, 39, 39, 39, 39, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {31, 31, 31, 31, 31, 34, 37, 31, 34, 37, 31, 34, 37, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 31, 32, 33, 34, 35, 36, 37, 38, 39, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {32, 32, 32, 32, 32, 35, 38, 32, 35, 38, 32, 35, 38, 32, 32, 33, 35, 35, 36, 38, 38, 39, 32, 32, 33, 35, 35, 36, 38, 38, 39, 32, 32, 33, 35, 35, 36, 38, 38, 39, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {33, 33, 33, 33, 33, 36, 39, 33, 36, 39, 33, 36, 39, 33, 33, 33, 36, 36, 36, 39, 39, 39, 33, 33, 33, 36, 36, 36, 39, 39, 39, 33, 33, 33, 36, 36, 36, 39, 39, 39, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {34, 34, 34, 34, 34, 34, 37, 34, 34, 37, 34, 34, 37, 34, 35, 36, 34, 35, 36, 37, 38, 39, 34, 35, 36, 34, 35, 36, 37, 38, 39, 34, 35, 36, 34, 35, 36, 37, 38, 39, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {35, 35, 35, 35, 35, 35, 38, 35, 35, 38, 35, 35, 38, 35, 35, 36, 35, 35, 36, 38, 38, 39, 35, 35, 36, 35, 35, 36, 38, 38, 39, 35, 35, 36, 35, 35, 36, 38, 38, 39, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {36, 36, 36, 36, 36, 36, 39, 36, 36, 39, 36, 36, 39, 36, 36, 36, 36, 36, 36, 39, 39, 39, 36, 36, 36, 36, 36, 36, 39, 39, 39, 36, 36, 36, 36, 36, 36, 39, 39, 39, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 37, 38, 39, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 38, 38, 39, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 39, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {40, 40, 67, 94, 40, 49, 58, 67, 76, 85, 94, 103, 112, 40, 43, 46, 49, 52, 55, 58, 61, 64, 67, 70, 73, 76, 79, 82, 85, 88, 91, 94, 97, 100, 103, 106, 109, 112, 115, 118, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {41, 41, 68, 95, 41, 50, 59, 68, 77, 86, 95, 104, 113, 41, 44, 47, 50, 53, 56, 59, 62, 65, 68, 71, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 107, 110, 113, 116, 119, 41, 41, 42, 44, 44, 45, 47, 47, 48, 50, 50, 51, 53, 53, 54, 56, 56, 57, 59, 59, 60, 62, 62, 63, 65, 65, 66, 68, 68, 69, 71, 71, 72, 74, 74, 75, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 95, 95, 96, 98, 98, 99, 101, 101, 102, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {42, 42, 69, 96, 42, 51, 60, 69, 78, 87, 96, 105, 114, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 42, 42, 42, 45, 45, 45, 48, 48, 48, 51, 51, 51, 54, 54, 54, 57, 57, 57, 60, 60, 60, 63, 63, 63, 66, 66, 66, 69, 69, 69, 72, 72, 72, 75, 75, 75, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 96, 96, 96, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {43, 43, 70, 97, 43, 52, 61, 70, 79, 88, 97, 106, 115, 43, 43, 46, 52, 52, 55, 61, 61, 64, 70, 70, 73, 79, 79, 82, 88, 88, 91, 97, 97, 100, 106, 106, 109, 115, 115, 118, 43, 44, 45, 43, 44, 45, 46, 47, 48, 52, 53, 54, 52, 53, 54, 55, 56, 57, 61, 62, 63, 61, 62, 63, 64, 65, 66, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {44, 44, 71, 98, 44, 53, 62, 71, 80, 89, 98, 107, 116, 44, 44, 47, 53, 53, 56, 62, 62, 65, 71, 71, 74, 80, 80, 83, 89, 89, 92, 98, 98, 101, 107, 107, 110, 116, 116, 119, 44, 44, 45, 44, 44, 45, 47, 47, 48, 53, 53, 54, 53, 53, 54, 56, 56, 57, 62, 62, 63, 62, 62, 63, 65, 65, 66, 71, 71, 72, 71, 71, 72, 74, 74, 75, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 98, 98, 99, 98, 98, 99, 101, 101, 102, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {45, 45, 72, 99, 45, 54, 63, 72, 81, 90, 99, 108, 117, 45, 45, 48, 54, 54, 57, 63, 63, 66, 72, 72, 75, 81, 81, 84, 90, 90, 93, 99, 99, 102, 108, 108, 111, 117, 117, 120, 45, 45, 45, 45, 45, 45, 48, 48, 48, 54, 54, 54, 54, 54, 54, 57, 57, 57, 63, 63, 63, 63, 63, 63, 66, 66, 66, 72, 72, 72, 72, 72, 72, 75, 75, 75, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 99, 99, 99, 99, 99, 99, 102, 102, 102, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {46, 46, 73, 100, 46, 55, 64, 73, 82, 91, 100, 109, 118, 46, 46, 46, 55, 55, 55, 64, 64, 64, 73, 73, 73, 82, 82, 82, 91, 91, 91, 100, 100, 100, 109, 109, 109, 118, 118, 118, 46, 47, 48, 46, 47, 48, 46, 47, 48, 55, 56, 57, 55, 56, 57, 55, 56, 57, 64, 65, 66, 64, 65, 66, 64, 65, 66, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {47, 47, 74, 101, 47, 56, 65, 74, 83, 92, 101, 110, 119, 47, 47, 47, 56, 56, 56, 65, 65, 65, 74, 74, 74, 83, 83, 83, 92, 92, 92, 101, 101, 101, 110, 110, 110, 119, 119, 119, 47, 47, 48, 47, 47, 48, 47, 47, 48, 56, 56, 57, 56, 56, 57, 56, 56, 57, 65, 65, 66, 65, 65, 66, 65, 65, 66, 74, 74, 75, 74, 74, 75, 74, 74, 75, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 101, 101, 102, 101, 101, 102, 101, 101, 102, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {48, 48, 75, 102, 48, 57, 66, 75, 84, 93, 102, 111, 120, 48, 48, 48, 57, 57, 57, 66, 66, 66, 75, 75, 75, 84, 84, 84, 93, 93, 93, 102, 102, 102, 111, 111, 111, 120, 120, 120, 48, 48, 48, 48, 48, 48, 48, 48, 48, 57, 57, 57, 57, 57, 57, 57, 57, 57, 66, 66, 66, 66, 66, 66, 66, 66, 66, 75, 75, 75, 75, 75, 75, 75, 75, 75, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 102, 102, 102, 102, 102, 102, 102, 102, 102, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {49, 49, 76, 103, 49, 49, 58, 76, 76, 85, 103, 103, 112, 49, 52, 55, 49, 52, 55, 58, 61, 64, 76, 79, 82, 76, 79, 82, 85, 88, 91, 103, 106, 109, 103, 106, 109, 112, 115, 118, 49, 50, 51, 52, 53, 54, 55, 56, 57, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {50, 50, 77, 104, 50, 50, 59, 77, 77, 86, 104, 104, 113, 50, 53, 56, 50, 53, 56, 59, 62, 65, 77, 80, 83, 77, 80, 83, 86, 89, 92, 104, 107, 110, 104, 107, 110, 113, 116, 119, 50, 50, 51, 53, 53, 54, 56, 56, 57, 50, 50, 51, 53, 53, 54, 56, 56, 57, 59, 59, 60, 62, 62, 63, 65, 65, 66, 77, 77, 78, 80, 80, 81, 83, 83, 84, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 104, 104, 105, 107, 107, 108, 110, 110, 111, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {51, 51, 78, 105, 51, 51, 60, 78, 78, 87, 105, 105, 114, 51, 54, 57, 51, 54, 57, 60, 63, 66, 78, 81, 84, 78, 81, 84, 87, 90, 93, 105, 108, 111, 105, 108, 111, 114, 117, 120, 51, 51, 51, 54, 54, 54, 57, 57, 57, 51, 51, 51, 54, 54, 54, 57, 57, 57, 60, 60, 60, 63, 63, 63, 66, 66, 66, 78, 78, 78, 81, 81, 81, 84, 84, 84, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 105, 105, 105, 108, 108, 108, 111, 111, 111, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {52, 52, 79, 106, 52, 52, 61, 79, 79, 88, 106, 106, 115, 52, 52, 55, 52, 52, 55, 61, 61, 64, 79, 79, 82, 79, 79, 82, 88, 88, 91, 106, 106, 109, 106, 106, 109, 115, 115, 118, 52, 53, 54, 52, 53, 54, 55, 56, 57, 52, 53, 54, 52, 53, 54, 55, 56, 57, 61, 62, 63, 61, 62, 63, 64, 65, 66, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {53, 53, 80, 107, 53, 53, 62, 80, 80, 89, 107, 107, 116, 53, 53, 56, 53, 53, 56, 62, 62, 65, 80, 80, 83, 80, 80, 83, 89, 89, 92, 107, 107, 110, 107, 107, 110, 116, 116, 119, 53, 53, 54, 53, 53, 54, 56, 56, 57, 53, 53, 54, 53, 53, 54, 56, 56, 57, 62, 62, 63, 62, 62, 63, 65, 65, 66, 80, 80, 81, 80, 80, 81, 83, 83, 84, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 107, 107, 108, 107, 107, 108, 110, 110, 111, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {54, 54, 81, 108, 54, 54, 63, 81, 81, 90, 108, 108, 117, 54, 54, 57, 54, 54, 57, 63, 63, 66, 81, 81, 84, 81, 81, 84, 90, 90, 93, 108, 108, 111, 108, 108, 111, 117, 117, 120, 54, 54, 54, 54, 54, 54, 57, 57, 57, 54, 54, 54, 54, 54, 54, 57, 57, 57, 63, 63, 63, 63, 63, 63, 66, 66, 66, 81, 81, 81, 81, 81, 81, 84, 84, 84, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 108, 108, 108, 108, 108, 108, 111, 111, 111, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {55, 55, 82, 109, 55, 55, 64, 82, 82, 91, 109, 109, 118, 55, 55, 55, 55, 55, 55, 64, 64, 64, 82, 82, 82, 82, 82, 82, 91, 91, 91, 109, 109, 109, 109, 109, 109, 118, 118, 118, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 55, 56, 57, 64, 65, 66, 64, 65, 66, 64, 65, 66, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {56, 56, 83, 110, 56, 56, 65, 83, 83, 92, 110, 110, 119, 56, 56, 56, 56, 56, 56, 65, 65, 65, 83, 83, 83, 83, 83, 83, 92, 92, 92, 110, 110, 110, 110, 110, 110, 119, 119, 119, 56, 56, 57, 56, 56, 57, 56, 56, 57, 56, 56, 57, 56, 56, 57, 56, 56, 57, 65, 65, 66, 65, 65, 66, 65, 65, 66, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {57, 57, 84, 111, 57, 57, 66, 84, 84, 93, 111, 111, 120, 57, 57, 57, 57, 57, 57, 66, 66, 66, 84, 84, 84, 84, 84, 84, 93, 93, 93, 111, 111, 111, 111, 111, 111, 120, 120, 120, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 57, 66, 66, 66, 66, 66, 66, 66, 66, 66, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {58, 58, 85, 112, 58, 58, 58, 85, 85, 85, 112, 112, 112, 58, 61, 64, 58, 61, 64, 58, 61, 64, 85, 88, 91, 85, 88, 91, 85, 88, 91, 112, 115, 118, 112, 115, 118, 112, 115, 118, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 58, 59, 60, 61, 62, 63, 64, 65, 66, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {59, 59, 86, 113, 59, 59, 59, 86, 86, 86, 113, 113, 113, 59, 62, 65, 59, 62, 65, 59, 62, 65, 86, 89, 92, 86, 89, 92, 86, 89, 92, 113, 116, 119, 113, 116, 119, 113, 116, 119, 59, 59, 60, 62, 62, 63, 65, 65, 66, 59, 59, 60, 62, 62, 63, 65, 65, 66, 59, 59, 60, 62, 62, 63, 65, 65, 66, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {60, 60, 87, 114, 60, 60, 60, 87, 87, 87, 114, 114, 114, 60, 63, 66, 60, 63, 66, 60, 63, 66, 87, 90, 93, 87, 90, 93, 87, 90, 93, 114, 117, 120, 114, 117, 120, 114, 117, 120, 60, 60, 60, 63, 63, 63, 66, 66, 66, 60, 60, 60, 63, 63, 63, 66, 66, 66, 60, 60, 60, 63, 63, 63, 66, 66, 66, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {61, 61, 88, 115, 61, 61, 61, 88, 88, 88, 115, 115, 115, 61, 61, 64, 61, 61, 64, 61, 61, 64, 88, 88, 91, 88, 88, 91, 88, 88, 91, 115, 115, 118, 115, 115, 118, 115, 115, 118, 61, 62, 63, 61, 62, 63, 64, 65, 66, 61, 62, 63, 61, 62, 63, 64, 65, 66, 61, 62, 63, 61, 62, 63, 64, 65, 66, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {62, 62, 89, 116, 62, 62, 62, 89, 89, 89, 116, 116, 116, 62, 62, 65, 62, 62, 65, 62, 62, 65, 89, 89, 92, 89, 89, 92, 89, 89, 92, 116, 116, 119, 116, 116, 119, 116, 116, 119, 62, 62, 63, 62, 62, 63, 65, 65, 66, 62, 62, 63, 62, 62, 63, 65, 65, 66, 62, 62, 63, 62, 62, 63, 65, 65, 66, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {63, 63, 90, 117, 63, 63, 63, 90, 90, 90, 117, 117, 117, 63, 63, 66, 63, 63, 66, 63, 63, 66, 90, 90, 93, 90, 90, 93, 90, 90, 93, 117, 117, 120, 117, 117, 120, 117, 117, 120, 63, 63, 63, 63, 63, 63, 66, 66, 66, 63, 63, 63, 63, 63, 63, 66, 66, 66, 63, 63, 63, 63, 63, 63, 66, 66, 66, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {64, 64, 91, 118, 64, 64, 64, 91, 91, 91, 118, 118, 118, 64, 64, 64, 64, 64, 64, 64, 64, 64, 91, 91, 91, 91, 91, 91, 91, 91, 91, 118, 118, 118, 118, 118, 118, 118, 118, 118, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 64, 65, 66, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {65, 65, 92, 119, 65, 65, 65, 92, 92, 92, 119, 119, 119, 65, 65, 65, 65, 65, 65, 65, 65, 65, 92, 92, 92, 92, 92, 92, 92, 92, 92, 119, 119, 119, 119, 119, 119, 119, 119, 119, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 65, 65, 66, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {66, 66, 93, 120, 66, 66, 66, 93, 93, 93, 120, 120, 120, 66, 66, 66, 66, 66, 66, 66, 66, 66, 93, 93, 93, 93, 93, 93, 93, 93, 93, 120, 120, 120, 120, 120, 120, 120, 120, 120, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 66, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {67, 67, 67, 94, 67, 76, 85, 67, 76, 85, 94, 103, 112, 67, 70, 73, 76, 79, 82, 85, 88, 91, 67, 70, 73, 76, 79, 82, 85, 88, 91, 94, 97, 100, 103, 106, 109, 112, 115, 118, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {68, 68, 68, 95, 68, 77, 86, 68, 77, 86, 95, 104, 113, 68, 71, 74, 77, 80, 83, 86, 89, 92, 68, 71, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 107, 110, 113, 116, 119, 68, 68, 69, 71, 71, 72, 74, 74, 75, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 68, 68, 69, 71, 71, 72, 74, 74, 75, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 95, 95, 96, 98, 98, 99, 101, 101, 102, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {69, 69, 69, 96, 69, 78, 87, 69, 78, 87, 96, 105, 114, 69, 72, 75, 78, 81, 84, 87, 90, 93, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 69, 69, 69, 72, 72, 72, 75, 75, 75, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 69, 69, 69, 72, 72, 72, 75, 75, 75, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 96, 96, 96, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {70, 70, 70, 97, 70, 79, 88, 70, 79, 88, 97, 106, 115, 70, 70, 73, 79, 79, 82, 88, 88, 91, 70, 70, 73, 79, 79, 82, 88, 88, 91, 97, 97, 100, 106, 106, 109, 115, 115, 118, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 70, 71, 72, 70, 71, 72, 73, 74, 75, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {71, 71, 71, 98, 71, 80, 89, 71, 80, 89, 98, 107, 116, 71, 71, 74, 80, 80, 83, 89, 89, 92, 71, 71, 74, 80, 80, 83, 89, 89, 92, 98, 98, 101, 107, 107, 110, 116, 116, 119, 71, 71, 72, 71, 71, 72, 74, 74, 75, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 71, 71, 72, 71, 71, 72, 74, 74, 75, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 98, 98, 99, 98, 98, 99, 101, 101, 102, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {72, 72, 72, 99, 72, 81, 90, 72, 81, 90, 99, 108, 117, 72, 72, 75, 81, 81, 84, 90, 90, 93, 72, 72, 75, 81, 81, 84, 90, 90, 93, 99, 99, 102, 108, 108, 111, 117, 117, 120, 72, 72, 72, 72, 72, 72, 75, 75, 75, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 72, 72, 72, 72, 72, 72, 75, 75, 75, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 99, 99, 99, 99, 99, 99, 102, 102, 102, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {73, 73, 73, 100, 73, 82, 91, 73, 82, 91, 100, 109, 118, 73, 73, 73, 82, 82, 82, 91, 91, 91, 73, 73, 73, 82, 82, 82, 91, 91, 91, 100, 100, 100, 109, 109, 109, 118, 118, 118, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 73, 74, 75, 73, 74, 75, 73, 74, 75, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {74, 74, 74, 101, 74, 83, 92, 74, 83, 92, 101, 110, 119, 74, 74, 74, 83, 83, 83, 92, 92, 92, 74, 74, 74, 83, 83, 83, 92, 92, 92, 101, 101, 101, 110, 110, 110, 119, 119, 119, 74, 74, 75, 74, 74, 75, 74, 74, 75, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 74, 74, 75, 74, 74, 75, 74, 74, 75, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 101, 101, 102, 101, 101, 102, 101, 101, 102, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {75, 75, 75, 102, 75, 84, 93, 75, 84, 93, 102, 111, 120, 75, 75, 75, 84, 84, 84, 93, 93, 93, 75, 75, 75, 84, 84, 84, 93, 93, 93, 102, 102, 102, 111, 111, 111, 120, 120, 120, 75, 75, 75, 75, 75, 75, 75, 75, 75, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 75, 75, 75, 75, 75, 75, 75, 75, 75, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 102, 102, 102, 102, 102, 102, 102, 102, 102, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {76, 76, 76, 103, 76, 76, 85, 76, 76, 85, 103, 103, 112, 76, 79, 82, 76, 79, 82, 85, 88, 91, 76, 79, 82, 76, 79, 82, 85, 88, 91, 103, 106, 109, 103, 106, 109, 112, 115, 118, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 76, 77, 78, 79, 80, 81, 82, 83, 84, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {77, 77, 77, 104, 77, 77, 86, 77, 77, 86, 104, 104, 113, 77, 80, 83, 77, 80, 83, 86, 89, 92, 77, 80, 83, 77, 80, 83, 86, 89, 92, 104, 107, 110, 104, 107, 110, 113, 116, 119, 77, 77, 78, 80, 80, 81, 83, 83, 84, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 77, 77, 78, 80, 80, 81, 83, 83, 84, 77, 77, 78, 80, 80, 81, 83, 83, 84, 86, 86, 87, 89, 89, 90, 92, 92, 93, 104, 104, 105, 107, 107, 108, 110, 110, 111, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {78, 78, 78, 105, 78, 78, 87, 78, 78, 87, 105, 105, 114, 78, 81, 84, 78, 81, 84, 87, 90, 93, 78, 81, 84, 78, 81, 84, 87, 90, 93, 105, 108, 111, 105, 108, 111, 114, 117, 120, 78, 78, 78, 81, 81, 81, 84, 84, 84, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 78, 78, 78, 81, 81, 81, 84, 84, 84, 78, 78, 78, 81, 81, 81, 84, 84, 84, 87, 87, 87, 90, 90, 90, 93, 93, 93, 105, 105, 105, 108, 108, 108, 111, 111, 111, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {79, 79, 79, 106, 79, 79, 88, 79, 79, 88, 106, 106, 115, 79, 79, 82, 79, 79, 82, 88, 88, 91, 79, 79, 82, 79, 79, 82, 88, 88, 91, 106, 106, 109, 106, 106, 109, 115, 115, 118, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 79, 80, 81, 79, 80, 81, 82, 83, 84, 79, 80, 81, 79, 80, 81, 82, 83, 84, 88, 89, 90, 88, 89, 90, 91, 92, 93, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {80, 80, 80, 107, 80, 80, 89, 80, 80, 89, 107, 107, 116, 80, 80, 83, 80, 80, 83, 89, 89, 92, 80, 80, 83, 80, 80, 83, 89, 89, 92, 107, 107, 110, 107, 107, 110, 116, 116, 119, 80, 80, 81, 80, 80, 81, 83, 83, 84, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 80, 80, 81, 80, 80, 81, 83, 83, 84, 80, 80, 81, 80, 80, 81, 83, 83, 84, 89, 89, 90, 89, 89, 90, 92, 92, 93, 107, 107, 108, 107, 107, 108, 110, 110, 111, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {81, 81, 81, 108, 81, 81, 90, 81, 81, 90, 108, 108, 117, 81, 81, 84, 81, 81, 84, 90, 90, 93, 81, 81, 84, 81, 81, 84, 90, 90, 93, 108, 108, 111, 108, 108, 111, 117, 117, 120, 81, 81, 81, 81, 81, 81, 84, 84, 84, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 81, 81, 81, 81, 81, 81, 84, 84, 84, 81, 81, 81, 81, 81, 81, 84, 84, 84, 90, 90, 90, 90, 90, 90, 93, 93, 93, 108, 108, 108, 108, 108, 108, 111, 111, 111, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {82, 82, 82, 109, 82, 82, 91, 82, 82, 91, 109, 109, 118, 82, 82, 82, 82, 82, 82, 91, 91, 91, 82, 82, 82, 82, 82, 82, 91, 91, 91, 109, 109, 109, 109, 109, 109, 118, 118, 118, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 82, 83, 84, 91, 92, 93, 91, 92, 93, 91, 92, 93, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {83, 83, 83, 110, 83, 83, 92, 83, 83, 92, 110, 110, 119, 83, 83, 83, 83, 83, 83, 92, 92, 92, 83, 83, 83, 83, 83, 83, 92, 92, 92, 110, 110, 110, 110, 110, 110, 119, 119, 119, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 83, 83, 84, 92, 92, 93, 92, 92, 93, 92, 92, 93, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {84, 84, 84, 111, 84, 84, 93, 84, 84, 93, 111, 111, 120, 84, 84, 84, 84, 84, 84, 93, 93, 93, 84, 84, 84, 84, 84, 84, 93, 93, 93, 111, 111, 111, 111, 111, 111, 120, 120, 120, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 84, 93, 93, 93, 93, 93, 93, 93, 93, 93, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {85, 85, 85, 112, 85, 85, 85, 85, 85, 85, 112, 112, 112, 85, 88, 91, 85, 88, 91, 85, 88, 91, 85, 88, 91, 85, 88, 91, 85, 88, 91, 112, 115, 118, 112, 115, 118, 112, 115, 118, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 85, 86, 87, 88, 89, 90, 91, 92, 93, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {86, 86, 86, 113, 86, 86, 86, 86, 86, 86, 113, 113, 113, 86, 89, 92, 86, 89, 92, 86, 89, 92, 86, 89, 92, 86, 89, 92, 86, 89, 92, 113, 116, 119, 113, 116, 119, 113, 116, 119, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 86, 86, 87, 89, 89, 90, 92, 92, 93, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {87, 87, 87, 114, 87, 87, 87, 87, 87, 87, 114, 114, 114, 87, 90, 93, 87, 90, 93, 87, 90, 93, 87, 90, 93, 87, 90, 93, 87, 90, 93, 114, 117, 120, 114, 117, 120, 114, 117, 120, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 87, 87, 87, 90, 90, 90, 93, 93, 93, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {88, 88, 88, 115, 88, 88, 88, 88, 88, 88, 115, 115, 115, 88, 88, 91, 88, 88, 91, 88, 88, 91, 88, 88, 91, 88, 88, 91, 88, 88, 91, 115, 115, 118, 115, 115, 118, 115, 115, 118, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 88, 89, 90, 88, 89, 90, 91, 92, 93, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {89, 89, 89, 116, 89, 89, 89, 89, 89, 89, 116, 116, 116, 89, 89, 92, 89, 89, 92, 89, 89, 92, 89, 89, 92, 89, 89, 92, 89, 89, 92, 116, 116, 119, 116, 116, 119, 116, 116, 119, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 89, 89, 90, 89, 89, 90, 92, 92, 93, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {90, 90, 90, 117, 90, 90, 90, 90, 90, 90, 117, 117, 117, 90, 90, 93, 90, 90, 93, 90, 90, 93, 90, 90, 93, 90, 90, 93, 90, 90, 93, 117, 117, 120, 117, 117, 120, 117, 117, 120, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 90, 90, 90, 90, 90, 90, 93, 93, 93, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {91, 91, 91, 118, 91, 91, 91, 91, 91, 91, 118, 118, 118, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 91, 118, 118, 118, 118, 118, 118, 118, 118, 118, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 91, 92, 93, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {92, 92, 92, 119, 92, 92, 92, 92, 92, 92, 119, 119, 119, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 92, 119, 119, 119, 119, 119, 119, 119, 119, 119, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 92, 92, 93, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {93, 93, 93, 120, 93, 93, 93, 93, 93, 93, 120, 120, 120, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 120, 120, 120, 120, 120, 120, 120, 120, 120, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 93, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {94, 94, 94, 94, 94, 103, 112, 94, 103, 112, 94, 103, 112, 94, 97, 100, 103, 106, 109, 112, 115, 118, 94, 97, 100, 103, 106, 109, 112, 115, 118, 94, 97, 100, 103, 106, 109, 112, 115, 118, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {95, 95, 95, 95, 95, 104, 113, 95, 104, 113, 95, 104, 113, 95, 98, 101, 104, 107, 110, 113, 116, 119, 95, 98, 101, 104, 107, 110, 113, 116, 119, 95, 98, 101, 104, 107, 110, 113, 116, 119, 95, 95, 96, 98, 98, 99, 101, 101, 102, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120, 95, 95, 96, 98, 98, 99, 101, 101, 102, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120, 95, 95, 96, 98, 98, 99, 101, 101, 102, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {96, 96, 96, 96, 96, 105, 114, 96, 105, 114, 96, 105, 114, 96, 99, 102, 105, 108, 111, 114, 117, 120, 96, 99, 102, 105, 108, 111, 114, 117, 120, 96, 99, 102, 105, 108, 111, 114, 117, 120, 96, 96, 96, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120, 96, 96, 96, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120, 96, 96, 96, 99, 99, 99, 102, 102, 102, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {97, 97, 97, 97, 97, 106, 115, 97, 106, 115, 97, 106, 115, 97, 97, 100, 106, 106, 109, 115, 115, 118, 97, 97, 100, 106, 106, 109, 115, 115, 118, 97, 97, 100, 106, 106, 109, 115, 115, 118, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 97, 98, 99, 97, 98, 99, 100, 101, 102, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {98, 98, 98, 98, 98, 107, 116, 98, 107, 116, 98, 107, 116, 98, 98, 101, 107, 107, 110, 116, 116, 119, 98, 98, 101, 107, 107, 110, 116, 116, 119, 98, 98, 101, 107, 107, 110, 116, 116, 119, 98, 98, 99, 98, 98, 99, 101, 101, 102, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120, 98, 98, 99, 98, 98, 99, 101, 101, 102, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120, 98, 98, 99, 98, 98, 99, 101, 101, 102, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {99, 99, 99, 99, 99, 108, 117, 99, 108, 117, 99, 108, 117, 99, 99, 102, 108, 108, 111, 117, 117, 120, 99, 99, 102, 108, 108, 111, 117, 117, 120, 99, 99, 102, 108, 108, 111, 117, 117, 120, 99, 99, 99, 99, 99, 99, 102, 102, 102, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120, 99, 99, 99, 99, 99, 99, 102, 102, 102, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120, 99, 99, 99, 99, 99, 99, 102, 102, 102, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {100, 100, 100, 100, 100, 109, 118, 100, 109, 118, 100, 109, 118, 100, 100, 100, 109, 109, 109, 118, 118, 118, 100, 100, 100, 109, 109, 109, 118, 118, 118, 100, 100, 100, 109, 109, 109, 118, 118, 118, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 100, 101, 102, 100, 101, 102, 100, 101, 102, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {101, 101, 101, 101, 101, 110, 119, 101, 110, 119, 101, 110, 119, 101, 101, 101, 110, 110, 110, 119, 119, 119, 101, 101, 101, 110, 110, 110, 119, 119, 119, 101, 101, 101, 110, 110, 110, 119, 119, 119, 101, 101, 102, 101, 101, 102, 101, 101, 102, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120, 101, 101, 102, 101, 101, 102, 101, 101, 102, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120, 101, 101, 102, 101, 101, 102, 101, 101, 102, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {102, 102, 102, 102, 102, 111, 120, 102, 111, 120, 102, 111, 120, 102, 102, 102, 111, 111, 111, 120, 120, 120, 102, 102, 102, 111, 111, 111, 120, 120, 120, 102, 102, 102, 111, 111, 111, 120, 120, 120, 102, 102, 102, 102, 102, 102, 102, 102, 102, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120, 102, 102, 102, 102, 102, 102, 102, 102, 102, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120, 102, 102, 102, 102, 102, 102, 102, 102, 102, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {103, 103, 103, 103, 103, 103, 112, 103, 103, 112, 103, 103, 112, 103, 106, 109, 103, 106, 109, 112, 115, 118, 103, 106, 109, 103, 106, 109, 112, 115, 118, 103, 106, 109, 103, 106, 109, 112, 115, 118, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 103, 104, 105, 106, 107, 108, 109, 110, 111, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {104, 104, 104, 104, 104, 104, 113, 104, 104, 113, 104, 104, 113, 104, 107, 110, 104, 107, 110, 113, 116, 119, 104, 107, 110, 104, 107, 110, 113, 116, 119, 104, 107, 110, 104, 107, 110, 113, 116, 119, 104, 104, 105, 107, 107, 108, 110, 110, 111, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120, 104, 104, 105, 107, 107, 108, 110, 110, 111, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120, 104, 104, 105, 107, 107, 108, 110, 110, 111, 104, 104, 105, 107, 107, 108, 110, 110, 111, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {105, 105, 105, 105, 105, 105, 114, 105, 105, 114, 105, 105, 114, 105, 108, 111, 105, 108, 111, 114, 117, 120, 105, 108, 111, 105, 108, 111, 114, 117, 120, 105, 108, 111, 105, 108, 111, 114, 117, 120, 105, 105, 105, 108, 108, 108, 111, 111, 111, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120, 105, 105, 105, 108, 108, 108, 111, 111, 111, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120, 105, 105, 105, 108, 108, 108, 111, 111, 111, 105, 105, 105, 108, 108, 108, 111, 111, 111, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {106, 106, 106, 106, 106, 106, 115, 106, 106, 115, 106, 106, 115, 106, 106, 109, 106, 106, 109, 115, 115, 118, 106, 106, 109, 106, 106, 109, 115, 115, 118, 106, 106, 109, 106, 106, 109, 115, 115, 118, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120, 106, 107, 108, 106, 107, 108, 109, 110, 111, 106, 107, 108, 106, 107, 108, 109, 110, 111, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {107, 107, 107, 107, 107, 107, 116, 107, 107, 116, 107, 107, 116, 107, 107, 110, 107, 107, 110, 116, 116, 119, 107, 107, 110, 107, 107, 110, 116, 116, 119, 107, 107, 110, 107, 107, 110, 116, 116, 119, 107, 107, 108, 107, 107, 108, 110, 110, 111, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120, 107, 107, 108, 107, 107, 108, 110, 110, 111, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120, 107, 107, 108, 107, 107, 108, 110, 110, 111, 107, 107, 108, 107, 107, 108, 110, 110, 111, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {108, 108, 108, 108, 108, 108, 117, 108, 108, 117, 108, 108, 117, 108, 108, 111, 108, 108, 111, 117, 117, 120, 108, 108, 111, 108, 108, 111, 117, 117, 120, 108, 108, 111, 108, 108, 111, 117, 117, 120, 108, 108, 108, 108, 108, 108, 111, 111, 111, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120, 108, 108, 108, 108, 108, 108, 111, 111, 111, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120, 108, 108, 108, 108, 108, 108, 111, 111, 111, 108, 108, 108, 108, 108, 108, 111, 111, 111, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {109, 109, 109, 109, 109, 109, 118, 109, 109, 118, 109, 109, 118, 109, 109, 109, 109, 109, 109, 118, 118, 118, 109, 109, 109, 109, 109, 109, 118, 118, 118, 109, 109, 109, 109, 109, 109, 118, 118, 118, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 109, 110, 111, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {110, 110, 110, 110, 110, 110, 119, 110, 110, 119, 110, 110, 119, 110, 110, 110, 110, 110, 110, 119, 119, 119, 110, 110, 110, 110, 110, 110, 119, 119, 119, 110, 110, 110, 110, 110, 110, 119, 119, 119, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 110, 110, 111, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {111, 111, 111, 111, 111, 111, 120, 111, 111, 120, 111, 111, 120, 111, 111, 111, 111, 111, 111, 120, 120, 120, 111, 111, 111, 111, 111, 111, 120, 120, 120, 111, 111, 111, 111, 111, 111, 120, 120, 120, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 120, 120, 120, 120, 120, 120, 120, 120, 120},
      {112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 115, 118, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120, 112, 113, 114, 115, 116, 117, 118, 119, 120},
      {113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 116, 119, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120, 113, 113, 114, 116, 116, 117, 119, 119, 120},
      {114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 117, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120, 114, 114, 114, 117, 117, 117, 120, 120, 120},
      {115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 115, 118, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120, 115, 116, 117, 115, 116, 117, 118, 119, 120},
      {116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 119, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120, 116, 116, 117, 116, 116, 117, 119, 119, 120},
      {117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120, 117, 117, 117, 117, 117, 117, 120, 120, 120},
      {118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120, 118, 119, 120},
      {119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120, 119, 119, 120},
      {120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120}
   };
   
   for (int i = 0; i <= index; i++) {
      input1.at(i) = array[input1.at(i)][input2.at(i)];
   }
}