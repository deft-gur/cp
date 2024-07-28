// nlogn algorithm since at each iteration we decrease the mx and mn by half.
#include <bits/stdc++.h>

using namespace std;

#define MX 200005
#define INF 1000000000

int n;
int a[MX];


int minV(int *a, int n) {
  int m = INF;
  for (int i = 0; i < n; ++i) {
    m = min(a[i], m);
  }
  return m;
}

int maxV(int *a, int n) {
  int m = 0;
  for (int i = 0; i < n; ++i) {
    m = max(a[i], m);
  }
  return m;
}

void solve() {
  bool sameParity = true;

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n-1; ++i) sameParity &= (a[i] % 2 == a[i+1] % 2);
  if (!sameParity) {
    cout << -1 << endl;
    return;
  }

  vector<int> seq;
  int mn = minV(a, n);
  int mx = maxV(a, n);
  while(mx != 0) {
    int avg = ceil((float)(mn + mx)/2);
    seq.push_back(avg);
    for (int i = 0; i < n; ++i) {
      a[i] = abs(a[i] - avg);
    }
    mn = minV(a, n);
    mx = maxV(a, n);
  }

  cout << seq.size() << endl;
  for (auto v : seq) cout << v << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
