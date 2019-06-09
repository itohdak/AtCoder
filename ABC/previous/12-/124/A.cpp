#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B;
  cin >> A >> B;
  cout << max(max(A+B, 2*A-1), 2*B-1) << endl;
  return 0;
}

