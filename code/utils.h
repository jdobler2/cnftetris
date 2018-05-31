//utils.h
//created 7/28/2014 by jdobler

#ifndef UTILS_H_
#define UTILS_H_

#include <vector>
#include <stdlib.h>
#include <boost/range/algorithm.hpp>
#include <boost/thread.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/bind.hpp>
#include <ctime>
#include <algorithm>

template <class RandomAccessIterator>
void parallelSort(
      RandomAccessIterator start, 
      RandomAccessIterator end,
      size_t jobs_available);
      
//implements quicksort in parallel
//O(nlog(n/p))
template <class RandomAccessIterator>
void parallelSort(
      RandomAccessIterator start, 
      RandomAccessIterator end,
      size_t jobs_available) {  
   
   //if we've exhausted the number of threads available, continue using stl.
   if (jobs_available <=1) { 
      std::sort(start, end);
   } else if (end - start > 1) {
      
      size_t range = end - start;
  //    std::cout << "range: " << range << std::endl;
      
      //randomly determine pivot point
      std::srand(std::time(0));
      size_t pivotPoint = std::rand() % (range);
      
      RandomAccessIterator mid_it = start + pivotPoint;
    
      auto value = *mid_it;
      
      RandomAccessIterator leftPointer = start;
      RandomAccessIterator rightPointer = end-1;
      

      while (true) {
         while (*leftPointer < value) {
            leftPointer++;
         }
         while (*rightPointer >= value && rightPointer!=start) {
            rightPointer--;
         }
         if (rightPointer <= leftPointer) break;
         std::swap(*leftPointer, *rightPointer); 
      }
      //assert: leftPointer is at the first element
      // that is greater than the midpoint's element 
      //(unless we got unlucky, in which case leftPointer==end)
      
      //now, do recursion
      void (*pSort) (RandomAccessIterator, RandomAccessIterator, size_t) 
            = &parallelSort;
      
      boost::thread t1(pSort, start, leftPointer, jobs_available/2);
      boost::thread t2(pSort, leftPointer, end, jobs_available/2);
      t1.join();
      t2.join();
      
   }   
}

//and let's do this again with comparitor objects!
template <class RandomAccessIterator, class Comparitor>
void parallelSort(
      RandomAccessIterator start, 
      RandomAccessIterator end,
      size_t jobs_available,
      Comparitor comp);
      
template <class RandomAccessIterator, class Comparitor>
void parallelSort(
      RandomAccessIterator start, 
      RandomAccessIterator end,
      size_t jobs_available,
      Comparitor comp) {  

   //if we've exhausted the number of threads available, continue using stl.
   if (jobs_available <=1) { 
      std::sort(start, end, comp);
   } else if (end - start > 1) {
      
      size_t range = end - start;
  //    std::cout << "range: " << range << std::endl;
      
      //randomly determine pivot point
      std::srand(std::time(0));
      size_t pivotPoint = std::rand() % (range - 1);
      
      RandomAccessIterator mid_it = start + pivotPoint;
    
      auto value = *mid_it;
      
      RandomAccessIterator leftPointer = start;
      RandomAccessIterator rightPointer = end-1;
      
      while (true) {
         while (comp(*leftPointer, value)) {
            leftPointer++;
         }
         while (!comp(*rightPointer, value) && rightPointer!=start) {
            rightPointer--;
         }
         if (rightPointer <= leftPointer) break;
         std::swap(*leftPointer, *rightPointer); 
      }
      //assert: leftPointer is at the first element
      // that is greater than or equal to the midpoint's element 
      //(unless we got unlucky, in which case leftPointer==end)
      
      //now, do recursion
      void (*pSort) 
            (RandomAccessIterator, RandomAccessIterator, size_t, Comparitor) 
            = &parallelSort;
      
      boost::thread t1(pSort, start, leftPointer, jobs_available/2, comp);
      boost::thread t2(pSort, leftPointer, end, jobs_available/2, comp);
      t1.join();
      t2.join();
      
   }   
}

using std::vector;

