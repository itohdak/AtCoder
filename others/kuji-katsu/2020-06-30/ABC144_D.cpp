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
  int a, b, x;
  cin >> a >> b >> x;
  cout << fixed << setprecision(20);
  if(x < a*b*a/2.0) {
    double c = (double)x/a*2/b;
    cout << 90 - atan(c/b)*180/M_PI << "\n";
  } else {
    double c = 2*b-(double)x/a*2/a;
    cout << 90 - atan(a/c)*180/M_PI << "\n";
  }
  return 0;
}
