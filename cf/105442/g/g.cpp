#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
int n;
//vi primes, dp;
map<int, int> dp;
int const MX = 1e9 + 5;

//void init() {
//  primes.assign(n+1, 1);
//  primes[0] = 0;
//  primes[1] = 0;
//  for (int i = 2; i * i <= n; ++i) {
//    if (primes[i]) {
//      for (int j = i * i; j <= n; j+=i) {
//	primes[j] = 0;
//      }
//    }
//  }
//}

int isPrime(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int findLongest(int n) {
  if (dp.find(n) != dp.end()) return dp[n];
  if (isPrime(n) == 0) return dp[n] = 0;
  if (n < 10) return dp[n] = isPrime(n);
  int ans = 0;
  int len = to_string(n).length();
  for (int i = 0; i < len; ++i) {
    string s = to_string(n); s.erase(i, 1);
    ans = max(ans, findLongest(stoi(s)));
  }
  if (isPrime(n)) ++ans;
  return dp[n] = ans;
}

int32_t main() {
  cin >> n;
  //dp.assign(n+1, -1);
  //init();
  cout << findLongest(n) << endl;
}
