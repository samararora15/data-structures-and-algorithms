//bipartite graph/graph coloring - a graph that can be colored using exactly 2 colors such that no two adjacent nodes have same color
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
bool isbipar = true;
bool dfs(int vertex,int color[])
{
    for(auto it = graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        if(color[*it]==-1)
        {
            if(color[vertex]==1)
            {
                color[*it] = 0;
                dfs(*it,color);
            }
            else if(color[vertex]==0)
            {
                color[*it] = 1;
                dfs(*it,color);
            }
        }
        else if(color[*it]==0 && color[vertex]==0)
        {
            isbipar &= false;
            break;
        }
        else if(color[*it]==1 && color[vertex]==1)
        {
            isbipar &= false;
            break;
        }
    }
    return isbipar;
}
int main()
{
    int n,m;
    cout<<"Enter vertices and edges of graph:";
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int color[n];
    memset(color,-1,sizeof(color));
    color[1] = 1;
    if(dfs(1,color))
    {
        cout<<"Bipartite";
    }
    else
    {
        cout<<"Non-Bipartite";
    }
    return 0;
}