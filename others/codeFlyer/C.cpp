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
  ll D;
  cin >> N >> D;
  vector<ll> X(N);
  for(int i=0; i<N; i++)
    cin >> X[i];
  vector<int> left(N), right(N);
  for(int i=0; i<N; i++){
    int lb, ub;
    lb = 0, ub = i;
    while(lb <= ub){
      int mid = (lb + ub) / 2;
      if(X[i] - X[mid] <= D)
	ub = mid - 1;
      else
	lb = mid + 1;
    }
    left[i] = i - lb;

    lb = i, ub = N-1;
    while(lb <= ub){
      int mid = (lb + ub) / 2;
      if(X[mid] - X[i] <= D)
	lb = mid + 1;
      else
	ub = mid - 1;
    }
    right[i] = ub - i;
  }

  ll A = 0, B = 0;
  for(int i=0; i<N; i++)
    if(right[i] >= 2)
      A += right[i] * (right[i] - 1) / 2;
    else
      A += 0;
  for(int i=0; i<N; i++)
    B += left[i] * right[i];
  cout << B - A << endl;

  return 0;
}
