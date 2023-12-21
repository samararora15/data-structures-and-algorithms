//top k frequent numbers
//whenever we need to find frequency we use hash fucntion which is basically map which stores frequency
#include<bits/stdc++.h>
using namespace std;
void funcheap(int arr[],int size,int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;

    unordered_map<int,int> mp;      //unordered map has better complexity than ordered map thus it has been used

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it = mp.begin();it!=mp.end();it++)
    {
        minh.push(make_pair(it->second,it->first));

        if(minh.size()>k)
        {
            minh.pop();
        }
    }

    while(!minh.empty())
    {
        pair<int,int> temp;
        temp = minh.top();
        cout<<temp.second<<" ";
        minh.pop();
    }
}
int main()
{   
    int arr[] = {1,1,1,3,2,2,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"enter constraint k:";
    cin>>k;
    funcheap(arr,size,k);
    return 0;
}