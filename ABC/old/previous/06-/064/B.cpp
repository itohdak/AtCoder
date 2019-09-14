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
  vector<int> A(N);
  for(int i=0; i<N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  cout << A[N-1] - A[0] << endl;
  return 0;
}

