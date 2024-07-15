#include <bits/stdc++.h>

#define MX 100005
#define ll long long
using namespace std;

int a[MX];
ll sum[MX];
int n;
int l, r;

void solve() {
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);

  sum[0] = 0;
  for (int i = 1; i <= n; ++i)
    sum[i] = sum[i-1] + a[i-1];


  int start = 1;
  int win = 0;
  while(start <= n) {
    auto low = lower_bound(sum+start, sum+n+1, sum[start-1] + l);
    //cout << "start:" << start << endl;
    //cout << "low:" << low-sum << endl;
    //cout << "sum[start-1]+r" << sum[start-1]+r << endl;
    //cout << "*low" << *low << endl;
    if (low == sum+n+1) break;
    if (*low <= sum[start-1] + r) {
      //cout << "-----opt: start:" << start << endl;
      ++win;
      start = low - sum + 1;
    } else {
      auto tmp = lower_bound(sum+start, sum+n+1, *low - r);
      start = tmp - sum + 1;
    }
  }
  printf("%d\n", win);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    solve();
  }
}
