// http://www.cnblogs.com/c-cloud/p/3224788.html
//  main.cpp
//  kmp
//
//  Created by Asmita on 2017/04/16.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef string::size_type ssize;

void makeNext(const string &patn, vector<int> &next)
{
    const ssize len=patn.length();
    int k=0,i=1;//k denotes the length of same prefix and suffix pair
    while( i<len)//i must be from 1, NOT 0, otherwsie patn[0]=patn[0]
    {
        if(patn[i]==patn[k]) next[i++]=++k;//one more match found
        else if(k==0) ++i;
        else k=next[k-1];
    }
    
}

int kmp(const string &tgt, const string &pat)// return the matching position
{
    vector<int> next(pat.size(),0);
    makeNext(pat,next);
    const ssize plen=pat.length();
    ssize i=0,j=0;
    while(i<tgt.length())//j denotes the matched length,和for++不一样,那个是延迟加1
    {
        if(tgt[i]==pat[j]) ++j,++i;
        else if(j==0) ++i;
        else j=next[j-1];
        if(j==plen) {cout<<"matched position is "<<i-plen<<endl;
            return int(i-plen);
        }
    }
    
    return -1;//not found
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string pattern("abcababcabc");
    string target{"gfsgbdhwabcababcabchfei"};
    //for(auto &elem:next) cout<<elem<<",";
    
    cout <<kmp(target,pattern)<<endl;
    return 0;
}

