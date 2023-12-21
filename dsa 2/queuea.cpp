//queue(FIFO - First In First Out)
//insertion and deletion from oppposite end
//implementation using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
int f = -1;
int r = -1;
int arr[size];
void ensert(int n)
{
    if(r==size-1)
    {
        printf("queue is full");
    }
    else
    {
        r=r+1;
        arr[r] = n;
        if(r==0)
        {
            f=0;
        }
    }
}
void delet()
{
    if(f==r==-1)
    {
        printf("queue is empty");
    }
    else if(f==r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = f+1;
    }
}
void traverse()
{
    for(int i=f;i<=r;i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
}
int main()
{
    ensert(10);
    ensert(20);
    delet();
    ensert(30);
    ensert(40);
    delet();
    ensert(60);
    traverse();
    return 0;
}