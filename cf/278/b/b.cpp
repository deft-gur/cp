#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> strs;

string update(string s, int idx) {
  size_t len = s.length();
  if (s[len+idx] == 'z') {
    if (idx == -1 * len) {
      return string(len+1, 'a');
    }
    s[len+idx] = 'a';
    return update(s, idx-1);
  } else {
    s[len+idx]++;
    return s;
  }
}

bool in(string s) {
  int slen = s.length();
  for (int i = 0; i < n; ++i) {
    int len = strs[i].length();
    for (int j = 0; j <= len-slen; ++j) {
      if (s == strs[i].substr(j, slen)) return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  strs.assign(n, "");
  for (int i = 0; i < n; ++i) {
    cin >> strs[i];
  }
  string ans = "a";
  while (true) {
    if (!in(ans)) break;
    ans = update(ans, -1);
  }
  cout << ans << endl;
}
