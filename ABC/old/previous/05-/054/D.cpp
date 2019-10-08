#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct data {
  int a, b, c;
  data(int a=0, int b=0, int c=0): a(a), b(b), c(c) {}
};

int main() {
  int N, Ma, Mb;
  cin >> N >> Ma >> Mb;
  vector<data> D(N);
  rep(i, N)
    cin >> D[i].a >> D[i].b >> D[i].c;
  vector<vector<vector<int> > > dp(N+1, vector<vector<int> >(405, vector<int>(405, inf)));
  dp[0][0][0] = 0;
  rep(i, N) {
    int a = D[i].a, b = D[i].b, c = D[i].c;
    rep(j, 405) {
      rep(k, 405) {
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        int an = j + a, bn = k + b;
        if(an < 405 && bn < 405 && dp[i][j][k] < inf)
          dp[i+1][an][bn] = min(dp[i+1][an][bn], dp[i][j][k] + c);
      }
    }
  }
  int ans = inf;
  REP(j, 1, 405)
    REP(k, 1, 405)
      if(j * Mb == k * Ma)
        ans = min(ans, dp[N][j][k]);
  cout << (ans == inf ? -1 : ans) << endl;
  return 0;
}

