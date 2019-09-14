#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<pair<int, int> > G[100005];
vector<pair<int, pair<int, int> > > Col[100005];

class LCA {
public:
    int V, logV;
    vector<int> depth, len;
    vector<vector<int> > parent;
    vector<vector<int> > n_color;
    vector<vector<int> > len_color;

    LCA(int V) {
        this->V = V;
        logV = 0;
        while (V > (1LL<<logV)) logV++;
        this->depth = vector<int>(V);
        this->len = vector<int>(V);
        this->n_color = vector<vector<int> >(V, vector<int>(V));
        this->len_color = vector<vector<int> >(V, vector<int>(V));
        this->parent = vector<vector<int> >(logV, vector<int>(V));
    }

    void init(int v, int par, int d, int l, int col=-1, int len_col=0) {
        depth[v] = d;
        parent[0][v] = par;
        len[v] = l;
        if(par != -1) {
          rep(i, v) {
            n_color[v][i] = n_color[par][i];
            len_color[v][i] = len_color[par][i];
            if(i == col) {
              n_color[v][i]++;
              len_color[v][i] += len_col;
            }
          }
        }
        for (int i = 0; i < (int)G[v].size(); i++) {
            int w = G[v][i].first;
            int lc = G[v][i].second;
            int col = Col[v][i].second.first;
            int len_col = Col[v][i].second.second;
            if (w == par) continue;
            init(w, v, d+1, lc + l, col, len_col);
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
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N), C(N), D(N);
  rep(i, N-1) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--; B[i]--; C[i]--;
    G[A[i]].push_back(make_pair(B[i], D[i]));
    G[B[i]].push_back(make_pair(A[i], D[i]));
    Col[A[i]].push_back(make_pair(B[i], make_pair(C[i], D[i])));
    Col[B[i]].push_back(make_pair(A[i], make_pair(C[i], D[i])));
  }

  LCA lca(N);
  lca.init(0, -1, 0, 0);
  lca.build();

  rep(i, Q) {
    int x, y, u, v;
    cin >> x >> y >> u >> v;
    x--;
    int z = lca.query(--u, --v);
    int ret = (lca.len[u] - lca.len_color[u][x] + lca.n_color[u][x] * y)
            + (lca.len[v] - lca.len_color[v][x] + lca.n_color[v][x] * y)
            - 2 * (lca.len[z] - lca.len_color[z][x] + lca.n_color[z][x] * y);
    cout << ret << endl;
  }
  return 0;
}

