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
  ll n; cin >> n;
  int cand[] = {3, 5, 7};
  int ans = 0;
  auto dfs = [&](auto dfs,
                 int i, ll val,
                 bool used3, bool used5, bool used7) -> void {
    if(val > n) return;
    if(val && used3 && used5 && used7) ans++;
    dfs(dfs, i+1, val+3*pow(10, i), true, used5, used7);
    dfs(dfs, i+1, val+5*pow(10, i), used3, true, used7);
    dfs(dfs, i+1, val+7*pow(10, i), used3, used5, true);
  };
  dfs(dfs, 0, 0, false, false, false);
  cout << ans << "\n";
  return 0;
}
