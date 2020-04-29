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
  string S, T;
  cin >> N >> S >> T;
  rep(i, N) {
    bool ok = true;
    rep(j, N-i) {
      if(S[i+j] != T[j]) {
	ok = false;
	break;
      }
    }
    if(ok) {
      cout << i+N << endl;
      return 0;
    }
  }
  cout << 2*N << endl;
  return 0;
}
