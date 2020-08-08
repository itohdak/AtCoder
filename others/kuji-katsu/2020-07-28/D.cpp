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
  int n; ll x; cin >> n >> x;
  vector<ll> cnt(51), cntAll(51);
  cnt[0] = cntAll[0] = 1;
  rep(i, 51) {
    if(i) {
      cnt[i] = cnt[i-1]*2+1;
      cntAll[i] = cntAll[i-1]*2+3;
    }
  }
  auto dfs = [&](auto dfs, int n, ll x, ll sum) -> ll {
    if(n == 0) return sum+1;
    if(x == 1) {
      return sum;
    } else if(x < (cntAll[n]+1)/2) {
      return dfs(dfs, n-1, x-1, sum);
    } else if(x == (cntAll[n]+1)/2) {
      return sum + cnt[n-1] + 1;
    } else if(x < cntAll[n]) {
      return dfs(dfs, n-1, x-2-cntAll[n-1], sum+cnt[n-1]+1);
    } else {
      return sum + cnt[n];
    }
  };
  cout << dfs(dfs, n, x, 0LL) << "\n";
  return 0;
}
