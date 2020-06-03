#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

template< typename T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int Q;
  cin >> Q;
  int mx = 200001;
  BinaryIndexedTree<int> bit(mx);
  auto binary_search = [&](int x) {
    ll ng = 0, ok = mx;
    while(abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if(bit.sum(mid) >= x) ok = mid;
      else ng = mid;
    }
    return ok;
  };
  rep(q, Q) {
    int t, x;
    cin >> t >> x;
    if(t == 1) {
      bit.add(x, 1);
    } else {
      int res = binary_search(x);
      cout << res << endl;
      bit.add(res, -1);
    }
  }
  return 0;
}
