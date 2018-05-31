//TrieActor.h
#ifndef TRIE_ACTORS_H_
#define TRIE_ACTORS_H_

#include "GenericTrie.h"
#include "trie.h"
#include "IntervalTrie.h"
#include "FertileIntervalTrie.h"
#include "IntIntervalTrie.h"
#include "GenericIntTrie.h"
#include "IntArrayTrie.h"
#include "IntFITrie.h"

#include <fstream>
#include <iostream>

struct printActor: public trie_actor {
   void if_word(trieNode* tn, vector<string> currentWord); 
   void if_interval(IntervalTrie* intTrie); 
   void if_interval(IntIntervalTrie* intTrie);
   void if_array(ArrayTrie* arrTrie, int index);
   void if_array(IntArrayTrie* arrTrie, int index);
};

struct printToFileActor: public trie_actor {
   std::ofstream file;
   string lhs;
   int maxDepth;
   int cliqueSize;
   
   //c: cycle
   //k: clique
   char mode;
   
   //0: off
   //1: on
   int printHelp;
   
   printToFileActor(string filename, int numBits, int cSize);
   ~printToFileActor();
   void if_interval(IntervalTrie* intTrie); 
   void if_array(ArrayTrie* arrTrie, int index);
   void if_array_word(ArrayTrie* arrTrie, int index);
};

struct countActor: public trie_actor {
   int totalCount;
   void if_interval(IntervalTrie* intTrie);
   void if_interval(IntIntervalTrie* intTrie);
};

struct removeActor: public trie_actor {
   vector<string> word;
   int level;
   int depth;
   int mode;
   int maxNodeID;
   
   removeActor(vector<string> newWord, int mnID);
   ~removeActor() {};
   
   void always_do(trieNode* tn, vector<string> currentWord);
   void after_children(trieNode* tn, vector<string> currentWord);
   
   bool br_left_if(trieNode* tn, vector<string> currentWord);
   bool br_right_if(trieNode* tn, vector<string> currentWord);
   bool br_down_if(trieNode* tn, vector<string> currentWord);
   
   void if_interval(IntervalTrie* intTrie);
};
/*
//get all containing boxes actor
struct getAllContActor : public trie_actor {
   vector<vector<string> > words;
   vector<string> currentWord;
   vector<string> input;
   
   void if_array(ArrayTrie* arrTrie);
   void if_fertileInterval(FertileIntervalTrie* fIntTrie);
};*/
#endif
