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

void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
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
  if(n != 1) res[n] = 1;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> cnt(m+1);
  vector<vector<ll>> primes(m+1);
  for(int i=1; i<=m; i++) {
    map<ll, int> res;
    prime_factorization(i, res);
    for(auto ele: res) primes[i].push_back(ele.first);
  }
  rep(i, n) {
    vector<ll> div;
    find_divisor(A[i], div);
    for(ll d: div) {
      if(d > m) break;
      cnt[d]++;
    }
  }
  // cout << cnt << "\n";
  vector<int> ans(m+1, n);
  for(int i=1; i<=m; i++) {
    int p = primes[i].size();
    rep(j, 1<<p) {
      ll mul = 1;
      rep(k, p) if((j>>k)&1) mul *= primes[i][k];
      if(mul == 1) continue;
      ans[i] += (__builtin_popcount(j)%2?-1:1) * cnt[mul];
    }
  }
  for(int i=1; i<=m; i++) cout << ans[i] << "\n";
  return 0;
}
