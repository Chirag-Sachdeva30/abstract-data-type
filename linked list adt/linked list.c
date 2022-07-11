#include <stdio.h>
#include <stdlib.h>

   struct node* head;
struct node
{
    int data;
    struct node *next;
};

void print(struct node *head)
{
      while (head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}
void reverse( struct node *q)
{
    if (q->next==NULL)
    {
        head=q;
        return;
    }
    struct node *s=q->next;
    reverse(q->next);
    s->next=q;
    q->next=NULL;
}

void delete(struct node *q, int x)
{
    struct node *prev=NULL;
    struct node *curr=q;
    while(curr && curr->data!=x)
    {
        prev=curr;
        curr=curr->next;
    }
    if(!curr)
        return ;
    if(prev->next=curr->next);
    free(curr);
}

struct node* createlist(int n)
{
    head=(struct node*)malloc(sizeof(struct node));
    scanf(" %d",&(head->data));
    head->next=NULL;
    struct node *temp=head;
    struct node *newnode;
    for(int i=1;i<n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf(" %d",&(newnode->data));
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
    newnode=NULL;
    temp=NULL;
    return head;
}
int main()
{
    int n;
    scanf(" %d",&n);

     head=createlist(n);

    reverse(head);
    delete(head,3);
    print(head);
    free(head);
    head=NULL;
    return 0;
}
