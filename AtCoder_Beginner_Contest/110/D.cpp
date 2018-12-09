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

int MAX_R = 100050;
int MAX_C = 50;
vector<vector<ll> > v(MAX_R, vector<ll>(MAX_C, 0LL));
void prep_comb(ll mod = MOD) {
  for(int i=0; i<MAX_C; i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for(int k=1; k<v.size(); k++) {
    for(int j=1; j<min(MAX_C, k); j++) {
      v[k][j] = (v[k-1][j-1] + v[k-1][j]) % mod;
    }
  }
}
ll comb(int n, int r) {
  if(2*r > n) r = n-r;
  return v[n][r];
}

int main(){
  int N;
  ll M;
  cin >> N >> M;

  factorization(M);

  ll ans = 1;
  int n = N-1;
  prep_comb();
  for(int i=0; i<result.size(); i++) {
    int m = result[i].power + n;
    ans *= comb(m, n);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}

