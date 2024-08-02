#include <bits/stdc++.h>

#define MX 10000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m;
int W[MX][MX];
bool Present[MX][MX];
int C[MX][MX];
int b[MX];
int WRes[MX][MX];
int y[MX];
int p[MX];
//vii AL[MX];
vii ALRes[MX];
int X[MX][MX];

// Return true iff node v is in the path from s to u in p.
bool inPath(int u, int v) {
  int node = u;
  while(node) {
    if (node == v) return true;
    node = p[node];
  }
  return false;
}

string getPath(int u) {
  int node = u;
  string path = "";
  while(node) { path += " ," + to_string(node); node = p[node]; }
  reverse(path.begin(), path.end());
  return path;
}

// On success returns 0 or returns a node i that's in a neagtive cycle
int dantzig() {
  // The reason we can set y to 0 is we can imagine a source node s connecting to all other nodes with 0 cost.
  memset(y, 0, sizeof(y));
  memset(p, 0, sizeof(p));
  bool restart = false;
  for (int u = 1; u <= n; ++u) {
    for (auto [v, w] : ALRes[u]) {
      if (y[v] > y[u] + w) {
        if (inPath(u, v)) {
          cout << "Negative cycle found: ";
          string path = getPath(u);
          path += to_string(v);
          cout << path << endl;
          p[v] = u;
          return v;
        } else {
          restart = true;
          y[v] = y[u] + w;
          p[v] = u;
        }
      }
    }
    if (restart) restart = false, u = 0;
  }
  return 0;
}

void printX() {
  cout << "X values:" << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << X[i][j] <<" ";
    }
    cout << endl;
  }
}

void printRes() {
  cout << "res graph: " << endl;
  for (int u = 1; u <= n; ++u) {
    for (auto [v, w] : ALRes[u]) cout << u << "->" << v << "[label=" << w <<"]" << endl;
  }
}

void solve() {
  // Initial feasible flow:
  // Assuming we are given an initial flow to work with.
  // If not then we can solve the maximum flow problem without worrying about W at first.
  // We run maxflow on the constructed D' graph stated in proposition 4.5.
  for (int i = 1; i <= m; ++i) {
    int u, v, x;
    cin >> u >> v >> x;
    X[u][v] = x;
    if (X[u][v] > 0) {
      ALRes[v].emplace_back(u, -W[u][v]);
    }
    if (X[u][v] < C[u][v]) {
      ALRes[u].emplace_back(v, W[u][v]);
    }
  }

  while(true) {
    printX();
    printRes();
    cout << "enteirng danztig" << endl;
    int cycle = dantzig();
    if (!cycle) break;
    int u = p[cycle];
    int v = cycle;
    int m = INT_MAX;
    do {
      if (Present[u][v]) {
        m = min(m, C[u][v] - X[u][v]);
      } else {
        m = min(m, X[v][u]);
      }
      if (m == 0) cout << "something is worng" << u << v << endl;
      cout << X[u][v];
      cout << C[u][v];
      v = u;
      u = p[u];
    } while(v != cycle);
    cout << "gamma" << m << endl;
    u = p[cycle];
    v = cycle;
    do {
      if (Present[u][v]) {
        if (X[u][v] == 0) ALRes[v].emplace_back(u, -W[u][v]);
        X[u][v] += m;
        if (X[u][v] == C[u][v]) {
          auto it = find(ALRes[u].begin(), ALRes[u].end(), make_pair(v, W[u][v]));
          ALRes[u].erase(it);
        }
      } else {
        if (X[v][u] == C[v][u]) ALRes[v].emplace_back(u, W[v][u]);
        X[v][u] -= m;
        if (X[v][u] == 0) {
          auto it = find(ALRes[u].begin(), ALRes[u].end(), make_pair(v, -W[v][u]));
          ALRes[u].erase(it);
        }
      }
      v = u;
      u = p[u];
    } while(v != cycle);
  }

  printX();
  printRes();
}


int main() {
  cin >> n >> m;
  // Node demand
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    b[x] = y;
  }
  // Arc info
  memset(W, 0, sizeof(W));
  memset(Present, 0, sizeof(Present));
  for (int i = 1; i <= m; ++i) {
    int u, v, w, c;
    cin >> u >> v >> w >> c;
    //AL[u].emplace_back(w, c);
    W[u][v] = w;
    Present[u][v] = 1;
    C[u][v] = c;
  }
  for (int i =1; i <=n; ++i) {
    for (int j = 1; j <=n; ++j) {
      cout << W[i][j] << " ";
    }
    cout << endl;
  }
  solve();
}
