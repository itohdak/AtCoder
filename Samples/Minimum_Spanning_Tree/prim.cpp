#include <bits/stdc++.h>
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

vector<vector<ll> > cost;
vector<pair<int, int> > conn; // result connections (edges in minimum spanning tree)
ll prim(int N) {
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
        mincost[u] =  cost[v][u];
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
