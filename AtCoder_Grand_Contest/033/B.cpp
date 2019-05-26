#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int H, W, N;
  cin >> H >> W >> N;
  int x, y;
  cin >> x >> y;
  x--; y--;
  string S, T;
  cin >> S >> T;
  vector<vector<int> > countR(N+1, vector<int>(2));
  vector<vector<int> > countL(N+1, vector<int>(2));
  vector<vector<int> > countU(N+1, vector<int>(2));
  vector<vector<int> > countD(N+1, vector<int>(2));
  bool ans = true;
  for(int i=1; i<N+1; i++) {
    int j = 0;
    countR[i][j] = countR[i-1][j];
    countL[i][j] = countL[i-1][j];
    countU[i][j] = countU[i-1][j];
    countD[i][j] = countD[i-1][j];
    switch(S[i-1]) {
    case 'R':
      countR[i][j]++;
      break;
    case 'L':
      countL[i][j]++;
      break;
    case 'U':
      countU[i][j]++;
      break;
    case 'D':
      countD[i][j]++;
      break;
    }
    j = 1;
    countR[i][j] = countR[i-1][j];
    countL[i][j] = countL[i-1][j];
    countU[i][j] = countU[i-1][j];
    countD[i][j] = countD[i-1][j];
    switch(T[i-1]) {
    case 'R':
      countR[i][j]++;
      break;
    case 'L':
      countL[i][j]++;
      break;
    case 'U':
      countU[i][j]++;
      break;
    case 'D':
      countD[i][j]++;
      break;
    }
    if(y + (countR[i][0] - countL[i-1][1]) >= W ||
       y - (countL[i][0] - countR[i-1][1]) <  0 ||
       x + (countD[i][0] - countU[i-1][1]) >= H ||
       x - (countU[i][0] - countD[i-1][1]) <  0) {
      ans = false;
    }
    if(y + (countR[i][0] - countL[i][1]) <  0)
      countL[i][1] = max(0, y + (countR[i][0] - countL[i][1])) + y + countR[i][0];
    if(y - (countL[i][0] - countR[i][1]) >= W)
      countR[i][1] = min(W-1, y - (countL[i][0] - countR[i][1])) - y + countL[i][0];
    if(x + (countD[i][0] - countU[i][1]) <  0)
      countU[i][1] = max(0, x + (countD[i][0] - countU[i][1])) + x + countD[i][0];
    if(x - (countU[i][0] - countD[i][1]) >= H)
      countD[i][1] = min(H-1, x - (countU[i][0] - countD[i][1])) - x + countU[i][0];
  }
  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

