#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll modinv(ll a, ll m=mod) {
  ll b = m, u = 1, v = 0;
  while(b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if(u < 0) u += m;
  return u;
}
int main() {
  int N;
  cin >> N;
  vector<ll> X(N);
  rep(i, N) cin >> X[i];
  ll p=0, sum=0, fac=1;
  rep(i, N-1) (fac *= (i+1)) %= mod;
  rep(i, N-1) {
    (p += fac * modinv(i+1) % mod) %= mod;
    (sum += (X[i+1]-X[i]) * p % mod) %= mod;
  }
  cout << sum << endl;
  return 0;
}
