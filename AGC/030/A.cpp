#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  ll A, B, C;
  cin >> A >> B >> C;
  if(A + B >= C) {
    cout << B + C << endl;
  } else {
    cout << A + 2 * B + 1 << endl;
  }
  return 0;
}

