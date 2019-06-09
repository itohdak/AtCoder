#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <climits>

using namespace std;
#define ll long long

int main(){
  int match[10] = {INT_MAX, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  int N, M;
  cin >> N >> M;
  vector<int> nums(M);
  for(int i=0; i<M; i++)
    cin >> nums[i];
  sort(nums.begin(), nums.end(), greater<int>());
  vector<int> dp(N+1, INT_MIN);
  dp[0] = 0;
  for(int i=1; i<N+1; i++) {
    for(int j=0; j<M; j++) {
      int pre = i - match[nums[j]];
      if(pre >= 0) {
	dp[i] = max(dp[i], dp[pre] + 1);
      }
    }
  }
  int tmp = N;
  int digit = dp[tmp];
  for(int i=0; i<digit; i++) {
    for(int j=0; j<M; j++) {
      if(tmp - match[nums[j]] >= 0 && dp[tmp - match[nums[j]]] == digit - 1 - i) {
	cout << nums[j];
	tmp -= match[nums[j]];
	break;
      }
    }
  }
  cout << endl;
  return 0;
}

