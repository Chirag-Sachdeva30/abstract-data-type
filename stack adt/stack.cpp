#include<iostream>
using namespace std;

template<class T>
class stack
{
    private:
        T*arr;
        int Size;
        int top=-1;

    public:
    stack(int Size)
    {
        this->Size=Size;
        arr=new T[Size];
    }

    void push(T val);

    bool isempty();

   bool isfull();


    T pop();


    ~stack()
    {
        delete []arr;
    }
};

template<class T>
  void stack<T>::push(T val)
   {
        if(top<Size-1)
        {
            top++;
          arr[top]=val;
        }
        else
        {
            cout<<"stack is full"<<endl;
        }
    }
template<class T>
    T stack<T>::pop()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else
        {
            top--;
            return arr[top+1];
        }
    }

    template<class T>
       bool stack<T>::isempty()
    {
        return (top==-1?true:false);
    }

    template<class T>
   bool stack<T>::isfull()
   {
       return (top==Size?true:false);
   }

   int main()
   {

       stack<char> test(3);

        stack<int>* stk;
        stk= new stack<int>(5);
       cout<<stk->pop();
       cout<<test.pop();
       test.push(69);
       test.push(4);
       test.push(69);
       test.push(69);
       cout<<test.pop();

       return 0;
   }
