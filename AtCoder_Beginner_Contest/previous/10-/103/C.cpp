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
  cout << accumulate(A.begin(), A.end(), 0) - N << endl;
  return 0;
}

