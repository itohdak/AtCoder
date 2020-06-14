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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> to(N);
  vector<vector<int>> from(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    to[x].push_back(y);
    from[y].push_back(x);
  }
  vector<ll> dp(1<<N);
  dp[0] = 1;
  rep(i, 1<<N) {
    rep(j, N) {
      if((i>>j)&1) {
        bool ok = true;
        for(int f: from[j]) {
          if((i>>f)&1) ok = false;
        }
        if(ok) dp[i] += dp[i&~(1<<j)];
      }
    }
  }
  cout << dp[(1<<N)-1] << endl;
  return 0;
}
