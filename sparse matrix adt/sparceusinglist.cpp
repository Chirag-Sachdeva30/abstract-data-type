#include<iostream>
#include "listforsparce.h"
using namespace std;

class sparce
{
    private:
        int row;
        int col;
        int num;
        List** Row;
    public:
        sparce(int row, int col)
        {
            this->row=row;
            this ->col=col;
            Row=new List*[row];
            for(int i=0;i<row;i++)
            {
                cout<<"Enter number of elements in row "<<i<<endl;
                int l;
                num+=l;
                cin>>l;
                Row[i]=new List(l);

            }
        }

        void display()
        {
            for(int i=0;i<row;i++)
            {
                Row[i]->display();
                cout<<endl;
            }
        }

        ~sparce()
        {
            for(int i=0;i<row;i++)
                 delete Row[i];
                delete []Row;
        }
};

int main()
{
    sparce test(2,2);
    test.display();
    return 0;
}
