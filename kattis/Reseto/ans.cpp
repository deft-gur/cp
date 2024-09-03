#include <bits/stdc++.h>

#define MX 100005
using namespace std;
typedef long long ll;


ll n, k;
ll ans;
ll p[MX];

void sieve() {
  fill(p, p+n+1, 1);
  p[0] = p[1] = 0;
  ll counter = 0;
  for (ll i = 2; i <= n; ++i) {
    if (p[i]) {
      ++counter;
      if (counter == k) ans = i;
      for (ll j = i * i; j <= n; j+=i) {
	if (p[j]) {
	  p[j] = 0;
	  ++counter;
	  if (counter == k) ans = j;
	}
      }
    }
  }
}

int main() {
  cin >> n >> k;
  sieve();
  cout << ans << '\n';
}
