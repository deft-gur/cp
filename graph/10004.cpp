#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int n, int m) {
  vvi al(n, vi());
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    al[u].push_back(v);
    al[v].push_back(u);
  }

  vi color(n, 0);
  color[0] = 1;
  queue<int> q;
  q.push(0);
  bool ans = true;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : al[u]) {
      if (color[v]) {
	if (color[v] == color[u]) {
	  ans = false;
	  break;
	}
      } else {
	color[v] = color[u] == 1 ? 2 : 1;
	q.push(v);
      }
    }
  }

  if (ans) printf("BICOLORABLE.\n");
  else printf("NOT BICOLORABLE.\n");

}

int main() {
  while (true) {
    int n, m;
    cin >> n;
    if (!n) break;
    cin >> m;
    solve(n, m);
  };

}
