#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N, T;
  cin >> N >> T;
  vector<int> A(N), B(N), idx(N);
  rep(i, N) {
    cin >> A[i] >> B[i];
    idx[i] = i;
  }
  sort(all(idx), [&](int i, int j) {
      return A[i] < A[j];
    });
  vector<vector<ll> > dp(T+1, vector<ll>(N+1));
  rep(t, T) {
    rep(i, N) {
      ll a = A[idx[i]];
      ll b = B[idx[i]];
      dp[t][i+1] = max(dp[t][i], dp[t][i+1]);
      if(t+a<=T) dp[t+a][i+1] = max(dp[t][i]+b, dp[t+a][i+1]);
      else       dp[T][i+1] = max(dp[t][i]+b, dp[T][i+1]);
    }
  }
  ll ans = 0;
  rep(i, N+1) ans = max(dp[T][i], ans);
  cout << ans << endl;
  return 0;
}
