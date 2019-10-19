#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

map<ll, int> mp;
void prime_factorization(ll N) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(mp.count(i)) mp[i]++;
      else mp[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) {
    if(mp.count(n)) mp[n]++;
    else mp[n] = 1;
  }
}


int main() {
  int N;
  cin >> N;
  REP(i, 1, N+1)
    prime_factorization(i);
  ll ans = 1;
  for(auto m: mp) {
    ans *= (1 + m.second);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

