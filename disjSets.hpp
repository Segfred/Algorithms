//
//  disjSets.cpp
//  disjSets
//
//  Created by Asmita on 2017/04/05.
//  Copyright © 2017年 Asmita. All rights reserved.
//
#ifndef _DISJSETS_HPP_
#define _DISJSETS_HPP_
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
template<typename DType>
class disjSets{
public:
    explicit disjSets(const vector<DType> &nodes);
    DType findParent(DType& nodeName) ;
    void unionSets(DType& node1, DType& node2);
    inline bool isConnected(DType& node1, DType& node2)
    {
        return findParent(node1)==findParent(node2);
    }
    inline int getCount()
    {
        return count_;
    }
private:
    unordered_map<DType, DType> roots_;
    unordered_map<DType, bool> added_;
    int count_=0;
};

template<typename DType>
disjSets<DType>::disjSets(const vector<DType> &nodes)
{   //count_=0;
    for(auto const &elem:nodes)
    {
        roots_[elem]=elem;
        //if(!added_[elem])
            ++count_;
    }
}

template<typename DType>
DType disjSets<DType>::findParent(DType& nodeName)
{
    if(roots_[nodeName]==nodeName) return nodeName;
    else return roots_[nodeName]= findParent(roots_[nodeName]);
}

template<typename DType>
void disjSets<DType>::unionSets(DType& node1, DType& node2) //union by size
{
    DType root1=findParent(node1);
    DType root2=findParent(node2);
    roots_[root2]=root1;
    /*if(root1!=root2)
    {
        if(roots_[root1]<roots_[root2]) //root1 is deeper, so let root2 move to root1
        {
            roots_[root1]+=std::move(roots_[root2]);
            roots_[root2]=root1;
        }
        
        else
        {
            roots_[root2]+=std::move(roots_[root1]);
            roots_[root1]=root2;
        }
    }*/
}

#endif



