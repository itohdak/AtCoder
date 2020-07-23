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
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  bool ok = true;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '.') continue;
    int cnt = 0;
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '#') cnt++;
    }
    ok &= (cnt != 0);
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
