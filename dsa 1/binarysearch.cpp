//binary search
#include<bits/stdc++.h>
using namespace std;
int bs_el_bitonic(int nums[], int size, int key)
{
    int s=0,e=size-1,id=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            id = mid;
            return id;
        }
        else if(nums[mid]>nums[mid+1] && (mid+1)<=size-1)
        {
            id = mid;
            e = mid-1;
        }
        else if(nums[mid]<nums[mid+1] && (mid+1)<=size-1)
        {
            s = mid+1;
        }
    }
    s=0,e=id-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            id = mid;
            return id;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    s=id+1,e=size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            id = mid;
            return id;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return id;
}
int bs_maxel_bitonic(int nums[], int size)
{
    int s=0,e=size-1,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]>nums[mid+1] && (mid+1)<=size-1)
        {
            ans = max(ans,nums[mid]);
            e = mid-1;
        }
        else if(nums[mid]<nums[mid+1] && (mid+1)<=size-1)
        {
            s = mid+1;
        }
    }
    return ans;
}
int bs_peak_element(int nums[], int size)
{
    int s=0,e=size-1,ans=nums[size-1];
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1] && (mid-1)>=0 && (mid+1)<=size-1)
        {
            ans = nums[mid];
            return ans;
        }
        else if(nums[mid]<nums[mid-1] && (mid-1)>=0)
        {
            e = mid-1;
        }
        else if(nums[mid]<nums[mid+1] && (mid+1)<=size-1)
        {
            s = mid+1;
        }
    }
    return ans;
}
int bs_minimum_diff(int nums[], int size, int key)
{
    int s=0,e=size-1,f=-1,c=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            return 0;
        }
        else if(nums[mid]<key)
        {
            f = nums[mid];
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            c = nums[mid];
            e = mid-1;
        }
    }
    int ans = min(abs(key-f),abs(key-c));
    return ans;
}
int bs_index_of_1(int nums[], int size)
{
    int s=0,e=1,ans=-1;
    while(nums[e]<1)
    {
        s = e;
        e = e*2;
    }
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==1)
        {
            ans = mid;
            e = mid-1;
        }
        else if(nums[mid]==0)
        {
            s = mid+1;
        }
    }
    return ans;
}
int bs_infinite_array(int nums[], int key)
{
    int s=0,e=1,ans=-1;
    while(key>nums[e])
    {
        s = e;
        e = e*2;
    }
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            ans = mid;
            return ans;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return ans;
}
char bs_next_alphabet(char nums[], int size, char key)
{
    int s=0,e=size-1;
    char ans = nums[e];
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            ans = nums[mid];
            return ans;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            ans = nums[mid];
            e = mid-1;
        }
    }
    return ans;
}
int bs_ceil(int nums[], int size, int key)
{
    // 1 2 3 4 8 10 10 12 19
    int s=0,e=size-1,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            ans = key;
            return ans;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            ans = nums[mid];
            e = mid-1;
        }
    }
    return ans;
}
int bs_floor(int nums[], int size, int key)
{
    // 1 2 3 4 8 10 10 12 19
    int s=0,e=size-1,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            ans = key;
            return ans;
        }
        else if(nums[mid]<key)
        {
            ans = nums[mid];
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return ans;
}
int bs_nearly_sorted(int nums[], int size, int key)
{
    int s=0,e=size-1,ans=-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            ans = mid;
            return ans;
        }
        else if(nums[mid-1]==key)
        {
            ans = mid-1;
            return ans;
        }
        else if(nums[mid+1]==key)
        {
            ans = mid+1;
            return ans;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return ans;
}
int bs_times_rotated(int nums[], int size)
{
    int ans=0,s=0,e=size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        int prev = nums[(mid-1+size)%size];
        int next = nums[(mid+1)%size];

        if(nums[mid]<prev && nums[mid]<next)
        {
            // ans = size-mid;
            ans = nums[mid];
            return ans;
        }
        else if(nums[mid]>=nums[0])
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
    return ans;
}
pair<int,int> bs_fo_and_lo(int nums[],int size,int key)
{
    int f=-1,l=-1,s=0,e=size-1;
    pair<int,int> p;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            p.first = mid;
            e = mid-1;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    s=0,e=size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            p.second = mid;
            s = mid+1;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return p;
}
int bs(int nums[], int size, int key)
{
    int s=0,e=size-1;
    while(s<=e)
    {
        int mid = (s+e)/2;
        if(nums[mid]==key)
        {
            return mid;
        }
        else if(nums[mid]<key)
        {
            s = mid+1;
        }
        else if(nums[mid]>key)
        {
            e = mid-1;
        }
    }
    return -1;
}
int bs_count_of_target(int nums[], int size, int key)
{
    int s=0,e=size-1,c=0;
    pair<int,int> p = bs_fo_and_lo(nums,size,key);
    while(p.first<=p.second)
    {
        c++;
        p.first++;
    }
    return c;
}
int main()
{
    // int nums[] = {2,4,7,8,9,9,9,9,9,11,12,15,19,20};
    int nums[] = {1,4,9,16,25,36,49,64,10,5};
    // int nums[] = {20,17,15,14,13,12,10,9,8,4};
    int size = sizeof(nums)/sizeof(nums[0]);
    int key;
    cin>>key;

    // cout<<bs(nums,size,key);

    // pair<int,int> p = bs_fo_and_lo(nums,size,key);
    // cout<<p.first<<" "<<p.second<<endl;

    // cout<<bs_count_of_target(nums,size,key);

    // cout<<bs_times_rotated(nums,size);

    // cout<<bs_nearly_sorted(nums,size,key);

    // cout<<bs_floor(nums,size,key);

    // cout<<bs_ceil(nums,size,key);

    // char alpha[] = {'a','c','f','h'};
    // int n = sizeof(alpha)/sizeof(alpha[0]);
    // char key;
    // cin>>key;
    // cout<<bs_next_alphabet(alpha,n,key);

    // cout<<bs_infinite_array(nums,key);

    // cout<<bs_index_of_1(nums,size);

    // cout<<bs_minimum_diff(nums,size,key);

    // cout<<bs_peak_element(nums,size);

    // cout<<bs_maxel_bitonic(nums,size);

    cout<<bs_el_bitonic(nums,size,key);

    return 0;
}