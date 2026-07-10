#include "graph.h"

int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.display();

    g.DFS(0);

    g.BFS(0);

    g.deleteEdge(0,2);

    cout<<"\n\nAfter deleting edge (0,2)\n";

    g.display();

    return 0;
}