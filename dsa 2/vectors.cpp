//vectors - vectors are arrays with dynamic size
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v1;//initialisation
    v1.push_back(0);
    v1.push_back(1);
    cout<<v1.size()<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    vector<int> &v2 = v1;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    v2.push_back(3);
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }
    return 0;
}