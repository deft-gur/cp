#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxn = 4000100;
const int N = 1000000;

int n, a[maxn], pr[maxn], tot, stk[maxn], top;
bool vis[maxn];

inline void init() {
  for (int i = 2; i <= N; ++i) {
      if (!vis[i]) {
            pr[++tot] = i;
          }
      for (int j = 1; j <= tot && i * pr[j] <= N; ++j) {
            vis[i * pr[j]] = 1;
            if (i % pr[j] == 0) {
                    break;
                  }
          }
    }
  mems(vis, 0);
}

