//sliding window
//variable size
//largest subarray of sum k
#include<bits/stdc++.h>
using namespace std;
int slwin(int arr[],int size,int k)
{
    int i=0,j=0,ans = -1;
    long long sum = 0;
    while(j<size)
    {
        sum += arr[j];
        
        if(sum<k)
        {
            j++;
        }

        else if(sum==k)
        {
            ans = max(ans,j-i+1);
            j++;
        }

        else if(sum>k)
        {
            while(sum>k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    int arr[] = {4,1,1,1,2,3,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<slwin(arr,size,k);
    return 0;
}