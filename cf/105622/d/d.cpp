#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef vector<int> vi;
typedef vector<vi> vii;

int n;
vii tree;
vi visited;
vi posW;
vi negW;

int BFSNode(int s) {
  int u = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()) {
    u = q.front(); q.pop();
    visited[u] = 1;
    for (auto v : tree[u]) {
      if (!visited[v]) q.push(v);
    }
  }
  return u;
}

int DFSLvl(int s, int lvl) {
  if (visited[s]) return 0;
  visited[s] = 1;
  int mxLvl = lvl;
  for (auto v : tree[s]) {
    mxLvl = max(DFSLvl(v, lvl+1), mxLvl);
  }
  return mxLvl;
}

// First find the longest s-t path then order them in highest + weight, highest - weight, 2nd highest postive weight, ...., 
int32_t main() {
  int u,v,w;
  cin >> n;
  tree.assign(n+1, vi(0));
  visited.assign(n+1, 0);
  for (int i = 1; i < n; ++i) {
    cin >> u >> v >> w;
    tree[u].push_back(v);
    tree[v].push_back(u);
    if (w > 0) posW.push_back(w);
    else negW.push_back(w);
  }
  sort(posW.begin(), posW.end(), greater<int>());
  sort(negW.begin(), negW.end(), greater<int>());

  visited.assign(n+1, 0); v = BFSNode(1);
  visited.assign(n+1, 0); int length = DFSLvl(v, 0);

  int ans = 0;
  for (int i = 0; i < length/2; ++i) {
    if (i == posW.size()) break;
    ans += posW[i];
    if (i == negW.size() || i+1 == posW.size() || posW[i+1] < -1 * negW[i] || i == length/2 - 1) break;
    ans += negW[i];
  }

  if (ans==0) ans = (posW.size() != 0 ? posW[0] : negW[0]);
  cout << ans << '\n';
}
