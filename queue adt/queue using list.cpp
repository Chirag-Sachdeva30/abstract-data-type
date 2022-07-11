#include <iostream>
using namespace std;


class  Queue
{
private:
    class node
    {
        public:
        int data;
        node *next;
    };
    node *front;
    node *rear;

public:
    Queue()
    {
        front=nullptr;
        rear=nullptr;
    }
    void enqueue(int x);


    int dequeue();


    ~Queue()
    {
        node *t=front;
        while (front!=nullptr)
        {
            t=t->next;
            delete front;
            front=t;
        }
    }
};



     void Queue::enqueue(int x)
    {
        if(front==nullptr)
        {
            node *newnode= new node;
        newnode->data=x;
        newnode->next=nullptr;
        front=rear=newnode;
        return;
        }

        node *newnode= new node;
        newnode->data=x;
        newnode->next=nullptr;
        rear->next=newnode;
        rear=newnode;
    }




    int Queue::dequeue()
    {
        if(front==nullptr)
        {
            cout<<"queue is empty\n";
            return -1;
        }
        node *t=front;
        front=front->next;
        int x=t->data;
        delete t;
        t=nullptr;
        return x;
    }


int main()
{
    Queue test();
    test.enqueue(5);
    test.enqueue(6);
    test.enqueue(7);
    test.enqueue(15);
    cout<<test.dequeue();
    cout<<test.dequeue();
    cout<<test.dequeue();
    test.enqueue(16);
    test.enqueue(17);
    test.enqueue(10);
    test.enqueue(25);
   cout<<test.dequeue();
   cout<<test.dequeue();
   test.enqueue(35);
   cout<<test.dequeue();
    return 0;
}





