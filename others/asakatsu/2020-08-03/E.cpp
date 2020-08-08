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
  ll n, c; cin >> n >> c;
  vector<vector<ll>> D(c, vector<ll>(c));
  rep(i, c) rep(j, c) cin >> D[i][j];
  vector<vector<ll>> C(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> C[i][j];
  vector<map<ll, ll>> cnt(3);
  rep(i, n) rep(j, n) {
    cnt[(i+j)%3][C[i][j]-1]++;
  }
  ll ans = longinf;
  vector<bool> used(c);
  auto dfs = [&](auto dfs, int k, ll cost) {
    if(k == 3) {
      ans = min(cost, ans);
      return;
    }
    rep(i, c) {
      if(!used[i]) {
        ll tmp = 0;
        for(auto ele: cnt[k]) tmp += D[ele.first][i] * ele.second;
        used[i] = true;
        dfs(dfs, k+1, cost+tmp);
        used[i] = false;
      }
    }
  };
  dfs(dfs, 0, 0);
  cout << ans << "\n";
  return 0;
}
