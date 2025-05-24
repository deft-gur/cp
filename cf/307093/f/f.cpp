#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

struct MMStack {
  vll s, smin = {LLONG_MAX}, smax = {LLONG_MIN};

  void push(ll x) {
    s.push_back(x);
    smin.push_back(std::min(smin.back(), x));
    smax.push_back(std::max(smax.back(), x));
  }

  ll pop() {
    ll ret = s.back();
    s.pop_back();
    smin.pop_back();
    smax.pop_back();
    return ret;
  }

  ll min() { return smin.back(); }
  
  ll max() { return smax.back(); }

  int empty() { return s.empty(); }

};

ll n, k;
MMStack s1, s2;
vll a;

void add(ll x) {
  s2.push(x);
}

void remove() {
  if (s1.empty()) {
    while(!s2.empty()) {
      s1.push(s2.pop());
    }
  }
  s1.pop();
}

bool good() {
  ll mn = min(s1.min(), s2.min());
  ll mx = max(s1.max(), s2.max());
  return (mx - mn) <= k;
}

int main() {
  cin >> n >> k;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) { cin >> a[i]; }

  int L = 0;
  ll ans = 0;
  for (int R = 0; R < n; ++R) {
    add(a[R]);
    while(!good()) {
      remove();
      ++L;
    }
    ans += R - L + 1;
  }
  cout << ans << endl;
}
