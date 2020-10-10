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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> B(n);
  vector<vector<int>> G(n);
  rep(i, n-1) {
    cin >> B[i+1];
    B[i+1]--;
    G[B[i+1]].push_back(i+1);
  }
  vector<ll> ans(n);
  auto dfs = [&](auto dfs, int cur) -> void {
    if(G[cur].size() == 0) {
      ans[cur] = 1;
      return;
    }
    ll mx = 0, mn = longinf;
    for(auto ne: G[cur]) {
      dfs(dfs, ne);
      chmax(mx, ans[ne]);
      chmin(mn, ans[ne]);
    }
    ans[cur] = mx + mn + 1;
    return;
  };
  dfs(dfs, 0);
  cout << ans[0] << endk;
  return 0;
}
