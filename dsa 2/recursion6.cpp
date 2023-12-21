//recursion practice
//input a number and print it in words
#include<bits/stdc++.h>
using namespace std;
void recurse(int n,char num[][10])
{
    if(n==0)
    {
        return;
    }
    else
    {
        recurse(n/10,num);
        n = n%10;
        cout<<num[n]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    char num[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    recurse(n,num);
    return 0;
}