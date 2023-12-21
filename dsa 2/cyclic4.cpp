//cyclic sort implementation
//find all numbers repeated in array
#include<bits/stdc++.h>
using namespace std;
vector<int> disapp(int arr[],int size,vector<int> &v)
{
    int i=0;
    while(i<size)
    {
        int cidx = arr[i]-1;
        if(arr[i]!=arr[cidx])
        {
            int temp = arr[cidx];
            arr[cidx] = arr[i];
            arr[i] = temp;
        }
        else
        {
            i++;
        }
    }
    for(int j=0;j<size;j++)
    {
        if(j==arr[j]-1)
        {
            continue;
        }
        else
        {
            v.push_back(arr[j]);
        }
    }
    return v;
}
int main()
{
    int arr[] = {4,3,2,7,8,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    disapp(arr,size,v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}