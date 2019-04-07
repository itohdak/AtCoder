#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X), B(Y), C(Z);
  for(int i=0; i<X; i++)
    cin >> A[i];
  for(int i=0; i<Y; i++)
    cin >> B[i];
  for(int i=0; i<Z; i++)
    cin >> C[i];
  sort(A.begin(), A.end(), greater<ll>());
  sort(B.begin(), B.end(), greater<ll>());
  sort(C.begin(), C.end(), greater<ll>());
  vector<ll> all;
  for(int i=0; i<X; i++)
    for(int j=0; j<Y; j++)
      for(int k=0; k<Z; k++)
	if(i * j * k < K)
	  all.push_back(A[i] + B[j] + C[k]);
  sort(all.begin(), all.end(), greater<ll>());
  for(int i=0; i<K; i++)
    cout << all[i] << endl;
  return 0;
}

