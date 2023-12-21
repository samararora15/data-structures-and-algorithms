//2-pointer concept
#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(int nums[], int size)
{
    int i=0,j=i+1;
    while(j<size)
    {
        if(nums[j]==nums[i])
        {
            j++;
        }
        else
        {
            i++;
            nums[i] = nums[j];
            j++;
        }
    }
    return i+1;
}

int rainwater_trapping(int nums[], int size)
{
    int ans=0;
    int temp = -1;
    int left[size];
    left[0] = nums[0];
    int right[size];
    right[size-1] = nums[size-1];
    for(int i=1;i<size;i++)
    {
        left[i] = max(left[i-1],nums[i]);
    }
    for(int i=size-2;i>=0;i--)
    {
        right[i] = max(right[i+1],nums[i]);
    }
    for(int i=0;i<size;i++)
    {
        ans+= min(left[i],right[i]) - nums[i];
    }
    return ans;
}
vector<vector<int>> three_sum(int nums[], int size)
{
    sort(nums, nums+size);
    vector<vector<int>> ans;
    for(int i=0;i<size;i++)
    {
        if(i>0 && nums[i]==nums[i-1])   continue;
        int j = i+1;
        int k = size-1;
        while(j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0)
            {
                i++;
            }
            else if(sum>0)
            {
                k--;
            }
            else if(sum==0)
            {
                ans.push_back({nums[i],nums[j],nums[k]});
                j++;
                k--;
                while(nums[j]==nums[j-1])   j++;
                while(nums[k]==nums[k+1])   k++;
            }
        }
    }
    return ans;
}
int main()
{
    int nums[] = {1,1,2,2,2,3,3,4,4,4,4,5};
    int size = sizeof(nums)/sizeof(nums[0]);
    // vector<vector<int>> ans = three_sum(nums,size);
    // for(int i=0;i<ans.size();i++)
    // {
    //     for(int j=0;j<ans[i].size();j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // cout<<three_sum(nums,size);

    // cout<<rainwater_trapping(nums,size);

    cout<<remove_duplicates(nums,size); //for sorted array

    return 0;
}