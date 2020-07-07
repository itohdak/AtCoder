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
  string s1, s2; cin >> s1 >> s2;
  vector<ll> dp(n+1);
  dp[0] = 1;
  int i = 0;
  while(i < n) {
    if(s1[i] != s2[i]) {
      if(i==0) dp[i+1] = dp[i+2] = 6;
      else if(s1[i-1] != s2[i-1]) dp[i+1] = dp[i+2] = dp[i] * 3 % mod;
      else dp[i+1] = dp[i+2] = dp[i] * 2 % mod;
      i += 2;
    } else {
      if(i==0) dp[i+1] = 3;
      else if(s1[i-1] != s2[i-1]) dp[i+1] = dp[i];
      else dp[i+1] = dp[i] * 2 % mod;
      i++;
    }
  }
  cout << dp[n] << "\n";
  return 0;
}
