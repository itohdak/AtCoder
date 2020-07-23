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

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  make();
  int n, a, b;
  cin >> n >> a >> b;
  vector<ll> V(n);
  map<ll, int> mp;
  rep(i, n) {
    cin >> V[i];
    mp[V[i]]++;
  }
  ll prev;
  int cnt = 0;
  auto itr = mp.rbegin();
  while(cnt < a) {
    cnt += itr->second;
    prev = itr->first;
    itr++;
  }
  cnt -= mp[prev];
  int mn = a-cnt;
  int mx = min(b-cnt, mp[prev]);
  if(mp.rbegin()->first == prev) {
    cout << prev << "\n";
    ll ans = 0;
    for(int i=mn; i<=mx; i++) {
      ans += comb(mp[prev], i);
    }
     cout << ans << "\n";
  } else {
    itr = mp.rbegin();
    double ans = 0;
    while(itr->first != prev) {
      ans += (double)itr->first/a*itr->second;
      itr++;
    }
    ans += (double)prev/a*mn;
    cout << ans << "\n";
    cout << comb(mp[prev], mn) << "\n";
  }
  return 0;
}
