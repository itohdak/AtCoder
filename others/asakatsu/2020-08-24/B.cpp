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
  vector<ll> A(n);
  bool zero = false;
  rep(i, n) {
    cin >> A[i];
    if(A[i] == 0) zero = true;
  }
  if(zero) {
    cout << 0 << endk;
    return 0;
  }
  ll ans = 1;
  rep(i, n) {
    if(A[i] > (ll)1e+18/ans) {
      cout << -1 << endk;
      return 0;
    }
    ans *= A[i];
  }
  cout << ans << endk;
  return 0;
}
