#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

struct data {
  ll prime;
  int power;
  data(ll prime, int power) : prime(prime), power(power) {}
};
vector<data> result;
void factorization(ll N) {
  if(N == 1 || N == 0) return;

  bool first = true;
  ll n = N;
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

int main() {
  ll A, B;
  cin >> A >> B;
  ll g = gcd(A, B);
  factorization(g);
  cout << result.size()+1 << endl;
  return 0;
}

