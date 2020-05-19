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
vector<ll> ds, dt;
// vector<int> par;
void dijkstra(int s, vector<ll>& d) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<ll>(N, longinf);
  // par = vector<int>(N, -1);
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
        // par[e.to] = v;
      }
    }
  }
}
int main() {
  int M, s, t;
  cin >> N >> M >> s >> t;
  --s, --t;
  G = vector<vector<edge>>(N);
  rep(i, M) {
    int x, y, d;
    cin >> x >> y >> d;
    --x, --y;
    G[x].emplace_back(y, d);
    G[y].emplace_back(x, d);
  }
  dijkstra(s, ds);
  dijkstra(t, dt);
  rep(i, N) {
    if(i == s || i == t) continue;
    if(ds[i] != longinf && dt[i] != longinf &&
       ds[i] == dt[i]) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
