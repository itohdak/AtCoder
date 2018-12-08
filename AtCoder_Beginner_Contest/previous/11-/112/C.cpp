#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

ll A[101][101];
bool B[101][101];

int main(){
  int N;
  cin >> N;
  vector<int> X(N), Y(N);
  vector<ll> H(N);
  for(int i=0; i<101; i++)
    for(int j=0; j<101; j++)
      B[i][j] = true;
  for(int n=0; n<N; n++) {
    cin >> X[n] >> Y[n] >> H[n];
  }
  for(int t=0; t<2; t++) {
    for(int n=0; n<N; n++) {
      for(int i=0; i<101; i++) {
	for(int j=0; j<101; j++) {
	  if(B[i][j]) {
	    if(H[n] == 0) {
	      if(A[i][j] != 0 && A[i][j] > H[n] + abs(X[n] - i) + abs(Y[n] - j))
		B[i][j] = false;
	    } else if(A[i][j] == 0)
	      A[i][j] = H[n] + abs(X[n] - i) + abs(Y[n] - j);
	    else if(A[i][j] != H[n] + abs(X[n] - i) + abs(Y[n] - j))
	      B[i][j] = false;
	  }
	}
      }
    }
  }
  bool done = false;
  for(int i=0; i<101; i++) {
    for(int j=0; j<101; j++) {
      if(B[i][j]) {
	cout << i << ' ' << j << ' ' << A[i][j] << endl;
	done = true;
	break;
      }
    }
    if(done) break;
  }
  return 0;
}

