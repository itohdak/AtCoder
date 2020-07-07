#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<int>> ans(h, vector<int>(w));
  int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') {
      rep(k, 8) {
        int nx = i+dx[k], ny = j+dy[k];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        ans[nx][ny]++;
      }
    }
  }
  rep(i, h) {
    rep(j, w) {
      if(S[i][j] == '#') cout << '#';
      else cout << ans[i][j];
    }
    cout << "\n";
  }
  return 0;
}
