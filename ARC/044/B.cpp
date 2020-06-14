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
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> cnt(N);
  rep(i, N) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  ll ans = 1;
  if(A[0] != 0) ans = 0;
  rep(i, N) {
    if(i) {
      if(cnt[i] > 0 && cnt[i-1] == 0) ans = 0;
    } else {
      if(cnt[i] > 1) ans = 0;
    }
  }
  if(ans == 0) {
    cout << 0 << endl;
    return 0;
  }
  int iend = find(all(cnt), 0) - cnt.begin();
  rep(i, iend) {
    if(i) {
      // cout << modpow(modpow(2, cnt[i-1])-1, cnt[i]) << ' '
      //      << modpow(2, cnt[i]*cnt[i-1]/2) << endl;
      (((ans *= modpow((modpow(2, cnt[i-1])+mod-1)%mod, cnt[i])) %= mod) *= modpow(2, (ll)cnt[i]*(cnt[i]-1)/2)) %= mod;
    }
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
