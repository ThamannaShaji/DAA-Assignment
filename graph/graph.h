#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    int vertices;
    vector<int> *adj;

    void DFSUtil(int, bool[]);

public:
    Graph(int);

    void addEdge(int,int);
    void deleteEdge(int,int);

    void DFS(int);
    void BFS(int);

    void display();
};

