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
  string c[] = {"A", "C", "G", "T"};
  string s[64];
  rep(i, 4) rep(j, 4) rep(k, 4) s[i*16+j*4+k] = c[i]+c[j]+c[k];
  vector<map<string, ll>> dp(n+1);
  set<string> ng3 = {"AGC", "ACG", "GAC"};
  set<string> ng4 = {"AGAC", "AGGC", "AGTC", "AGGC", "ATGC"};
  rep(i, 64) if(!ng3.count(s[i])) dp[3][s[i]] = 1;
  for(int i=4; i<=n; i++) {
    for(auto ele: dp[i-1]) {
      string s = ele.first;
      rep(j, 4) {
        if(ng4.count(s+c[j]) || ng3.count(s.substr(1)+c[j])) continue;
        (dp[i][s.substr(1)+c[j]] += ele.second) %= mod;
      }
    }
  }
  ll ans = 0;
  for(auto ele: dp[n]) (ans += ele.second) %= mod;
  cout << ans << "\n";
  return 0;
}