template <typename T>
void qsort(vector<T>& data, size_t leftBound, size_t rightBound) {

   //shortcut on small:
   if (rightBound - leftBound < 2048) {
      sort(data.begin()+leftBound, data.begin()+rightBound);
   }

   //randomly determine pivot point
   std::srand(std::time(0));
   size_t pivotPoint = std::rand() % (rightBound - leftBound);

    
   T value = data[leftBound + pivotPoint];
   
   size_t lbound = leftBound;
   size_t rbound = rightBound - 1;

   while (true) {
      while (data[lbound] < value) {
         lbound++;
      }
      while (data[rbound] >= value && rbound!=leftBound) {
         rbound--;
      }
      if (rbound <= lbound) break;
      std::swap(data[lbound], data[rbound]); 
      //lbound++;
      //rbound--;
   }
      
   //do recursion:
 //  if (lbound - leftBound > 1)
      qsort(data, leftBound, lbound);
 //  if (rightBound - lbound > 1) 
      qsort(data, lbound, rightBound);
   
}
   
   
template <typename T>
void buckPart(
              vector<T>& data,
              size_t lowerBound,
              size_t upperBound,
              vector<vector<T> >& outVecs,
              vector<T>& pivots) {
   
   for (size_t i = lowerBound; i < upperBound; i++) {
      T val = data[i];
      int leftBnd = -1;
      int rightBnd = pivots.size();
      while (leftBnd < rightBnd - 1) {
         int midpt = (rightBnd + leftBnd) / 2;
         if (val < pivots[midpt]) {
            rightBnd = midpt;
         } else {
            leftBnd = midpt;
         }
      }
      outVecs[leftBnd+1].push_back(val);
   }
}

template <typename T>
void innerBuckSort(
                   vector<T>& data,
                   vector<vector<T> >& outVecs,
                   size_t leftStep,
                   size_t rightStep) {

   //copy our outVecs into data
   size_t locInData = leftStep;
   for (int i = 0; i < outVecs.size(); i++) {
      for (int j = 0; j < outVecs[i].size(); j++) {
         data[locInData] = outVecs[i][j];
         locInData++;
      }
   }
   
   //and sort our data
   std::sort(data.begin()+leftStep, data.begin()+rightStep);
   //qsort(data, leftStep, rightStep);

}     

using std::cout;
using std::endl;
template <typename T>
void bucketSort(
                vector<T>& data,
                size_t range,
                int jobs_available) {
   
   //pick the |jobs_available| buckets
   std::srand(std::time(0));
   vector<int> pivotPoints(jobs_available-1);
   vector<T> pivots(pivotPoints.size());
   for (int i = 0; i < pivots.size(); i++) {
      pivotPoints[i] = std::rand() % (range);
      pivots[i] = data[pivotPoints[i]];
   }

   std::sort(pivots.begin(), pivots.end());
   //TODO: check for no duplicate pivot points?
   //They're unlikely, and the code doesn't crash... probably not worthwhile
   
   //subdivide the input array for the various processes
   int subLength = range / jobs_available;
   vector<int> steps(jobs_available+1);
   steps[0] = 0;
   for (int i = 1; i < steps.size()-1; i++) {
      steps[i] = steps[i-1] + subLength;
   }
   steps[steps.size()-1] = range;

   //create output vector
   vector<vector<vector<T> > > outVecs(jobs_available);
   
   for (int i = 0; i < outVecs.size(); i++) {
      outVecs[i].resize(jobs_available);
   }

   //spawn partitioning threads
   void (*fPtr) (vector<T>&, size_t, size_t, vector<vector<T> >&, vector<T>&) 
         = &buckPart;

   boost::thread_group tg;
   for (int i = 0; i < jobs_available; i++) {
      tg.create_thread(boost::bind(fPtr, boost::ref(data), steps[i], steps[i+1], boost::ref(outVecs[i]), boost::ref(pivots)));
   }
   tg.join_all();

   
   // rearrange output vector so that outVec[i] = the set of all partitions 
   // that are in a range r s.t. pivotPoints[i-1] < r < pivotPoints[i]
   // where pivotPoints[-1] = -inf and pivotPoints [jobs_...] = inf
   // ALSO: this is gonna be the fun-to-debug part!
   for (int i = 0; i < outVecs.size(); i++) {
      for (int j = i; j < outVecs[i].size(); j++) {
         outVecs[i][j].swap(outVecs[j][i]); 
      }
   } //... I think that's it? But it feels too simple...

   //repurpose steps as a quick prefix sum of sizes
   for (int i = 1; i < jobs_available; i++) {
      steps[i] = steps[i-1];
      for (int j = 0; j < jobs_available; j++) {
         steps[i] += outVecs[i-1][j].size();
      }
   }

   
   //and spawn sorting threads
   void (*innBuckSort) (vector<T>&, vector<vector<T> >&, size_t, size_t) = &innerBuckSort;
   
   boost::thread_group tg2;
   for (int i = 0; i < jobs_available; i++) {
      tg2.create_thread(boost::bind(innBuckSort, boost::ref(data), boost::ref(outVecs[i]), steps[i], steps[i+1]));
   }

   
   tg2.join_all();
   //and done.
   
}
#endif //UTILS_H_