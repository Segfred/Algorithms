//
//  main.cpp
//  hesort.cpp
//
//  Created by Asmita on 2017/01/08.
//  Copyright © 2017年 Asmita. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
template<typename Comparable>
void percodown(vector<Comparable> &vec, int i, int number)
{
    int child=2*i+1;
    Comparable temp=vec[i];
    while(child<=number-1)//to ensure the left child is still within the heap
    {
        if (child+1<=number-1&&vec[child]<vec[child+1])//to ensure the left child is still within the heap
            child++;
        if (temp<vec[child])
        {
            vec[i]=vec[child];
            i=child;
            child=child*2+1;
        }
        else
            break;
    }
    vec[i]=temp;
}
template<typename Comparable>
void buildheap(vector<Comparable> &arr)
{
    for (int k=arr.size()/2-1;k>=0;--k)
        percodown(arr, k, arr.size());
}
template<typename Comparable>
void heapsort(vector<Comparable> &vec)
{
    buildheap(vec);
    for (int j=vec.size()-1;j>0;--j)
    {
        swap(vec[0],vec[j]);
        percodown(vec, 0, j);
    }
}


int main(int argc, const char * argv[]) {

    vector<int> arr={5,2,3,6,7,10,4};
    heapsort(arr);
    for (int n=0;n<=6;++n)
        cout <<arr[n]<<endl;
    return 0;
}