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
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  rep(i, R) cin >> S[i];
  vector<vector<int>> up(R, vector<int>(C)), down(R, vector<int>(C));
  rep(j, C) {
    int cnt = 0;
    rep(i, R) {
      if(S[i][j] == 'x') {
        cnt = 0;
        up[i][j] = cnt;
      } else {
        cnt++;
        up[i][j] = cnt;
      }
    }
    cnt = 0;
    rrep(i, R) {
      if(S[i][j] == 'x') {
        cnt = 0;
        down[i][j] = cnt;
      } else {
        cnt++;
        down[i][j] = cnt;
      }
    }
  }
  // cout << up << down << endl;
  int ans = 0;
  rep(i, R) rep(j, C) {
    if(i-(K-1) < 0 || i+(K-1) >= R || j-(K-1) < 0 || j+(K-1) >= C) continue;
    bool ok = true;
    REP(k, j-(K-1), j+K) {
      if(up[i][k] < K-abs(k-j) || down[i][k] < K-abs(k-j)) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << "\n";
  return 0;
}
