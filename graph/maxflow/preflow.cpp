#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m, s, t;

vi h, e;
vvii AL;
vvi AM, x;
vvi Res;
priority_queue<int, vector<int>, greater<int>> q;
vector<int> contains;

void update(int v) {
  if (contains[v] || e[v] <= 0 || v == t) return;
  cout << "inserted " << v << " into the queue" << endl;
  q.push(v);
  contains[v] = 1;
}

int pop() {
  int v = q.top(); q.pop();
  cout << "popped " << v << " out of the queue" << endl;
  contains[v] = 0;
  return v;
}

void updateRes(int u, int v) {
  if (x[u][v] > 0) Res[v][u] = 1;
  if (x[u][v] == 0) Res[v][u] = 0;
  if (x[u][v] < AM[u][v]) Res[u][v] = 1;
  if (x[u][v] == AM[u][v]) Res[u][v] = 0;
}

void push(int u, int v) {
  cout << "pushing: " << u << "," << v << endl;
  if (AM[u][v]) {
    cout << "forward" << endl;
    int m = min(e[u], AM[u][v] - x[u][v]);
    x[u][v] += m;
    e[v] += m;
    e[u] -= m;
    update(v);
    update(u);
    updateRes(u, v);
  } else {
    cout << "backward" << endl;
    int m = min(e[u], x[v][u]);
    x[v][u] -= m;
    e[u] -= m;
    e[v] += m;
    update(v);
    update(u);
    updateRes(v, u);
  }
}

void relabel(int u, int v) {
  cout << "relabling " << u << endl;
  h[u] = h[v] + 1;
}

void preFlow() {
  cout << "Starting preflow" << endl;
  h.assign(n, 0);
  x.assign(n, vector(n, 0));
  h[s] = n;
  e.assign(n, 0);
  contains.assign(n, 0);
 

  for (int u = 0; u < n; ++u) {
    for (auto [v, w] : AL[u]) {
      if (u == s) {
	Res[v][s] = 1;
	x[s][v] = w;
	e[v] = w;
	e[s] -= w;
	update(v);
      } else {
	Res[u][v] = 1;
      }
    }
  }
  while(!q.empty()) {
    int u = pop();
    int candidate = n-1;
    int candidateHeight = 1e10;
    cout << "Picking " << u << endl;
    int done = false;
    for (int v = 0; v < n; ++v) {
      if (Res[u][v] != 0 && h[v] < candidateHeight) {
	candidate = v;
	candidateHeight = h[v];
      }
    }
    cout << "candidate" << candidate << endl;
    relabel(u, candidate);
    push(u, candidate);
  }

  int mxFlow = 0;
  for (int i = 0; i < n; ++i) {
    mxFlow += x[i][t];
  }
  cout << "Mx flow: " << mxFlow << endl;
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> m >> s >> t;
  AL.assign(n, vii(0, {0,0}));
  AM.assign(n, vector(n, 0));
  Res.assign(n, vector(n, 0));

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    cout.flush();
    AL[u].emplace_back(v, w);
    AM[u][v] = w;
  }
  preFlow();
}
