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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

int H, W, N;
vector<vector<edge>> G;
vector<ll> d1, d2, d3;
vector<int> par1, par2, par3;
void dijkstra(int s, vector<ll>& d, vector<int>& par) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    for (int i=0; i<(int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}
int pos2int(int x, int y) {
  return x*W+y;
}
int main() {
  cin >> H >> W;
  N = H * W;
  G = vector<vector<edge>>(N);
  vector<vector<int>> A(H, vector<int>(W));
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  rep(i, H) rep(j, W) {
    cin >> A[i][j];
    rep(k, 4) {
      int nx=i+dx[k], ny=j+dy[k];
      if(0 <= nx && nx < H && 0 <= ny && ny < W) {
        G[pos2int(nx, ny)].push_back(edge(pos2int(i, j), A[i][j]));
      }
    }
  }
  dijkstra(pos2int(H-1, W-1), d1, par1);
  dijkstra(pos2int(0, W-1), d2, par2);
  dijkstra(pos2int(H-1, 0), d3, par3);
  ll ans = longinf;
  rep(i, H) rep(j, W) {
    ll d = d1[pos2int(i, j)] + d2[pos2int(i, j)] + d3[pos2int(i, j)] - 2 * A[i][j];
    ans = min(d, ans);
  }
  cout << ans << endl;
  return 0;
}
