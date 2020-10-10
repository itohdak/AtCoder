#include "header.hpp"

vector<pair<int, int>> conn; // result connections (edges in minimum spanning tree)
ll prim(int N, vector<vector<ll>>& cost) {
  vector<ll> mincost(N, inf);
  vector<bool> used(N, false);
  vector<int> from(N);
  mincost[0] = 0;

  ll res = 0;
  while(true) {
    int v = -1;
    rep(u, N) { if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u; }
    if(v == -1) break; // all vertices are covered
    used[v] = true;
    res += mincost[v];
    if(v != 0) { conn.push_back(make_pair(v, from[v])); }
    rep(u, N) {
      if(cost[v][u] < mincost[u]) {
        mincost[u] = cost[v][u];
        from[u] = v;
      }
    }
  }
  return res;
}

/*
  プリム法
  最小全域木を求める手法．
  最初，ある一つの頂点vのみからなる木Tを考え，そこから貪欲的にTとTに含まれていないその他の頂点を結ぶ最小コストの辺をTに付け加えることを繰り返して，全域木を構成していく．
  計算量はO(E log V)．
*/
