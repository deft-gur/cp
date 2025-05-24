#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
int n, m;
vi a, sums;

int32_t main() {
  cin >> n >> m;
  a.assign(n, 0);
  for (int i= 0; i < n; ++i) cin >> a[i];
  sums.assign(1ll << (n/2), 0);
  for (int i = 0; i < (1ll << (n/2)); ++i) {
    int sum = 0;
    for (int j = 0; j < 38; ++j) {
      if (i & (1ll << j)) sum = (sum + a[j]) % m;
    }
    sums[i] = sum;
  }
  sort(sums.begin(), sums.end());

  int offSet = n/2;
  int ans = 0;
  for (int i = 1; i < (1ll << (n - n/2)); ++i) {
    int sum = 0;
    for (int j = 0; j < 38; ++j) {
      if (i & (1ll << j)) {
	sum = (sum + a[j+offSet]) % m;
      }
    }
    int low = *(lower_bound(sums.begin(), sums.end(), m-sum)-1);
    ans = max(ans, sum + low);
  }
  ans = max(ans, sums[sums.size()-1]);
  cout << ans << '\n';
}
