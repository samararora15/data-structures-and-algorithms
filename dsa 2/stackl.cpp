//revision
//stack implementation using linked list
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int n)
{
    struct node *cur,*temp;
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = n;
    cur->next = NULL;
    if(top==NULL)
    {
        top = temp = cur;
    }
    else
    {
        cur->next = top;
        top = cur;
    }
}
void pop()
{
    struct node *po;
    if(top==NULL)
    {
        cout<<"STACK UNDERFLOW";
    }
    else
    {
        po = top;
        top = top->next;
        free(po);
        po = NULL;
    }
}
void traverse()
{
    cout<<"ELEMENTS OF STACK ARE:"<<endl;
    while(top!=NULL)
    {
        cout<<top->data<<endl;
        top = top->next;
    }
}
int main()
{
    push(10);
    push(20);
    push(40);
    pop();
    push(30);
    traverse();
    return 0;
}