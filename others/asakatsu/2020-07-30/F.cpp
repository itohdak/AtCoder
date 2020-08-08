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
  int n, p; cin >> n >> p;
  vector<pair<ll, ll>> P(n);
  ll mxp = 0;
  rep(i, n) {
    cin >> P[i].first >> P[i].second;
    mxp = max(P[i].first, mxp);
  }
  sort(all(P), greater<pair<ll, ll>>());
  vector<vector<ll>> dp(n+1, vector<ll>(p+mxp+1));
  rep(i, n) {
    rep(j, p+mxp+1) {
      dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
      if(j+P[i].first < p+P[i].first+1) {
        dp[i+1][j+P[i].first] = max(dp[i][j]+P[i].second,
                                    dp[i+1][j+P[i].first]);
      }
    }
  }
  cout << *max_element(all(dp[n])) << "\n";
  return 0;
}
