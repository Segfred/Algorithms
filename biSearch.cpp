//int binary_search(int *A, int C, int V) {
	int left=0, right=C-1;  // 闭合空间
  while(left<right){
    int mid=left+(right-left>>1);
    if(A[mid]<V) left=mid+1;
    else right=mid;
  }
  if(A[left]==V) return left;
  return -1;
}
l+1=r，且最终在l
l+1=r，且最终在r
l+2=r，且最终在l+1
//  main.cpp
//  biSearch
//
//  Created by Asmita on 2017/04/15.
//  Copyright © 2017年 Asmita. All rights reserved.

#include <iostream>
using namespace std;

typedef int INDEX;
INDEX myUpperBound(int *arr, int size, int target)
{
    //int len=sizeof(arr);指针取大小不是元素个数*每个元素大小,而是指针本身大小
    cout<<"length of arr== "<<sizeof(arr)<<endl;
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=left+((right-left)>>1);
        if(arr[mid]<=target) left=mid+1;
        else right=mid-1;
    }
    return left;
}
INDEX myLowerBound(int *arr, int size, int target)
{
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=left+((right-left)>>1);
        if(arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return left;
}

INDEX lastElement(int *arr, int size, int target)
{
    //int len=sizeof(arr);指针取大小不是元素个数*每个元素大小,而是指针本身大小
    cout<<"length of arr== "<<sizeof(arr)<<endl;//大于等于pivot最后一个数upper_bound-1
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=left+((right-left)>>1);
        if(arr[mid]>target) right=mid-1;
        else left=mid+1;
    }
    return right;//这个时候就一定要返回right,不能是left,因为是从右向左的大方向
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[]{1,3,5,5,5,7,8,9,10,11};
    //int a[]{1};
    int len=sizeof(a)>>2;
    //cout<<"size of a is "<<sizeof(a)<<endl;
    cout << "upper bound is "<<myUpperBound(a, len,11)<<endl;
    cout<<"last element is"<<lastElement(a,len,11)<<endl;
    
    return 0;
}
