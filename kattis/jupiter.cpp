#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef tuple<int, ll, ll> edge;

int n, q, s;
int source, sink;
vi qCap;
vi sQ;

#define INF 1e18


struct maxflow {
  vi d;
  vi last;
  vector<vi> AL;
  vector<edge> EL;
  int V;

  bool BFS(int s, int t) {
    //cout << "calling BFS" << endl;
    queue<int> q;
    q.push(s);
    d.assign(V, -1);
    d[s] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) return true;
      for (auto idx : AL[u]) {
	auto &[v, c, f] = EL[idx];
	if (c - f > 0 && d[v] == -1) {
	  //cout << "bfs" << u << " " << v << endl;
	  d[v] = d[u] + 1;
	  q.push(v);
	}
      }
    }

    return d[t] != -1;
  }

  bool DFS(int u, int t, ll flow = INF) {
    //cout << "dfs: " << u << " " << t << " " << flow << endl;
    if (u == t || flow == 0) return flow;

    for (int &i = last[u]; i < (int)AL[u].size(); ++i) {
      auto &[v, c, f] = EL[AL[u][i]];
      //cout << v << "d[v], d[u]" << d[v] << ", " << d[u] << endl;
      if (d[v] != d[u] + 1) continue;
      if (ll pushed = DFS(v, t, min(flow, c - f))) {
	f += pushed;
	ll &rf = get<2>(EL[AL[u][i] ^ 1]);
	rf -= pushed;
	return pushed;
      }
    }
    return 0;
  }

  maxflow(int V) : V(V) {
    EL.clear();
    AL.assign(V, vi());
  }

  void add_edge(int u, int v, ll c) {
    //cout << "adding edge" << u << "->" << v << " " << c << endl;
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

int getSensor(int it, int i) {
  return 1 + it * (s + 2*q + 2) + i;
}

int getQueue(int it, int i, int cpy = 0) {
  return getSensor(it, s) + 2*i + cpy;
}

int getT(int it, int cpy = 0) {
  return getQueue(it, q) + cpy;
}

int main() {
  cin >> n >> q >> s;
  int total = n * (q*2 + s + 2) + 2;
  maxflow mf(total);
  sink = total-1;
  source = 0;
  sQ.assign(s, 0);
  qCap.assign(q, 0);

  for (int i = 0; i < s; ++i) {
    int y;
    cin >> y;
    sQ[i] = y-1;
  }

  for (int i = 0; i < q; ++i) {
    cin >> qCap[i];
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mf.add_edge(getT(i), getT(i, 1), x);
    for (int j = 0; j < s; ++j) {
      int y;
      cin >> y;
      sum += y;
      mf.add_edge(getSensor(i, j), getQueue(i, sQ[j]), y);
      mf.add_edge(0, getSensor(i, j), INF);
    }
    for (int j = 0; j < q; ++j) {
      mf.add_edge(getQueue(i, j), getQueue(i, j, 1), qCap[j]);
      mf.add_edge(getQueue(i, j, 1), getT(i), qCap[j]);
      if (i != n - 1) 
	mf.add_edge(getQueue(i, j, 1), getQueue(i+1, j), qCap[j]);
    }
    mf.add_edge(getT(i, 1), sink, INF);
  }

  ll mx = mf.dinic(source, sink);
  //cout << sink << " " << source << endl;
  //cout << mx << endl;
  cout << ((mx == sum) ? "possible" : "impossible") << endl;

  return 0;
}
