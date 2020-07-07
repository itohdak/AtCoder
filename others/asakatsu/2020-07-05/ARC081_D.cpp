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
  int n; cin >> n;
  vector<string> S(2);
  rep(i, 2) cin >> S[i];
  vector<ll> dp(n+1);
  dp[0] = 1;
  rep(i, n) {
    if(i) {
      if(S[0][i] == S[1][i]) {
        if(S[0][i-1] == S[1][i-1]) {
          (dp[i+1] = dp[i] * 2) %= mod;
        } else {
          (dp[i+1] = dp[i] * 1) %= mod;
        }
      } else {
        if(S[0][i-1] == S[1][i-1]) {
          (dp[i+1] = dp[i] * 2) %= mod;
        } else {
          (dp[i+1] = dp[i] * 3) %= mod;
        }
        dp[i+2] = dp[i+1];
        i++;
      }
    } else {
      if(S[0][i] == S[1][i]) {
        (dp[i+1] = dp[i] * 3) %= mod;
      } else {
        (dp[i+1] = dp[i] * 6) %= mod;
        dp[i+2] = dp[i+1];
        i++;
      }
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
