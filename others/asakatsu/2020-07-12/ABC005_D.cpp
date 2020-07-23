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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<vector<ll>> D(n+1, vector<ll>(n+1));
  rep(i, n) rep(j, n) cin >> D[i+1][j+1];
  rep(i, n) rep(j, n) D[i+1][j+1] += D[i+1][j];
  rep(j, n) rep(i, n) D[i+1][j+1] += D[i][j+1];
  vector<ll> ans(n*n+1);
  REP(h, 1, n+1) REP(w, 1, n+1) {
    rep(i, n-h+1) rep(j, n-w+1) {
      ans[h*w] = max(ans[h*w], D[i+h][j+w]-D[i][j+w]-D[i+h][j]+D[i][j]);
    }
  }
  rep(i, n*n+1) if(i) ans[i] = max(ans[i], ans[i-1]);
  int q; cin >> q;
  while(q--) {
    int p; cin >> p;
    cout << ans[p] << "\n";
  }
  return 0;
}
