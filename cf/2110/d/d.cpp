#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;

const int MX = 1e9+1;
int n, m;
vvii g;
vi b, sum;

ii dfs(int s, int a) {
  if (s == n-1) return make_pair(1, 0);

  int ans = MX;
  int succeed = 0;
  for (auto [t, w] : g[s]) {
    if (a >= w) {
      auto [x, y] = dfs(t, a+b[t]);
      if (x == 1) {
	succeed = 1;
	ans = min(max(w, y), ans);
      }
    }
  }
  return make_pair(succeed, ans);
}

int dijkstra(int s, int t) {
  vi dist(n, MX);
  vi avai(n, 0);
  auto greater = [](const iii &a, const iii &b) { return get<1>(a) > get<1>(b); };
  priority_queue<iii, viii, decltype(greater)> pq(greater);
  dist[s] = 0;
  avai[s] = b[s];
  pq.emplace(s, 0, b[s]);

  int ans = MX;
  while(!pq.empty()) {
    auto [u, c, a] = pq.top(); pq.pop();
    //cout << "looking at " << u << endl;
    if (u == t) return c;

    for (auto [v, w] : g[u]) {
      //cout << "edge " << u << " "<< v << endl;
      int newMax = max(c, w);
      if ((newMax < dist[v] || a > avai[v]) && a >= w) {
	//cout << "insert" << v << " " << newMax << " " << a + b[v] << endl;
	dist[v] = min(newMax, dist[v]);
	avai[v] = max(a, avai[v]);
	pq.emplace(v, newMax, a + b[v]);
      }
    }
  }
  return ans;
}

void solve() {
  cin >> n >> m;
  b.assign(n, 0);
  g.assign(n, vii(0));
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int s, t, w;
  for (int i = 0; i < m; ++i) {
    cin >> s >> t >> w;
    g[--s].emplace_back(--t, w);
  }
  //auto [succeed, ans] = dfs(0, b[0]);
  //cout << (succeed == 1 ? ans : -1) << '\n';
  int ans = dijkstra(0, n-1);
  cout << (ans == MX ? -1 : ans) << '\n';
}

int32_t main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
