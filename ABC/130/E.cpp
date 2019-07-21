#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> S(N), T(M);
  rep(i, N) cin >> S[i];
  rep(i, M) cin >> T[i];
  vector<vector<ll> > sum(N+1, vector<ll>(M+1));
  vector<vector<ll> > dp(N+1, vector<ll>(M+1));
  dp[0][0] = 1;
  rep(i, N+1) {
    rep(j, M+1) {
      if(i != 0 && j != 0 && S[i-1] == T[j-1])
	(dp[i][j] += sum[i-1][j-1]) %= mod;
      (sum[i][j] += dp[i][j]) %= mod;
      if(j != 0)
	(sum[i][j] += sum[i][j-1]) %= mod;
    }
    if(i != 0)
      rep(j, M+1)
	(sum[i][j] += sum[i-1][j]) %= mod;
  }
  cout << sum[N][M] << endl;
  return 0;
}

