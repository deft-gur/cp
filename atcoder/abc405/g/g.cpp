#include <bits/stdc++.h>

using namespace std;
#define int long long
#define _1 first
#define _2 second
#define L(x) 2ll*x+1
#define R(x) 2ll*x+2
#define P(x) (x-1)/2
typedef tuple<int, int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<int> vi;

const int MX = 2.6e5;
const int mod = 998244353;
int n,q;
viii queries;
vi a, b, fact, inv;
vii ans, seg;

int modpow(int a, int b) {
  int x = a;
  int ans = 1;
  while(true) {
    if (b % 2 == 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    b = (b>>1);
    if (b == 0) return ans;
  }
}

int inverse(int x) {
  return modpow(x, mod-2);
}

void init() {
  fact.assign(MX, 1);
  inv.assign(MX, 1);
  for (int i = 1; i < MX; ++i) {
    fact[i] = (fact[i-1] * i) % mod;
    inv[i] = (inverse(i)) % mod;
  }
}

void update(int idx, int val, int tidx, int tl, int tr) {
  //printf("%d %d %d %d %d \n", idx, val, tidx, tl, tr);
  if (tl == tr) {
    if (val < 0) {
      seg[tidx]._2 = (seg[tidx]._2 * seg[tidx]._1) % mod;
    } else {
      seg[tidx]._2 = (seg[tidx]._2 * inv[seg[tidx]._1 + 1]) % mod;
    }
    seg[tidx]._1 = seg[tidx]._1 + val;
    return;
  }

  int tm = (tl + tr) / 2;
  if (idx <= tm) update(idx, val, L(tidx), tl, tm);
  else update(idx, val, R(tidx), tm+1, tr);
  seg[tidx]._1 = seg[L(tidx)]._1 + seg[R(tidx)]._1;
  seg[tidx]._2 = (seg[L(tidx)]._2 * seg[R(tidx)]._2) % mod;
}

void update(int idx, int val) {
  update(idx, val, 0, 0, n-1);
}

ii query(int i, int tl, int tr, int l, int r) {
  //printf("seg query %d %d %d %d %d \n", i, tl, tr, l, r);
  if (l > r) return {0, 1};
  if (tl > tr) return {0, 1};
  if (tl == l && tr == r) return seg[i];

  int tm = (tl + tr)/2;

  ii a1 = query(L(i), tl, tm, l, min(r, tm));
  ii a2 = query(R(i), tm+1, tr, max(l, tm+1), r);
  return {a1._1 + a2._1, (a1._2 * a2._2) % mod};
}

ii query(int l, int r) {
  return query(0, 0, n-1, l, r);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  init();
  cin >> n >> q;
  queries.assign(q, make_tuple(0, 0, 0, 0));
  a.assign(n, 0);
  b.assign(n, 0);
  ans.assign(q, {0, 0});
  seg.assign(4*n+1, {0, 1});
  for (int i = 0; i < n; ++i) { cin >> a[i]; a[i]--; }
  for (int i = 0; i < q; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    --l, --r, --x;
    queries[i] = make_tuple(l, r, x, i);
  }
  
  sort(queries.begin(), queries.end());
  int c_l=0, c_r=0;
  int i = 0;
  update(a[0], 1);
  for (auto q : queries) {
    int l, r, x, id;
    tie(l, r, x, id) = q;
    //printf("query %d %d %d %d\n", l, r, x, id);
    while(c_l > l) {
      update(a[--c_l], 1);
    }
    while(c_l < l) {
      update(a[c_l++], -1);
    }
    while (c_r > r) {
      update(a[c_r--], -1);
    }
    while (c_r < r) {
      update(a[++c_r], 1);
    }
    auto [sum, denom] = query(0, x-1);
    //printf("sum, denom, ans, %d %d %d \n", sum, denom, (fact[sum]*denom)%mod);
    ans[i++] = make_pair(id, (fact[sum] * denom)%mod);
  }
  sort(ans.begin(), ans.end());
  for (auto [idx, val] : ans) {
    cout << val << '\n';
  }
}
