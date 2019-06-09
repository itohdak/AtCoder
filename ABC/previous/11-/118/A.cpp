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
  if(B % A == 0)
    cout << A + B << endl;
  else
    cout << B - A << endl;
  return 0;
}

