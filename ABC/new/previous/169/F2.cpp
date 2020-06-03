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
const ll mod = 998244353;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  int S;
  cin >> N >> S;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int mx = S+1;
  vector<vector<ll>> dp(N+1, vector<ll>(mx));
  dp[0][0] = 1;
  rep(i, N) {
    rep(j, mx) {
      if(j+A[i]<mx) (dp[i+1][j+A[i]] += dp[i][j]) %= mod;
      (dp[i+1][j] += dp[i][j] * 2) %= mod;
    }
  }
  cout << dp[N][S] << endl;
  return 0;
}
