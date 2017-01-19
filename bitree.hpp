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
    void noRecurPre();
	//void InOrder(BiNode<T> *root);
    void noRecurInorder();
	void PostOrder();

private:
	BiNode<T> *root;
	void release(BiNode<T> *node);
	void create(BiNode<T> *&node);
};
template<typename T>
void BiTree<T>::noRecurInorder()
{
    if (root)
    {
        std::stack<BiNode<T>*> stc;
        BiNode<T> *temp=root;
        while (temp||!stc.empty())
        {
            while (temp)
            {
                stc.push(temp);
                temp=temp->lchild;
            }
            if(!stc.empty())
            {
                temp=stc.top();
                std::cout<<temp->data<<std::endl;
                stc.pop();
                temp=temp->rchild;
                
            }
        }
    }
}
template<typename T>
void BiTree<T>::noRecurPre()
{
    if (root)
    {
        std::stack<BiNode<T>*> stc;
        BiNode<T> *temp=root;
        while (!stc.empty()||temp)
        {
            while (temp)
            {
                std::cout<<temp->data<<std::endl;
                stc.push(temp);
                temp=temp->lchild;
            }
            
            if (!stc.empty())
            {
                temp=stc.top();
                stc.pop();
                temp=temp->rchild;
            }
            
        }
    }
    
}
template<typename T>
void BiTree<T>::PreOrder(BiNode<T> *root)
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

















