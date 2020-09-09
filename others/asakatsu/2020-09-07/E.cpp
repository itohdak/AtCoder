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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, c; cin >> n >> c;
  vector<vector<int>> D(c, vector<int>(c));
  vector<vector<int>> C(n, vector<int>(n));
  rep(i, c) rep(j, c) cin >> D[i][j];
  rep(i, n) rep(j, n) {
    cin >> C[i][j];
    C[i][j]--;
  }
  vector<vector<ll>> cost(3, vector<ll>(c));
  rep(i, n) rep(j, n) {
    rep(k, c) cost[(i+j)%3][k] += D[C[i][j]][k];
  }
  ll ans = longinf;
  rep(i, c) rep(j, c) rep(k, c) {
    if(i != j && i != k && j != k) {
      chmin(ans, cost[0][i]+cost[1][j]+cost[2][k]);
    }
  }
  cout << ans << endk;
  return 0;
}
