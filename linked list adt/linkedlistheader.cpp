

class List
{
    private:
        class node
        {
            public:
            int data;
            node *next;
        };
        node* head;
        int n;

        public:
        List(int n)
        {
            this->n=n;
            head=new node;

            cout<<"Enter elements\n";
            cin>>head->data;
            node *curr=head;
            node *temp;
            for(int t=1;t<n;t++)
            {
                temp=new node;
                cin>>temp->data;
                curr->next=temp;
                curr=temp;
            }
        }

        void display()
        {
            node *temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }




        void Insert(int data,int index)
        {
             node *newnode=new node;
                         newnode->data=data;

            if (index==0)
            {
                newnode->next=head;
                head=newnode;
                n++;
                return;
            }

            node *temp=head;
            for(int i=0;i<index-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            n++;
            temp=nullptr;
        }


        node& pos(int index)
        {
            node *temp=head;
            for(int i=0;i<index;i++)
            {
                temp=temp->next;
            }
            return *temp;
        }


        void Delete(int index)
        {
            node *temp=head;

            if (index==0)
                {
            head=head->next;
            delete temp;
            temp=nullptr;
            n--;
            return;
        }
        node *prev=nullptr;
            for(int i=0;i<index;i++)
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=temp->next;
            delete temp;
            temp=nullptr;
            prev=nullptr;
            n--;
        }

        void Reverse()
        {
            if(n==1)
                return;

            node* ptr1=head;
            node *ptr2=head->next;
            node *ptr3=ptr2->next;
            head->next=nullptr;

            while(ptr3!=nullptr)
            {
                ptr2->next=ptr1;
                ptr1=ptr2;
                ptr2=ptr3;
                ptr3=ptr3->next;
            }
            ptr2->next=ptr1;
            head=ptr2;
            ptr2=nullptr;
            ptr1=nullptr;
            ptr3=nullptr;
        }
           void Append(int data)
        {
            node *newnode=new node;
            newnode->data=data;
            node *temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            newnode->next=nullptr;
            temp->next=newnode;
            n++;
            temp=nullptr;

        }


     ~List()
     {
        node* temp;
        temp=head->next;

        while(temp!=nullptr)
        {
              delete head;
              head=temp;
              temp=temp->next;
        }
        delete head;
        head=nullptr;
     }

};
