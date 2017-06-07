//
//  main.cpp
//  insertion_sort
//
//  Created by Asmita on 2017/04/08.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

template<typename Comparable>
void insertion_sort(vector<Comparable> &vec)
{
    for(size_t p=1;p<vec.size();++p)
    {
        Comparable temp=std::move(vec[p]);
        int i;
        for(i=(int)p;i>0&&temp<vec[i-1];--i)
            vec[i]=std::move(vec[i-1]);
        vec[i]=std::move(temp);
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> arr{5,2,3,6,7,10,4};
    insertion_sort(arr);
    for(const auto &elem:arr)
        cout << elem<<endl;
    return 0;
}
