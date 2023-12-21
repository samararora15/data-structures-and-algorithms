//basic recursion for DSA
#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int checkifpalindromestring(char str[], int s, int e)
{
    if(s==e)
    {
        return 1;
    }
    else if(str[s]!=str[e])
    {
        return 0;
    }
    else if(s<e+1)
    {
        s++;
        e--;
        return checkifpalindromestring(str,s,e);
    }
    return true;
}

void reverseanarray(int arr[],int s,int e)  //multiple parameters
{
    if(s>=e)
    {
        return;
    }
    else if(s<e)
    {
        int k = arr[s];
        arr[s] = arr[e];
        arr[e] = k;
        reverseanarray(arr,s+1,e-1);
    }
}

int sumoffirstnnumbers2(int n)  //functional recursion
{
    if(n==0)
    {
        return 0;
    }
    else
    {
       return n = n + sumoffirstnnumbers2(n-1);
    }
}

void sumoffirstnnumbers1(int n,int sum) //parametrized recursion
{
    if(n==0)
    {
        cout<<sum<<" ";
        return;
    }
    else
    {
        sum = sum + n;
        n--;
        sumoffirstnnumbers1(n,sum);
    }
}

void printlinearlyfrom1ton(int n)
{
    if(n==0)    //base condition or stopping condition(necessary in recursion)
    {
        return;
    }
    else
    {
        n--;
        printlinearlyfrom1ton(n);
        cout<<n+1<<" ";
    }
}

void printname5times(int n)
{
    if(n==0)    //base condition or stopping condition(necessary in recursion)
    {
        return;
    }
    else
    {
        cout<<"JIGSAW"<<endl;
        n--;
        printname5times(n);
    }
}
int main()
{
    //printname5times(5);
    //printlinearlyfrom1ton(5);
    //sumoffirstnnumbers1(7,0);
    //cout<<sumoffirstnnumbers2(7);
    //int arr[] = {1,2,3,4,5,6,7};
    //int size = sizeof(arr)/sizeof(arr[0]);
    //reverseanarray(arr,0,size-1); 
    /*for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }*/
    //char str[] = "rexaaxer";
    //cout<<checkifpalindromestring(str,0,strlen(str)-1);
    cout<<fibonacci(8);
    return 0;
}