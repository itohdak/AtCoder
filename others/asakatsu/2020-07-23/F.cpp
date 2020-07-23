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

#define MAX_N 200005

class UnionFind
{
public:
  int par[MAX_N];
  int depth[MAX_N];
  int nGroup[MAX_N];

  UnionFind(int n) {
    init(n);
  }

  void init(int n) {
    for(int i=0; i<n; i++) {
      par[i] = i;
      depth[i] = 0;
      nGroup[i] = 1;
    }
  }

  int root(int x) {
    if(par[x] == x) {
      return x;
    } else {
      return par[x] = root(par[x]);
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if(x == y) return;

    if(depth[x] < depth[y]) {
      par[x] = y;
      nGroup[y] += nGroup[x];
      nGroup[x] = 0;
    } else {
      par[y] = x;
      nGroup[x] += nGroup[y];
      nGroup[y] = 0;
      if(depth[x] == depth[y])
        depth[x]++;
    }
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    uf.unite(x, y);
  }
  map<int, vector<int>> mp;
  rep(i, n) {
    mp[uf.root(i)].push_back(i);
  }
  // cerr << mp << endl;
  priority_queue<pair<int, int>> q;
  for(auto& ele: mp) {
    q.push({ele.second.size(), ele.first});
  }
  priority_queue<ll, vector<ll>, greater<ll>> q2;
  ll ans = 0;
  int root = mp[q.top().second].front();
  for(int i: mp[q.top().second]) q2.push(A[i]);
  q.pop();
  while(!q.empty()) {
    if(q2.empty()) break;
    auto ele = q.top(); q.pop();
    priority_queue<ll, vector<ll>, greater<ll>> q3;
    for(int i: mp[ele.second]) q3.push(A[i]);
    // cerr << q2.top() << ' ' << q3.top() << endl;
    ans += q2.top() + q3.top();
    uf.unite(root, mp[ele.second].front());
    q2.pop(); q3.pop();
    while(!q3.empty()) {
      q2.push(q3.top());
      q3.pop();
    }
  }
  bool ok = true;
  rep(i, n) {
    if(uf.root(i) != uf.root(root)) ok = false;
  }
  if(ok) cout << ans << "\n";
  else cout << "Impossible" << "\n";
  return 0;
}
