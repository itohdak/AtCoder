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
  ll ans = 0;
  rep(i, 1<<(n-1)) {
    ll cur = s[0]-'0';
    rep(j, n-1) {
      if((i>>j)&1) {
        ans += cur;
        cur = 0;
      } else {
        cur *= 10;
      }
      cur += s[j+1]-'0';
    }
    ans += cur;
  }
  cout << ans << "\n";
  return 0;
}
