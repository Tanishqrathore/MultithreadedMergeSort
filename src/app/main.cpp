#include <iostream>
#include <vector>
#include <mutex>
#include <chrono> // Include chrono for timing
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"
#include <string>


int main(int argc, char *argv[]) {

    const int SIZE = 3*1e7;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % 10000000;
        nums1[i] = nums[i];
    }

    std::string st = argv[1];
    if(st=="simple"){ 
    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;

    std::cout << "MergeSort time taken: " << mergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort;}
    else{
      // Measure time for ParallelMergeSort
    int depth;
    std::cout<<"Recursive depth till which threads be spawned"<<std::endl;
    std::cin>>depth;
    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1,depth);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelMergeSortDuration = end - start;

    std::cout << "ParallelMergeSort time taken: " << parallelMergeSortDuration.count() << " seconds" << std::endl;

    delete mergesort1;
  }

   

    return 0;
}
