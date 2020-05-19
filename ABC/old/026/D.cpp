#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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

double A, B, C;
double f(double theta) {
  return A*(theta/C/M_PI)+B*sin(theta);
}
bool test(double theta) {
  return f(theta) >= 100;
}
double binary_search(double theta) {
  double ftheta = f(theta);
  double ng, ok;
  if(ftheta == 100) return theta;
  else if(ftheta < 100) {
    ng = ftheta, ok = ftheta+M_PI;
  } else {
    ng = ftheta+M_PI, ok = ftheta;
  }
  while(abs(ok - ng) > 0.00000001) {
    double mid = (ok + ng) / 2;
    if(test(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}
int main() {
  cin >> A >> B >> C;
  double theta = M_PI/2;
  while((f(theta)-100)*(f(theta+M_PI)-100)>0) theta+=M_PI;
  cout << (f(theta)-100) << ' ' << (f(theta+M_PI)-100) << endl;
  double res = binary_search(theta);
  cout << res/C/M_PI << endl;
  return 0;
}
