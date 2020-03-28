#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct data {
  ll a;
  ll b;
  data(ll a_, ll b_) : a(a_), b(b_) {}
};


/*
  冪乗(pow(a, N); O(logN))
*/
const ll mod = 1e9+7;
ll binary_pow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) {
      ans *= tmp;
      ans %= mod;
    }
    N /= 2;
    tmp *= tmp;
    tmp %= mod;
  }
  return ans;
}


/*
  階乗
*/
int factorial(int N, int buf=1) {
  if(N == 1) {
    return buf;
  } else {
    return factorial(N-1, buf*N);
  }
}


/*
  最大公約数
*/
ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
/*
  最小公倍数
*/
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}

/*
  モジュラ逆元
*/
#define mod 1000000007
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

ll modinv_old(ll a, ll m=mod) {
  ll x = 0, y = 1, gcd = m;
  ll px = 1, py = 0, pgcd = a;
  ll tmp = 0;
  while(gcd > 0) {
    ll quotient = pgcd / gcd;

    tmp = x;
    x = px - quotient * tmp;
    px = tmp;

    tmp = y;
    y = py - quotient * tmp;
    py = tmp;

    tmp = gcd;
    gcd = pgcd - quotient * tmp;
    pgcd = tmp;
  }

  if(px < 0)
    px += m;

  return px;
}

ll sumOfVector(vector<ll> v) {
  return accumulate(v.begin(), v.end(), 0LL);
}

// 除算したものの切り上げ（天井関数）
// ceil((double) n / d) だと怪しい
// ceil((long double) n / d) だと大丈夫？
ll devided_ceil(ll n, ll d) {
  return (n + d - 1) / d;
}
