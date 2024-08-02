#include <bits/stdc++.h>

#define INF 1e9
#define EPS 1e-9

using namespace std;

typedef double ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
// (u, v) with capcity c, w, and flow f stored as: (v, c, w, f)
typedef tuple<int, ll, ll, ll> edge;

class mcmf {
public:
  int V;
  ll totalCost;
  vector<vi> AL;
  vector<edge> EL;
  vector<bool> visited;
  vector<ll> d;
  vector<int> last;

  // Return true if s -> t path found in residual graph.
  bool SPFA(int s, int t) {
    d.assign(V, INF);
    d[s] = 0;
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
      int u = q.front(); q.pop(); visited[u] = false;
      for (auto idx : AL[u]) {
	auto &[v, c, w, f] = EL[idx];
	if ((c - f > 0) && (d[v] > d[u] + w)) {
	  d[v] = d[u] + w;
	  if (!visited[v]) { q.push(v), visited[v] = 1; }
	}
      }
    }
    return d[t] != INF;
  }

  ll DFS(int u, int t, ll flow = INF) {
    if (u == t || flow == 0) return flow;
    visited[u] = 1;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) {
      auto &[v, c, w, f] = EL[AL[u][i]];
      if (!visited[v] && d[v] == d[u] + w) {
	if (ll pushed = DFS(v, t, min(c - f, flow))) {
	    totalCost += pushed * w;
	    f += pushed;
	    auto &rf = get<3>(EL[AL[u][i]^1]);
	    rf -= pushed;
	    visited[u] = 0;
	    return pushed;
	}
      }
    }
    visited[u] = 0;
    return 0;
  }

  pair<ll, ll> findMin(int s, int t) {
    ll flow = 0;
    totalCost = 0;
    while(SPFA(s,t)) {
      last.assign(V, 0);
      while(ll f = DFS(s, t)) {
	flow += f;
      }
    }
    return {totalCost, flow};
  }

  mcmf(int V) : V(V), totalCost(0) { 
    AL.assign(V, vi());
    EL.clear();
    visited.assign(V, false);
  }

  void add_edge(int u, int v, ll c, ll w) {
    if (u == v) return;
    AL[u].emplace_back(EL.size());
    EL.emplace_back(v, c, w, 0);
    AL[v].emplace_back(EL.size());
    EL.emplace_back(u, 0, -w, 0);
  }
};

void solve(int n, int m) {
  mcmf g(n + m + 2);

  for (int i = 1; i <= n; ++i) {
    g.add_edge(0, i, 1, 0);
  }

  for (int i = n+1; i <= n+m; ++i) {
    g.add_edge(i, n+m+1, 1, 0);
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = n+1; j <= n+m; ++j) {
      ll w;
      cin >> w;
      g.add_edge(i, j, 1, w);
    }
  }

  auto [c, f] = g.findMin(0, n+m+1);
  // 0.(x)(y)5 should be rounded to 0.(x)(y+1) but it could be the case that
  // 0.(x)(y)5 in double be reprsented as 0.(x)(y)49999999999 something, so we need EPS.
  cout << fixed << setprecision(2) << c/n + EPS << endl;
  //cout << fixed << setprecision(2) << c/n << endl;
}

int main() {
  int n, m;
  while(true) {
    cin >> n >> m;
    if (!m && !n) break;
    solve(n, m);
  }
}
