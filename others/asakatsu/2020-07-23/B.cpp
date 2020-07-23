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
  string a, b; cin >> a >> b;
  int ans = atoi(a.c_str()) - atoi(b.c_str());
  rep(i, 3) {
    string tmpa = a;
    rep(j, 10) {
      if(i==0 && j==0) continue;
      tmpa[i] = '0'+j;
      ans = max(atoi(tmpa.c_str()) - atoi(b.c_str()), ans);
    }
  }
  rep(i, 3) {
    string tmpb = b;
    rep(j, 10) {
      if(i==0 && j==0) continue;
      tmpb[i] = '0'+j;
      ans = max(atoi(a.c_str()) - atoi(tmpb.c_str()), ans);
    }
  }
  cout << ans << "\n";
  return 0;
}
