//
//  main.cpp
//  bucketsort
//
//  Created by Asmita on 2017/04/09.
//  Copyright © 2017年 Asmita. All rights reserved.
//

#include <iostream>
//#include <iterator>
#include <iostream>
#include <vector>
using namespace std;
const int BUCKET_NUM = 10;

struct ListNode{
    explicit ListNode(int i=0):mData(i),mNext(NULL){}
    ListNode* mNext;
    int mData;
};

ListNode* insert(ListNode* head,int val){
    if(!head) return new ListNode(val);
    ListNode *dummy=new ListNode(-1);
    dummy->mNext=head;
    ListNode *pre=dummy;//两个指针指向同一地址,改变了其中一个指针的next地址另一个指针的next也会改变
    //因此最后的dummy->mNext就是改变之后的头节点，不是原来的头节点
    while(head&&val>head->mData) //如果第一个数head就比当前val大把val直接插到头节点,此时的head就会改变
    {  //故first=head,最后返回first是不对的，因为此时头节点已经改变
        pre=head;
        head=head->mNext;
    }
    ListNode *cur=new ListNode(val);
    cur->mNext=pre->mNext;
    pre->mNext=cur;
    return dummy->mNext;//为了和val不插入头节点进行统一直接返回dummy->mNext
}


ListNode* Merge(ListNode *head1,ListNode *head2){
    if(!head1) return head2;
    if(!head2) return head1;
    //ListNode *dummy=new dummyNode(-1);
    //dummy->mNext=head;
    ListNode *first=head1;
    while(head1->mNext) head1=head1->mNext;
    head1->mNext=head2;
    return first;
}

void BucketSort(int n,int arr[]){
    vector<ListNode*> buckets(BUCKET_NUM);
    for(int i=0;i<n;++i){
        int index = arr[i]/BUCKET_NUM;
        ListNode *head = buckets[index];
        buckets[index] = insert(head,arr[i]);
    }
    ListNode *head = buckets[0];
    for(int i=1;i<BUCKET_NUM;++i){
        head = Merge(head,buckets[i]);
    }
    for(int i=0;i<n;++i){
        arr[i] = head->mData;
        head = head->mNext;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int vec[] {5,3,76,43,45,2,23,85,63,38,51};
    BucketSort(11, vec);
    for(int i=0;i<11;++i)
    cout << vec[i]<<",";
    return 0;
}
