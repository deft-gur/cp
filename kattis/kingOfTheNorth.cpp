#include <bits/stdc++.h>

using namespace std;

#define INF 1e18

typedef long long ll;
typedef vector<int> vi;
typedef tuple<int, ll, ll> edge;
typedef pair<int, int> ii;

int r, c;

ii invIdx(int idx) {
  int i, j;
  j = idx % c;
  i = idx / c;
  return {i,j};
}

struct maxflow {
  vector<vi> AL;
  vector<edge> EL;
  vi d;
  vi last;
  int V;

  maxflow(int V) : V(V) {
    AL.assign(V, vi());
    EL.clear();
  }

  bool BFS(int s, int t) {
    queue<int> q;
    d.assign(V, -1);
    d[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) return true;
      for (auto idx : AL[u]) {
	auto &[v, c, f] = EL[idx];
	if (c - f > 0 && d[v] == -1) {
	  d[v] = d[u] + 1;
	  q.push(v);
	}
      }
    }
    return d[t] != -1;
  }

  ll DFS(int u, int t, ll flow = INF) {
    if (u == t || flow == 0) return flow;

    for (int &i = last[u]; i < (int)AL[u].size(); ++i) {
      //cout << u << " " << t << " " << flow << endl;
      auto &[v, c, f] = EL[AL[u][i]];
      if (d[v] != d[u] + 1) continue;
      if (ll pushed = DFS(v, t, min(flow, c - f))) {
	f += pushed;
	ll &rf = get<2>(EL[AL[u][i]^1]);
	rf -= pushed;
	return pushed;
      }
    }
    return 0;
  }

  void add_edge(int u, int v, ll c) {
    //auto [a, b] = invIdx(u);
    //auto [x, y] = invIdx(v);
    //cout << "adding (" << a << ", " << b << ")->(" << x << ", " << y << ")" << endl;
    AL[u].push_back(EL.size());
    EL.emplace_back(v, c, 0);
    AL[v].push_back(EL.size());
    EL.emplace_back(u, 0, 0);
  }

  ll dinic(int s, int t) {
    ll mf = 0;
    while(BFS(s, t)) {
      last.assign(V, 0);
      while(ll pushed = DFS(s, t)) {
	mf += pushed;
      }
    }
    return mf;
  }
};



int getIdx(int i, int j) {
  return (i * c) + j;
}

int getCpyIdx(int i, int j) {
  return (r * c) + getIdx(i, j);
}

int main() {
  cin >> r >> c;
  int target = 2 * r * c;
  maxflow mf(2 * r * c + 1);
  int M[r][c];
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> M[i][j];
      mf.add_edge(getIdx(i, j), getCpyIdx(i, j), M[i][j]);
    }
  }
  for (int i = 1; i < r-1; ++i) {
    mf.add_edge(getCpyIdx(i, 0), target, M[i][0]);
    mf.add_edge(getCpyIdx(i, c-1), target, M[i][c-1]);
  }
  for (int i = 1; i < c-1; ++i) {
    mf.add_edge(getCpyIdx(0, i), target, M[0][i]);
    mf.add_edge(getCpyIdx(r-1, i), target, M[r-1][i]);
  }

  // Four corners, to prevent the above two loop add duplicates.
  mf.add_edge(getCpyIdx(0, 0), target, M[0][0]);
  mf.add_edge(getCpyIdx(r-1, 0), target, M[r-1][0]);
  mf.add_edge(getCpyIdx(0, c-1), target, M[0][c-1]);
  mf.add_edge(getCpyIdx(r-1, c-1), target, M[r-1][c-1]);

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (i > 0)
	mf.add_edge(getCpyIdx(i, j), getIdx(i-1, j), M[i][j]);
      if (i < r-1)
	mf.add_edge(getCpyIdx(i, j), getIdx(i+1, j), M[i][j]);
      if (j > 0)
	mf.add_edge(getCpyIdx(i, j), getIdx(i, j-1), M[i][j]);
      if (j < c - 1)
	mf.add_edge(getCpyIdx(i, j), getIdx(i, j+1), M[i][j]);
    }
  }

  int s, t;
  cin >> s >> t;
  cout << mf.dinic(getIdx(s, t), target) << endl;
}
