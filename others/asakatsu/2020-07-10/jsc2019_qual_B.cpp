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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> cnt(n);
  rep(i, n) REP(j, i+1, n) if(A[i]>A[j]) cnt[i]++;
  map<ll, ll> mp;
  mp[0] = 0;
  rep(i, n) mp[A[i]]++;
  ll prev = 0;
  for(auto& ele: mp) {
    ele.second += prev;
    prev = ele.second;
  }
  ll ans = 0;
  rep(i, n) {
    (ans += cnt[i]*k%mod + (k-1)*k/2%mod*(--mp.upper_bound(A[i]-1))->second%mod) %= mod;
  }
  cout << ans << "\n";
  return 0;
}
