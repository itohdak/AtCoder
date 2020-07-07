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
  int n, m; cin >> n >> m;
  ll p = pow(2, m);
  ll t = 1900 * m + 100 * (n-m);
  // S = 1*t*p + 2*t*(1-p)*p + 3*t*(1-p)^2*p + ...
  // (1-p)S =    1*t*(1-p)*p + 2*t*(1-p)^2*p + 3*t*(1-p)^2*p + ...
  // pS = 1*t*p + 1*t*(1-p)*p + 1*t*(1-p)^2*p + ...
  // a0 = 1*t*p, r = (1-p)
  cout << t*p << "\n";
  return 0;
}