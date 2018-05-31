#ifndef _VARMAP_H
#define _VARMAP_H

#include <string.h>
#include <map>
#include <vector>

class varMap {
	std::map<std::string,std::string> Data;
  public:
	varMap();
	
	void insert(const std::string id, const std::string value);
	
	void insert(const char* id, const char* value);
	
	void insert(const char* id, const int value);
	
	void insert(const std::string id, const int value);
	
	void insert(const char* id, const double value);
	
	void insert(const std::string id, const double value);
	
	void insert(const char* id, const char value);
	
	void insert(const std::string id, const char value);
	
	std::string get(const std::string id);
	std::string get(const char* id);
	
	int getInt(const std::string id);
	double getDouble(const std::string id);
	int getInt(const char* id);
	double getDouble(const char* id);
	
	int getBool(const std::string id);
	int getBool(const char* id);
	
	char getChar(const std::string id);
	char getChar(const char* id);
	
	std::string getStr(const std::string id);
	std::string getStr(const char* id);
	
	std::vector<int> getIntVector(const std::string id);
	std::vector<int> getIntVector(const char* id);
	
	std::string& operator[](const std::string id);
	std::string& operator[](const char* id);
   
   std::vector<std::pair<std::string, std::string> > getKeys();
};

extern varMap gvars;
const std::string RATIO = "ratio";
const std::string ORDERING = "ordering";

//This is the method for incrementing the COUNTS variable during load.
//Set to "mult" to consider the size of the clause.
//Default is "plusone"
const std::string COUNT_METHOD = "countMethod";

//constant, global DB name
//default allows skipping, set to noSkips to disable
const std::string DB_TYPE = "dbType";
//local constraint database name
//default allows skipping, set to noSkips to disable
const std::string CDB_TYPE = "cdbType";
//whether or not to preprocess
//default to true (1)
const std::string PREPROCESS = "preprocess";
//sets how the initial max "best" value is set for MaxSAT.
//default to fromFile
//can be set to infinity
const std::string INITIAL_MAX = "initialMax";

//sets whether or not to use singleton code in SIMD
//defaults to true
const std::string SINGLETON = "singleton";

//sets which variables to predefine
//defaults to none
const std::string PREDEFS = "predefs";

//sets output filename
//defaults to none
const std::string OUTFILE = "outfile";

//suppress output
//defaults to false (0)
const std::string SILENCE = "silence";
#endif //_VARMAP_H