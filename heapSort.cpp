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
        if (child+1<=number-1&&vec[child]<vec[child+1])//to ensure the right child is still within the heap as well as to pick up the bigger one
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

/*#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
template<typename Comparable>
void percolate_down(vector<Comparable> &srcvec, int hole, int end)
//end means node numbers(NOT index number)
{
    Comparable temp=std::move(srcvec[hole]);
    while(hole<=(end/2-1))
    {
        int child=hole*2+1;
        if(child<end-1&&srcvec[child]<srcvec[child+1]) ++child;
        if (temp<srcvec[child])
        {
            srcvec[hole]=std::move(srcvec[child]);
            hole=child;
        }
        else break;
    }
    srcvec[hole]=temp;
    
}
template<typename Comparable>
void heap_sort(vector<Comparable> &srcvec)
{
    int lnth=(int)srcvec.size();
    for(int i=(lnth/2-1);i>=0;--i) //build heap,i代表下标，不是第几个
    {
        percolate_down(srcvec, i, lnth);
    }
    
    for(int j=lnth-1;j>=1;--j)
    {
        //swap(srcvec[j],srcvec[0]);
        Comparable temp=std::move(srcvec[j]);
         srcvec[j]=std::move(srcvec[0]);
         srcvec[0]=std::move(temp);
        percolate_down(srcvec,0,j); //after swap, the itinial srcvec loses one item
    }
}
int main(int argc, const char * argv[]) {
    vector<int> arr={5,2,3,6,7,10,4};
    clock_t start,end;
    start=clock();
    heap_sort(arr);
    end=clock();
    for (int n=0;n<=6;++n)
        cout <<arr[n]<<endl;
    cout<<"run time"<<(double)(end-start)/CLOCKS_PER_SEC<<endl;
    return 0;
    return 0;
}
//
//  main.cpp
//  heap_sort
//
//  Created by Asmita on 2017/04/08.
//  Copyright © 2017年 Asmita. All rights reserved.
//
#include <iostream>
#include <vector>
//#include <ctime>
using namespace std;
template<typename Comparable>
void percolate_down(vector<Comparable> &srcvec, int hole, int end)
//endindex 代表下标
{
    Comparable temp=std::move(srcvec[hole]);
    while(hole<(end+1)/2) //hole<=(end-1)/2是不对的，因为int靠近0取整，不是向下取整,或者floor
    {
        int child=hole*2+1;
        if(child+1<=end&&srcvec[child]<srcvec[child+1]) ++child;//保证有右子树
        if (temp<srcvec[child])
        {
            srcvec[hole]=std::move(srcvec[child]);
            hole=child;
        }
        else break;
    }
    srcvec[hole]=temp;
    
}
template<typename Comparable>
void heap_sort(vector<Comparable> &srcvec)
{
    int lnth=(int)srcvec.size();
    for(int i=((lnth-1)/2);i>=0;--i) //build heap,i代表下标，不是第几个
    {
        percolate_down(srcvec, i, lnth-1);
    }
    cout<<"built heap is"<<endl;
    for(auto &elem:srcvec) cout<<elem<<","<<endl;
    for(int j=lnth-1;j>=1;--j)
    {
        swap(srcvec[j],srcvec[0]);
        percolate_down(srcvec,0,j-1); //after swap, the itinial srcvec loses one item
    }
}
int main(int argc, const char * argv[]) {
    vector<int> arr{5,2,3,6,7,10,4};
    heap_sort(arr);
    for (auto &elem:arr)
        cout <<elem<<endl;
    return 0;
}