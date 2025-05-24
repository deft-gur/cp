#include <bits/stdc++.h>

using namespace std;
typedef unordered_map<int, int> mapii;
typedef vector<int> vi;
vi a;
mapii m;
int n, k;

int main() {
  cin >> n >> k;
  if (k == 0) { cout << 0 << endl; return 0; }
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int L = 0;
  int uniq = 0;
  long long ans = 0;
  for (int R = 0; R < n; ++R) {
    if(m[a[R]] == 0) ++uniq;
    m[a[R]]++;
    while(uniq > k) {
      m[a[L]]--;
      if (m[a[L]] == 0) --uniq;
      ++L;
    }
    ans += R - L + 1;
  }
  cout << ans << endl;
}
