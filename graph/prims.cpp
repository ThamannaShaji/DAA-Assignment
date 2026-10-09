#include <iostream>
using namespace std;

#define INF 9999

int graph[20][20], n;

int main() {
    int e, u, v, w;
    int key[20], parent[20], inMST[20];

    cout << "Enter number of vertices (1 to 20): ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    for (int i = 1; i <= e; i++) {
        cout << "Edge " << i << " (u v weight): ";
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;





      }

      for (int i = 0; i < n; i++) {
          key[i] = INF;
          inMST[i] = 0;
      }
      key[0] = 0;
      parent[0] = -1;

      for (int count = 0; count < n; count++) {
          u = -1;
          for (int i = 0; i < n; i++) {
              if (inMST[i] == 0 && (u == -1 || key[i] < key[u]))
                  u = i;
          }
          if (key[u] == INF) {
              cout << "Graph is not connected. MST is not possible.\n";
              return 0;
          }
          inMST[u] = 1;
          for (v = 0; v < n; v++) {
              if (graph[u][v] != 0 && inMST[v] == 0 && graph[u][v] < key[v]) {
                  key[v] = graph[u][v];
                  parent[v] = u;
              }
          }
      }

      int total = 0;
      cout << "Edge     Weight\n";
      for (int i = 1; i < n; i++) {
          cout << parent[i] << " - " << i << "     " << graph[i][parent[i]] << endl;
          total = total + graph[i][parent[i]];
      }
      cout << "Total weight of MST = " << total << endl;
      return 0;
}
