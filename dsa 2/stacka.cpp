//revision
//stack implementation using arrays
#include<bits/stdc++.h>
using namespace std;
#define size 5
int stak[size];
int top = -1;
void push(int n)
{
    if(top==size-1)
    {
        cout<<"STACK OVERFLOW";
    }
    else
    {
        top++;
        stak[top] = n;
    }
}
void pop()
{
    if(top==-1)
    {
        cout<<"STACK UNDERFLOW";
    }
    else
    {
        top = top-1;
    }
}
void traverse()
{
    cout<<"ELEMENTS OF STACK ARE:"<<endl;
    for(int i=top;i>=0;i--)
    {
        cout<<stak[i]<<endl;
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    push(50);
    pop();
    traverse();
    return 0;
}