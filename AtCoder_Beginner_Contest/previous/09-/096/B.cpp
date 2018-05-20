#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int M = max(A, max(B, C));
  cout << A + B + C + M * pow(2, K) - M << endl;
  return 0;
}

