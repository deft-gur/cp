#include <bits/stdc++.h>

using namespace std;

#define MXG 27
#define MXM 207

int memo[MXG][MXM];
int gar[MXG][MXG];
int garS[MXG];
int m, c;

int dp(int g, int v) {
	if (v < 0) return -1;
	if (g == c) return m - v;
	if (memo[g][v] != -1) return memo[g][v];

	for (int i = 0; i < garS[g]; ++i) {
		memo[g][v] = max(memo[g][v], dp(g+1, v-gar[g][i]));
	}

	return memo[g][v];
}

void solve() {
	memset(memo, -1, sizeof(memo));
	scanf("%d %d", &m, &c);
	for (int i = 0; i < c; ++i) {
		scanf("%d", &garS[i]);
		for (int j = 0; j < garS[i]; ++j) {
			scanf("%d", &gar[i][j]);
		}
	}
	int ans = dp(0, m);
	if (ans > 0) printf("%d\n", ans);
	else printf("no solution\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		solve();
	}
}
