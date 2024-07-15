#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n; long long k;
  cin >> n >> k;
  vector<long long> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
 

  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());

  long long last = a.back(), cnt = 1;
  a.pop_back();
  while(!a.empty() && last == a.back()) a.pop_back(), ++cnt;

  long long nxt;
  long long need;
  while(!a.empty()) {
     nxt = a.back();
     need = (nxt - last) * cnt;
     if (k < need) break;
     k -= need;
     last = nxt;
     while(!a.empty() && last == a.back()) a.pop_back(), ++cnt;
  }

  last += k/cnt;
  k %= cnt;
  cnt -= k;
  //cout << (last * n) - n + (n - cnt) + 1 << endl;
  cout << (last * n) - cnt + 1 << endl;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
