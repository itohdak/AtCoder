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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N; ll K;
  cin >> N >> K;
  vector<ll> A(N);
  vector<int> cnt(45);
  rep(i, N) {
    cin >> A[i];
    ll a = A[i];
    int j = 0;
    while(a > 0) {
      cnt[j] += a&1;
      a >>= 1;
      j++;
    }
  }
  // rep(i, 4) cout << cnt[i] << endl;
  ll k = 0;
  rrep(i, 45) {
    if(cnt[i] <= (N-1)/2 && k + (1LL<<i) <= K) {
      // cout << i << ' ' << k + (1LL<<i) << endl;
      k += (1LL<<i);
    }
  }
  // cout << k << "\n";
  ll ans = 0;
  rep(i, N) ans += A[i] ^ k;
  cout << ans << "\n";
  return 0;
}
