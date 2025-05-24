#include <bits/stdc++.h>

using namespace std;

#define MX 30001
#define OFFSET 246
typedef vector<int> vi;
typedef vector<vi> vvi;
vvi dp;
vvi visited;
vi gems;
int n;
int d;
int mx;

int solution(int s, int l) {
  if (l <= -d || l >= OFFSET || s >= mx) return 0;
  if (visited[s][l+OFFSET]) return dp[s][l+OFFSET];
  visited[s][l+OFFSET] = 1;
  int sol = 0;
  for (int i = -1; i <= 1; ++i) {
    int next = s+d+l+i;
    sol = max(sol, solution(next, l+i) + gems[s]);
  }
  dp[s][l+OFFSET] = sol;
  return sol;
}


void solve() {
  dp.assign(MX, vi(OFFSET * 2+1, 0));
  visited.assign(MX, vi(OFFSET * 2+1, 0));
  cout << solution(d, 0) << endl;
}

int main() {
  gems.assign(MX, 0);
  cin >> n >> d;
  mx = 0;
  for (int i = 0; i < n; ++i) {
    int j; cin >> j; ++gems[j];
    mx = max(mx, j);
  }

  ++mx;
  solve();
}
