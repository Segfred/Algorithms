//
//  main.cpp
//  tree_test
//
//  Created by Zhao Tianqi on 2017/01/17.
//  Copyright © 2017年 Zhao Tianqi. All rights reserved.
//


#include <iostream>
#include "binode.h"
#include "bitree.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
    BiTree<char> btree;
    //btree.noRecurPre();
    //btree.PostOrder();
    btree.noRecurInorder();
    return 0;
}
