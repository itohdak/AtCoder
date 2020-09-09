#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, k; cin >> h >> w >> k;
  k--;
  vector<vector<ll>> dp(h+1, vector<ll>(w));
  dp[0][0] = 1;
  rep(i, h) {
    rep(j, 1<<(w-1)) {
      bool ok = true;
      rep(k, w-2) {
        if((j>>k)&(j>>(k+1)&1)) ok = false;
      }
      if(!ok) continue;
      rep(k, w-1) {
        if((j>>k)&1) {
          (dp[i+1][k+1] += dp[i][k]) %= mod;
          (dp[i+1][k] += dp[i][k+1]) %= mod;
        } else {
          (dp[i+1][k] += dp[i][k]) %= mod;
          (dp[i+1][k+1] += dp[i][k+1]) %= mod;
        }
      }
    }
  }
  cout << dp[h][k] << endk;
  return 0;
}
