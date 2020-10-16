#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  sort(all(A));
  if(n%2) {
    ll ans = 0;
    {
      ll tmp = 0;
      rep(i, n) {
        if(i < n/2) tmp -= 2*A[i];
        else if(i < n/2+2) tmp += A[i];
        else tmp += 2*A[i];
      }
      chmax(ans, tmp);
    }
    {
      ll tmp = 0;
      rep(i, n) {
        if(i < n/2-1) tmp -= 2*A[i];
        else if(i < n/2+1) tmp -= A[i];
        else tmp += 2*A[i];
      }
      chmax(ans, tmp);
    }
    cout << ans << endk;
  } else {
    ll ans = 0;
    rep(i, n) {
      if(i < n/2-1) ans -= 2*A[i];
      else if(i == n/2-1) ans -= A[i];
      else if(i == n/2) ans += A[i];
      else ans += 2*A[i];
    }
    cout << ans << endk;
  }
  return 0;
}