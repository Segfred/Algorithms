//
//  main.cpp
//  count_sort
//
//  Created by Asmita on 17/3/25.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void countsort(vector<int>& src, vector<int>& buffer, vector<int>& target)
{
    size_t srclength=src.size();
    size_t maxnum=buffer.size();
    for(size_t i=0;i<srclength;++i)
        ++buffer[src[i]];
    for(size_t j=1;j<=maxnum;++j)
        buffer[j]+=buffer[j-1];
    for(int i=int(srclength)-1;i>=0;--i)
    {
        target[--buffer[src[i]]]=src[i];
        //--buffer[src[i]];
    }
    for(auto const&elem:target)
        cout<<elem<<","<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> origin{2,5,3,0,2,3,0,3};
    vector<int> buffer(6,0);
    vector<int> dest(origin.size(),0);
    countsort(origin, buffer, dest);
    return 0;
}
