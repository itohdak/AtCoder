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
  int N;
  cin >> N;
  vector<int> B(N);
  priority_queue<pair<int, int>> q;
  rep(i, N) {
    cin >> B[i];
    q.emplace(B[i], i);
  }
  BinaryIndexedTree<int> bit(N);
  ll ans = 0;
  int cnt = 0;
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    int l = bit.sum(ele.second);
    int r = cnt-l;
    ans += min(l, r);
    bit.add(ele.second, 1);
    cnt++;
  }
  cout << ans << "\n";
  return 0;
}
