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
  vector<int> C(n); rep(i, n) cin >> C[i];
  vector<int> dp(n, 1);
  rep(i, n) {
    REP(j, i+1, n) {
      if(C[j] > C[i]) dp[j] = max(dp[i]+1, dp[j]);
    }
  }
  cout << n-*max_element(all(dp)) << "\n";
  return 0;
}
