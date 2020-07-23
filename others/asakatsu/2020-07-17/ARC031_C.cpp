#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
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
  int n; cin >> n;
  vector<int> B(n), id(n);
  rep(i, n) {
    cin >> B[i];
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
      return B[i] > B[j];
    });
  BinaryIndexedTree<int> bit(n);
  ll ans = 0;
  rep(i, n) {
    int cur = id[i];
    int cntl = bit.sum(cur);
    int cntr = i-cntl;
    ans += min(cntl, cntr);
    bit.add(cur, 1);
  }
  cout << ans << "\n";
  return 0;
}
