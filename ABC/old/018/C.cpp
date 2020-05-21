#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  rep(i, R) cin >> S[i];
  vector<vector<vector<int>>> T(R, vector<vector<int>>(C, vector<int>(2)));
  rep(i, R) rep(j, C) {
    if(S[i][j] == 'o') {
      if(i) T[i][j][0] = T[i-1][j][0]+1;
      else  T[i][j][0] = 1;
    } else {
      T[i][j][0] = 0;
    }
  }
  rrep(i, R) rep(j, C) {
    if(S[i][j] == 'o') {
      if(i<R-1) T[i][j][1] = T[i+1][j][1]+1;
      else      T[i][j][1] = 1;
    } else {
      T[i][j][1] = 0;
    }
  }
  vector<int> need(2*(K-1)+1);
  rep(i, K) need[i] = need[2*(K-1)-i] = i+1;
  // cout << need << endl;
  int ans = 0;
  rep(i, R) rep(j, C) {
    if(i < K-1 || i > R-K || j < K-1 || j > C-K) continue;
    bool ok = true;
    rep(k, 2*(K-1)+1) {
      if(T[i][j-(K-1)+k][0] < need[k] || T[i][j-(K-1)+k][1] < need[k]) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
  return 0;
}
