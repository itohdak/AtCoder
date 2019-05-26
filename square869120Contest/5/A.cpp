#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, T;
  cin >> N >> T;
  int A[N];
  for(int i=0; i<N; i++)
    cin >> A[i];
  int ret = 0;
  for(int i=0; i<N; i++){
    ret = ceil(max(ret - A[i], 0) * 1.0 / T) * T + A[i];
  }
  cout << ret << endl;
  return 0;
}
