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
  int n, q; cin >> n >> q;
  vector<int> C(n);
  rep(i, n) {
    cin >> C[i];
    C[i]--;
  }
  vector<pair<int, int>> p(q);
  vector<int> id(q);
  rep(i, q) {
    cin >> p[i].first >> p[i].second;
    p[i].first--; p[i].second--;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
    return p[i].second < p[j].second;
  });
  vector<int> prev(n, -1);
  BinaryIndexedTree<int> bit(n);
  int j = 0;
  vector<int> ans(q);
  rep(i, n) {
    if(prev[C[i]] != -1) {
      bit.add(prev[C[i]], -1);
    }
    bit.add(i, 1);
    prev[C[i]] = i;
    while(j < q && p[id[j]].second == i) {
      ans[id[j]] = bit.sum(p[id[j]].second) - bit.sum(p[id[j]].first-1);
      j++;
    }
  }
  rep(i, q) cout << ans[i] << endk;
  return 0;
}
