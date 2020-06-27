#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to, cost;
  edge(int to, int cost) : to(to), cost(cost) {}
};
vector<vector<edge>> G;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, P;
  cin >> N >> M >> P;
  G = vector<vector<edge>>(N);
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, -(c-P)});
  }

  vector<ll> dist;
  vector<int> par;
  auto bellman_ford = [&](int n, int s) {
    dist = vector<ll>(n, longinf);
    par = vector<int>(n, -1);
    dist[s] = 0;
    rep(i, n) {
      rep(v, n) {
        for(auto e: G[v]) {
          if(dist[v] != longinf && dist[e.to] > dist[v] + e.cost) {
            dist[e.to] = dist[v] + e.cost;
            par[e.to] = v;
            if(i == n-1) return true;
          }
        }
      }
    }
    return false;
  };

  bellman_ford(N, 0);

  cout << max(-dist[N-1], 0LL) << "\n";
  return 0;
}
