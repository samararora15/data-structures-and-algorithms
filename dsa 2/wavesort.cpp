//wave sort
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,8,5,1,0,4,6,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<size-1;i=i+2)
    {
        if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
        {
            continue;
        }
        else if(arr[i]>arr[i-1])
        {
            int k = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = k;
        }
        else
        {
            int k = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = k;
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}