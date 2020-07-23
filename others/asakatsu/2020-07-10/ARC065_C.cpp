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
  string s; cin >> s;
  int n = s.size();
  vector<int> dp(n+1);
  dp[0] = 1;
  string t[] = {"dream", "dreamer", "erase", "eraser"};
  rep(i, n) rep(j, 4) {
    if(i+(int)t[j].size()<=n && s.substr(i, (int)t[j].size())==t[j]) {
      dp[i+(int)t[j].size()] = dp[i];
    }
  }
  // cout << dp << "\n";
  cout << (dp[n] ? "YES" : "NO") << "\n";
  return 0;
}
