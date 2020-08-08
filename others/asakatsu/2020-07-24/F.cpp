#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  ll s; cin >> s;
  ll mx = 20000;
  vector<vector<edge>> G(n*mx);
  rep(i, m) {
    int u, v, a; ll b;
    cin >> u >> v >> a >> b;
    u--; v--;
    rep(j, mx) {
      if(j >= a) G[u*mx+j].push_back({int(v*mx+j-a), b});
      if(j >= a) G[v*mx+j].push_back({int(u*mx+j-a), b});
    }
  }
  rep(i, n) {
    ll c, d;
    cin >> c >> d;
    rep(j, mx) {
      G[i*mx+j].push_back({int(i*mx+min(j+c, mx-1)), d});
    }
  }
  dijkstra(min(s, mx-1), n*mx, G);
  rep(i, n) {
    if(i) {
      cout << *min_element(begin(d)+i*mx, begin(d)+(i+1)*mx) << "\n";
    }
  }
  return 0;
}
