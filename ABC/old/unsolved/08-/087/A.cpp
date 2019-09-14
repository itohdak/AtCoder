#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int X, A, B;
  cin >> X >> A >> B;
  cout << (X - A) % B << endl;
  return 0;
}

