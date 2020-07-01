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

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

class LCA {
public:
  int V, logV;
  vector<int> depth, len;
  vector<vector<int> > parent; // parent[i][v]: ノードvの(i+1)個上の親

  LCA(int V) {
    this->V = V;
    logV = 0;
    while(V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->len = vector<int>(V);
    this->parent = vector<vector<int> >(logV, vector<int>(V));
  }

  void init(int v, int par, int d, int l, vector<vector<edge>>& G) {
    depth[v] = d;       // rootからの深さ
    parent[0][v] = par; // 親
    len[v] = l;         // rootからの距離
    for(int i=0; i<(int)G[v].size(); i++) {
      int w = G[v][i].to;   // 子ノード
      int lc = G[v][i].cost; // 子ノードとの距離
      if(w == par) continue;
      init(w, v, d+1, lc + l, G);
    }
  }

  void build() {
    for(int k=0; k+1<logV; k++) {
      for(int v=0; v<V; v++) {
        if(parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  int query(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    for(int k=0; k<logV; k++) {
      if((depth[v] - depth[u]) >> k & 1)
        v = parent[k][v];
    }
    if(u == v) return u;

    for(int k=logV-1; k>=0; k--) {
      if(parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<vector<edge>> G(N);
  map<pair<int, int>, int> mp;
  rep(i, N-1) {
    int a, b;
    cin >> a >> b; a--; b--;
    G[a].push_back({b, 1});
    G[b].push_back({a, 1});
    mp[{min(a, b), max(a, b)}] = i;
  }
  LCA lca(N);
  lca.init(0, -1, 0, 0, G);
  lca.build();
  int M;
  cin >> M;
  vector<bitset<50>> onPath(M);
  rep(i, M) {
    int u, v;
    cin >> u >> v; u--; v--;
    int z = lca.query(u, v);
    int cur = u;
    while(cur != z) {
      if(!mp.count({min(cur, lca.parent[0][cur]),
              max(cur, lca.parent[0][cur])})) {
        cout << "something wrong\n";
      }
      int e = mp[{min(cur, lca.parent[0][cur]),
                  max(cur, lca.parent[0][cur])}];
      onPath[i].set(e);
      cur = lca.parent[0][cur];
    }
    cur = v;
    while(cur != z) {
      if(!mp.count({min(cur, lca.parent[0][cur]),
              max(cur, lca.parent[0][cur])})) {
        cout << "something wrong\n";
      }
      int e = mp[{min(cur, lca.parent[0][cur]),
                  max(cur, lca.parent[0][cur])}];
      onPath[i].set(e);
      cur = lca.parent[0][cur];
    }
  }
  ll ans = 0;
  rep(i, 1<<M) {
    int n = __builtin_popcount(i);
    bitset<50> onPaths;
    rep(j, M) if((i>>j)&1) onPaths |= onPath[j];
    int m = onPaths.count();
    ans += (n%2 ? -1 : 1) * (1LL<<(N-1-m));
  }
  cout << ans << "\n";
  return 0;
}
