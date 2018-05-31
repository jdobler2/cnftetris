//FixedIITrie.cpp

#include "FixedIITrie.h"
#include <iostream>
#include <cmath>

FixedIITrie::FixedIITrie(int mD) {
   maxNodeID = mD;
   //waste space, saves time...
   maxDepth = std::ceil(std::log(maxNodeID+1)/std::log(2));
   finalLevelStart = (1 << maxDepth);
}

FixedIITrie::~FixedIITrie() {
}

void FixedIITrie::buildData(
      int& upperBound, 
      pair<size_t, size_t>& data) const 
{
   size_t difference = 1;
   
   while (data.first < finalLevelStart) {
      data.first *=2;
      difference *= 2;
   }
   
   upperBound = data.first + difference - 1;
   
   //NOTE: no need to double or count from 0 anymore!
}

bool FixedIITrie::contains(const vector<int>& box, vector<int>& output){
         
   map<size_t, pair<size_t, size_t> >::iterator it = 
         intervals.lower_bound(box.at(myLayer));
   
   if (it!=intervals.end()) {
      if (it->second.first <= box.at(myLayer)) {
         output.at(myLayer) = it->second.second;
         return true;
      }
   }

   return false;
}

int FixedIITrie::insert(const vector<int>& box) {

   //kinda ugly...
   int upperBound = box.at(myLayer);
   pair<size_t, size_t> val(upperBound, upperBound);
   buildData(upperBound, val);

   intervals[upperBound] = val;
    
   //return this->isFull();
    
   return false;
}

//duplicate of above (yuck)
bool FixedIITrie::insertPair(
   const pair<dataLayerPair, dataLayerPair>& box) 
{
   int upperBound = box.second.data;
   pair<size_t, size_t> val(upperBound, upperBound);
   buildData(upperBound, val);

   intervals[upperBound] = val;
   
   return false;
}

bool FixedIITrie::remove(const vector<int>& box) {
   std::cout << "ERR: FixedIITrie::remove not implemented!" << std::endl;
   return false;
}

//identical
//TODO: this
void FixedIITrie::apply(trie_actor* actor) {
   std::cout << "ERR: FixedIITRie::apply not implemented!" << std::endl;
 //  actor->if_interval(this);
}

//identical
int FixedIITrie::size() {
   //TODO: make more thorough?
   return intervals.size();
}

map<size_t, pair<size_t, size_t> > FixedIITrie::getIntervals() {
   return intervals;
}

void FixedIITrie::setIntervals(
         map<size_t, pair<size_t, size_t> >& newIntervals) 
{
   intervals = newIntervals;
}

void FixedIITrie::getAllContainingBoxes(
   const vector<int>& input,
   vector<pair<dataLayerPair, dataLayerPair> >& output,
   vector<int>& prevWord) const
{
   std::cout << "ERR: FixedIITrie::GACB not implemented!" << std::endl;
}
