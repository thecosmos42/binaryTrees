#include<iostream>
#include "CircularQ.h"

using namespace std;

Node* root = NULL;
class Tree
{
private:
    Node* root;
public:
    Tree(){root = NULL;}
    void create();
    void preorder() {preorder(root);}
    void preorder(Node* t)
    {
        if (t)
        {
            cout<<t->data;
            preorder(t->lchild);
            preorder(t->rchild);
        }
    }
    void inorder(){inorder(root);}
    void inorder(Node* t)
    {
        if (t)
        {
            inorder(t->lchild);
            cout<<t->data;
            inorder(t->rchild);
        }
    }
    void postorder(){postorder(root);}
    void postorder(Node* t)
    {
        if (t)
        {
            postorder(t->lchild);
            cout<<t->data;
            postorder(t->rchild);
        }
    }

};

void Tree:: create()
{
    int i,x;
    Node *p, *q;
    cout<<"Enter root element \n";
    cin>>x;
    root = new Node;
    root->data = x;
    root->lchild=NULL;
    root->rchild=NULL;
    CircularQ arr(100);
    arr.enqueue(root);
    while(!arr.isEmpty())
    {
        p = arr.dequeue();
        cout<<"\nEnter a left child for "<<p->data;
        cin>>x;
        if (x!=-1)
        {
            q = new Node;
            q->data = x;
            q->lchild = NULL;
            q->rchild = NULL;
            arr.enqueue(q);
            p->lchild = q;
        }

        cout<<"\nEnter a right child for "<<p->data;
        cin>>x;
        if(x!=-1)
        {
            q = new Node;
            q->data = x;
            q->lchild = NULL;
            q->rchild = NULL;
            arr.enqueue(q);
            p->rchild = q;

        }

    }
}


int main()
{
    Tree a;
    a.create();
    a.preorder();


}
