#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<int> dp(N+1, N);
  dp[N] = 0;
  for(int i=N; i>=0; i--){
    for(int j=0; j<=ceil(log(N) / log(9)); j++)
      if(i + (int)pow(9, j) <= N)
	dp[i] = min(dp[i], dp[i + (int)pow(9, j)] + 1);
    for(int j=0; j<=ceil(log(N) / log(6)); j++)
      if(i + (int)pow(6, j) <= N)
	dp[i] = min(dp[i], dp[i + (int)pow(6, j)] + 1);
  }
  cout << dp[0] << endl;
  return 0;
}

