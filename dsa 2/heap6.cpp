//frequency sort
//whenever we need to find frequency we use hash fucntion which is basically map which stores frequency
#include<bits/stdc++.h>
using namespace std;
void funcheap(int arr[],int size)
{
    priority_queue<pair<int,int>> maxh;

    unordered_map<int,int> mp;      //unordered map has better complexity than ordered map thus it has been used

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it = mp.begin();it!=mp.end();it++)
    {
        maxh.push(make_pair(it->second,it->first));
    }

    while(!maxh.empty())
    {
        pair<int,int> temp;
        temp = maxh.top();
        while(temp.first>0)
        {
            cout<<temp.second<<" ";
            temp.first -= 1;
        }
        maxh.pop();
    }
}
int main()
{   
    int arr[] = {1,1,1,3,2,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    funcheap(arr,size);
    return 0;
}