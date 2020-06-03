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
  int N;
  cin >> N;
  vector<int> G(2), S(2), B(2);
  rep(i, 2) cin >> G[i] >> S[i] >> B[i];
  vector<int> choice[] = {G, S, B};
  vector<ll> dp(N+1, N);
  rep(i, N+1) {
    rep(j, 3) {
      if(choice[j][1] < choice[j][0]) continue;
      if(i+choice[j][0] <= N) {
        dp[i+choice[j][0]] = max(dp[i]+choice[j][1]-choice[j][0],
                                 dp[i+choice[j][0]]);
      }
    }
  }
  N = *max_element(all(dp));
  dp = vector<ll>(N+1, N);
  rep(i, N+1) {
    rep(j, 3) {
      if(choice[j][0] < choice[j][1]) continue;
      if(i+choice[j][1] <= N) {
        dp[i+choice[j][1]] = max(dp[i]+choice[j][0]-choice[j][1],
                                 dp[i+choice[j][1]]);
      }
    }
  }
  cout << *max_element(all(dp)) << endl;
  return 0;
}
