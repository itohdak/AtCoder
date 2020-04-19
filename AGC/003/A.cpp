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
  string S;
  cin >> S;
  vector<bool> flag(4);
  for(char c: S) {
    if(c == 'N') flag[0] = 1;
    else if(c == 'S') flag[1] = 1;
    else if(c == 'W') flag[2] = 1;
    else flag[3] = 1;
  }
  cout << ((!(flag[0]^flag[1]) && !(flag[2]^flag[3])) ? "Yes" : "No") << endl;
  return 0;
}
