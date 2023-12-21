//binary trees
#include<bits/stdc++.h>
using namespace std;
queue<struct node*> q;
struct node{
    int data;
    struct node *left;
    struct node *right; 
};
struct node *createNode(int data)
{
    struct node *treeNode = (struct node *)malloc(sizeof(struct node));
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}
void preordertraversal(struct node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        preordertraversal(temp->left);
        preordertraversal(temp->right);
    }
}
void inordertraversal(struct node *temp)
{
    if(temp!=NULL)
    {
        inordertraversal(temp->left);
        cout<<temp->data<<" ";
        inordertraversal(temp->right);
    }
}
void postordertraversal(struct node *temp)
{
    if(temp!=NULL)
    {
        postordertraversal(temp->left);
        postordertraversal(temp->right);
        cout<<temp->data<<" ";
    }
}
int height(struct node *temp)
{
    if(temp==NULL)  return 0;
    int heightLeft = height(temp->left);
    int heightRight = height(temp->right);
    return max(heightLeft,heightRight)+1;
}
void invert(struct node *temp)
{
    if(temp!=NULL)
    {
        invert(temp->left);
        invert(temp->right);
        swap(temp->left,temp->right);
    }
}
void leafnodes(struct node *temp)
{
    if(temp!=NULL)
    {
        leafnodes(temp->left);
        leafnodes(temp->right);
        if(temp->left == NULL && temp->right == NULL)
        {
            cout<<temp->data<<" ";
        }
    }
}
void bfs(struct node *temp)
{
    if(temp!=NULL)
    {
        q.push(temp);
        while(!q.empty())
        {
            auto a = q.front();
            cout<<a->data<<" ";
            if(a->left)
            q.push(a->left);
            if(a->right)
            q.push(a->right);
            q.pop();
        }
    }
}
int main()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // preordertraversal(root);
    // cout<<endl;
    // inordertraversal(root);
    // cout<<endl;
    // postordertraversal(root);
    // cout<<endl;
    // cout<<height(root);
    // invert(root);
    // preordertraversal(root);
    // leafnodes(root);
    bfs(root);
    return 0;
}