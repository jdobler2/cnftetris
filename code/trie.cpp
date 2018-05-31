//trie.cpp

#include "trie.h"
#include <iostream>
#include "IntervalTrie.h"
#include "TrieActors.h"

trieNode::~trieNode() {
   delete leftChild;
   delete rightChild;
   delete branchChild;
}

void trieNode::apply(trie_actor* actor, vector<string> currentWord) {
   int level = currentWord.size()-1;
   
   actor->always_do(this, currentWord);
   
   if (this->value!='x' && this->value!='/') {
      currentWord[level] += string(1, this->value);
	   actor->if_not_root(this, currentWord);
   }
   else {
      actor->if_root(this, currentWord);
   }
   
   if (this->isWord()) {
      actor->if_word(this, currentWord);
   }
   
   if (this->leftChild!=NULL && actor->br_left_if(this, currentWord)) {
      this->leftChild->apply(actor, currentWord);
   }
   if (this->rightChild!=NULL && actor->br_right_if(this, currentWord)) {
      this->rightChild->apply(actor, currentWord);
   }
   if (this->branchChild!=NULL && actor->br_down_if(this, currentWord)) {
     // currentWord.push_back("");
         std::cout << "at ";
         for (int i=0; i < currentWord.size(); i++) {
           std::cout << currentWord[i];
          if (currentWord[i].length()==0) {
             std::cout << "*";
           }
          if (i < currentWord.size()-1) {
             std::cout << "/";
           }
         }
        std::cout << std::endl;
      this->branchChild->apply(actor);
   }
   
   actor->after_children(this, currentWord);
}

trie::trie() {
   firstNode = new trieNode();
   firstNode->value = 'x';
}

trie::~trie() {
   delete firstNode;
}

//TODO: keep tally? Not sure if easily doable...
int trie::size() {
   return -1;
}

trieValuePair trie::find(vector<string> box) {
   trieNode* currentLocation = firstNode;
  
   trieValuePair toBeReturned;
   vector<string> currentBox;
 /*  currentBox.push_back("");
   toBeReturned.node = currentLocation;
   toBeReturned.box = currentBox;
   return toBeReturned;*/
   int level = 0;
 
   for (int depth = 0; depth < box[level].length(); depth++) {
      if (box[level][depth] =='0') {
         if (currentLocation->leftChild!=NULL) {
            currentLocation = currentLocation -> leftChild;
         } else {
            currentBox.push_back(box[level].substr(0,depth));
            toBeReturned.box = currentBox;
            toBeReturned.node = currentLocation;
            return toBeReturned;
         }
      } else if (box[level][depth] == '1') {
         if (currentLocation->rightChild!=NULL) {
            currentLocation = currentLocation -> rightChild;
         } else {
            currentBox.push_back(box[level].substr(0,depth));
            toBeReturned.box = currentBox;
            toBeReturned.node = currentLocation;
            return toBeReturned;
         }
      } else {
         std::cerr << "ERROR: box formatted incorrectly!" << std::endl;
         toBeReturned.node = NULL;
         return toBeReturned;
      }   
   }
   
   //the box we're searching for has been found in full (on the top layer.)
   currentBox.push_back(box[level]);
   toBeReturned.box = currentBox;
   toBeReturned.node = currentLocation;
   return toBeReturned;
}

//DOES NOT WORK IN MODERN PARADIGM
bool trie::contains(const vector<string>& box) {
   trieValuePair pair = this->find(box);
   if (pair.box!=box) {
      return false;
   } 
   if (pair.node->isWord() == false || pair.node->value=='x') {
      return false;
   }
   return true;
}

