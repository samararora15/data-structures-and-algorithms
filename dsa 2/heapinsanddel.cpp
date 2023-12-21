//maxheap insertion and deletion
#include<bits/stdc++.h>
using namespace std;
void heapdelete(int &size,int arr[])
{
    arr[1] = arr[size-1];
    size = size-2;
    int i = 1;
    while(i<size)
    {
        int left = arr[2*size];
        int right = arr[2*size+1];
        int larger = left>right?2*size:2*size+1;
        if(arr[larger]>arr[i])
        {
            int temp = arr[larger];
            arr[larger] = arr[i];
            arr[i] = temp;
            i = larger;
        }
        else
        {
            break;
        }
    }
}
void heapinsert(int &size,int arr[],int key)
{
    size = size+1;
    arr[size-1] = key;

    int i = size-1;
    while(i>1)
    {
        int parent = i/2;
        if(arr[parent]<arr[i])
        {
            int temp = arr[parent];
            arr[parent] = arr[i];
            arr[i] = temp;
            i = parent;
        }
        else
        {
            break;
        }
    }
}
int main()
{   
    int size = 6;
    int arr[size] = {-1,40,30,10,20,15};
    int key;
    cout<<"enter key:";
    cin>>key;
    heapinsert(size,arr,key);
    for(int i=1;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapdelete(size,arr);
    for(int i=1;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}