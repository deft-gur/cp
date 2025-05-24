#include <bits/stdc++.h>

using namespace std;
#define int long long
#define par(x) (x-1)/2
#define L(x) 2*x+1
#define R(x) 2*x+2
typedef vector<int> vi;
vi T;
vi a;
int n;

void build(int node, int tl, int tr) {
  if (tl == tr) { T[node] = a[tl]; return; }
  int tm = (tl+tr)/2;
  build(L(node), tl, tm);
  build(R(node), tm+1, tr);
  T[node] = T[L(node)] + T[R(node)];
}

void update(int idx, int val, int node, int tl, int tr) {
  if (tl == tr) { T[node] = val; return; }

  int tm = (tl+tr)/2;
  if (idx <= tm) update(idx, val, L(node), tl, tm);
  else update(idx, val, R(node), tm+1, tr);

  T[node] = T[L(node)] + T[R(node)];
}

void update(int idx, int val) {
  update(idx, val, 0, 0, n-1);
}

int query(int node, int l, int r, int tl, int tr) {
  if (l > r) return 0;
  if (l == tl && r == tr) return T[node];
  int tm = (tl+tr)/2;
  return query(L(node), l, min(r, tm), tl, tm) +
	 query(R(node), max(l, tm+1), r, tm+1, tr);
}

int query(int l, int r) {
  return query(0, l, r, 0, n-1);
}

int32_t main() {
  int m;
  cin >> n >> m;
  T.assign(4*n, 0);
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  build(0, 0, n-1);
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(b, c);
    } else {
      cout << query(b, c-1) << '\n';
    }
  }
}
