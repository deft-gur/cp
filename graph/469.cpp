#include <bits/stdc++.h>

using namespace std;

#define MX 150

char grid[MX][MX], line[MX];
int visited[MX][MX];
int R, C;
const int dr[]={-1,-1,-1,0,0,1,1,1};
const int dc[]={-1,0,1,-1,1,-1,0,1};

int solve(int r, int c) {
  if (r < 0 || r >= R) return 0;
  if (c < 0 || c >= C) return 0;
  if (visited[r][c]) return 0;

  visited[r][c] = 1;

  if (grid[r][c] == 'L') return 0;

  int res = 1;
  for (int i = 0; i < 8; ++i) {
    res += solve(r + dr[i], c + dc[i]);
  }
  return res;
}


int main() {
  int t;
  fgets(line, MX, stdin);
  sscanf(line, "%d", &t);
  fgets(line, MX, stdin);
  while (t--) {
    R = 0;
    while(true) {
      fgets(grid[R], MX, stdin);
      if (grid[R][0] != 'W' && grid[R][0] != 'L') break;
      ++R;
    }
    C = strlen(grid[0]) - 1;

    strcpy(line, grid[R]);
    while(true) {
      int r, c;
      sscanf(line, "%d %d", &r, &c);
      memset(visited, 0, sizeof(visited));
      printf("%d\n", solve(--r, --c));
      fgets(line, MX, stdin);
      if(strlen(line) == 0 || isspace(line[0]) || feof(stdin)) break;
    }
    if (t) printf("\n");
  }
}
