//hashing
//count maximum and minimum frequencied character(Character Hashing)
#include<bits/stdc++.h>
using namespace std;
void hashing(string str,int size)
{
    unordered_map<char,int> cmap;

    for(int i=0;i<size;i++)
    {
        cmap[str[i]]++;
    }

    for(auto it = cmap.begin();it!=cmap.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }

    cout<<cmap['g']<<" ";
}
int main()
{
    string str;
    cout<<"enter a string:";
    cin>>str;
    hashing(str,str.length());
    return 0;
}