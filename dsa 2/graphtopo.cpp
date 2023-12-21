//implementation of topological sort
#include<bits/stdc++.h>
using namespace std;
const int n = 1e5+10;
int vis[n];
vector<int> graph[n];
stack<int> s;
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
    s.push(vertex);
}
int main()
{
    //multiple topological sort for a single graph is possible
    //only applicable to directed acyclic graph(DAG)
    //hence solution is not unique
    int n,m;
    cout<<"Enter the Vertices and Edges respectively:";
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]);
        else
        {
            dfs(i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}