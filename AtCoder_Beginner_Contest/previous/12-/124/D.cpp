#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  string S;
  cin >> N >> K >> S;
  vector<int> zeroOne;
  int begin = 0;
  for(int i=0; i<N; i++) {
    if(S[i] != S[begin]) {
      zeroOne.push_back(i-begin);
      begin = i;
    }
  }
  zeroOne.push_back(N-begin);

  vector<int> sumZeroOne(zeroOne.size()+1);
  sumZeroOne[0] = 0;
  for(int i=0; i<zeroOne.size(); i++)
    sumZeroOne[i+1] = sumZeroOne[i] + zeroOne[i];

  int ans = 0;
  int ib = S[0] == '0' ? -1 : 0;
  for(int i=ib; i<(int)sumZeroOne.size(); i+=2) {
    int tmp = sumZeroOne[min((int)sumZeroOne.size()-1, i+2*K+1)] - sumZeroOne[max(i,0)];
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}

