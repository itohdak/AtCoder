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
  int L;
  cin >> L;
  vector<int> B(L);
  int tmp = 0;
  rep(i, L) {
    cin >> B[i];
    tmp ^= B[i];
  }
  if(tmp != 0) cout << -1 << endl;
  else {
    int prev = 0;
    cout << 0 << endl;
    rep(i, L-1) {
      cout << (prev ^ B[i]) << endl;
      prev ^= B[i];
    }
  }
  return 0;
}
