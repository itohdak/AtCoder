#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  cout << int(ceil(1.0 * (N-1) / (K-1))) << endl;
  return 0;
}

