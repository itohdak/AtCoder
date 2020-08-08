#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

#define MAX_N 55
ll C[MAX_N][MAX_N];
void make() {
  rep(i, MAX_N) {
    C[i][1] = i;
    C[i][i] = 1;
    C[0][i] = 1;
    C[i][0] = 1;
  }
  REP(i, 1, MAX_N) rep(j, i) {
    if(i-1 < 0 || j-1 < 0) continue;
    C[i][j] = C[i-1][j] + C[i-1][j-1];
  }
}
ll comb(ll n, ll r) {
  if(n < 0)       return 0;
  else if(n < r)  return 0;
  else            return C[n][r];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n, p; cin >> n >> p;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int nOdd=0, nEven=0;
  rep(i, n) (A[i]%2==0 ? nEven : nOdd)++;
  if(nOdd == 0) {
    if(p == 1) cout << 0 << "\n";
    else cout << (1LL<<n) << "\n";
  } else if(nEven == 0) {
    if(p == 1) {
      ll ans = 0;
      rep(i, n+1) if(i%2==1) ans += comb(n, i);
      cout << ans << "\n";
    } else {
      ll ans = 0;
      rep(i, n+1) if(i%2==0) ans += comb(n, i);
      cout << ans << "\n";
    }
  } else {
    if(p == 1) {
      ll ans = 0;
      rep(i, nOdd+1) if(i%2==1) ans += comb(nOdd, i);
      ans *= (1<<nEven);
      cout << ans << "\n";
    } else {
      ll ans = 0;
      rep(i, nOdd+1) if(i%2==0) ans += comb(nOdd, i);
      ans *= (1<<nEven);
      cout << ans << "\n";
    }
  }
  return 0;
}
