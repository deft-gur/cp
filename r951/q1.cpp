#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int m = max(a[0], a[1]);
	for (int i = 1; i < n-1; ++i) {
		m = min(m, max(a[i],a[i+1]));
	}

	cout << m -1 << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) solve();
}
