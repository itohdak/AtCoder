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
  double x, y; cin >> x >> y;
  int n; cin >> n;
  vector<double> X(n), Y(n);
  double mn = inf;
  rep(i, n) cin >> X[i] >> Y[i];
  rep(i, n) {
    int j = (i+n-1)%n;
    double a, b, c;
    // a * xi + b * yi = - c
    // a * xj + b * yj = - c
    // a * (xi - xj) + b * (yi - yj) = 0
    a = Y[i]-Y[j];
    b = -(X[i]-X[j]);
    c = -(a*X[i]+b*Y[i]);
    double d = abs(a*x+b*y+c) / sqrt(a*a+b*b);
    mn = min(d, mn);
  }
  cout << fixed << setprecision(10) << mn << "\n";
  return 0;
}
