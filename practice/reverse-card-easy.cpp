#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    for (long long i = 1; i <= m; ++i) {
      for (long long j = i; j <= n; j+=i) {
        long long sum = i + j;
        if (sum %i == 0 && sum%(i * __gcd(i,j)) == 0) ++ ans;
        //if ((i + j) % (j * __gcd(i,j)) == 0) ++ans;
      }
    }
    cout << ans << endl;
  }
}
