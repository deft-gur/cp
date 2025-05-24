#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, vi> mvi;
vi s;
int n;
const int K = 25;
vvi table;
mvi occMap;
int T = 0;

int logfloor(int i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int occurence(int l, int r, int val) {
  vi &V = occMap[val];
  auto lIdx = lower_bound(V.begin(), V.end(), l);
  auto rIdx = upper_bound(V.begin(), V.end(), r);
  return rIdx - lIdx;
}

void solve() {
  ++T;
  int l, r;
  cin >> l >> r;
  --l, --r;
  if (l == r) {
    cout << 0 << endl;
    return;
  }
  int i = logfloor(r-l+1);
  int num = 0;
  if (table[i][l] % table[i][r - (1 << i)+1] == 0) {
    num = table[i][r-(1<<i)+1];
  } else if (table[i][r - (1 << i)+1] % table[i][l] == 0) {
    num = table[i][l];
  } else {
    num = 1;
  }
  int ans = occurence(l, r, num);
  cout << (r-l+1) - ans << endl;
}

void init() {
  for (int j = 0; j < n; ++j) {
    table[0][j] = s[j];
  }
  for (int k = 1; k < K; ++k) {
    for (int j = 0; j + (1 << k) <= n; ++j) {
      table[k][j] = gcd(table[k-1][j], table[k-1][j + (1<<(k-1))]);
    }
  }
}

int32_t main() {
  cin >> n;
  s.assign(n, 0);
  table.assign(K, vi(n, 0));
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    occMap[s[i]].push_back(i);
  }
  init();
  int t;
  cin >> t;
  while(t--) solve();
}
