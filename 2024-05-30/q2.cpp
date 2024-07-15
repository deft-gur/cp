#include <iostream>

using namespace std;

void solve() {
  long long n;
  cin >> n;
  long long a[n], b[n+1];
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n+1; ++i) {
    cin >> b[i];
  }

  long long ans = 0;
  long long flag = 0;
  long long closest = INT32_MAX;
  for (long long i = 0; i < n; ++i) {
    long long mx = max(a[i], b[i]);
    long long mn = min(a[i], b[i]);
    if (mn <= b[n] && b[n] <= mx) closest = 0;
    else { closest = min(min(abs(b[n] - a[i]), abs(b[n] - b[i])), closest); }
    ans += abs(a[i] - b[i]);
  }

  ans += 1 + closest;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
