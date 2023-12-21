//arrays
#include<bits/stdc++.h>
using namespace std;
int vis[INT8_MAX];

vector<vector<int>> sum_3(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])   continue;
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])   j++;
                    while(j<k && nums[k]==nums[k+1])   k--;
                }
            }
        }
        return ans;
    }

int moorevotingalgo(int arr[],int size)
{
    int ct = 0;
    int el = arr[0];

    for(int i=0;i<size;i++)
    {
        if(ct==0)
        {
            el = arr[i];
            ct++;
        }
        else if(arr[i]==el)
        {
            ct++;
        }
        else if(arr[i]!=el)
        {
            ct--;
        }
    }
    return el;
}

int fact(int num)
{
    if(num==0)
    {
        return 1;
    }
    else
    {
        int prod = 1;
        for(int i=num;i>=1;i--)
        {
            prod *= i;
        }
        return prod;
    }
}

void pascaltriangle(int n)
{
    int sp = 1;
    for(int i=0;i<n;i++)
    {
        for(int k=sp;k<=(n-1);k++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            int a = fact(i);
            int b = fact(j);
            int c = fact(i-j);
            int d = b*c;
            int ans = a/d;
            cout<<ans<<" ";
        }
        sp++;
        cout<<endl;
    }
}

void longestconsecutiveseq(int arr[],int size)
{
    sort(arr, arr+size);
    int maxseq = 1;
    int curseq = 1;
    int lastsmaller = arr[0];

    for(int i=1;i<size;i++)
    {
        if(arr[i]==lastsmaller+1)
        {
            curseq++;
            lastsmaller = arr[i];
            maxseq = max(maxseq,curseq);
        }
        else if(arr[i]!=lastsmaller)
        {
            lastsmaller = arr[i];
            curseq = 1;
        }
        // maxseq = max(maxseq,curseq);
    }
    cout<<maxseq;
}

void leadersinanarray(int arr[],int size)
{
    int e = size-1;
    int maxel = INT8_MIN;
    vector<int> ans;

    while(e>=0)
    {
        if(arr[e]>maxel)
        {
            ans.push_back(arr[e]);
            maxel = arr[e];
        }
        e--;
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}

void rearrangearrayelementsbysign(int arr[], int n) //order should also be maintained
{
    int pos[] ={3,1,2};
    int neg[] = {-2,-5,-4};

    int k = 0;
    for(int i=0;i<n;i=i+2)
    {
        arr[i] = pos[k];
        arr[i+1] = neg[k];
        k++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void testing(int a, int b)
{
    if(a==0)
    {
        cout<<b;
    }
    else if(b==0)
    {
        cout<<a;
    }
    else if(a>0 && b>0)
    {
        int maxi = a>b ? a : b;
        int mini = a<b ? a : b;

        testing(maxi%mini, mini);
    }
}

void numberthatappearsonce(int arr[], int size)
{
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++)
    {
        mp[arr[i]]++;
    }

    for(auto it:mp)
    {
        if(it.second==1)
        {
            cout<<it.first;
            break;
        }
    }
}

void maxconsecutiveones(int arr[],int size)
{
    int ans = 0, cnt = 0;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==1)
        {
            cnt++;
        }
        else
        {
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    cout<<ans;
}

void missingnumber(int arr[], int size)
{
    int hasharray[size+1];
    memset(hasharray,0,sizeof(hasharray));
    int temp;

    for(int i=0;i<size;i++)
    {
        hasharray[arr[i]] = 1;
    }

    for(int i=0;i<size+1;i++)
    {
        if(hasharray[i]==0)
        {
            temp = i;
        }
    }

    cout<<temp;
}

void intersectionof2sortedarrays()
{
    int arr1[] = {1,1,1,1,2,3,4,5,5,5,6,6,7,9};
    int arr2[] = {1,1,4,4,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    int i=0,j=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]>arr2[j])
        {
            j++;
        }
        else if(arr2[j]>arr1[i])
        {
            i++;
        }
        else if(arr1[i]==arr2[j] && vis[arr1[i]]==0)
        {
            cout<<arr2[j]<<" ";
            vis[arr1[i]] = 1;
            i++;
            j++;
        }
        else if(vis[arr1[i]]==1)
        {
            i++;
            j++;
        }
    }
}

