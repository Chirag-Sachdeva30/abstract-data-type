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

            node *newnode= new node;
        newnode->data=x;
                newnode->next=nullptr;
        if(front==nullptr)
        {
        front=rear=newnode;
        return;
        }


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
    Queue test;
    test.enqueue(5);
    test.enqueue(6);
    test.enqueue(7);
    test.enqueue(15);
    cout<<test.dequeue()<<endl;
    cout<<test.dequeue()<<endl;
    cout<<test.dequeue()<<endl;
    test.enqueue(16);
    test.enqueue(17);
    test.enqueue(10);
    test.enqueue(25);
   cout<<test.dequeue()<<endl;
   cout<<test.dequeue()<<endl;
   test.enqueue(35);
   cout<<test.dequeue()<<endl;
    return 0;
}





