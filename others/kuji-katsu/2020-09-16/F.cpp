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
  int n; ll m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  sort(all(A));
  vector<ll> sum(n+1);
  rep(i, n) sum[i+1] = sum[i] + A[i];
  auto bsearch = [&]() {
    auto test = [&](ll k) {
      ll cnt = 0;
      rep(i, n) {
        int j = lower_bound(all(A), k-A[i]) - begin(A);
        chmax(j, i);
        cnt += (n-j) * 2 - (i >= j);
      }
      return cnt <= m;
    };
    ll ok = longinf, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll ret = bsearch();
  ll ans = 0;
  ll cnt = 0;
  // cout << A << endk;
  rep(i, n) {
    int j = lower_bound(all(A), ret-A[i]) - begin(A);
    chmax(j, i);
    cnt += (n-j) * 2 - (i >= j);
    ans += (A[i] * (n-j) + sum[n]-sum[j]) * 2 - (i >= j) * A[i] * 2;
  }
  // cout << ret << endk;
  ans += (m-cnt) * (ret-1);
  cout << ans << endk;
  return 0;
}
