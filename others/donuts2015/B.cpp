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

int bitcount32(unsigned long dw32) {
  dw32 = ((dw32 & 0xAAAAAAAA) >>  1) + (dw32 & 0x55555555);
  dw32 = ((dw32 & 0xCCCCCCCC) >>  2) + (dw32 & 0x33333333);
  dw32 = ((dw32 & 0xF0F0F0F0) >>  4) + (dw32 & 0x0F0F0F0F);
  dw32 = ((dw32 & 0xFF00FF00) >>  8) + (dw32 & 0x00FF00FF);
  dw32 = ((dw32 & 0xFFFF0000) >> 16) + (dw32 & 0x0000FFFF);
  return dw32;
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  vector<int> B(M), C(M);
  vector<int> I(M);
  rep(i, M) {
    cin >> B[i] >> C[i];
    rep(j, C[i]) {
      int k;
      cin >> k;
      --k;
      I[i] += (1<<k);
    }
  }
  vector<ll> dp(1<<N);
  rep(i, 1<<N) {
    rep(j, N) if(i&(1<<j)) dp[i] += A[j];
    rep(j, M) if(bitcount32(i&I[j]) >= 3) dp[i] += B[j];
  }
  ll ans = 0;
  rep(i, 1<<N) if(bitcount32(i) == 9) ans = max(dp[i], ans);
  cout << ans << endl;
  return 0;
}
