#include <bits/stdc++.h>

using namespace std;

#define INF 1e17

typedef long long ll;
// u -> v with capacity c and flow f. stored as (v, c, f)
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;

int s, r, f, t;

enum type {
  F,
  S,
  T
};

struct maxflow {
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d;
  vi last;

  maxflow(int V) : V(V) {
    EL.clear();
    AL.assign(V, vi());
  }

  bool BFS(int s, int t) {
    d.assign(V, -1);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (int i = 0; i < (int)AL[u].size(); ++i) {
	int idx = AL[u][i];
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
      int idx = AL[u][i];
      auto &[v, c, f] = EL[idx];
      if (d[v] != d[u] + 1) continue;
      if (ll pushed = DFS(v, t, min(flow, c - f))) {
	  f += pushed;
	  auto &[rv, rc, rf] = EL[idx^1];
	  rf -= pushed;
	  return pushed;
      }
    }
    return 0;
  }

  void add_edge(int u, int v, ll c) {
    AL[u].push_back(EL.size());
    EL.emplace_back(v, c, 0);
    AL[v].push_back(EL.size());
    EL.emplace_back(u, 0, 0);
  }

  ll dinic(int s, int t) {
    ll mf = 0;
    while(BFS(s, t)) {
      last.assign(V, 0);
      while(ll pushed = DFS(s,t)) {
	mf += pushed;
      }
    }
    return mf;
  }
};

inline enum type getType(int u) {
  if (u <= r) {
    return S;
  } else if (u <= r + f) {
    return F;
  } else {
    return T;
  }
}

int main() {
  int counter = 0;
  map<string, int> toIdx;
  cin >> s >> r >> f >> t;
  maxflow mf(s+2*t+2);
  for (int i = 1; i <= r; ++i) {
    string name;
    cin >> name;
    if (!toIdx[name]) toIdx[name] = ++counter;
    mf.add_edge(0, toIdx[name], 1);
  }
  for (int i = 1; i <= f; ++i) {
    string name;
    cin >> name;
    if (!toIdx[name]) toIdx[name] = ++counter;
    mf.add_edge(toIdx[name], s+2*t+1, 1);
  }
  for (int i = 1; i <= t; ++i) {
    string name = "f" + to_string(i);
    string rname = "rf" + to_string(i);
    if (!toIdx[name]) toIdx[name] = ++counter;
    if (!toIdx[rname]) toIdx[rname] = ++counter;
    mf.add_edge(toIdx[name], toIdx[rname], 1);
  }
  for (int i = 1; i <= t; ++i) {
    int n;
    int ff = toIdx["f" + to_string(i)];
    int rf = toIdx["rf" + to_string(i)];
    string name;
    cin >> n;
    vi vertices(n, 0);
    for (int j = 0; j < n; ++j) {
      cin >> name;
      if (!toIdx[name]) toIdx[name] = ++counter;
      int v = toIdx[name];
      enum type vType = getType(v);
      if (vType == S) {
	mf.add_edge(v, ff, 1);
      } else if (vType == F) {
	mf.add_edge(rf, v, 1);
      } else {
	mf.add_edge(v, ff, 1);
	mf.add_edge(rf, v, 1);
      }
    }
  }
  cout << mf.dinic(0, s+2*t+1) << endl;;
}
