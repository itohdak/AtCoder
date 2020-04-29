#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

bool inside(int x, int y, int H, int W) {
  return 0 <= x && x < H && 0 <= y && y < W;
}
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  rep(i, H) cin >> A[i];
  int tmpX = 0, tmpY = 0;
  int preX = -1, preY = 0;
  int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
  while(true) {
    int cnt = 0;
    int nextX, nextY;
    rep(i, 4) {
      int nx = tmpX+dx[i], ny = tmpY+dy[i];
      if(inside(nx, ny, H, W) &&
	 !(nx == preX && ny == preY) &&
	 A[nx][ny] == '#') {
	cnt++;
	nextX = nx, nextY = ny;
      }
    }
    if(cnt > 1 || nextX < tmpX || nextY < tmpY) {
      cout << "Impossible" << endl;
      return 0;
    }
    if(tmpX == H-1 && tmpY == W-1) {
      if(cnt == 0) break;
      else {
	cout << "Impossible" << endl;
	return 0;
      }
    }
    preX = tmpX, preY = tmpY;
    tmpX = nextX, tmpY = nextY;
  }
  cout << "Possible" << endl;
  return 0;
}
