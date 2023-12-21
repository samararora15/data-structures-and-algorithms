//hashing
//count maximum and minimum frequencied number
#include<bits/stdc++.h>
using namespace std;
void hashing(int arr[],int size)
{
    unordered_map<int,int> cmap;

    for(int i=0;i<size;i++)
    {
        cmap[arr[i]]++;
    }

    int maxfreq = -1;
    int minfreq = INT8_MAX;

    for(auto it:cmap)
    {
        if(it.second>maxfreq)
        {
            maxfreq = it.second;
        }
        if(it.second<minfreq)
        {
            minfreq = it.second;
        }
    }

    cout<<maxfreq<<" "<<minfreq;
}
int main()
{
    int arr[] = {2,4,1,3,1,2,2,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    hashing(arr,size);
    return 0;
}