void unionof2sortedarrays()
{
    int arr1[] = {1,1,1,1,2,3,5,5,5,7,7,9};
    int arr2[] = {1,1,4,4,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    set<int> st;

    int i=0,j=0;
    while(i<size1 && j<size2)
    {
        st.insert(arr1[i]);
        st.insert(arr2[j]);
        i++;
        j++;
    }
    while(i<size1)
    {
        st.insert(arr1[i]);
        i++;
    }
    while(j<size2)
    {
        st.insert(arr2[j]);
        j++;
    }

    for(auto it : st)
    {
        cout<<it<<" ";
    }
}

void movezeroestoend(int arr[], int size)
{
    vector<int> v;

    for(int i=0;i<size;i++)
    {
        if(arr[i]!=0)
        {
            v.push_back(arr[i]);
        }
    }
    for(int i=0;i<v.size();i++)
    {
        arr[i] = v[i];
    }
    for(int i=v.size();i<size;i++)
    {
        arr[i] = 0;
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void leftrotatearraybyd(int arr[], int size, int d)
{
    d = d%size;
    
    while(d>0)
    {
        int temp = arr[0];
        int j=0;

        for(int i=1;i<size;i++)
        {
            arr[j] = arr[i];
            j++;    
        }
        arr[size-1] = temp;
        j=0;
        d--;
    }

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void leftrotatearray(int arr[], int size)
{
    int temp = arr[0];
    int j=0;

    for(int i=1;i<size;i++)
    {
        arr[j] = arr[i];
        j++;    
    }
    arr[size-1] = temp;

    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void removeduplicates2(int arr[], int size)
{
    set<int> st;

    for(int i=0;i<size;i++)
    {
        st.insert(arr[i]);
    }

    int i=0;
    for(auto it:st)
    {
        arr[i] = it;
        i++;
    }

    for(int j=0;j<size;j++)
    {
        cout<<arr[j]<<" ";
    }
}

void removeduplicates1(int arr[], int size)
{
    int i=1;

    for(int j=1;j<size-1;j++)
    {
        if(arr[j+1]>arr[j])
        {
            arr[i] = arr[j+1];
            i++;
        }
    }

    for(int j=0;j<size;j++)
    {
        cout<<arr[j]<<" ";
    }
}

bool isarraysorted(int arr[], int size)
{
    bool ans = true;

    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            ans = false;
            break;
        }
    }

    return ans;
}

int secondlargestel2(int arr[], int size)
{
    int lar = arr[0], slar = -1;

    for(int i=1;i<size;i++)
    {
        if(arr[i]>lar)
        {
            slar = lar;
            lar = arr[i];
        }
        else if(arr[i]>slar && slar!=lar)
        {
            slar = arr[i];
        }
    }
    return slar;
}

int secondlargestel1(int arr[], int size)
{
    int lar = -1, slar = -1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>lar)
        {
            lar = arr[i];
        }
    }

    for(int i=0;i<size;i++)
    {
        if(arr[i]>slar && arr[i]!=lar)
        {
            slar = arr[i];
        }
    }

    return slar;
}

int largestel(int arr[], int size)
{
    int temp = INT8_MIN;

    for(int i=0;i<size;i++)
    {
        if(arr[i]>temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    // int size = sizeof(arr)/sizeof(arr[0]);
    //cout<<largestel(arr,size);
    //cout<<secondlargestel1(arr,size);
    //cout<<secondlargestel2(arr,size);
    //cout<<isarraysorted(arr,size);
    //removeduplicates1(arr,size);
    //removeduplicates2(arr,size);
    //leftrotatearray(arr,size);
    //leftrotatearraybyd(arr,size,3);
    //movezeroestoend(arr,size);
    //unionof2sortedarrays();
    //testing(39,117);
    //intersectionof2sortedarrays();
    //missingnumber(arr,size);
    //maxconsecutiveones(arr,size);
    // numberthatappearsonce(arr,size);
    // rearrangearrayelementsbysign(arr,size);
    // leadersinanarray(arr,size);
    // longestconsecutiveseq(arr,size);
    // pascaltriangle(6);
    // cout<<moorevotingalgo(arr,size);
    vector<vector<int>> ans = sum_3(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}