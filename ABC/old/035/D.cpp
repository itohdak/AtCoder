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
vector<vector<edge>> G1, G2;
vector<ll> d1, d2;
// vector<int> par;
void dijkstra(int s, vector<vector<edge>>& G, vector<ll>& d) {
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
  int M;
  ll T;
  cin >> N >> M >> T;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  G1 = vector<vector<edge>>(N);
  G2 = vector<vector<edge>>(N);
  rep(i, M) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a, --b;
    G1[a].push_back(edge(b, c));
    G2[b].push_back(edge(a, c));
  }
  dijkstra(0, G1, d1);
  dijkstra(0, G2, d2);
  ll ans = 0;
  rep(i, N) ans = max(A[i]*max(T-d1[i]-d2[i], 0LL), ans);
  cout << ans << endl;
  return 0;
}
