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
  int N, M;
  cin >> N >> M;
  dist = vector<vector<ll>>(N, vector<ll>(N, longinf));
  rep(i, N) dist[i][i] = 0;
  rep(i, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }

  warshall_floyd(N);

  int K;
  cin >> K;
  rep(k, K) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    dist[x][y] = min(dist[x][y], (ll)z);
    dist[y][x] = min(dist[y][x], (ll)z);
    rep(i, N) rep(j, N) {
      dist[i][j] = min({dist[i][x]+dist[x][y]+dist[y][j],
                        dist[i][y]+dist[y][x]+dist[x][j],
                        dist[i][j]});
    }
    ll ans = 0;
    rep(i, N) REP(j, i+1, N) {
      ans += dist[i][j];
    }
    cout << ans << endl;
  }

  return 0;
}
