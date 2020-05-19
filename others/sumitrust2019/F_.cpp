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
  vector<ll> T(2), A(2), B(2);
  rep(i, 2) cin >> T[i];
  rep(i, 2) cin >> A[i];
  rep(i, 2) cin >> B[i];
  if(A[0]<B[0]) rep(i, 2) swap(A[i], B[i]);
  ll d1 = (A[0]-B[0])*T[0];
  ll d2 = (A[0]-B[0])*T[0]+(A[1]-B[1])*T[1];
  if(d2 > 0) {
    cout << 0 << endl;
  } else if(d2 == 0) {
    cout << "infinity" << endl;
  } else {
    ll cnt = 1 + 2 * (d1/(-d2));
    if(d1%(-d2) == 0) cnt--;
    cout << cnt << endl;
  }
  return 0;
}
