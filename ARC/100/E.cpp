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
  vector<ll> A(N);
  int n = (int)pow(2,N)-1;
  for(int i=0; i<n; i++)
    cin >> A[i];
  vector<ll> ans(n, 0LL);
  for(int i=0; i<n; i++){
    ll tmp = 0;
    for(int j=0; j<N; j++){
      if((i>>j) % 2 == 0){
	
      } else {
	
      }
    }
  }
  return 0;
}

