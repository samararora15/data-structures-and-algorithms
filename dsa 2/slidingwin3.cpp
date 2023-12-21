//sliding window problem
//identification - array/string + subarray/substring + window size(k)
//types - fixed size window and variable size window
//maximum of all subarrays
#include<bits/stdc++.h>
using namespace std;
void slwin(int arr[],int size,int k)
{
    int i=0,j=0,tempmax = INT8_MIN;
    while(j<size)
    {
        tempmax = max(tempmax,arr[j]);

        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            cout<<tempmax<<" ";

            if(tempmax==arr[i])
            {
                tempmax = INT8_MIN;
            }

            for(int p = i+1;p<i+k;p++)
            {
                tempmax = max(tempmax,arr[p]);
            }
            i++;
            j++;
        }
    }
}
int main()
{
    int arr[] = {6,2,4,1,7,9,5,8,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    slwin(arr,size,k);
    return 0;
}