#include <bits/stdc++.h>

#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int n;
int q;
vi blocks, a, s, ss, pb, ppb;

ii convert(int i) {
  int idx = upper_bound(blocks.begin(), blocks.end(), i) - blocks.begin()-1;
  return {idx, i - blocks[idx] + idx};
}

int get_part(int i, int l, int r) {
  if (r < l) return 0;
  int cnt = 1 + r - l;
  int rem = s[i] * cnt;
  int ans = ss[r+1] - ss[l];
  //printf("ans, rem : %d %d\n", ans, rem);
  return ans - rem;
}

int32_t main() {
  cin >> n;
  a.assign(n, 0);
  s.assign(n+1, 0);
  ss.assign(n+1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> q;

  blocks.push_back(0);
  for (int i = n; i >= 1; --i) {
    blocks.push_back(blocks.back() + i);
  }

  ss[0] = s[0] = 0;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i-1] + a[i-1];
    ss[i] = ss[i-1] + s[i];
  }

  pb.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    pb[i] = get_part(i, i, n-1);
  }

  ppb.assign(n+1, 0);
  for (int i = 0; i < n; ++i) {
    ppb[i+1] = pb[i] + ppb[i];
  }

  while(q--) {
    int l, r; cin >> l >> r;
    --l; --r;
    ii ll = convert(l);
    ii rr = convert(r);
    int ans = ppb[rr.first+1] - ppb[ll.first];
    //printf("l.1, l.2, r.1, r.2: %d %d %d %d\n", ll.first, ll.second, rr.first, rr.second);
    //cout << ans << " " << get_part(ll.first, ll.first, ll.second-1) << " " << get_part(rr.first, rr.second+1, n-1) << endl;
    ans -= get_part(ll.first, ll.first, ll.second-1);
    ans -= get_part(rr.first, rr.second+1, n-1);
    cout << ans << '\n';
  }
}
