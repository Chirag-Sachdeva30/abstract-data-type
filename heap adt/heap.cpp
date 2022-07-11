#include <iostream>
#include <vector>
using namespace std;


class heap
{
private:
    int* a;
    int size;
    int last;

public:
    heap(int size=0)
    {
        this->size=size+1;
        a=new int[size+1];
        last=1;
    }

    void insert(int x);
    int Delete();

  ~heap()
  {
      delete []a;
      a=nullptr;
  }
};


void heap::insert(int x)
{
        last++;
        a[last]=x;
        int i=last;
    while(i>1)
    {
        if(x>a[i/2])
        {
            a[i]=a[i/2];
            i=i/2;
        }
        else
            break;
    }
    a[i]=x;
}



int heap::Delete()
{
    int x=a[1];
    a[1]=a[last];
    last--;
    int i=1;
    int j=2;
    while(j<=last)
    {
        if(j<last && a[j+1]>a[j])
            j=j+1;
        if(a[j]>a[i])
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else break;
    }
    a[last+1]=x;
    return x;
}


int main()
{
return 0;
}

