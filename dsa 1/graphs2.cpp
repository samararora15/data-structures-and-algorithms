#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<int> graph[N];
bool vis[N];
vector<pair<pair<int,int>,int>> eg;
queue<int> q;
void bfs(int node)
{
    q.push(node);
    vis[node] = 1;
    
    while(!q.empty())
    {
        int top = q.front();
        cout<<top<<" ";
        q.pop();
        for(auto it:graph[top])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}
void dfs(int node)
{
    vis[node] = 1;
    cout<<node<<" ";
    
    for(auto it:graph[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
    // cout<<node<<" ";
}
void addedge(int v1, int v2)
{
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}
void displayedgelist(int e)
{
    for(int i=0;i<e;i++)
    {
        int v1,v2,ew;
        cin>>v1>>v2>>ew;
        eg.push_back({{v1,v2},ew});
    }
    cout<<endl<<endl;
    for(int i=0;i<e;i++)
    {
        cout<<eg[i].first.first<<" "<<eg[i].first.second<<" "<<eg[i].second<<endl;
    }
}
void displaylist(int vertices, int edges)
{
    int v = vertices;
    int e = edges;
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=0;i<=v;i++)
    {
        for(auto it:graph[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
void displaymatrix(int vertices,int edges)
{
    int v = vertices;
    int e = edges;
    int adjmat[v+1][v+1];
    memset(adjmat,0,sizeof(adjmat));
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        adjmat[v1][v2] = 1;
        adjmat[v2][v1] = 1;
    }
    for(int i=0;i<v+1;i++)
    {
        for(int j=0;j<v+1;j++)
        {
            cout<<adjmat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int v,e;
    // cin>>v>>e;
    // displaymatrix(v,e);
    // displaylist(v,e);
    // displayedgelist(e);
    addedge(1,2);
    addedge(1,3);
    addedge(2,4);
    addedge(3,5);
    addedge(4,8);
    addedge(5,6);
    addedge(5,7);
    // dfs(1);
    bfs(1);
    return 0;
}