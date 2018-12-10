#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

const ll MOD = 1e+9 + 7;

struct data {
  ll prime;
  int power;
  data(ll prime, int power) : prime(prime), power(power) {}
};
vector<data> result;
void factorization(ll N) {
  if(N == 1 || N == 0) return;

  bool first = true;
  int n = N;
  while(n % 2 == 0) {
    if(first) {
      result.push_back(data(2LL, 1));
      first = false;
    } else {
      result[result.size()-1].power++;
    }
    n /= 2;
  }
  first = true;

  for(ll i=3; i<ceil(sqrt(N)); i+=2) {
    while(n % i == 0) {
      if(first) {
	result.push_back(data(i, 1));
	first = false;
      } else {
	result[result.size()-1].power++;
      }
      n /= i;
    }
    first = true;
  }

  if(n != 1) {
    result.push_back(data(n, 1));
  }

  return;
}


#define N_MAX 30
ll fact[N_MAX]; // 階乗
ll inv[N_MAX]; // 逆元
ll power(ll x, int n) {
  ll ans = 1;
  while(n > 0) {
    if((n & 1) == 1) {
      ans = ans * x % MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return ans;
}
void FermatCombination() {
  fact[0] = 1;
  inv[0] = 1;
  for(int i=1; i<N_MAX; i++) {
    fact[i] = (fact[i-1] * i) % MOD;
    inv[i] = power(fact[i], (int)MOD-2) % MOD; // フェルマーの小定理の逆元
  }
}
ll comb(int n, int k) {
  if(2*k > n) k = n-k;
  ll ans = 1LL;
  for(int i=0; i<k; i++) {
    ans *= (n-i) % MOD;
    ans %= MOD;
  }
  return ans * inv[k] % MOD; // フェルマーの小定理
}


int main(){
  FermatCombination();

  int N;
  ll M;
  cin >> N >> M;

  factorization(M);

  ll ans = 1;
  int n = N-1;
  for(int i=0; i<result.size(); i++) {
    int m = result[i].power + n;
    ans *= comb(m, n);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}
