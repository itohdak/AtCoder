#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C;
  cin >> A >> B >> C;
  cout << min(B / A, C) << endl;
  return 0;
}

