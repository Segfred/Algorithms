#include <iostream>
#include <string>
using namespace std;
const int KEYNUM=26;

struct node{
    int count; //the appear times of the current prefix or words
    bool exist;
    struct node* next[KEYNUM];
};
node* creatNode()
{
    node* thenode=new node;
    thenode->count=0;
    thenode->exist=false;
    memset(thenode->next, 0, sizeof(thenode->next));
    return thenode;
}
void insert(node* root, string str)
{
    if(str.empty()) return;
    node* pcur=root;
    int index;
    for(size_t i=0;i<str.length();++i)
    {
        index=str[i]-'a';
        if(!pcur->next[index]) pcur->next[index]=creatNode();
        pcur=pcur->next[index];
        pcur->count++;
    }
    pcur->exist=true;
}

void destroy(node* root)
{
    for(int i=0;i<KEYNUM;++i)
        if (root->next[i]) destroy(root->next[i]);
    
    delete root;
}

int search(node *root, string str)
{
    if(str.empty()) return false;
    node *pcur=root;
    int index;
    for(size_t i=0;i<str.length();++i)
    {
        index=str[i]-'a';
        if(!pcur->next[index]) return 0;
        pcur=pcur->next[index];
    }
    return (pcur->count);
}

int main(){
    node *root=creatNode();
    string A{"very"},B{"good"},C{"very"},D{"sharp"};
    insert(root,A);
    insert(root,B);
    insert(root,C);
    insert(root,D);
    int a=search(root,A);
    cout<<a<<endl;
    destroy(root);
    cout<<search(root,A)<<endl;
    return 0;
}
