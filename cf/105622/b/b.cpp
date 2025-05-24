#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

vii tree;
int n;
int s, t;

int main() {
  cin >> n >> s >> t;
  tree.assign(n+1, vi(0));
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  bool win = false;
  for (auto v : tree[s]) if (v == t) win = true;
  cout << (win ? "YES" : "NO") << '\n';

  return 0;
}
