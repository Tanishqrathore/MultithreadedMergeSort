#include "parallelMergeSort.hpp"
#include <algorithm>

ParallelMergeSort::ParallelMergeSort(std::vector<int> *nums,int depth) 
{this->nums=nums; this->depth=depth;}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right,int depth) {

    const int THRESHOLD = 5000;

    if (right - left < THRESHOLD) {
        std::sort(nums->begin() + left, nums->begin() + right + 1);
        return;
    }
    
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    if(depth>0){
      depth--;
      std::thread thread_1([this, left, mid,depth] { this->recursiveSort(left, mid,depth); });
      std::thread thread_2([this, mid, right,depth] { this->recursiveSort(mid + 1, right,depth); });
      thread_1.join();
      thread_2.join();
   }
   else{
    this->recursiveSort(left, mid,depth);
    this->recursiveSort(mid + 1, right,depth);
   }
   
    std::vector<int> result;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if ((*nums)[i] <= (*nums)[j]) {
            result.push_back((*nums)[i]);
            i++;
        } else {
            result.push_back((*nums)[j]);
            j++;
        }
    }

    while (i <= mid) {
        result.push_back((*nums)[i]);
        i++;
    }

    while (j <= right) {
        result.push_back((*nums)[j]);
        j++;
    }

    for (int k = 0; k < result.size(); k++) {
        (*nums)[left + k] = result[k];
    }
}

void ParallelMergeSort::sort() {
    if ((*nums).size() == 0) {
        exit(1);
    }

    std::thread thread_1([this] { this->recursiveSort(0, (*nums).size() - 1,depth); });
    thread_1.join();

    //  for(int i=0;i<(*nums).size();i++){
    //     std::cout<<(*nums)[i]<<" ";
    //    }

}