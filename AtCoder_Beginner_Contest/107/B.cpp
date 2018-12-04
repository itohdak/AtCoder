#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  vector<bool> row(H, true);
  vector<bool> col(W, true);
  for(int i=0; i<H; i++) {
    cin >> A[i];
    for(int j=0; j<W; j++) {
      if(A[i][j] == '#') {
	row[i] = false;
	col[j] = false;
      }
    }
  }
  
  for(int i=0; i<H; i++) {
    for(int j=0; j<W; j++) {
      if(!row[i] && !col[j]) {
	cout << A[i][j];
      }
    }
    if(!row[i])
      cout << endl;
  }
  
  return 0;
}

