//k closest numbers
#include<bits/stdc++.h>
using namespace std;
void funcheap(int arr[],int size,int key,int k)
{
    priority_queue<pair<int,int>> maxh;

    for(int i=0;i<size;i++)
    {
        int diff = abs(arr[i]-key);
        maxh.push(make_pair(diff,arr[i]));

        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }

    while(!maxh.empty())
    {
        pair<int,int> temp;
        temp = maxh.top();
        cout<<temp.second<<" ";
        maxh.pop();
    }
}
int main()
{   
    int arr[] = {8,7,5,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key,k;
    cout<<"enter key:";
    cin>>key;
    cout<<"enter constraint k:";
    cin>>k;
    funcheap(arr,size,key,k);
    return 0;
}