#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <thread>
#include <mutex>
#include <iostream>

class ParallelMergeSort {
private:
    std::vector<int> *nums;
    int depth;

public:
    ParallelMergeSort(std::vector<int> *nums,int depth);
    ~ParallelMergeSort();
    void sort();
    void recursiveSort(int left, int right,int depth);
};

#endif