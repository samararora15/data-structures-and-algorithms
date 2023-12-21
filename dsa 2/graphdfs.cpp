//trees and graphs
//dfs(depth first search) is a traversal algorithm in graph/tree
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> graph[N];
void dfs(int vertex)
{
    //preorder
    vis[vertex] = 1;
    cout<<vertex<<" ";

    //inorder
    vector<int> :: iterator it;
    for(it = graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        if(vis[*it]);
        else
        {
            dfs(*it);
        }
    }

    //postorder
    //cout<<vertex<<" ";
}
int main()
{
    int n,m;
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
            dfs(i);
        }
    }
    return 0;
}