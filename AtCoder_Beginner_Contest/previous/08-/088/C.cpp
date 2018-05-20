#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int C[3][3];
  for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
      cin >> C[i][j];
  bool ret = true;
  if(C[0][0] - C[0][1] == C[1][0] - C[1][1] &&
     C[0][0] - C[0][1] == C[2][0] - C[2][1] &&
     C[0][1] - C[0][2] == C[1][1] - C[1][2] &&
     C[0][1] - C[0][2] == C[2][1] - C[2][2] &&
     C[0][0] - C[1][0] == C[0][1] - C[1][1] &&
     C[0][0] - C[1][0] == C[0][2] - C[1][2] &&
     C[1][0] - C[2][0] == C[1][1] - C[2][1] &&
     C[1][0] - C[2][0] == C[1][2] - C[2][2])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

