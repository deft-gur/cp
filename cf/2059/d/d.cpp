#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<ii> sii;
typedef set<pair<int, ii>> siii;
int const INF = 1<<30;
vvi g1, g2, d, vis;
int n, s1, s2, m;
vi good;
sii edges;
siii st;



void solve() {
  cin >> n >> s1 >> s2;
  --s1, --s2;
  g1.assign(n, vi(0));
  g2.assign(n, vi(0));
  d.assign(n, vi(n, INF));
  vis.assign(n, vi(n, 0));
  good.assign(n, 0);
  edges.clear();
  st.clear();
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g1[u].push_back(v);
    g1[v].push_back(u);
    edges.insert({min(u, v), max(u, v)});
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g2[u].push_back(v);
    g2[v].push_back(u);
    if (edges.find({min(u, v), max(u, v)}) != edges.end()) {
      good[u] = good[v] = 1;
    }
  }

  d[s1][s2] = 0;
  st.insert({0, {s1, s2}});
  while(!st.empty()) {
    int u, v;
    int dist = st.begin()->first;
    tie(u, v) = st.begin()->second;
    st.erase(st.begin());
    if (vis[u][v]) continue;
    vis[u][v] = 1;
    //cout << "visiting " << u << ", " << v << endl;
    for (auto a1 : g1[u]) {
      for (auto a2 : g2[v]) {
	int w = abs(a1 - a2);
	if (d[a1][a2] > d[u][v] + w) {
	  //st.erase({d[a1][a2], {a1, a2}});
	  d[a1][a2] = d[u][v] + w;
	  st.insert({d[a1][a2], {a1, a2}});
	}
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; ++i) {
    if (good[i]) {
      //cout << i << "i is good" << d[i][i] << endl;
      ans = min(ans, d[i][i]);
    }
  }
  cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
