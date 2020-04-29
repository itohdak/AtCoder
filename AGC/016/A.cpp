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
  vector<int> alph(26);
  vector<int> ans(26);
  for(char c: S) {
    int id = int(c-'a');
    rep(i, 26) {
      if(i == id) {
        ans[i] = max(alph[i], ans[i]);
        alph[i] = 0;
      } else {
        alph[i]++;
      }
    }
  }
  rep(i, 26) ans[i] = max(alph[i], ans[i]);
  cout << *min_element(all(ans)) << endl;
  return 0;
}
