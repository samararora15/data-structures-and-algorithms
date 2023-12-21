//medium level arrays 
#include<bits/stdc++.h>
using namespace std;

void printallsubarrays(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int kadanealgo(int arr[], int size)
{
    int tempmax = 0, ans = INT8_MIN;

    for(int i=0;i<size;i++)
    {
        tempmax = tempmax + arr[i];
        if(tempmax>0)
        {
            ans = max(ans,tempmax);
        }
        else
        {
            tempmax = 0;
        }
    }
    return ans;
}

int moorevotingalgo2(int arr[], int size)
{
    //majority element in array i.e element occuring >= n/2 times

    int el=0,cnt=0;

    for(int i=0;i<size;i++)
    {
        if(cnt==0)
        {
            el = arr[i];
        }
        if(el==arr[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return el;
}

int moorevotingalgo1(int arr[], int size)
{
    //majority element in array i.e element occuring >= n/2 times
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    int k = INT8_MIN,ans=-1;
    for(auto it:mp)
    {
        if(k<it.second)
        {
            k = it.second;
            ans = it.first;
        }
    }
    return ans;
}

void sortarrayof012ordnfsort(int arr[], int size)
{
    //sorting an array of 0 1 and 2
    int low = 0, mid = 0, high = size-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            int k = arr[low];
            arr[low] = arr[mid];
            arr[mid] = k;
            low++;  mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            int k = arr[mid];
            arr[mid] = arr[high];
            arr[high] = k;
            high--;
        }
    } 
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

pair<int,int> sum2problemoptimalapproach(int arr[], int size, int target)
{
    sort(arr, arr+size); //solve using merge or quicksort in interview/technical round  
    //nlogn 

    int p=0,q=size-1;
    pair<int,int> pr;
    pr = {-1,-1};

    for(int i=0;i<size;i++)
    {
        if(arr[p]+arr[q]==target)
        {
            pr = {p,q};
            return pr;
        }
        else if(arr[p]+arr[q]<target)
        {
            p++;
        }
        else if(arr[p]+arr[q]>target)
        {
            q--;
        }
    }
    return pr;
}

pair<int,int> sum2problemtype2(int arr[], int size, int target)
{
    pair<int,int> p;

    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                p = {i,j};
            }
        }
    }
    return p;
}

bool sum2problemtype1(int arr[], int size, int target)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    //int arr[] = {1,2,0,1,2,2,2,0,1,2,0,2,2,1,0,2,2};

    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    //int target;
    //cout<<"enter target:";
    //cin>>target;

    //cout<<sum2problemtype1(arr,size,target);
    //pair<int,int> p = sum2problemtype2(arr,size,target);
    //cout<<p.first<<" "<<p.second<<endl;

    //pair<int,int> pr = sum2problemoptimalapproach(arr,size,target);
    //cout<<pr.first<<" "<<pr.second<<endl;

    //sortarrayof012ordnfsort(arr,size);

    //cout<<moorevotingalgo1(arr,size);

    //cout<<moorevotingalgo2(arr,size);

    //cout<<kadanealgo(arr,size);

    printallsubarrays(arr,size);

    return 0;
}