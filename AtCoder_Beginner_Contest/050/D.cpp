#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
  ll N;
  cin >> N;
  ll max = ceil(log2(N));
  ll dp[max][3];
  for(int i=0; i<max; i++)
    for(int j=0; j<3; j++)
      if(i == max-1)
	if(j == (N >> (max-1)))
	  if(j == 1)
	    dp[i][j] = 2;
	  else
	    dp[i][j] = 1;
	else
	  dp[i][j] = 0;
      else
	dp[i][j] = 0;
  
  for(ll i=max-1; i>0; i--){
    int N_ith = (N >> (i-1)) - ((N >> i) << 1); // Nのi-1番目のビット
    cout << N_ith << ' ';
    cout << dp[i][0] << ' ' << dp[i][1] << ' '<< dp[i][2] << endl;
    switch(N_ith){
    case 0:
      dp[i-1][0] =                                   dp[i][0];
      dp[i-1][1] =                    dp[i][1] + 2 * dp[i][0];
      dp[i-1][2] = 4 * dp[i][2] + 3 * dp[i][1] +     dp[i][0];
      break;
      dp[i-1][0] =                               0 * dp[i][0];
      dp[i-1][1] =                0 * dp[i][1] + 1 * dp[i][0];
      dp[i-1][2] = 4 * dp[i][2] + 4 * dp[i][1] + 3 * dp[i][0];
    case 1:
      break;
    }
  }

  cout << (dp[0][0] + dp[0][1] + dp[0][2]) % MOD << endl;
  return 0;
}

