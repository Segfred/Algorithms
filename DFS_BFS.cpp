//  main.cpp
//  nonrecurdfs
//
//  Created by Asmita on 2017/01/18.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template<typename element>
class Graph
{
    
public:
    //Graph(int number);
    typedef unordered_map<element, unordered_set<element>> graph_type;
    void addEdge(const element& from, const element &to);
    void BFS(const element& start);
    void DFS(const element& start);
private:
    int counts_;
    graph_type Adj_;
    unordered_map<element, bool> visited_;
};

template<typename element>
void Graph<element>::addEdge(const element& from, const element &to)
{
    Adj_[from].insert(to);
    visited_[from]=false;
    visited_[to]=false;
}
template<typename element>
void Graph<element>::BFS(const element& start)
{
    queue<element> que{};
    que.push(start);
    cout<<"BFS Start:"<<endl;
    while(!que.empty())
    {
        element cur=std::move(que.front());
        cout<<cur<<endl;
        visited_[cur]=false;
        que.pop();

            for(auto const &neighbor:Adj_[cur])
                if(!visited_[neighbor]) que.push(neighbor);
    }
    
}
template<typename element>
void Graph<element>::DFS(const element& start)
{
    stack<element> stc;
    stc.push(start);
    while(!stc.empty())//every node is only pushed once
    {
        element cur=std::move(stc.top());
            cout<<cur<<endl;
            visited_[cur]=true;
        stc.pop();

        for(auto const &neighbor:Adj_[cur])
            if(!visited_[neighbor]) stc.push(neighbor);
    }
    
}

int main(int argc, const char * argv[]) {
    Graph<string> gra;
    string a="A",b="B",c="C",d="D",e="E",f="F",g="G",h="H";
    
    gra.addEdge(a, b);                   
    gra.addEdge(a, c);
    gra.addEdge(b, d);
    //gra.addEdge(c, d);  
    //gra.addEdge(d, f);
    gra.addEdge(b, e);
    gra.addEdge(d, h);
    gra.addEdge(c, f);
    gra.addEdge(c, g);

    gra.DFS(a);
    return 0;
}