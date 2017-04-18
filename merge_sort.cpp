//
//  main.cpp
//  mergesort
//
//  Created by Asmita on 17/1/8.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
template<typename Comparable>
void integrate(vector<Comparable> &vec, vector<Comparable> &target, size_t left, size_t rbegin, size_t right)
{
    size_t leftend=rbegin-1, tindex=left, count=right-left+1;
    while (left<=leftend&&rbegin<=right)
    {
        if (vec[left]<vec[rbegin])
            target[tindex++]=vec[left++];
        else
            target[tindex++]=vec[rbegin++];
    }
    while (left<=leftend)
        target[tindex++]=vec[left++];
    while (rbegin<=right)
        target[tindex++]=vec[rbegin++];
    --tindex;
    for (int i=0;i<count;++i,--tindex)//right cannot be replaced by tindex
        vec[tindex]=target[tindex];
    //for(;int(tindex)>=0;--tindex)下面两种写法都是可以的
        //vec[tindex]=target[tindex];
    /*
     for (int i=0;i<count;++i,--right)//right cannot be replaced by tindex, (right=tindex-1)
     vec[right]=target[right];
     */
    
}
template<typename Comparable>
void mergeSort(vector<Comparable> &vec, vector<Comparable> &target, size_t left, size_t right)
{
    if (left<right)
    {
        size_t mid=(left+right)/2;
        mergeSort(vec, target, left, mid);
        mergeSort(vec, target, mid+1, right);
        integrate(vec, target, left, mid+1, right);
    }
    
}
template<typename Comparable>
void mergeSort(vector<Comparable> &vec)
{
    vector<Comparable> temp(vec.size());
    mergeSort(vec, temp, 0, vec.size()-1);
}
int main(int argc, const char * argv[]) {
    vector<int> arr={2,10,32,5,6,3,7,9};
    mergeSort(arr);
    for (int k=0;k<=7;++k)
        cout <<arr[k]<<endl;
    return 0;
}
