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
  vector<int> A(M), B(M);
  vector<int> C(M);
  rep(i, M) {
    cin >> A[i] >> B[i];
    int cbyte = 0;
    rep(j, B[i]) {
      int c;
      cin >> c;
      c--;
      cbyte += (1<<c);
    }
    C[i] = cbyte;
  }
  vector<vector<int> > dp(1<<N, vector<int>(M+1, inf));
  rep(i, M+1) dp[0][i] = 0;
  REP(i, 1, M+1) {
    rep(j, 1<<N) {
      dp[j|C[i-1]][i] = min(dp[j|C[i-1]][i], dp[j][i-1]+A[i-1]);
      dp[j][i] = min(dp[j][i], dp[j][i-1]);
    }
  }
  cout << (dp[(1<<N)-1][M] == inf ? -1 : dp[(1<<N)-1][M]) << endl;
  return 0;
}

