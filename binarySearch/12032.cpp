#include <bits/stdc++.h>

#define MX 100005

int a[MX];
int n;

int can(int m) {
	if (a[0] == m) --m;
	else if (a[0] > m) return false;
	for (int i = 0; i < n-1; ++i) {
		int dist = a[i+1] - a[i];
		//printf("dist: %d, m: %d\n", dist, m);
		if (dist == m) --m;
		else if (dist > m) return false;
	}
	return true;
}

int solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}

	int lo = 0, hi = 1e7, res = 0;

	while(lo < hi) {
		int mid = (hi + lo)/2;
		//printf("%d %d\n", lo, hi);
		//printf("%d \n", can(mid));
		can(mid) ? hi = mid : lo = mid+1;
	}
	return hi;
}

int main() {
	int t;
	scanf("%d", &t);
	int i = 1;
	for (int i = 1; i <= t; ++i) {
		printf("Case %d: %d\n", i, solve());
	}
}
