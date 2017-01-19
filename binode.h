#ifndef BINODE_H_
#define BINODE_H_
template<typename T>
struct BiNode
{
    T data;
    BiNode<T> *lchild, *rchild;
};
#endif