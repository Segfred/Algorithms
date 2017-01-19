void removeNode1(BSTNode *& p)  
{  
    BSTNode *q = NULL;  
    if(!p->rchild)//*p的右子树为空   
    {  
        q = p;  
        p = p->lchild;  
        delete q;  
    }  
    else if(!p->lchild)//*p的左子树为空   
    {  
        q = p;  
        p = p->rchild;  
        delete q;  
    }  
    else//左右子树均不空   
    {  
        BSTNode *s = NULL;  
        q = p;  
        s = p->lchild;       //左子树根结点  
        while(s->rchild) //寻找结点*p的中序前驱结点，                      
        {                   //也就是以p->lchild为根结点的子树中最右的结点   
            q = s;          //*s指向*p的中序前驱   
            s = s->rchild;   //*q指向*s的父节点   
        }  
        p->data = s->data;    //*s结点中的数据转移到*p结点，然后删除*s  
        if(q != p)          //p->lchild右子树非空   
        {  
            q->rchild = s->lchild;//把*s的左子树接到*q的右子树上   
        }  
        else                //p->lchild右子树为空 ,此时q ==p   
        {  
            q->lchild = s->lchild;//把*s的左子树接到*q的左子树上   
        }  
        delete s;           //删除结点*s   
    }  
}  