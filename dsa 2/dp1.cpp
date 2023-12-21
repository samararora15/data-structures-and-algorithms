//dynamic programming (memoized version)
//0/1 knapsack
#include<bits/stdc++.h>
using namespace std;
int static t[102][1002];
int maxprofit = 0;
int knapsack(int items[],int val[],int cap,int n)
{
    if(n==0 || cap==0)
    {
        return 0;
    }

    if(t[n][cap]!=-1)
    {
        return t[n][cap];
    }

    else if(items[n-1]<=cap)
    {
        return t[n][cap] =  max(maxprofit + val[n-1] + knapsack(items,val,cap-items[n-1],n-1),knapsack(items,val,cap,n-1));
    }
    else if(items[n-1]>cap)
    {
        return t[n][cap] =  knapsack(items,val,cap,n-1);
    }
    return maxprofit;
}
int main()
{
    memset(t,-1,sizeof(t));
    int n;
    cout<<"enter number of items:";
    cin>>n;
    int items[n] = {1,2,3,4};
    int val[n] = {1,3,4,6};
    int cap = 7;
    cout<<"maximum profit is = "<<knapsack(items,val,cap,n);
    return 0;
}