//inserts value.
//returns false on failure due to value already being in the trie
bool trie::insert(const vector<string>& box) {
 //  std::cout << "in trie's insertion..." << std::endl;
   trieValuePair pair = this->find(box);
//   std::cout << "Pair found. " << std::endl;
   
   
 /*  std::cout << "printing pair.box... ";
   for (int i = 0; i < pair.box.size(); i++) {
      std::cout << pair.box[i] << ";"; 
   } std::cout << ". done" << std::endl;
   
   std::cout << "printing box... ";
   for (int i = 0; i < box.size(); i++) {
      std::cout << box[i] << ";"; 
   } std::cout << ". done" << std::endl;
   */
   //check if box already contained
   if (pair.box==box) { 
 //     std::cout << "This shouldn't have happened." << std::endl;
      if (pair.node->isWord() == true) {
	     return false;
	  } else {
	     //node exists, but isn't a word		 
		 //check to see if it subsumes any boxes
		 if (pair.node->leftChild!=NULL) {
		    delete pair.node->leftChild;
			pair.node->leftChild = NULL;
	     } 
		 if (pair.node->rightChild!=NULL) {
		    delete pair.node->rightChild;
			pair.node->rightChild = NULL;
	     }
		 if (pair.node->branchChild!=NULL) {
		    delete pair.node->branchChild;
			pair.node->branchChild = NULL;
	     }
		 return true;
	  }
   }
   
   //check that correctness is maintained
   if (pair.node->isWord()==true) {
      //we don't want to kill a bigger box to add a smaller one!
      return false;
   }
      
   //figure out how deep we got.
   int level = pair.box.size()-1;
   if (level!=0) {
      std::cout << "ERROR: why is level not 0?" << std::endl;
   }
   int depth = pair.box[level].length(); 
   trieNode* currentLocation = pair.node;
   
   
 //  std::cout << "Currently at " << level << "//" << depth << std::endl;
 //  std::cout <<  "maxlevel: " << box.size() << "; Maxdepth: " << box[level].size() <<std::endl; 
   
   //build new nodes as necessary
   for (; depth < box[level].size(); depth++) {
      if (box[level][depth] == '0') {
         currentLocation -> leftChild = new trieNode();
         currentLocation -> leftChild -> value = '0';
         currentLocation -> leftChild->parent = currentLocation;
         currentLocation = currentLocation -> leftChild;
      } else if (box[level][depth] == '1') {
         currentLocation -> rightChild = new trieNode();
         currentLocation -> rightChild -> value = '1';
         currentLocation -> rightChild->parent = currentLocation;
         currentLocation = currentLocation -> rightChild;
      }
   }
   
   //check for level switch
   if (level==box.size() - 2) {
      //TODO: actually have the maxDepth value known
      if (currentLocation->branchChild==NULL) {
         currentLocation -> branchChild = new IntervalTrie(maxNodeID);
      }     
      vector<string> bottomBox;
      bottomBox.push_back(box.at(box.size()-1));
  //          std::cout << "Sending to interval (2)..." << std::endl;
      bool val = currentLocation -> branchChild -> insert(bottomBox);
 //     std::cout << "Back from interval." << std::endl;
      return val;
   }
   
   else if (level < box.size() - 2) {
      std::cout << "ERROR: not implemented yet" << std::endl;
   }
   
 //  std::cout << "We're at the end...?" << std::endl;
   //successfully made word node!
   return true;
}

//removes a node
//if the node did not exist, returns false
bool trie::remove(const vector<string>& box) {
 //  std::cout << "Entering remove." << std::endl;
   trieValuePair pair = this->find(box);
   
   trieNode* currentLocation = pair.node;
   //if removing sub-box of a word:
   //NOTE: This is bugged in the case of one way right, one way wrong!
   if (pair.box!=box) {
  //    std::cout << "Removing subboxes." << std::endl;
      int level = pair.box.size()-1; //is V 0
      int depth = pair.box[level].length();
      for (; depth < box[level].size(); depth++) {
         if (currentLocation->leftChild==NULL) {
            currentLocation->leftChild = new trieNode();
            currentLocation->leftChild->value = '0';
            currentLocation->leftChild->parent = currentLocation;
         }
         
         if (currentLocation->rightChild==NULL) {
            currentLocation->rightChild = new trieNode();
            currentLocation->rightChild->value = '1';
            currentLocation->rightChild->parent = currentLocation;
         }
         if (box[level][depth]==0) {
            currentLocation = currentLocation->leftChild;
         } else {
            currentLocation = currentLocation->rightChild;
         }
      }
      if (currentLocation->branchChild==NULL) {
         currentLocation->branchChild = new IntervalTrie(maxNodeID);
         vector<string> tempBox;
         tempBox.push_back("");
         currentLocation->branchChild->insert(tempBox);
      }
      //finished removing and inserting alt. boxes
   }//end removing sub-box
//   std::cout << "Done removing subboxes" << std::endl;
   if (currentLocation->isWord()==false && currentLocation->branchChild==NULL){
      std::cout << "ERROR: found box " << pair.box[0] 
	            << ", but is not a word" << std::endl;
      return false;
   } else if (currentLocation->branchChild!=NULL) {
      //remove from IntervalTrie
  //    std::cout << "In last routine" << std::endl;
      currentLocation->branchChild->remove(box);
      if (currentLocation->branchChild->size()==0) {
         //fall through to below and delete up
      } else {
   //      std::cout << "Leaving last routine." << std::endl;
         return true;
      }
   }
   
   //assert: we have found the node and it is a word,
   //        or else branchNode now has no words in it
   while (currentLocation->leftChild   == NULL && 
          currentLocation->rightChild  == NULL &&
		    currentLocation->branchChild == NULL)
   { 
      std::cout << "deleting up" << std::endl;
      trieNode * newLocation = currentLocation->parent;
	  if (currentLocation->value=='0') {
	     delete currentLocation;
		 currentLocation = newLocation;
		 currentLocation -> leftChild = NULL;
	  } else if (currentLocation->value=='1') {
	     delete currentLocation;
		 currentLocation = newLocation;
		 currentLocation -> rightChild = NULL;
	  } else if (currentLocation->value=='/') {
	     delete currentLocation;
		 currentLocation = newLocation;
		 currentLocation -> branchChild = NULL;
	  } else {
	     std::cerr << "ERROR: child and parent don't know each other?"
        << std::endl;
		 return false;
	  }
   }
   
   //box has been removed, and cleanup finished successfully.
   //removeActor* ra = new removeActor(box, maxNodeID);
   //this->apply(ra);
  // delete ra;
   return true;
}

