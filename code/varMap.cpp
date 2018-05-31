#include <stdlib.h>
#include <map>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "varMap.h"
#include <vector>

using namespace std;

//declared in varMap.h

//you stick things in and get them out.
//lots of methods, but most are self-explanatory.
//to update a value, just use an insert method.
varMap::varMap() {
}

void varMap::insert(const string id, const string value) {
	Data[id] = value;
}

void varMap::insert(const char* id, const char* value) {
	Data[string(id)] = string(value);
}

void varMap::insert(const char* id, const int value) {
	stringstream temp;
	temp << value;
	Data[string(id)] = temp.str();
}

void varMap::insert(const string id, const int value) {
	stringstream temp;
	temp << value;
	Data[id] = temp.str();
}

void varMap::insert(const char* id, const double value) {
	stringstream temp;
	temp << value;
	Data[string(id)] = temp.str();
}

void varMap::insert(const string id, const double value) {
	stringstream temp;
	temp << value;
	Data[id] = temp.str();
}

void varMap::insert(const char* id, const char value) {
	stringstream temp;
	temp << value;
	Data[string(id)] = temp.str();
}
void varMap::insert(const string id, const char value) {
	stringstream temp;
	temp << value;
	Data[(id)] = temp.str();
}

string varMap::get(const string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return Data[id];
}

string varMap::get(const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return Data[string(id)];
}

int varMap::getInt(const string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	return atoi(temp.c_str());
}

double varMap::getDouble(const string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	return atof(temp.c_str());
}

int varMap::getInt(const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	return atoi(temp.c_str());
}

double varMap::getDouble(const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	return atof(temp.c_str());
}
int varMap::getBool(const string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return getInt(id);
}
int varMap::getBool(const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return getInt(id);
}

char varMap::getChar(const string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	return temp[0];
}
char varMap::getChar(const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[string(id)];
	return temp[0];
}
string varMap::getStr(const string id) {
	return get(id);
}
string varMap::getStr(const char* id) {
	return get(id);
}

vector<int> varMap::getIntVector(const std::string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	string temp = Data[id];
	int curLoc = 0;
	vector<int> tbRet;
	//cout << temp << " " << temp.size() << endl;
	//cout << curLoc << " " << temp.size() << endl;
	while (curLoc < (temp.size()-1)) {
		int underscoreLoc = temp.find_first_of('_', curLoc);
		//cout << "Underscore loc is " << underscoreLoc << endl;
		string substr = temp.substr(curLoc, underscoreLoc-curLoc);
		curLoc = underscoreLoc+1;
		tbRet.push_back(atoi(substr.c_str()));
	}
	return tbRet;
}
	
vector<int> varMap::getIntVector(const char* id) {
	return getIntVector(string(id));
}

//warning: this method will only return in the form of a string.
string& varMap::operator[](const std::string id) {
	if (Data.count(id) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return Data[id];
}
string& varMap::operator[](const char* id) {
	if (Data.count(string(id)) == 0) {
		cerr << "ERROR: Could not find: " << id << endl;
	}
	return Data[string(id)];
}

vector<pair<string, string> > varMap::getKeys() {
   vector<pair<string, string> > output;
   for (auto it = Data.begin(); it!=Data.end(); it++) {
      pair<string, string> item = make_pair(it->first, it->second);
      output.push_back(item);
   }
   
   return output;
}

//testing purposes only...
/*int main() {
	varMap bob;
	bob.insert("test", "1");
	bob.insert("test2", "-5");
	bob.insert("test3", 7);
	bob.insert("test4", 84.2);
	bob.insert("test5", false);
	bob.insert("test6", 'z');
	cout << bob.get("test") << endl;
	cout << bob.get("test2") << endl;
	cout << bob.getInt("test3") << endl;
	cout << bob.getDouble("test4") << endl;
	cout << bob.getBool("test5") << endl;
	cout << bob.getChar("test6") << endl;
	cout << bob.get("test3") << endl;
	cout << bob.get("emptytest") << endl;
	bob.insert("test6", 'a');
	cout << bob.get("test6") << endl;
	bob["test7"] = "frog";
	cout << bob["test7"] << endl;
	return 0;
}
*/