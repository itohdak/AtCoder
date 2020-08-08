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
  int r, g, b, n; cin >> r >> g >> b >> n;
  ll ans = 0;
  for(int i=0; i<=n/r; i++) {
    for(int j=0; j<=(n-i*r)/g; j++) {
      if((n-i*r-j*g)%b==0) ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
