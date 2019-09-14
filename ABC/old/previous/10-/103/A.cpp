#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  vector<int> A(3);
  for(int i=0; i<3; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  cout << A[2] - A[0] << endl;
  return 0;
}

