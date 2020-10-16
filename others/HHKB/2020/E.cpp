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

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> S(h); rep(i, h) cin >> S[i];
  vector<vector<int>> sum(h, vector<int>(w));
  int cnt = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '.') {
      sum[i][j]++;
      cnt++;
    }
  }
  rep(i, h) {
    int tmp = 0;
    rep(j, w) {
      sum[i][j] += tmp;
      if(S[i][j] == '#') tmp = 0;
      else tmp++;
    }
    tmp = 0;
    rrep(j, w) {
      sum[i][j] += tmp;
      if(S[i][j] == '#') tmp = 0;
      else tmp++;
    }
  }
  rep(j, w) {
    int tmp = 0;
    rep(i, h) {
      sum[i][j] += tmp;
      if(S[i][j] == '#') tmp = 0;
      else tmp++;
    }
    tmp = 0;
    rrep(i, h) {
      sum[i][j] += tmp;
      if(S[i][j] == '#') tmp = 0;
      else tmp++;
    }
  }
  ll ans = 0;
  rep(i, h) rep(j, w) {
    if(S[i][j] == '#') continue;
    (ans += (modpow(2, sum[i][j])+mod-1)%mod * modpow(2, cnt-sum[i][j])%mod) %= mod;
  }
  cout << ans << endk;
  return 0;
}
