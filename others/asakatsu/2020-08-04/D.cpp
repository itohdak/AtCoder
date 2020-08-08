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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n, k; cin >> n >> k;
  ll ans = 0;
  for(ll i=k; i<=n+1; i++) {
    ll mn = (i-1)*i/2;
    ll mx = (n+n-i+1)*i/2;
    (ans += (mx-mn+1)) %= mod;
    // cout << ans << endk;
  }
  cout << ans << endk;
  return 0;
}
