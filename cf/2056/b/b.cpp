#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, n;
vvi grid;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    grid.assign(n, vi(n, 0));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
	char c; cin >> c;
	if (c == '1') grid[i][j] = 1;
      }

    vi ans;
    ans.push_back(0);
    for (int i = 1; i < n; ++i) {
      int j = 0;
      for (; j < ans.size(); ++j) {
	int pj = ans[j];
	if (grid[i][pj] == 0) {
	  ans.insert(ans.begin()+j, i);
	  break;
	}
      }
      if (j==ans.size()) ans.push_back(i);
    }

    for (int i = 0; i < n; ++i) {
      cout << ans[i] + 1 << " ";
    }
    cout << '\n';
  }
}
