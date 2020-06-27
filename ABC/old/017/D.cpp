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
  int N, M;
  cin >> N >> M;
  vector<ll> F(N);
  rep(i, N) cin >> F[i];
  vector<ll> dp(N+1);
  ll sum = 0;
  int l=0, r=0;
  dp[0] = 1;
  set<int> se;
  while(l < N) {
    while(r < N && !se.count(F[r])) {
      (sum += dp[r]) %= mod;
      dp[r+1] = sum;
      se.insert(F[r]);
      r++;
    }
    while(l < N && (r == N || se.count(F[r]))) {
      (sum += mod - dp[l]) %= mod;
      se.erase(F[l]);
      l++;
    }
    // cout << r << ' ' << se << endl;
  }
  // cout << dp << endl;
  cout << dp[N] << endl;
  return 0;
}
