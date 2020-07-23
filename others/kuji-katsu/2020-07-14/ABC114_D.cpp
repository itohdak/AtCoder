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
  ll n; cin >> n;
  // 3 5 5; 2 4 4
  // 3 25; 2 24
  // 5 15; 4 14
  // 75; 74
  ll ans = 0;
  map<ll, int> res;
  for(int i=1; i<=n; i++) {
    prime_factorization(i, res);
  }
  map<int, int> cnt;
  for(auto ele: res) {
    cnt[ele.second]++;
  }
  int prev = 0;
  for(auto itr=cnt.rbegin(); itr!=cnt.rend(); itr++) {
    itr->second += prev;
    prev = itr->second;
  }
  cnt[inf] = 0;
  ans += cnt.lower_bound(4)->second * (cnt.lower_bound(4)->second-1) / 2 * (cnt.lower_bound(2)->second-2);
  ans += cnt.lower_bound(24)->second * (cnt.lower_bound(2)->second-1);
  ans += cnt.lower_bound(14)->second * (cnt.lower_bound(4)->second-1);
  ans += cnt.lower_bound(74)->second;
  cout << ans << "\n";
  return 0;
}
