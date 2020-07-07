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
  string s; cin >> s;
  int n = s.size();
  for(int i=n/2*2; i>=0; i-=2) {
    if(n == i) continue;
    // cout << s.substr(0, i/2) << ' ' << s.substr(i/2, i/2) << "\n";
    if(s.substr(0, i/2) == s.substr(i/2, i/2)) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
  return 0;
}
