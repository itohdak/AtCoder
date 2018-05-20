#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll X;
  int K;
  cin >> X >> K;
  ll tmp = pow(10, K);
  cout << (X / tmp + 1) * tmp << endl;
  return 0;
}

