#include <iostream>
using namespace std;

int eu[100], ev[100], ew[100];     
int parent[20];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}
int main() {





      int n, e, total = 0, count = 0;
      int ru[20], rv[20], rw[20];   

      cout << "Enter number of vertices (1 to 20): ";
      cin >> n;
      cout << "Enter number of edges (0 to 100): ";
      cin >> e;
      for (int i = 0; i < e; i++) {
          cout << "Edge " << i + 1 << " (u v weight): ";
          cin >> eu[i] >> ev[i] >> ew[i];
      }

      for (int i = 0; i < e - 1; i++) {
          for (int j = 0; j < e - i - 1; j++) {
              if (ew[j] > ew[j + 1]) {
                  int t;
                  t = eu[j]; eu[j] = eu[j + 1]; eu[j + 1] = t;
                  t = ev[j]; ev[j] = ev[j + 1]; ev[j + 1] = t;
                  t = ew[j]; ew[j] = ew[j + 1]; ew[j + 1] = t;
              }
          }
      }

      for (int i = 0; i < n; i++)
          parent[i] = i;

      for (int i = 0; i < e && count < n - 1; i++) {
          int a = find(eu[i]);
          int b = find(ev[i]);
          if (a != b) {              
              ru[count] = eu[i];
              rv[count] = ev[i];
              rw[count] = ew[i];
              count++;
              total = total + ew[i];
              parent[a] = b;
          }
      }

      if (count != n - 1) {
          cout << "Graph is not connected. MST is not possible.\n";
          return 0;
      }
      cout << "Edge     Weight\n";
      for (int i = 0; i < count; i++)
          cout << ru[i] << " - " << rv[i] << "     " << rw[i] << endl;
      cout << "Total weight of MST = " << total << endl;
      return 0;
}
