//recursion practice
//check if array is sorted or not via recursion
#include<bits/stdc++.h>
using namespace std;
bool recurse(int arr[],int n)
{
    if(n==1)
    {
        return true;
    }
    else if(arr[n-2]<arr[n-1])
    {
        return recurse(arr,n-1);
    }
    else
    {
        return false;
    }
}
int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i=0;
    cout<<recurse(arr,n);
    return 0;
}