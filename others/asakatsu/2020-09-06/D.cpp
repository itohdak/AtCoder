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
  ll x; cin >> x;
  vector<ll> cnt(51), pat(51);
  cnt[0] = 1;
  pat[0] = 1;
  rep(i, 51) {
    if(i) {
      cnt[i] = 2*cnt[i-1]+3;
      pat[i] = 2*pat[i-1]+1;
    }
  }
  auto dfs = [&](auto dfs, int lev, ll x) -> ll {
    if(x == 0) return 0;
    if(lev == 0) return 1;
    if(x < cnt[lev-1]+2) {
      return dfs(dfs, lev-1, x-1);
    } else if(x == cnt[lev-1]+2) {
      return pat[lev-1]+1;
    } else {
      return pat[lev-1]+1+dfs(dfs, lev-1, x-cnt[lev-1]-2);
    }
  };
  cout << dfs(dfs, n, x) << endk;
  return 0;
}
