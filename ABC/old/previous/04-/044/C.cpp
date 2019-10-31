#include <bits/stdc++.h>
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
  int N, A;
  cin >> N >> A;
  vector<int> X(N);
  rep(i, N) {
    cin >> X[i];
    X[i] -= A;
  }
  int MAX = 105 * 50;
  vector<vector<ll> > dp(N, vector<ll>(MAX));
  rep(i, N) {
    if(i == 0) {
      dp[i][MAX/2+X[i]] += 1;
      dp[i][MAX/2] += 1;
    } else {
      rep(j, MAX) {
        if(j+X[i] >= 0 && j+X[i] < MAX)
          dp[i][j+X[i]] += dp[i-1][j];
        dp[i][j] += dp[i-1][j];
      }
    }
  }
  cout << dp[N-1][MAX/2]-1 << endl;
  return 0;
}

