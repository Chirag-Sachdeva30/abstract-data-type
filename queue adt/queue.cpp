#include <iostream>
using namespace std;


class Queue
{
        private:
            int *arr;
            int Size;
            int Front=0;
            int Rear=0;

        public:
            Queue(int Size)
            {
                this->Size=Size+1;
                arr= new int[this->Size];
            }

            void enqueue(int x);


            int dequeue();



            ~Queue()
            {
                delete []arr;
            }

};


 void Queue::enqueue(int x)
            {
                if((Rear+1)%Size==Front)
                cout<<"this queue is full"<<endl;
                else
                {
                    Rear=((Rear+1)%Size);
                    arr[Rear]=x;
                }
            }

            int Queue::dequeue()
            {
                if(Front==Rear)
                    {
                        cout<<"the queue is empty"<<endl;
                        return -1;
                    }

                else
                {
                    Front=(Front+1)%Size;
                    return arr[Front];
                }
            }



int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
           cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
      cout<<q.dequeue()<<endl;
           cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
      cout<<q.dequeue()<<endl;

    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.enqueue(14);
       cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
      cout<<q.dequeue()<<endl;
    return 0;
}
