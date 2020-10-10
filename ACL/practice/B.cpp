#include <bits/stdc++.h>
#include <atcoder/all>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  vector<ll> A(n);
  fenwick_tree<ll> bit(n);
  rep(i, n) {
    cin >> A[i];
    bit.add(i, A[i]);
  }
  rep(_, q) {
    int t; cin >> t;
    if(t == 0) {
      int p; ll x; cin >> p >> x;
      bit.add(p, x);
    } else {
      int l, r; cin >> l >> r;
      cout << bit.sum(l, r) << endk;
    }
  }
  return 0;
}
