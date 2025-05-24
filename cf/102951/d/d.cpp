#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
int n, q;
vi indices;
viii updates;
vii queries;

int getCompressed(int a) {
  return lower_bound(indices.begin(), indices.end(), a) - indices.begin();
}

int32_t main() {
  cin >> n >> q;
  int l, r, v;
  updates.assign(n, {0, 0, 0});
  queries.assign(q, {0, 0});
  for (int i = 0; i < n; ++i) {
    cin >> l >> r >> v;
    indices.push_back(l);
    indices.push_back(r);
    updates[i] = {l, r, v};
  }

  for (int i = 0; i < q; ++i) {
    cin >> l >> r;
    indices.push_back(l);
    indices.push_back(r);
    queries[i] = {l, r};
  }

  sort(indices.begin(), indices.end());
  indices.erase(unique(indices.begin(), indices.end()), indices.end());

  int N = indices.size() + 1;
  vi upVal, width, interSum, prefixSum;
  upVal.assign(N, 0);
  width.assign(N, 0);
  interSum.assign(N, 0);
  prefixSum.assign(N, 0);

  for (auto up : updates) {
    ll l, r, v;
    tie(l, r, v) = up;
    upVal[getCompressed(l)+1] += v;
    upVal[getCompressed(r)+1] -= v;
  }
  for (int i = 1; i < indices.size(); ++i) {
    width[i] = indices[i] - indices[i-1];
  }
  for (int i = 1; i < indices.size(); ++i) {
    interSum[i] = interSum[i-1] + upVal[i];
  }
  for (int i = 1; i < indices.size(); ++i) {
    prefixSum[i] = prefixSum[i-1] + interSum[i] * width[i];
  }

  for (auto q : queries) {
    int l, r;
    tie(l, r) = q;
    cout << (ll)(prefixSum[getCompressed(r)] - prefixSum[getCompressed(l)]) << '\n';
  }
}
