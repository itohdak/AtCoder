#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main() {
  int A, P;
  cin >> A >> P;
  P += A * 3;
  cout << P / 2 << endl;
  return 0;
}

