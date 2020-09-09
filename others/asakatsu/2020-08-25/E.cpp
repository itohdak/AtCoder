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
  int n, m; cin >> n >> m;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> B(m), C(m);
  rep(i, m) {
    cin >> B[i];
    int c; cin >> c;
    rep(j, c) {
      int k; cin >> k;
      k--;
      C[i] |= (1<<k);
    }
  }
  ll ans = 0;
  rep(i, 1<<n) {
    if(__builtin_popcount(i) != 9) continue;
    ll tmp = 0;
    rep(j, n) if((i>>j)&1) tmp += A[j];
    rep(j, m) if(__builtin_popcount(C[j]&i) >= 3) tmp += B[j];
    chmax(ans, tmp);
  }
  cout << ans << endk;
  return 0;
}
