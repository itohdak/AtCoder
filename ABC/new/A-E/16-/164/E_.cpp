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
struct edge {
  int to;
  int cost;
  edge(int t, int c): to(t), cost(c) {};
};
using P = pair<int, int>;
int N;
vector<vector<edge>> G;
vector<ll> d;
void dijkstra(int N, int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<ll>(N, longinf);
  d[s] = 0;
  que.push(P(0, s));
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i=0; i<G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
      }
    }
  }
}
int main(){
  int n, m;
  ll s;
  cin >> n >> m >> s;
  int N = 2501*n;
  G = vector<vector<edge>>(N);
  rep(i, m) {
    int u, v, a;
    ll b;
    cin >> u >> v >> a >> b;
    --u, --v;
    rep(i, 2501) if(i>=a) {
      G[2501*u+i].push_back(edge(2501*v+i-a, b));
      G[2501*v+i].push_back(edge(2501*u+i-a, b));
    }
  }
  rep(i, n) {
    ll c, d;
    cin >> c >> d;
    rep(j, 2501) {
      if(j+c<2501) G[2501*i+j].push_back(edge(2501*i+j+c, d));
    }
  }
  dijkstra(N, min(2500LL, s));
  rep(i, n) if(i) {
    ll ans = longinf;
    rep(j, 2501) ans = min(d[2501*i+j], ans);
    cout << ans << endl;
  }
  return 0;
}
