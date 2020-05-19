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
  string S;
  cin >> S;
  set<string> se;
  int N = S.size();
  rep(i, N) REP(j, i, i+3) {
    se.insert(S.substr(i, j-i+1));
  }
  // cout << se << endl;
  set<string> se2;
  for(string s: se) {
    rep(i, 1<<(s.size())) {
      string t = s;
      rep(j, s.size()) if((i>>j)&1) t[j] = '.';
      se2.insert(t);
    }
  }
  cout << se2.size() << endl;
  return 0;
}
