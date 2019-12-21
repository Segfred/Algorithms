//
//  main.cpp
//  known_dijkstra
//
//  Created by Asmita on 17/4/3.
//  Copyright (c) 2017年 Asmita. All rights reserved.
//
//狄杰斯特拉的特点在于每次的最小值必定都是从已知的最短路径连接过去的，可能是之前找到的最短路径一直没排上号，也可能是上一次才刚刚发现的最短路径


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int MAXCOST=1000000;
struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ (std::hash<U>()(x.second)<<1);
    }
};

template<typename element>
class Graph
{
    
public:
    typedef unordered_map<element, unordered_set<element>> graph_type;
    typedef unordered_map<pair<element, element>, int, pairhash> cost_type;
    
    void addEdge(const element& from, const element &to, int weight);
    void dijkstra(const element& start);
    
    inline const element& getWeight(const element& from, const element &to) const
    {
        return weight_[make_pair(from,to)];
    }
    
    inline int getDist(const element& node)
    {
        return dist_[node];
    }
private:
    graph_type Adj_;
    cost_type weight_;
    unordered_map<element, bool> known_;
    unordered_map<element, int> dist_;//distance to the source node
    unordered_map<element, element> path_;//records the middle paths by current node and previous node order
    
};

template<typename element>
void Graph<element>::addEdge(const element& from, const element &to, int weight)
{
    Adj_[from].insert(to);
    weight_.insert(make_pair(make_pair(from, to), weight) );
    dist_[from]=dist_[to]=MAXCOST;
}

template<typename element>
struct cmp{
    typedef pair<int,element> pie;
    bool operator ()(pie a,pie b){
        return a.first > b.first;
    }
};

template<typename element>
void Graph<element>::dijkstra(const element &start)
{
    typedef pair<int,element> pie;
    priority_queue<pair<int,element>, vector<pair<int,element>>, cmp<element>> PQ;
    dist_[start] = 0;
    cout<<"push"<<start<<endl;
    PQ.push({dist_[start],start});
    while(!PQ.empty()){
        pie x = PQ.top();
        cout<<"pop"<<x.second<<endl;
        known_[x.second]=true;
        PQ.pop();
        //if(x.first>dist_[x.second]) continue;
        for(auto const &neighbor : Adj_[x.second]){
            if(!known_[neighbor])
            {
                int curCost = weight_[make_pair(x.second, neighbor)];
                if(dist_[neighbor] > dist_[x.second] + curCost){
                    dist_[neighbor] = dist_[x.second] + curCost;
                    path_[neighbor]=x.second;
                    cout<<"push"<<neighbor<<endl;
                    PQ.push(make_pair(dist_[neighbor],neighbor));
            }
           
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    Graph<string> gra{};
    string v1="V1",v2="V2",v3="V3",v4="V4",v5="V5",v6="V6",v7="V7";
    gra.addEdge(v1, v2, 2);
    gra.addEdge(v1, v4, 1);
    gra.addEdge(v2, v5, 10);
    gra.addEdge(v2, v3, 4);
    gra.addEdge(v3, v1, 4);
    gra.addEdge(v3, v6, 5);
    gra.addEdge(v4, v3, 2);
    gra.addEdge(v4, v5, 2);
    gra.addEdge(v4, v6, 8);
    gra.addEdge(v4, v7, 4);
    gra.addEdge(v5, v7, 6);
    gra.addEdge(v7, v6, 1);
    
    gra.dijkstra(v1);
    cout<<gra.getDist(v1)<<","<<gra.getDist(v2)<<gra.getDist(v3)<<gra.getDist(v4)<<gra.getDist(v5)<<gra.getDist(v6)<<gra.getDist(v7)<<endl;
    return 0;
}
