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
  cin >> N;
  vector<int> D(N);
  rep(i, N) cin >> D[i];
  sort(all(D));
  vector<vector<ll>> dp(N+1, vector<ll>(5));
  dp[0][0] = 1;
  rep(i, N) {
    int k = upper_bound(all(D), D[i]/2) - begin(D);
    rep(j, 5) {
      (dp[i+1][j] += dp[i][j]) %= mod; // 選ばない
      if(j+1<5) (dp[i+1][j+1] += dp[k][j]) %= mod; // 選ぶ
    }
  }
  cout << dp[N][4] << endl;
  return 0;
}
