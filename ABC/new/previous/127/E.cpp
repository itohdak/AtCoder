#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

#define MAX_N 200005
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

int main() {
  make();
  int N, M, K;
  cin >> N >> M >> K;
  ll ans = 0;
  REP(i, 1, N) {
    ans += (i * ((((N-i) * M % mod) * M % mod) * comb(N*M-2, K-2) % mod) % mod);
    ans %= mod;
  }
  REP(i, 1, M) {
    ans += (i * ((((M-i) * N % mod) * N % mod) * comb(N*M-2, K-2) % mod) % mod);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

