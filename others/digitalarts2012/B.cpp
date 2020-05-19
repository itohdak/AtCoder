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
  int hash = 0;
  for(char c: S) hash += int(c-'a')+1;
  // cout << hash << endl;
  string ans = "";
  while(hash > 26) {
    ans += "z";
    hash -= 26;
  }
  ans += (char)('a'+(hash-1));
  if(ans == S) {
    if(ans == "zzzzzzzzzzzzzzzzzzzz") cout << "NO" << endl;
    else if(ans == "a") cout << "NO" << endl;
    else if(ans.size() == 1) {
      ans[0]--;
      ans += "a";
      cout << ans << endl;
    } else {
      ans[0]--;
      ans[ans.size()-1]++;
      cout << ans << endl;
    }
  } else {
    cout << ans << endl;
  }
  return 0;
}
