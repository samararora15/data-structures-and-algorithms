//cyclic sort 
//first missing positive
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {7,8,9,11,12};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<size)
    {
        if(arr[i]<size && arr[i]>0 && arr[i]!=i)
        {
            int cidx = arr[i];
            int temp = arr[cidx];
            arr[cidx] = arr[i];
            arr[i] = temp;
        }
        else
        {
            i++;
        }
    }
    for(int j=1;j<size;j++)
    {
        if(j!=arr[j])
        {
            cout<<j;
            break;
        }
        else if(j==size-1)
        {
            cout<<size;
        }
    }
    return 0;
}