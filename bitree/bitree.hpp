#ifndef BITREE_HPP_
#define BITREE_HPP_
#include "binode.h"
#include <stack>
template<typename T>
class BiTree
{
public:
	BiTree();
	~BiTree();
	void PreOrder(BiNode<T> *root);
	void InOrder(BiNode<T> *root);
	void PostOrder();

private:
	BiNode<T> *root;
	void release(BiNode<T> *node);
	void create(BiNode<T> *&node);
};

template<typename T>
void PreOrder(BiNode<T> *root)
{
	if(root!=nullptr)
	{
		std::cout<<root->data;
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}

	return;
}

template<typename T>
BiTree<T>::BiTree()
{
	create(root);
}

template<typename T>
void BiTree<T>::create(BiNode<T> *&node)
{
	char ch;
	std::cin>>ch;
	if(ch=='#') node = nullptr;
	else
	{
		node=new BiNode<T>;
		node->data=ch;
        create(node->lchild);
        create(node->rchild);
	}
}

template<typename T>
BiTree<T>::~BiTree()
{
	release(root);
}

template<typename T>
void BiTree<T>::release(BiNode<T> *node)
{
	if(node != nullptr)
	{
		release(node->lchild);
		release(node->rchild);
		delete node;
        //node=nullptr;
	}
}

template<typename T>
void BiTree<T>::PostOrder()
{
	BiNode<T> *pivot=root, *last=root;
	//vector<T> vec;
	if(root == nullptr) return;
	std::stack<BiNode<T>*> stc;
	stc.push(pivot);
	while(!stc.empty())
	{
		pivot=stc.top();
		if((!pivot->lchild&&!pivot->rchild)||last==pivot->rchild||(!pivot->rchild&&last==pivot->lchild))
		{
			last=pivot;
			std::cout<<pivot->data<<std::endl;
			stc.pop();
		}
		else
		{
			if(pivot->rchild!=nullptr)
				stc.push(pivot->rchild);
			if(pivot->lchild!=nullptr)
				stc.push(pivot->lchild);
		}
	}

}
#endif

















