//
//  main.cpp
//  kruskal
//
//  Created by Asmita on 2017/04/05.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include "disjSets.hpp"
using namespace std;
//const int MAXCOST=1000000;
struct pairhash {
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};

template<typename element>
class Graph
{
    
public:
    typedef tuple<int,element,element> edge_type;
    //typedef unordered_map<element, unordered_set<element>> graph_type;
    //typedef unordered_map<pair<element, element>, int, pairhash> cost_type;
    
    void addEdge(const element& from, const element &to, int weight);
    void kruskal(vector<edge_type> &inputedges, disjSets<element> &djset);
        
    inline vector<edge_type>& getEdges()
    {
        return edges_;
    }
private:
    //graph_type Adj_;
    //cost_type weight_;
    vector<edge_type> edges_;
    
};

template<typename element>
void Graph<element>::addEdge(const element& from, const element &to, int weight)
{
    edges_.push_back(make_tuple(weight,from,to) );
}

template<typename element>
struct cmp{
    typedef tuple<int,element,element> edge;
    bool operator ()(edge& a,edge& b){
        return get<0>(a) > get<0>(b);
    }
};

template<typename element>
void Graph<element>::kruskal(vector<edge_type> &inputedges,disjSets<element> &djset)
{
    //typedef tuple<int,element,element> edge_type;
    vector<edge_type> rslt;
    int acceptedNum=0;
    
    priority_queue<edge_type, vector<edge_type>, cmp<element>> PQ;
    for(auto const&everyEdge:edges_)
        PQ.push(everyEdge);
    for(int i=0;acceptedNum<djset.getCount()-1;++i)
    {
        edge_type curEdge=std::move(PQ.top()) ;
        PQ.pop();
        if(!djset.isConnected(get<1>(curEdge),get<2>(curEdge)))
        {
            rslt.push_back(curEdge);
            ++acceptedNum;
            djset.unionSets(get<1>(curEdge),get<2>(curEdge));
        }
    }
        
    for(auto const &pntEdge:rslt)
        cout<<"weight is　"<<get<0>(pntEdge)<<"　connected by　"<<get<1>(pntEdge)<<"　and　"<<get<2>(pntEdge)<<endl;
}
int main(int argc, const char * argv[]) {
    Graph<string> gra{};
    
    string v1="V1",v2="V2",v3="V3",v4="V4",v5="V5",v6="V6",v7="V7";
    vector<string> nodevec{v1,v2,v3,v4,v5,v6,v7};
    gra.addEdge(v1, v2, 2);
    gra.addEdge(v1, v4, 1);
    gra.addEdge(v1, v3, 4);
    gra.addEdge(v2, v5, 10);
    gra.addEdge(v2, v4, 3);
    gra.addEdge(v3, v4, 2);
    gra.addEdge(v3, v6, 5);
    gra.addEdge(v4, v5, 7);

    gra.addEdge(v4, v6, 8);
    gra.addEdge(v4, v7, 4);
    gra.addEdge(v5, v7, 6);
    gra.addEdge(v6, v7, 1);
    disjSets<string> dijSet(nodevec);
    gra.kruskal(gra.getEdges(), dijSet);

    return 0;
}