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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

struct edge {
  int to;
  ld cost;
  edge(int t, ld c): to(t), cost(c) {};
};

using P = pair<ld, int>;

vector<ld> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ld>(N, longinf);
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
  int n; cin >> n;
  vector<int> X(n), Y(n), T(n), R(n);
  rep(i, n) {
    cin >> X[i] >> Y[i] >> T[i] >> R[i];
  }
  vector<vector<edge>> G(n);
  rep(i, n) rep(j, n) {
    if(i == j) continue;
    ll dx = X[i]-X[j];
    ll dy = Y[i]-Y[j];
    G[i].push_back({j, sqrt((ld)dx*dx+dy*dy)/min(T[i], R[j])});
  }
  dijkstra(0, n, G);
  ld mx = 0;
  sort(all(d));
  rep(i, n) {
    if(i == 0) continue;
    mx = max(d[i]+n-1-i, mx);
  }
  cout << fixed << setprecision(10) << mx << endk;
  return 0;
}
