//hashing - it is a technique that maps a key to its corresponding hash value   
#include<bits/stdc++.h>
using namespace std;

//Time Complexity for storing and fetching
//map -> log(n) for all best, average and worst case
//unordered_map -> 0(1) for best, average and 0(n) for worst case

void hashmap2(char str[],int size)
{
    map<char,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[str[i]]++;
    }

    for(auto it : mp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
}

void hashmap1(int n, int arr[])
{
    map<int,int> mp;    //map stores values in sorted order

    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it = mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}

int main()
{
    //int arr[] = {5,4,7,7,1,4,3,4,4,4,5,1};
    //int n = sizeof(arr)/sizeof(arr[0]);

    //hashmap1(n,arr);
    char str[] = "disappointment";
    int size = sizeof(str)/sizeof(str[0]);
    hashmap2(str,size);
    return 0;
}