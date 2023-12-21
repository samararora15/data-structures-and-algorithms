//cyclic sort implementation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {3,5,2,1,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<size)
    {
        int cidx = arr[i]-1;
        if(arr[cidx]!=arr[i])
        {
            int temp = arr[cidx];
            arr[cidx] = arr[i];
            arr[i] = temp;
        }
        else
        {
            i++;
        }
    }
    for(int j=0;j<size;j++)
    {
        cout<<arr[j]<<" ";
    }
    return 0;
}