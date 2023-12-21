//sieve of eratosthenes
#include<bits/stdc++.h>
using namespace std;
void sieveofera(int n)
{
    bool arr[n];
    memset(arr,true,n);
    for(int i=2;i*i<n;i++)
    {
        if(arr[i]==true)
        {
            for(int j=i+i;j<n;j+=i)
            {
                arr[j] = false;
            }
        }
    }

    for(int k=2;k<n;k++)
    {
        if(arr[k]==true)
        {
            cout<<k<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    sieveofera(n+1);
    return 0;
}