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
  int N;
  string S;
  cin >> N >> S;
  int ans = S.size();
  rep(i, N) {
    string s1 = S.substr(0, i);
    string s2 = S.substr(i);
    int n = s1.size();
    int m = s2.size();
    if(n == 0 || m == 0) continue;
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = (s1[0] == s2[0]);
    REP(j, 1, n) dp[j][0] = max(dp[j-1][0], (int)(s1[j] == s2[0]));
    REP(k, 1, m) dp[0][k] = max(dp[0][k-1], (int)(s1[0] == s2[k]));
    REP(j, 1, n) REP(k, 1, m) {
      if(s1[j] == s2[k]) dp[j][k] = dp[j-1][k-1] + 1;
      else               dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
    }
    ans = min(N-2*dp[n-1][m-1], ans);
  }
  cout << ans << endl;
  return 0;
}
