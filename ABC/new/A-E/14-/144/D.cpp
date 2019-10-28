#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const double PI = 3.14159265358979;

double rad2deg(double rad) {
  return rad * 180 / PI;
}
int main() {
  double a, b, x;
  cin >> a >> b >> x;
  x /= a;
  if(x <= a * b / 2) {
    double c = x * 2 / b;
    cout << setprecision(10) << rad2deg(atan(b / c)) << endl;
  } else {
    double c = x * 2 / a - b;
    cout << setprecision(10) << rad2deg(atan((b - c) / a)) << endl;
  }
  return 0;
}

