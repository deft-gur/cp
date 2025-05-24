#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef stack<int> si;

void solve() {
  si s;
  string c;
  cin >> c;
  bool flag1 = false;
  bool flag2 = false;
  for (int i = 0; i < c.length(); ++i) {
    if (flag1 == true && s.size() == 0) { cout << "YES" << endl; return; } 
    flag1 = true;
    if (s.size() != 0 && ((s.top() == '(' && c[i] == ')') || (s.top() == ')' & c[i] == '('))) s.pop();
    else s.push(c[i]);
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
