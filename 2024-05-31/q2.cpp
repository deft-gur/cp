#include <bits/stdc++.h>

using namespace std;

#define ll long long
void solve() {
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  for (int i = 0; i <= 30; ++i) {
    if (n & (1 << i)) {
      ans |= (1LL << i); continue;
    } else {
      ll tmp = n & ((1LL << (i+1)) - 1);
      /* cout << "tmp:" << tmp << endl; */
      ll leftTime = tmp + 1;
      /* cout << "lt:" << leftTime << endl; */
      ll rightTime = (1LL << i) - tmp;
      /* cout << "rt:"<< rightTime << endl; */
      ll time = rightTime;
      if (n >= (1LL << i)) {
        time = min(leftTime, rightTime);
      }
      if (time <= m){
        ans |= (1LL << i);
      }
    }
  }
  /* for (int i = 0; i < 30; ++i) { */
  /*   if (ans % 2) cout << 1; */
  /*   else cout << 0; */
  /*   ans = (ans >> 1); */
  /* } */
  /* cout << endl; */
  cout << ans << endl;
}

int main() {
  int t;
  cin >>t;
  while(t--) solve();
}
