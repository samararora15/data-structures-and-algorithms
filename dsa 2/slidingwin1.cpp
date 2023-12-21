//sliding window problem
//identification - array/string + subarray/substring + window size(k)
//types - fixed size window and variable size window
//program to find maximum sum of subarray of size k
#include<bits/stdc++.h>
using namespace std;
int slwin(int arr[],int size,int k)
{
    int i=0,j=0,sum=0;
    int maxsum = INT8_MIN;

    while(j<n)
    {
        sum = sum + arr[j];

        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            maxsum = max(maxsum,sum);
            sum = sum - arr[i];
            i++;
            j++;
        }
    }

    return maxsum;
}
int main()
{
    int arr[] = {2,5,1,8,2,9,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"enter the value of k:";
    cin>>k;
    cout<<"maximum sub array sum is:";
    cout<<slwin(arr,n,k);
    return 0;
}