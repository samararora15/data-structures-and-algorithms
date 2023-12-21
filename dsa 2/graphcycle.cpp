//cycle detection in an undirected graph
#include<bits/stdc++.h>
using namespace std;
const int n = 1e5+10;
vector<int> graph[n];
bool vis[n];
bool isloop = false;
bool dfs(int vertex,int parent)
{

    vis[vertex] = true;
    for(auto it=graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        if(vis[*it] && *it==parent)
        {
            continue;
        }
        if(vis[*it])
        {
            return true;
        }
        if(!vis[*it])
        isloop |= dfs(*it,vertex);
    }
    return isloop;
}
int main()
{
    int n,m;
    bool isloop = false;
    cout<<"enter the vertices and edges:";
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
        if(!vis[i])
        {
            if(dfs(i,-1))
            {
                isloop = true;
                break;
            }
        }
    }
    cout<<isloop<<endl;
    return 0;
}