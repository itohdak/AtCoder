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
  vector<pair<int, int>> ans;
  int r = 100;
  int y = 0;
  while(r > 0) {
    int h = r;
    y += h;
    int x = 0;
    while(x + 2*r <= 1500 && r > 0) {
      ans.emplace_back(x+r, y);
      x += 2*r;
      r--;
    }
    y += h;
  }
  reverse(all(ans));
  for(auto a: ans) cout << a.first << ' ' << a.second << endl;
  return 0;
}
