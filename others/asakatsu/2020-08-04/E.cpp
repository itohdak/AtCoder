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
  string f, l; cin >> f >> l;
  int n; cin >> n;
  vector<string> S(n+2);
  S[n] = f, S[n+1] = l;
  rep(i, n) cin >> S[i];
  vector<vector<edge>> G(n+2);
  int m = S[0].size();
  rep(i, n+2) REP(j, i+1, n+2) {
    int diff = 0;
    rep(k, m) if(S[i][k] != S[j][k]) diff++;
    if(diff == 1) {
      G[i].push_back({j, 1});
      G[j].push_back({i, 1});
    }
  }
  dijkstra(n, n+2, G);
  if(f == l) {
    cout << 0 << endk;
    cout << f << endk << l << endk;
  } else if(d[n+1] == longinf) {
    cout << -1 << endk;
  } else {
    // cout << d[n+1]-1 << endk;
    vector<int> path;
    int cur = n+1;
    while(cur != n) {
      path.push_back(cur);
      cur = par[cur];
    }
    path.push_back(n);
    reverse(all(path));
    assert(path.size()-1 == d[n+1]);
    cout << path.size()-2 << endk;
    for(int i: path) cout << S[i] << endk;
  }
  return 0;
}
