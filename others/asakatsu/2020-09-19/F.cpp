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
  int r, g, b; cin >> r >> g >> b;
  auto cost = [&](int l, int r, int mid) {
    if(r < mid) {
      // (mid-r) ... (mid-l)
      return 1LL*(2*mid-r-l)*(r-l+1)/2;
    } else if(l < mid) {
      // mid-l ... 0 ... r-mid
      return 1LL*(mid-l)*(mid-l+1)/2 + 1LL*(r-mid)*(r-mid+1)/2;
    } else {
      // l-mid ... r-mid
      return 1LL*(r+l-2*mid)*(r-l+1)/2;
    }
  };
  ll ans = longinf;
  REP(lg, -1000, 1000) {
    int rg = lg+g-1;
    ll tmp = cost(lg, rg, 0);
    {
      ll tmp2 = longinf;
      REP(lb, rg+1, 1000) {
        int rb = lb+b-1;
        chmin(tmp2, cost(lb, rb, 100));
      }
      tmp += tmp2;
    }
    {
      ll tmp2 = longinf;
      REP(lr, -1000, lg-r+1) {
        int rr = lr+r-1;
        chmin(tmp2, cost(lr, rr, -100));
      }
      tmp += tmp2;
    }
    chmin(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
