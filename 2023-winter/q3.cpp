#include <bits/stdc++.h>

using namespace std;

#define mx 500000 + 5
int a[mx];
int ans[mx];
set<pair<int, int>> s;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s.insert(make_pair(a[i], i));
  }

  int adds= 0;
  int ep = 0;
  for (int i = 0; i < n; ++i) {
    pair<int,int> t = *s.rbegin();
    if (t.first + adds < n-1) {
      break;
    }
    ep = i;
    s.erase(t);
    t.first = t.first - n;
    s.insert(t);
    ++adds;
  }

  if (ep == n-1) {
    printf("Recurrent\n");
    return 0;
  }
  for (auto e : s) {
    ans[e.second] = e.first + adds;
  }
  for (int i = 0; i  < n; ++i) {
    printf("%d%c", ans[i], i == n-1 ? '\n' : ' ');
  }
}
