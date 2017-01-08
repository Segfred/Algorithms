#ifndef BINODE_H_
#define BINODE_H_
template<typename T>
class BiNode
{
public:
	T data;
	BiNode<T> *lchild, *rchild;
};
#endif
