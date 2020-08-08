#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<vector<int>> C(h, vector<int>(w));
  string s0, s1;
  int sx, sy;
  rep(i, h) rep(j, w) {
    cin >> C[i][j];
    s0 += '0'+C[i][j];
    if(C[i][j] == 0) sx = i, sy = j;
  }
  rep(i, h*w) s1 += '0'+((i+1)%(h*w));
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<set<string>> vst(13), rvst(13);
  string s;
  auto dfs = [&](auto dfs,
                 int x, int y,
                 int px, int py,
                 int n, vector<set<string>>& vst) -> void {
    if(n == 13) return;
    vst[n].insert(s);
    rep(k, 4) {
      int nx = x+dx[k], ny = y+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(nx == px && ny == py) continue;
      swap(s[nx*w+ny], s[x*w+y]);
      dfs(dfs, nx, ny, x, y, n+1, vst);
      swap(s[nx*w+ny], s[x*w+y]);
    }
  };
  s = s1;
  dfs(dfs, h-1, w-1, -1, -1, 0, vst);
  s = s0;
  dfs(dfs, sx, sy, -1, -1, 0, rvst);
  int mn = inf;
  rep(i, 13) rep(j, 13) {
    for(string s: vst[i]) {
      if(rvst[j].count(s) && i+j < mn) {
        // cout << s << ' ' << i << ' ' << j << endl;
        mn = i+j;
      }
    }
  }
  cout << mn << "\n";
  return 0;
}
