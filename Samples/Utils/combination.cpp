#define ll long long
#include<bits/stdc++.h>

// #define N 30
// const ll mod = 1e+9+7;
// ll fact[N]; // 階乗
// ll inv[N]; // 逆元
// ll power(ll x, int n) {
//   ll ans = 1;
//   while(n > 0) {
//     if((n & 1) == 1) {
//       ans = ans * x % mod;
//     }
//     x = x * x % mod;
//     n >>= 1;
//   }
//   return ans;
// }
// void FermatCombination() {
//   fact[0] = 1;
//   inv[0] = 1;
//   for(int i=1; i<N; i++) {
//     fact[i] = (fact[i-1] * i) % mod;
//     inv[i] = power(fact[i], (int)mod-2) % mod; // フェルマーの小定理の逆元
//   }
// }
// ll comb(int n, int k) {
//   if(2*k > n) k = n-k;
//   ll ans = 1LL;
//   for(int i=0; i<k; i++) {
//     ans *= (n-i) % mod;
//     ans %= mod;
//   }
//   return ans * inv[k] % mod; // フェルマーの小定理
// }

// FermatCombination();
// comb(n, k);
// http://keita-matsushita.hatenablog.com/entry/2016/12/05/184011


#define N 30
const ll mod = 1e+9+7;
ll inv[N], fac[N], finv[N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<N; i++) {
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

// make();
// comb(n, r);

int main() {
  make();
  for(int i=1; i<N; i++) {
    for(int j=0; j<=i; j++) {
      std::cout << comb(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}
