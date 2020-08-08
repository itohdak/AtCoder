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
  int n, m; cin >> n >> m;
  vector<int> L(m), R(m);
  vector<ll> C(m);
  vector<ll> P;
  P.push_back(0);
  P.push_back(n-1);
  rep(i, m) {
    cin >> L[i] >> R[i] >> C[i];
    L[i]--; R[i]--;
    P.push_back(L[i]);
    P.push_back(R[i]);
  }
  sort(all(P));
  P.erase(unique(all(P)), end(P));
  vector<int> Li(m), Ri(m);
  int k = P.size();
  vector<vector<edge>> G(k);
  rep(i, m) {
    Li[i] = lower_bound(all(P), L[i]) - begin(P);
    Ri[i] = lower_bound(all(P), R[i]) - begin(P);
    G[Li[i]].push_back({Ri[i], C[i]});
  }
  rep(i, k-1) G[i+1].push_back({i, 0});
  dijkstra(0, k, G);
  cout << (d[k-1]==longinf ? -1 : d[k-1]) << "\n";
  return 0;
}
