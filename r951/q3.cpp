#include <bits/stdc++.h>

using namespace std;

#define MX 55
#define ll long long
ll a[MX];
ll res[MX];
ll k[MX];

ll lcm(ll a, ll b) {
	return a * b / __gcd(a,b);
}
void solve() {
	int n;
	cin >> n;
	ll p = 1;
	memset(k, 0, sizeof(k));
	memset(res, 0, sizeof(res));
	memset(a, 0, sizeof(a));

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		p = lcm(p, a[i]);
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		res[i] = p / a[i];
		sum += res[i];
	}

	if (sum < p) {
		for (int i = 0; i < n; ++i)
			cout << res[i] << " ";
		cout << "\n";
	} else {
		cout << "-1\n";
	}
}

signed main() {
	int t;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--) solve();
}
