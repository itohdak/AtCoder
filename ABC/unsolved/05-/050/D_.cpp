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
  ll max = floor(log2(N));
  ll dp[max+1][N+1];
  for(int i=0; i<max+1; i++)
    for(int j=0; j<N+1; j++)
      dp[i][j] = 0;
  
  ll tmp;
  if((tmp = (ll)pow(2, max) * 2) <= N)
    dp[max][tmp] = 1;
  if((tmp = (ll)pow(2, max)) <= N)
    dp[max][tmp] = 1;
  dp[max][0] = 1;

  for(ll i=max; i>0; i--){
    for(ll j=0; j<N; j++){
      if((tmp = j + (ll)pow(2, i-1) * 2) <= N)
	dp[i-1][tmp] += dp[i][j];
      if((tmp = j + (ll)pow(2, i-1)) <= N)
	dp[i-1][tmp] += dp[i][j];
      if((tmp = j) <= N)
	dp[i-1][tmp] += dp[i][j];
    }
  }

  for(int i=0; i<max+1; i++){
    for(int j=0; j<N+1; j++){
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  cout << accumulate(dp[0], dp[0]+N+1, 0) % MOD << endl;
  return 0;
}

