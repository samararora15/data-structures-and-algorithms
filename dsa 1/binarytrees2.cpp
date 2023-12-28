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
void iterativepreorder(struct node *temp)
{
    stack<struct node*> s;
    s.push(temp);
    while(!s.empty())
    {
        auto a = s.top();
        s.pop();
        cout<<a->data<<" ";
        if(a->right)
        {
            s.push(a->right);
        }
        if(a->left)
        {
            s.push(a->left);
        }
    }
}
void iterativeinorder(struct node *temp)
{
    stack<struct node *>s;
    s.push(temp);
    while(!s.empty())
    {
        auto a = s.top();
        if(a->left)
        {
            s.push(a->left);
            a->left = NULL;
        }
        else
        {
            cout<<a->data<<" ";
            s.pop();
            if(a->right)
            {
                s.push(a->right);
                a->right = NULL;
            }
        }   
    }
}
void iterativepostorder(struct node *temp)
{
    stack<struct node *>s;
    s.push(temp);
    while(!s.empty())
    {
        auto a = s.top();
        if(a->left)
        {
            s.push(a->left);
            a->left = NULL;
        }
        else
        {
            if(a->right)
            {
                s.push(a->right);
                a->right = NULL;
            }
            else
            {
                cout<<a->data<<" ";
                s.pop();
            }
        }   
    }
}
bool isbst(int l, int r, struct node *temp)
{
    if(temp==NULL)  return true;
    if(temp->data<l || temp->data>r)    return false;
    if(isbst(l,temp->data,temp->left) && isbst(temp->data,r,temp->right))   return true;
    return false;
}
bool issametree(struct node *p, struct node *q)
{
    if(p==NULL && q==NULL)  return true;
    if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))    return false;
    if(p->data!=q->data)    return false;
    return issametree(p->left,q->left) && issametree(p->right,q->right);
}
bool isMirror(struct node *rootleft, struct node *rootright)
    {
        if(rootleft==NULL && rootright==NULL)   return true;
        if((rootleft!=NULL && rootright==NULL) || (rootleft==NULL) && rootright!=NULL)   return false;
        if(rootleft->data!=rootright->data) return false;
        return isMirror(rootleft->left,rootright->right) && isMirror(rootleft->right, rootright->left);
    }
bool issymmetric(struct node *root)
{
    if(root==NULL)  return true;
    return isMirror(root->left,root->right);
}
int searchBST(struct node *temp, int val)
{
    if(temp==NULL)  return -1;
    if(temp->data==val)  return temp->data;
    if(temp->data>val)   return searchBST(temp->left,val);
    if(temp->data<val)   return searchBST(temp->right,val);
    return -1;
}
struct node * insertBST(struct node* temp, int val)
{
    if(temp==NULL)
    {
        temp = createNode(val);
        return temp;
    }
    if(temp->data>val)  temp->left = insertBST(temp->left,val);
    if(temp->data<val)  temp->right = insertBST(temp->right,val);  
    return temp;
}
vector<double> averageoflevels(struct node *temp)
{
    queue<struct node *> q;
    vector<double> v;
    double sum = 0;
    q.push(temp);
    while(!q.empty())
    {
        int s = q.size();
        int k = s;
        while(s--)
        {
            struct node *t = q.front();
            q.pop();
            sum += t->data;
            if(t->left) q.push(t->left);
            if(t->right)    q.push(t->right); 
        }
        v.push_back(sum/k);
        sum = 0;
    }
    return v;
}
vector<int> topview(struct node *temp)
{
    vector<int> ans;
    if(temp==NULL)
    return ans;

    map<int,int> mp;
    queue<pair<struct node*,int>> q;

    q.push(make_pair(temp,0));
    while(!q.empty())
    {
        pair<struct node*,int> p = q.front();
        q.pop();
        struct node* n = p.first;
        int hd = p.second;

        if(mp.find(hd)==mp.end())
        // mp.insert({hd,n->data});
        mp[hd] = n->data;

        if(n->left)
        q.push(make_pair(n->left,hd-1));
        if(n->right)
        q.push(make_pair(n->right,hd+1));
    }
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    //normal tree
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    //bst
    // struct node *root = createNode(4);
    // root->left = createNode(2);
    // root->right = createNode(7);
    // root->left->left = createNode(1);
    // root->left->right = createNode(3);

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
    // bfs(root);
    // iterativepreorder(root);
    // iterativeinorder(root);
    // iterativepostorder(root);
    // cout<<isbst(INT_MIN, INT_MAX, root);
    // cout<<issametree(p,q);
    // cout<<issymmetric(root);
    // vector<double> v = averageoflevels(root);
    vector<int> v = topview(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    // int val;
    // cin>>val;
    // cout<<searchBST(root,val);
    // insertBST(root,val);
    return 0;
}