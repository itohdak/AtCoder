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
  for(int i=0; i<N; i++)
    cin >> A[i];
  sort(A.begin(), A.end(), greater<ll>());
  ll l1 = 0, l2 = 0;
  ll tmp1 = 0, tmp2 = 0;
  for(int i=0; i<N; i++){
    if(l1 == 0)
      if(tmp1 != A[i])
	tmp1 = A[i];
      else
	l1 = A[i];
    else
      if(tmp2 != A[i])
	tmp2 = A[i];
      else
	l2 = A[i];
    if(l1 != 0 && l2 != 0)
      break;
  }
  cout << l1 * l2 << endl;
  return 0;
}

