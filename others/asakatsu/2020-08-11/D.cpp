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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> dp(n, longinf);
  dp[0] = 0;
  rep(i, n) {
    if(i+1 < n) dp[i+1] = min(dp[i]+abs(A[i]-A[i+1]), dp[i+1]);
    if(i+2 < n) dp[i+2] = min(dp[i]+abs(A[i]-A[i+2]), dp[i+2]);
  }
  cout << dp[n-1] << endk;
  return 0;
}
