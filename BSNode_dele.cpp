void removeNode1(BSTNode *& p)  
{  
    BSTNode *q = NULL;  
    if(!p->rchild)//left child of p is empty
    {  
        q = p;  
        p = p->lchild;  
        delete q;  
    }  
    else if(!p->lchild)//right child of p is empty   
    {  
        q = p;  
        p = p->rchild;  
        delete q;  
    }  
    else//left and right children all exist      
    {  
        BSTNode *s = NULL;  
        q = p;  
        s = p->lchild;       //root node of the left subtree  
        while(s->rchild) //find the precursor node of inorder traversal                           
        {                     
            q = s;          
            s = s->rchild;   
        }  
        p->data = s->data;    
        if(q != p)           
        {  
            q->rchild = s->lchild;
        }  
        else               
        {  
            q->lchild = s->lchild; 
        }  
        delete s;          
    }  
}  
