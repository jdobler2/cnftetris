// ============================================================================
// subgraphcount.cpp
// ~~~~~~~~~~~~~~~~
// author: hqn
// may 04, 2014
// USAGE: subgraphcount [m/s]
//            m is for multi-thread
//            s is for single-thread
//        if no option is given then 'm' is the default
// ============================================================================

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>   
#include <vector>   
#include <map>   
#include <set>   
#include <math.h>   
#include <sys/time.h>
#include <stdexcept>
#include <boost/thread.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

#include "BFSRelation.h"
#include "SimpleRelation.h"
#include "DegreeRelation.h"
#include "SIMD_Relation.h"
#include "SIMD_RLERelation.h"
#include "SIMD_HybridRelation.h"
#include "TrieRelation.h"
#include "IterTrieRelation.h"
#include "IntTrieRelation.h"
#include "CNFIntTrieRelation.h"
#include "Base121TrieRelation.h"
#include "Base243TrieRelation.h"
#include "Locks243Relation.h"

#include "term_control.h"
#include "error_handling.h"
#include "algos.h"
#include "varMap.h"
#include "clause.h"

using namespace std;

typedef void (*cmd_handler_t)(const vector<string>&);
static const int COL_WIDTH = 30;
static bool multithreadMode = true;
static string iInputFile;
static string iModes;
static string iOutputFile;
static string iPredefs;
static int relSize = 1;

/**
 * global relation, reset everytime a new 'load' is called
 * use of unique_ptr is to follow Google C++ style guide
 * http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml
 */
unique_ptr<Relation> relationPtr;

/**
 * load a given SNAP format file into a Relation data structure
 * tokens is the set of input tokens from the command line
 */
void load(const vector<string>& tokens);

/**
 * load a given CNF format file into a supporting Relation data structure
 * tokens is the set of input tokens from the command line
 */
void loadCNF(const vector<string>& tokens);

/**
 * load a given WCNF format file into a supporting Relation data structure
 * tokens is the set of input tokens from the command line
 */
void loadMax(const vector<string>& tokens);

/**
 * load a PROG dataset's evidence file
 */
void loadProg(const vector<string>& tokens);

/**
 * Sets a parameter to the given value
 * tokens contains the variable name and its value
 */
void setval(const vector<string>& tokens);

/**
 * Print value of a given parameter
 * tokens contain variable name
 */
void print(const vector<string>& tokens);

/**
 * read data from file 'fileName' into a vector of pairs
 */
void loadRawData(const string& fileName, vector<pair<unsigned, unsigned> >& v);

/**
 * read wcnf data from 'fileName' into a vector of pairs
 * returns maxNodeID
 */
int loadMaxDataSigned(const string& fileName, vector<clause>& v,
                       vector<std::pair<int, int> >& counts,
                       int& maxWeight);

/**
 * read signed data from file 'fileName' into a vector of pairs
 * returns maxNodeID
 */
int loadRawDataSigned(const string& fileName, vector<vector<int> >& v, 
                      vector<std::pair<int, int> >& counts);
/** 
 * Reads the prog data and converts it into a graph dataset by treating each argument as a node 
 * and letting the tuples define edges
 */
int loadProgData(const string& fileName, vector<pair<unsigned, unsigned> >& v,
                      vector<std::pair<int, int> >& counts);
                      
/** 
 * Reads the prog data and converts it into a graph dataset by treating each tuple as a node 
 * and letting the inference rules define edges
 */
int loadFullProgData(const string& fileName, const string& progFileName);

                      
/**
 * call the appropriate triangle counting algorithm
 * tokens is the set of input tokens from the command line
 */
void tricount(const vector<string>& tokens);

// set the threading mode
void mthread(const vector<string>& tokens) { multithreadMode = true; }
void sthread(const vector<string>& tokens) { multithreadMode = false; }

// quit the program
void bye(const vector<string>& tokens) { exit(0); }

// comment line, skip it
void comment(const vector<string>& tokens) { }

// print a prompt '>'
void prompt() { cout << term_cc(BLUE) << "> " << term_cc() << flush; }

// command line is supposed to be 'subgraphcount [m | s]'
void parseCommandLine(int, char**);

// disable cout
void silence(const vector<string>& tokens) {
   gvars.insert(SILENCE, 1);
   std::cout.setstate(std::ios_base::failbit);
   std::cerr.setstate(std::ios_base::failbit);
}
// enable cout
void unsilence(const vector<string>& tokens) {
   std::cout.clear();
   std::cerr.clear();
}

/** 
 * currently, commmands supported include the following
 * load file.txt mode      //
 * mthread                 // set multithread mode
 * sthread                 // set singlthread mode
 * [ tricount | tc ] algo
 * [ quit | bye | exit ]
 */
map<string, cmd_handler_t> loadCommands();

void initializeGvars() {
   gvars.insert(RATIO, .5);
   gvars.insert(ORDERING, "degreeDesc");
   gvars.insert(COUNT_METHOD, "plusone");
   gvars.insert(DB_TYPE, "skips");
   gvars.insert(CDB_TYPE, "skips");
   gvars.insert(PREPROCESS, "1");
   gvars.insert(INITIAL_MAX, "fromFile");
   gvars.insert(SINGLETON, "1");
   gvars.insert(PREDEFS, "");
   gvars.insert(OUTFILE, "");
   gvars.insert(SILENCE, "0");
}

