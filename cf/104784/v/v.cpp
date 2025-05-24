#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
vi hashes;
map<ii, int> visited;
map<ii, int> revPts;
vii pts;

unsigned long long rng() {
  static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
  return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

ii minuss(ii a, ii b) {
  return {a.first - b.first, a.second - b.second};
}

ii add(ii a, ii b) {
  return {a.first + b.first, a.second + b.second};
}

int main() {
  cin >> n;
  ll h = 0;
  hashes.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    pts.emplace_back(x, y);
    hashes[i] = rng();
    revPts[pts[i]] = i;
    h += hashes[i];
  }

  sort(pts.begin(), pts.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ii v = minuss(pts[i], pts[0]);
    if (v.first == 0 && v.second == 0) continue;
    visited.clear();
    ll tmp = 0;
    //cout << "v: " << v.first << " " << v.second << endl;
    for (int j = 0; j < n; ++j) {
      ii w = add(pts[j], v);
      //cout << "w: " << w.first << " " << w.second << endl;
      if (revPts.find(w) == revPts.end() && !visited[minuss(pts[j], v)]) {
	//cout << "breaking\n";
	break;
      }
      tmp += hashes[j];
      visited[pts[j]] = 1;
    }
    //cout << tmp << h << endl;
    if (tmp == h) ++ans;
  }
  cout << 2 * ans << endl;
}
