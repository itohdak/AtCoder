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

#define MAX_N 100000

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
  double cost;
  edge(int _u, int _v, double _cost) : u(_u), v(_v), cost(_cost) {}
};

vector<edge> es;
bool comp(const edge& e1, const edge& e2) {
  return e1.cost < e2.cost;
}

vector<pair<int, int> > conn;
double kruskal(int N) {
  sort(es.begin(), es.end(), comp);
  UnionFind uf(N);
  double res = 0;
  rep(i, es.size()) {
    edge e = es[i];
    if(!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
      // conn.push_back(make_pair(e.u, e.v));
    }
  }
  return res;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<double> X(N+M), Y(N+M);
  vector<int> C(N+M);
  rep(i, N+M) cin >> X[i] >> Y[i] >> C[i];

  vector<vector<double>> cost(N+M, vector<double>(N+M));
  rep(i, N+M) REP(j, i+1, N+M) {
    double dx = X[i]-X[j], dy = Y[i]-Y[j];
    cost[j][i] = cost[i][j] = sqrt(dx*dx+dy*dy) * (C[i]==C[j] ? 1 : 10);
  }

  double mn = longinf;
  rep(n, 1<<M) {
    es = vector<edge>();
    vector<int> vs;
    rep(i, N) vs.push_back(i);
    rep(i, M) if((n>>i)&1) vs.push_back(N+i);
    int m = vs.size();
    rep(i, m) REP(j, i+1, m) es.push_back(edge(i, j, cost[vs[i]][vs[j]]));
    mn = min(kruskal(m), mn);
  }
  cout << setprecision(10) << mn << endl;
  return 0;
}
