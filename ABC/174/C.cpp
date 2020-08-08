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
  int k; cin >> k;
  set<ll> rem;
  int ans = 1;
  ll tmp = 7;
  while(tmp < k) {
    tmp = tmp*10+7;
    ans++;
  }
  while(true) {
    ll r = tmp%k;
    if(r == 0) {
      cout << ans << "\n";
      return 0;
    } else if(rem.count(r)) {
      cout << -1 << "\n";
      return 0;
    } else {
      rem.insert(r);
      tmp = r*10+7;
      ans++;
    }
  }
  return 0;
}
