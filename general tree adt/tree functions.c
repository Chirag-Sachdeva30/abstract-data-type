int countnodes(struct Node *root)
{
if(root)
return countnodes(root->lchild)+countnodes(root->rchild)+1;
return 0;
}


int count2deg(struct Node *root)
{
if(root && root->lchild && root->rchild)
return count2deg(root->lchild)+count2deg(root->rchild)+1;
elseif(root)
return count2deg(root->lchild)+count2deg(root->rchild);
return 0;
}

int sumnodes(struct Node *root)
{
if(root)
return sumnodes(root->lchild)+sumnodes(root->rchild)+root->data;
return 0;
}

int countleaf(struct Node *root)
{
    return count2deg(root)+1;
}

int count1deg(struct node *root)
{
    return countnodes(root)-countleaf(root)-count1deg(root);
}

int height(struct Node *root)
{
int x=0,y=0;
if(root==0)
return 0;
x=height(root->lchild);
y=height(root->rchild);
if(x>y)
return x+1;
else
return y+1;
}

int main()
{
    return 0;
}
