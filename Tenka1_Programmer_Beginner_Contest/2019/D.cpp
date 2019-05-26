#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 998244353

int main(){
  int N;
  cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  vector<vector<vector<ll> > > dp(300*N+5, vector<vector<ll> >(300*N+5, vector<ll>(N+1)));
  dp[0][0][0] = 1;
  for(int i=0; i<N; i++) {
    ll s = A[i];
    for(int a=0; a<=sum-s; a++) {
      for(int b=0; b<=sum-s; b++) {
	dp[a+s][b][i+1] += dp[a][b][i];
	dp[a][b+s][i+1] += dp[a][b][i];
	dp[a][b][i+1] += dp[a][b][i];
	dp[a+s][b][i+1] %= MOD;
	dp[a][b+s][i+1] %= MOD;
	dp[a][b][i+1] %= MOD;
      }
    }
  }
  // for(int n=0; n<N+1; n++) {
  //   for(int i=0; i<sum; i++) {
  //     for(int j=0; j<sum; j++) {
  // 	cout << dp[i][j][n] << ' ';
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
  int aBegin = sum % 3 == 0 ? sum/3 : sum/3+1;
  int aEnd = sum % 2 == 0 ? sum/2-1 : (sum-1)/2;
  ll ans = 0;
  for(int a=aBegin; a<=aEnd; a++) {
    int bBegin = (sum-a) % 2 == 0 ? (sum-a)/2 : (sum-a+1)/2;
    int bEnd = sum-a-1;
    for(int b=bBegin; b<=bEnd; b++) {
      int c = sum-a-b;
      if(a+b>c && b+c>a && c+a>b) {
	// cout << a << ' ' << b << ' ' << c << ": " << dp[a][b][N] << endl;
	ans += dp[a][b][N];
	ans %= MOD;
      }
    }
  }
  ans *= 3;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}

