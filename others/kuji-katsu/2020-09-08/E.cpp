#include <bits/stdc++.h>
// #include <atcoder/all>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y, z, k; cin >> x >> y >> z >> k;
  vector<ll> A(x), B(y), C(z);
  rep(i, x) cin >> A[i];
  rep(i, y) cin >> B[i];
  rep(i, z) cin >> C[i];
  vector<ll> AB;
  rep(i, x) rep(j, y) {
    AB.push_back(A[i]+B[j]);
  }
  sort(all(AB));
  int w = x*y;
  sort(all(C));
  // cout << AB << endk;
  // cout << C << endk;
  auto bsearch = [&]() {
    auto test = [&](ll t) {
      ll cnt = 0;
      rep(i, w) {
        cnt += end(C) - lower_bound(all(C), t-AB[i]);
      }
      // cout << t << ' ' << cnt << endk;
      return cnt <= k;
    };
    ll ok = longinf, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll res = bsearch();
  vector<ll> ans;
  rep(i, w) {
    for(auto itr=lower_bound(all(C), res-AB[i]); itr!=end(C); itr++) {
      ans.push_back(*itr+AB[i]);
    }
  }
  sort(all(ans), greater<ll>());
  rep(i, k) {
    if(i < ans.size()) cout << ans[i] << endk;
    else cout << res-1 << endk;
  }
  return 0;
}
