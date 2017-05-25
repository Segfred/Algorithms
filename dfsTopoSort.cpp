#include <iostream>
#include <vector>
#include <stack>
const int MAX_V=10005;
using namespace std;
typedef int NODE;
int V, E;
bool visited[MAX_V];
vector<NODE> adj[MAX_V];//adjacent list storing for graph
stack<NODE> stc{};
void dfs(int node){
    visited[node]=true;
    if(!adj[node].empty()) for(NODE &ele:adj[node]) if(!visited[ele]) dfs(ele);
    stc.push(node);
}

int main(int argc, const char* argv[]){
    cin>>V;
    cin>>E;
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<E;++i){
        NODE from, to;
        cin>>from;
        cin>>to;
        adj[from].emplace_back(to);
    }
    
    for(NODE j=0;j<V;++j){
        if(!visited[j])  dfs(j);
    }
    while(!stc.empty()) {cout<<stc.top(); stc.pop();}
}