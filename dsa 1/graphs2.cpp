#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
vector<int> graph[N];
bool vis[N];
vector<pair<pair<int,int>,int>> eg;
queue<int> q;
void getislands(int r, int c, vector<vector<int>> &g)
{
    if(r<0 || c<0 || r==g.size() || c==g.size())  return;
    if(g[r][c]==0)  return;
    g[r][c] = 0;
    getislands(r-1,c,g);   //top
    getislands(r,c-1,g);   //left
    getislands(r,c+1,g);   //right
    getislands(r+1,c,g);   //bottom
}
int findCircleNum(vector<vector<int>>& graph)
{
    int ans=0;
    for(int i=0;i<graph.size();i++) {
        for(int j=0;j<graph.size();j++) {
            if(graph[i][j]==1) {
                ans++;
                getislands(i,j,graph);
            }
        }
    }
    return ans;
}
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
void createedgelist(int e)
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
void createlist(int vertices, int edges)
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
    // for(int i=0;i<=v;i++)
    // {
    //     for(auto it:graph[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
}
void creatematrix(int vertices,int edges)
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
    // creatematrix(v,e);
    // createlist(v,e);
    // createedgelist(e);
    // addedge(1,2);
    // addedge(1,3);
    // addedge(2,4);
    // addedge(3,5);
    // addedge(4,8);
    // addedge(5,6);
    // addedge(5,7);
    // addedge(8,9);
    // dfs(1);
    // bfs(1);

    // int cc=0;
    // for(int i=1;i<=v;i++)
    // {
    //     if(!vis[i])
    //     {
    //         cc++;
    //         dfs(i);
    //     }
    // }
    // cout<<cc;

    vector<vector<int>> graph = {{1,0,0},{0,1,0},{0,0,1}};
    cout<<findCircleNum(graph);
    return 0;
}