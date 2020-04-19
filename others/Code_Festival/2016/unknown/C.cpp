#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N;
  cin >> N;
  vector<ll> T(N+2), A(N+2);
  ll ans = 1;
  rep(i, N) cin >> T[i+1];
  rep(i, N) cin >> A[i+1];
  T[0] = 0;    T[N+1] = T[N];
  A[0] = A[1]; A[N+1] = 0;
  REP(i, 1, N+1) {
    if(T[i] != T[i-1] &&
       A[i] != A[i+1] &&
       T[i] != A[i]) {
      ans = 0;
    } else if(T[i] != T[i-1]) {
      if(T[i] > A[i]) ans = 0;
    } else if(A[i] != A[i+1]) {
      if(A[i] > T[i]) ans = 0;
    } else {
      (ans *= min(T[i], A[i])) %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
