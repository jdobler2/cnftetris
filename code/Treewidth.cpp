//Treewidth.cpp

#include "Treewidth.h"
using std::string;
using std::vector;

#include "TreedLib/treed.h"

Treewidth::~Treewidth() {
   //nothing to clean up
}

string Treewidth::getType() const {
   return string("treewidth");
}

vector<int> Treewidth::getOrdering(
      std::vector<std::vector<int> >& input,
      int maxNodeID,
      vector<std::pair<int, int> >& counts) 
{
   vector<int> mappings(counts.size());
   
   //note: horrible waste of space...
   //but we need this to do the treewidth stuff
   vector<vector<int> > absValInput;
   for (int i = 0; i < input.size(); i++) {
      absValInput.push_back(input.at(i));
   }
   for (int i = 0; i < absValInput.size(); i++) {
      for (int j = 0; j < absValInput.at(i).size(); j++) {
         if (absValInput.at(i).at(j) < 0) {
            absValInput.at(i).at(j) *= -1;
         }
      }
   }
   
   CConstraintHypergraph cchg;
   cchg.SetHypergraph(maxNodeID+1, absValInput.size(), absValInput);
   //using method 0 for now
   CTreeDecomposition ctd(&cchg);
   CMCSTreeDecomposer mcstd(&cchg,&ctd);
   mcstd.Decompose();
   cout<<"MCS Width "<<mcstd.GetMCSWidth()<<endl;
   cout<<"MCS Tree Width "<<ctd.GetTreeWidth()<<endl;
   vector<int> order = ctd.GetElimOrder();
   
   //still have to invert the mapping (I think?)
   //let's try not.
   //nope, that backfired.
   for (int i = 1; i < counts.size(); i++) {
      //thinking about this, counts.size-i should be the RHS here
      //but that causes the answer to be wrong???!!!
      //TODO: Figure out why
      mappings.at(order.at(i)) = counts.size() - i;
   }
   //std::reverse(mappings.begin()+1, mappings.end());
   
   return mappings;
}