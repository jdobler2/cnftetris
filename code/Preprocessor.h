//Preprocessor.h

#ifndef PREPROCESSOR_H_
#define PREPROCESSOR_H_

#include <vector>
//#include <pair>

using std::vector;
using std::pair;

class Preprocessor {
  private:
   
   
  public:
   Preprocessor();
   ~Preprocessor();
   
   //@input: input edges. Returns the new set of input edges
   //@counts: Counts, as calculated per global variable. Input only.
   //@removedVars: Returns the set of variables with fixed values, along with said value
   void preprocess(
      vector<vector<int> >& input,
      vector<pair<int, int> >& counts,
      vector<int>& removedVars,
      int& maxNodeID);
};

#endif //PREPROCESSOR_H_