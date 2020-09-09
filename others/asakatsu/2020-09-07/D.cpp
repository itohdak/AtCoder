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
  vector<string> S(10);
  rep(i, 10) cin >> S[i];
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<int> vis(100, -1);
  int col = 0;
  auto dfs = [&](auto dfs, int cur) -> void {
    int x = cur/10;
    int y = cur%10;
    vis[cur] = col;
    rep(k, 4) {
      int nx = x+dx[k];
      int ny = y+dy[k];
      int ne = nx*10+ny;
      if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
      if(S[nx][ny] == 'x') continue;
      if(vis[ne] != -1) continue;
      dfs(dfs, ne);
    }
  };
  rep(i, 10) rep(j, 10) {
    if(S[i][j] == 'o') continue;
    vis = vector<int>(100, -1);
    S[i][j] = 'o';
    col = 0;
    rep(ii, 10) rep(jj, 10) {
      if(S[ii][jj] == 'o' && vis[ii*10+jj] == -1) {
        col++;
        dfs(dfs, ii*10+jj);
      }
    }
    // rep(ii, 10) {
    //   rep(jj, 10) {
    //     cout << vis[ii*10+jj] << ' ';
    //   }
    //   cout << endk;
    // }
    if(col == 1) {
      cout << "YES" << endk;
      return 0;
    }
    S[i][j] = 'x';
  }
  cout << "NO" << endk;
  return 0;
}
