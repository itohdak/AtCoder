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
  int n; cin >> n;
  ll ans = 1;
  while((1LL<<ans) < n) ans++;
  rep(i, n-1) {
    REP(j, i+1, n) {
      int tmp = i^j;
      int a = 1;
      while(!(tmp&1)) {
        tmp >>= 1;
        a++;
      }
      cout << a << " ";
    }
    cout << "\n";
  }
  return 0;
}
