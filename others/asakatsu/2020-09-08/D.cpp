#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r, c; cin >> r >> c;
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  sx--; sy--; tx--; ty--;
  vector<string> S(r); rep(i, r) cin >> S[i];
  queue<int> q;
  vector<bool> vis(r*c);
  vector<int> dis(r*c, inf);
  q.push(sx*c+sy);
  dis[sx*c+sy] = 0;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    int x = cur/c;
    int y = cur%c;
    if(vis[cur]) continue;
    vis[cur] = true;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      int ne = nx*c+ny;
      if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if(S[nx][ny] == '#') continue;
      if(dis[ne] > dis[cur]+1) {
        dis[ne] = dis[cur]+1;
        q.push(ne);
      }
    }
  }
  cout << dis[tx*c+ty] << endk;
  return 0;
}
