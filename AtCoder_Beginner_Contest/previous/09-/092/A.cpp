#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << min(A, B) + min(C, D) << endl;
  return 0;
}

