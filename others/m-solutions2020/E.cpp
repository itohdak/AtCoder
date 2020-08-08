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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n), Y(n), P(n);
  rep(i, n) cin >> X[i] >> Y[i] >> P[i];
  vector<vector<ll>> xmin(1<<n, vector<ll>(n)), ymin(1<<n, vector<ll>(n));
  rep(i, 1<<n) {
    rep(j, n) {
      xmin[i][j] = abs(X[j]);
      ymin[i][j] = abs(Y[j]);
    }
    rep(k, n) {
      if((i>>k)&1) {
        rep(j, n) {
          xmin[i][j] = min(abs(X[j]-X[k]), xmin[i][j]);
          ymin[i][j] = min(abs(Y[j]-Y[k]), ymin[i][j]);
        }
      }
    }
  }
  vector<ll> ans(n+1, longinf);
  auto dfs = [&](auto dfs, int i, ll xb, ll yb) -> void {
    if(i == n) {
      ll cost = 0;
      rep(j, n) cost += P[j] * min(xmin[xb][j], ymin[yb][j]);
      int cnt = __builtin_popcount(xb) + __builtin_popcount(yb);
      if(cnt > n) return;
      ans[cnt] = min(cost, ans[cnt]);
      return;
    }
    dfs(dfs, i+1, xb, yb);
    dfs(dfs, i+1, xb|(1<<i), yb);
    dfs(dfs, i+1, xb, yb|(1<<i));
  };
  dfs(dfs, 0, 0, 0);

  /* dummy */
  // vector<ll> pw(n+1);
  // pw[0] = 1;
  // rep(i, n) pw[i+1] = pw[i] * 3;
  // rep(i, pw[n]) {
  //   ll x = 0, y = 0;
  //   rep(j, n) {
  //     if(i/pw[j]%3 == 1) {
  //       x |= 1<<j;
  //     } else if(i/pw[j]%3 == 2) {
  //       y |= 1<<j;
  //     }
  //   }
  //   ll cur = 0;
  //   rep(j, n) cur += P[j] * min(xmin[x][j], ymin[y][j]);
  //   int cnt = __builtin_popcount(x) + __builtin_popcount(y);
  //   if(cnt > n) continue;
  //   assert(0<=cnt && cnt<=n);
  //   if(cur < ans[cnt]) ans[cnt] = cur;
  // }
  /* dummy */

  rep(i, n+1) cout << ans[i] << "\n";
  return 0;
}
