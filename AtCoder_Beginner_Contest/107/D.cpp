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
  vector<ll> A(N+1);
  for(int i=1; i<=N; i++)
    cin >> A[i];

  ll xmin = 0L;
  ll xmax = *max_element(A.begin(), A.end());
  while(xmin < xmax) {
    int x = (xmin + xmax) / 2.0;
    vector<ll> B(N+1, 0L);
    for(int i=1; i<=N; i++) {
      if(A[i] < x)
	B[i] = B[i-1] - 1;
      else
	B[i] = B[i-1] + 1;
    }
    
  }

  return 0;
}
