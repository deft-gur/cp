#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi a, b;
int n;

void solve() {
  cin >> n;
  a.assign(n, 0); b.assign(n, 0);

  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  int cnt = 0;
  int need = 0;
  int resource = INT_MAX;
  for (int i = 0; i < n; ++i) {
    if (a[i] - b[i] >= 0) resource = min(resource, a[i] - b[i]);
    else { need = max(need, b[i] - a[i]); ++cnt;}
  }

  //cout << "cnt, resource, need" << cnt << "," << resource << "," << need << endl;

  if (cnt > 1 || resource < need) cout << "NO";
  else cout << "YES";
  cout << '\n';
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
