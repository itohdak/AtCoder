#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to;
  ll cost;
  edge(int to, ll cost) : to(to), cost(cost) {}
};

void dfs(vector<vector<edge> >& G,
         vector<bool>& vis,
         vector<ll>& D,
         int tmp, int par, ll cost) {
  if(!vis[tmp]) {
    if(par != -1) {
      D[tmp] = D[par] + cost;
    }
    vis[tmp] = true;
    for(auto ne: G[tmp])
      dfs(G, vis, D, ne.to, tmp, ne.cost);
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<edge> > G(N);
  rep(i, N-1) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back(edge(b, c));
    G[b].push_back(edge(a, c));
  }
  int s;
  cin >> s;
  s--;
  vector<bool> vis(N);
  vector<ll> D(N);
  dfs(G, vis, D, s, -1, 0);
  rep(i, N)
    cout << i << ": " << D[i] << endl;
  return 0;
}

