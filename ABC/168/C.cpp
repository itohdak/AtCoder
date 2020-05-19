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
const double pi = 3.1415926535;

int main() {
  int A, B, H, M;
  cin >> A >> B >> H >> M;
  double angle = -H*30;
  angle += 5.5*M;
  angle = abs(angle);
  cout << setprecision(15) << sqrt(A*A+B*B-2*A*B*cos(angle*pi/180)) << endl;
  return 0;
}
