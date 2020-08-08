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
  int m, d; cin >> m >> d;
  ll ans = 0;
  REP(i, 1, m+1) {
    REP(j, 1, d+1) {
      int d1 = j%10;
      int d10 = j/10;
      if(d1<2 || d10<2) continue;
      if(d1*d10==i) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
