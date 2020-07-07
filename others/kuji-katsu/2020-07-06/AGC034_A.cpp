#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;
  string s; cin >> s;
  if(s[a]=='#' || s[b]=='#' || s[c]=='#' || s[d]=='#') {
    cout << "No" << "\n";
    return 0;
  }
  bool ok = true;
  for(int i=a; i<c; i++) {
    if(s[i]=='#' && s[i+1]=='#') ok = false;
  }
  for(int i=b; i<d; i++) {
    if(s[i]=='#' && s[i+1]=='#') ok = false;
  }
  if(d < c) {
    bool ok2 = false;
    for(int i=b; i<=d; i++) {
      if(i>0 && s[i-1]=='.' && s[i]=='.' && i<n-1 && s[i+1]=='.') ok2 = true;
    }
    ok &= ok2;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
