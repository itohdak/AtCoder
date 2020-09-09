#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll x; cin >> n >> x;
  vector<ll> W(n); rep(i, n) cin >> W[i];
  map<ll, int> mp1, mp2;
  rep(i, 1<<(n/2)) {
    ll sum = 0;
    rep(j, n/2) {
      if((i>>j)&1) sum += W[j];
    }
    mp1[sum]++;
  }
  rep(i, 1<<(n-n/2)) {
    ll sum = 0;
    rep(j, n-n/2) {
      if((i>>j)&1) sum += W[n/2+j];
    }
    mp2[sum]++;
  }
  ll ans = 0;
  for(auto ele: mp1) {
    if(mp2.count(x-ele.first)) {
      ans += 1LL * ele.second * mp2[x-ele.first];
    }
  }
  cout << ans << endk;
  return 0;
}
