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
  int N, K;
  cin >> N >> K;
  vector<ll> cnt(K+1);
  for(int k=K; k>=1; k--) {
    cnt[k] = modpow(K/k, N);
    for(int j=2; k*j<=K; j++) {
      (cnt[k] += mod - cnt[k*j]) %= mod;
    }
  }
  ll ans = 0;
  for(int k=1; k<=K; k++) {
    (ans += k * cnt[k]) %= mod;
  }
  cout << ans << "\n";
  return 0;
}
