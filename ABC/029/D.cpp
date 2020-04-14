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
  ll N;
  cin >> N;
  ll Norig = N;
  ll ans = 0;
  ll pow = 1;
  while(N > 0) {
    int n = N % 10;
    ans += N/10 * pow;
    if(n > 1) {
      ans += pow;
    } else if(n == 1) {
      ans += Norig % pow + 1;
    } else {
      ans += 0;
    }
    N /= 10;
    pow *= 10;
  }
  cout << ans << endl;
  return 0;
}
