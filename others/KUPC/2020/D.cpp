#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

bool is_prime(const unsigned n) {
  switch(n) {
  case 0:
  case 1: return false;
  case 2:
  case 3: return true;
  }
  if(n % 2 == 0) return false;
  if(n % 3 == 0) return false;
  if(n % 6 != 1 && n % 6 != 5) return false;
  for(unsigned i=5; i*i<=n; i+=6) {
    if(n % i     == 0) return false;
    if(n % (i+2) == 0) return false;
  }
  return true;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  if(n == 2) {
    cout << "impossible" << endk;
  } else if(n % 2 == 0) {
    cout << n/2 << endk;
    rep(i, n/2) {
      cout << 2 << ' ' << i*2+1 << ' ' << 2*n-1-i*2 << endk;
    }
  } else {
    if(is_prime(n)) {
    } else {
      cout << "impossible" << endk;
    }
  }
  return 0;
}
