#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
int main() {
  int N, K;
  cin >> N >> K;
  ll ans = 0;
  vector<ll> cnt(K+1);
  RREP(i, K, 1) {
    cnt[i] = binary_pow(K/i, N);
    for(ll j=i*2; j<=K; j+=i) cnt[i] -= cnt[j];
    if(cnt[i] < 0) (cnt[i] += (abs(cnt[i])+mod-1)/mod*mod) %= mod;
    (ans += cnt[i]*i%mod) %= mod;
  }
  cout << ans << endl;
  return 0;
}
