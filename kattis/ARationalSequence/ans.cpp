#include <bits/stdc++.h>

using namespace std;

pair<int, int> F(int p, int q) {
  if (q == 1) return {1, p+1};
  if (p < q) return {q, q - p};
  int lvl = p/q;
  int numParent = p % q;
  int denomParent = q;
  int denom = (denomParent - numParent) + lvl * (denomParent);
  return {q, denom};
}

void solve() {
  int k, p, q;
  scanf("%d %d/%d\n", &k, &p, &q);

  tie(p, q) = F(p, q);
  
  printf("%d %d/%d\n", k, p, q);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) solve();
}
