// Complexity: O(E + V) bounded by topsort, bfs, and dp
// AC
#include <bits/stdc++.h>

using namespace std;

#define MX 26

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int W[MX];
vii AL[MX];
vi top;
int visited[MX];
int memo[MX];
int n;

void dfs(int u) {
  if (visited[u]) return;

  visited[u] = 1;

  for (auto [v, w] : AL[u]) {
    if (visited[v]) continue;
    dfs(v);
  }

  top.push_back(u);
}

void topSort() {
  memset(visited, 0, sizeof visited);
  top.clear();
  for (int i = 0; i < n; ++i) {
    dfs(i);
  }
  reverse(top.begin(), top.end());
}

void dp() {
  for (int u = 0; u < n; ++u) {
    for (auto [v, w] : AL[u]) {
      memo[v] = max(memo[u] + w, memo[v]);
    }
  }
}

void solve() {
  memset(memo, 0, sizeof memo);
  memset(W, 0, sizeof W);
  for (int i = 0; i < MX; ++i) {
     AL[i].clear();
  }
  string line;
  n = 0;
  while(getline(cin, line)) {
    if (line.empty()) break;
    ++n;
    stringstream ss(line);
    char u;
    int w;
    ss >> u >> w;
    W[u - 'A'] = w;
    char v;
    while(ss >> v) {
      AL[v - 'A'].emplace_back(u - 'A', 0);
    }
  }
  for (int u = 0; u < n; ++u) {
    for (auto &[v, w] : AL[u]) {
      w = W[u];
    }
  }

  topSort();
  dp();
  int m = 0;
  for (int i = 0; i < n; ++i) {
    m = max(memo[i] + W[i], m);
  }
  cout << m << endl;
}

int main() {
  int t;
  string s;
  getline(cin, s);
  t = stoi(s);
  getline(cin, s);
  for (int i = t-1; i >= 0; --i) {
    solve();
    if (i) cout << endl;
  }
}
