#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

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
  int n, m; ll s; cin >> n >> m >> s;
  int mx = 10000;
  vector<int> U(m), V(m), A(m);
  vector<ll> B(m), C(n), D(n);
  rep(i, m) {
    cin >> U[i] >> V[i] >> A[i] >> B[i];
    U[i]--; V[i]--;
  }
  rep(i, n) cin >> C[i] >> D[i];
  vector<vector<edge>> G(n*mx);
  rep(i, m) {
    rep(j, mx) {
      if(j < A[i]) continue;
      G[U[i]*mx+j].push_back({V[i]*mx+j-A[i], B[i]});
      G[V[i]*mx+j].push_back({U[i]*mx+j-A[i], B[i]});
    }
  }
  rep(i, n) {
    rep(j, mx) {
      G[i*mx+j].push_back({i*mx+(int)min(j+C[i], (ll)mx-1), D[i]});
    }
  }
  dijkstra((int)min(s, (ll)mx-1), n*mx, G);
  // cout << d << endk;
  rep(i, n) {
    if(i == 0) continue;
    cout << *min_element(d.begin()+i*mx, d.begin()+(i+1)*mx) << endk;
  }
  return 0;
}
