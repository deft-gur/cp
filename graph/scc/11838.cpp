#include <bits/stdc++.h>

using namespace std;
#define MX 2005
typedef vector<int> vi;

int n, m;
vi al[MX];
vi al_t[MX];
int visited[MX];
vi topSort;

void dfs(int i, int t = 0) {
  visited[i] = 1;
  for (auto j : (!t ? al[i] : al_t[i])) {
    if (!visited[j]) dfs(j, t);
  }
  topSort.push_back(i);
}

void solve() {
  fill(al, al+MX, vi());
  fill(al_t, al_t+MX, vi());
  fill(visited, visited+MX, 0);
  topSort.clear();

  for (int i = 0; i < m; ++i) {
    int v, w, p;
    scanf("%d %d %d", &v, &w, &p);
    if (p == 1){
      al[v].push_back(w);
      al_t[w].push_back(v);
    } else {
      al[w].push_back(v);
      al[v].push_back(w);
      al_t[w].push_back(v);
      al_t[v].push_back(w);
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]){
      dfs(i, 0);
    }
  }

  fill(visited, visited+MX, 0);
  reverse(topSort.begin(), topSort.end());
  int scc = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(topSort[i-1],1);
      ++scc;
    }
  }

  printf("%d\n", (scc==1) ? 1 : 0);
}

int main() {
  while (true) {
    scanf("%d %d", &n, &m);
    if (!n && !m) break;
    solve();
  }
}
