#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<pair<ll, ll> > lr;
  set<pair<ll, ll> > se;
  ll mx=-inf, mn=inf;
  rep(i, N) {
    ll l, r;
    cin >> l >> r;
    l--;
    lr.push_back(make_pair(l, r));
    mx = max(mx, l);
    mn = min(mn, r);
  }
  ll ans = 0;
  for(auto s: lr) {
    ll l = s.first, r = s.second;
    ans = max(ans, max(0LL, mn-mx)+r-l);
  }
  for(auto s: lr) {
    ll l = s.first, r = s.second;
    ll a = max(0LL, r - mx);
    ll b = max(0LL, mn - l);
    se.insert(make_pair(a, -b));
  }
  ll w = inf;
  for(auto s: se) {
    ll a = s.first, b = - s.second;
    if(w != inf) ans = max(ans, w + a);
    w = min(w, b);
  }
  cout << ans << endl;
  return 0;
}

