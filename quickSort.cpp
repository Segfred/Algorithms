//  main.cpp
//  quicksort
//
//  Created by Asmita on 2017/01/09.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
template<typename Comparable>
void quicksort(vector<Comparable> &vec, int left, int right)
{

    if (left<right)// end condition of the recursion, crucial!!! when equal, do nothing.
    {
        //swap(vec[left],vec[(left+right)/2]);
        int i=left, j=right;
        Comparable temp=vec[left];
        while (i<j)
        {
            while (i<j&&vec[j]>=temp) --j;
                vec[i]=vec[j];
            
            while (i<j&&vec[i]<=temp) ++i;
                vec[j]=vec[i];
            
        }
        vec[i]=temp;
        quicksort(vec, left, i-1);
        quicksort(vec, i+1, right);
    }

}

int main(int argc, const char * argv[]) {
    vector<int> arr={5,3,4,7,6,8,2,10};
    quicksort(arr, 0, 7);
    for (int k=0;k<arr.size();++k)
        cout <<arr[k]<<endl;
    return 0;
}
