//cyclic sort
//smallest missing positive number
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {4,0,2,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<size)
    {
        int cidx = arr[i];
        if(arr[i]<size && arr[i]!=arr[cidx])
        {
            int temp = arr[i];
            arr[i] = arr[cidx];
            arr[cidx] = temp;
        }
        else
        {
            i++;
        }
    }
    for(int j=0;j<size;j++)
    {
        if(j!=arr[j])
        {
            cout<<j;
            break;
        }
        if(j==size-1)
        {
            cout<<size;
        }
    }
    return 0;
}