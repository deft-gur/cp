#include <bits/stdc++.h>

#define int long long
const int MX = 1e6+7;
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
vb prime, one;
int n, e;
vi a, vis;

void solve() {
  cin >> n >> e;
  a.assign(n, 0);
  one.assign(n, 0);
  vis.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1) one[i] = true;
  }

  int ans = 0;
  vi group;
  int curOnes;
  for (int i = 0; i < n; ++i) {
    group.clear();
    curOnes = 0;
    if (vis[i]) continue;
    for (int j = i; j < n; j += e) {
      vis[j] = 1;
      if (!one[j] && !prime[a[j]]) {
	break;
      }
      if (one[j]) {
	++curOnes;
      } else {
	group.push_back(curOnes);
	curOnes = 0;
      }
    }
    if (group.size() == 0) continue;
    group.push_back(curOnes);
    for (int j = 0; j < group.size(); ++j) {
      ans += group[j];
      if (j > 0 && j < group.size() - 1) {
	ans += group[j];
      }
      if (j < group.size() - 1) {
	ans += group[j] * group[j+1];
      }
    }
    //cout << group.size() << i << " " << ans << " ";
  }
  cout << ans << endl;
}

void init() {
  prime.assign(MX, true);
  prime[0] = prime[1] = 0;
  for (int i = 2; i*i < MX; ++i) if (prime[i]) {
    for (int j = i*i; j < MX; j += i) {
      prime[j] = 0;
    }
  }
}

int32_t main() {
  init();
  int t;
  cin >> t;
  while(t--) solve();
}
