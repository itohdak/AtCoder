#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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
const ll mod = 998244353;

#define MAX_N 400005
ll inv[MAX_N], fac[MAX_N], finv[MAX_N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<MAX_N; i++) {
    inv[i] = mod - inv[mod%i] * (mod/i) % mod;
    fac[i] = fac[i-1] * (ll)i % mod;
    finv[i] = finv[i-1] * inv[i] % mod;
  }
}
ll perm(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return (fac[n] * finv[n-r]) % mod;
}
ll comb(ll n, ll r) {
  ll ans = 1;
  ans = perm(n, r); // n * (n-1) * ... * (n-r+1)
  ans = (ans * finv[r]) % mod; // フェルマーの小定理
  return ans;
}

ll binary_pow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    N /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}

int main() {
  make();
  int N, M, K;
  cin >> N >> M >> K;
  ll ans = 0;
  ll pow = (M * binary_pow(M-1, N-K-1)) % mod;
  for(ll k=K; k>=0; k--) {
    (ans += (comb(N-1, k) * pow) % mod) %= mod;
    (pow *= M-1) %= mod;
  }
  cout << ans << endl;
  return 0;
}
