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

int N;
vector<vector<edge>> G;
vector<ll> d;
vector<int> par;
int H, W;
void dijkstra(int s) {
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
  return x * W + y;
}
bool in(int x, int y) {
  return 0 <= x && x < H && 0 <= y && y < W;
}
int main() {
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];
  N = H*W;
  G = vector<vector<edge>>(N);
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  int s, g;
  rep(i, H) rep(j, W) {
    if(S[i][j] == 's') s = pos2int(i, j);
    if(S[i][j] == 'g') g = pos2int(i, j);
    rep(k, 4) {
      int nx = i+dx[k];
      int ny = j+dy[k];
      int c = (S[i][j] == '#' ? 1 : 0);
      if(in(nx, ny)) G[pos2int(i, j)].push_back(edge(pos2int(nx, ny), c));
    }
  }
  dijkstra(s);
  cout << (d[g]<=2 ? "YES" : "NO") << endl;
  return 0;
}
