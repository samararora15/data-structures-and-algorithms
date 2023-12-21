//heaps
//how to identify the question requires heap?   Asnwer - question contains 2 keywords - k and smallest/largest
//heaps is of 2 types - min heap and max heap
//if question contains k and smallest keyword - create max heap
//if question contains k and largest keyword - create min heap 
//use of heap - basically every question of heap requires sorting(nlogn best) so it converts that into nlogk which is better
//max heap - priority_queue<int> maxh
//min heap - priority_queue<int,vector<int>,greater<int>>
//1- kth smallest element
#include<bits/stdc++.h>
using namespace std;
void funcheap(int arr[],int size,int k)
{
    priority_queue<int> maxh;

    for(int i=0;i<size;i++)
    {
        maxh.push(arr[i]);

        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }
    cout<<maxh.top();
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