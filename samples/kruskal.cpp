#include "header.hpp"

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

/*
  クラスカル法
  最小全域木を求める手法
  すべての辺をコストの小さい順にみていき，閉路ができなければ追加していく．
  閉路ができるかどうかは，追加しようとしている辺eが結ぶ頂点uと頂点vが同じ連結成分に属しているかで判断できる．
  同じ成分に属しているかどうかはUnion-Find木を用いて判定できる．
*/
