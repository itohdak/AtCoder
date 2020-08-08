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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r, c; cin >> r >> c;
  int sx, sy; cin >> sx >> sy;
  sx--; sy--;
  int gx, gy; cin >> gx >> gy;
  gx--; gy--;
  vector<string> S(r);
  rep(i, r) cin >> S[i];
  auto bfs = [&]() {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    queue<int> q;
    vector<bool> vis(r*c);
    q.push(sx*c+sy);
    vector<int> d(r*c, inf);
    d[sx*c+sy] = 0;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      if(vis[cur]) continue;
      vis[cur] = true;
      int x = cur/c;
      int y = cur%c;
      rep(k, 4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        int ne = nx*c+ny;
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(S[nx][ny] == '#') continue;
        if(d[ne] > d[cur]+1) {
          d[ne] = d[cur]+1;
          q.push(ne);
        }
      }
    }
    return d[gx*c+gy];
  };
  cout << bfs() << endk;
  return 0;
}
