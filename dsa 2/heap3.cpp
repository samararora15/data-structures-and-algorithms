//sort a k sorted(nearly sorted) array
#include<bits/stdc++.h>
using namespace std;
vector<int> funcheap(int arr[],int size,int k)
{
    priority_queue<int,vector<int>,greater<int>> minh;
    vector<int> ans_arr;

    for(int i=0;i<size;i++)
    {
        minh.push(arr[i]);

        if(minh.size()>k)
        {
            ans_arr.push_back(minh.top());
            minh.pop();
        }
    }
    while(!minh.empty())
    {
        ans_arr.push_back(minh.top());
        minh.pop();
    }
    return ans_arr;
}
int main()
{   
    int arr[] = {6,5,3,2,8,10,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"enter constraint k:";
    cin>>k;
    vector<int> ans_arr = funcheap(arr,size,k);
    for(int i=0;i<ans_arr.size();i++)
    {
        cout<<ans_arr[i]<<" ";
    }
    return 0;
}