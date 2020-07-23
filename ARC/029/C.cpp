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

#define MAX_N 200050

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

struct edge {
  int u;
  int v;
  ll cost;
  edge(int _u, int _v, ll _cost) : u(_u), v(_v), cost(_cost) {}
};

bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

vector<pair<int, int>> conn;
ll kruskal(int N, vector<edge>& es) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(N);
  ll res = 0;
  rep(i, es.size()) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      conn.push_back(make_pair(e.u, e.v));
    }
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<edge> es;
  rep(i, n) {
    ll c; cin >> c;
    es.push_back({n, i, c});
  }
  rep(i, m) {
    int a, b;
    ll r;
    cin >> a >> b >> r;
    a--; b--;
    es.push_back({a, b, r});
    es.push_back({b, a, r});
  }
  cout << kruskal(n+1, es) << "\n";
  return 0;
}
