#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long
#define MOD 1000000007

ll A[100][9];

bool valid(int n, int w) {
  bool ret = true;
  int prev = n % 2;
  n /= 2;
  for(int i=0; i<w-1; i++) {
    if((n % 2) * prev == 1) {
      ret = false;
      break;
    }
    prev = n % 2;
    n /= 2;
  }
  return ret;
}

int main(){
  int H, W, K;
  cin >> H >> W >> K;
  A[0][0] = 1;
  for(int i=1; i<H+1; i++) {
    for(int j=0; j<pow(2,W-1); j++) {
      // init
      if(valid(j, W-1)) {
	int tmp = j;
	int prev = 0;
	for(int k=0; k<W; k++) {
	  if(prev == 0) {
	    if(tmp % 2 == 0) {
	      A[i][k] += A[i-1][k];
	      A[i][k] %= MOD;
	    } else {
	      A[i][k+1] += A[i-1][k];
	      A[i][k+1] %= MOD;
	    }
	  } else {
	    A[i][k-1] += A[i-1][k];
	    A[i][k-1] %= MOD;
	  }
	  prev = tmp % 2;
	  tmp /= 2;
	}
      }
    }
  }
  // for(int i=0; i<H+1; i++) {
  //   for(int j=0; j<W; j++) {
  //     cout << A[i][j] << ' ';
  //   }
  //   cout << endl;
  // }
  cout << A[H][K-1] % MOD << endl;
  return 0;
}

