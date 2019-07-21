#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

#define MAX_N 40000
vector<pair<int, int> > G[MAX_N];

class LCA {
public:
  int V, logV;
  vector<int> depth, len;
  vector<vector<int> > parent; // parent[i][v]: ノードvの(i+1)個上の親

  LCA(int V) {
    this->V = V;
    logV = 0;
    while (V > (1LL<<logV)) logV++;
    this->depth = vector<int>(V);
    this->len = vector<int>(V);
    this->parent = vector<vector<int> >(logV, vector<int>(V));
  }

  void init(int v, int par, int d, int l) {
    depth[v] = d;       // rootからの深さ
    parent[0][v] = par; // 親
    len[v] = l;         // rootからの距離
    for (int i = 0; i < (int)G[v].size(); i++) {
      int w = G[v][i].first;   // 子ノード
      int lc = G[v][i].second; // 子ノードとの距離
      if (w == par) continue;
      init(w, v, d+1, lc + l);
    }
  }

  void build() {
    for (int k = 0; k + 1 < logV; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }

  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < logV; k++) {
      if ((depth[v] - depth[u]) >> k & 1)
        v = parent[k][v];
    }
    if (u == v) return u;

    for (int k = logV-1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

int main() {
  int N, M;
  cin >> N >> M;

  rep(i, M) {
    int x, y, d;
    cin >> x >> y >> d;
    x--; y--;
    G[x].push_back(make_pair(y, d));
    G[y].push_back(make_pair(x, d));
  }

  LCA lca(N);
  lca.init(0, -1, 0, 0);
  lca.build();

  int Q;
  cin >> Q;
  rep(q, Q) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    int z = lca.query(x, y);
    int ret = lca.len[x] + lca.len[y] - 2 * lca.len[z];
    cout << ret << endl;
  }

  return 0;
}

