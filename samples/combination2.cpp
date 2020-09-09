#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

#define MAX_N 100000
ll fact[MAX_N]; // 階乗
ll inv[MAX_N]; // 逆元
ll power(ll x, int n) {
  ll ans = 1;
  while(n > 0) {
    if((n & 1) == 1) {
      ans = ans * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return ans;
}
void FermatCombination() {
  fact[0] = 1;
  inv[0] = 1;
  for(int i=1; i<MAX_N; i++) {
    fact[i] = (fact[i-1] * i) % mod;
    inv[i] = power(fact[i], (int)mod-2) % mod; // フェルマーの小定理の逆元
  }
}
ll comb(int n, int k) {
  if(2*k > n) k = n-k;
  ll ans = 1LL;
  for(int i=0; i<k; i++) {
    ans *= (n-i) % mod;
    ans %= mod;
  }
  return ans * inv[k] % mod; // フェルマーの小定理
}

// FermatCombination();
// comb(n, k);
// http://keita-matsushita.hatenablog.com/entry/2016/12/05/184011

int main() {
  FermatCombination();
  for(int i=1; i<MAX_N; i++) {
    for(int j=0; j<=i; j++) {
      std::cout << comb(i, j) << ' ';
    }
    std::cout << std::endl;
  }
}

