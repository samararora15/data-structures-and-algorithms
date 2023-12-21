#include<bits/stdc++.h>
using namespace std;
int binsearch(int arr[],int size,int key)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid]==key)
        {
            cout<<"found:";
            return mid;
        }
        else if(arr[mid]>key)
        {
            e = mid-1;
        }
        else if(arr[mid]<key)
        {
            s = mid+1;
        }
    }
    return -1;
}
int main()
{
    //binary search
    int arr[] = {1,3,4,5,8,9,12,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key;
    cin>>key;
    cout<<binsearch(arr,size,key);
    return 0;
}