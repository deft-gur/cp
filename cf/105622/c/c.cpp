#include <bits/stdc++.h>

using namespace std;

vector<int> childs;
vector<int> parent;
int n;

int main() {
  cin >> n;
  childs.assign(n+1, 0);
  parent.assign(n+1, 0);
  int p;
  for (int i = 2; i <= n; ++i){
    cin >> p;
    parent[i] = p;
    ++childs[p];
  }

  cout << 1;
  for (int i = 2; i <= n; ++i) {
    cout << (childs[parent[i]] == 1 ? 0 : 1);
  }
  cout << '\n';
}
