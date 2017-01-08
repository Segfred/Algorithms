//
//  main.cpp
//  biheap
//
//  Created by Asmita on 2017/01/04.
//  Copyright © 2017年 Asmita. All rights reserved.
//

int main(int argc, const char * argv[]) {
    vector<int> vec(10);
    vec={32,26,68,65,19,31,24,21,16,13};
    BinaryHeap<int> biheap=BinaryHeap<int> (vec);
    //vec.resize(11);
    //biheap.insert(10);
    for (int k=1;k<=10;++k)
        cout<<biheap.arr[k]<<endl;
    return 0;
}
