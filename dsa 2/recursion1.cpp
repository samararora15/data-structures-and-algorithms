//recursion
//power of a number
#include<bits/stdc++.h>
using namespace std;
int recurse(int a,int p)
{
    if(p==0)
    {
        return 1;
    }
    else
    {
        return a*recurse(a,p-1);
    }
}
int main()
{
    int a,p;
    cin>>a>>p;
    cout<<recurse(a,p);
    return 0;
}