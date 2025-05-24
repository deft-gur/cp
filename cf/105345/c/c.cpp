#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; string s;
  cin >> n >> s;
  
  int ones = 0;
  int zeros = 0;
  int i = 0;
  while(i < n) {
    int j = i+1;
    for (; j < n; ++j) {
      if (s[j] != s[i]) break;
    }
    if (s[i] == '1') ++ones;
    else ++zeros;
    i = j;
  }
  cout << min(ones, zeros) << endl;
}
