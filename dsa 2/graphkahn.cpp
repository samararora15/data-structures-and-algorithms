//topological sort using bfs(kahn's algorithm)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
queue<int> q;
void topo(int n,int indegree[])
{
    for(int i=1;i<=n;i++)
    {
        for(auto it = graph[i].begin();it!=graph[i].end();it++)
        {
            indegree[*it]++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int top = q.front();
        cout<<top<<" ";
        q.pop();
        for(auto it=graph[top].begin();it!=graph[top].end();it++)
        {
            indegree[*it]--;
            if(indegree[*it]==0)
            {
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
    }

    int indegree[n+1];
    memset(indegree,0,sizeof(indegree));

    topo(n,indegree);

    return 0;
}