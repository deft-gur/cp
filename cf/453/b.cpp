#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
int n;
vi a;
int dp[101][(1 << 17)];
int fact[60];
vvi ans;
vvi oldAns;
vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

void init() {
  for (int i = 2; i < 60; ++i) {
    for (int j = 0; j <= 16; ++j) {
      if (gcd(i, primes[j]) != 1) { fact[i] = fact[i] | (1 << j); }
    }
  }
}

int main() {
  init();
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cin >> n;
  a.assign(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 0; j < (1 << 17); ++j) {
      dp[i][j] = 1e9;
    }
  }

  ans.assign(1 << 17, vi());
  oldAns.assign(1 << 17, vi());
  for (int j = 0; j < (1 << 17); ++j) {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int b = 1; b < 60; ++b) {
      int comp = ~fact[b] & ((1 << 17) - 1);
      for (int s = comp; ; s = (s - 1) & comp) {
	if (s == 0) break;
	if (dp[i-1][s] + abs(a[i] - b) < dp[i][s | fact[b]]) {
	  dp[i][s | fact[b]] = dp[i-1][s] + abs(a[i] - b);
	}
      }
    }
  }

  int min = 1e9, minidx = 0;
  for (int j = 0; j < (1 << 17); ++j) {
    if (min > dp[n][j]) {
      minidx = j; min = dp[n][j];
    }
  }

  // Retrieve back answer.
  vi bs; bs.assign(n, 0);
  int m = minidx;
  for (int i = n; i > 0; --i) {
    for (int b = 1; b < 60; ++b) {
      if ((b != 1) && ((m & fact[b]) != fact[b])) continue;
      int rest = m ^ fact[b];
      if (min == (dp[i-1][rest] + abs(a[i] - b))) {
	bs[i-1] = b; m = rest; min = dp[i-1][rest];
	break;
      }
    }
  }

  for (auto b : bs) {
    cout << b << ' ';
  }
  cout << '\n';
}
