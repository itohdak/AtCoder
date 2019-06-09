#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  if(N % 2 == 0) {
    cout << N * (N-2) / 2 << endl;
    for(int i=1; i<=N; i++) {
      for(int j=i+1; j<=N; j++) {
	if(i + j != N + 1)
	  cout << i << ' ' << j << endl;
      }
    }
  } else {
    cout << (N-1) * (N-3) / 2 + (N-1) << endl;
    for(int i=1; i<=N; i++) {
      for(int j=i+1; j<=N; j++) {
	if(i + j != N)
	  cout << i << ' ' << j << endl;
      }
    }
  }
  return 0;
}

