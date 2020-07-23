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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<ll> cnt(2001);
  rep(i, n) cnt[A[i]]++;
  rep(i, 2001) if(i) cnt[i] += cnt[i-1];
  ll ans = 0;
  rep(i, n) {
    ll cur = 0;
    REP(j, i+1, n) if(A[i] > A[j]) cur++;
    (ans += cur*k%mod) %= mod;
    ll m = cnt[A[i]-1];
    (ans += (k-1)*k/2%mod*m%mod) %= mod;
  }
  cout << ans << "\n";
  return 0;
}
