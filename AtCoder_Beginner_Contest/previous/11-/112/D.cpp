#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

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

ll ans = 0LL;
void calc(int n, ll m, int i=0, ll tmp=1LL) {
  if(i == (int)result.size()) {
    if(tmp * n <= m && tmp > ans)
      ans = tmp;
  } else {
    for(int j=0; j<=result[i].power; j++)
      calc(n, m, i+1, tmp*(ll)pow(result[i].prime, j));
  }
}

int main(){
  int N;  ll M;
  cin >> N >> M;
  factorization(M);
  calc(N, M);
  cout << ans << endl;
  return 0;
}

