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
  int N;
  cin >> N;
  vector<pair<ll, int>> A(N);
  rep(i, N) {
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(all(A), greater<pair<ll, int>>());
  vector<vector<ll>> dp(N+1, vector<ll>(N+1));
  rep(i, N+1) rep(j, N+1) {
    if(i) dp[i][j] = max(dp[i-1][j] + A[i+j-1].first * abs(i-1-A[i+j-1].second), dp[i][j]);
    if(j) dp[i][j] = max(dp[i][j-1] + A[i+j-1].first * abs(N-j-A[i+j-1].second), dp[i][j]);
  }
  ll mx = 0;
  rep(i, N+1) mx = max(dp[i][N-i], mx);
  cout << mx << endl;
  return 0;
}
