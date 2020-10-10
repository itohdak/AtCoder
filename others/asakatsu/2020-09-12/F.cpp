#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

ll dist[500][500];
void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    chmin(dist[j][k], dist[j][i] + dist[i][k]);
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  rep(i, n) rep(j, n) {
    dist[i][j] = (i==j ? 0 : longinf);
  }
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    chmin(dist[a][b], c);
    chmin(dist[b][a], c);
  }
  warshall_floyd(n);
  int k; cin >> k;
  rep(_, k) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    rep(i, n) rep(j, n) {
      chmin(dist[i][j], dist[i][x] + z + dist[y][j]);
      chmin(dist[i][j], dist[i][y] + z + dist[x][j]);
    }
    ll ans = 0;
    rep(i, n) REP(j, i+1, n) ans += dist[i][j];
    cout << ans << endk;
  }
  return 0;
}
