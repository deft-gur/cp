#include <bits/stdc++.h>

using namespace std;

void solve(int e) {
	int r;
	scanf("%d", &r);
	--r;
	int a[r];
	for (int i = 0; i < r; ++i) {
		scanf("%d", &a[i]);
	}
	int sum = 0;
	int s = 0;
	int l = 0;
	int maxl = 0;
	int maxs = 0;
	int maxStart = 0;
	for (int i = 0; i < r; ++i) {
		if (sum < 0) {
			s = i;
			l = 0;
			sum = 0;
		}

		sum += a[i];
		++l;
		if (maxs < sum || (maxs == sum && maxl < l)) {
			maxs = sum;
			maxStart = s;
			maxl = l;
		}
	}
	if (maxl > 0) printf("The nicest part of route %d is between stops %d and %d\n", e, maxStart+1, 1+maxStart + maxl);
	else printf("Route %d has no nice parts\n", e);
}

int main() {
	int b;
	scanf("%d", &b);
	for (int i = 1; i <= b; ++i) {
		solve(i);
	}
}
