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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n), sum(n+1);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  vector<pair<ll, int>> v;
  rep(i, n+1) {
    v.push_back({sum[i]-k*i, i});
  }
  sort(all(v));
  BinaryIndexedTree<int> bit(n+1);
  ll ans = 0;
  rep(i, n+1) {
    ans += bit.sum(v[i].second);
    bit.add(v[i].second, 1);
  }
  cout << ans << "\n";
  return 0;
}
