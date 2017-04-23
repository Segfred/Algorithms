//  Created by Asmita on 17/1/5.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void shellsort(vector<Comparable> &vec)
{
    //int gap;
    for (int gap=vec.size()/2;gap>0;gap/=2)
    {
        
        for (int i=gap;i<vec.size();++i)
        {
            int j;
            Comparable temp=vec[i];
            for (j=i-gap;j>=0&&vec[j]>temp;j-=gap)
            {
                vec[j+gap]=vec[j];
            }
            vec[j+gap]=temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr(10);
    arr={3,8,7,6,30,12,20,5,19,18};
    shellsort(arr);
    for (int k=0;k<arr.size();++k)
        cout<<arr[k]<<endl;
   // cout << "Hello, World!\n";
    return 0;
}