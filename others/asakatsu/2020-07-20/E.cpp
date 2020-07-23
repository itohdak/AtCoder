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
  ll h, w; cin >> h >> w;
  ll ans = longinf;
  if(h%3==0 || w%3==0) ans = 0;
  else ans = min({w, h, ans});
  REP(i, 1, h) {
    ll a = w/2*i;
    ll b = (w-w/2)*i;
    ll c = h*w-a-b;
    ans = min(max({a,b,c})-min({a,b,c}), ans);
  }
  REP(i, 1, w) {
    ll a = h/2*i;
    ll b = (h-h/2)*i;
    ll c = h*w-a-b;
    ans = min(max({a,b,c})-min({a,b,c}), ans);
  }
  cout << ans << "\n";
  return 0;
}