int main(int argc, char **argv) 
{
   initializeGvars();
   iModes = "-1";

   parseCommandLine(argc, argv);
   map<string, cmd_handler_t> commands = loadCommands();
   string line;
   
   if (iModes != "-1") {
      vector<string> tokens;
      tokens.push_back("loadcnf");
      tokens.push_back(iInputFile);
      tokens.push_back(iModes);

      if (argc >= 6) {
         gvars.insert(OUTFILE, iOutputFile);
      }
      
      if (argc >= 7) {
         gvars.insert(PREDEFS, iPredefs);
      }
      
      struct timeval tv;
      gettimeofday(&tv, NULL);     // mark start time
      std::cout << "Executing..." << std::endl;
      commands[tokens[0]](tokens); // execute command
      struct timeval tv2;          // mark finish time
      gettimeofday(&tv2, NULL);
      ostringstream oss;
      oss << left << setw(COL_WIDTH) << fixed
         << "seconds elapsed: " 
         << double(tv2.tv_sec - tv.tv_sec) + 
         double(tv2.tv_usec - tv.tv_usec)/1000000;
      report(oss.str());   
      
      tokens.clear();
      tokens.push_back("tc");
      tokens.push_back("fr");
      
      gettimeofday(&tv, NULL);     // mark start time
      commands[tokens[0]](tokens); // execute command
      gettimeofday(&tv2, NULL);
      ostringstream oss2;
      oss2 << left << setw(COL_WIDTH) << fixed
         << "seconds elapsed: " 
         << double(tv2.tv_sec - tv.tv_sec) + 
         double(tv2.tv_usec - tv.tv_usec)/1000000;
      report(oss2.str());   
      
      return 0;
   }

   while (cin) {
      prompt(); getline(cin, line); 
      std::cout << "Line: " << line << std::endl;
      vector<string> tokens;
      using namespace boost::algorithm;
      split(tokens, line, is_any_of("\t\n\r "));
      if (tokens.size() == 0) continue;

      if (commands.find(tokens[0]) != commands.end()) {
         try {
            struct timeval tv;
            gettimeofday(&tv, NULL);     // mark start time
            commands[tokens[0]](tokens); // execute command
            struct timeval tv2;          // mark finish time
            gettimeofday(&tv2, NULL);
            ostringstream oss;
            oss << left << setw(COL_WIDTH) << fixed
               << "seconds elapsed: " 
               << double(tv2.tv_sec - tv.tv_sec) + 
               double(tv2.tv_usec - tv.tv_usec)/1000000;
            report(oss.str());          
            continue;
         } catch (exception &e) {
            error_return(e.what());
         }
      } else {
         error_return("Unknown command");
      }
   }

   return 0;
}

// just a helper for relFactory below
template<typename T> 
unique_ptr<Relation> getPtr() 
{
   return unique_ptr<Relation>(new T); 
}

unique_ptr<Relation> relFactory(const string& mode) 
{
   // C++ doesn't have native support for the reflection pattern, 
   // here's a simple way to mimic it
   std::map<std::string, unique_ptr<Relation> (*)()> mymap;

   mymap["0"]           = &getPtr<SimpleRelation>;
   mymap["simple"]      = &getPtr<SimpleRelation>;
   mymap["1"]           = &getPtr<BFSRelation>;
   mymap["bfs"]         = &getPtr<BFSRelation>;
   mymap["2"]           = &getPtr<SIMD_BFSRelation>;
   mymap["simd_bfs"]    = &getPtr<SIMD_BFSRelation>;
   mymap["3"]           = &getPtr<SIMD_DegreeRelation>;
   mymap["simd_degree"] = &getPtr<SIMD_DegreeRelation>;
   mymap["4"]           = &getPtr<DegreeRelation>;
   mymap["degree"]      = &getPtr<DegreeRelation>;
   mymap["5"]           = &getPtr<SIMD_RLERelation>;
   mymap["simd_rle"]    = &getPtr<SIMD_RLERelation>;
   mymap["6"]           = &getPtr<SIMD_HybridRelation>;
   mymap["simd_hybrid"] = &getPtr<SIMD_HybridRelation>;
   mymap["7"]           = &getPtr<TrieRelation>;
   mymap["trie"]        = &getPtr<TrieRelation>;
   mymap["8"]           = &getPtr<IterTrieRelation>;
   mymap["itrie"]       = &getPtr<IterTrieRelation>;
   mymap["inttrie"]     = &getPtr<IntTrieRelation>;
   mymap["9"]           = &getPtr<IntTrieRelation>;
   mymap["10"]          = &getPtr<CNFIntTrieRelation>;
   mymap["smallinttrie"]= &getPtr<CNFIntTrieRelation>;
   mymap["11"]          = &getPtr<Base121TrieRelation>;
   mymap["b121"]        = &getPtr<Base121TrieRelation>;
   mymap["12"]          = &getPtr<Base243TrieRelation>;
   mymap["b243"]        = &getPtr<Base243TrieRelation>;
   mymap["13"]          = &getPtr<Locks243Relation>;
   mymap["locks"]       = &getPtr<Locks243Relation>;
   mymap["lock"]        = &getPtr<Locks243Relation>;

   

   if (mymap.find(mode) == mymap.end()) {
      throw runtime_error("Unknown mode");
   }

   return mymap[mode]();
}

void load(const vector<string>& tokens)
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: load edgeFile.txt MODE (SNAP format)");
   }

   vector<pair<unsigned, unsigned> > rawPairs;
   loadRawData(tokens[1], rawPairs);    // tokens[1] is file name
   relationPtr = relFactory(tokens[2]); // tokens[2] is the mode
   relationPtr->buildIndex(rawPairs);
}

void loadCNF(const vector<string>& tokens) 
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: loadcnf cnfFile.txt (CNF format)");
   }
   
   
   
   vector<vector<int> > rawPairs;
   vector<std::pair<int, int> > counts;
   //std::cout << "About to load..." << std::endl;
   int maxNodeID = loadRawDataSigned(tokens[1], rawPairs, counts);
   /*std::cout << "average count of top 10%: ";
   vector<std::pair<int, int> > counts2 = counts;
   std::sort(counts2.begin(), counts2.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
   });
   int totalSize = 0;
   for (int i = 0; i < counts2.size()/10; i++) {
      std::cout << counts2.at(i).second << std::endl;
      totalSize += counts2.at(i).second;
   }
   std::cout << ((double)totalSize) / (counts2.size()/10) << std::endl;*/
   relationPtr = relFactory(tokens[2]);
   //relationPtr = relFactory("11");
   relationPtr->buildIndexCNF(rawPairs, maxNodeID, counts);
   relSize = rawPairs.size();
}

