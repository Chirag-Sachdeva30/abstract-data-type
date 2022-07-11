#include <iostream>
using namespace std;

template<class T>
class  Queue
{
private:
    class node
    {
        public:
        T data;
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
    void enqueue(T x);

    bool isempty();


    T dequeue();


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


        template <class T>
     void Queue<T>::enqueue(T x)
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



        template <class T>
    T Queue<T>::dequeue()
    {

        node *t=front;
        front=front->next;
        T x=t->data;
        delete t;
        t=nullptr;
        return x;
    }

    template <class T>
bool Queue<T>::isempty()
{
    return (front==nullptr)?1:0;
}




