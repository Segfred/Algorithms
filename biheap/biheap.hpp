#ifndef BIHEAP_HPP_
#define BIHEAP_HPP_
#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
class BinaryHeap
{
public:
    explicit BinaryHeap(int capacity=100);
    explicit BinaryHeap(const vector<Comparable> &items);
    void deleteMin();
    void deleteMin(Comparable &minItem);
    void insert(const Comparable &elem);
    bool isEmpty() const;
    void makeEmpty();
    vector<Comparable> arr;
private:
    void buildHeap();
    int currentSize;
    
    void percolateDown(int hole);
    
};
template<typename Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    //if (isEmpty())
        //throw UnderflowException();
    arr[1]=arr[currentSize--];
    percolateDown(1);
}
template<typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &elem)
{
    if (currentSize==arr.size()-1)
        arr.resize(2*arr.size() );
    int hole=++currentSize;
    while (hole/2>=1&&elem<arr[hole/2])
    {
            arr[hole]=arr[hole/2];
            hole/=2;
    }
    arr[hole]=elem;
}
template<typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    Comparable temp=arr[hole];
    int child;
    while(hole<=currentSize/2)
    {
        child=2*hole;
        if (child!=currentSize&&arr[child+1]<arr[child])
            child++;
        if (temp>arr[child])
        {
            arr[hole]=arr[child];
            hole=child;
        }
        
        else
            break;
    }

    arr[hole]=temp;
}
template<typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> &items)
:currentSize(items.size()),arr(items.size()+10)
{
    for (int i=0;i<items.size();++i)
    {
        arr[i+1]=items[i];
    }
    buildHeap();
}
template<typename Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for (int j=currentSize/2;j>0;--j)
    {
        percolateDown(j);
    }
}
#endif