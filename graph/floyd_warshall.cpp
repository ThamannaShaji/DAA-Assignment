#include <iostream>
#include <iomanip>
using namespace std;

#define INF 9999

int main() {
    int n, e, u, v, w;
    int dist[20][20];

    cout << "Enter number of vertices (1 to 20): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                dist[i][j] = 0;






              else
                  dist[i][j] = INF;
          }
      }
      cout << "Enter number of edges: ";
      cin >> e;
      for (int i = 1; i <= e; i++) {
          cout << "Edge " << i << " (from to weight): ";
          cin >> u >> v >> w;
          dist[u][v] = w;
      }

      for (int k = 0; k < n; k++) {
          for (int i = 0; i < n; i++) {
              for (int j = 0; j < n; j++) {
                  if (dist[i][k] != INF && dist[k][j] != INF) {
                      if (dist[i][k] + dist[k][j] < dist[i][j])
                          dist[i][j] = dist[i][k] + dist[k][j];
                  }
              }
          }
          for (int i = 0; i < n; i++) {
              if (dist[i][i] < 0) {
                  cout << "Graph contains a negative weight cycle.\n";
                  return 0;
              }
          }
      }

      cout << "Shortest distance matrix:\n";
      cout << "      ";
      for (int j = 0; j < n; j++)
          cout << setw(5) << j;
      cout << endl;
      for (int i = 0; i < n; i++) {
          cout << setw(5) << i;
          for (int j = 0; j < n; j++) {
              if (dist[i][j] == INF)
                   cout << setw(5) << "INF";
              else
                   cout << setw(5) << dist[i][j];
          }
          cout << endl;
      }
      return 0;
}
