//cycle detection in directed graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int vis[N];
int dfsvis[N];
bool iscycle;
bool dfs(int vertex)
{
    vis[vertex] = 1;
    dfsvis[vertex] = 1;
    for(auto it = graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        if(!vis[*it])
        {
            iscycle |= dfs(*it);
        }
        else if(vis[*it]==1 && dfsvis[*it]==1)
        {
            return true;
        }
    }
    dfsvis[vertex] = 0;
    return iscycle;
}
int main()
{
    int n,m;
    cout<<"Enter vertices and edges respectively:";
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);    
    }

    //we call dfs for every component
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i));
            {
                cout<<"Cycle Detected";
                break;
            }
        }
    }
    return 0;
}