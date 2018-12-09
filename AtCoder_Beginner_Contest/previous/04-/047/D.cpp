#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;  ll T;
  cin >> N >> T;
  vector<ll> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  vector<ll> B(N);
  ll M = A[N-1];
  for(int i=N-1; i>=0; i--) {
    if(M - A[i] > 0) {
      B[i] = M - A[i];
    } else {
      M = A[i];
    }
  }
  sort(B.begin(), B.end());
  int tmp;
  for(int i=N-1; i>=0; i--)
    if(B[i] != B[N-1]) {
      tmp = i;
      break;
    }
  cout << N - tmp - 1 << endl;
  return 0;
}

