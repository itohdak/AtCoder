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

vector<vector<ll>> dist;
void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, r; cin >> n >> m >> r;
  vector<int> R(r);
  rep(i, r) {
    cin >> R[i];
    R[i]--;
  }
  dist = vector<vector<ll>>(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;
  rep(i, m) {
    int a, b; ll c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  warshall_floyd(n);
  ll ans = longinf;
  auto dfs = [&](auto dfs, int prev, int done, ll cost) -> void {
    if(done==(1<<r)-1) {
      ans = min(cost, ans);
      return;
    }
    rep(i, r) {
      if((done>>i)&1) continue;
      dfs(dfs, i, done|(1<<i), cost+dist[R[prev]][R[i]]);
    }
  };
  rep(i, r) dfs(dfs, i, 1<<i, 0);
  cout << ans << "\n";
  return 0;
}
