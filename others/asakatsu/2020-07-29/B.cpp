#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  vector<int> D;
  while(n > 0) {
    D.push_back(n%10);
    n /= 10;
  }
  reverse(all(D));
  int d = D.size();
  vector<vector<int>> dp(d+1, vector<int>(2));
  rep(i, d) {
    if(i == 0) {
      dp[i+1][0] = max(dp[i][0]+D[i], dp[i+1][0]);
      dp[i+1][1] = max(dp[i][0]+D[i]-1, dp[i+1][1]);
    } else {
      dp[i+1][0] = max(dp[i][0]+D[i], dp[i+1][0]);
      dp[i+1][1] = max({dp[i][0]+D[i]-1, dp[i][1]+9, dp[i+1][1]});
    }
  }
  cout << max(dp[d][0], dp[d][1]) << "\n";
  return 0;
}
