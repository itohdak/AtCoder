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

using mint = modint998244353;
mint pw[200050];
mint pwsum[200050];
struct S {
  mint val;
  int size;
};
struct F {
  mint n;
};
S op(S a, S b) {
  return S{a.val*pw[b.size]+b.val, a.size+b.size};
}
S e() {
  return S{0, 0};
}
S mapping(F f, S x) {
  if(f.n == 0) return x;
  else return S{pwsum[x.size]*f.n, x.size};
}
F composition(F f, F g) {
  // return (g.n == 0 ? f : g);
  return (f.n == 0 ? g : f);
}
F id() {
  return F{0};
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(i, 200050) {
    if(i == 0) pw[i] = 1;
    else pw[i] = pw[i-1] * 10;
  }
  rep(i, 200050) {
    if(i!=200049) pwsum[i+1] = pwsum[i] + pw[i];
  }
  int n, q; cin >> n >> q;
  vector<S> init(n, S{1, 1});
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
  rep(_, q) {
    int l, r, d; cin >> l >> r >> d;
    l--;
    seg.apply(l, r, F{d});
    cout << seg.prod(0, n).val.val() << endk;
  }
  return 0;
}
