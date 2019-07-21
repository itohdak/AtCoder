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
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}
ll num(ll a, ll b, ll c) {
  return b / c - (a % c == 0 ? a / c : a / c + 1) + 1;
}

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  ll L = lcm(C, D);
  cout << (B - A + 1) - (num(A, B, C) + num(A, B, D) - num(A, B, L)) << endl;
  return 0;
}

