#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

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
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll a, b, c; cin >> a >> b >> c;
  // n = i+j
  // a = nCi = nCj
  // b = n+1Cj+1 = n+1Ci = a * (n+1)/(n-i+1)
  // c = n+1Cj = n+1Ci+1 = a * (n+1)/(n-j+1)
  // b*(j+1) = c*(i+1) = a*(i+j+1)
  // b*j + b = c*i + c = a*i + a*j + a
  // j = (c*i + c - b) / b
  // c*i + c = a*i + a*(c*i+c-b)/b + a
  // c*i + c = a*i + a*c*i/b + a*c/b
  // (a+a*c/b-c)*i = c-a*c/b = (b*c-c*a)/b
  // i = (b*c-c*a)/(a*b-b*c+c*a)
  // j = (c*(b*c-c*a) + c*(a*b-b*c+c*a) - b*(a*b-b*c+c*a)) / b*(a*b-b*c+c*a)
  //   = (-a*b+b*c)/(a*b-b*c+c*a)
  ll i = ((b*c-c*a)%mod+mod)%mod*modinv(((a*b-b*c+c*a)%mod+mod)%mod)%mod;
  ll j = ((-a*b+b*c)%mod+mod)%mod*modinv(((a*b-b*c+c*a)%mod+mod)%mod)%mod;
  cout << i << ' ' << j << endk;
  return 0;
}
