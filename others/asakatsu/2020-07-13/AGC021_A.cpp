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
  ll n; cin >> n;
  ll orig = n;
  bool all9 = true;
  ll ans = 0;
  while(n > 0) {
    int cur = n%10;
    if(n >= 10) {
      if(cur != 9) all9 = false;
      ans += 9;
    } else {
      if(all9) ans += n;
      else     ans += n-1;
    }
    n /= 10;
  }
  if(orig < 10) cout << orig << "\n";
  else cout << ans << "\n";
  return 0;
}
