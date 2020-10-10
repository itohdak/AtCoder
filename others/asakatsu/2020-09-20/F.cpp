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
  int n; ll w; cin >> n >> w;
  vector<ll> V(n), W(n);
  rep(i, n) cin >> V[i] >> W[i];
  bool smallW = true;
  rep(i, n) if(W[i] > 1000) smallW = false;
  if(n <= 30) {
    vector<map<ll, ll>> vmp(n/2+1), vmp2(n-n/2+1);
    vmp[0][0] = 0; vmp2[0][0] = 0;
    rep(i, n/2) {
      for(auto ele: vmp[i]) {
        chmax(vmp[i+1][ele.first], ele.second);
        chmax(vmp[i+1][ele.first+W[i]], ele.second+V[i]);
      }
    }
    {
      ll prev = 0;
      for(auto &ele: vmp.back()) {
        chmax(ele.second, prev);
        prev = ele.second;
      }
    }
    rep(i, n-n/2) {
      for(auto ele: vmp2[i]) {
        chmax(vmp2[i+1][ele.first], ele.second);
        chmax(vmp2[i+1][ele.first+W[i+n/2]], ele.second+V[i+n/2]);
      }
    }
    {
      ll prev = 0;
      for(auto &ele: vmp2.back()) {
        chmax(ele.second, prev);
        prev = ele.second;
      }
    }
    ll ans = 0;
    for(auto ele: vmp.back()) {
      auto itr = vmp2.back().upper_bound(w-ele.first);
      if(itr == vmp2.back().begin()) break;
      --itr;
      chmax(ans, ele.second+itr->second);
    }
    cout << ans << endk;
  } else if(smallW) {
    vector<vector<ll>> dp(n+1, vector<ll>(n*1000+1, 0));
    dp[0][0] = 0;
    rep(i, n) {
      rep(j, n*1000+1) {
        chmax(dp[i+1][j], dp[i][j]);
        if(j+W[i] < n*1000+1) chmax(dp[i+1][j+W[i]], dp[i][j]+V[i]);
      }
      // rep(j, n*1000) chmax(dp[i+1][j+1], dp[i+1][j]);
    }
    cout << *max_element(dp[n].begin(), dp[n].begin()+w+1) << endk;
  } else {
    vector<vector<ll>> dp(n+1, vector<ll>(n*1000+1, longinf));
    dp[0][0] = 0;
    rep(i, n) {
      rep(j, n*1000+1) {
        chmin(dp[i+1][j], dp[i][j]);
        if(j+V[i] < n*1000+1) chmin(dp[i+1][j+V[i]], dp[i][j]+W[i]);
      }
      // rrep(j, n*1000+1) if(j-1 >= 0) chmin(dp[i+1][j-1], dp[i+1][j]);
    }
    ll ans = 0;
    rep(i, n*1000+1) if(dp[n][i] <= w) chmax(ans, i);
    cout << ans << endk;
  }
  return 0;
}
