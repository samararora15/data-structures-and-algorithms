//dynamic programming 
//subset-sum problem
#include<bits/stdc++.h>
using namespace std;
bool static t[102][1002];
bool subsetpos = false;
int i,j;
bool knapsack(int items[],int n,int sum)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<sum;j++)
        {
            if(j==0)
            {
                t[i][j] = true;
            }
            if(i==0 && j!=0)
            {
                t[i][j] = false;
            }
        }
    }

    if(items[n-1]<=sum)
    {
        return t[i][j] = t[i-1][j-items[i-1]] || t[i-1][j];
    }

    else
    {
        return t[i][j] = t[i-1][j];
    }
}
int main()
{
    memset(t,-1,sizeof(t));
    int items[] = {2,3,7,8,10};
    int n = sizeof(items)/sizeof(items[0]);
    int sum = 14;
    cout<<"subset possible = "<<knapsack(items,n,sum);
    return 0;
}