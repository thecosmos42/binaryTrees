#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* lchild;
    Node* rchild;
};

class CircularQ
{
private:
    int front;
    int rear;
    int size;
    Node **q;
public:

    CircularQ(int k){front=rear=0;size = k; q = new Node*[size-1];}
    void enqueue(Node* ele);
    Node* dequeue();
    void display();
    int isFull();
    int isEmpty();

};

void CircularQ:: enqueue(Node* ele)
{
    if (front ==(rear+1)% size )
        cout<<"Queue is full ";
    else
    {
        rear = (rear+1)%size;
        q[rear] = ele;
    }
}

Node* CircularQ :: dequeue()
{
    Node* x=NULL;
    if (front == rear)
        cout<<"Queue is empty";
    else
    {
        front = (front+1)%size;
        x = q[front];
    }

    return x;
}

void CircularQ :: display()
{
    cout<<endl;
    if (front == rear )
        cout<<"Queue is empty";
    else
    {   cout<<"The elements are: ";
        for (int i=(front+1)%size; (rear+1)%size != i; )
        {
            cout<<q[i]<<" ";
            i = (i+1)%size;
        }
        cout<<endl;
    }
}

int CircularQ:: isFull()
{

    if (front == (rear+1)%size )
        return 1;
    else
        return 0;
}

int CircularQ:: isEmpty()
{

    if (front == rear )
        return 1;
    else
        return 0;
}


// int main()
// {
//
//     int n,i,x;
//     cout<<"Enter no. of elements \n";
//     cin>>n;
//     CircularQ a(n);
//     cout<<"Enter the elements";
//     for (i=1; i<=n; i++)
//     {   cin>>x;
//         a.enqueue(x);
//     }
//     a.display();
//     cout<<a.dequeue()<<" is the element deleted"<<endl;
//     cout<<a.isFull();
//     a.enqueue(9);
//     a.enqueue(16);
//     a.display();
// }
