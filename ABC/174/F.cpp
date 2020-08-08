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
  int n, q; cin >> n >> q;
  vector<int> C(n);
  rep(i, n) {
    cin >> C[i];
    C[i]--;
  }
  vector<pair<int, int>> Q(q);
  vector<int> id(q);
  rep(i, q) {
    cin >> Q[i].first >> Q[i].second;
    Q[i].first--; Q[i].second--;
    id[i] = i;
  }
  sort(all(id), [&](int i, int j) {
      return Q[i].second < Q[j].second;
    });
  vector<int> last(n, -1);
  BinaryIndexedTree<int> bit(n);
  int tmp = -1;
  vector<int> ans(q);
  rep(i, q) {
    while(tmp < Q[id[i]].second) {
      tmp++;
      if(last[C[tmp]] != -1) bit.add(last[C[tmp]], -1);
      last[C[tmp]] = tmp;
      bit.add(tmp, 1);
    }
    ans[id[i]] = bit.sum(Q[id[i]].second) - bit.sum(Q[id[i]].first-1);
  }
  rep(i, q) cout << ans[i] << "\n";
  return 0;
}
