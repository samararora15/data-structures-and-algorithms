//recursion
//input a number and print it in words
#include<bits/stdc++.h>
using namespace std;
int recurse1(int n,int ans)
{
    if(n==0)
    {
        return ans;
    }
    else
    {
        int k = n%10;
        ans = (ans*10) + k;
        return recurse1(n/10,ans);
    }
}
void recurse2(int p)
{
    if(p==0)
    {
        cout<<"ZERO ";
    }
    else if(p==1)
    {
        cout<<"ONE ";
    }
    else if(p==2)
    {
        cout<<"TWO ";
    }
    else if(p==3)
    {
        cout<<"THREE ";
    }
    else if(p==4)
    {
        cout<<"FOUR ";
    }
    else if(p==5)
    {
        cout<<"FIVE ";
    }
    else if(p==6)
    {
        cout<<"SIX ";
    }
    else if(p==7)
    {
        cout<<"SEVEN ";
    }
    else if(p==8)
    {
        cout<<"EIGHT ";
    }
    else if(p==9)
    {
        cout<<"NINE ";
    }
}
int main()
{
    int n,ans=0;
    cin>>n;
    int val = recurse1(n,ans);
    for(int i = val;i>0;i = i/10)
    {
        int p = i%10;
        recurse2(p);
    }
    return 0;
}