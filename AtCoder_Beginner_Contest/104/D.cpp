#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 1000000007

ll dp[100000][4];

int main(){
  string S;
  cin >> S;
  int N = (int)S.size();
  dp[0][0] = 1;
  for(int i=1; i<=N; i++) {
    if(S[i-1] == '?') {
      dp[i][0] = 3 * dp[i-1][0];
      dp[i][1] = 3 * dp[i-1][1];
      dp[i][2] = 3 * dp[i-1][2];
      dp[i][3] = 3 * dp[i-1][3];
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = dp[i-1][1];
      dp[i][2] = dp[i-1][2];
      dp[i][3] = dp[i-1][3];
    }
    if(S[i-1] == 'A')
      dp[i][1] += dp[i-1][0];
    else if(S[i-1] == 'B')
      dp[i][2] += dp[i-1][1];
    else if(S[i-1] == 'C')
      dp[i][3] += dp[i-1][2];
    else { // S[i-1] == '?'
      dp[i][1] += dp[i-1][0];
      dp[i][2] += dp[i-1][1];
      dp[i][3] += dp[i-1][2];
    }

    dp[i][0] %= MOD;
    dp[i][1] %= MOD;
    dp[i][2] %= MOD;
    dp[i][3] %= MOD;
  }
  // for(int i=0; i<N+1; i++) {
  //   for(int j=0; j<4; j++) {
  //     cout << dp[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << dp[N][3] << endl;
  return 0;
}

