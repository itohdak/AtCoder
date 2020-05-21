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

vector<vector<ll>> dist;
void warshall_floyd(int n) {
  rep(i, n)rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  dist = vector<vector<ll>>(N, vector<ll>(N, longinf));
  vector<ll> dist0(N, longinf);
  rep(i, M) {
    int u, v;
    ll l;
    cin >> u >> v >> l;
    --u, --v;
    if(u != 0 && v != 0) {
      dist[u][v] = dist[v][u] = l;
    } else {
      dist0[max(u, v)] = l;
    }
  }
  warshall_floyd(N);
  ll ans = longinf;
  REP(i, 1, N) REP(j, i+1, N) {
    ans = min(dist0[i]+dist[i][j]+dist0[j], ans);
  }
  cout << (ans==longinf ? -1 : ans) << endl;
  return 0;
}
