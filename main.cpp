//
//  main.cpp
//  traversal_graph
//
//  Created by Asmita on 2017/01/19.
//  Copyright © 2017年 Zhao Tianqi. All rights reserved.
//

#include <iostream>

#include <string>
#include "traverse_graph.hpp"

int main(int argc, const char * argv[])
{
    Graph<string> gra1;
    string a="A",b="B",c="C",d="D";
    
    gra1.addEdge(a, b);
    gra1.addEdge(a, c);
    gra1.addEdge(b, d);
    gra1.addEdge(c, d);
    Graph<string> gra2(gra1);
    gra1.DFS(a);
    gra2.BFS(a);
    return 0;
}