#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int A[100][25];
int B[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main(){
  int N;
  cin >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<25; j++) {
      if(i > 0)
	A[i][j] = A[i-1][j];
      int tmp = i+1;
      while(tmp % B[j] == 0) {
	tmp /= B[j];
	A[i][j]++;
      }
    }
  }

  int seventyfour = 0;
  int twentyfour = 0;
  int forteen = 0;
  int four = 0;
  int two = 0;
  for(int j=0; j<25; j++) {
    if(A[N-1][j] >= 74)
      seventyfour++;
    if(A[N-1][j] >= 24)
      twentyfour++;
    if(A[N-1][j] >= 14)
      forteen++;
    if(A[N-1][j] >= 4)
      four++;
    if(A[N-1][j] >= 2)
      two++;
  }

  int ans = 0;
  ans += max(four * (four-1) / 2 * (two-2), 0); // 2 * 4 * 4
  ans += max(twentyfour * (two-1), 0); // 2 * 24
  ans += max(forteen * (four-1), 0); // 4 * 14
  ans += seventyfour; // 74
  cout << ans << endl;
  return 0;
}

