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
  vector<ll> A(n), sum(n+1), sumb(n+1);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
    sumb[i+1] = sumb[i] ^ A[i];
  }
  // a + b = (a ^ b) + (a & b) << 1
  int l=0, r=0;
  ll ans = 0;
  rep(l, n+1) {
    while(r < n+1 && sum[r]-sum[l]==(sumb[r]^sumb[l])) r++;
    // cout << l << ' ' << r << endk;
    ans += r-l-1;
  }
  cout << ans << endk;
  return 0;
}
