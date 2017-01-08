#ifndef BINODE_H_
#define BINODE_H_
template<typename T>
class BiNode
{
public:
	T data;
	BiNode<T> *lchild, *rchild;
    //~BiNode();
};

/*template<typename T>
BiNode<T>::BiNode()
{
    lchild=new BiNode<T>;
    rchild=new BiNode<T>;
}*/

/*template<typename T>
BiNode<T>::~BiNode()
{
    if(lchild!=nullptr) delete lchild;
    if(rchild!=nullptr) delete rchild;
}*/
#endif