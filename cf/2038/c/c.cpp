#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
vi points, deleted;
int n;

void solve() {
  cin >> n;
  points.assign(n, 0);
  deleted.assign(n, 0);
  for (int i=0; i < n; ++i) cin >> points[i];

  sort(points.begin(), points.end());

  int del = 0;
  vi candidate;
  for (int i = 0; i < n-1; ++i) {
    if (points[i] == points[i+1]) {
      candidate.push_back(points[i]);
      deleted[i] = 1;
      deleted[i+1] = 1;
      ++i;
      del+=2;
    }
    if (del == 4) break;
  }

  for (int i = n-1; i > 0 ; --i) {
    if (deleted[i] == 1 || deleted[i-1] == 1) break;
    if (points[i] == points[i-1]) {
      candidate.push_back(points[i]);
      deleted[i] = 1;
      deleted[i-1] = 1;
      --i;
      del+=2;
    }
    if (del == 8) break;
  }

  if (del != 8) { cout << "NO\n"; return; }

  cout << "YES\n";
  sort(candidate.begin(), candidate.end());
  printf("%d %d %d %d ", candidate[0], candidate[1], candidate[2], candidate[1]);
  printf("%d %d %d %d\n", candidate[0], candidate[3], candidate[2], candidate[3]);
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
