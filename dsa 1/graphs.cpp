//graphs 
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int vis[N];
int pathvis[N];
vector<int> v[N];
int color[N];   
bool iscycle;
bool isbipar = true;
stack<int> st;

bool cycledg(int node)
{
    vis[node] = 1;
    pathvis[node] = 1;

    for(auto it:v[node])
    {
        if(!vis[it])
        {
            iscycle |=cycledg(it);
        }
        else if(vis[it]==1 && pathvis[it]==1)
        {
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}

void topo(int node)
{
    vis[node] = 1;
    for(auto it:v[node])
    {
        if(!vis[it])
        {
            topo(it);
        }
    }
    st.push(node);
}

bool bipar(int node)
{
    //12    23  25  34  45  46
    for(auto it:v[node])
    {
        if(color[it]==0)
        {
            if(color[node]==-1)
            {
                color[it] = 1;
                isbipar &= bipar(it);
            }
            else
            {
                color[it] = -1;
                isbipar &= bipar(it);
            }
        }
        else if(color[it]==1 && color[node]==1)
        {
            return false;
        }
        else if(color[it]==-1 && color[node]==-1)
        {
            return false;
        }
    }
    return isbipar;
}   

bool cycleug(int node, int parent)
{
    //12    13  34  35
    vis[node] = 1;

    for(auto it:v[node])
    {
        if(!vis[it])
        {
            iscycle |= cycleug(it,node);
        }
        else if(vis[it]==1 && it==parent)
        {
            continue;
        }
        else if(vis[it]==1 && it!=parent)
        {
            return true;
        }
    }
    return iscycle;
}

void conc(int node)
{
    vis[node] = 1;

    for(auto it:v[node])
    {
        if(!vis[it])    
        conc(it);
    }
}

void dfs(int node)
{
    vis[node] = 1;
    // cout<<node<<" ";

    for(auto it:v[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
    cout<<node<<" ";
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty())
    {
        int top = q.front();
        cout<<top<<" ";
        q.pop();

        for(auto it:v[top])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

void adjmat(int n, int m)
{
    int arr[n+1][n+1];
    memset(arr,0,sizeof(arr));

    //12   13  24  34  35  45
    cout<<endl;

    for(int i=1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        arr[v1][v2] = 1;
        arr[v2][v1] = 1;
    }

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void adjlist(int n, int m)
{
    //12   13  24  34  35  45

    for(int i=1;i<=m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        v[v1].push_back(v2);
        // v[v2].push_back(v1);
    }

    // for(int i=1;i<n+1;i++)
    // {
    //     for(auto it:v[i])
    //     {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
}

int main()
{
    int n,m;
    cout<<"enter vertices and edges:";
    cin>>n>>m;

    // adjmat(n,m);
    // cout<<endl;

    adjlist(n,m);
    cout<<endl;

    // bfs(1);
    // cout<<endl;

    // dfs(1);
    // cout<<endl;

    // int c=0;
    // for(int i=1;i<n+1;i++)
    // {
    //     if(!vis[i])
    //     {
    //         c++;
    //         conc(i);
    //     }
    // }
    // cout<<"connected components = "<<c;

    // cout<<cycleug(1,-1);

    // color[1] = -1;
    // cout<<bipar(1);

    // for(int i=1;i<=n;i++)
    // {
    //     if(!vis[i])
    //     {
    //         topo(i);
    //     }
    // }

    // while(!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    cout<<cycledg(1);

    return 0;
}