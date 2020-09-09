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
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> P(n); rep(i, n) { cin >> P[i]; P[i]--; }
  vector<ll> C(n); rep(i, n) cin >> C[i];
  vector<int> path;
  ll ans = -longinf;
  auto dfs = [&](auto dfs, int cur, int s) -> void {
    path.push_back(cur);
    if(P[cur] == s) {
      int m = path.size();
      vector<ll> sum(m+1);
      rep(i, m) sum[i+1] = sum[i] + C[path[i]];
      if(k < m || sum[m] < 0) {
        ll mx = -longinf;
        rep(i, min((int)k, m)) chmax(mx, sum[i+1]);
        chmax(ans, mx);
      } else {
        ll tmp = sum[m] * (k/m-1);
        ll mx = -longinf;
        rep(i, m+1) chmax(mx, tmp+sum[i]);
        tmp += sum[m];
        rep(i, k%m) chmax(mx, tmp+sum[i+1]);
        chmax(ans, mx);
      }
      return;
    }
    dfs(dfs, P[cur], s);
  };
  rep(i, n) {
    path.clear();
    dfs(dfs, i, i);
    // cout << ans << endk;
  }
  cout << ans << endk;
  return 0;
}
