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
  ll n, m; cin >> n >> m;
  auto bsearch =
    [&]() {
      auto test =
        [&](ll k) {
          if(m < k*2) return false;
          ll rem = m-k*2;
          if(n+rem/2 < k) return false;
          return true;
        };
      ll ok = 0, ng = longinf;
      while(ng-ok>1) {
        ll mid = (ok+ng)/2;
       (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
  cout << bsearch() << endk;
  return 0;
}
