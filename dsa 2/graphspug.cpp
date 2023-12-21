//shortest distance in undirected graph with unit weights(using plain bfs)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> graph[N];
queue<int> q;
void spug(int src,int dis[])
{
    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        int pathlen = dis[node];

        for(auto it=graph[node].begin();it!=graph[node].end();it++)
        {
            if(dis[*it]>pathlen+1)
            {
                dis[*it] = pathlen+1;
                q.push(*it);
            }
        }
    }
}
int main()
{
    int n,m;
    cout<<"enter vertices and edges:";
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int dis[n+1];
    memset(dis,INT8_MAX,sizeof(dis));

    spug(1,dis);

    for(int i=0;i<n+1;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;
}