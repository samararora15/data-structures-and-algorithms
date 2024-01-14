//heaps practice
//heap is a tree based data structure with the tree being complete binary tree
//heap has comparitively larger memory as compared to stack and data in heap can be accessed globally
//heap can be a max heap or a min heap
#include<bits/stdc++.h>
using namespace std;

int getMaximumScore(int a, int b, int c)
{
    int ans=0;
    priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int x,y;
    while(pq.size()>1) {
        x = pq.top();
        x--;
        pq.pop();
        y = pq.top();
        y--;
        pq.pop();
        ans++;
        if(x>0) pq.push(x);
        if(y>0) pq.push(y);                   
    }
    return ans;
}

int pickGifts(vector<int>&gifts, int k)
{
    priority_queue<long long> maxh;
    for(int i=0;i<gifts.size();i++) {
        maxh.push(gifts[i]);
    }
    while(k>0) {
        long long a = sqrt(maxh.top());
        maxh.pop();
        maxh.push(a);
        k--;
    }
    long long ans=0;
    while(!maxh.empty()){
        ans = ans + maxh.top();
        maxh.pop();
    }
    return ans;
}

int lastStoneWeight(vector<int> &stones)
{
    if(stones.size()==1) {
            return stones[0];
        }
        priority_queue<int> maxh;
        for(int i=0;i<stones.size();i++) {
            maxh.push(stones[i]);
        }
        while(!maxh.empty()) {
            int y = maxh.top();
            maxh.pop();
            int x = maxh.top();
            maxh.pop();
            if(x!=y) {
                y = y-x;
                maxh.push(y);
            }
            if(maxh.size()==1) {
                return maxh.top();
            }
        }
        return 0;
}

void sumofelementsbwk1andk2smallest(int arr[], int size, int k1, int k2)
{
    priority_queue<int> maxh;

    int a,b;

    for(int i=0;i<size;i++)
    {
        maxh.push(arr[i]);

        if(maxh.size()>k1)
        {
            maxh.pop();
        }
    }
    a = maxh.top();
    while(!maxh.empty())
    {
        maxh.pop();
    }

    for(int i=0;i<size;i++)
    {
        maxh.push(arr[i]);

        if(maxh.size()>k2)
        {
            maxh.pop();
        }
    }
    b = maxh.top();

    int sum = 0;
    for(int i = 0;i<size;i++)
    {
        if(arr[i]>a && arr[i]<b)
        {
            sum = sum + arr[i];
        }
    }

    cout<<sum<<" ";
}

void kclosestpointstoorigin(int arr[][2], int size, int k)
{
    priority_queue<pair<int,pair<int,int>>> maxh;

    for(int i=0;i<size;i++)
    {
        int d = sqrt((arr[i][0]*arr[i][0]) + (arr[i][1]*arr[i][1]));

        maxh.push({d,{arr[i][0],arr[i][1]}});

        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }
    while(!maxh.empty())
    {
        cout<<maxh.top().second.first<<" "<<maxh.top().second.second<<endl;
        maxh.pop();
    }
}

void frequencysort(int arr[], int size)
{
    priority_queue<pair<int,int>> maxh;

    unordered_map<int,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it:mp)
    {
        maxh.push({it.second,it.first});
    }

    while(!maxh.empty())
    {
        int temp = maxh.top().first;
        while(temp!=0)
        {
            cout<<maxh.top().second<<" ";
            temp--;
        }
        maxh.pop();
    }
}

void topkfrequentnumbers(int arr[], int size, int k)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;

    map<int,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it:mp)
    {
        minh.push({it.second, it.first});

        if(minh.size()>k)
        {
            minh.pop();
        }
    }

    while(!minh.empty())
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }
}

void kclosestnumber(int arr[], int size, int k, int key)
{
    priority_queue<pair<int,int>> maxh;

    for(int i=0;i<size;i++)
    {
        int temp = abs(arr[i]-key);
        maxh.push({temp,arr[i]});

        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }

    while(!maxh.empty())
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }
}

void nearlysortedorksorted(int arr[], int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    int j=0;

    for(int i=0;i<size;i++)
    {
        minh.push(arr[i]);

        if(minh.size()>k)
        {
            cout<<minh.top()<<" ";
            minh.pop();
        }
    }
    while(!minh.empty())
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }
}

void returnklargestnumbers(int arr[],int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> minh;

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

int kthsmallestnumber(int arr[], int size, int k)
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
    return maxh.top();
}
int main()
{
    // int arr[] = {4,2,2,3,1,1,4,1,1,2,1,3};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int k1,k2;
    // cout<<"enter k1 && k2:";
    // cin>>k1>>k2;
    //cout<<kthsmallestnumber(arr,size,k);
    //returnklargestnumbers(arr,size,k);
    //nearlysortedorksorted(arr,size,k);
    //kclosestnumber(arr,size,k,key);
    //topkfrequentnumbers(arr,size,k);
    //frequencysort(arr,size);
    //kclosestpointstoorigin(arr,size,k);
    // sumofelementsbwk1andk2smallest(arr,size,k1,k2);

    // vector<int> v = {2,7,4,1,8,1};
    // int k = 3;
    // cout<<lastStoneWeight(weight);
    // cout<<pickGifts(v,k);

    int a = 3,b=5,c=4;
    cout<<getMaximumScore(a,b,c);
    return 0;
}