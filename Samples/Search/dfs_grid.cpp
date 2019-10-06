#include <iostream>
#include <string>
#include <deque>

using namespace std;

#define MAX_N 500
int C[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dx[] = { 0, 0, -1, 1};
int dy[] = {-1, 1,  0, 0};
int H, W;
bool reached;

bool in(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}
bool valid(int x, int y) {
  return (C[x][y] == 1 || C[x][y] == 3) && !visited[x][y] && in(x, y); // modify here
}

// depth first search with recursion (再帰)
void dfs(int x, int y, int type=0) {
  // cout << x << ' ' << y << endl;
  visited[x][y] = true;

  // process v
  // modify here

  for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(valid(nx, ny)) {
      dfs(nx, ny);
    }
  }
}

// depth first search without recursion
deque<pair<int, int> > D; // stack when dfs, queue when bfs
void search(int x, int y, int type=0) {
  visited[x][y] = true;
  D.push_back(pair<int, int>(x, y));
  while(D.size() > 0) {
    pair<int, int> v;
    if(type == 0) v = D.back();  // dfs
    else          v = D.front(); // bfs
    int xtmp = v.first;
    int ytmp = v.second;
    if(type == 0) D.pop_back();  // dfs
    else          D.pop_front(); // bfs
    // cout << xtmp << ' ' << ytmp << endl;
    for(int i=0; i<4; i++) {
      int nx = xtmp + dx[i];
      int ny = ytmp + dy[i];
      if(valid(nx, ny)) {
	visited[nx][ny] = true;
	D.push_back(pair<int, int>(nx, ny));
      }
    }
  }
}

int main() {
  cin >> H >> W;
  int xs, ys, xg, yg;
  for(int i=0; i<H; i++) {
    string S;
    cin >> S;
    for(int j=0; j<W; j++) {
      if(S[j] == '#')
	C[i][j] = 0;
      else if(S[j] == '.')
	C[i][j] = 1;
      else if(S[j] == 's') {
	C[i][j] = 2;
	xs = i;
	ys = j;
      } else if(S[j] == 'g') {
	C[i][j] = 3;
	xg = i;
	yg = j;
      }
    }
  }

  dfs(xs, ys);
  // search(xs, ys, 0);

  if(visited[xg][yg])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
