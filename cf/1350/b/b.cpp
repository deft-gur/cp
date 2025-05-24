#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int n;
vi a, dp;

int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n;
    a.assign(n+1, 0); dp.assign(n+1, 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
      for (int j = i+i; j <= n; j+=i) {
	if (a[j] > a[i]) {
	  dp[j] = max(dp[j], dp[i]+1);
	}
      }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}
