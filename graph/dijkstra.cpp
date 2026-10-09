#include <iostream>
#include <iomanip>
using namespace std;

#define INF 9999

int graph[20][20], n;
int dist[20], parent[20], visited[20];

void printPath(int v) {
    if (parent[v] != -1) {
        printPath(parent[v]);
        cout << " -> ";
    }
    cout << v;
}

int main() {






      int e, u, v, w, src;
      cout << "Enter number of vertices (1 to 20): ";
      cin >> n;
      cout << "Enter number of edges: ";
      cin >> e;
      for (int i = 1; i <= e; i++) {
          cout << "Edge " << i << " (from to weight): ";
          cin >> u >> v >> w;
          graph[u][v] = w;
      }
      cout << "Enter source vertex: ";
      cin >> src;

      for (int i = 0; i < n; i++) {
          dist[i] = INF;
          parent[i] = -1;
          visited[i] = 0;
      }
      dist[src] = 0;

      for (int count = 0; count < n; count++) {
          u = -1;
          for (int i = 0; i < n; i++) {
              if (visited[i] == 0 && (u == -1 || dist[i] < dist[u]))
                  u = i;
          }
          if (dist[u] == INF)
              break;
          visited[u] = 1;
          for (v = 0; v < n; v++) {
              if (graph[u][v] != 0 && visited[v] == 0 && dist[u] + graph[u][v] < dist[v]) {
                  dist[v] = dist[u] + graph[u][v];
                  parent[v] = u;
              }
          }
      }

      cout << "Vertex   Distance    Path\n";
      for (int i = 0; i < n; i++) {
          cout << left << setw(9) << i;
          if (dist[i] == INF)
              cout << setw(11) << "INF" << "No path\n";
          else {
              cout << setw(11) << dist[i];
              printPath(i);
              cout << endl;
          }
      }
      return 0;
}
