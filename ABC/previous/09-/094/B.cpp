#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, M, X;
  cin >> N >> M >> X;
  int A[N+1];
  for(int i=0; i<N; i++)
    A[i] = 0;
  for(int i=0; i<M; i++){
    int in;
    cin >> in;
    A[in] = 1;
  }
  int tmp = 0;
  for(int i=0; i<X; i++){
    tmp += A[i];
  }
  cout << min(tmp, M-tmp) << endl;
  return 0;
}

