//sliding window technique
#include<bits/stdc++.h>
using namespace std;
queue<int> negs;

vector<int> maximum_of_all_subarrays_of_size_k(vector<int> &nums, int k)
{
    int l=0,r=0,n=nums.size(),ans=INT8_MIN;
    // int temp;
    vector<int> ansvec;
    // 1,3,-1,-3,5,3,6,7

    while(r<n)
    {   
        ans = max(ans,nums[r]);
        if(r-l+1 < k)
        {
            r++;
        }
        
        else if(r-l+1 == k)
        {
            ansvec.push_back(ans);
            if(ans == nums[l])
            {
                ans = INT8_MIN;
            }
            l++;    r++;
        }
    }

    return ansvec;
}

vector<int> first_negative_in_every_window_of_size_k(vector<int>&nums, int k)
{
    // 12 -1 -7 8 -15 30 16 28
    // -1 -1 -7 -15 -15 0
    //fixed size window
    vector<int> ans;
    int r=0,l=0,n=nums.size();
    // for(int i=0;i<n;i++)
    // {
    //     if(nums[i]<0)
    //     {
    //         negs.push(nums[i]);
    //     }
    // }

    while(r<n)
    {
        if(nums[r]<0)
        {
            negs.push(nums[r]);
        }
        if(r-l+1<k)
        {
            r++;
        }
        else if(r-l+1==k)
        {
            ans.push_back(negs.front());
            if(negs.front()==nums[l])
            {
                negs.pop();
            }
            l++;    r++;
        }
    }
    return ans;
}

int maximum_subarraysum_of_size_k(vector<int>&nums, int k)
{
    // 2 5 1 8 2 9 1
    //fixed size window
    int r=0,l=0,sum=0,ans=0,n=nums.size();
    while(r<n)
    {
        sum += nums[r];
        if(r-l+1<k)
        {
            r++;
        }
        else if(r-l+1 == k)
        {
            ans = max(ans,sum);
            sum -= nums[l];
            l++;    r++;
        }
    }
    return ans;
}

char repeatedCharacter(string s) {
        int cnt[26];
        // memset(cnt,0,sizeof(cnt));
        char ans;
        for(int i=0;s[i]!='\0';i++)
        {
            cnt[s[i]-97]++;
            if(cnt[s[i]-97]==2)
            {
                ans = s[i];
                break;
            }
        }
        return ans;
    }

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    //variable sized window
        long r=0,l=0,n=nums.size(),ans=0;
        long prod = 1;
        for(r;r<n;r++)
        {
            prod *= nums[r];
            for(l;prod>=k;l++)
            {
                prod /= nums[l];
            }
            ans += (r-l+1);
        }
        return ans;
    }

int lengthOfLongestSubstring(string s) {
    //variable sized window
        int l=0,r=0,n=s.size(),ans=1;
        unordered_map<char,int> mp;
        for(r;r<n;r++)
        {   
            mp[s[r]]++;
            for(l;mp[s[r]]>1;l++)
            {
                mp[s[l]]--;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }

int longest_subarrayof1s_after_deleting_1_element( vector<int> nums)
{
    //variable window template pattern
    int l=0,r=0,ans=0,count_0=0,n=nums.size();
    for(r;r<n;r++)
    {
        if(nums[r]==0)  count_0++;
        for(l;count_0>1;l++)
        {
            if(nums[l]==0)  
            {
                count_0--;
            }
        }
        ans = max(ans,r-l+1);
    }

    return ans-1;
}

int main()
{
    //brute force - print sum of all subarrays of size k(say k = 3)

    // int arr[] = {2,3,1,0,5,6,4,9,8};
    // int size = sizeof(arr)/sizeof(arr[0]);

    // int k = 3;

    // int n=0,m=k-1;

    // int sum = 0;
    // while(m<size)
    // {
    //     for(int i=n;i<=m;i++)
    //     {
    //         sum = sum+arr[i];
    //     }
    //     cout<<sum<<" ";
    //     sum = 0;
    //     n++;
    //     m++;
    // }   

    //time complexity for above solution is approx O(nk)

    //sliding window optimizes it to **O(n)** from O(nk)

    // vector<int> nums = {1,0,1,1,1,0,1,1};
    // cout<<longest_subarrayof1s_after_deleting_1_element(nums);

    // string s = "pwswkew";
    // cout<<lengthOfLongestSubstring(s);

    // vector<int> nums = {10,5,2,6};
    // int k = 100;
    // cout<<numSubarrayProductLessThanK(nums,k);

    // string s = "abccdba";
    // cout<<repeatedCharacter(s);

    // vector<int> nums = {2,5,1,8,2,9,1};
    // int k = 3;
    // cout<<maximum_subarraysum_of_size_k(nums,k);

    // vector<int> nums = {12,-1,-7,8,-15,30,16,28};
    // int k = 3;
    // vector<int> ans = first_negative_in_every_window_of_size_k(nums,k);
    // for(int i=0;i<ans.size();i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maximum_of_all_subarrays_of_size_k(nums,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}