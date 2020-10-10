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

vector<ll> dist;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  dist = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  dist[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(dist[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(dist[e.to] > dist[v] + e.cost) {
        dist[e.to] = dist[v] + e.cost;
        que.push(P(dist[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, d, k; cin >> n >> m >> d >> k;
  vector<pair<int, int>> P(n);
  vector<vector<int>> grid(1000, vector<int>(1000, -1));
  rep(i, n) {
    cin >> P[i].first >> P[i].second;
    grid[P[i].first][P[i].second] = i;
  }
  vector<vector<edge>> G(n);
  rep(i, n) {
    for(int x=max(0, P[i].first-d); x<=min(999, P[i].first+d); x++) {
      for(int y=max(0, P[i].second-d); y<=min(999, P[i].second+d); y++) {
        if(grid[x][y] == -1 || grid[x][y] == i) continue;
        int j = grid[x][y];
        int dx = P[i].first-P[j].first;
        int dy = P[i].second-P[j].second;
        if(dx*dx+dy*dy <= d*d) {
          G[i].push_back({j, 1});
        }
      }
    }
  }
  dijkstra(0, n, G);
  int ans = 0;
  // cout << dist << endk;
  rep(i, n) if(k-m < dist[i] && dist[i] <= k) ans++;
  cout << ans << endk;
  return 0;
}
