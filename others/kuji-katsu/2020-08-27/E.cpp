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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> T(n), A(n);
  rep(i, n) cin >> T[i];
  rep(i, n) cin >> A[i];
  vector<ll> mn(n, 1), mx(n, longinf);
  rep(i, n) {
    if(i == 0 || T[i] > T[i-1]) {
      chmax(mn[i], T[i]);
      chmin(mx[i], T[i]);
    } else {
      chmin(mx[i], T[i]);
    }
  }
  rrep(i, n) {
    if(i == n-1 || A[i] > A[i+1]) {
      chmax(mn[i], A[i]);
      chmin(mx[i], A[i]);
    } else {
      chmin(mx[i], A[i]);
    }
  }
  ll ans = 1;
  rep(i, n) {
    if(mx[i] < mn[i]) ans = 0;
    else (ans *= mx[i]-mn[i]+1) %= mod;
  }
  cout << ans << endk;
  return 0;
}
