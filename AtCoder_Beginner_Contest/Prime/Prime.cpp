#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define ll long long

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
