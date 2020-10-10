#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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

ll e() {
  return -1;
}
ll op(ll n, ll m) {
  return max(n, m);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  segtree<ll, op, e> seg(A);
  rep(_, q) {
    int t; cin >> t;
    if(t == 1) {
      int x; ll v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
    } else if(t == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r) << endk;
    } else {
      int x; ll v;
      cin >> x >> v;
      x--;
      cout << seg.max_right(x, [&](ll u) { return v > u; }) + 1 << endk;
    }
  }
  return 0;
}
