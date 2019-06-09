#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <complex>

using namespace std;
#define ll long long

int main(){
  int x, a, b;
  cin >> x >> a >> b;
  if(abs(a - x) < abs(b - x))
    cout << 'A' << endl;
  else
    cout << 'B' << endl;
  return 0;
}

