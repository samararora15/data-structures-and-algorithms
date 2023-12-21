//recursion
//print fibonacci series till n
#include<bits/stdc++.h>
using namespace std;
int recurse(int n)
{
    int temp = 0;
    if(n==0 || n==1)
    {
        return n;
    }
    else
    {
        return recurse(n-1)+recurse(n-2);
    }
}
int main()
{
    int n;
    cin>>n;
    int i=0;
    while(i<n)
    {
        cout<<recurse(i)<<" ";
        i++;
    }
    return 0;
}