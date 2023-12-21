//binary trees
#include<bits/stdc++.h>
using namespace std;

struct node{
    struct node *left;
    int data;
    struct node *right;

    node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

int balancedornot(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        int lh = balancedornot(temp->left);
        if(lh==-1)  return -1;
        int rh = balancedornot(temp->right);
        if(rh==-1)  return -1;

        if(abs(lh-rh)>1)    return -1;

        return 1+max(lh,rh);
    }
}

int heightoftree(struct node *temp)
{
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        int lh = heightoftree(temp->left);
        int rh = heightoftree(temp->right);

        return 1+max(lh,rh);
    }
}

void bfs(struct node *root)
{
    if(root==NULL)
    {
        return;
    }

    queue<node*> q;

    q.push(root);

    while(!q.empty())
    {
        struct node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }

}

void postorder(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        postorder(temp->left);
        postorder(temp->right);
        cout<<temp->data<<" ";
    }
}

void inorder(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        inorder(temp->left);
        cout<<temp->data<<" ";
        inorder(temp->right);
    }
}

void preorder(struct node *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        cout<<temp->data<<" ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

int main()
{
    struct node *root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    // preorder(root);

    // inorder(root);

    // postorder(root);

    // bfs(root);

    // cout<<heightoftree(root);

    cout<<balancedornot(root);

    return 0;
}