void loadMax(const vector<string>& tokens) 
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: loadmax wcnfFile.txt MODE (WCNF (MaxSAT) format)");
   }
   
   vector<clause> rawPairs;
   vector<std::pair<int, int> > counts;
   int maxWeight = 0;
   int maxNodeID = loadMaxDataSigned(tokens[1], rawPairs, counts, maxWeight);
   if (maxWeight <= 0) maxWeight = -1;
         
   relationPtr = relFactory(tokens[2]);
   relationPtr->buildIndexMax(rawPairs, maxNodeID, counts, maxWeight);

}

void loadProg(const vector<string>& tokens) 
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: loadprog evidenceFile.db MODE (Prog/evidence/query format)");
   }
   vector<pair<unsigned, unsigned> > rawPairs;
   vector<std::pair<int, int> > counts;
   int maxNodeID = loadProgData(tokens[1], rawPairs, counts);
   relationPtr = relFactory(tokens[2]);
   relationPtr->buildIndex(rawPairs);
}


void fullProg(const vector<string>& tokens) 
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: fullprog evidenceFile.db progFile.prog");
   }
   loadFullProgData(tokens[1], tokens[2]);

}

void setval(const vector<string>& tokens) 
{
   if (tokens.size() != 3) {
      throw runtime_error("Usage: set VAR_NAME VALUE");
   }
  
   gvars.insert(tokens[1], tokens[2]);
}

void print(const vector<string>& tokens)
{
   if (tokens.size() != 2) {
      throw runtime_error("Usage: print VAR_NAME");
   }
   
   if (tokens[1]=="all") {
      vector<pair<string, string> > list = gvars.getKeys();
      for (int i = 0; i < list.size(); i++) {
         std::cout << list.at(i).first << ": " << list.at(i).second << std::endl;
      }
   }
   else {
      std::cout << tokens[1] << ": " << gvars.getStr(tokens[1]) << std::endl;
   }
}

