//implement bfs algorithm for graph/trees
//queue data structure is used for bfs
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool vis[N];
vector<int> graph[N];
int main()
{
    memset(vis,0,sizeof(vis));
    int n,m;
    cin>>n>>m;
    //we will always create adjacency list as time complexity is better here
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        vector<int> :: iterator it;
        for(it = graph[node].begin();it!=graph[node].end();it++)
        {
            if(vis[*it]);
            else
            {
                vis[*it] = 1;
                q.push(*it);
            }
        }
    }
    return 0;
}