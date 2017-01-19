#ifndef TRAVERSE_GRAPH_HPP
#define TRAVERSE_GRAPH_HPP
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
    queue<element> que;
    que.push(start);
    cout << "BFS: "<<endl;

    while(!que.empty())
    {
        element cur = que.front();
        que.pop();
        if(visited_[cur]==false)
        {
            visited_[cur]=true;
            cout<<cur<<endl;
            for (auto neighbor: Adj_[cur])
                que.push(neighbor);
        }

    }

}
template<typename element>
void Graph<element>::DFS(const element& start)
{

    stack<element> stc;
    cout << "DFS: "<<endl;
    stc.push(start);
    //typename graph_type::iterator ite;   
    while(!stc.empty())
    {
        element cur = stc.top();
        stc.pop();
        if(visited_[cur]==false)
        {
            visited_[cur]=true;
            cout<<cur<<endl;
            //for(auto ite = Adj_[cur].begin(); ite != Adj_[cur].end(); ++ite)
            for(auto neighbor: Adj_[cur])
                  stc.push(neighbor);

        }
        
    }
    
}
#endif