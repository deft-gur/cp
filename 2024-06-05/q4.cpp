#include <bits/stdc++.h>

using namespace std;

bool good(vector<int> &b) {
  int g = __gcd(b[0], b[1]);
  for (int i = 1; i < b.size() -1; ++i) {
    int tmp = __gcd(b[i], b[i+1]);
    if (g > tmp) return false;
    g = tmp;
  }
  return true;
}

bool solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int g = __gcd(a[0], a[1]);
  int pivot= -1;
  for (int i = 1; i < a.size() -1; ++i) {
    int tmp = __gcd(a[i], a[i+1]);
    if (g > tmp)  {
      pivot = i;
    }
    g = tmp;
  }

  if (pivot ==-1) return true;
  vector<int> b0 = a, b1 = a, b2 = a;
  if (pivot > 0) b0.erase(b0.begin() + pivot -1);
  b1.erase(b1.begin() + pivot);
  if (pivot < n-1) b2.erase(b2.begin() + pivot +1);
  return good(b0) || good(b2) || good(b2);
}
int main() {
  int t;
  cin >> t;
  while(t--) 
    if (solve()) cout << "YES" << endl;
    else cout << "NO" << endl;
}
