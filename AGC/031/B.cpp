#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
  int N;
  cin >> N;
  vector<int> C(N);
  for(int i=0; i<N; i++)
    cin >> C[i];
  C.push_back(0);
  vector<int> next(N, -1);
  {
    map<int, int> tmp;
    for(int i=0; i<N; i++) {
      if(C[i] != C[i+1]) {
	if(tmp.find(C[i]) != tmp.end()) {
	  next[tmp[C[i]]] = i;
	  tmp[C[i]] = i;
	} else {
	  tmp[C[i]] = i;
	}
      }
    }
  }

  vector<ll> dp(N, 0);
  dp[0] = 1;
  for(int i=0; i<N; i++) {
    if(i != 0) {
      dp[i] += dp[i-1];
      dp[i] %= MOD;
    }
    if(next[i] != -1) {
      dp[next[i]] += dp[i];
      dp[next[i]] %= MOD;
    }
  }
  cout << dp[N-1] << endl;

  return 0;
}

