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
  int N; ll W;
  cin >> N >> W;
  ll w0 = 0;
  vector<vector<ll>> Vs(4);
  rep(i, N) {
    ll w, v; cin >> w >> v;
    if(i == 0) w0 = w;
    Vs[w-w0].push_back(v);
  }
  vector<vector<ll>> sum(4);
  rep(i, 4) {
    sort(all(Vs[i]), greater<ll>());
    sum[i] = vector<ll>(Vs[i].size()+1);
    rep(j, Vs[i].size()) sum[i][j+1] = sum[i][j] + Vs[i][j];
  }

  ll ans = 0;
  function<void(int, ll, ll)> dfs = [&](int cur, ll w, ll v) {
    if(cur == 4) {
      ans = max(v, ans);
      return;
    }
    rep(i, sum[cur].size()) {
      if(w+i*(w0+cur) > W) break;
      dfs(cur+1, w+i*(w0+cur), v+sum[cur][i]);
    }
  };
  dfs(0, 0, 0);
  cout << ans << "\n";
  return 0;
}
