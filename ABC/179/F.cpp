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
  int n, q; cin >> n >> q;
  int mn1=n-1, mn2=n-1;
  map<int, int> cnt1, cnt2;
  ll cnt = 0;
  rep(_, q) {
    int t, x; cin >> t >> x;
    x--;
    if(t == 1) {
      if(x > mn1) {
        // for(auto itr=cnt1.upper_bound(x); itr!=cnt1.end(); itr++) {
        //   cout << *itr << endk;
        // }
        cnt += (--cnt1.upper_bound(x))->second;
      } else {
        cnt += mn2-1;
        cnt1[x] = mn2-1;
      }
      chmin(mn1, x);
    } else {
      if(x > mn2) {
        cnt += (--cnt2.upper_bound(x))->second;
      } else {
        cnt += mn1-1;
        cnt2[x] = mn1-1;
      }
      chmin(mn2, x);
    }
    // cout << mn1 << ' ' << cnt1 << endk;
    // cout << mn2 << ' ' << cnt2 << endk;
    // cout << cnt << endk << endk;
  }
  cout << 1LL*(n-2)*(n-2) - cnt << endk;
  return 0;
}
