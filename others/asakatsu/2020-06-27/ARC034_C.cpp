#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

map<ll, int> res;
void prime_factorization(ll N) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n]++;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll A, B;
  cin >> A >> B;
  for(ll i=B+1; i<=A; i++) {
    prime_factorization(i);
  }
  ll ans = 1;
  for(auto ele: res) {
    (ans *= ele.second+1) %= mod;
  }
  cout << ans << "\n";
  return 0;
}
