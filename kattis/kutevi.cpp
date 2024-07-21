#include <bits/stdc++.h>

using namespace std;

// Using number theory.
// alpha . v = s iff s is multiple of gcd(v)
// Where alpha and v are vectors and s is a number.
/*
void solve() {
  int n, k;
  cin >> n >> k;
  int g = 360;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    g = __gcd(g, tmp);
  }
  for (int i = 0; i < k; ++i) {
    int tmp;
    cin >> tmp;
    cout << (tmp % g == 0 ? "YES" : "NO") << endl;
  }
}
*/


// Now use dp
int dp[360];
int a[10];
int n, k;

void dpFn(int v) {
  if (dp[v]) return;
  dp[v] = 1;
  for (int i = 0; i < n; ++i) {
    dpFn((v + a[i]) % 360);
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  dpFn(0);

  for (int i = 0; i < k; ++i) {
    int tmp;
    cin >> tmp;
    cout << (dp[tmp] ? "YES" : "NO") << endl;
  }
}

int main() {
  int t;
  solve();
}
