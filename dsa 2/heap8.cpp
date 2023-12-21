//connect ropes to minimize the cost
#include<bits/stdc++.h>
using namespace std;
int funcheap(int arr[],int size)
{
    priority_queue<int,vector<int>,greater<int>> minh;
    int cost = 0;

    for(int i=0;i<size;i++)
    {
        minh.push(arr[i]);
    }

    while(minh.size()>1)
    {
        int r1 = minh.top();
        minh.pop();
        int r2 = minh.top();
        minh.pop();
        int cur_len = r1+r2;
        cost = cost + cur_len;
        minh.push(cur_len);
    }

    return cost;
}
int main()
{   
    int arr[] = {4,7,1,2,9,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int cost = funcheap(arr,size);
    cout<<"cost is = "<<cost;
    return 0;
}