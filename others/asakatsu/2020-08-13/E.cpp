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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, K; cin >> n >> K;
  vector<pair<ll, ll>> P(n);
  rep(i, n) cin >> P[i].first >> P[i].second;
  ll ans = LONG_LONG_MAX;
  rep(i, n) rep(j, n) rep(k, n) rep(l, n) {
    ll xl = min({P[i].first, P[j].first, P[k].first, P[l].first});
    ll xr = max({P[i].first, P[j].first, P[k].first, P[l].first});
    ll yl = min({P[i].second, P[j].second, P[k].second, P[l].second});
    ll yr = max({P[i].second, P[j].second, P[k].second, P[l].second});
    int cnt = 0;
    rep(m, n) {
      if(xl <= P[m].first && P[m].first <= xr &&
         yl <= P[m].second && P[m].second <= yr) cnt++;
    }
    // cout << (xr-xl)*(yr-yl) << endk;
    if(cnt >= K) ans = min((xr-xl)*(yr-yl), ans);
  }
  cout << ans << endk;
  return 0;
}
