#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int n;
vi a;
vi T;

#define L(i) 2 * i + 1
#define R(i) 2 * i + 2
#define par(i) (i - 1)/2

void build(int i, int tl, int tr) {
  if (tl == tr) {
    T[i] = a[tl];
    return;
  }
  int tm = (tl + tr)/2;
  build(L(i), tl, tm);
  build(R(i), tm+1, tr);
  T[i] = T[L(i)] + T[R(i)];
}

int query(int i, int tl, int tr, int l, int r) {
  if (l > r) return 0;

  if (tl == l && tr == r) return T[i];

  int tm = (tl + tr)/2;
  int resL = query(L(i), tl, tm, l, min(tm, r));
  int resR = query(R(i), tm+1, tr, max(tm+1, l), r);
  return resL + resR;
}

int query(int l, int r) {
  return query(0, 0, n-1, l, r);
}

void update(int newVal, int idx, int v, int tl, int tr) {
  if (tl == tr) T[v] = newVal;

  int tm = (tl + tr)/2;
  if (idx <= tm) update(newVal, idx, L(v), tl, tm);
  else update(newVal, idx, R(v), tm+1, tr);

  T[v] = T[L(v)] + T[R(v)];
}


void update(int newVal, int idx) {
  update(newVal, idx, 0, 0, n-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  n = 4;
  // cin >> n;
  //a.resize(n);
  //for (int i = 0; i < n; ++i) cin >> a[i];
  // a = [8,9,-10,-20];
  a.push_back(8);
  a.push_back(9);
  a.push_back(-10);
  a.push_back(-20);
  T.assign(4*n, 0);

  build(0, 0, n-1);
  cout << query(0, 3) << endl;
  cout << query(2, 3) << endl;
  cout << query(1, 2) << endl;
  cout << query(1, 1) << endl;
}
