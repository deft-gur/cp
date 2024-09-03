#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n;
vvi AL;
vi vis, match;
vi l;

int aug(int L) {
  if (vis[L]) return 0;
  vis[L] = 1;
  for (auto &R : AL[L]) {
    if ((match[R] == -1) || aug(match[R])) {
      match[R] = L;
      l[L] = R;
      return 1;
    }
  }
  return 0;
}

int MaxMatch() {
  int m = 0;
  match.assign(2*n, -1);
  l.assign(n, -1);
  while (true) {
    bool updated = false;
    vis.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      int tmp = 0;
      if (l[i] == -1) tmp = aug(i);
      if (tmp) updated = true;
      m += tmp;
    }
    if (!updated) break;
  }
  return m;
}

void solve() {
  cin >> n;
  int p, q;

  AL.assign(n, vi());

  for (int i = 0; i < n; ++i) {
    cin >> p >> q;
    --q, --p;
    AL[i].push_back(p);
    if (p != q) AL[i].push_back(q);
  }

  int m = MaxMatch();
  cout << (m == n ? "possible" : "impossible") << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) solve();
}
