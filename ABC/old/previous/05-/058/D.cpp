#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> X(n), Y(m);
  rep(i, n) cin >> X[i];
  rep(i, m) cin >> Y[i];
  ll sumi = 0;
  REP(i, 1, n) {
    sumi += (((i * (n-i)) % mod) * ((X[i] - X[i-1]) % mod)) % mod;
    sumi %= mod;
  }
  ll sumj = 0;
  REP(j, 1, m) {
    sumj += (((j * (m-j)) % mod) * ((Y[j] - Y[j-1]) % mod)) % mod;
    sumj %= mod;
  }
  // sum_i i * (n-i) * dx[i] * sum_j j * (m-j) * dy[j]
  cout << (sumi * sumj) % mod << endl;
  return 0;
}

