#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// <1, 2, 3> 1 is the head of an arc. 2 is the capcity and 3 is current flow.
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  // Find augmenting path.
  bool BFS(int s, int t) {
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;
      for (auto &idx : AL[u]) {
      auto &[v, cap, flow] = EL[idx];
      // Note in the directed arc, we have the backward arc with capcity 0 and 
      // * -1 of the forward arc's flow. So cap - flow > 0 as long as flow 
      // of the foward arc is > 0.
      if (d[v] == -1 && (cap - flow > 0))
        d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
      }
    }
    return d[t] != -1;
  }

  ll send_flow(int s, int t, ll f = INF) {
    if (s == t) return f;
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_flow(s, u, min(f, cap - flow));
    flow += pushed;
    // The reverse arc is always right beside the foward arc.
    auto &rFlow = get<2>(EL[idx ^ 1]);
    rFlow -= pushed;
    return pushed;
  }

  ll DFS(int u, int t, ll f = INF) {
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) {
      auto &[v, cap, flow] = EL[AL[u][i]];
      // Check for correct layer.
      if (d[v] != d[u]+1) continue;
      if (ll pushed = DFS(v, t, min(f, cap - flow))) {
        flow += pushed;
        // The reverse arc is always right beside the foward arc.
        auto &rFlow = get<2>(EL[AL[u][i] ^ 1]);
        rFlow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:

  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  void add_edge(int u, int v, ll c, bool directed = true) {
    if (u == v) return;
    EL.emplace_back(v, c, 0);
    AL[u].push_back(EL.size() - 1);
    EL.emplace_back(u, directed ? 0 : c, 0);
    AL[v].push_back(EL.size() - 1);
  }
  
  void reset() {
    for (auto &[v, c, f] : EL) {
      f = 0;
    }
  }

  // O(VE^2)
  ll edmonds_karp(int s, int t) {
    ll mf = 0;
    while(BFS(s,t)) {
      ll f = send_flow(s, t);
      if (!f) break;
      mf += f;
    }
    return mf;
  }

  // O(V^2E)
  ll dinic(int s, int t) {
    ll mf = 0;
    while(BFS(s, t)) {
      last.assign(V, 0);
      while (ll f = DFS(s,t)) {
        mf += f;
      }
    }
    return mf;
  }
};


int main() {
}
