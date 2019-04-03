#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <climits>

using namespace std;
#define ll long long
#define MOD 1000000007

bool condition(int j, int k, int l, int m) {
  if(j == 0 && k == 2 && l == 1) // AGCx
    return false;
  if(j == 0 && k == 1 && l == 2) // ACGx
    return false;
  if(j == 2 && k == 0 && l == 1) // GACx
    return false;
  if(j == 0 && l == 2 && m == 1) // AxGC
    return false;
  if(k == 0 && l == 2 && m == 1) // xAGC
    return false;
  if(k == 2 && l == 0 && m == 1) // xGAC
    return false;
  if(k == 0 && l == 1 && m == 2) // xACG
    return false;
  if(j == 0 && k == 2 && m == 1) // AGxC
    return false;
  return true;
}

int main(){
  int N;
  cin >> N;
  vector<vector<ll> > dp(4*4*4, vector<ll>(N+1, 0));
  char C[] = {'A', 'C', 'G', 'T'};
  for(int j=0; j<4; j++) {
    for(int k=0; k<4; k++) {
      for(int l=0; l<4; l++) {
	if(condition(j, k, l, INT_MAX))
	  dp[(j<<4)+(k<<2)+l][3] = 1;
      }
    }
  }
  for(int i=4; i<=N; i++) {
    for(int j=0; j<4; j++) {
      for(int k=0; k<4; k++) {
	for(int l=0; l<4; l++) {
	  for(int m=0; m<4; m++) {
	    if(condition(j, k, l, m)) {
	      dp[(k<<4)+(l<<2)+m][i] += dp[(j<<4)+(k<<2)+l][i-1];
	      dp[(k<<4)+(l<<2)+m][i] %= MOD;
	    }
	  }
	}
      }
    }
  }
  ll ans = 0;
  for(int i=0; i<4*4*4; i++) {
    ans += dp[i][N];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}

