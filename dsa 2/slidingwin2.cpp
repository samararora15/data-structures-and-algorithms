//sliding window problem
//identification - array/string + subarray/substring + window size(k)
//types - fixed size window and variable size window
//first negative integer in every window of size k
#include<bits/stdc++.h>
using namespace std;
vector<int> slwin(int arr[],int size,int k)
{
    int i=0,j=0;
    queue<int> q;
    vector<int> ans;
    while(j<size)
    {
        if(arr[j]<0)
        {
            q.push(arr[j]);
        }
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1 == k)
        {
            if(q.size()==0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front());
                if(arr[i]==q.front())
                {
                    q.pop();
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"enter the value of k:";
    cin>>k;
    vector<int> ans = slwin(arr,size,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}