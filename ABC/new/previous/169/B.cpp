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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> A(N);
  bool zero = false;
  rep(i, N) {
    cin >> A[i];
    if(A[i] == 0) zero = true;
  }
  if(zero) cout << 0 << endl;
  else {
    ll large = 1000000000000000000LL;
    ll ans = 1;
    rep(i, N) {
      if(ans > LONG_LONG_MAX / A[i] || ans * A[i] > large) {
        cout << -1 << endl;
        return 0;
      }
      ans *= A[i];
    }
    cout << ans << endl;
  }
  return 0;
}
