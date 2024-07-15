#include <bits/stdc++.h>

void solve() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", (1 << __builtin_ctz(a^b)));
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) solve();
}
