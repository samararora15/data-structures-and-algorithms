//quick sort
//recursive method
#include<bits/stdc++.h>
using namespace std;
int partitionn(int arr[],int l,int r)
{
    int pi = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pi)
        {
            i++;
            int k = arr[i];
            arr[i] = arr[j];
            arr[j] = k; 
        }
    }
    int p = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = p;
    return i+1;
}
void quicksot(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi = partitionn(arr,l,r);

        quicksot(arr,l,pi-1);
        quicksot(arr,pi+1,r);
    }
    return;
}
int main()
{
    int arr[] = {5,3,1,8,7,4,6,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksot(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}