#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ld a, b, x; cin >> a >> b >> x;
  cout << fixed << setprecision(10);
  if(x <= a*a*b/2) {
    ld d = x*2/a/b;
    ld angle = atan2(b, d);
    cout << angle*180/M_PI << endk;
  } else {
    ld d = (a*a*b-x)*2/a/a;
    ld angle = atan2(d, a);
    cout << angle*180/M_PI << endk;
  }
  return 0;
}
