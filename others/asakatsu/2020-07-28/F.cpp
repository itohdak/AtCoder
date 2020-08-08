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
  int r, g, b;
  cin >> r >> g >> b;
  auto count = [&](int i, int n, int org) -> ll {
    // [i, i+n-1]
    if(i+n-1 < org) {
      // org-i + ... + org-i-n+1
      return (org-i+org-i-n+1) * n / 2;
    } else if(i < org) {
      // org-i + ... + 0
      // 0 + ... + i+n-1-org
      return (org-i)*(org-i+1)/2 + (i+n-1-org)*(i+n-1-org+1)/2;
    } else {
      // i-org + ... + i+n-1-org
      return (i-org+i+n-1-org) * n / 2;
    }
  };
  ll mn = longinf;
  ll mx = 2000;
  REP(j, -mx, mx) {
    ll tmp = count(j, g, 0);
    ll m = longinf;
    REP(i, -mx, j+1) {
      m = min(count(i-r, r, -100), m);
    }
    tmp += m;
    m = longinf;
    REP(k, j+g, mx) {
      m = min(count(k, b, 100), m);
    }
    tmp += m;
    mn = min(tmp, mn);
  }
  cout << mn << "\n";
  return 0;
}
