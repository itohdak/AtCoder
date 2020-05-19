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
  vector<string> S(3);
  rep(i, 3) cin >> S[i];
  vector<vector<int>> cnt(3, vector<int>(26));
  rep(i, 3) for(char c: S[i]) cnt[i][int(c-'A')]++;
  bool ok = true;
  int mn = 0, mx = 0;
  rep(i, 26) {
    if(cnt[0][i]+cnt[1][i]<cnt[2][i]) {
      ok = false;
      break;
    }
    mn += max(0, cnt[2][i]-cnt[1][i]);
    mx += min(cnt[0][i], cnt[2][i]);
  }
  int N = S[0].size();
  if(ok && mn <= N/2 && N/2 <= mx) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
