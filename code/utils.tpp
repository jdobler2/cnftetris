//utils.tpp

/*template <class RandomAccessIterator, class Sample>
void innerQSort(
      RandomAccessIterator start,
      RandomAccessIterator end,
      Sample value,
      size_t initLoc,
      map<size_t, size_t>& stuffToTheLeft) {
      
   for (size_t i = initLoc; start!=end; i++, start++) {
      if ((*start) < value) {
         stuffToTheLeft.insert(std::pair<size_t, size_t>(i,1));
      }
   }
   
}

template <class RandomAccessIterator>
void doMerge(
      RandomAccessIterator leftPointer,
      RandomAccessIterator rightPointer,
      RandomAccessIterator destPointer) {
   std::copy(leftPointer, rightPointer, destPointer);
}*/

template <class RandomAccessIterator, class Sample>
void parallelSort(
      RandomAccessIterator start, 
      RandomAccessIterator end,
      size_t jobs_available,
      Sample value,
      RandomAccessIterator storageArrayIt) {  
   
   //if we've exhausted the number of threads available, continue using stl.
   if (jobs_available <=1) { 
      std::sort(start, end);
   } else if (end - start > 1) {
      
      size_t range = end - start;
  //    std::cout << "range: " << range << std::endl;
      
      //randomly determine pivot point
      std::srand(std::time(0));
      size_t pivotPoint = std::rand() % (range - 1);
      
      RandomAccessIterator mid_it = start + pivotPoint;
    
      value = *mid_it;
      
      //results vector that'll be used to get prefix sum
      std::vector<size_t> numToTheLeft(jobs_available);
      
      //setup step lengths
      size_t subdivLength = range / jobs_available;
      std::vector<size_t> steps(jobs_available+1);
      steps[0] = 0;
      steps[jobs_available] = range;
      for (int i=1; i < jobs_available; i++) {
         steps[i] = steps[i-1] + subdivLength;
      }
      
      //create threads
      void (*inSort) (RandomAccessIterator, RandomAccessIterator, Sample, size_t&) = &innerQSort;
      boost::thread_group tg;
      
      for (int i = 0; i < jobs_available; i++) {
         RandomAccessIterator leftPointer = start + steps[i];
         RandomAccessIterator rightPointer = start + steps[i+1];
         tg.create_thread(boost::bind(inSort, leftPointer, rightPointer, value, numToTheLeft[i]));
      }
      tg.join_all();
      
      //todo: fold into above or below?
      for (int i=1; i < numToTheLeft.size(); i++) {
         numToTheLeft[i] += numToTheLeft[i-1];
      }
      
      //copy in.      
      boost::thread_group tg2;
      void (*merge) (RandomAccessIterator, RandomAccessIterator, RandomAccessIterator) = &doMerge;
      
      for (int i=1; i < numToTheLeft.size(); i++) {
         //write in the left
         RandomAccessIterator leftPointer = start + steps[i];
         RandomAccessIterator rightPointer = start + steps[i] + numToTheLeft[i] - numToTheLeft[i-1];
         RandomAccessIterator destPointer = storageArrayIt + numToTheLeft[i-1];
         tg2.create_thread(boost::bind(merge, leftPointer, rightPointer, destPointer));
         
         //and write in the right
         leftPointer = rightPointer;
         rightPointer = start + steps[i+1];
         destPointer = storageArrayIt + numToTheLeft[numToTheLeft.size()-1] + i * subdivLength;
         tg2.create_thread(boost::bind(merge, leftPointer, rightPointer, destPointer));
      }
      tg2.join_all();
      
      //setup recursion
      RandomAccessIterator newDest1 = start;
      RandomAccessIterator newDest2 = start + numToTheLeft[numToTheLeft.size()-1];
      
      start = storageArrayIt;
      RandomAccessIterator leftPointer = start + numToTheLeft[numToTheLeft.size()-1];      
      end = storageArrayIt + range;
      
      //now, do recursion
      void (*pSort) (RandomAccessIterator, RandomAccessIterator, size_t, Sample, RandomAccessIterator) 
            = &parallelSort;
      
      boost::thread t1(pSort, start, leftPointer, jobs_available/2, value, newDest1);
      boost::thread t2(pSort, leftPointer, end, jobs_available/2, value, newDest2);
      t1.join();
      t2.join();
      
   }   
}

template <class RandomAccessIterator, class Comparitor>
void parallelSortComparitor(
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
            = &parallelSortComparitor;
      
      boost::thread t1(pSort, start, leftPointer, jobs_available/2, comp);
      boost::thread t2(pSort, leftPointer, end, jobs_available/2, comp);
      t1.join();
      t2.join();
      
   }   
}