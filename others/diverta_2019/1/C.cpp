#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0; i<N; i++)
    cin >> S[i];
  int numAB = 0;
  int numHeadB = 0, numTailA = 0, numHeadBAndTailA = 0;
  for(int i=0; i<N; i++) {
    if(*(S[i].begin()) == 'B' && *(S[i].end()-1) == 'A') numHeadBAndTailA++;
    else if(*(S[i].begin()) == 'B') numHeadB++;
    else if(*(S[i].end()-1) == 'A') numTailA++;
    for(int j=0; j<S[i].size()-1; j++)
      if(S[i][j] == 'A' && S[i][j+1] == 'B')
	numAB++;
  }
  // cout << numAB << ' ' << numHeadB << ' ' << numTailA << ' ' << numHeadBAndTailA << endl;
  int ans = numAB;
  if(numHeadBAndTailA > 0) {
    ans += numHeadBAndTailA - 1;
    if(numHeadB == 0 && numTailA == 0) {
    } else if(numHeadB == 0) {
      ans += 1;
    } else if(numTailA == 0) {
      ans += 1;
    } else {
      ans += 2;
      ans += min(numHeadB-1, numTailA-1);
    }
  } else {
    ans += min(numHeadB, numTailA);
  }
  cout << ans << endl;
  return 0;
}

