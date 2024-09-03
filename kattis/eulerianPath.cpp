#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int n, m;
vector<vi> AL, inAL;

vi eulerianPath(int s) {
  vi idx;
  idx.assign(n, 0);
  vi p;
  p.push_back(s);
  vi res;
  while(!p.empty()) {
    int i = p.back();
    if (idx[i] == AL[i].size()) {
      res.push_back(i);
      p.pop_back();
    } else {
      p.push_back(AL[i][idx[i]]);
      ++idx[i];
    }
  }
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  while(true) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    AL.assign(n, vi());
    inAL.assign(n, vi());
    int u, v;
    for (int i = 0; i < m; ++i) {
      cin >> u >> v;
      AL[u].push_back(v);
      inAL[v].push_back(u);
    }
    int in, out, eq;
    in = out = eq = 0;
    int s = 0;
    for (int i = 0; i < n; ++i) {
      if (AL[i].size() - inAL[i].size() == 1) { s = i; ++out; }
      else if (AL[i].size() - inAL[i].size() == -1) { ++in; }
      else if (AL[i].size() == inAL[i].size()) { ++eq; }
    }
    // In a connected graph, there is a eulerian tour iff indegree = outdegree.
    // In a connected graph, there is a eulerian path iff it's an eulerian tour or 
    //	  (one of the outdegree = indegree - 1 and one of indegree = outdegree - 1)
    if (in > 1 || out > 1 || out + in + eq != n) {
      cout << "impossible" << endl;
      continue;
    }
    auto p = eulerianPath(s);
    // Check for disconnected graph
    if (p.size() != m+1) {
      cout << "impossible" << endl;
      continue;
    }
    vi vis(n, 0);
    for (auto v : p) { cout << v << " "; }
    cout << '\n';
  }
}
