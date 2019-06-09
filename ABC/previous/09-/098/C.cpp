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
  string S;
  cin >> N >> S;
  int dp[N][2];
  int tmp = 0;
  for(int i=1; i<N; i++){
    if(S[i] == 'E') tmp++;
  }
  dp[0][0] = tmp; // 東にいて東を向いてる
  dp[0][1] = 0; // 西にいて西を向いてる
  for(int i=1; i<N; i++){
    dp[i][0] = dp[i-1][0];
    dp[i][1] = dp[i-1][1];
    if(S[i] == 'E'){
      dp[i][0]--;
    }
    if(S[i-1] == 'W'){
      dp[i][1]++;
    }
  }
  int ret = N+1;
  for(int i=0; i<N; i++){
    // cout << dp[i][0] << ' ' << dp[i][1] << endl;
    if(dp[i][0] + dp[i][1] < ret)
      ret = dp[i][0] + dp[i][1];
  }
  cout << ret << endl;
  return 0;
}

