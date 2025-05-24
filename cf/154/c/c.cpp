#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> ii;
typedef vector<ull> vi;
typedef vector<ii> vii;
ull n, m;
const ull B = 17;
const ull B2 = 37;
vi powB, powB2;
vii hashes, hashes2;

void init() {
  powB.assign(n, 0);
  powB2.assign(n, 0);
  powB[0] = 1;
  powB2[0] = 1;
  for (int i = 1; i < n; ++i) {
    powB[i] = powB[i-1] * B;
    powB2[i] = powB2[i-1] * B2;
  }
}

int main() {
  cin >> n >> m;
  init();
  hashes.assign(n, {0, 0});
  hashes2.assign(n, {0, 0});

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v; --u, --v;
    hashes[u].first += powB[v];
    hashes[u].second += powB2[v];
    hashes[v].first += powB[u];
    hashes[v].second += powB2[u];
    hashes2[u].first += powB[v];
    hashes2[v].first += powB[u];
    hashes2[u].second += powB2[v];
    hashes2[v].second += powB2[u];
  }

  for (int i = 0; i < n; ++i) {
    hashes2[i].first += powB[i];
    hashes2[i].second += powB2[i];
  }
  
  ull ans = 0;
  sort(hashes.begin(), hashes.end());
  int acc = 1;
  for (int i = 0; i < n-1; ++i) {
    if (hashes[i] == hashes[i+1]) { ans += acc; ++acc; }
    else acc = 1;
  }
  sort(hashes2.begin(), hashes2.end());
  acc = 1;
  for (int i = 0; i < n-1; ++i) {
    if (hashes2[i] == hashes2[i+1]) { ans += acc; ++acc; }
    else acc = 1;
  }

  cout << ans << '\n';
}