void trie::apply(trie_actor* actor) {
   vector<string> currentWord;
   currentWord.push_back("");
   firstNode -> apply(actor, currentWord);
}

//=======begin getBoxesActor===================================================
void trie::getBoxesActor::setBox(vector<string>& newBox) {
   this->box = newBox;
}
   
void trie::getBoxesActor::if_word(trieNode* tn, vector<string> currentWord) {
   container.push_back(currentWord);
}

bool trie::getBoxesActor::br_left_if(trieNode* tn, vector<string> currentWord)
{
   bool toBeReturned = true;
   for (int i = 0; i < currentWord.size(); i++) {
     if (i == currentWord.size()-1) {
        if (box[i].substr(0,currentWord[i].size()+1)
             != (currentWord[i] + string("0"))) {
          toBeReturned = false;
         break;
      }
     } else {
       if (box[i].substr(0,currentWord[i].size()) != currentWord[i]) {
         toBeReturned = false;
         break;
      }
    }
  }
  return toBeReturned;
}
   
bool trie::getBoxesActor::br_right_if(trieNode* tn, vector<string> currentWord)
{
   bool toBeReturned = true;
   for (int i = 0; i < currentWord.size(); i++) {
     if (i == currentWord.size()-1) {
        if (box[i].substr(0,currentWord[i].size()+1)
             != (currentWord[i] + string("1"))) {
          toBeReturned = false;
         break;
      }
     } else {
       if (box[i].substr(0,currentWord[i].size()) != currentWord[i]) {
         toBeReturned = false;
         break;
      }
    }
  }
  return toBeReturned;
}
//=======end getBoxesActor=====================================================

//TODO: WARNING: BROKEN---
vector<vector<string> > trie::getAllContainingBoxes(const vector<string>& box){
   getBoxesActor* ta = new trie::getBoxesActor();
  // ta->setBox(box);
   this->apply(ta);
  
   vector<vector<string> > container = ta -> container;
   delete ta;
   return container;
}

/*
//driver for testing
int main() {
	trie* tr = new trie();
	vector<string> data;
	data.push_back("100");
	tr->insert(data);
	
	data.pop_back();
	data.push_back("101");
	tr->insert(data);
	
	data.pop_back();
	data.push_back("111");
	tr->insert(data);
	
	data.pop_back();
	data.push_back("001");
	tr->insert(data);
	
	data.push_back("001");
	tr->insert(data);
	
	data.clear(); 
	data.push_back("110");
	tr->insert(data);
	
	data.pop_back();
	data.push_back("1");
	data.push_back("100");
	tr->insert(data);
	
		trie_actor* ta = new printActor();
	tr->apply(ta);
	
	trie_actor* sm = new simpleMergerActor();
	tr->apply(sm);
	tr->apply(ta);
	
	data.pop_back();
	data.pop_back();
	data.push_back("100");
	data.push_back("100");
	std::cout << "Getting all boxes..." << std::endl;
	vector<vector<string> > container = tr->getAllContainingBoxes(data);
	for (int i = 0 ; i < container.size(); i++) {
	   for (int j = 0; j < container[i].size(); j++) {
	      std::cout << container[i][j];
		   if (j < container[i].size()-1) {
		     std::cout << "/";
		   }
	   }
	   std::cout << std::endl;
	}
	std::cout << "Got all boxes." << std::endl;
	
		data.pop_back();

	data.pop_back();
	data.push_back("1");
	tr->insert(data);
		std::cout << std::endl;

	tr->apply(ta);
	
	tr->remove(data);
	
	std::cout << "After removing 1: " << std::endl;
	tr->apply(ta);
	
	data.push_back("1");
	tr->insert(data);
	data[0]="0";
   data[1] = "10";
	tr->insert(data);
	data.clear();
   data.push_back("001");
   tr->remove(data);
   
	std::cout<< "After inserting stuff" << std::endl;
	tr->apply(ta);
	
	
   
	mlMergerActor* mlma = new mlMergerActor(tr);
	
	   tr->apply(mlma);

	
	std::cout << std::endl;
	tr->apply(ta);
}*/
