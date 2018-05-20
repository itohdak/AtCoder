#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M, L, X;
  cin >> N >> M >> L >> X;
  vector<int> A;
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    A.push_back(in);
  }
  sort(A.begin(), A.end(), greater<int>());
  ll NN = pow(2, N);
  ll R[NN];
  for(ll i=0; i<NN; i++) R[i] = 0;
  for(int i=0; i<N; i++){
    int a = A[i];
    for(ll j=1; j<pow(2, i+1); j+=2){
      for(ll k=j*pow(2,N-i-1); k<(j+1)*pow(2,N-i-1); k++){
	R[k] += a;
      }
    }
  }
  // for(ll i=0; i<NN; i++) cout << R[i] << ' ';
  for(ll i=0; i<NN; i++){
    if(R[i] % M == L){
      // cout << R[i] << endl;
      if(R[i] / M < X){
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}

