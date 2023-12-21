//return k largest elements in an array
#include<bits/stdc++.h>
using namespace std;
void funcheap(int arr[],int size,int k)
{
    priority_queue<int,vector<int>,greater<int>> minh;

    for(int i=0;i<size;i++)
    {
        minh.push(arr[i]);

        if(minh.size()>k)
        {
            minh.pop();
        }
    }

    while(!minh.empty())
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }
}
int main()
{   
    int arr[] = {7,10,4,3,20,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"enter constraint k:";
    cin>>k;
    funcheap(arr,size,k);
    return 0;
}