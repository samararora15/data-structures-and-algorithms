//merge sort
//recursive method
#include<bits/stdc++.h>
using namespace std;
void mergee(int arr[],int l,int mid,int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    int k = l;
    int arr1[n1];
    int arr2[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i] = arr[i+l];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i] = arr[mid+1+i];
    }
    int p=0,q=0;
    while(p<n1 && q<n2)
    {
        if(arr1[p]<arr2[q])
        {
            arr[k] = arr1[p];
            k++;
            p++;
        }
        else
        {
            arr[k] = arr2[q];
            k++;
            q++;
        }
    }
    while(p<n1)
    {
        arr[k] = arr1[p];
        k++;
        p++;
    }
    while(q<n2)
    {
        arr[k] = arr2[q];
        k++;
        q++;
    }
    return;
}
void mergesot(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergesot(arr,l,mid);
        mergesot(arr,mid+1,r);
        mergee(arr,l,mid,r);
    }
    return;
}
int main()
{
    int arr[] = {5,3,1,2,4,7,8,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int l=0,r=size-1;
    mergesot(arr,l,r);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}