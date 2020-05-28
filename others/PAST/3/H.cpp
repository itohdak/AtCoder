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
  int N, L;
  cin >> N >> L;
  vector<int> X(N), T(3);
  vector<bool> H(L+1);
  rep(i, N) {
    cin >> X[i];
    H[X[i]] = true;
  }
  rep(i, 3) cin >> T[i];
  vector<ll> dp(L+1, longinf);
  dp[0] = 0;
  rep(i, L) {
    // 行動1
    dp[i+1] = min(dp[i]+T[0]+T[2]*H[i+1], dp[i+1]);
    // 行動2
    if(i+2 <= L) {
      dp[i+2] = min(dp[i]+T[0]+T[1]+T[2]*H[i+2], dp[i+2]);
    } else {
      dp[L] = min(dp[i]+T[0]/2+T[1]/2, dp[L]);
    }
    // 行動3
    if(i+4 <= L) {
      dp[i+4] = min(dp[i]+T[0]+T[1]*3+T[2]*H[i+4], dp[i+4]);
    } else {
      dp[L] = min(dp[i]+T[0]/2+T[1]/2+T[1]*max(L-i-1, 0), dp[L]);
    }
  }
  // cout << dp << endl;
  cout << dp[L] << endl;
  return 0;
}
