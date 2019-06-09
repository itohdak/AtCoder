#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, T;
  cin >> A >> B >> T;
  cout << floor((T + 0.5) / A) * B << endl;
  return 0;
}

