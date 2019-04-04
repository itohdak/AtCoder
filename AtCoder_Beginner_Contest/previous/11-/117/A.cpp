#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int T, X;
  cin >> T >> X;
  cout << showpoint << setprecision(10) << (double)T / X << endl;
  return 0;
}

