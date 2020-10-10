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
  int n; ll k; cin >> n >> k;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  vector<ll> C(n); rep(i, n) cin >> C[i];
  vector<bool> vis(n);
  vector<vector<int>> path;
  auto dfs = [&](auto dfs, int cur) {
               if(vis[cur]) return;
               vis[cur] = true;
               path.back().push_back(cur);
               dfs(dfs, P[cur]);
             };
  rep(i, n) {
    if(!vis[i]) {
      path.push_back(vector<int>());
      dfs(dfs, i);
    }
  }
  auto func = [&](vector<int>& path) {
                int n = path.size();
                ll sum = 0;
                rep(i, n) sum += C[path[i]];
                vector<vector<ll>> mx(n, vector<ll>(2*n+1));
                rep(i, n) rep(j, 2*n) {
                  mx[i][j+1] = mx[i][j] + C[path[(i+j)%n]];
                }
                if(sum < 0 || k < n) {
                  ll ans = -longinf;
                  rep(i, n) REP(j, 1, min(k+1, (ll)n+1)) {
                    ans = max(mx[i][j], ans);
                  }
                  return ans;
                } else {
                  ll ans = -longinf;
                  rep(i, n) rep(j, k%n+n+1) {
                    ans = max(mx[i][j], ans);
                  }
                  ans += sum * (k/n-1);
                  return ans;
                }
              };
  ll ans = -longinf;
  for(auto& ele: path) {
    ans = max(func(ele), ans);
  }
  cout << ans << endk;
  return 0;
}
