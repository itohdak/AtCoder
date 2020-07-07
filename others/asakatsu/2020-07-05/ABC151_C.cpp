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
  int n, m; cin >> n >> m;
  vector<int> pen(n);
  vector<bool> done(n);
  rep(i, m) {
    int p; string s;
    cin >> p >> s;
    if(!done[--p]) {
      if(s == "WA") pen[p]++;
      else done[p] = true;
    }
  }
  int ans = 0;
  rep(i, n) if(done[i]) ans += pen[i];
  cout << accumulate(all(done), 0) << ' ' << ans << "\n";
  return 0;
}
