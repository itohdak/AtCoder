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
ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  map<pair<ll, ll>, ll> mp;
  ll cnt00 = 0, cntA0 = 0, cnt0B = 0;
  rep(i, N) {
    cin >> A[i] >> B[i];
    if(A[i] == 0 && B[i] == 0) {
      cnt00++;
    } else if(B[i] == 0) {
      cntA0++;
    } else if(A[i] == 0) {
      cnt0B++;
    } else {
      ll G = gcd(abs(A[i]), abs(B[i]));
      if(A[i] < 0 && B[i] < 0) mp[make_pair(-A[i]/G, -B[i]/G)]++;
      else if(A[i] < 0)        mp[make_pair(A[i]/G, B[i]/G)]++;
      else if(B[i] < 0)        mp[make_pair(-A[i]/G, -B[i]/G)]++;
      else                     mp[make_pair(A[i]/G, B[i]/G)]++;
    }
  }
  set<pair<ll, ll>> done;
  ll ans = 1;
  if(cntA0 && cnt0B) {
    (ans *= (binary_pow(2, cntA0) + binary_pow(2, cnt0B) - 1 + mod) % mod) %= mod;
  } else if(cntA0) {
    (ans *= binary_pow(2, cntA0)) %= mod;
  } else if(cnt0B) {
    (ans *= binary_pow(2, cnt0B)) %= mod;
  }
  for(auto m: mp) {
    auto val = m.first;
    pair<ll, ll> val2;
    if(val.first < 0) val2 = make_pair(val.second, -val.first);
    else              val2 = make_pair(-val.second, val.first);
    if(done.count(val2)) continue;
    if(mp.count(val2)) {
      (ans *= (binary_pow(2, m.second) + binary_pow(2, mp[val2]) - 1 + mod) % mod) %= mod;
    } else {
      (ans *= binary_pow(2, m.second)) %= mod;
    }
    done.insert(val);
  }
  cout << (ans+mod-1+cnt00)%mod << endl;
  return 0;
}
