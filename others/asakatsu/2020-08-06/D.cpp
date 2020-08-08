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
  int n, m; cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<string> ans(n, string(m, '0'));
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  rep(i, n) rep(j, m) {
    if(i==0 || i==n-1 || j==0 || j==m-1) continue;
    int mn = inf;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      mn = min(S[nx][ny]-'0', mn);
    }
    ans[i][j] = char(mn+'0');
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      S[nx][ny] -= mn;
    }
  }
  rep(i, n) cout << ans[i] << endk;
  return 0;
}
