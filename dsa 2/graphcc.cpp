//graphs and trees
//find the connected components in undirected graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex] = 1;

    for(auto it = graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }
    }
}
int main()
{
    memset(vis,0,sizeof(vis));
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]);
        else
        {
            ans++;
            dfs(i);
        }
    }
    cout<<"Connected Components = "<<ans;
    return 0;
}