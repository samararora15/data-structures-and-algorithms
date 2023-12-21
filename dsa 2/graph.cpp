//trees and graphs
//graph can be represented in two ways - adjacency matrix and adjacency list
//adjacency matrix method an array of size nxn is created where n is number of vertices in the graph
//adjacency list method is space optimized
#include<bits/stdc++.h>
using namespace std;
void adjacency_list()
{
    int n,m; // n and m are vertices and edges respectively
    cin>>n>>m;
    vector<int> graph[n+1];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=0;i<n+1;i++)
    {
        for (auto it = graph[i].begin(); it != graph[i].end(); it++)
        {   
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}
void adjacency_matrix()
{
    int n,m; // n and m are vertices and edges respectively
    cin>>n>>m;
    int graph[n+1][n+1];
    memset(graph,0,sizeof(graph));
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    //limitations of adjacency matrix is space complexity is 0(n2)
}
int main()
{
    int ch;
    cin>>ch;
    if(ch==1)
    {
        adjacency_matrix();
    }
    else
    {
        adjacency_list();
    }
    return 0;
}