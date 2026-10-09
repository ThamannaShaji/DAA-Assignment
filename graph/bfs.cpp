#include <iostream>
using namespace std;

int adj[20][20], visited[20], n;

void bfs(int start) {
    int q[20], front = 0, rear = 0;
    visited[start] = 1;
    q[rear++] = start;
    cout << "BFS traversal: ";
    while (front < rear) {
        int v = q[front++];
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
    cout << endl;
}

int main() {
    int e, u, v, start;
    cout << "Enter number of vertices (1 to 20): ";
    cin >> n;






      cout << "Enter number of edges: ";
      cin >> e;
      for (int i = 1; i <= e; i++) {
          cout << "Edge " << i << " (u v): ";
          cin >> u >> v;
          adj[u][v] = 1;
          adj[v][u] = 1;
      }
      cout << "Enter starting vertex: ";
      cin >> start;
      bfs(start);
      return 0;
}
