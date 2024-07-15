#include <bits/stdc++.h>

#define MX 21
using namespace std;
double k[MX], c[MX];
int n;
double t;

double f(double p) {
	double cheater = p/k[n-1] + (t - p)/c[n-1];
	double fast = DBL_MAX;
	for (int i = 0; i < n - 1; ++i) {
		fast = min(fast, p/k[i] + (t - p)/c[i]);
	}
	return (fast - cheater) * 3600;
}

int main() {
	while (cin >> t) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> k[i] >> c[i];

		double lo = 0, hi = t;
		double eps = 1e-8;
		while (hi - lo > eps) {
			//cout << "Hi" << hi << "lo " << lo << endl;
			double delta = (hi - lo)/3;
			double m1 = lo + delta, m2 = hi - delta;
			//double m1 = (hi + 2 * lo)/3, m2 = (2*hi + lo)/3;
			//cout << "m1" << m1 << "m2 " << m2 << endl;
			//cout << "f(m1):" << f(m1) << "f(m2):" << f(m2) << endl;
			if (f(m1) > f(m2)) hi = m2;
			else lo = m1;
		}
		if (f(lo) > 0)
			printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n", int(f(lo)+0.5), lo, t-lo);
		else
			printf("The cheater cannot win.\n");
	}
}
