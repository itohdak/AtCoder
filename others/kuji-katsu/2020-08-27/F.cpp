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

vector<pair<ll, ll>> d;
ll l;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<pair<pair<ll, ll>, int>,
                 vector<pair<pair<ll, ll>, int>>,
                 greater<pair<pair<ll, ll>, int>>> que;
  d = vector<pair<ll, ll>>(N, {longinf, longinf});
  d[s] = {0, 0};
  que.push(make_pair(make_pair(0, 0), s));

  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[v].second + e.cost > l) {
        if(e.cost > l) continue;
        if(d[e.to] > make_pair(d[v].first+1, e.cost)) {
          d[e.to] = make_pair(d[v].first+1, e.cost);
          que.push(make_pair(d[e.to], e.to));
        }
      } else {
        if(d[e.to] > make_pair(d[v].first, d[v].second+e.cost)) {
          d[e.to] = make_pair(d[v].first, d[v].second+e.cost);
          que.push(make_pair(d[e.to], e.to));
        }
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  cin >> l;
  vector<vector<edge>> G(n);
  rep(i, m) {
    int a, b; cin >> a >> b;
    ll c; cin >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  vector<vector<ll>> ans(n, vector<ll>(n, longinf));
  rep(i, n) {
    dijkstra(i, n, G);
    // cout << d << endk;
    rep(j, n) ans[i][j] = d[j].first;
  }
  int q; cin >> q;
  rep(_, q) {
    int s, t; cin >> s >> t;
    s--; t--;
    cout << (ans[s][t]==longinf ? -1 : ans[s][t]) << endk;
  }
  return 0;
}
