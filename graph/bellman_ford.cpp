#include <iostream>
#include <iomanip>
using namespace std;

#define INF 9999

int main() {
    int n, e, src;
    int eu[100], ev[100], ew[100];     
    int dist[20];

    cout << "Enter number of vertices (1 to 20): ";
    cin >> n;
    cout << "Enter number of edges (0 to 100): ";
    cin >> e;
    for (int i = 0; i < e; i++) {
        cout << "Edge " << i + 1 << " (from to weight): ";
        cin >> eu[i] >> ev[i] >> ew[i];
    }
    cout << "Enter source vertex: ";
    cin >> src;

    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;






      for (int i = 1; i <= n - 1; i++) {
          for (int j = 0; j < e; j++) {
              if (dist[eu[j]] != INF && dist[eu[j]] + ew[j] < dist[ev[j]])
                  dist[ev[j]] = dist[eu[j]] + ew[j];
          }
      }

      for (int j = 0; j < e; j++) {
          if (dist[eu[j]] != INF && dist[eu[j]] + ew[j] < dist[ev[j]]) {
              cout << "Graph contains a negative weight cycle.\n";
              return 0;
          }
      }

      cout << "Vertex    Distance\n";
      for (int i = 0; i < n; i++) {
          cout << left << setw(9) << i;
          if (dist[i] == INF)
               cout << "INF\n";
          else
               cout << dist[i] << endl;
      }
      return 0;
}
