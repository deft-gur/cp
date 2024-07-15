#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>

map<string, int> toIdx;
map<int, string> toName;
vvi neigh;
vi inDegree;
int n,m;

vi topSort() {
  vi sort;
  priority_queue<int, vi, greater<int>> pq;

  for (int i = 0; i < n; ++i) {
    if (inDegree[i] == 0) pq.push(i);
  }

  while(!pq.empty()) {
    int u = pq.top(); pq.pop();
    sort.push_back(u);
    for (auto &v : neigh[u]) {
      --inDegree[v];
      if (inDegree[v] == 0) pq.push(v);
    }
  }

  return sort;
}

int main() {
  int C = 1;
  while (cin >> n) {
    neigh.resize(n);
    inDegree.resize(n);
    fill(neigh.begin(), neigh.begin() + n, vi());
    fill(inDegree.begin(), inDegree.begin() + n, 0);
    toName.clear();
    toIdx.clear();

    for (int i = 0; i < n; ++i) {
      string name;
      cin >> name;
      toName[i] = name;
      toIdx[name] = i;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
      string u, v;
      cin >> u >> v;
      neigh[toIdx[u]].push_back(toIdx[v]);
      ++inDegree[toIdx[v]];
    }

    vi sort = topSort();
    printf("Case #%d: Dilbert should drink beverages in this order:", C++);
    for (int i = 0; i < n; ++i) {
      printf(" %s", toName[sort[i]].c_str());
    }
    printf(".\n\n");
  }
}
