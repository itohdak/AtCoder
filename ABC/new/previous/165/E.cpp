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
  int N, M;
  cin >> N >> M;
  // if(N%2) {
  //   rep(i, M) cout << i+1 << ' ' << M*2-i << endl;
  // } else {
    int a = 0;
    set<int> se;
    rep(i, M) {
      int b = N-i-(i+1);
      if(a == 0 && (se.count(min(b, N-b)) || b == N-b)) a = 1;
      cout << i+1 << ' ' << N-i-a << endl;
      if(a == 0) se.insert(min(b, N-b));
    }
  // }
  return 0;
}
