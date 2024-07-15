#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
vll buf(1,1);

void init() {
	ll tmp = 1;
	ll thres = 1L << 31;
	int j = 0, i = 0;
	while (tmp <= thres) {
		tmp = min(buf[i] * 2, buf[j] * 3);
		buf.push_back(tmp);
		if (buf[i] * 2 == tmp) ++i;
		if (buf[j] * 3 == tmp) ++j;
	}
}


signed main() {
	init();
	int n;
	while (scanf("%d", &n)) {
		if (n == 0) return 0;
		cout << *lower_bound(buf.begin(), buf.end(), n) << endl;
	}
}
