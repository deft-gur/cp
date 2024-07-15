#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<char> s;
  map<char, int> set;
  vector<char> unique;
  for (int i= 0; i < n; ++i) {
    char c;
    cin >> c;
    s.push_back(c);
  }
  vector<char> rev{s};

  for (int i = 0; i < n; ++i) {
    char c = rev[i];
    if (set.find(c) == set.end()){
      set[c] = set.size();
      unique.push_back(c);
    }
  }
  sort(unique.begin(), unique.end());
  for (int i =0; i < set.size(); ++i) {
    set[unique[i]] = i;
  }

  for (int i = 0; i < n; ++i) {
    cout << unique[set.size() - (set.find(s[i]))->second - 1];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}
