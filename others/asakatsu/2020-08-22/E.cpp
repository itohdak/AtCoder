#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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

void prime_factorization(ll N, map<ll, int>& res) {
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
  int n; cin >> n;
  // 75 = 3 * 5 * 5
  // 2, 4, 4
  // 2, 24
  // 4, 14
  // 74
  map<ll, int> primes;
  for(int i=1; i<=n; i++) {
    prime_factorization(i, primes);
  }
  vector<ll> cnt(100);
  for(auto ele: primes) {
    cnt[ele.second]++;
  }
  rrep(i, 99) cnt[i] += cnt[i+1];
  ll ans = 0;
  ans += cnt[4] * (cnt[4]-1) / 2 * (cnt[2]-2);
  ans += cnt[24] * (cnt[2]-1);
  ans += cnt[14] * (cnt[4]-1);
  ans += cnt[74];
  cout << ans << endk;
  return 0;
}
