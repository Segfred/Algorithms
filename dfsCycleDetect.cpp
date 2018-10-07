//  main.cpp
//  cycleDetect
//
//  Created by Asmita on 2017/05/07.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N=1000;

vector<int> g[N];//邻接表存储
int vis[N];
stack<int> stc;
bool dfs(int u)
{
    vis[u] = -1;//-1用来表示顶点u正在访问
    if(!g[u].empty()) for(auto &neigh:g[u])//别忘了非空判断，不然会越界
    {
        if(vis[neigh]==-1)//表示这个点进入了两次，肯定出现了环
            return false;
        else if(!vis[neigh]&&!dfs(neigh)) return false;
    }
    vis[u] = 1;
    stc.push(u); //放到结果数组里，输出的时候记得倒序输出，（回溯的原因）
    cout<<u<<" pushed"<<",";
    return true;//本身这个点第一次访问，并且所有邻居节点出发都没遇到环，（邻居到不了这个节点），因此可以确定没环
}

bool toposort(int n)
{
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            cout<<"start from"<<i<<",";
            if(!dfs(i)) return false;//huan
        }
    }
    cout<<endl;
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    memset(vis,0,sizeof(vis));
    int V,E;
    cin>>V;
    cin>>E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    if(!toposort(V)) {cout<<"cycle exist"<<endl;return false;}

    while (!stc.empty()) {
        cout<<stc.top()<<endl;
        stc.pop();
    }
    return 0;
}

4 3
1 0
0 2
0 3

4 4
1 0
0 2
3 0
2 3
