#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

/*
  素数か否か
*/
bool is_prime(const unsigned n){
  switch(n){
  case 0: // fall-through
  case 1: return false;
  case 2: // fall-through
  case 3: return true;
  } // n > 3 が保証された

  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  // 2と3の倍数でないので6の倍数ではないことが保証された

  if(n % 6 != 1 && n % 6 != 5) return false;
  // 6の倍数前後の数(素数かもしれない数)であることが保証された

  // 6の倍数前後の数を使って試し割りをする
  for(unsigned i=5; i*i<=n; i+=6){
    if(n % i     == 0) return false; // 6n-1
    if(n % (i+2) == 0) return false; // 6n+1
  }

  return true;
}


/*
  エラトステネスの篩
*/
bool arr[1000000000];
vector<ll> primes;
void Eratosthenes(int N) {
  for(int i=0; i<N; i++) {
    arr[i] = true;
  }
  for(int i=2; i<sqrt(N); i++) {
    if(arr[i]) {
      for(int j=0; i*(j+2)<N; j++) {
        arr[i*(j+2)] = false;
      }
    }
  }

  for(int i=2; i<N; i++) {
    if(arr[i]) {
      primes.push_back(i);
    }
  }
}


/*
  素因数分解
*/
map<ll, int> res;
void prime_factorization(ll N) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n] = 1;
}

/*
  約数
*/
vector<ll> divisor;
void find_divisor(ll N) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
