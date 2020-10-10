#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, n; cin >> h >> n;
  vector<ll> A(n), B(n); rep(i, n) cin >> A[i] >> B[i];
  ll mxh = h+10005;
  vector<ll> dp(mxh, longinf);
  dp[0] = 0;
  rep(i, mxh) {
    rep(j, n) {
      if(i+A[j] < mxh) chmin(dp[i+A[j]], dp[i]+B[j]);
    }
  }
  ll ans = longinf;
  REP(i, h, mxh) chmin(ans, dp[i]);
  cout << ans << endk;
  return 0;
}
