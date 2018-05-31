//test.cpp
#include <iostream>
#include <string>

bool removeTest(size_t left, size_t right, int it_lower, int it_upper) {
   
   int correctLeft = left;
   int correctRight = right;
   //(check for legality is unnecessary
   
   
   //handling left side
   if (it_lower==left) { //check for guaranteed safety on left
      //left is good
   } 
   else { //it_lower passed left and is on the next right-hand bound
      //it_lower--; //adjust to correct LHB
      int val = it_lower;
      while (val < left) {
         int distance = 4;
         while (val % distance == 0 && val + distance <= it_upper + 1) {
            distance*=2;
         }
         distance/=2;
         
         if (val + distance > correctLeft) 
         {
            correctLeft = val + distance;
         }
         
         val+=distance;
      }
   }
   
   //handling right side
   if (it_upper==right) { //check for guaranteed safety on right
      //right is good
   } 
   else { //it_upper is past right, on the RHB.
      int val = it_upper;
      val++;
      while (val > right + 1) {
         int distance = 4;
         while (val % distance == 0 && val-distance >= it_lower) {
            distance*=2;
         }
         distance/=2;
         
         if (val - distance - 1 < correctRight) 
         {
            correctRight = val - distance - 1;
         }
         val-=distance;
      }
   }
   
      std::cout << "Lower: " << it_lower << ", upper: " << it_upper << std::endl;
   std::cout << "Left: " << left << ", Right: " << right << std::endl;
   std::cout << "CorrectLeft: " << correctLeft << ", CorrectRight: " << correctRight << std::endl << std::endl;
   
}

int main() {
   for (int i = 0; i < 16; i+=2) {
      for (int j = i+1; j < 16; j+=2) {
         for (int k = i; k < j; k+=2) {
            for (int l = k+1; l <= j; l+=2) {
               removeTest(k, l, i, j);
               std::string temp;
               std::cin >> temp;
            }
         }
      }
   }
}

