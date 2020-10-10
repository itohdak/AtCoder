#include "header.hpp"

struct data {
  ll a;
  ll b;
  data(ll a_, ll b_) : a(a_), b(b_) {}
};


/*
  冪乗(pow(a, N); O(logN))
*/
ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
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
  最大公約数, 最小公倍数
*/
ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}

/*
  拡張GCD
  不定方程式 a * x + b * y == gcd(a, b)
  の解を (x, y) に格納する
*/
ll extGCD(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = extGCD(b, a%b, y, x);
  y -= a/b * x;
  return d;
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

// 1が立っているbit数を数える
int bitcount32(unsigned long dw32) {
  dw32 = ((dw32 & 0xAAAAAAAA) >>  1) + (dw32 & 0x55555555);
  dw32 = ((dw32 & 0xCCCCCCCC) >>  2) + (dw32 & 0x33333333);
  dw32 = ((dw32 & 0xF0F0F0F0) >>  4) + (dw32 & 0x0F0F0F0F);
  dw32 = ((dw32 & 0xFF00FF00) >>  8) + (dw32 & 0x00FF00FF);
  dw32 = ((dw32 & 0xFFFF0000) >> 16) + (dw32 & 0x0000FFFF);
  return dw32;
}
