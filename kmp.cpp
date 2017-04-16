//
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
    ssize len=patn.length();
    int k=0;//k denotes the length of same prefix and suffix pair
    for(ssize i=1;i<len;++i)//i must be from 1, NOT 0, otherwsie patn[0]=patn[0]
    {
        while(k>0&&patn[i]!=patn[k]) k=next[k-1];
        if(patn[i]==patn[k]) ++k;//one more match found
        next[i]=k;
    }
    
}

int kmp(const string &tgt, const string &pat)// return the matching position
{
    vector<int> next(pat.size(),0);
    makeNext(pat,next);
    const ssize plen=pat.length();
    for(ssize i=0,j=0;i<tgt.length();++i)//j denotes the matched length
    {
        while(j>0&&tgt[i]!=pat[j]) j=next[j-1];
        if(tgt[i]==pat[j]) ++j;
        if(j==plen) {cout<<"matched position is "<<i-plen+1<<endl;
            return int(i-plen+1);
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
