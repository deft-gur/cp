#include <bits/stdc++.h>

using namespace std;
#define MX 100000
int n, l, w;
#define pi pair<int, int>
#define vii vector<pi>

const double EPS = 1e-9;

struct sp{
	int x, r;
	double x_l, x_r;
} s[MX];

bool cmp(sp a, sp b) {
	if (fabs(a.x_l - b.x_l) > EPS) return a.x_l < b.x_l;
	else return a.x_r < b.x_r;
}

int main() {
	while (scanf("%d %d %d", &n, &l, &w) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &s[i].x, &s[i].r);
			if (s[i].r > w/2) {
				double d = sqrt(double(s[i].r * s[i].r) - w * w /4.0);
				s[i].x_l = max(0.0, s[i].x - d);
				s[i].x_r = min(double(l), s[i].x + d);
			} else {
				s[i].x_r = s[i].x_l = s[i].x;
			}
		}
		sort(s, s+n, cmp);
		//for (int i = 0; i < n; ++i) {
		//	printf("%f %f\n", s[i].x_l, s[i].x_r);
		//}
		double covered = 0.0;
		int count = 0;
		int i = 0;
		int possible = true;
		while (i < n) {
			if (fabs(covered - l) < EPS) break;
			int valid = -1;
			double longest = -1.0;
			for (int j = i; j < n; ++j) {
				if (s[j].x_l < covered + EPS) {
					longest = max(s[j].x_r, longest);
					if (longest == s[j].x_r) valid = j;
				}
				else break;
			}
			if (valid == -1) {
				possible = false;
				//printf("impossible\n");
				break;
			}
			covered = s[valid].x_r;
			i = valid + 1;
			count++;
		}
		if (fabs(covered - l) < EPS) printf("%d\n", count);
		else printf("-1\n");
	}
}
