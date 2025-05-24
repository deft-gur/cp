#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef complex<ll> point;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define mx (int)1e5 + 5
#define C mx
#define inf (ll)1e18
int n;
vvi g;
ll a[mx];
ll b[mx];
ll dp[mx];

struct Line {
  ll m, b;
  ll operator()(ll x) { return m * x + b; }
};

struct Node {
  Line seg;
  Node *l, *r;
  Node(Line _seg) : seg(_seg), l(nullptr), r(nullptr) {}
};

void insert(ll l, ll r, Line seg, Node *o) {
  if (l + 1 == r) {
    if (seg(l) < o->seg(l)) o->seg = seg;
    return;
  }
  ll mid = (l+r) >> 1;
  if (seg.m < o->seg.m) swap(seg, o->seg);
  if (o->seg(mid) > seg(mid)) {
    swap(seg, o->seg);
    if (o->r) insert(mid, r, seg, o->r);
    else o->r = new Node(seg);
  } else {
    if (o->l) insert(l, mid, seg, o->l);
    else o->l = new Node(seg);
  }
}

ll query(ll l, ll r, ll x, Node *o) {
  if (l + 1 == r) return o->seg(x);
  ll mid = (l+r) >> 1;
  if (x < mid && o->l) { return min(o->seg(x), query(l, mid, x, o->l)); }
  else if (x > mid && o->r) { return min(o->seg(x), query(mid, r, x, o->r)); }
  else return o->seg(x);
}

void merge(Node *dest, Node *old) {
  if (old->seg.b == inf) return;
  insert(-C, C, old->seg, dest);
  if (old->l) merge(dest, old->l);
  if (old->r) merge(dest, old->r);
}

void del(Node *o) {
  if (o->l) del(o->l);
  if (o->r) del(o->r);
  delete o;
}

pair<int, Node*> dfs(int u, int p) {
  int sz = 0;
  Node *root = new Node({0, inf});
  for (auto v : g[u]) {
    if (v == p) continue;
    auto [szz, son] = dfs(v, u);
    if (sz < szz) swap(root, son);
    merge(root, son);
    sz += szz;
  }

  dp[u] = (sz ? query(-C, C, a[u], root) : 0);
  insert(-C, C, {b[u], dp[u]}, root);
  return {sz + 1, root};
}

int main() {
  cin >> n;
  int u, v;
  g.assign(n, vi(0));
  for (int i = 0; i < n; ++i) { cin >> a[i]; }
  for (int i = 0; i < n; ++i) { cin >> b[i]; }
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto [s, o] = dfs(0, -1);
  del(o);
  for (int i = 0; i < n; ++i) {
    cout << dp[i] << " ";
  }
  cout << endl;
}
