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

// #define MAX_N 2000005
// ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
// void make() {
//   fac[0] = fac[1] = 1;
//   finv[0] = finv[1] = 1;
//   inv[1] = 1;
//   for(int i=2; i<MAX_N; i++) {
//     inv[i] = mod - inv[mod%i] * (mod/i) % mod;
//     fac[i] = fac[i-1] * (ll)i % mod;
//     finv[i] = finv[i-1] * inv[i] % mod;
//   }
// }
// ll perm(ll n, ll r) {
//   if(n < 0)       return 0;
//   else if(n < r)  return 0;
//   else            return (fac[n] * finv[n-r]) % mod;
// }
// ll comb(ll n, ll r) {
//   ll ans = 1;
//   ans = perm(n, r);
//   ans = (ans * finv[r]) % mod;
//   return ans;
// }
ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // make();
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll ans = 1;
  int l = 0, r = 0;
  while(l < n) {
    while(l < n && A[l] != -1) l++;
    if(l == n) break;
    r = l;
    while(r < n && A[r] == -1) r++;
    int m = r-l;
    ll diff = A[r]-A[l-1]+1;
    rep(i, m) { // comb(diff+m-1, m)
      (((ans *= diff+m-1-i) %= mod) *= modinv(m-i)) %= mod;
    }
    // (ans *= comb(diff+m-1, m)) %= mod;
    l = r;
  }
  cout << ans << "\n";
  return 0;
}
