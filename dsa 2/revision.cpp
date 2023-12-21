//sliding window
//variable size
//largest subarray of sum k
#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> cmap;

int slwin(string str,int size,int k)
{
    int i=0,j=0,ans = INT8_MIN,freqcnt=0;
    while(str[j]!='\0')
    {
        cmap[str[j]]++;

        if(cmap.size()<k)
        {
            j++;
        }

        else if(cmap.size()==k)
        {
            ans = max(ans,j-i+1);
            j++;
        }

        else if(cmap.size()>k)
        {
            while(cmap.size()>k)
            {
                cmap[i]--;
                if(cmap[i]==0)
                {
                    cmap.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    string str = "aabacbebebe";
    int size = str.size();
    int k;
    cin>>k;
    cout<<slwin(str,size,k);
    return 0;
}