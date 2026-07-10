#include "graph.h"
#include<queue>

Graph::Graph(int v)
{
    vertices=v;
    adj=new vector<int>[vertices];
}

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::deleteEdge(int u,int v)
{
    for(auto it=adj[u].begin();it!=adj[u].end();it++)
    {
        if(*it==v)
        {
            adj[u].erase(it);
            break;
        }
    }

    for(auto it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(*it==u)
        {
            adj[v].erase(it);
            break;
        }
    }
}

void Graph::display()
{
    cout<<"\nAdjacency List\n";

    for(int i=0;i<vertices;i++)
    {
        cout<<i<<" -> ";

        for(int x:adj[i])
            cout<<x<<" ";

        cout<<endl;
    }
}

void Graph::DFSUtil(int v,bool visited[])
{
    visited[v]=true;

    cout<<v<<" ";

    for(int x:adj[v])
    {
        if(!visited[x])
            DFSUtil(x,visited);
    }
}

void Graph::DFS(int start)
{
    bool *visited=new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i]=false;

    cout<<"\nDFS : ";

    DFSUtil(start,visited);

    delete[] visited;
}

void Graph::BFS(int start)
{
    bool *visited=new bool[vertices];

    for(int i=0;i<vertices;i++)
        visited[i]=false;

    queue<int> q;

    visited[start]=true;

    q.push(start);

    cout<<"\nBFS : ";

    while(!q.empty())
    {
        int v=q.front();

        q.pop();

        cout<<v<<" ";

        for(int x:adj[v])
        {
            if(!visited[x])
            {
                visited[x]=true;
                q.push(x);
            }
        }
    }

    delete[] visited;
}