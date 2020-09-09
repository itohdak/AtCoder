#include <bits/stdc++.h>
// #include <atcoder/all>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n), B(n);
  map<pair<ll, ll>, ll> mp;
  ll zero=0;
  rep(i, n) {
    cin >> A[i] >> B[i];
    if(A[i] == 0 && B[i] == 0) {
      zero++;
    } else if(A[i] == 0) {
      mp[{0, 1}]++;
    } else if(B[i] == 0) {
      mp[{1, 0}]++;
    } else {
      ll g = gcd(abs(A[i]), abs(B[i]));
      A[i] /= g; B[i] /= g;
      if(A[i] < 0) {
        mp[{-A[i], -B[i]}]++;
      } else {
        mp[{A[i], B[i]}]++;
      }
    }
  }
  // cout << mp << endk;
  set<pair<ll, ll>> done;
  ll ans = 1;
  for(auto ele: mp) {
    ll a = ele.first.first;
    ll b = ele.first.second;
    if(!done.count({a, b})) {
      if(b > 0) {
        ll tmp = (modpow(2, ele.second) + modpow(2, mp[{b, -a}]) - 1) % mod;
        (ans *= tmp) %= mod;
        done.insert({a, b});
        done.insert({b, -a});
      } else {
        ll tmp = (modpow(2, ele.second) + modpow(2, mp[{-b, a}]) - 1) % mod;
        (ans *= tmp) %= mod;
        done.insert({a, b});
        done.insert({-b, a});
      }
    }
  }
  (ans += zero) %= mod;
  cout << (ans+mod-1)%mod << endk;
  return 0;
}
