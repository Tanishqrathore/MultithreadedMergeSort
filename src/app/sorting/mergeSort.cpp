#include "mergeSort.hpp"
#include<iostream>
#include<vector>

MergeSort::MergeSort(std:: vector<int>*nums){
    this->nums=nums;
}

MergeSort::~MergeSort(){}

void MergeSort::recursiveSort(int left,int right){
      if(left>=right){return;}

      int mid =  left+(right-left)/2;
      recursiveSort(left,mid);
      recursiveSort(mid+1,right);
      
      //merging sorted vectors
      std::vector<int>result;
      int i=left,j=mid+1;
      while(i<mid+1 && j<right+1){
        if((*nums)[i]<=(*nums)[j]){result.push_back((*nums)[i++]);}
        else{result.push_back((*nums)[j++]);}
      }
      while(i<mid+1){result.push_back((*nums)[i++]);}
      while(j<right+1){result.push_back((*nums)[j++]);}
      i=left;
      for(auto it:result){
        (*nums)[i++]=it;
      }
}

void MergeSort::sort(){
       if(nums->size()==0){exit(1);}
       recursiveSort(0,nums->size()-1);
      //  for(int i=0;i<(*nums).size();i++){
      //   std::cout<<(*nums)[i]<<" ";
      //  }
}