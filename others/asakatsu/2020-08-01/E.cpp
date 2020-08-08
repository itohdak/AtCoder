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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n+1); rep(i, n+1) cin >> A[i];
  auto no = [&]() {
    cout << -1 << "\n";
    exit(0);
  };
  vector<ll> mn(n+2), mx(n+2);
  mn[0] = 1, mx[0] = 1;
  rep(i, n+1) {
    if(i==n) {
      if(mn[i]<=A[i] && A[i]<=mx[i]) {
        break;
      } else {
        no();
      }
    }
    if(mx[i]-A[i]<0) no();
    mn[i+1] = max(mn[i]-A[i], 0LL);
    mx[i+1] = min((mx[i]-A[i])*2, longinf);
  }
  ll ans = 0;
  ll tmp = A[n];
  rrep(i, n+1) {
    ans += tmp;
    if(i) tmp = min(mx[i-1], tmp+A[i-1]);
  }
  cout << ans << "\n";
  return 0;
}
