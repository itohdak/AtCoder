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
  vector<ll> A(N+1);
  rep(i, N+1) cin >> A[i];
  ll tmp = 0;
  vector<ll> mx(N+1);
  rrep(i, N+1) {
    tmp += A[i];
    mx[i] = tmp;
  }
  tmp = 1;
  ll ans = 1;
  rep(i, N+1) {
    if(tmp < A[i]) {
      cout << -1 << endl;
      return 0;
    }
    tmp -= A[i];
    tmp *= 2;
    ans += tmp;
    if(i != N && tmp > mx[i+1]) {
      ans -= tmp-mx[i+1];
      tmp = mx[i+1];
    }
    // cout << i << ' ' << tmp << ' ' << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
