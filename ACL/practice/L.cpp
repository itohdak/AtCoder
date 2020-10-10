#include <bits/stdc++.h>
#include <print.hpp>
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

struct S {
  // num0: number of 0s
  // num1: number of 1s
  // inv : number of inversions
  ll num0, num1, inv;
};
struct F {
  ll flip;
};
S op(S a, S b) {
  return S{a.num0+b.num0, a.num1+b.num1, a.inv+b.inv+a.num1*b.num0};
}
S e() {
  return S{0LL, 0LL, 0LL};
}
S mapping(F f, S x) {
  if(f.flip == 0) return x;
  else return S{x.num1, x.num0, x.num0*x.num1-x.inv};
}
F composition(F f, F g) {
  return F{f.flip^g.flip};
}
F id() {
  return F{0};
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<int> A(n);
  vector<S> s(n);
  rep(i, n) {
    cin >> A[i];
    s[i] = S{1-A[i], A[i], 0};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(s);
  rep(_, q) {
    int t, l, r; cin >> t >> l >> r;
    l--;
    if(t == 1) {
      seg.apply(l, r, F{1});
    } else {
      cout << seg.prod(l, r).inv << endk;
    }
  }
  return 0;
}
