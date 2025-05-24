#include <bits/stdc++.h>

typedef vi vector<int>
typedef vii vector<vi>
typedef li list<int>

int n, m;
vii g;
vi sets;
int set, unset;
li ans;
map<int, list<int>::iterator> nodeToList;
vi visited;

bool bfs(int i) {
  if (visitied[i]) return true;
  queue<int> q;
  q.push(i);
  while(!q.empty()) {
    int u = q.top(); q.pop();
    for (auto v : g[i]) {
      if (set[v] && set[u]) {
      } else {

      }
    }
  }
}

void solve() {
  visited.assign(n, 0);
  for (int i = 1; i <n; ++i) {
    if (!bfs(i)) {cout << -1 << '\n'; return;}
  }

  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}



int main() {
  set = unset = 0;
  cin >> n;
  g.assign(n, vi());
  for (int i = 1; i <= n; ++i) {
    string s; bool b;
    cin >> s >> b;
    if (s == "set") {
      if (b) {
	if (set) { cout << -1 << '\n' return 0;}
	set = i;
      }
      sets.push_back(1);
    } else {
      if (b) {
	if (unset) { cout << -1 << '\n' return 0;}
	unset = i;
      }
      sets.push_back(0);
    }
  }

  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
  }

  if (set) {
    ans.push_front(set); 
    nodeToList[set] = ans.end() - 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (sets[i]) {
      ans.push_back(i);
      nodeToList[i] = ans.end() - 1;
    } else {
      ans.push_front(i);
      nodeToList[i] = ans.begin();
    }
  }
  if (unset) { 
    ans.push_back(unset);
    nodeToList[unset] = ans.end() - 1;
  }
  solve();
}

