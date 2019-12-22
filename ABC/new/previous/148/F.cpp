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
// template<class t, class u>
// ostream& operator<<(ostream& os, const pair<t, u>& p) {
//   return os << "{" << p.first << ", " << p.second << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const vector<t>& v) {
//   os << "{";
//   rep(i, v.size()) { if(i) os << ", "; os << v[i]; }
//   return os << "}";
// }
// template<class t> ostream& operator<<(ostream& os, const set<t>& se) {
//   os << "{";
//   auto itr = se.begin();
//   rep(i, se.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
// template<class t, class u>
// ostream& operator<<(ostream& os, const map<t, u>& mp) {
//   os << "{";
//   auto itr = mp.begin();
//   rep(i, mp.size()) { if(i) os << ", "; os << *itr; itr++; }
//   return os << "}";
// }
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

vector<vector<edge> > G;
vector<bool> vis;
vector<ll> D;
vector<int> leaves;
int N, u, v;

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
      int w = G[v][i].to;   // 子ノード
      int lc = G[v][i].cost; // 子ノードとの距離
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

void dfs(int tmp, int par, ll cost) {
  if(!vis[tmp]) {
    if(par != -1) {
      D[tmp] = D[par] + cost;
    }
    vis[tmp] = true;
    for(auto ne: G[tmp])
      dfs(ne.to, tmp, ne.cost);
    if(G[tmp].size()-1==0) leaves.push_back(tmp);
  }
}

int main() {
  cin >> N >> u >> v;
  u--; v--;
  G = vector<vector<edge> >(N);
  vis = vector<bool>(N);
  D = vector<ll>(N);
  vector<int> A(N-1), B(N-1);
  rep(i, N-1) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    G[A[i]].push_back(edge(B[i], 1));
    G[B[i]].push_back(edge(A[i], 1));
  }

  LCA lca(N);
  lca.init(v, -1, 0, 0);
  lca.build();

  D[v] = 0;
  dfs(v, -1, 0);

  ll ans = 0;
  for(int l: leaves) {
    if(l == v) continue;
    int z = lca.query(u, l);
    if(2 * D[z] - D[u] >= 0) {
      ans = max(D[l]-1, ans);
    }
  }
  cout << ans << endl;
  return 0;
}

