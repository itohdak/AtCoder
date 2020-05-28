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
  string s, t;
  cin >> s >> t;
  string sl = s, tl = t;
  transform(all(sl), sl.begin(), [&](char c){ return tolower(c); });
  transform(all(tl), tl.begin(), [&](char c){ return tolower(c); });
  if(s == t) {
    cout << "same" << endl;
  } else if(sl == tl) {
    cout << "case-insensitive" << endl;
  } else {
    cout << "different" << endl;
  }
  return 0;
}
