//shortest path in a directed acyclic graph
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<pair<int,int>> graph[N];
stack<int> st;
void shortest_path(int dis[],int src)
{
    dis[src] = 0;
    while(!st.empty())
    {
        int top = st.top();
        st.pop();
        int pathlen = dis[top];
        for(auto it = graph[top].begin();it!=graph[top].end();it++)
        {
            int v = it->first;
            int wt = it->second;

            if(dis[v]>wt+pathlen)
            {
                dis[v] = wt+pathlen;
            }
        }
    }
}
void topo(int vertex)
{
    vis[vertex] = true;

    for(auto it = graph[vertex].begin();it!=graph[vertex].end();it++)
    {
        int v = it->first;
        if(!vis[v])
        {
            topo(v);
        }
    }
    st.push(vertex);
}
int main()
{
    int n,m;
    cout<<"enter number of vertices and edges:";
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int v1,v2,w;
        cin>>v1>>v2>>w;
        graph[v1].push_back(make_pair(v2,w));
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            topo(i);
        }
    }

    int dis[n+1];
    memset(dis,INT8_MAX,sizeof(dis));

    shortest_path(dis,1);       //1 is assumed to be source node(you can choose any node of your choice in the graph)

    for(int i=0;i<n+1;i++)
    {
        cout<<dis[i]<<" ";
    }
    
    return 0;
}