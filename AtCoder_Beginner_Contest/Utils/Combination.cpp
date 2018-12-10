#define ll long long

// #define N 30
// const ll MOD = 1e+9+7;
// ll fact[N]; // 階乗
// ll inv[N]; // 逆元
// ll power(ll x, int n) {
//   ll ans = 1;
//   while(n > 0) {
//     if((n & 1) == 1) {
//       ans = ans * x % MOD;
//     }
//     x = x * x % MOD;
//     n >>= 1;
//   }
//   return ans;
// }
// void FermatCombination() {
//   fact[0] = 1;
//   inv[0] = 1;
//   for(int i=1; i<N; i++) {
//     fact[i] = (fact[i-1] * i) % MOD;
//     inv[i] = power(fact[i], (int)MOD-2) % MOD; // フェルマーの小定理の逆元
//   }
// }
// ll combine(int n, int k) {
//   return fact[n] * inv[k] % MOD * inv[n-k] % MOD; // フェルマーの小定理
// }

// http://keita-matsushita.hatenablog.com/entry/2016/12/05/184011


#define N 30
const ll MOD = 1e+9+7;
ll inv[N], fac[N], finv[N];
void make() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for(int i=2; i<N; i++) {
    inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
    fac[i] = fac[i-1] * (ll)i % MOD;
    finv[i] = finv[i-1] * inv[i] % MOD;
  }
}
ll comb(ll n, ll r) {
  ll ans = 1;
  for(int i=0; i<r; i++) {
    ans = (ans * (n-i) % MOD) % MOD; // n * (n-1) * ... * (n-r+1)
  }
  ans = (ans * finv[r]) % MOD; // フェルマーの小定理
  return ans;
}

// make();
// comb(n, r);
