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
  int a, b, h, m; cin >> a >> b >> h >> m;
  ld angle = abs(30*h-5.5*m);
  angle = min(angle, 360-angle);
  ld theta = angle * M_PI / 180;
  ld ans = sqrt(a*a+b*b-2*a*b*cos(theta));
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