void loadRawData(const string& fileName, vector<pair<unsigned, unsigned> >& v)
{
   boost::iostreams::mapped_file mmapFile;
   try {
      mmapFile.open(fileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   if (!mmapFile.is_open()) {
      throw runtime_error(string("Failed to open ") + fileName);
   } 

   bool cry = false;

   const char* front = mmapFile.const_data();
   const char* back = front + mmapFile.size();

   while (front != back)                     // for each line
   {
      if (front[0] == '#') {                 // comment line in SNAP format
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }

      // parse integers, TODO: should check formatting errors here
      unsigned val[2];
      val[0] = val[1] = 0;
      int ref = 0;
      for ( ; ref < 2; front++) {
         if (front[0] <= 32) { // if first char is a control code
            ref++;            // i.e. tab, space, or \n
         } else {             // assume numeric
            val[ref] = 10 * val[ref] + front[0] - '0';
         }
      }

      if (val[0] != val[1]) // TODO: should we add loops too?
         v.push_back(std::make_pair(val[0],val[1]));

      front++;
   }
   mmapFile.close();

   // Next, post-processing to remove duplicate edges
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   
}

int loadRawDataSignedCin(vector<vector<int> >& v, 
                         vector<std::pair<int, int> >& counts)
{
   char c;
   int nCls, nVars;
   string idstring;
   
   int countMethod = 0;
   if (gvars.getStr(COUNT_METHOD)=="mult") {
      countMethod = 1;
   }
   
   bool cry = false;

   int maxNodeID = 0;
   
   char buff[65536];
   
   while (std::cin.getline(buff, 65535)) {
      char* front = buff;
      if (front[0] == 'c' || front[0] == 'p') { // comment line in CNF format
         if (front[0] == 'p') {
            front+=6;
            for(bool exit = false;exit==false; front++) {
               switch(front[0]) {
                case ' ':
                  exit = true;
                  break;
                default:
                  maxNodeID = 10 * maxNodeID + front[0] - '0';
               }
            }
            counts.resize(maxNodeID+1, std::pair<int, int>(0,0));
            for (int i = 0; i < counts.size(); i++) {
               counts.at(i).first = i;
            }
         }
         continue; 
      }

      // parse integers, TODO: should check formatting errors here, use switch
      vector<int> val;
      val.push_back(0);
      int multiplier = 1;
      for ( ; ; front++) {
         if (front[0] == 32) { // if first char is space
            if (val.back()!=0) {
               val.back() *= multiplier; 
               multiplier = 1;
               val.push_back(0);
            }
         } else if (front[0] < 32) { //i.e. \0
            val.pop_back();
            break;
         } else if (front[0]=='0' && val.back()==0) { //end-of-line 0
            continue;
         }
         else {             // assume numeric
            if (front[0] == '-') {
               multiplier = -1;
            }
            else {
               val.back() = 10 * val.back() + front[0] - '0';
            }
         }
      } //finish reading individual line
      //
      if (val.size() > 0) { //extra guard for CNF gen'd on Windows
         for (int i = 0; i < val.size(); i++) {
            if (countMethod == 1) { //mult
               counts.at(std::abs(val.at(i))).second+=val.size();
            }
            else {
               counts.at(std::abs(val.at(i))).second++;
            }
         }
         v.push_back(val);
      }
      front++;
   
   }
   
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   return maxNodeID;
}

int loadRawDataSigned(const string& fileName, vector<vector<int> >& v, 
                      vector<std::pair<int, int> >& counts)
{
   if (fileName == "STDIN" || fileName == "stdin" || fileName == "cin") {
      return loadRawDataSignedCin(v, counts);
   }
   boost::iostreams::mapped_file mmapFile;
   std::cout << "Loading " << fileName << std::endl;
   try {
      mmapFile.open(fileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   std::cout << "Please let this print." << std::endl;
   
   if (!mmapFile.is_open()) {
      throw runtime_error(string("Failed to open ") + fileName);
   } 

   int countMethod = 0;
   if (gvars.getStr(COUNT_METHOD)=="mult") {
      countMethod = 1;
   }
   
   bool cry = false;

   const char* front = mmapFile.const_data();
   const char* back = front + mmapFile.size();

   int maxNodeID = 0;
   
   while (front != back)                     // for each line
   {
      if (front[0] == 'c' || front[0] == 'p') { // comment line in CNF format
                                                //TODO: handle 'p' line smartly
         if (front[0] == 'p') {
            front+=6;
            for(bool exit = false;exit==false; front++) {
               switch(front[0]) {
                case ' ':
                  exit = true;
                  break;
                default:
                  maxNodeID = 10 * maxNodeID + front[0] - '0';
               }
            }
            counts.resize(maxNodeID+1, std::pair<int, int>(0,0));
            for (int i = 0; i < counts.size(); i++) {
               counts.at(i).first = i;
            }
         }
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }

      // parse integers, TODO: should check formatting errors here, use switch
      vector<int> val;
      val.push_back(0);
      int multiplier = 1;
      bool zeroFlag = false;
      for ( ; ; front++) {
         if (front[0] == 32) { // if first char is space
            if (val.back()!=0) {
               val.back() *= multiplier; 
               multiplier = 1;
               val.push_back(0);
            }
         } else if (front[0] == '\n') { //i.e. \n
            if (zeroFlag) {
               val.pop_back();
               break;
            }
            else {
               continue;
            }
         } else if (front[0]=='0' && val.back()==0) { //end-of-line 0
            zeroFlag = true;
            continue;
         }
         else {             // assume numeric
            if (front[0] == '-') {
               multiplier = -1;
            }
            else {
               val.back() = 10 * val.back() + front[0] - '0';
            }
         }
      } //finish reading individual line
      //
      if (val.size() > 0) { //extra guard for CNF gen'd on Windows
         for (int i = 0; i < val.size(); i++) {
            if (countMethod == 1) { //mult
               counts.at(std::abs(val.at(i))).second+=val.size();
            }
            else {
               counts.at(std::abs(val.at(i))).second++;
            }
         }
         v.push_back(val);
      }
      front++;
   }
   mmapFile.close();

   // Next, post-processing to remove duplicate edges
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   return maxNodeID;
}

int loadMaxDataSigned(const string& fileName, vector<clause>& v, 
                      vector<std::pair<int, int> >& counts,
                      int& maxWeight)
{
   boost::iostreams::mapped_file mmapFile;
   try {
      mmapFile.open(fileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   if (!mmapFile.is_open()) {
      throw runtime_error(string("Failed to open ") + fileName);
   } 

   int countMethod = 0;
   if (gvars.getStr(COUNT_METHOD)=="mult") {
      countMethod = 1;
   }
   
   bool cry = false;

   const char* front = mmapFile.const_data();
   const char* back = front + mmapFile.size();

   int maxNodeID = 0;
   int clauseCount = 0;

   while (front != back)                     // for each line
   {
      if (front[0] == 'c' || front[0] == 'p') { // comment line in CNF format
                                                //TODO: handle 'p' line smartly
         if (front[0] == 'p') {
            front+=7; //move pointer past the header
            
            //get number of nodes
            for(bool exit = false;exit==false; front++) {
               switch(front[0]) {
                case ' ':
                  exit = true;
                  break;
                default:
                  maxNodeID = 10 * maxNodeID + front[0] - '0';
               }
            }
            counts.resize(maxNodeID+1, std::pair<int, int>(0,0));
            for (int i = 0; i < counts.size(); i++) {
               counts.at(i).first = i;
            }
            
            //get number of clauses
            for(bool exit = false; exit==false; front++) {
               if (front[0] < '0') break;
               else  {
                  clauseCount = 10 * clauseCount + front[0] - '0';
               }
            }
            
            //get maxWeight, if it exists
            if (front[0] != '\n') {
               front++;
               for (bool exit = false; exit==false; front++) {
                  if (front[0] < '0') break;
                  else {
                     maxWeight = 10 * maxWeight + front[0] - '0';
                  }
               }
            }
         }
         
         //advance to next line
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }

      // parse integers, TODO: should check formatting errors here, use switch
      vector<int> val;
      //val.push_back(0);
      int multiplier = 1;
      int weight = -1;
      int tempValue = 0;
      for ( ; ; front++) {
         if (front[0] == ' ') { // if first char is space
            if (weight == -1) { //tempValue holds the weight
               weight = tempValue;
               tempValue = 0;
               continue;
            }
            else if (tempValue!=0) { //so we don't grab the 0 at line ends
               tempValue *= multiplier; 
               multiplier = 1;
               val.push_back(tempValue);
               tempValue = 0;
            }
         } else if (front[0] < 32) { //i.e. \n
            tempValue = 0;
            break;
         } else if (front[0]=='0' && tempValue == 0) { //end-of-line 0
            continue;
         }
         else {             // assume numeric
            if (front[0] == '-') {
               multiplier = -1;
            }
            else {
               tempValue = 10 * tempValue + front[0] - '0';
            }
         }
      } //finish reading individual line
      //
      if (val.size() > 0) { //extra guard for CNF gen'd on Windows
         for (int i = 0; i < val.size(); i++) {
            if (countMethod == 1) { //mult
               counts.at(std::abs(val.at(i))).second+=val.size();
            }
            else {
               counts.at(std::abs(val.at(i))).second++;
            }
         }
         clause tempClause;
         tempClause.values = val;
         tempClause.weight = weight;
         v.push_back(tempClause);
      }
      front++;
   }

   mmapFile.close();

   // Next, post-processing to remove duplicate edges
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   return maxNodeID;
}

//currently only handles the evidence.db file. Also, we're ignoring types.
//TODO: integrate everything. Somehow.
int loadProgData(const string& fileName, vector<pair<unsigned, unsigned> >& v, 
                      vector<std::pair<int, int> >& counts)
{
   boost::iostreams::mapped_file mmapFile;
   try {
      mmapFile.open(fileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   if (!mmapFile.is_open()) {
      throw runtime_error(string("Failed to open ") + fileName);
   } 
   std::cout << "File opened." << std::endl;
   int countMethod = 0;
   if (gvars.getStr(COUNT_METHOD)=="mult") {
      countMethod = 1;
   }
   
   bool cry = false;

   const char* front = mmapFile.const_data();
   const char* back = front + mmapFile.size();

   int maxNodeID = 0;
   
   map<string, int> dictionary;
   
   while (front != back)                     // for each line
   {
      if (front[0]=='/' && front[1]=='/') { //comment
       //  std::cout << "Found comment." << std::endl;
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }
      
      vector<int> vals;
      while (front[0] >= 32) { //i.e., is not a control character
         if (front[0]!='"') {
            //std::cout << "Front is: " << front[0] << std::endl;
            front++;
            continue;
         }
         else {
          //  std::cout << "quote found." << std::endl;
            front++;
            string str;
            while (front[0]!='"') {//need a slightly better way to capture...
               str.append(front, 1); //legal syntax?
               front++;
            }
         //   std::cout << "String found: " << str << std::endl;
            //grab int from dict, put in val
            if (dictionary.count(str)==0) {
               dictionary[str] = maxNodeID++;
            }
            
            vals.push_back(dictionary[str]);
         }
         front++;
      }//We've reached the end of a line, store vals
      
      //get rid of reflexives
      if (vals.size()==2 && vals.at(0)==vals.at(1)) {
         front++;
         continue;
      }
      
      //nothing to do with 1-off's right now
      if (vals.size()==1) {
         front++;
         continue;
      }
      //Sort
      std::sort(vals.begin(), vals.end());
      
      //split up biggies
      for (int i = 0; i < vals.size(); i++) {
         for (int j = 1; j < vals.size(); j++) {
            v.push_back(std::make_pair(vals.at(i), vals.at(j)));
         }
      }
      front++;
   }//file fully scanned
   mmapFile.close();

   // Next, post-processing to remove duplicate edges
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   return maxNodeID;
}

bool recursiveAddition(vector<vector<int> >& infRule, int location, vector<vector<int> >& idSets, map<int, int>& pastAssignments) {
   vector<int> currentRule = infRule.at(location);
   if (currentRule.size()==0) {
    //  std::cout << "About to insert." << std::endl;
      location++;
      currentRule = infRule.at(location);
      vector<int> setToInsert;
      setToInsert.push_back(currentRule.at(0));
      for (int i = 1; i < currentRule.size(); i++) {
         if (pastAssignments.count(currentRule.at(i)) > 0) {
            setToInsert.push_back(pastAssignments.at(currentRule.at(i)));
         }
         else {
            std::cout << "WTF?! Location: " << location << ", size: " << currentRule.size() << "; i = " << i << endl;
            std::cout << "Printing full rule: " << std::endl;
            for (int j = 0; j < infRule.size(); j++) {
               for (int k = 0; k < infRule.at(j).size(); k++) {
                  std::cout << "j: " << j << "; k: " << k << "; " << infRule.at(j).at(k) << std::endl;
               }
            }
            throw runtime_error("WTF");
         }
      }
      
      //make sure not already contained
      bool cry = false;
      for (int i = 0; i < idSets.size(); i++) {
         bool equal = true;
         for (int j = 0; j < idSets.at(i).size(); j++) {
            if (idSets.at(i).at(j) != setToInsert.at(j)) {
               equal = false;
               break;
            }
         }
         if (equal) {
            cry = true;
            break;
         }
      }
      //if !cry, we have a new element to insert
 //     std::cout << "Insertion 'complete'" << endl;
      if (!cry) {
         idSets.push_back(setToInsert);
         return true;
      }
      return false;
   }
   else if (currentRule.at(0)==0) {
      //TODO: Handle math
      std::cout <<" I can't deal with math" << std::endl;
   }
   else {
      if (currentRule.at(0) < 0) {
         std::cout << "Negative detected." << std::endl;
         bool cry = false;
         for (int i = 0; i < idSets.size(); i++) {
            if (idSets.at(i).at(0) == currentRule.at(0) * -1) {
               bool equals = true;
               for ( int j = 1; j < idSets.at(i).size(); j++) {
                  if (idSets.at(i).at(j) != pastAssignments.at(currentRule.at(j))) {
                     equals = false;
                     break;
                  }
               }
               if (equals) {
                  cry = true;
                  break;
               }
            }
         }
         std::cout << "Past dealing with negative." << std::endl;
         if (cry) return false;
         else return recursiveAddition(infRule, location + 1, idSets, pastAssignments);
      }
      
      //else, dealing with a positive. 
  //    std::cout << "Dealing with a positive." << std::endl;
      bool totalResult = false;
      for (int i = 0; i < idSets.size(); i++) {
         if (idSets.at(i).at(0) == currentRule.at(0)) {
            bool cry = false;
            vector<int> myAssignments;
            for (int j = 1; j < idSets.at(i).size(); j++) {
               if (pastAssignments.count(currentRule.at(j))==0) {
           //       std::cout << "Assigning " << currentRule.at(j) << " = " << idSets.at(i).at(j) << endl;
                  myAssignments.push_back(currentRule.at(j));
                  pastAssignments[currentRule.at(j)] = idSets.at(i).at(j);
               }
               else {
                  if (pastAssignments.at(currentRule.at(j))!=idSets.at(i).at(j)) {
                     cry = true;
                     break;
                  }
               }
            }
            if (!cry) {
               totalResult |= recursiveAddition(infRule, location + 1, idSets, pastAssignments);
            }
            //cleanup
            for ( int j = 0; j < myAssignments.size(); j++) {
               pastAssignments.erase(myAssignments.at(j));
            }
         }
      }
      
      return totalResult;
   }
}

//TODO: Merge with above function, rather than have two nearly identical ones
bool recursivePrint(vector<vector<int> >& infRule, int location, vector<vector<int> >& idSets, map<int, int>& pastAssignments, ofstream& file) {
   vector<int> currentRule = infRule.at(location);
   if (currentRule.size()==0) {
      return recursivePrint(infRule, location+1, idSets, pastAssignments, file);
   }
   else if (currentRule.at(0)==0) {
      //TODO: Handle math
      std::cout <<" I can't deal with math" << std::endl;
   }
   else {
      //handle negative
      if (currentRule.at(0) < 0) {
         bool cry = false;
         for (int i = 0; i < idSets.size(); i++) {
            if (idSets.at(i).at(0) == currentRule.at(0) * -1) {
               bool equals = true;
               for ( int j = 1; j < idSets.at(i).size(); j++) {
                  if (idSets.at(i).at(j) != pastAssignments.at(currentRule.at(j))) {
                     equals = false;
                     break;
                  }
               }
               if (equals) {
                  cry = true;
                  break;
               }
            }
         }
         if (cry) return false;
         else if (location + 1 == infRule.size()) {
            //output result
            std::cout << "Outputting negative... " << std::endl;
            for (int i = -1; -1 * i <= infRule.size(); i--) {
               if (pastAssignments.count(i) > 0) {         
                  file << pastAssignments[i] << " ";
               }
            }
            file << "0\n";
            return true;
         }
         else return recursivePrint(infRule, location + 1, idSets, pastAssignments, file);
      }//end handling negative
      
      //else, dealing with a positive. 
      bool totalResult = false;
      for (int i = 0; i < idSets.size(); i++) {
         if (idSets.at(i).at(0) == currentRule.at(0)) {
            bool cry = false;
            vector<int> myAssignments;
            for (int j = 1; j < idSets.at(i).size(); j++) {
               if (pastAssignments.count(currentRule.at(j))==0) {
                  myAssignments.push_back(currentRule.at(j));
                  pastAssignments[currentRule.at(j)] = idSets.at(i).at(j);
               }
               else {
                  if (pastAssignments.at(currentRule.at(j))!=idSets.at(i).at(j)) {
                     cry = true;
                     break;
                  }
               }
            }
          //  std::cout << "Location: " << location << endl;
          //  std::cout << "infRule.size(): " << infRule.size() << endl;
            if (cry) continue;
            else if (location + 1 == infRule.size()) {
               //output result
            //   std::cout << "Location: " << location << endl;
               myAssignments.push_back((location+1) * -1);
               pastAssignments[(location+1)*-1] = i;
          //     std::cout << "Outputting positive... " << std::endl;
               for (int i = -1; -1 * i <= infRule.size(); i--) {
                  if (pastAssignments.count(i) > 0) {    
              //       std::cout << "Printing for " << i << std::endl;
                     file << pastAssignments[i] << " ";
                  }
               }
               file << "0\n";
               totalResult = true;
            }
            
            else {
               myAssignments.push_back((location+1) * -1);
               pastAssignments[(location+1)*-1] = i;
               totalResult |= recursivePrint(infRule, location + 1, idSets, pastAssignments, file);
            }
            
            //cleanup
            for ( int j = 0; j < myAssignments.size(); j++) {
               pastAssignments.erase(myAssignments.at(j));
            }
         }
      }//end foreach idset
      
      return totalResult;
   }
}

//TODO: separate this stuff out into submethods already.
//Also: allow for file names to be set.
int loadFullProgData(const string& fileName, const string& progFileName)

{
   boost::iostreams::mapped_file mmapFile;
   try {
      mmapFile.open(fileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   if (!mmapFile.is_open()) {
      throw runtime_error(string("Failed to open ") + fileName);
   } 
   std::cout << "File opened." << std::endl;
   
   bool cry = false;

   const char* front = mmapFile.const_data();
   const char* back = front + mmapFile.size();

   int maxNodeID = 0;
   int maxTupleNameID = 1;
   
   map<string, int> dictionary;
   map<string, int> tupleDictionary;
   vector<vector<int> > idSets;
   
   while (front != back)                     // for each line
   {
      if (front[0]=='/' && front[1]=='/') { //comment
         std::cout << "Found comment." << std::endl;
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }
      
      string tupleName;
      bool nameEnded = false;
      while (front[0] >= 32) { //i.e., is not a control character
         if (front[0]!='"') {
         //   std::cout << "Front is: " << front[0] << std::endl;
            if (front[0]==' ') {
               tupleName.clear();
            }
            if (front[0] == '(') {
               //end of tuple name, so insert.
               nameEnded = true;
               if (dictionary.count(tupleName)==0) {
                  dictionary[tupleName] = maxTupleNameID++;
               }
               vector<int> tempVector;
               tempVector.push_back(dictionary[tupleName]);
               idSets.push_back(tempVector);
   //            std::cout << "Pushing back tuple name: " << tupleName << std::endl;
            }
            if (!nameEnded) {
               tupleName.append(front, 1);
            }
            front++;
            continue;
         }
         else {
          //  std::cout << "quote found." << std::endl;
            front++;
            string str;
            while (front[0]!='"') {//need a slightly better way to capture...
               str.append(front, 1); //legal syntax?
               front++;
            }
         //   std::cout << "String found: " << str << std::endl;
            //grab int from dict, put in val
            if (dictionary.count(str)==0) {
               dictionary[str] = maxNodeID++;
            }
            
            idSets.back().push_back(dictionary[str]);
   //         std::cout << "Pushing back arg: " << str << std::endl;
         }
         front++;
      }//We've reached the end of a line, store vals
      
      //DO NOT SORT!!!
      
      front++;
   }//file fully scanned
   mmapFile.close();

   cout << "Evidence loaded." << endl;
   //time to load prog file============================================

   boost::iostreams::mapped_file mmapFile2;
   
   try {
      mmapFile2.open(progFileName.c_str(), boost::iostreams::mapped_file::readonly);
   } catch (exception &e) {
      throw runtime_error(e.what());
   }

   if (!mmapFile2.is_open()) {
      throw runtime_error(string("Failed to open ") + progFileName);
   } 
   
   front = mmapFile2.const_data();
   back = front + mmapFile2.size();
   
   vector<vector<vector<int> > > infSets;
   vector<vector<int> > currentSet;

   while (front != back)                     // for each line
   {
   //   std::cout << "Front[0] is " << front[0] << std::endl;
      if (front[0]=='/' && front[1]=='/') { //comment
       //  std::cout << "Found comment." << std::endl;
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue; 
      }
      //skip garbage opening bits
      else if (front[0]=='*') {
         front = static_cast<const char*>(memchr(front, '\n', back-front));
         front++;
         continue;
      }
      
      else if (front[0]=='.') {
         front++;
         continue;
      }
      
      else if (front[0] >= '0' && front[0] < '9') {
         do {
            front++;
         } while (front[0]!=' ');
         
         continue;
      }
   
      else if (front[0]=='=' && front[1]=='>') {
         //...Represent the arrow with an empty set?
         //Sure, why not.
         vector<int> tempSet;
         currentSet.push_back(tempSet);
         front++;
         front++;
         continue;
      }
      
      else if (front[0]=='[') {
         //TODO: Deal with math
         //for now, just fuck it and skip
         //future plan is to indicate with a leading 0.
         while (front[0]!=']') {
            front++;
         }
         front++;
      }
      else if (front[0]==',') {
         //if comma, just move forwards
         front++;
         continue;
      }
      
      else if (front[0] == ' ') {
         //blank space, skip
         front++;
         continue;
      }
      
      else if (front[0] < 32) { //newline detection. Finish line, move to next
         if (currentSet.size() > 1) {//don't want singleton inference rules
            infSets.push_back(currentSet);
         }
         currentSet.clear();
         front++;
         continue;
      }
      else { //deal with tuples
         int negation = 1;
         if (front[0]=='!') {
            negation = -1;
         }
         
         vector<int> tempVector;
         string tupleName;
         while (front[0]!='(') {
            tupleName.append(front, 1);
            front++;
         }
         front++;
         std::cout << "Tuple name: " << tupleName << endl;
         if (dictionary.count(tupleName)==0) {
            dictionary[tupleName] = maxTupleNameID++;
         }
         tempVector.push_back(dictionary[tupleName] * negation);
         
         //arguments of tuple
         string argString;
         while(true) {
           // std::cout << "Front[0]: " << front[0] << std::endl;
            if (front[0]==' ') {
               front++;
            }
            else if (front[0]==',' || front[0]==')') {
               if (dictionary.count(argString)==0) {
                  dictionary[argString] = maxNodeID++;
               }
               tempVector.push_back(dictionary[argString]);
               std::cout << "Argument: " << argString << endl;
               front++;
               argString.clear();
               if (front[-1]==')') break;
            }
            
            else { //grabbing word
               argString.append(front, 1);
               front++;
            }
         }
         
         currentSet.push_back(tempVector);
      } //end dealing with tuples
   }
   mmapFile2.close();
   cout << ".mln file complete." << endl;
   
   //debug: print out dictionary
   /*int count = 0;
   for (auto it = dictionary.begin(); it!= dictionary.end(); it++) {
      cout << it->first << ": " << it->second << endl;
      count++;
      if (count % 50 == 0) {
         string tmepInput;
         cin >> tmepInput;
      }
   }*/
   
   //Inference generation!
   int currentSize = 0;
   while (currentSize != idSets.size()) {
      currentSize = idSets.size();
      std::cout << "Current size: " << currentSize << endl;
      for (int i = 0; i < infSets.size(); i++) {
         std::cout << "i = " << i << endl;
         map<int, int> temp;
         recursiveAddition(infSets.at(i), 0, idSets, temp);
      }
   }
   
   std::cout << "Printing..." << std::endl;
   ofstream outputFile("graphOutput.txt"); //TODO: Set name of file w/ var
   for (int i = 0; i < infSets.size(); i++) {
      map<int, int> temp;
      std::cout << "i = " << i << endl;
      recursivePrint(infSets.at(i), 0, idSets, temp, outputFile);
   }
   outputFile.close();
      
   
   //cleanup
   ostringstream oss;
   if (cry) {
      oss << "Invalid format";
      throw runtime_error(oss.str());
   } 
      
   return maxNodeID;
}

// just a hook to call the algo
void callable(tricount_strategy_t f, size_t s, size_t e, unsigned long& result)
{
   /*
   struct timeval tv;
   gettimeofday(&tv, NULL);     // mark start time
   */
   result = f(*relationPtr, s, e);

   /*
   struct timeval tv2;          // mark finish time
   gettimeofday(&tv2, NULL);
   ostringstream oss;
   oss << left << setw(COL_WIDTH) << fixed
       << "seconds elapsed: " 
       << double(tv2.tv_sec - tv.tv_sec) + 
          double(tv2.tv_usec - tv.tv_usec)/1000000
       << " [" << s << ", " << e << "]" << endl;
   report(oss.str());          
   */
}

// uniformly partition the vertex set into numJobs subsets
vector<size_t> partitionSizes(int numJobs)
{
   vector<size_t> steps(numJobs+1);
   steps[0] = 0;
   steps[numJobs] = relationPtr->size();

   size_t step = relationPtr->size()/numJobs;
   for (int i=1; i<numJobs; i++) {
      steps.at(i) = step*i;
   }
   return steps;
}

void tricount(const vector<string>& tokens)
{
   ostringstream oss;

   //check for contradictory inputs
   if (!relSize) {
      oss << left << setw(COL_WIDTH) << fixed
         << "number of solutions: " 
         /*<< term_cc(MAGENTA)*/ << 0 << term_cc();
      report(oss.str());
      return;
   }

   if (tokens.size() != 2)
      throw runtime_error("Usage: tricount/tc strategy");

   // TODO: turn this map into a global variable later?
   map<string, tricount_strategy_t> strategies;
   strategies["minesweeper"] = &basicMSTricount;
   strategies["ms"]          = &basicMSTricount;
   strategies["frogger"]     = &froggerTricount;
   strategies["fr"]          = &froggerTricount;
   strategies["ams"]         = &advancedMSTricount;
   strategies["dms"]         = &dyadicMSTricount;
   strategies["pl"]          = &preloadedTricount;
   strategies["preloaded"]   = &preloadedTricount;
   strategies["max"]         = &maxSATCount;

   if (strategies.find(tokens[1]) == strategies.end())
      throw runtime_error("Unknown strategy");

   boost::asio::io_service io_service;

   unsigned numThreads, numJobs;
   if (multithreadMode) {
      numThreads = boost::thread::hardware_concurrency();
      numJobs    = 64*numThreads; // 64 is hard-coded, data dependent
   } else {
      numThreads = 1;
      numJobs = 1;
   }

   if (numThreads == 0) {
      numThreads = numJobs = 1;
   } else if (relationPtr->size() < numThreads) {
      numThreads = numJobs = relationPtr->size();
   } else if (relationPtr->size() < numJobs) {
      numJobs = relationPtr->size();
   }

   vector<unsigned long> counts(numJobs); // i'th job returns counts[i]
   tricount_strategy_t algo = strategies[tokens[1]];

   vector<size_t> steps = partitionSizes(numJobs);

   // create jobs first, there are many more jobs than threads
   for (size_t i = 0; i < numJobs; i++)
      io_service.post(boost::bind(callable, algo, steps[i], steps[i+1],
                                  boost::ref(counts[i])));

                                  
   boost::thread_group tg;
   for (size_t i=0; i<numThreads; i++) 
   {
      tg.create_thread(boost::bind(&boost::asio::io_service::run, &io_service));
   }

   tg.join_all();
   unsigned long count = 0;
   for (size_t i=0; i<numJobs; i++) {
      count += counts.at(i);
   }
   if (gvars.getStr(OUTFILE)=="") {
      oss << left << setw(COL_WIDTH) << fixed
         << "number of solutions: " 
         /*<< term_cc(MAGENTA)*/ << count << term_cc();
      report(oss.str());       
   }
   else {
      ofstream outFile;
      outFile.open(gvars.getStr(OUTFILE));
      outFile << count << "\n";
      outFile.close();
   }

   return;
}

void parseCommandLine(int argc, char** argv)
{
   bool goodArgs = true;
   switch (argc)
   {
   case 1:
      multithreadMode = false; // this is the default
      break;
   default:
      if (argv[1][0] == 'm')
         multithreadMode = true;
      else if (argv[1][0] == 's')
         multithreadMode = false;
      else {
         goodArgs = false;
         break;
      }
      
      for (int ptr = 2; ptr < argc; ptr++) {

         if (strcmp(argv[ptr], "-e") == 0) {
            iInputFile = argv[++ptr];
            iModes = argv[++ptr];

            /*TODO: not individually check each*/
            if (strcmp(iModes.c_str(), "12+") == 0) {
               gvars.insert(CDB_TYPE, "bigor");
               gvars.insert(DB_TYPE, "bigor");
               gvars.insert(SINGLETON, "0");
               gvars.insert(RATIO, .8);
               iModes = "12";
            }
            else if (strcmp(iModes.c_str(), "12+_") == 0) {
               gvars.insert(CDB_TYPE, "bigor");
               gvars.insert(DB_TYPE, "bigor");
               gvars.insert(SINGLETON, "1");
               gvars.insert(RATIO, .8);
               iModes = "12";
            }
            else if (strcmp(iModes.c_str(), "12_") == 0) {
               gvars.insert(SINGLETON, "1");
               iModes = "12";
            }
            else if (strcmp(iModes.c_str(), "12") == 0) {
               gvars.insert(SINGLETON, "0");
            }
            else if (strcmp(iModes.c_str(), "13+") == 0) {
               gvars.insert(CDB_TYPE, "bigor");
               gvars.insert(DB_TYPE, "bigor");
               gvars.insert(SINGLETON, "0");
               gvars.insert(RATIO, .8);
               iModes = "13";
            }
            else if (strcmp(iModes.c_str(), "13+_") == 0) {
               gvars.insert(CDB_TYPE, "bigor");
               gvars.insert(DB_TYPE, "bigor");
               gvars.insert(SINGLETON, "1");
               gvars.insert(RATIO, .8);
               iModes = "13";
            }
            else if (strcmp(iModes.c_str(), "13_") == 0) {
               gvars.insert(SINGLETON, "1");
               iModes = "13";
            }
            else if (strcmp(iModes.c_str(), "13") == 0) {
               gvars.insert(SINGLETON, "0");
            }
            
            ++ptr;
            if (ptr < argc && argv[ptr][0]!='-') {
               iOutputFile = argv[ptr++];
               if (ptr < argc && argv[ptr][0]!='-') {
                  iPredefs = argv[ptr++];
               }
            }
            ptr--;
         }
         else if (strcmp(argv[ptr], "-q") == 0) {
            vector<string> dummy;
            silence(dummy);
         }
         else if (strcmp(argv[ptr], "-o") == 0) {
            if (ptr + 1 > argc) {
               std::cout << "ERROR: please specify ordering when using -o" << std::endl;
               goodArgs = false;
            }
            else {
               std::cout << "Inserting " << argv[++ptr] << std::endl;
               gvars.insert(ORDERING, argv[ptr]);
            }
         }
         else if (strcmp(argv[ptr], "-ratio") == 0) {
            gvars.insert(RATIO, argv[++ptr]);
         }
         else if (strcmp(argv[ptr], "-p") == 0) {
            gvars.insert(PREPROCESS, argv[++ptr]);
         }
      }
   }
   
   if (!goodArgs)
      error_quit("Usage: subgraphcount [m/s] (m is for multithread, s single)");
}

void buildCNF(const vector<string>& tokens)
{
   relationPtr->performBuildCNFInput(0, 1);
}

map<string, cmd_handler_t> loadCommands()
{
   map<string, cmd_handler_t> commands;
   commands["load"]     = &load;
   commands["mthread"]  = &mthread;
   commands["sthread"]  = &sthread;
   commands["tricount"] = &tricount;
   commands["tc"]       = &tricount; // to save typing time
   commands["quit"]     = &bye;
   commands["exit"]     = &bye;
   commands["bye"]      = &bye;
   commands["#"]        = &comment;  // to skip lines in scripts
   commands["loadcnf"]  = &loadCNF;
   commands["bcnf"]     = &buildCNF;
   commands["buildcnf"] = &buildCNF;
   commands["set"]      = &setval;
   commands["setval"]   = &setval;
   commands["print"]    = &print;
   commands["list"]     = &print;
   commands["loadprog"] = &loadProg;
   commands["fullprog"] = &fullProg;
   commands["loadmax"]  = &loadMax;
   commands["loadwcnf"] = &loadMax;
   
   commands["silence"]  = &silence;
   commands["unsilence"]= &unsilence;
   commands["quiet"]    = &silence;
   commands["unquiet"]  = &unsilence;
   commands["loud"]     = &unsilence;
   
   return commands;
}
