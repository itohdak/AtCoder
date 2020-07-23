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
  int n; cin >> n;
  string s; cin >> s;
  ll cur = 0;
  ll ans = 1;
  rep(i, 2*n) {
    if(s[i] == 'W') {
      if(cur&1) {
        cur++;
      } else {
        (ans *= cur) %= mod;
        cur--;
        if(cur < 0) ans = 0;
      }
    } else {
      if(cur&1) {
        (ans *= cur) %= mod;
        cur--;
        if(cur < 0) ans = 0;
      } else {
        cur++;
      }
    }
  }
  for(int i=1; i<=n; i++) {
    (ans *= i) %= mod;
  }
  cout << (cur != 0 ? 0 : ans) << "\n";
  return 0;
}
