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
  int d; ll g; cin >> d >> g;
  vector<ll> P(d), C(d);
  rep(i, d) cin >> P[i] >> C[i];
  ll ans = longinf;
  rep(i, 1<<d) {
    ll cur = 0;
    ll cnt = 0;
    set<int> se;
    rep(j, d) {
      if((i>>j)&1) {
        cur += P[j]*100*(j+1) + C[j];
        cnt += P[j];
      } else {
        se.insert(j);
      }
    }
    if(cur >= g) {
      ans = min(ans, cnt);
    } else {
      for(auto j: se) {
        if(cur+(P[j]-1)*100*(j+1) < g) continue;
        ans = min(ans, cnt+((g-cur)+(100*(j+1))-1)/(100*(j+1)));
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
