//recursion
//staircase problem (source - love babbar)
#include<bits/stdc++.h>
using namespace std;
int recurse(int n)
{
    if(n<0)
    {
        return 0;
    }
    else if(n==0)
    {
        return 1;
    }
    else if(n==1)
    {
        return 1;
    }
    else
    {
        return recurse(n-1)+recurse(n-2)+recurse(n-3);
    }
}
int main()
{
    int n;  //n denotes number of stairs
    cin>>n;
    cout<<recurse(n);
    return 0;
}