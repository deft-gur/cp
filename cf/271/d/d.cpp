#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef set<int> si;
const int mod = (int)1e10 + 7;
const int B = 19;
const int B2 = 23;
int n, k;
string s, good;
vi prefixSum, powB, powB2;

void init() {
  powB.assign(n, 0);
  powB2.assign(n, 0);
  powB[0] = 1;
  powB2[0] = 1;
  for (int i = 1; i < n; ++i) {
    powB[i] = (B * powB[i-1]) % mod;
    powB2[i] = (B2 * powB2[i-1]) % mod;
  }
}

int isBad(char c) {
  return (good[c-'a'] == '0') ? 1 : 0;
}

int32_t main() {
  cin >> s >> good >> k;
  n = s.size();
  init();
  prefixSum.assign(n+1, 0);
  prefixSum[0] = 0;
  for (int i = 1; i <= n; ++i) {
    prefixSum[i] = prefixSum[i-1] + isBad(s[i-1]);
  }

  vii counts;
  for (int i = 0; i < n; ++i) {
    int h = 0, h2 = 0;
    for (int j = i; j < n; ++j) {
      h += (((s[j] * powB[j-i]) % mod) + mod) % mod;
      h2 += (((s[j] * powB2[j-i]) % mod) + mod) % mod;
      h = h % mod;
      h2 = h2 % mod;
      if (prefixSum[j+1] - prefixSum[i] <= k) {
	counts.emplace_back(h, h2);
      } else break;
    }
  }
  sort(counts.begin(), counts.end());
  int ans = (counts.size() > 0 ? 1 : 0);
  for (int i = 1; i < counts.size(); ++i) {
    if (counts[i-1] != counts[i]) ++ans;
  }
  cout << ans << '\n';
}
