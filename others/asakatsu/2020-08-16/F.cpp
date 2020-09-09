#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

template< typename Monoid >
struct SegmentTree {
  using F = function< Monoid(Monoid, Monoid) >;

  int sz;
  vector< Monoid > seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> A(n); rep(i, n) cin >> A[i];
  SegmentTree<int> seg(n, [](int a, int b) { return min(a, b); }, INT_MAX);
  rep(i, n) seg.update(i, A[i]);
  auto bsearchl = [&](int i) {
                    auto test = [&](int k) {
                                  return (seg.query(k, i+1) == A[i]);
                                };
                    int ok = i, ng = -1;
                    while(ok-ng>1) {
                      int mid = (ok+ng)/2;
                      (test(mid) ? ok : ng) = mid;
                    }
                    return ok;
                  };
  auto bsearchr = [&](int i) {
                    auto test = [&](int k) {
                                  return (seg.query(i, k+1) == A[i]);
                                };
                    int ok = i, ng = n;
                    while(ng-ok>1) {
                      int mid = (ok+ng)/2;
                      (test(mid) ? ok : ng) = mid;
                    }
                    return ok;
                  };
  ll ans = 0;
  rep(i, n) {
    int l = bsearchl(i);
    int r = bsearchr(i);
    ans += 1LL * A[i] * (i-l+1) * (r-i+1);
  }
  cout << ans << endk;
  return 0;
}
