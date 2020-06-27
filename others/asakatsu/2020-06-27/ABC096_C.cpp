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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  bool ok = true;
  rep(i, H) rep(j, W) {
    if(S[i][j] == '#') {
      int dx[] = {-1, 0, 1, 0};
      int dy[] = {0, 1, 0, -1};
      bool ok2 = false;
      rep(k, 4) {
        int nx = i+dx[k], ny = j+dy[k];
        if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        ok2 |= (S[nx][ny]=='#');
      }
      ok &= ok2;
    }
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
