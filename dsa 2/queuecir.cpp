//circular queue implementation using arrays
#include<bits/stdc++.h>
using namespace std;
#define size 5
int que[size];
int f=-1;
int r=-1;
void enqueue(int n)
{
    if((r+1)%size==f)
    {
        cout<<"QUEUE IS FULL";
    }
    else if(f==-1 && r==-1)
    {
        f = 0;
        r=r+1;
        que[r] = n;
    }
    else
    {
        r = (r+1)%size;
        que[r] = n;
    }
}
void dequeue()
{
    if(f==-1 && r==-1)
    {
        cout<<"QUEUE IS EMPTY";
    }
    else if(f==r)
    {
        f=-1;
        r=-1;
    }
    else
    {
        f = (f+1)%size;
    }
}
void traverse()
{
    cout<<"ELEMENTS OF QUEUE ARE:"<<endl;
    for(int i=f;i<=r;i++)
    {
        cout<<que[i]<<endl;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    traverse();
    enqueue(10);
    traverse();
    return 0;
}