//basic maths for DSA
#include<bits/stdc++.h>
using namespace std;

void euclidgcd(int n1,int n2)
{
    while(n1>0 && n2>0)
    {
        if(n1>n2)
        {
            n1 = n1%n2;
        }
        else
        {
            n2 = n2%n1;
        }
    }
    if(n1==0)
    {
        cout<<n2;
    }
    else
    {
        cout<<n1;
    }
}

void gcd(int n1, int n2)
{
    int small = (n1>n2) ? n2 : n1;
    int ans;
    for(int i=1;i<=small;i++)
    {
        if(n1%i==0 && n2%i==0)
        {
            ans = i;
        }
    }
    cout<<ans;
}

void ifprime(int num)
{
    int flag = 0;
    for(int i=2;i<sqrt(num);i++)
    {
        if(num%i==0)
        {
            flag = 1;
            break;
        }
    }
    
    if(flag==1)
    {
        cout<<"not prime";
    }
    else
    {
        cout<<"prime";
    }
}

void alldivisors(int num)
{
    vector<int> ls;
    for(int i=1;i<=sqrt(num);i++)
    {
        if(num%i==0)
        {
            ls.push_back(i);
            if((num/i)!=i)
            {
                ls.push_back(num/i);
            }
        }
    }
    sort(ls.begin(),ls.end());
    for(auto it : ls)
    {
        cout<<it<<" ";
    }
}

void ifarmstrong(int num)
{
    int newnum=0,count=0;
    for(int i = num;i>0;i=i/10)
    {
        int k = i%10;
        count++;
    }

    for(int i = num;i>0;i=i/10)
    {
        int k = i%10;
        newnum = newnum + pow(k,count);
    }

    if(newnum==num)
    {
        cout<<"Armstrong";
    }
    else
    {
        cout<<"Not Armstrong";
    }
}

void ifpalindrome(int num)
{
    int k,newnum=0;
    for(int i=num;i>0;i=i/10)
    {
        k = i%10;
        newnum = newnum*10 + k;
    }

    if(newnum==num)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not Palindrome";
    }
}

void revnum(int num)
{
    int k,newnum=0;
    for(int i=num;i>0;i=i/10)
    {
        k = i%10;
        newnum = newnum*10 + k;
    }
    cout<<newnum;
}

void cntdigits(int num)
{
    int count = 0;
    for(int i=num;i>0;i=i/10)
    {
        int k = i%10;
        count++;
    }
    cout<<count;
}

void digits(int num)
{
    stack<int> st;
    for(int i=num;i>0;i=i/10)
    {
        int k = i%10;
        st.push(k);
    }
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main()
{
    int num = 48;
    //int n1,n2;
    //cout<<"enter number:";
    //cin>>n1>>n2;
    //digits(num);
    //cntdigits(num);
    //revnum(num);
    //ifpalindrome(num);
    //ifarmstrong(num);
    alldivisors(num);
    //ifprime(num);
    //gcd(n1,n2);
    //euclidgcd(n1,n2);
    return 0;
}